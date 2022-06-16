/*
 *Class:       CS 4308 Section 
 *Term:        ____________
 *Name:         Ethan Hunt
 *Instructor:   Sharon Perry
 *Project:     Deliverable P3 Interpeter 
 */ 
#include "Exp1.h"
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

Exp1::Exp1()
{
}


int Exp1::eval(int val1, int val2, int OPID){
   
    if(OPID==27){
        
        
        
        return val1+val2;
    }
    
    else if(OPID==28){
        
        
        
        return val1-val2;
    }
    
    else if(OPID==29){
        
        
        
        return val1*val2;
    }
    
   else if(OPID==30){
        
        
        
        return val1/val2;
    }
    else{
        
        
        
        return -99999;
        
    }
    
    
}


int Exp1::evalExp1(){
   
    int rt= val[0];
    int OPID;
    if(l>1){
    for(int i=1; i<l;i++){
       
        rt=eval(rt,val[i], OpIDs[i-1] );
        
       
       
   }
    }
    
    
  
    return rt; 
    
    
    
}




Exp1::~Exp1()
{
}

