#ifndef SEQUENCE_H_INCLUDED
#define SEQUENCE_H_INCLUDED

#include <iostream>
#include <string.h>
using namespace std;

class Sequence
{
  	public:
        string  seq;
    public:
 	 	// constructors and destructor
       // Sequence();
      //Sequence(Sequence& rhs);
     //virtual ~Sequence();

 	 	// pure virtual function that should be overridden because every
        // type of sequence has its own details to be printed
        virtual void Print()= 0;
 	 	// friend function that will find the LCS (longest common
        // subsequence) between 2 sequences of any type, according to
        // polymorphism
        friend string Align(Sequence * s1, Sequence * s2);
};
///*************************************************************************************************************************


#endif // SEQUENCE_H_INCLUDED
