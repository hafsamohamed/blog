#ifndef RNA_H_INCLUDED
#define RNA_H_INCLUDED
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
class Protein;
enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA : public Sequence
{
  	private:
        RNA_Type type;
  	public:
 	 	// constructors and destructor
        RNA();
        RNA(string seq, RNA_Type atype);
        RNA(const RNA& rhs);
        string GetSeq();
       // ~RNA();
 	 	// function to be overridden to print all the RNA information
        void Print();
 	 	//  function to convert the RNA sequence into protein sequence
        //  using the codonsTable object
        Protein ConvertToProtein( CodonsTable & table);
 	 	//  function to convert the RNA sequence back to DNA
        DNA ConvertToDNA();
        RNA  operator+ (RNA r2);
        bool operator== (RNA r2);
        bool operator!= (RNA r2);
       friend ostream & operator << (ostream &Out, RNA &rna);
       friend istream & operator >> (istream &in, RNA &rna);
       void Save_Data_To_File(string fileNameYouWantToSaveIn);
       void Load_Data_From_File(string file_Name);


};
///*************************************************************************************************************************
class Strange_Character_RNA: public exception{
    public:
        const char * ERROR() const throw(){
        return " you have entered wrong RNA sequence ?!!!! -_- ";
        }
};


#endif // RNA_H_INCLUDED
