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
string  Align(Sequence * s1, Sequence * s2)
{
    string String1 = "";
    string String2 = "";
    if(s1->seq.length() >  s2->seq.length())
    {
        String1 = s1->seq;
        String2 = s2->seq;
    }
    else if(s2->seq.length() >  s1->seq.length())
    {
        String1 = s2->seq;
        String2 = s1->seq;
    }
    else if(s1->seq.length() ==  s2->seq.length())
    {
        String1 = s1->seq;
        String2 = s2->seq;
    }

    int FirstIndex = -1;
    string st = "";
    string st2 = "";
    for(int k = 0; k < String2.length(); ++k)
    {

        for(int i = k; i < String2.length() ; ++i)
        {
            for(int j = 0; j < String1.length() ; ++j)
            {
                if(( String2[i] == String1[j] ) && ( j > FirstIndex ))
                {
                    FirstIndex = j;
                    st += String2[i];
                    break;
                }
            }

            if(st.length() > st2.length())
                st2 = st;

        }

    }
    return st2;
}
///************************************************************
///************************************************************
///************************************************************