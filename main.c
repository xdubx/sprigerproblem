#include <stdio.h>
#include <stdlib.h>



int main()
{
    int brettx = 4, bretty = 4;
    printf ("Bitte X angeben: ");
    scanf ("%d", &brettx);
    printf ("Bitte Y angeben: ");
    scanf ("%d", &bretty);

    int brett [bretty -1][brettx -1];       //Deklaration des Feldes
    int i, j = 0;                           //Variablen fuer die Schleifen


    for(i=0; i<bretty; i++)                 //Ausgabe des Schachfeldes
    {
        printf ("\n");
        for( j=0; j<brettx; j++)
        {
            brett[i][j] = moeglichkeiten(j,i,brettx-1,bretty-1);

            printf("%d ", brett[i][j]);
        }
    }

    //Hier gehts los
    int startx, starty;
    startx = 2;
    starty = 2;






    printf("\n\n Ende!\n");
    return 0;
}





int moeglichkeiten(int x, int y, int grenzex, int grenzey)              //Hier werden die Moeglichkeiten der einzelnen Positionen berechnet
{
        int k, zaehler = 0;                                             //Variablen fuer die Schleifen
        int zuege [8][2] = {                                            //Speicherung der Zuege in X und Y Richtung
            {-1, -2}, {+1, -2}, {-1, +2}, {+1, +2},
            {+2, -1}, {+2, +1}, {-2, -1}, {-2, +1}
            };


        for(k=0; k<8; k++)                                              //Alle Laufmoeglichkeiten werden durchgegangen und zurueckgegeben
        {
           if((x+zuege[k][0]>=0) && (y+zuege[k][1]>=0) && (x+zuege[k][0]<=grenzex) && (y+zuege[k][1]<=grenzey))
           {
               zaehler +=1;
           }
        }


        return zaehler;

}
