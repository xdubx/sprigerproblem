#include <stdio.h>
#include <stdlib.h>


/*
        x
   ---------->
   |
y  |    feld[y][x];
   |
   |
   V


*/

int kombis[8][2]={{-2, -1},
                {-2, +1},
                {+2, -1},
                {+2, +1},
                {-1, +2},
                {+1, +2},
                {-1, -2},
                {+1, -2}};

int main()
{
    int size = 8;
    int feld[size][size];
    int i, j;
    printf("Das ist das Feld: \n\n");
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            printf("%d ", 0);
            feld[i][j] = 0;
        }
        printf("\n");
    }


    //Start
    getnextpoint(0,0,size,feld);

    return 0;
}




int getzuege(int Y, int X, int size, int feld[size][size]) //Hier wird die anzahl der naechsten Zuege ueberprueft
{
   int zuege = 0;
   int i, j;
   for(i=0; i<size; i++)
   {
       if(Y+kombis[i][0]>=0 && Y+kombis[i][0]<size && X+kombis[i][1]>=0 && X+kombis[i][1]<size && feld[Y+kombis[i][0]][X+kombis[i][1]]==0) zuege +=1;
   }
   return zuege;

}



int counter = 1;


void getnextpoint(int Y, int X, int size, int feld[size][size])
{
    int nextPoint[8][3]; //speicher fuer die naechsten moeglichen Punkte
    int i, j = 0;

    printf("\nAktuelles Standpunkt: Y: %d, X: %d", Y, X);

    feld[Y][X] = counter++;
    printf("\nCounter: %d", counter);


    for( i=0; i<8; i++)
    {
        for( j=0; j<3; j++)
        {
             nextPoint[i][j] = -1;
        }
    }

    for(i=0; i<size; i++)
    {
       if(Y+kombis[i][0]>=0 && Y+kombis[i][0]<size && X+kombis[i][1]>=0 && X+kombis[i][1]<size && feld[Y+kombis[i][0]][X+kombis[i][1]]==0)
       {
           nextPoint[i][0] = Y + kombis[i][0];
           nextPoint[i][1] = X + kombis[i][1];
           nextPoint[i][2] = getzuege(Y + kombis[i][0], X + kombis[i][1], size, feld);
       }
    }

    printf("\n");
    for( i=0; i<8; i++)
    {
        printf("\n");
        for( j=0; j<3; j++)
        {
            printf("%d ", nextPoint[i][j]);
        }
    }


    int kleinste, kX, kY;
    kX = kY = 0;
    kleinste = 100;
    for(i=0; i<8; i++)
    {
        if (nextPoint[i][2]<kleinste && nextPoint[i][2]>-1 )
        {
            kY = nextPoint[i][0];
            kX = nextPoint[i][1];
            kleinste = nextPoint[i][2];
        }
    }
    printf("\nIch empfehle: X: %d, Y: %d, mit den Moeglichkeiten: %d", kX, kY, kleinste);
    feldausgabe(size, feld);



    if ( kleinste!=100) getnextpoint(kY, kX, size, feld); //rekursion, solange es noch einen naechsten Punkt gibt
    else feldausgabe(size,feld);


}


void feldausgabe(int size, int feld[size][size])
{
    int i, j;
    printf("\n\n");
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            printf("%2d ", feld[i][j]);

        }
        printf("\n");
    }
}


