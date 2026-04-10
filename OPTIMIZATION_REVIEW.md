# Optimization Review (April 10, 2026)

This document captures targeted, high-impact optimizations for the current EIL interpreter codebase.

## 1) Replace pass-by-value stack helpers with reference-based versions

Several utility functions take `std::stack` by value and then iterate/pop all elements. That causes a full copy at call time, then another full traversal, which is expensive for large token/program stacks.

Examples:
- `get_stack_size(stack<...> x)` overloads in `main.cpp`
- `flipstack(...)` overloads in `main.cpp` and `Starr.cpp`
- `appendstack(...)` overloads in `main.cpp`

### Recommendation
- For read-only display/size helpers: use `const std::stack<T>&` and iterate via a copied local only when needed.
- For mutation helpers: use rvalue refs (`std::stack<T>&&`) or explicit in-place variants to avoid accidental copies.
- Where possible, replace stack reversal patterns with `std::vector` and index iteration.

### Expected impact
Lower CPU and memory pressure in parse/compile phases where stacks are heavily transformed.

## 2) Migrate raw dynamic arrays to `std::vector<int>` / `std::string`

The code allocates many arrays with `new[]` and does not consistently show ownership/deallocation near call sites.

Examples:
- `main.cpp` allocates expression/value arrays (`new int[...]`, `new Exp1[...]`).
- `Starr.cpp` allocates helper arrays with `new int[...]`.
- `Chunk` stores raw `char*` buffers.

### Recommendation
- Replace return types like `int*` and `Exp1*` with `std::vector<int>` / `std::vector<Exp1>`.
- Change `Chunk::CHARS` from `char*` to `std::string` (or `std::vector<char>` if binary-safe behavior is required).
- Use move semantics for handoff between parser/compiler stages.

### Expected impact
- Prevent leaks and double-free risk.
- Improve cache locality and simplify code.
- Reduce bug surface and enable safer refactoring.

## 3) Remove duplicate/heavy includes from headers

Most headers and sources include `#include <bits/stdc++.h>` plus repeated STL headers and duplicate `#include <fstream>` lines.

### Recommendation
- In headers, include only what is used (e.g., `<stack>`, `<string>`, forward declarations where possible).
- Remove duplicate includes.
- Avoid `#include <bits/stdc++.h>` for portability and faster incremental builds.

### Expected impact
Faster compile times and improved portability across non-GNU toolchains.

## 4) Avoid global `using namespace std;` in headers

`using namespace std;` appears in headers, which leaks namespace pollution into all translation units that include them.

### Recommendation
- Remove it from headers (`Chunk.h`, `Exp1.h`, `Starr.h`, `OPCODE.h`).
- Use explicit `std::` qualifications in headers.

### Expected impact
Fewer symbol conflicts and cleaner API boundaries.

## 5) Harden expression evaluation edge cases

`Exp1::eval` performs division directly, and `evalExp1` assumes at least one value (`val[0]`) exists.

### Recommendation
- Add guards for:
  - division by zero,
  - empty expression (`l == 0`),
  - malformed operator/value count mismatch.
- Return typed error status (e.g., `std::optional<int>` or result struct with error code).

### Expected impact
Improved runtime stability and clearer diagnostics for invalid EIL programs.

## 6) Break up `main.cpp` (2,600+ LOC) into modules

`main.cpp` combines tokenizing, parsing, command-stack transforms, codegen/compile logic, runtime execution, and debugging helpers.

### Recommendation
Split into focused translation units, e.g.:
- `lexer.*`
- `parser.*`
- `ir_builder.*`
- `compiler.*`
- `runtime.*`
- `debug_utils.*`

### Expected impact
Faster iteration, easier testing, lower merge conflict probability, and better optimization opportunities per module.

## 7) Enable warning-driven cleanup in CI/local scripts

A warning-enabled build already surfaces many unused variables and a sign-compare warning.

### Recommendation
- Add a build target with: `-Wall -Wextra -Wpedantic -Wconversion`.
- Gradually drive warnings to zero.
- Treat key warnings as errors in CI once baseline is clean.

### Expected impact
Earlier bug detection and a more maintainable codebase.

## Suggested implementation order

1. Header/include cleanup (`bits/stdc++.h`, duplicate includes, `using namespace std` in headers).
2. Stack helper API redesign (remove pass-by-value hot paths).
3. `Exp1` safety checks and result/error model.
4. Raw array migration to vectors/strings.
5. `main.cpp` modularization.

