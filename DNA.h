#ifndef DNA_H_INCLUDED
#define DNA_H_INCLUDED
#include "SEQUENCE.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
#include "Codon.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string.h>
using namespace std;

class RNA;

enum DNA_Type{promoter, motif, tail, noncoding};

class DNA : public Sequence
{
  	private:
        DNA_Type type;
        DNA * complementary_strand;
        int startIndex;
        int endIndex;
    public:
 	 	// constructors and destructor

        DNA();
        DNA(string seq);
        DNA(string seq, DNA_Type atype);
        DNA(string seq,int start  , int End , DNA_Type type);
        string GetSeq();
        void set_start_end(int start, int endd);

        DNA(const DNA& rhs);
        ~DNA();
 	 	// function printing DNA sequence information to user
        void Print();
        friend ostream & operator << (ostream &Out, DNA& dna);
        friend istream & operator >> (istream &in, DNA& dna);
        DNA operator+ (DNA d2);
        bool operator== (DNA d2);
        bool operator!= (DNA d2);
        // function to convert the DNA sequence to RNA sequence
        // It starts by building the complementary_strand of the current
        // DNA sequence (starting from the startIndex to the endIndex), then,
        // it builds the RNA corresponding to that complementary_strand.
        RNA ConvertToRNA();
 	 	// function to build the second strand/pair of DNA sequence
	    // To build a complementary_strand (starting from the startIndex to
        // the endIndex), convert each A to T, each T to A, each C to G, and
        // each G to C. Then reverse the resulting sequence.
        void BuildComplementaryStrand();
        void Save_Data_To_File(string fileNameYouWantToSaveIn);
        void Load_Data_From_File(string file_Name);
  };
///*************************************************************************************************************************
class Strange_Character_DNA: public exception{
    public:
        const char * ERROR() const throw(){
        return " you have entered wrong DNA sequence ?!!!! -_- ";
        }
};


#endif // DNA_H_INCLUDED
