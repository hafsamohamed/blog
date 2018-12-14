///***************************************************************************************************************************************************
///***************************************************************************************************************************************************
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
///////////////////////////////////////////////////////////////// HEADERS/////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
#include<cstring>
#include "Codon.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <fstream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display()
{
    cerr << "*******************************************" << endl
         << "*******************************************" << endl
         << "Do you want" << endl
         << "1-To enter DNA" << endl
         << "2-To enter RNA" << endl
         << "3-To enter Protein" << endl
         << "4-To Print DNA" << endl
         << "5-To Print RNA" << endl
         << "6-To Print Protein" << endl
         << "7-To concatenate 2 sequence of DNA" << endl
         << "8-To concatenate 2 sequence of RNA" << endl
         << "9-To concatenate 2 sequence of Protein" << endl
         << "10-To know if 2 DNA sequences are equal" << endl
         << "11-To know if 2 RNA sequences are equal" << endl
         << "12-To know if 2 Protein sequences are equal" << endl
         << "13-To know if 2 DNA sequences are not equal" << endl
         << "14-To know if 2 RNA sequences are not equal" << endl
         << "15-To know if 2 Protein sequences not are equal" << endl
         << "16-Convert from DNA to RNA" << endl
         << "17-Convert from RNA to DNA" << endl
         << "18-Convert from RNA to Protein" << endl
         << "19-To Get DNA Strands Encoding Me" << endl
         << "20-To get AminoAcid" << endl
         << "21-To let 2 sequences of RNA equals" << endl
         << "22-To let 2 sequences of DNA equals" << endl
         << "23-To let 2 sequences of Protein equals" << endl
         << "24-To do LCS Alignment" << endl
         << "25-To exit" << endl
         << "26- To Save data to files ?!" << endl
         << "27- To Save load to files ?!" << endl
         << "*******************************************" << endl
         << "*******************************************" << endl;
}
int main()
{

    DNA dna, dna1, dna2;
    RNA rna, rna1, rna2;
    Protein pr, pr1, pr2;
    int  Choice = 0;
    Display();
    cout << "Enter choice: ";
    while (cin >> Choice)
    {
        ///******************************
        int choose;
        string file_Name;

        switch(Choice)
        {
        case 1:
            try
            {
                cin >> dna;
            }
            catch(Strange_Character_DNA &e)
            {
                cout << e.ERROR() << endl;
            }
            break;
        case 2:
            try
            {
                cin >> rna;
            }
            catch(Strange_Character_RNA &e)
            {
                cout << e.ERROR() << endl;
            }
            break;
        case 3:
            try
            {
                cin >> pr;
            }
            catch(Strange_Character_Protein &e)
            {
                cout << e.ERROR() << endl;
            }

            break;
        case 4:
            cout << dna;
            break;
        case 5:
            cout << rna;
            break;
        case 6:
            cout << pr;
            break;
        case 7:
            {


            cout << "DNA1:" << endl;
            try
            {
                cin >> dna;
            }
            catch(Strange_Character_DNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "DNA2:" << endl;
            try
            {
                cin >> dna1;
            }
            catch(Strange_Character_DNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "DNA1: " << endl << dna << endl << "DNA2: " << endl << dna1 << endl;
            DNA dn3 = dna + dna1;
            cout << "DNA1 + DNA2: " << endl << dn3 << endl;
            }
            break;
        case 8:
            {


            try
            {
                cin >> rna;
            }
            catch(Strange_Character_RNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "RNA2:" << endl;
            try
            {
                cin >> rna1;
            }
            catch(Strange_Character_RNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "RNA1: " << endl << rna << endl << "RNA2: " << endl << rna1 << endl;
            RNA r=rna + rna1;
            cout << "RNA1 + RNA2: " << endl << r << endl;
            }
            break;
        case 9:
            {


            cout << "Protein1:" << endl;
            try
            {
                cin >> pr;
            }
            catch(Strange_Character_Protein &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "Protein2:" << endl;
            try
            {
                cin >> pr1;
            }
            catch(Strange_Character_Protein &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "Protein1: " << endl << pr << endl << "Protein2: " << endl << rna1 << endl;
            Protein p=pr + pr1;
            cout << "Protein1 + Protein2: " << endl << p << endl;
        }
            break;
        case 10:
            {


            cout << "DNA1:" << endl;
            try
            {
                cin >> dna;
            }
            catch(Strange_Character_DNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "DNA2:" << endl;
            try
            {
                cin >> dna1;
            }
            catch(Strange_Character_DNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "DNA1: " << endl << dna << endl << "DNA2: " << endl << dna1 << endl;
            if(dna == dna1)
                cout << "the 2 DNA Sequences are equal" << endl;
            else
                cout << "the 2 DNA Sequences are not equal" << endl;
            }
            break;
        case 11:
            {


            try
            {
                cin >> rna;
            }
            catch(Strange_Character_RNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "RNA2:" << endl;
            try
            {
                cin >> rna1;
            }
            catch(Strange_Character_RNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "RNA1: " << endl << rna << endl << "RNA2: " << endl << rna1 << endl;
            if(rna == rna1)
                cout << "the 2 RNA Sequences are equal" << endl;
            else
                cout << "the 2 RNA Sequences are not equal" << endl;
        }
            break;
        case 12:
            {


            cout << "Protein1:" << endl;
            try
            {
                cin >> pr;
            }
            catch(Strange_Character_Protein &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "Protein2:" << endl;
            try
            {
                cin >> pr1;
            }
            catch(Strange_Character_Protein &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "Protein1: " << endl << pr << endl << "Protein2: " << endl << pr1 << endl;
            if(pr == pr1)
                cout << "the 2 Protein Sequences are equal" << endl;
            else
                cout << "the 2 Protein Sequences are not equal" << endl;
        }
            break;
        case 13:
            {


            cout << "DNA1:" << endl;
            try
            {
                cin >> dna;
            }
            catch(Strange_Character_DNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "DNA2:" << endl;
            try
            {
                cin >> dna1;
            }
            catch(Strange_Character_DNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "DNA1: " << endl << dna << endl << "DNA2: " << endl << dna1 << endl;
            if(dna != dna1)
                cout << "the 2 DNA Sequences are not equal" << endl;
            else
                cout << "the 2 DNA Sequences are equal" << endl;
        }
            break;
        case 14:
            {


            try
            {
                cin >> rna;
            }
            catch(Strange_Character_RNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "RNA2:" << endl;
            try
            {
                cin >> rna1;
            }
            catch(Strange_Character_RNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "RNA1: " << endl << rna << endl << "RNA2: " << endl << rna1 << endl;
            if(rna != rna1)
                cout << "the 2 RNA Sequences are not equal" << endl;
            else
                cout << "the 2 RNA Sequences are equal" << endl;
        }
            break;
        case 15:
            {


            cout << "Protein1:" << endl;
            try
            {
                cin >> pr;
            }
            catch(Strange_Character_Protein &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "Protein2:" << endl;
            try
            {
                cin >> pr1;
            }
            catch(Strange_Character_Protein &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "Protein1: " << endl << pr << endl << "Protein2: " << endl << pr1 << endl;
            if(pr != pr1)
                cout << "the 2 Protein Sequences are not equal" << endl;
            else
                cout << "the 2 Protein Sequences are equal" << endl;
            }
            break;
        case 16:
            {
            try
            {
                cin >> dna;
            }
            catch(Strange_Character_DNA &e)
            {
                cout << e.ERROR() << endl;
            }
            int start, endd;
            cout << "Enter start index: ";
            cin >> start;
            cout << "Enter end index: ";
            cin >> endd;
            dna.set_start_end(start, endd);
            cout << "Before Converting: " << endl;
            cout << dna;
            rna = dna.ConvertToRNA();
            cout << "After Converting: " << endl;
            cout << rna << endl;
        }
            break;
        case 17:
            try
            {
                cin >> rna;
            }
            catch(Strange_Character_RNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "Before Converting: " << endl;
            cout << rna;
            dna = rna.ConvertToDNA();
            cout << "After Converting: " << endl;
            cout << dna << endl;
            break;
        case 18:
            {


            try
            {
                cin >> rna;
            }
            catch(Strange_Character_RNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "Before Converting: " << endl;
            cout << rna;
            CodonsTable co;
            pr = rna.ConvertToProtein(co);
            cout << "After Converting: " << endl;
            cout << pr << endl;
            }
            break;
        case 19:
            {


            try
            {
                cin >> dna;
            }
            catch(Strange_Character_DNA &e)
            {
                cout << e.ERROR() << endl;
            }
            int start, endd;
            cout << "Enter start index: ";
            cin >> start;
            cout << "Enter end index: ";
            cin >> endd;
            dna.set_start_end(start, endd);
            cout << "Before Converting: " << endl;
            cout << dna;
            rna = dna.ConvertToRNA();
            CodonsTable c;
            pr = rna.ConvertToProtein(c);
            cout << "After Converting: " << endl;
            cout << pr << endl;
            }
            break;
        case 20:
            cout << "Enter Protein:" << endl;
            try
            {
                cin >> pr;
            }
            catch(Strange_Character_Protein &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "Enter DNA: " << endl;
            try
            {
                cin >> dna;
            }
            catch(Strange_Character_DNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "DNA Strands encoding me is: " << endl;
            DNA* dptr;
            dptr = pr.GetDNAStrandsEncodingMe(dna);
            for(int i = 0; i < dptr->GetSeq().length(); ++i)
            {
                cout << dptr[i] << endl;
            }
            break;
        case 21:
            {


            CodonsTable co1;
            Codon co;
            cout << "Enter value to get AminoAcid: ";
            cin >> co.value;
            co.AminoAcid = co1.getAminoAcid(co.value);
            cout << "The AminoAcid is: " << co.AminoAcid << endl;
            }
            break;
        case 22:
            {


            cout << "DNA1:" << endl;
            try
            {
                cin >> dna;
            }
            catch(Strange_Character_DNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "DNA2:" << endl;
            try
            {
                cin >> dna1;
            }
            catch(Strange_Character_DNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "Before: "<< endl;
            cout << dna << endl << dna1 << endl;
            dna = dna1;
            cout << "After: "<< endl;
            cout << dna << endl << dna1 << endl;
        }
            break;
        case 23:
            {


            try
            {
                cin >> rna;
            }
            catch(Strange_Character_RNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "RNA2:" << endl;
            try
            {
                cin >> rna1;
            }
            catch(Strange_Character_RNA &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "Before: "<< endl;
            cout << rna << endl << rna1 << endl;
            rna = rna1;
            cout << "After: "<< endl;
            cout << rna << endl << rna1 << endl;
        }
            break;
        case 24:
            {


            cout << "Protein1:" << endl;
            try
            {
                cin >> pr;
            }
            catch(Strange_Character_Protein &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "Protein2:" << endl;
            try
            {
                cin >> pr1;
            }
            catch(Strange_Character_Protein &e)
            {
                cout << e.ERROR() << endl;
            }
            cout << "Before: "<< endl;
            cout << pr << endl << pr1 << endl;
            pr = pr1;
            cout << "After: "<< endl;
            cout << pr << endl << pr1 << endl;
        }
            break;
    case 25:
        {


        Sequence* s1, *s2;
        string type = "";
        cout << "Enter 2 sequences to do alignment: " << endl;
        cout << "Enter type of Sequence 1: ";
        cin >> type;
        if (type == "DNA" || type == "dna")
        {
            cout << "Enter DNA Sequence: " << endl;
            cin >> dna;
            s1 = new DNA(dna);
        }
        else if (type == "RNA" || type == "rna")
        {
            cout << "Enter RNA Sequence: " << endl;
            cin >> rna;
            s1 = new RNA(rna);
        }
        else
        {
            cout << "Enter Protein Sequence: " << endl;
            cin >> pr;
            s1 = new Protein(pr);
        }
        cout << "Enter type of Sequence 2: ";
        cin >> type;
        if (type == "DNA" || type == "dna")
        {
            cout << "Enter DNA Sequence: " << endl;
            cin >> dna;
              s2 = new DNA(dna);
        }
        else if (type == "RNA" || type == "rna")
        {
            cout << "Enter RNA Sequence: " << endl;
            cin >> rna;
            s2 = new RNA(rna);
        }
        else
        {
            cout << "Enter Protein Sequence: " << endl;
            cin >> pr;
            s2 = new Protein(pr);
        }
        cout << Align(s1, s2) << endl;
        }
        break;
    case 26:
        {


        cerr << "1-Do you want to save Data From DNA ?" << endl
             << "2-Do you want to save Data From RNA ?" << endl
             << "3-Do you want to save Data From Protein ?" << endl
             << "Enter Choice: ";
        cin >> choose;

        if(choose == 1)
        {
            cout << "Enter the DNA" << endl;
            cin >> dna;
            cout << "Enter the file name you want to save the data in : " ;
            cin >> file_Name;
            dna.Save_Data_To_File(file_Name);
            cout << "The Data has been Saved !!" << endl;
        }
        else if(choose == 2)
        {
            cout << "Enter the RNA" << endl;
            cin >> rna;
            cout << "Enter the file name you want to save the data in : " ;
            cin >> file_Name;
            rna.Save_Data_To_File(file_Name);
            cout << "The Data has been Saved !!" << endl;
        }
        else if(choose == 3)
        {
            cout << "Enter the Protein" << endl;
            cin >> pr;
            cout << "Enter the file name you want to save the data in : " ;
            cin >> file_Name;
            pr.Save_Data_To_File(file_Name);
            cout << "The Data has been Saved !!" << endl;
        }}
        break;
    case 27:
        cerr << "1-Do you want to load Data From DNA ?" << endl
             << "2-Do you want to load Data From RNA ?" << endl
             << "3-Do you want to load Data From Protein ?" << endl
             << "Enter Choice: ";
        cin >> choose;
        if(choose == 1)
        {
            cout << "Enter the file name you want to load data from : " ;
            cin >> file_Name;
            dna.Load_Data_From_File(file_Name);
            cout << "The Data has been Loaded !!" << endl;
        }
        else if(choose == 2)
        {
            cout << "Enter the file name you want to Load data from : " ;
            cin >> file_Name;
            rna.Load_Data_From_File(file_Name);
            cout << "The Data has been Loaded !!" << endl;
        }
        else if(choose == 3)
        {
            cout << "Enter the file name you want to load data from : " ;
            cin >> file_Name;
            pr.Load_Data_From_File(file_Name);
            cout << "The Data has been Loaded !!" << endl;
        }
        break;
    }
    Display();
    cout << "Enter choice: ";
}
//
/////************ Exception Handling *************************
/////DNA !! #######
//try
//{
//    Sequence * s1 = new DNA("TAGCCW",promoter);
//}
//catch(Strange_Character_DNA &e)
//{
//    cout << e.ERROR() << endl;
//}
/////*************************
//try
//{
//    DNA dn;
//    cin >> dn;
//}
//catch(Strange_Character_DNA &e)
//{
//    cout << e.ERROR() << endl;
//}
/////**********************************
/////RNA !! ##########
//try
//{
//    Sequence * s1 = new RNA("TAGCCW",mRNA);
//}
//catch(Strange_Character_RNA &e)
//{
//    cout << e.ERROR() << endl;
//}
/////*************************
//try
//{
//    RNA dn;
//    cin >> dn;
//}
//catch(Strange_Character_RNA &e)
//{
//    cout << e.ERROR() << endl;
//}
/////**********************************
/////Protein !! ##########
//try
//{
//    Sequence * s2 = new Protein("TAGCCW");
//}
//catch(Strange_Character_Protein &e)
//{
//    cout << e.ERROR() << endl;
//}
/////*************************
//try
//{
//    Protein pr;
//    cin >> pr;
//}
//catch(Strange_Character_Protein &e)
//{
//    cout << e.ERROR() << endl;
//}


return 0;

}
