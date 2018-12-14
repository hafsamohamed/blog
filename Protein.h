#ifndef PROTEIN_H_INCLUDED
#define PROTEIN_H_INCLUDED
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
class DNA;

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
  	private:
        Protein_Type type;
      public:
 	 	// constructors and destructor
 	 	Protein();
 	 	Protein(string p);
        void Print();
 	 	Protein(const Protein& P);
 	friend 	ostream & operator << (ostream &Out, Protein& pr);
 	friend 	istream & operator >> (istream &in, Protein &pr);
    Protein operator+ (Protein p2);
    bool operator== (Protein p2);
    bool operator!= (Protein p2);

 	 //	~Protein()
 	 	// return an array of DNA sequences that can possibly
                // generate that protein sequence
        DNA * GetDNAStrandsEncodingMe(const DNA & bigDNA);
        void Save_Data_To_File(string fileNameYouWantToSaveIn);
        void Load_Data_From_File(string file_Name);


};
///*************************************************************************************************************************
class Strange_Character_Protein: public exception{
    public:
        const char * ERROR() const throw(){
        return " you have entered wrong Protein sequence ?!!!! -_- ";
        }
};


#endif // PROTEIN_H_INCLUDED
