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

using namespace std;

Starr::Starr() {}

Starr::~Starr() {}

int * Starr::get_arr(stack < int > x, int sl) {
  int i = 0;
  int * c = new int[sl];
  while (!x.empty()) {
    c[i] = x.top();
    i++;
    x.pop();
  }

  return c;
}

stack < int > Starr::flipstack(stack < int > x) {
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

Exp1 Starr::get_Expr1(int * arr, int l, int * reg) {
  stack < int > v;
  stack < int > o;
  int os = 0;
  int vs = 0;

  Exp1 c;
  c.Code = arr;
  c.z = l;
  /* 
    for (int i = 0; i < l; i++)
    {
    cout << arr[i] <<" ";

    }

    cout << endl;
*/

  for (int i = 0; i < l; i++) {
    if (0 < arr[i] && arr[i] < 27) {
      vs++;

      v.push(reg[arr[i] - 1]);
      // cout<<" v "  << reg[arr[i] - 1] << endl;
    } else if (26 < arr[i] && arr[i] < 31) {
      os++;
      o.push(arr[i]);
      // cout<<" o"  << os  << endl;
    } else if (10000000 <= arr[i]) {
      vs++;
      v.push(arr[i] - 10000000);
      // cout<<" v "  << vs << endl;
    }
  }

  if (vs > 0) {
    //cout<< vs<<endl;
    //showstack(v);
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

void Starr::maintain() {

  // stack <Exp1> Cstack = Mstack;  
  int i = 0;
  int f = 0;
  Exp1 current;

  int * Code;

  while (i < count) { // transfer previous updates to tempstack
    Tstack.push(Mstack.top());

    Mstack.pop();
    i++;
  }

  current = Mstack.top();
  Mstack.pop();
  f = current.varID;
  cout << endl;

  current = get_Expr1(current.Code, current.z, Reg);
  current.varID = f;
  Reg[f] = current.evalExp1();

  cout << f << " : " << Reg[f] << endl;

  Mstack.push(current);

  while (!Tstack.empty()) {

    Mstack.push(Tstack.top());
    Tstack.pop();

  }

}