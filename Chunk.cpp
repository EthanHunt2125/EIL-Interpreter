/*
 *Class:       CS 4308 Section 
 *Term:        ____________
 *Name:         Ethan Hunt
 *Instructor:   Sharon Perry
 *Project:     Deliverable P3 Interpeter 
 */ 
#include "Chunk.h"
#include <stdio.h>
#include <bits/stdc++.h>
#include <cctype>   // Provides toupper
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream>
#include <fstream>
#include <fstream>
#include <string>
#include <queue>      // Provides the queue template class
#include <stack>
using namespace std;


Chunk::Chunk() {}

Chunk::Chunk(char * arr, int l) {
  length = l;
  CHARS = arr;

}

Chunk::~Chunk() {}

void Chunk::print_Chunk() {
  cout << length << "  : ";
  for (int i = 0; i < length; i++) {
    cout << CHARS[i];

  }

  cout << " : " << token_id << endl;

}