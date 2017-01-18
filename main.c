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
    int feld[8][8];
    int i, j;
    printf("Das ist das Feld: \n\n");
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            printf("%d ", 0);
            feld[i][j] = 0;
        }
        printf("\n");
    }
 /*   for(i=0; i<8; i++)
    {
        feld[i][3] = getzuege(i,3,8,feld);
    }
    feldausgabe(8, feld);
*/
    getnextpoint(0,0,8,feld);

    return 0;
}




int getzuege(int Y, int X, int size, int feld[size][size])
{
   int zuege = 0;
   int i, j;
   for(i=0; i<8; i++)
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


    feld[Y][X] = counter++;



    for( i=0; i<8; i++)
    {
        for( j=0; j<3; j++)
        {
             nextPoint[i][j] = -1;
        }
    }

    for(i=0; i<8; i++)
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
        if (nextPoint[i][2]<kleinste && nextPoint[i][2]>0 )
        {
            kY = nextPoint[i][0];
            kX = nextPoint[i][1];
            kleinste = nextPoint[i][2];
        }
    }
    printf("\nIch empfehle: X: %d, Y: %d, mit den Moeglichkeiten: %d", kX, kY, kleinste);
    feldausgabe(8, feld);



    if ( kleinste!=100)getnextpoint(kY, kX, 8, feld);


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


