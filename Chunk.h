/*
 *Class:       CS 4308 Section 
 *Term:        ____________
 *Name:         Ethan Hunt
 *Instructor:   Sharon Perry
 *Project:     Deliverable P3 Interpeter 
 */ 
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



#ifndef CHUNK_H
#define CHUNK_H

class Chunk
{
public:
    int length;
    char* CHARS;
    int priority_num;
    int token_id=0;
    Chunk();
    Chunk(char* arr, int l);
    ~Chunk();
    void print_Chunk();
};

#endif // CHUNK_H
