#ifndef CODON_H_INCLUDED
#define CODON_H_INCLUDED
///////////////////////////////////////////////////////////////// HEADERS/////////////////////////////////////////////////////////////////////////////
#include "SEQUENCE.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
#include "Codon.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string.h>

using namespace std;


class Protein;

// struct representing a codon of 3 DNA/RNA characters and ‘\0’
struct Codon
{
  	string value;    	    // 4th location for null character
    char AminoAcid;  	    // corresponding AminoAcid according to Table
};

// need to create one object of that class to load the AminoAcids table
// into memory
class CodonsTable
{
  	private:
        Codon codons[64];
   	public:
 	 	// constructors and destructor
        CodonsTable();
        //  ~CodonsTable();
 	 	// function to load all codons from the given text file
        void LoadCodonsFromFile(string codonsFileName);
   //     Codon getAminoAcid(string value);
        char getAminoAcid(string value);
        void setCodon(string value, char AminoAcid, int index);
};

#endif // CODON_H_INCLUDED
