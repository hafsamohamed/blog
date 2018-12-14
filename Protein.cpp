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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Protein:: Protein()
{
    type = Cellular_Function;
    seq = "";

}
///******************************************************************
Protein::Protein(string p)
{
    ///***************** Exception Handling *******************************

    for(int i = 0; i < p.length(); ++i)
    {
        if(p[i] != 'K' && p[i] != 'N' && p[i] != 'T' && p[i] != 'R' && p[i] != 'S' && p[i] != 'I' && p[i] != 'M' && p[i] != 'Q' && p[i] != 'H' && p[i] != 'P' && p[i] != 'L' && p[i] != 'E' && p[i] != 'D' && p[i] != 'G' && p[i] != 'V' && p[i] != 'Y' && p[i] != 'C' && p[i] != 'W' && p[i] != 'F')
        {
            throw Strange_Character_Protein();
        }
    }
    ///*********************************************************************
    seq = p;

}
///*******************************************************************
Protein::Protein(const Protein& P)
{
    seq = P.seq;
}
///*******************************************************************
void Protein::Print()
{
    cerr << "Type: " << type << endl
         << "protein Seq: " << seq << endl
         << "*****************************************" << endl;
}
///********************************************************************
Protein Protein:: operator+ (Protein p2)
{
    return Protein(seq + p2.seq);
}
///***********************************************************************************
bool Protein:: operator== (Protein p2)
{
    return (seq == p2.seq);
}

///***********************************************************************************
bool Protein:: operator!= (Protein p2)
{
    return (seq != p2.seq);
}
///********************************************************************************
ostream & operator << (ostream &Out, Protein& pr)
{
    if (pr.type == 0)
        Out << "Type: " << "Harmon" << endl;
    else if (pr.type == 1)
        Out << "Type: " << "Enzyme" << endl;
    else if (pr.type == 2)
        Out << "Type: " << "TF" << endl;
    else if (pr.type == 3)
        Out << "Type: " << "Cellular_Function" << endl;


    Out << "Protein Seq: " << pr.seq << endl
        << "*****************************************" << endl;
    return Out;
}
///**********************************************************************************
istream & operator >> (istream &in, Protein& pr)
{
    string t;
    cout << "Enter type of Protein: ";
    cin >> t;
    if (t == "Hormon")
        pr.type == Hormon;
    else if (t == "Enzyme")
        pr.type == Enzyme;
    else if (t == "TF")
        pr.type == TF;
    else if (t == "Cellular_Function")
        pr.type == Cellular_Function;

    cout << "Enter the sequence: ";
    in >> pr.seq;
    ///****************************** Exception Handling *******************
    for(int i = 0; i < pr.seq.length(); ++i)
    {
        if(pr.seq[i] != 'K' && pr.seq[i] != 'N' && pr.seq[i] != 'T' && pr.seq[i] != 'R' && pr.seq[i] != 'S' && pr.seq[i] != 'I' && pr.seq[i] != 'M' && pr.seq[i] != 'Q' && pr.seq[i] != 'H' && pr.seq[i] != 'P' && pr.seq[i] != 'L' && pr.seq[i] != 'E' && pr.seq[i] != 'D' && pr.seq[i] != 'G' && pr.seq[i] != 'V' && pr.seq[i] != 'Y' && pr.seq[i] != 'C' && pr.seq[i] != 'W' && pr.seq[i] != 'F')
        {
            throw Strange_Character_Protein();
        }
    }
    ///*********************************************************************
    return in;
}
///******************************************************************
DNA* Protein ::GetDNAStrandsEncodingMe(const DNA & bigDNA)
{
    DNA dn(bigDNA);
    RNA rn ( dn.ConvertToRNA());
    cout << rn << endl;
    CodonsTable co;
    co.LoadCodonsFromFile("RNA_codon_table.txt");
    DNA * dnPointer = new DNA[100];
    int counter = 0;
    for (int i = 0; i < rn.seq.length(); ++i)
    {

        string st = "";
        string st2 = "";

        int k = 0;
        for(int j = i; j < (seq.length() * 3 ) + i; ++j)
        {
            st += rn.seq[j];
            if(st.length()  == 3)
            {

                if( co.getAminoAcid(st) != seq[k])
                {

                    st = "";
                    st2 = "";

                    break;
                }
                if(co.getAminoAcid(st) == seq[k])
                {
                    st2 += st;

                }
                st = "";
                ++k;
            }
        }
        if (st2.length() == seq.length() * 3)
        {
            RNA rn2(st2, mRNA);
            DNA dn2("", 1, st2.length(),promoter);
            dn2 = rn2.ConvertToDNA();
            dnPointer[counter] = dn2;
            counter ++;
            i = (seq.length() * 3) + i - 1;
            //    cout << "dfghjkh" << endl;
            //cout << st2 << endl;
            //cout << dn2 << endl;
        }
    }
    return dnPointer;
}
///***************************************************************************
void Protein::Save_Data_To_File(string fileNameYouWantToSaveIn)
{
ofstream myfile;
  myfile.open ("fileNameYouWantToSaveIn");
  myfile << "The Sequence is: " << seq << endl << "The Type is: " << type << endl;
  myfile.close();
}
///************************************************************
void  Protein::Load_Data_From_File(string file_Name)
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
