/*
 *Class:       CS 4308 Section 
 *Term:        ____________
 *Name:         Ethan Hunt
 *Instructor:   Sharon Perry
 *Project:     Deliverable P3 Interpeter 
 */ 
#include <stdio.h>
#include <bits/stdc++.h>
#include <cctype>  	// Provides toupper
#include <cstdlib> 	// Provides EXIT_SUCCESS
#include <iostream>
#include <fstream>
#include <fstream>
#include <string>
#include <queue>     	// Provides the queue template class
#include <stack>
#include "Chunk.h"
#include "Exp1.h"
#include "Starr.h"
#include "OPCODE.h"

using namespace std;

// Print functions

void print_arr(int * arr, int l) {
  for (int i = 0; i < l; i++) {
    cout << arr[i];

  }

  cout << endl;

}

void showstack(stack < Chunk > x) {
  while (!x.empty()) {
    x.top().print_Chunk();
    x.pop();
  }
}

void showstack(stack < int > x) {
  while (!x.empty()) {
    cout << x.top() << endl;
    x.pop();
  }
}

void showparsedstack(stack < int > x) {
  bool startLoop = false;
  bool ifstart = false;

  while (!x.empty()) {
    if (0 < x.top() && x.top() < 27) {

      cout << " <ID> ";

    } else if (26 < x.top() && x.top() < 31) {
      cout << " <Operator> ";

    } else if (10000000 <= x.top()) {

      cout << "<Value> ";

    } else if (31 == x.top()) {
      cout << "<=> ";

    } else if (46 == x.top()) {
      startLoop = true;
      cout << "<L> ";
    } else if (50 == x.top()) {

    } else if (48 == x.top()) {
      cout << "<:> ";
    } else if (47 == x.top()) {

    } else if (39 == x.top()) {
      cout << "<;> " << endl;
    } else if (38 == x.top()) {
      cout << "<)> " << endl;
    } else if (37 == x.top()) {
      cout << "<(> " << endl;
    } else {
      cout << "error" << endl;
      return;

    }
    x.pop();
  }

}

void showstack(stack < stack < int >> x) {
  while (!x.empty()) {
    showstack(x.top());
    x.pop();
  }
}

// Stack functions

int get_stack_size(stack < Chunk > x) {
  int i = 0;
  while (!x.empty()) {
    i++;
    x.pop();
  }

  return i;
}

int get_stack_size(stack < int > x) {
  int i = 0;
  while (!x.empty()) {
    i++;
    x.pop();
  }

  return i;
}

int get_stack_size(stack < Exp1 > x) {
  int i = 0;
  while (!x.empty()) {
    i++;
    x.pop();
  }

  return i;
}

int * get_arr(stack < int > x, int sl) {
  int i = 0;
  int * c = new int[sl];
  while (!x.empty()) {
    c[i] = x.top();
    i++;
    x.pop();
  }

  return c;
}

Exp1 * get_arr(stack < Exp1 > x, int sl) {
  int i = 0;
  Exp1 * c = new Exp1[sl];
  while (!x.empty()) {
    c[i] = x.top();
    i++;
    x.pop();
  }

  return c;
}

stack < char * > appendstack(stack < char * > x, stack < char * > y) {
  while (!x.empty()) {
    y.push(x.top());
    x.pop();
  }

  return y;

}

stack < stack < int >> appendstack(stack < stack < int >> x, stack < stack < int >> y) {
  while (!x.empty()) {
    y.push(x.top());
    x.pop();
  }

  return y;

}

stack < Chunk > flipstack(stack < Chunk > x) {
  stack < Chunk > y;
  stack < Chunk > s;
  Chunk i;
  while (!x.empty()) {
    i = x.top();
    y.push(i);
    x.pop();
  }

  s = y;

  return y;

}

stack < int > flipstack(stack < int > x) {
  stack < int > y;
  stack < int > s;
  int i;
  while (!x.empty()) {
    i = x.top();
    y.push(i);
    x.pop();
  }

  s = y;

  return y;

}

stack < stack < stack < int >>> flipstack(stack < stack < stack < int >>> x) {
  stack < stack < stack < int >>> y;
  stack < stack < stack < int >>> s;
  stack < stack < int >> i;
  while (!x.empty()) {
    i = x.top();
    y.push(i);
    x.pop();
  }

  s = y;

  return y;

}

stack < stack < int >> flipstack(stack < stack < int >> x) {
  stack < stack < int >> y;
  stack < stack < int >> s;
  stack < int > i;
  while (!x.empty()) {
    i = x.top();
    y.push(i);
    x.pop();
  }

  s = y;

  return y;

}

stack < string > flipstack(stack < string > x) {
  stack < string > y;
  stack < string > s;
  string i;
  while (!x.empty()) {
    i = x.top();
    y.push(i);
    x.pop();
  }

  s = y;

  while (!s.empty()) {
    cout << '\t' << s.top();
    s.pop();
  }

  cout << '\n';

  return y;

}

stack < Exp1 > flipstack(stack < Exp1 > x) {
  stack < Exp1 > y;
  stack < Exp1 > s;
  Exp1 i;
  while (!x.empty()) {
    i = x.top();
    y.push(i);
    x.pop();
  }

  s = y;

  return y;

}

stack < int > clearStack(stack < int > x) {
  while (!x.empty()) {
    x.pop();
  }

  return x;
}

stack < Exp1 > clearStack(stack < Exp1 > x) {
  while (!x.empty()) {
    x.pop();
  }

  return x;
}

// String Conversion Functions 

char * string_to_char(string line_str) {
  char * line_arr = new char[line_str.length()];

  for (int i = 0; i < line_str.length(); i++) {
    line_arr[i] = line_str.at(i);

  }

  return line_arr;

}

int digitscombine(int * digits, int digitnum) {
  int value = 0;
  int Value = 0;

  int value_new = value;
  int decmial_power = 1;
  int count = 0;

  for (int i = 0; i < digitnum; i++) {
    value = digits[count];
    //power of ten

    for (int j = digitnum - i; j > 1; j--) {
      decmial_power = decmial_power * 10;

    }

    Value = (value * decmial_power) + Value;
    decmial_power = 1;
    count++;
  }

  return Value;

}

int * chunk_to_digits(Chunk x) {
  int * y = new int[x.length];
  for (int i = 0; i < x.length; i++) {
    if (x.CHARS[i] == '0') {
      y[i] = 0;

    }

    if (x.CHARS[i] == '1') {
      y[i] = 1;

    }

    if (x.CHARS[i] == '2') {
      y[i] = 2;

    }

    if (x.CHARS[i] == '3') {
      y[i] = 3;

    }

    if (x.CHARS[i] == '4') {
      y[i] = 4;

    }

    if (x.CHARS[i] == '5') {
      y[i] = 5;

    }

    if (x.CHARS[i] == '6') {
      y[i] = 6;

    }

    if (x.CHARS[i] == '7') {
      y[i] = 7;

    }

    if (x.CHARS[i] == '8') {
      y[i] = 8;

    }

    if (x.CHARS[i] == '9') {
      y[i] = 9;

    }
  }

  return y;

}

int char_to_int(Chunk x) {
  int * y = chunk_to_digits(x);
  return digitscombine(y, x.length);
}

// Conditional Functions 

bool IS_identfier(char ch) {
  // tell wether a char is an identifier

  if (ch == 'a' || ch == 'b' || ch == 'c' || ch == 'd' ||
    ch == 'e' || ch == 'f' || ch == 'g' || ch == 'h' ||
    ch == 'i' || ch == 'j' || ch == 'k' || ch == 'l' ||
    ch == 'm' || ch == 'n' || ch == 'o' || ch == 'p' ||
    ch == 'q' || ch == 'r' || ch == 's' || ch == 't' ||
    ch == 'u' || ch == 'v' || ch == 'w' || ch == 'x' ||
    ch == 'y' || ch == 'z') {
    return true;

  } else {
    return false;
  }
}

bool IS_Structure_ID(char ch) {
  // tell wether a char is an identifier of loop or fucntion

  if (ch == 'A' || ch == 'B' || ch == 'C' || ch == 'D' ||
    ch == 'E' || ch == 'F' || ch == 'G' || ch == 'H' ||
    ch == 'I' || ch == 'J' || ch == 'K' || ch == 'L' ||
    ch == 'M' || ch == 'N' || ch == 'O' || ch == 'P' ||
    ch == 'Q' || ch == 'R' || ch == 'S' || ch == 'T' ||
    ch == 'U' || ch == 'V' || ch == 'W' || ch == 'X' ||
    ch == 'Y' || ch == 'Z') {
    return true;

  } else {
    return false;
  }
}

bool IS_Reserved_ID(char ch) {
  // tell wether is an identifier is reserved ie M for main and F for For ect

  if (ch == 'F' || ch == 'M' || ch == 'W' || ch == 'L' || ch == 'P') {
    return true;

  } else {
    return false;
  }
}

bool IS_operator(char ch) {
  // tell wether a char is an operator

  if (ch == '+' || ch == '-' || ch == '*' ||
    ch == '/') {
    return true;

  } else {
    return false;
  }
}

bool IS_punctuation(char ch) {
  // tell wether a char is an punctuation

  if (ch == ')' || ch == '(' ||
    ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
    ch == '>' || ch == '<' || ch == '=' || ch == ';' || ':' || '$') {
    return true;

  } else {
    return false;
  }
}

bool IS_WhitespaceP(char ch) {
  // tell wether a char is an punctuation

  if (ch == ' ' || ch == '\t') {
    return true;

  } else {
    return false;
  }
}

bool IS_relator(char ch) {
  // tell wether a char is an relator

  if (ch == '>' || ch == '<' || ch == '=') {
    return true;

  } else {
    return false;
  }
}

bool IS_doublerelator(char ch1, char ch2) {
  // tell wether a char is an relator

  if ((ch1 == '>' && ch2 == '=') || (ch1 == '<' && ch2 == '=') ||
    (ch1 == '=' && ch2 == '=') || (ch1 == '~' && ch2 == '=')) {
    return true;

  } else {
    return false;
  }
}

bool IS_digit(char ch) {
  if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' ||
    ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '0') {
    return true;
  }

  return false;
}

bool IS_Number(char * phrase, int l) {
  for (int i = 0; i < l; i++) {
    if (IS_digit(phrase[i]) != true) {
      return false;
    }
  }

  return true;
}

bool arr_vs_str(char * arr, string str, int arrL) {
  char * conv_str = string_to_char(str);
  int strL = str.length();
  if (strL == arrL) {
    for (int i = 0; i < arrL; i++) {
      if (conv_str[i] != arr[i]) {
        return false;
      }
    }

    return true;
  }

  return false;

}

bool IS_KeyWord(char * phrase, int pL) {
  if (arr_vs_str(phrase, "Start", pL) || arr_vs_str(phrase, "End", pL) || arr_vs_str(phrase, "IF", pL) || arr_vs_str(phrase, "IN", pL) 
       || arr_vs_str(phrase, "RAND", pL) ) {
    return true;
  }

  return false;
}

bool Stop(char ch) {
  //check if the given character is a punctuator or not
  if (ch == '(' || ch == ')' ||
    ch == '[' || ch == ']' || ch == '{' || ch == '}' ||
    ch == '&' || ch == '|' || IS_operator(ch) || IS_relator(ch)) {
    return true;
  }

  return false;

}

// Op code functions 

int get_specific_operator_code(char ch) {
  if (ch == '+') {
    return 27;
  }

  if (ch == '-') {
    return 28;
  }

  if (ch == '*') {
    return 29;
  }

  if (ch == '/') {
    return 30;
  }

  return -1;

}

int get_specific_id_code(char ch) {
  if (ch == 'a') {
    return 1;
  }

  if (ch == 'b') {
    return 2;
  }

  if (ch == 'c') {
    return 3;
  }

  if (ch == 'd') {
    return 4;
  }

  if (ch == 'e') {
    return 5;
  }

  if (ch == 'f') {
    return 6;
  }

  if (ch == 'g') {
    return 7;
  }

  if (ch == 'h') {
    return 8;
  }

  if (ch == 'i') {
    return 9;
  }

  if (ch == 'j') {
    return 10;
  }

  if (ch == 'k') {
    return 11;
  }

  if (ch == 'l') {
    return 12;
  }

  if (ch == 'm') {
    return 13;
  }

  if (ch == 'n') {
    return 14;

  }

  if (ch == 'o') {
    return 15;
  }

  if (ch == 'p') {
    return 16;
  }

  if (ch == 'q') {
    return 17;
  }

  if (ch == 'r') {
    return 18;
  }

  if (ch == 's') {
    return 19;
  }

  if (ch == 't') {
    return 20;
  }

  if (ch == 'u') {
    return 21;
  }

  if (ch == 'v') {
    return 22;
  }

  if (ch == 'w') {
    return 23;
  }

  if (ch == 'x') {
    return 24;
  }

  if (ch == 'y') {
    return 25;
  }

  if (ch == 'z') {
    return 26;
  }

  return -1;

}

int get_specific_relators_code(char ch) {
  if (ch == '=') {
    return 31;
  }

  if (ch == '<') {
    return 32;
  }

  if (ch == '>') {
    return 33;
  }

  return -1;

}

int get_specific_reservedID_code(char ch) {
  if (ch == 'M') {
    return 34;
  }

  if (ch == 'F') {
    return 35;
  }

  if (ch == 'W') {
    return 36;
  }

  if (ch == 'L') {
    return 46;
  }

  if (ch == 'P') {
    return 47;
  }

  return -1;

}

int get_specific_punctuation_code(char ch) {
  if (ch == '(') {
    return 37;
  }

  if (ch == ')') {
    return 38;
  }

  if (ch == ';') {
    return 39;
  }

  if (ch == ':') {
    return 48;
  }

  if (ch == '$') {
    return 49;
  }
  return -1;

}

int get_specific_doubleOP_code(char ch1, char ch2) {
  if (ch1 == '>' && ch2 == '=') {
    return 40;
  }

  if (ch1 == '<' && ch2 == '=') {
    return 41;
  }

  if (ch1 == '=' && ch2 == '=') {
    return 42;
  }

  if (ch1 == '~' && ch2 == '=') {
    return 43;
  }

  return -1;

}

int get_specific_keyword_code(char * phrase, int pL) {
  if (arr_vs_str(phrase, "Start", pL)) {
    return 44;
  }

  if (arr_vs_str(phrase, "End", pL)) {
    return 45;
  }

  if (arr_vs_str(phrase, "IF", pL)) {
    return 50;
  }
  
  if (arr_vs_str(phrase, "IN", pL)) {
    return 55;
  }
  if (arr_vs_str(phrase, "RAND", pL)) {
    return 56;
  }
  return -1;

}

int * get_opCodes(stack < Chunk > chunk_stack, int count) {
  chunk_stack = flipstack(chunk_stack);
  int * arr = new int[count];
  int i = 0;

  while (!chunk_stack.empty()) {
    arr[i] = chunk_stack.top().token_id;

    chunk_stack.pop();
    i++;

  }

  return arr;
}

// Evaluator Functions 

int ChunkEvaluator(Chunk lexem) {
  if (IS_Number(lexem.CHARS, lexem.length) && lexem.length > 0) {
    // Checks if Chunk is number

    return 10000000 + char_to_int(lexem);

  } else if (lexem.length == 1) {
    if (IS_identfier(lexem.CHARS[0])) {
      return get_specific_id_code(lexem.CHARS[0]);
    } else if (IS_operator(lexem.CHARS[0])) {
      return get_specific_operator_code(lexem.CHARS[0]);

    } else if (IS_relator(lexem.CHARS[0])) {
      return get_specific_relators_code(lexem.CHARS[0]);
    } else if (IS_Reserved_ID(lexem.CHARS[0])) {
      return get_specific_reservedID_code(lexem.CHARS[0]);
    } else if (IS_punctuation(lexem.CHARS[0])) {
      return get_specific_punctuation_code(lexem.CHARS[0]);

    } else {
      return -1;
    }
  } else if (lexem.length == 2) {
    if (IS_doublerelator(lexem.CHARS[0], lexem.CHARS[1])) {
      return get_specific_doubleOP_code(lexem.CHARS[0], lexem.CHARS[1]);
    } else if (IS_KeyWord(lexem.CHARS, lexem.length)) {
      return get_specific_keyword_code(lexem.CHARS, lexem.length);
    } else {
      // 2 char lexem

      return -1;

    }
  } else if (IS_KeyWord(lexem.CHARS, lexem.length)) {
    return get_specific_keyword_code(lexem.CHARS, lexem.length);
  }

  return -1;
}

//Lexical Analyzer Functions

stack < string > get_Code() {
  stack < string > Strings;
  string lT;

  ifstream myfile("test.txt");
  if (myfile.is_open()) {
    while (getline(myfile, lT)) {
      if (lT.find("//") != std::string::npos) {} else {
        Strings.push(lT);
      }
    }

    myfile.close();
  } else {
    cout << "Unable to open file";
  }

  Strings = flipstack(Strings);

  return Strings;

}

stack < Chunk > get_lex_stack() {
  Chunk temp;
  stack < Chunk > Lex_stack;
  stack < string > Strings;
  char * line_arr;
  int s = 0;
  int l = 0;
  int z = 0;
  bool is_part = false;
  int lnum = 1;

  Strings = get_Code();

  while (Strings.empty() == false) {
    line_arr = string_to_char(Strings.top());
    l = Strings.top().length();

    for (int i = 0; i < l; i++) {
      s = i;

      z = 0;

      while (IS_WhitespaceP(line_arr[i]) == false && i < l) {
        // Chunks

        i++;
        is_part = true;
      }

      if (is_part) {
        temp.CHARS = new char[(i - s)];
        temp.length = (i - s);
        temp.priority_num = lnum;
        for (int j = s; j < i; j++) {
          temp.CHARS[z] = line_arr[j];

          z++;

        }

        temp.token_id = ChunkEvaluator(temp);
        Lex_stack.push(temp);

      }

      is_part = false;
    }

    Strings.pop();
    lnum++;

  }

  return Lex_stack;

}

// Parser Functions

bool function_closed(int * oparr, int l) {
  if (oparr[0] == 44 && oparr[l - 2] == 45) {
    if (oparr[1] == oparr[l - 1]) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

bool expression_type_one(int * oparr, int l) {
  if (oparr[0] == 9 && oparr[l - 2] == 9) {
    if (oparr[1] == oparr[l - 1]) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

bool expression_type_two(int * oparr, int l) {
  if (oparr[0] == 9 && oparr[l - 2] == 9) {
    if (oparr[1] == oparr[l - 1]) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

stack < int > get_command_line(int * oparr, int l) {
  stack < int > x;
  for (int i = 2; i < l - 2; i++) {
    if (oparr[i] == 39) {
      break;

    } else {
      x.push(oparr[i]);

    }
  }

  return x;

}

stack < stack < int >> get_subcommand_stack(int * oparr, int l) {
  stack < stack < int >> stackX;
  stack < int > x;
  int a = 0;
  int c = 0;

  while (a < l) {
    c = 0;
    for (int i = a; i < l; i++) {
      if (oparr[i] == 39) {

        c = i;
        break;

      } else {
        x.push(oparr[i]);

      }
    }

    //cout<<"<>><><><><><><>"<<endl;
    //showparsedstack(x);
    //cout<<"<>><><><><><><>"<<endl;
    a = c + 1;

    stackX.push(x);
    x = clearStack(x);

  }

  return stackX;

}

stack < stack < int >> get_command_stack(int * oparr, int l) {
  stack < stack < int >> stackX;
  stack < int > x;
  int a = 2;
  int c = 0;

  while (a < l - 2) {
    c = 0;
    for (int i = a; i < l - 2; i++) {
      if (oparr[i] == 39) {

        c = i;
        break;

      } else {

        x.push(oparr[i]);

      }
    }

    //cout<<"<>><><><><><><>"<<endl;
    //showparsedstack(flipstack(x));
    //cout<<"<>><><><><><><>"<<endl;
    a = c + 1;

    stackX.push(x);
    x = clearStack(x);

  }

  return stackX;

}

stack < stack < int >> get_command_stack3(int * oparr, int l) {
  stack < stack < int >> stackX;
  stack < int > x;
  int a = 0;
  int c = 0;

  while (a < l) {
    c = 0;
    for (int i = a; i < l; i++) {
      if (oparr[i] == 49) {

        c = i;
        break;

      } else {
        x.push(oparr[i]);

      }
    }

    //cout<<"<>><><><><><><>"<<endl;
    //showparsedstack(x);
    //cout<<"<>><><><><><><>"<<endl;
    a = c + 1;
    cout << "<statement> ";
    stackX.push(x);
    x = clearStack(x);

  }

  return stackX;

}

stack < stack < int >> update_command_ifstack(int * oparr, int l) {
  stack < stack < int >> stackX;
  stack < int > x;
  int a = 0;
  int c = 0;

  while (a < l) {
    c = 0;
    for (int i = a; i < l; i++) {
      if (oparr[i] == 38) {

        x.push(48);

      } else if (oparr[i] == 48) {

        x.push(39);

      } else {
        x.push(oparr[i]);

      }

      c = i;
    }
    // x.push(39);
    // cout<<"<>><><><><><><>"<<endl;
    //showparsedstack(x);
    // cout<<"<>><><><><><><>"<<endl;
    a = c + 1;
    x = flipstack(x);
    stackX.push(x);
    x = clearStack(x);

  }

  return stackX;

}

stack < stack < int >> update_command_stack2(int * oparr, int l) {
  stack < stack < int >> stackX;
  stack < int > x;
  int a = 0;
  int c = 0;

  while (a < l) {
    c = 0;
    for (int i = a; i < l; i++) {
      if (oparr[i] == 38) {

        x.push(48);

      } else if (oparr[i] == 48) {

        x.push(39);

      } else {
        x.push(oparr[i]);

      }

      c = i;
    }
    // x.push(39);
    // cout<<"<>><><><><><><>"<<endl;
    //showparsedstack(x);
    // cout<<"<>><><><><><><>"<<endl;
    a = c + 1;
    x = flipstack(x);
    stackX.push(x);
    x = clearStack(x);

  }

  return stackX;

}

stack < int > update2_command_stack2(int * oparr, int l) {

  stack < int > x;
  int a = 0;
  int c = 0;
  bool Level_sawp = false;

  for (int i = a; i < l; i++) {
    if (oparr[i] == 38) {

      x.push(48);

    } else if (oparr[i] == 48) {

      x.push(39);

    } else if (oparr[i] == 37) {

      x.push(38);

    } else {
      x.push(oparr[i]);

    }

  }
  //   x.push(39);
  // cout<<"<>><><><><><><>"<<endl;
  x = flipstack(x);
  showparsedstack(x);
  // cout<<"<>><><><><><><>"<<endl;

  return x;

}

stack < stack < int >> get_command_stack2(int * oparr, int l) {
  stack < stack < int >> stackX;
  stack < int > x;
  int a = 0;
  int c = 0;

  while (a < l) {
    c = 0;
    for (int i = a; i < l; i++) {
      if (oparr[i] == 48) {
        if (oparr[i + 1] == 48) {

          c = i + 1;
          break;

        } else {

          c = i;
          break;

        }

      } else {
        x.push(oparr[i]);

      }
    }

    //cout<<"<>><><><><><><>"<<endl;
    //showparsedstack(flipstack(x));
    //cout<<"<>><><><><><><>"<<endl;
    a = c + 1;
    cout << "<statement> ";
    stackX.push(x);
    x = clearStack(x);

  }

  return stackX;

}

int * get_commands2(int * oparr, int l) {
  int * x;
  int c = 0;
  for (int i = 2; i < l - 2; i++) {
    if (oparr[i] == 39) {
      break;

    } else {
      c++;

    }
  }

  x = new int[c];
  for (int i = 0; i <= c; i++) {
    x[i] = oparr[i + 2];

  }

  return x;

}

// Interptuter Functions 

Exp1 get_Expr1(int * arr, int l, int * reg) {
  stack < int > v;
  stack < int > o;
  int os = 0;
  int vs = 0;
  //  cout<<" count  " << l<< endl;
  Exp1 c;

  for (int i = 0; i < l; i++) {
    if (0 < arr[i] && arr[i] < 27) {
      vs++;
      cout << "<ID> ";
      v.push(reg[arr[i] - 1]);

    } else if (26 < arr[i] && arr[i] < 31) {
      os++;
      o.push(arr[i]);
      cout << "<Operator> ";
    } else if (10000000 <= arr[i]) {
      vs++;
      v.push(arr[i] - 10000000);
      cout << "<Value> ";
    }
  }

  if (vs > 0) {
    //cout<< vs<<endl;
    // showstack(v);
    v = flipstack(v);
    c.val = get_arr(v, vs);
    c.l = vs;
  }

  if (os > 0) {
    // showstack(o);
    o = flipstack(o);
    c.OpIDs = get_arr(o, os);
    c.opC = os;
  }

  return c;

}

int * Compilier_v1D2(int * Registers, stack < stack < int >> x, int count, int * opcode) {
  stack < int > lengths;
  int z = 0;
  stack < Chunk > Lex_stack;
  int f = 0;
  int temp;
  stack < stack < int >> loopstack2;
  stack < stack < int >> loopstack;
  stack < Exp1 > Cstack;

  Exp1 command;
  int loopS = 0;
  Starr LoopCode;
  OPCODE Code;

  if (function_closed(opcode, count)) {
    ///single command line///
    x = get_command_stack(opcode, count);
    x = flipstack(x);

    while (!x.empty()) {
      z = get_stack_size(x.top());
      x.top() = flipstack(x.top());
      // showstack(x.top());
      if (0 < x.top().top() && x.top().top() < 27) {
        command.varID = x.top().top();

        f = command.varID - 1;

        z--; // remove assingto count
        x.top().pop(); // remove assingto value
        z--; // remove =
        x.top().pop(); // remove =
        //showstack(x.top());
        command = get_Expr1(get_arr(x.top(), z), z, Registers);
        Registers[f] = command.evalExp1();
        cout << f << " : " << Registers[f] << endl;
        // cout<< " expression evluation = "   <<command.evalExp1()<<endl;

      }

      if (x.top().top() == 47) {
        for (int i = 0; i < 26; i++) {
          cout << "| id " << i << ": " << Registers[i];
          if (i % 4 == 3) {
            cout << endl;

          }
        }

        cout << endl;

      }

      if (x.top().top() == 46) {
        //showstack(x.top());
        x.top().pop(); // get rid of L
        z--; // get rid of L 
        temp = x.top().top() - 10000000; // get counter 
        x.top().pop(); // get rid of counter
        z--; // get rid of counter 
        // showstack(x.top());
        //print_arr(get_arr(x.top(),z),z);

        loopstack = get_command_stack2(get_arr(x.top(), z), z);
        loopstack = flipstack(loopstack);

        while (!loopstack.empty()) {
          z = get_stack_size(loopstack.top());
          loopstack.top() = flipstack(loopstack.top());
          //showstack(loopstack.top());
          if (0 < loopstack.top().top() && loopstack.top().top() < 27) {
            f = loopstack.top().top();

            z--; // remove assingto count
            loopstack.top().pop(); // remove assingto value
            z--; // remove =
            loopstack.top().pop(); // remove =
            //showstack(x.top());
            command = get_Expr1(get_arr(loopstack.top(), z), z, Registers);
            command.z = z;
            command.Code = get_arr(loopstack.top(), z);
            command.varID = f - 1;

            Cstack.push(command);

            // cout<< " expression evluation = "   <<command.evalExp1()<<endl;

          }

          loopstack.pop();

        }
        //////////////////////////////////////////////////////////////////////////////////////////////
        Cstack = flipstack(Cstack);
        loopS = temp * get_stack_size(Cstack);
        LoopCode.Mstack = Cstack;
        LoopCode.Reg = Registers;
        LoopCode.z = z;
        int n = 0;

        for (int i = 0; i < loopS; i++) {
          if (n % get_stack_size(Cstack) == 0) {
            n = 0;

          }
          if (n == get_stack_size(Cstack)) {

            n = 0;

          }
          LoopCode.count = n;
          LoopCode.maintain();
          //Cstack=LoopCode.Mstack;
          n++;
          /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        }
        Registers = LoopCode.Reg;

      }
      x.pop();

    }
  }

  return Registers;
}

int * LOOP_Handler2(int * Registers, stack < int > x) {
  int z = get_stack_size(x);
  int f = 0;
  int temp;
  stack < stack < int >> loopstack;
  stack < stack < int >> loopstack2;
  stack < stack < int >> loopstackC;
  stack < Exp1 > Cstack;
  Exp1 command;
  int loopS = 0;
  Starr LoopCode;
  OPCODE Code;
  stack < stack < stack < int >>> SUBLOOPS;
  stack < stack < stack < int >>> COPY;

  x.pop(); // get rid of L

  z--; // get rid of L 

  //temp = x.top() - 10000000;	// get counter 
  temp = Registers[x.top() - 1]; //

  x.pop(); // get rid of counter
  z--; // get rid of counter 
  cout << "LOOP --> <L> <ID> <CODE> " << endl;
  // showstack(x.top());
  //print_arr(get_arr(x.top(),z),z);
  cout << "CODE --> ";

  loopstack = get_command_stack2(get_arr(x, z), z);
  cout << " END " << endl;
  loopstack = flipstack(loopstack);

  while (!loopstack.empty()) {
    z = get_stack_size(loopstack.top());
    loopstack.top() = flipstack(loopstack.top());

    if (0 < loopstack.top().top() && loopstack.top().top() < 27) {
      f = loopstack.top().top();

      z--; // remove assingto count
      loopstack.top().pop(); // remove assingto value
      z--; // remove =
      loopstack.top().pop(); // remove =
      //showstack(x.top());
      cout << "statement --> <assigment> " << endl;
      cout << "assignment --> <ID> <=> <expression> " << endl;
      cout << "expression --> ";
      command = get_Expr1(get_arr(loopstack.top(), z), z, Registers);
      command.z = z;
      command.Code = get_arr(loopstack.top(), z);
      command.varID = f - 1;

      cout << endl;
      Cstack.push(command);

      // cout<< " expression evluation = "   <<command.evalExp1()<<endl;

    }
    if (loopstack.top().top() == 47) {
      for (int i = 0; i < 26; i++) {
        cout << "| id " << i << ": " << Registers[i];
        if (i % 4 == 3) {
          cout << endl;

        }
      }

      cout << endl;

    }
    if (loopstack.top().top() == 46) {
      // loopstack2=update_command_stack2(get_arr(loopstack.top(), z),z);
      //loopstack2.top()=flipstack(loopstack2.top());
      //SUBLOOPS.push(loopstack2);
      cout << "statement --> <LOOP> " << endl;
      loopstack2.push(update2_command_stack2(get_arr(loopstack.top(), z), z));

    }

    loopstack.pop();

  }

  // SUBLOOPS=flipstack(SUBLOOPS);
  // showstack(SUBLOOPS.top());
  // COPY=SUBLOOPS;
  Cstack = flipstack(Cstack);
  loopstack2 = flipstack(loopstack2);
  loopstackC = loopstack2;
  loopS = temp * get_stack_size(Cstack);
  LoopCode.Mstack = Cstack;
  LoopCode.Reg = Registers;
  LoopCode.z = z;
  int n = 0;

  //cout<<loopS<<endl;
  for (int i = 0; i < loopS; i++) {
    if (n % get_stack_size(Cstack) == 0) {
      if (!loopstack2.empty()) {
        Registers = LOOP_Handler2(Registers, loopstack2.top());
        loopstack2.pop();
        LoopCode.Reg = Registers;

      } else {

        loopstack2 = loopstackC;

      }

      n = 0;

    }
    if (n == get_stack_size(Cstack)) {

      n = 0;

    }
    LoopCode.count = n;
    LoopCode.maintain();
    //Cstack=LoopCode.Mstack;
    Registers = LoopCode.Reg;
    n++;

  }

  return LoopCode.Reg;
}

int * Assigment_Handler2(int * Registers, stack < int > x) {
  int f = 0;
  int z = get_stack_size(x);
  Exp1 command;
  command.varID = x.top();
  cout << "assignment --> <ID> <=> <expression> " << endl;
  f = command.varID - 1;

  z--; // remove assingto count

  x.pop(); // remove assingto value
  if (x.top() == 31) {
    z--; // remove =
    x.pop(); // remove =
    //showstack(x.top());
    cout << "expression --> ";

    command = get_Expr1(get_arr(x, z), z, Registers);
    Registers[f] = command.evalExp1();
    cout << endl;
    cout << f << " : " << Registers[f] << endl;

  } else {

    cout << "error" << endl;
  }

  return Registers;
}

int * IF_Handler2(int * Registers, stack < int > x) {

  int LID = 0;
  int Rval = 0;
  int if_type = 0;
  int z = get_stack_size(x);
  int f = 0;
  int temp;
  stack < stack < int >> loopstack;
  stack < Exp1 > Cstack;
  Exp1 command;
  Starr LoopCode;
  OPCODE Code;

  cout << "IF --> <ID> <Double_Operator> <ID> <CODE> " << endl;

  x.pop(); // get rid of IF
  z--; // get rid of IF 
  
  if (0 < x.top() && x.top() < 27) {
    LID = x.top(); // get var
    x.pop();
    z--;
    
    if_type = x.top(); // get if type
    x.pop();
    z--;
    
    if (0 < x.top() && x.top() < 27) {
     
    Rval = Registers[x.top() - 1]; // val 
      x.pop(); // get rid of counter
      z--; // get rid of counter 

      if (if_type == 42) {
    
        if (Registers[LID - 1] == Rval) {
          cout << "CODE --> ";

          loopstack = get_command_stack3(get_arr(x, z), z);

          cout << " END " << endl;

          loopstack = flipstack(loopstack);

          while (!loopstack.empty()) {
            z = get_stack_size(loopstack.top());
            loopstack.top() = flipstack(loopstack.top());
            //cout<<endl;

            if (0 < loopstack.top().top() && loopstack.top().top() < 27) {
              Registers = Assigment_Handler2(Registers, loopstack.top());

            } else if (loopstack.top().top() == 46) {

              Registers = LOOP_Handler2(Registers, loopstack.top());

            }
            loopstack.pop();

          }

        }
      } else if (if_type == 40) {

        if (Registers[LID - 1] >= Rval) {
          cout << "CODE --> ";

          loopstack = get_command_stack3(get_arr(x, z), z);

          cout << " END " << endl;

          loopstack = flipstack(loopstack);

          while (!loopstack.empty()) {
            z = get_stack_size(loopstack.top());
            loopstack.top() = flipstack(loopstack.top());
            //cout<<endl;

            if (0 < loopstack.top().top() && loopstack.top().top() < 27) {
              Registers = Assigment_Handler2(Registers, loopstack.top());

            } else if (loopstack.top().top() == 46) {

              Registers = LOOP_Handler2(Registers, loopstack.top());

            }
            loopstack.pop();

          }

        }
      } else if (if_type == 41) {

        if (Registers[LID - 1] <= Rval) {
          cout << "CODE --> ";

          loopstack = get_command_stack3(get_arr(x, z), z);

          cout << " END " << endl;

          loopstack = flipstack(loopstack);

          while (!loopstack.empty()) {
            z = get_stack_size(loopstack.top());
            loopstack.top() = flipstack(loopstack.top());
            //cout<<endl;

            if (0 < loopstack.top().top() && loopstack.top().top() < 27) {
              Registers = Assigment_Handler2(Registers, loopstack.top());

            } else if (loopstack.top().top() == 46) {

              Registers = LOOP_Handler2(Registers, loopstack.top());

            }
            loopstack.pop();

          }

        }
      } else if (if_type == 43) {

        if (Registers[LID - 1] != Rval) {
          cout << "CODE --> ";

          loopstack = get_command_stack3(get_arr(x, z), z);

          cout << " END " << endl;

          loopstack = flipstack(loopstack);

          while (!loopstack.empty()) {
            z = get_stack_size(loopstack.top());
            loopstack.top() = flipstack(loopstack.top());
            //cout<<endl;

            if (0 < loopstack.top().top() && loopstack.top().top() < 27) {
              Registers = Assigment_Handler2(Registers, loopstack.top());

            } else if (loopstack.top().top() == 46) {

              Registers = LOOP_Handler2(Registers, loopstack.top());

            }
            loopstack.pop();

          }

        }
      }

    } else {

      cout << "error" << endl;
    }
  } else {

    cout << "error" << endl;
  }

  return Registers;
}

int * SubCompilier(int * Registers, stack < stack < int >> x) {
  stack < int > lengths;
  int z = 0;
  stack < Chunk > Lex_stack;
  int f = 0;
  int temp;
  stack < stack < int >> loopstack2;
  stack < stack < int >> loopstack;
  stack < Exp1 > Cstack;
  Exp1 command;
  int loopS = 0;
  int LID = 0;
  int Rval = 0;
  int if_type = 0;
  Starr LoopCode;
  OPCODE Code;

  ///single command line///

  while (!x.empty()) {
    z = get_stack_size(x.top());
    x.top() = flipstack(x.top());
    // showstack(x.top());
    if (0 < x.top().top() && x.top().top() < 27) {

      cout << "statement --> <assignment> " << endl;

      Registers = Assigment_Handler2(Registers, x.top());

    } else if (x.top().top() == 47) {
      cout << "statement --> <Print> " << endl;
      for (int i = 0; i < 26; i++) {
        cout << "| id " << i << ": " << Registers[i];
        if (i % 4 == 3) {
          cout << endl;

        }
      }

      cout << endl;

    } else if (x.top().top() == 46) {
      cout << "statement --> <LOOP> " << endl;

      //showstack(x.top());
      x.top().pop(); // get rid of L
      z--; // get rid of L 
      temp = x.top().top() - 10000000; // get counter 
      x.top().pop(); // get rid of counter
      z--; // get rid of counter 
      // showstack(x.top());
      //print_arr(get_arr(x.top(),z),z);

      loopstack = get_command_stack2(get_arr(x.top(), z), z);

      loopstack = flipstack(loopstack);

      while (!loopstack.empty()) {
        z = get_stack_size(loopstack.top());
        loopstack.top() = flipstack(loopstack.top());
        cout << endl;
        // showstack(loopstack.top());

        if (0 < loopstack.top().top() && loopstack.top().top() < 27) {
          f = loopstack.top().top();

          z--; // remove assingto count
          loopstack.top().pop(); // remove assingto value
          z--; // remove =
          loopstack.top().pop(); // remove =
          //showstack(x.top());
          command = get_Expr1(get_arr(loopstack.top(), z), z, Registers);
          command.z = z;
          command.Code = get_arr(loopstack.top(), z);
          command.varID = f - 1;

          Cstack.push(command);

          // cout<< " expression evluation = "   <<command.evalExp1()<<endl;

        }

        loopstack.pop();

      }

      //////////////////////////////////////////////////////////////////////////////////////////////

      Cstack = flipstack(Cstack);
      loopS = temp * get_stack_size(Cstack);
      LoopCode.Mstack = Cstack;
      LoopCode.Reg = Registers;
      LoopCode.z = z;
      int n = 0;

      for (int i = 0; i < loopS; i++) {
        if (n % get_stack_size(Cstack) == 0) {
          n = 0;

        }
        if (n == get_stack_size(Cstack)) {

          n = 0;

        }
        LoopCode.count = n;
        LoopCode.maintain();
        //Cstack=LoopCode.Mstack;
        n++;
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      }
      Registers = LoopCode.Reg;

    } else if (x.top().top() == 50) {
      cout << "statement --> <IF> " << endl;
      Registers = IF_Handler2(Registers, x.top());
    } else {
      cout << " error " << endl;
      break;

    }

    x.pop();

  }

  return Registers;
}

int * LoopExe(int * Registers, stack < stack < int >> x) {

  stack < int > lengths;
  int z = 0;
  stack < Chunk > Lex_stack;
  int f = 0;
  int temp;
  stack < stack < int >> loopstack2;
  stack < stack < int >> loopstack;
  stack < Exp1 > Cstack;
  Exp1 command;
  int loopS = 0;
  Starr LoopCode;
  OPCODE Code;

  while (!x.empty()) {
    z = get_stack_size(x.top());
    x.top() = flipstack(x.top());
    // showstack(x.top());
    if (0 < x.top().top() && x.top().top() < 27) {
      command.varID = x.top().top();

      f = command.varID - 1;

      z--; // remove assingto count
      x.top().pop(); // remove assingto value
      z--; // remove =
      x.top().pop(); // remove =
      //showstack(x.top());
      command = get_Expr1(get_arr(x.top(), z), z, Registers);
      Registers[f] = command.evalExp1();
      cout << f << " : " << Registers[f] << endl;
      // cout<< " expression evluation = "   <<command.evalExp1()<<endl;

    }

    if (x.top().top() == 47) {
      for (int i = 0; i < 26; i++) {
        cout << "| id " << i << ": " << Registers[i];
        if (i % 4 == 3) {
          cout << endl;

        }
      }

      cout << endl;

    }

    if (x.top().top() == 46) {
      //showstack(x.top());
      x.top().pop(); // get rid of L
      z--; // get rid of L 
      temp = x.top().top() - 10000000; // get counter 
      x.top().pop(); // get rid of counter
      z--; // get rid of counter 
      // showstack(x.top());
      //print_arr(get_arr(x.top(),z),z);

      loopstack = get_command_stack2(get_arr(x.top(), z), z);

      loopstack = flipstack(loopstack);

      while (!loopstack.empty()) {
        z = get_stack_size(loopstack.top());
        loopstack.top() = flipstack(loopstack.top());
        cout << endl;
        // showstack(loopstack.top());

        if (0 < loopstack.top().top() && loopstack.top().top() < 27) {
          f = loopstack.top().top();

          z--; // remove assingto count
          loopstack.top().pop(); // remove assingto value
          z--; // remove =
          loopstack.top().pop(); // remove =
          //showstack(x.top());
          command = get_Expr1(get_arr(loopstack.top(), z), z, Registers);
          command.z = z;
          command.Code = get_arr(loopstack.top(), z);
          command.varID = f - 1;

          Cstack.push(command);

          // cout<< " expression evluation = "   <<command.evalExp1()<<endl;

        }

        loopstack.pop();

      }

      //////////////////////////////////////////////////////////////////////////////////////////////

      Cstack = flipstack(Cstack);
      loopS = temp * get_stack_size(Cstack);
      LoopCode.Mstack = Cstack;
      LoopCode.Reg = Registers;
      LoopCode.z = z;
      int n = 0;

      for (int i = 0; i < loopS; i++) {
        if (n % get_stack_size(Cstack) == 0) {
          n = 0;

        }
        if (n == get_stack_size(Cstack)) {

          n = 0;

        }
        LoopCode.count = n;
        LoopCode.maintain();
        //Cstack=LoopCode.Mstack;
        n++;
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      }
      Registers = LoopCode.Reg;

    }
    x.pop();

  }

  return Registers;
}

int * LOOP_Handler(int * Registers, stack < int > x) {
  int z = get_stack_size(x);
  int f = 0;
  int temp;
  int* state_arr;  // holds a int value that maps to a specific statement type
  state_arr= new int[z]; 
  int itertator=0;  // itertator used to instert or update state arr
  stack< int > state_stack; 
  stack < stack < int >> loopstack; // loopcode
  stack < stack < int >> loopstack2; //embebeded loop statements stack 
  stack < stack < int >> loopstackC; //embebeded loop statements stack copy
  stack < stack < int >> ifstack;   //embebeded IF statements stack 
  stack < stack < int >> ifstackC; //embebeded IF statements stack 
  stack < Exp1 > Cstack;
  Exp1 command;
  int loopS = 0;
  Starr LoopCode;
  OPCODE Code;
 

  x.pop(); // get rid of L

  z--; // get rid of L 

  //temp = x.top() - 10000000;	// get counter 
  if (0 < x.top() && x.top() < 27) {
    
    temp = Registers[x.top() - 1]; // get counter
    x.pop(); // get rid of counter
    z--; // get rid of counter 
    cout << "LOOP --> <L> <ID> <CODE> " << endl;
    cout << "CODE --> ";
    loopstack = get_command_stack2(get_arr(x, z), z);
    cout << " END " << endl;
    loopstack = flipstack(loopstack);

    while (!loopstack.empty()) {   // finds all statement types
      z = get_stack_size(loopstack.top());
      loopstack.top() = flipstack(loopstack.top());
      // assigment condition 
      if (0 < loopstack.top().top() && loopstack.top().top() < 27) {
        state_stack.push(1);// 1 means assigment statement 
        f = loopstack.top().top();
        z--; // remove assingto count
        loopstack.top().pop(); // remove assingto value
        z--; // remove =
        loopstack.top().pop(); // remove =
        cout << "statement --> <assigment> " << endl;
        cout << "assignment --> <ID> <=> <expression> " << endl;
        cout << "expression --> ";
        command = get_Expr1(get_arr(loopstack.top(), z), z, Registers);
        command.z = z;
        command.Code = get_arr(loopstack.top(), z);
        command.varID = f - 1;
        cout << endl;
        Cstack.push(command);
      }
       // print condition 
      if (loopstack.top().top() == 47) {
        for (int i = 0; i < 26; i++) {
          cout << "| id " << i << ": " << Registers[i];
          if (i % 4 == 3) {
            cout << endl;
          }
        }
        cout << endl;
      }
      // subloop condition
      if (loopstack.top().top() == 46) {
        state_stack.push(2);
        cout << "statement --> <LOOP> " << endl;
        loopstack2.push(update2_command_stack2(get_arr(loopstack.top(), z), z));
      }
      // if condition
      if (loopstack.top().top() == 50) {
        //state_arr[itertator] = 3 ; // 3 means if statement 
        state_stack.push(3);
        cout << "statement --> <IF> " << endl;
        ifstack.push(loopstack.top());
       // Registers = IF_Handler2(Registers, loopstack.top());

      }
       itertator++;
      loopstack.pop();

    }
    
    state_stack=flipstack(state_stack);
    state_arr= get_arr(state_stack,get_stack_size(state_stack));
    ifstack = flipstack(ifstack);
    ifstackC = ifstack;
    Cstack = flipstack(Cstack);
    loopstack2 = flipstack(loopstack2);
    loopstackC = loopstack2;
    loopS = temp * itertator;
    LoopCode.Mstack = Cstack;
    LoopCode.Reg = Registers;
    LoopCode.z = z;
    int n = 0;
    int m = 0; 
    print_arr(state_arr,get_stack_size(state_stack));
    int b = 0;
    for (int i = 0; i < loopS; i++) {
       
        if (m % itertator == 0) {
    //cout<<"iteration "<<b<<endl;
        m = 0;
    b++;
      }
        if(state_arr[m]==3){
           // cout<<"if "<<endl;
             if (!ifstack.empty()) {
          //showstack(ifstack);
          Registers = IF_Handler2(Registers, ifstack.top());
          ifstack.pop();
          LoopCode.Reg = Registers;

        } else {

          ifstack = ifstackC;
          Registers = IF_Handler2(Registers, ifstack.top());
          ifstack.pop();
          LoopCode.Reg = Registers;
        }
            
            
            
        }
       
        
        
      if(state_arr[m]==1){
          // cout<<"a "<<endl;
    if (n % get_stack_size(Cstack) == 0) {

        if (!loopstack2.empty()) {
          Registers = LOOP_Handler2(Registers, loopstack2.top());
          loopstack2.pop();
          LoopCode.Reg = Registers;

        } else {

          loopstack2 = loopstackC;

        }

        n = 0;

      }
      if (n == get_stack_size(Cstack)) {

        n = 0;

      }

        LoopCode.count = n;
        LoopCode.maintain();
        Registers = LoopCode.Reg;
        n++;
      }
      m++;
      //Cstack=LoopCode.Mstack;

     

    }

  } 
  else {

    cout << "error" << endl;
  }

  return LoopCode.Reg;
}

int * Assigment_Handler(int * Registers, stack < int > x) {
  int f = 0;
  int z = get_stack_size(x);
  Exp1 command;
  command.varID = x.top();
  cout << "assignment --> <ID> <=> <expression> " << endl;
  f = command.varID - 1;

  z--; // remove assingto count

  x.pop(); // remove assingto value
  if (x.top() == 31) {
    z--; // remove =
    x.pop(); // remove =
    //showstack(x.top());
    cout << "expression --> ";

    command = get_Expr1(get_arr(x, z), z, Registers);
    Registers[f] = command.evalExp1();
    cout << endl;
    cout << f << " : " << Registers[f] << endl;

  } else {

    cout << "error" << endl;
  }

  return Registers;
}

int * IF_Handler(int * Registers, stack < int > x) {

  int LID = 0;
  int Rval = 0;
  int if_type = 0;
  int z = get_stack_size(x);
  int f = 0;
  int temp;
  stack < stack < int >> loopstack;
  stack < Exp1 > Cstack;
  Exp1 command;
  Starr LoopCode;
  OPCODE Code;

  cout << "IF --> <ID> <Double_Operator> <ID> <CODE> " << endl;

  x.pop(); // get rid of IF
  z--; // get rid of IF 
  if (0 < x.top() && x.top() < 27) {
    LID = x.top(); // get var
    x.pop();
    z--;
    if_type = x.top(); // get if type
    x.pop();
    z--;
    if (0 < x.top() && x.top() < 27) {
      Rval = Registers[x.top() - 1]; // val 
      x.pop(); // get rid of counter
      z--; // get rid of counter 

      if (if_type == 42) {

        if (Registers[LID - 1] == Rval) {
          cout << "CODE --> ";

          loopstack = get_command_stack3(get_arr(x, z), z);

          cout << " END " << endl;

          loopstack = flipstack(loopstack);

          while (!loopstack.empty()) {
            z = get_stack_size(loopstack.top());
            loopstack.top() = flipstack(loopstack.top());
            //cout<<endl;

            if (0 < loopstack.top().top() && loopstack.top().top() < 27) {
              Registers = Assigment_Handler(Registers, loopstack.top());

            } else if (loopstack.top().top() == 46) {

              Registers = LOOP_Handler(Registers, loopstack.top());

            }
            loopstack.pop();

          }

        }
      } else if (if_type == 40) {

        if (Registers[LID - 1] >= Rval) {
          cout << "CODE --> ";

          loopstack = get_command_stack3(get_arr(x, z), z);

          cout << " END " << endl;

          loopstack = flipstack(loopstack);

          while (!loopstack.empty()) {
            z = get_stack_size(loopstack.top());
            loopstack.top() = flipstack(loopstack.top());
            //cout<<endl;

            if (0 < loopstack.top().top() && loopstack.top().top() < 27) {
              Registers = Assigment_Handler(Registers, loopstack.top());

            } else if (loopstack.top().top() == 46) {

              Registers = LOOP_Handler(Registers, loopstack.top());

            }
            loopstack.pop();

          }

        }
      } else if (if_type == 41) {

        if (Registers[LID - 1] <= Rval) {
          cout << "CODE --> ";

          loopstack = get_command_stack3(get_arr(x, z), z);

          cout << " END " << endl;

          loopstack = flipstack(loopstack);

          while (!loopstack.empty()) {
            z = get_stack_size(loopstack.top());
            loopstack.top() = flipstack(loopstack.top());
            //cout<<endl;

            if (0 < loopstack.top().top() && loopstack.top().top() < 27) {
              Registers = Assigment_Handler(Registers, loopstack.top());

            } else if (loopstack.top().top() == 46) {

              Registers = LOOP_Handler(Registers, loopstack.top());

            }
            loopstack.pop();

          }

        }
      } else if (if_type == 43) {

        if (Registers[LID - 1] != Rval) {
          cout << "CODE --> ";

          loopstack = get_command_stack3(get_arr(x, z), z);

          cout << " END " << endl;

          loopstack = flipstack(loopstack);

          while (!loopstack.empty()) {
            z = get_stack_size(loopstack.top());
            loopstack.top() = flipstack(loopstack.top());
            //cout<<endl;

            if (0 < loopstack.top().top() && loopstack.top().top() < 27) {
              Registers = Assigment_Handler(Registers, loopstack.top());

            } else if (loopstack.top().top() == 46) {

              Registers = LOOP_Handler(Registers, loopstack.top());

            }
            loopstack.pop();

          }

        }
      }

    } else {

      cout << "error" << endl;
    }
  } else {

    cout << "error" << endl;
  }

  return Registers;
}

int * Compilier(int * Registers, stack < stack < int >> x, int count, int * opcode) {
  stack < int > lengths;
  int z = 0;
  stack < Chunk > Lex_stack;
  int f = 0;
  int temp;
  stack < stack < int >> loopstack2;
  stack < stack < int >> loopstack;
  stack < Exp1 > Cstack;
  int input;
  Exp1 command;
  int loopS = 0;
  int LID = 0;
  int Rval = 0;
  int if_type = 0;
  Starr LoopCode;
  OPCODE Code;

  if (function_closed(opcode, count)) {

    cout << "Start --> ";
    for (int i = 0; i < get_stack_size(get_command_line(opcode, count)); i++) {
      cout << " <statement> ";

    }
    cout << " END " << endl;
    ///single command line///
    x = get_command_stack(opcode, count);
    x = flipstack(x);

    while (!x.empty()) {
      z = get_stack_size(x.top());
      x.top() = flipstack(x.top());
      // showstack(x.top());
      if (0 < x.top().top() && x.top().top() < 27) {

        cout << "statement --> <assignment> " << endl;

        Registers = Assigment_Handler(Registers, x.top());

      } else if (x.top().top() == 47) {
        cout << "statement --> <Print> " << endl;
        for (int i = 0; i < 26; i++) {
          cout << "| id " << i << ": " << Registers[i];
          if (i % 4 == 3) {
            cout << endl;

          }
        }

        cout << endl;

      } else if (x.top().top() == 46) {
        cout << "statement --> <LOOP> " << endl;
        Registers = LOOP_Handler(Registers, x.top());
      } else if (x.top().top() == 50) {
        cout << "statement --> <IF> " << endl;
        Registers = IF_Handler(Registers, x.top());
      } 
      else if (x.top().top() == 55) {
        cout << "statement --> <INPUT> " << endl;
        x.top().pop(); // get rid of IN 
        
        cin >> Registers[x.top().top()-1];
      }
      else if (x.top().top() == 56) {
        cout << "statement --> <RAND> " << endl;
        x.top().pop(); // get rid of IN 
        
      Registers[x.top().top()-1 ]= rand() % 100; ;
      }
      else {
        cout << " error " << endl;
        break;

      }

      x.pop();

    }

  }

  return Registers;
}

//driver code

int main() 
{

  int * Registers = new int[26]; // values of varibles a is at index zero registers 
  for (int i = 0; i < 26; i++) {
    Registers[i] = 0;

  }

  stack < int > lengths;

  stack < Chunk > Lex_stack;

  int * opcode;
  stack < stack < int >> x;

  int count = 0;

  int loopS = 0;

  Lex_stack = get_lex_stack();

  count = get_stack_size(Lex_stack);

  opcode = get_opCodes(Lex_stack, count);

  print_arr(opcode, count);

  cout << "  " << endl;
  cout << " Input: " << endl;

  showstack(flipstack(Lex_stack));

  cout << " Output: " << endl;
  cout << "  " << endl;
  cout << "  " << endl;

  Registers = Compilier(Registers, x, count, opcode);

  /*
  	if (function_closed(opcode, count))
  	{
  		///single command line///
  		x = get_command_stack(opcode, count);
  		x = flipstack(x);

  		while (!x.empty())
  		{
  			z = get_stack_size(x.top());
  			x.top() = flipstack(x.top());

  			if (0 < x.top().top() && x.top().top() < 27)
  			{
  				command.varID = x.top().top();

  				f = command.varID - 1;

  				z--;	// remove assingto count
  				x.top().pop();	// remove assingto value
  				z--;	// remove =
  				x.top().pop();	// remove =
  				
  				command = get_Expr1(get_arr(x.top(), z), z, Registers);
  				Registers[f] = command.evalExp1();
  				cout << f << " : " << Registers[f] << endl;
  				
  			}

  			if (x.top().top() == 47)
  			{
  				for (int i = 0; i < 26; i++)
  				{
  					cout << "| id " << i << ": " << Registers[i];
  					if (i % 4 == 3)
  					{
  						cout << endl;

  					}
  				}

  				cout << endl;

  			}

  			if (x.top().top() == 46)
  			{
  				
  				x.top().pop();	// get rid of L
  				z--;	// get rid of L 
  				temp = x.top().top() - 10000000;	// get counter 
  				x.top().pop();	// get rid of counter
  				z--;	// get rid of counter 
  				

  				loopstack = get_command_stack2(get_arr(x.top(), z), z);
  				loopstack = flipstack(loopstack);

  				while (!loopstack.empty())
  				{
  					z = get_stack_size(loopstack.top());
  					loopstack.top() = flipstack(loopstack.top());
  					//showstack(loopstack.top());
  					if (0 < loopstack.top().top() && loopstack.top().top() < 27)
  					{
  						f = loopstack.top().top();

  						z--;	// remove assingto count
  						loopstack.top().pop();	// remove assingto value
  						z--;	// remove =
  						loopstack.top().pop();	// remove =
  						command = get_Expr1(get_arr(loopstack.top(), z), z, Registers);
  						command.z = z;
  						command.Code = get_arr(loopstack.top(), z);
  						command.varID = f - 1;
  						
                       
                          Cstack.push(command);

  					}

  					loopstack.pop();

  				}

  				Cstack = flipstack(Cstack);
  				loopS = temp* get_stack_size(Cstack);
                  LoopCode.Mstack=Cstack;
                  LoopCode.Reg=Registers;
                  LoopCode.z=z;
                  int n=0;
                  
                  
  				for (int i = 0; i < loopS; i++)
  				{
  					if(n % get_stack_size(Cstack)==0){
                          n=0;
                          
                      }
                      if( n==get_stack_size(Cstack)){
                          
                         n=0; 
                          
                      }
                      LoopCode.count=n;
                      LoopCode.maintain();
                      //Cstack=LoopCode.Mstack;
                      n++;

              }
              Registers=LoopCode.Reg;

              }
  			x.pop();

  		}
  	}
  */
  return (EXIT_SUCCESS);

}