/*
 *Class:       CS 4308 Section 
 *Term:        ____________
 *Name:         Ethan Hunt
 *Instructor:   Sharon Perry
 *Project:     Deliverable P3 Interpeter 
 */ 

#ifndef EXP1_H
#define EXP1_H
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





class Exp1
{
public:
   
    int* OpIDs;
    int* RegIDs;
    int* val;
    int* Code;
    int l;
    int opC;
    int z;
    int regC;
    int varID;
    Exp1();
    ~Exp1();
    
    int evalExp1();
    int eval(int val1, int val2, int OPID );
    
    
};

#endif // EXP1_H
