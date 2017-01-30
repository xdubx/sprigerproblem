#include <stdio.h>
#include <stdlib.h>

int x;
int y;
int VektorX;
int VektorY;
int PruefungX[100];
int PruefungY[100];
int counter=0;


void Setup()
{
    int Koordinaten[1][7] = {{1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8}};
}

void Eingabe()
{
    scanf("%d",&x);
    scanf("%d",&y);

    printf("Die X-Koordinate: %d    \n",x);
    printf("Die Y-Koordinate: %d    \n",y);
}


void Vektor()
{   int a;
    int b;


    int Vektoren[3] = {1,2,-1,-2};



    do
    {
        a = rand()%+3;
        b = rand()%+3;
    }
    while(a==b);

    VektorX = Vektoren[a];
    VektorY = Vektoren[b];

   printf("Vektor X:%d  \n",VektorX);
   printf("Vektor Y:%d  \n",VektorY);
}

void Safe()
{


    PruefungX[counter]=x;
    PruefungY[counter]=y;

    counter++;


}

void Check()
{
   int i;
   for(i=0;i<counter;i++)
   {
     if((x==PruefungX[i])&&(y==PruefungY[i]))
     {
         ///////////////////
     }



   }

}


void Berechnung()
{
    x = x+VektorX;
    y = y+VektorY;

    printf("Neues Feld X:%d  \n",x);
    printf("Neues Feld Y:%d  \n",y);


}




int main()
{
    Setup();
    Eingabe();
    Vektor();
    Safe();
    Check();
    Berechnung();






    return 0;
}
