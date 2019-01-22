#include "answer.h"

string pytanie(int nr,int swth)
{
    string odpPoprawna;
    fstream plik;
    string odp_A,odp_B,odp_C,odp_D,tresc;
    int nr_linii;
    int aktualny_nr_linii=1;
    string linia_tekstu;
    nr_linii=(nr-1)*6+1;
    plik.open("quiz.txt");
    while(getline(plik,linia_tekstu))
    {
        if(aktualny_nr_linii==nr_linii)tresc=linia_tekstu;
        if(aktualny_nr_linii==nr_linii+1)odp_A=linia_tekstu;
        if(aktualny_nr_linii==nr_linii+2)odp_B=linia_tekstu;
        if(aktualny_nr_linii==nr_linii+3)odp_C=linia_tekstu;
        if(aktualny_nr_linii==nr_linii+4)odp_D=linia_tekstu;
        if(aktualny_nr_linii==nr_linii+5)odpPoprawna=linia_tekstu;
        aktualny_nr_linii++;
    }
    plik.close();
    if(swth==1)
    {
        return tresc;
    }
    else if(swth==2)
    {
        return odp_A;
    }
    else if (swth==3)
    {
        return odp_B;
    }
    else if(swth==4)
    {
        return odp_C;
    }
    else if(swth==5)
    {
        return odp_D;
    }
    else if(swth==6)
    {
        return odpPoprawna;
    }
}
