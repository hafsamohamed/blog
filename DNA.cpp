///***************************************************************************************************************************************************
///***************************************************************************************************************************************************
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
///////////////////////////////////////////////////////////////// HEADERS/////////////////////////////////////////////////////////////////////////////
#include "SEQUENCE.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
#include "Codon.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <fstream>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
DNA :: DNA()
{
    type = motif;
    startIndex = 0;
    endIndex = 0;
    seq = "NO-Sequence";

}
///*********************************************************************
DNA :: DNA(const DNA& rhs)
{
    type = rhs.type;
    seq = rhs.seq;
    startIndex = rhs.startIndex;
    endIndex = rhs.endIndex;
}
DNA ::~DNA()
{

}
///******************************************************************************************************
DNA::DNA(string seq2, int start, int End, DNA_Type type)
{
    Strange_Character_DNA e;
    for(int i = 0; i < seq2.length(); ++i)
    {
        if(seq2[i] != 'A' && seq2[i] != 'G' && seq2[i] != 'C' && seq2[i] != 'T' )
        {
            throw Strange_Character_DNA();
        }

    }

    this ->seq = seq2;
    startIndex = start;
    endIndex = End;
    this-> type = type;
}
///*******************************************************************************************************
DNA:: DNA(string seq2, DNA_Type atype)
{
    for(int i = 0; i < seq2.length(); ++i)
    {
        if(seq2[i] != 'A' && seq2[i] != 'G' && seq2[i] != 'C' && seq2[i] != 'T' )
        {
            throw Strange_Character_DNA();
        }

    }
    this->seq = seq2;
    this->type = atype;
}
///*************************************************************************************************************************
///*******************************************************************************************************
DNA:: DNA(string seq2)
{
    for(int i = 0; i < seq2.length(); ++i)
    {
        if(seq2[i] != 'A' && seq2[i] != 'G' && seq2[i] != 'C' && seq2[i] != 'T' )
        {
            throw Strange_Character_DNA();
        }

    }
    this->seq = seq2;
}
///*********************************************************************************************************
string DNA::GetSeq()
{
    return seq;
}

///***********************************************************************************
void DNA:: set_start_end(int start, int endd)
{
    startIndex = start;
    endIndex = endd;
}
///******************************************************
RNA DNA::ConvertToRNA()
{
    complementary_strand = new DNA ();

    complementary_strand->seq = seq;
    string newst = "";
    for(int i = startIndex - 1; i < endIndex; ++i)
    {
        if(seq[i] == 'A' )
            complementary_strand->seq[i] = 'U';
        else if(seq[i] == 'T' )
            complementary_strand->seq[i] = 'A';
        else if(seq[i] == 'G' )
            complementary_strand->seq[i] = 'C';
        else if(seq[i] == 'C' )
            complementary_strand->seq[i] = 'G';
        newst += complementary_strand->seq[i];
    }


    for(int i = 0; i < newst.length() /2; ++i)
    {
        char temp = newst[i];
        newst[i] =  newst[(newst.length() - 1) - i];
        newst[(newst.length() - 1) - i] = temp;
    }
    //cout << newst << endl;
    //   RNA rn(newst,mRNA);
    //cout << rn << endl;
    return RNA(newst,mRNA) ;
}
///*************************************************************************************************************************
void DNA ::BuildComplementaryStrand()
{
    complementary_strand = new DNA ();
    complementary_strand->seq = seq;
    for(int i = 0; i < seq.length(); ++i)
    {
        if(seq[i] == 'A' )
            complementary_strand->seq[i] = 'T';
        if(seq[i] == 'T' )
            complementary_strand->seq[i] = 'A';
        if(seq[i] == 'G' )
            complementary_strand->seq[i] = 'C';
        if(seq[i] == 'C' )
            complementary_strand->seq[i] = 'G';
    }

    for(int i = 0; i < seq.length()/2; ++i)
    {
        char temp = complementary_strand->seq[i];
        complementary_strand->seq[i] = complementary_strand->seq[(seq.length() - 1) - i];
        complementary_strand->seq[(seq.length() - 1) - i] = temp;
    }
    //cout << complementary_strand->seq << endl;
}
///*************************************************************************************************************************
void DNA:: Print()
{
    cerr << "Type: " << type << endl
         << "DNA Seq: " << seq << endl
         << "*****************************************" << endl;
}
///*********************************************************************************************************************
///***********************************************************************************
DNA DNA:: operator+ (DNA d2)
{
    return DNA(seq + d2.seq);
}
///***********************************************************************************
bool DNA:: operator== (DNA d2)
{
    return (seq == d2.seq);
}

///***********************************************************************************
bool DNA:: operator!= (DNA d2)
{
    return (seq != d2.seq);
}
///********************************************************************************
ostream & operator << (ostream &Out, DNA& dna)
{
    if (dna.type == 0)
        Out << "Type: " << "promoter" << endl;
    else if (dna.type == 1)
        Out << "Type: " << "motif" << endl;
    else if (dna.type == 2)
        Out << "Type: " << "tail" << endl;
    else if (dna.type == 3)
        Out << "Type: " << "noncoding" << endl;


    Out << "DNA Seq: " << dna.seq << endl;
    return Out;
}
///**********************************************************************************
istream & operator >> (istream &in, DNA& dna)
{
    string t;
    cout << "Enter type of DNA: ";
    cin >> t;
    if (t == "promoter")
        dna.type == promoter;
    else if (t == "motif")
        dna.type == motif;
    else if (t == "tail")
        dna.type == tail;
    else if (t == "noncoding")
        dna.type == noncoding;

    cout << "Enter the sequence: ";
    in >> dna.seq;
    ///****************** exception handling !!***********************
    for(int i = 0; i < dna.seq.length(); ++i)
    {
        if(dna.seq[i] != 'A' && dna.seq[i] != 'G' && dna.seq[i] != 'C' && dna.seq[i] != 'T' )
        {
            throw Strange_Character_DNA();
        }

    }
    ///***************************************************************
    return in ;
}
///**********************************************************
void DNA::Save_Data_To_File(string fileNameYouWantToSaveIn)
{
ofstream myfile;
  myfile.open ("fileNameYouWantToSaveIn");
  myfile << "The Sequence is: " << seq << endl << "The Type is: " << type << endl;
  myfile.close();
}
///************************************************************
void  DNA::Load_Data_From_File(string file_Name)
{
  string line;
  ifstream myfile ("file_Name");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file";
}
///****************************************************************************************************************
///****************************************************************************************************************
///****************************************************************************************************************
///****************************************************************************************************************
