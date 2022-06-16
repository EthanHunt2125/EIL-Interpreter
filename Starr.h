
/*
 *Class:       CS 4308 Section 
 *Term:        ____________
 *Name:         Ethan Hunt
 *Instructor:   Sharon Perry
 *Project:     Deliverable P3 Interpeter 
 */ 
#ifndef STARR_H
#define STARR_H
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







class Starr
{
public:
    

    Exp1* arr;
    stack<Exp1> Mstack;
    stack<Exp1> Tstack;
    int count=0;
    int period=1;
    int* Reg;
    int z=0;
    Starr();
    ~Starr();
    int*  get_arr(stack<int> x, int sl);
    stack<int> flipstack(stack<int> x);
    Exp1 get_Expr1(int *arr, int l, int *reg);
     void maintain(); 
     
};

#endif // STARR_H
