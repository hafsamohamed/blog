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
RNA:: RNA()
{
    type = mRNA;
}
///********************************************************************
RNA::RNA(string seq2, RNA_Type atype)
{
    ///****************** exception handling !!***********************
    for(int i = 0; i < seq2.length(); ++i)
    {
        if(seq2[i] != 'A' && seq2[i] != 'U' && seq2[i] != 'G' && seq2[i] != 'C' )
        {
            throw Strange_Character_RNA();
        }

    }
    ///***************************************************************
    this-> seq = seq2;
    this-> type = atype;
}
///********************************************************************
RNA::RNA(const RNA& rhs)
{
    seq = rhs.seq;
    type = rhs.type;
}

void RNA:: Print()
{
    cerr << "Type: " << type << endl
         << "DNA Seq: " << seq << endl
         << "*****************************************" << endl;
}
///********************************************************************
string RNA::GetSeq()
{
    return seq;
}
///***********************************************************************************
DNA RNA::ConvertToDNA()
{
    string newst = "";
    for(int i = 0; i < seq.length(); ++i)
    {
        if(seq[i] == 'A' ) ///A -> T /// U -> A /// G -> C /// C -> G
            seq[i] = 'T';
        else if(seq[i] == 'U' )
            seq[i] = 'A';
        else if(seq[i] == 'G' )
            seq[i] = 'C';
        else if(seq[i] == 'C' )
            seq[i] = 'G';

        newst += seq[i];
    }


    for(int i = 0; i < newst.length() /2; ++i)
    {
        char temp = newst[i];
        newst[i] =  newst[(newst.length() - 1) - i];
        newst[(newst.length() - 1) - i] = temp;
    }

    return  DNA (newst,promoter);
}
///*********************************************************************************************************************
Protein RNA:: ConvertToProtein( CodonsTable & table)
{
    string st = "";
    string st2 = "";
    for(int i = 0; i <= seq.length(); ++i)
    {
        if( i % 3 == 0 && i != 0)
        {
            st2 += table.getAminoAcid(st);
            st = "";
        }
        st += seq[i];
    }
    return Protein(st2);
}
///********************************************************************
RNA RNA:: operator+ (RNA r2)
{
    return RNA(seq + r2.seq, mRNA);
}
///***********************************************************************************
bool RNA:: operator== (RNA r2)
{
    return (seq == r2.seq);
}

///***********************************************************************************
bool RNA:: operator!= (RNA r2)
{
    return (seq != r2.seq);
}
///***********************************************************************************
///********************************************************
ostream & operator << (ostream &Out, RNA &rna)
{
    if (rna.type == 0)
        Out << "Type: " << "mRNA" << endl;
    else if (rna.type == 1)
        Out << "Type: " << "pre_mRNA" << endl;
    else if (rna.type == 2)
        Out << "Type: " << "mRNA_exon" << endl;
    else if (rna.type == 3)
        Out << "Type: " << "mRNA_intron" << endl;


    Out << "RNA Seq: " << rna.seq << endl
        << "*****************************************" << endl;
    return Out;
}
///**********************************************************************************
istream & operator >> (istream &in, RNA& rna)
{
    string t;
    cout << "Enter type of RNA: ";
    cin >> t;
    if (t == "mRNA")
        rna.type == mRNA;
    else if (t == "pre_mRNA")
        rna.type == pre_mRNA;
    else if (t == "mRNA_exon")
        rna.type == mRNA_exon;
    else if (t == "mRNA_intron")
        rna.type == mRNA_intron;

    cout << "Enter the sequence: ";
    in >> rna.seq;
    ///****************** exception handling !!***********************
    for(int i = 0; i < rna.seq.length(); ++i)
    {
        if(rna.seq[i] != 'A' && rna.seq[i] != 'U' && rna.seq[i] != 'G' && rna.seq[i] != 'C' )
        {
            throw Strange_Character_RNA();
        }

    }
    ///***************************************************************
    return in;
}
///**********************************************************
void RNA::Save_Data_To_File(string fileNameYouWantToSaveIn)
{
ofstream myfile;
  myfile.open ("fileNameYouWantToSaveIn");
  myfile << "The Sequence is: " << seq << endl << "The Type is: " << type << endl;
  myfile.close();
}
///************************************************************
void  RNA::Load_Data_From_File(string file_Name)
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
///********************************************************************************************************************
///********************************************************************************************************************
///********************************************************************************************************************
///********************************************************************************************************************
