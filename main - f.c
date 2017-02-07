#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
/*
Erläuterungen für den Code
        x
   ---------->
   |
y  |    feld[y][x];
   |
   |
   V

*/
//prototype functions
 int posLetterToInt(char posL);
int ex,ey = 0;
// global vars
short debug = 1;
int counter = 1;
char alp[26]={'A','B','C','D','E','F','G','H','I','J'}; //complete it later...
short close = 1;
int backbool = 0;
int kombis[8][2]={
                {-2, -1},
                {-2, +1},
                {+2, -1},
                {+2, +1},
                {-1, +2},
                {+1, +2},
                {-1, -2},
                {+1, -2}
                };

int main(){
    int size = SIZE;
    int feld[size][size];
    int feld3[size][size];
    int i, j;
    printf("Das ist das Feld: \n\n");
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            printf("%d ", 0);
            feld[i][j] = 0;
            feld3[i][j] = -1;
        }
        printf("\n");
    }


    //Start // INPUT // TODO

    //printf("Bitte geben Sie die Startposition an:");
    //char input[2];
    //scanf("%c", input);

    //Split input to 2 chars and transform it to ints
    char x1,y1;
    ex=2;
    ey=2; //Erste Position
    getnextpoint(ey,ex,size,feld, feld3, 0);

    return 0;
}




int getzuege(int Y, int X, int size, int feld[size][size], int feld3[size][size]) //Hier wird die anzahl der naechsten Zuege ueberprueft
{
   int zuege = 0;
   int i, j;
   // const 8 für die max anzahl an zuegen
   for(i=0; i<8; i++)
   {

       if(Y+kombis[i][0] >= 0 && Y+kombis[i][0] < 8 && X+kombis[i][1] >= 0 && X+kombis[i][1] < 8){
            // neue if mit feld da sonst outside and falsche werte
             //printf("\n%d>=0 && %d<8 && %d>=0 && %d<8 && %d==0 && %d != %d",Y+kombis[i][0], Y+kombis[i][0], X+kombis[i][1], X+kombis[i][1],feld[Y+kombis[i][0]][X+kombis[i][1]], feld3[Y+kombis[i][0]][X+kombis[i][1]], (Y*10+X));
            if(feld[Y+kombis[i][0]][X+kombis[i][1]] == 0 && feld3[Y+kombis[i][0]][X+kombis[i][1]] != (Y*10+X)){
                zuege +=1;
            }
       }
   }

   return zuege;

}


void getnextpoint(int Y, int X, int size, int feld[size][size], int feld3[size][size], int back){
    int nextPoint[8][3]; //speicher fuer die naechsten moeglichen Punkte
    int i, j = 0;
    if(counter == 1){
    ex = X;
    ey = Y;
    }
    if(debug == 1){
        printf("\nAktueller Standpunkt: Y: %d, X: %d", Y, X);
        printf("\tCounter: %d", counter);
    }


    for( i=0; i<8; i++)
    {
        for( j=0; j<3; j++)
        {
             nextPoint[i][j] = -1;
        }
    }

    for(i=0; i<8; i++)
    {
        //allgemeine abfrage ob im feld oder gültiger zug
       if(Y+kombis[i][0]>=0 && Y+kombis[i][0]<size && X+kombis[i][1]>=0 && X+kombis[i][1]<size && feld[Y+kombis[i][0]][X+kombis[i][1]]==0)
       {
        printf("\nCounter bei Neuen Zuegen: %d", counter);
        if(feld3[Y+ kombis[i][0]][X+ kombis[i][1]] != counter+1){

            nextPoint[i][0] = Y + kombis[i][0];
            nextPoint[i][1] = X + kombis[i][1];
            nextPoint[i][2] = getzuege(Y + kombis[i][0], X + kombis[i][1], size, feld, feld3);
        }else{
            printf("\nFeld wurde schon mal besucht!\n Y=%d, X=%d \n", Y+kombis[i][0], X+kombis[i][1]);

       }
       }
    }
    if(debug == 1){
        printf("\nY X M");
        for( i=0; i<8; i++)
        {
            printf("\n");
            for( j=0; j<3; j++)
            {
                printf("%d ", nextPoint[i][j]);
            }
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
    //feldausgabe(size, feld);
    // open or closed path open = 0
    if(close == 0){
            //open path
        if (kleinste != 100){
            if(debug == 1){
                printf("\nIch empfehle: X: %d, Y: %d, mit den Moeglichkeiten: %d\n-----------\n", kX, kY, kleinste);
            }
            feld[Y][X] = counter++;
            getnextpoint(kY, kX, size, feld, feld3, back); //rekursion, solange es noch einen naechsten Punkt gibt
        }else if (counter < (size*size) && kleinste == 100){
            feld3[Y][X] = 1;
            printf("\n Backtrack!");

            feldausgabe(size,feld);
            feldausgabe(size,feld3);
            //

            //TODO controll why in a corner and go back maybe?

        }else if (counter >= (size*size) && kleinste ==100){
            feld[Y][X] = counter++;
            printf("Counter:%d finish", counter);
            feldausgabe(size,feld); // fertig
        }
    }else{
        //Geschlossener Weg
        if(counter==size*size) feld[ey][ex]=0;
        if(counter<size*size) feld[ey][ex] = 1;
        if(counter == size*size +1 && Y == ey && X == ex){
            feldausgabe(size,feld);
            printf("\nFertig\n");
        }else if (counter == 0){
            printf("\nKein Geschlossener Zug vorhanden!!\n");
        }else if (kleinste == 100){
            printf("\nSackgasse\n");
            feld3[Y][X] = counter;

            int posX = 0;
            int posY = 0;
            posatcounter(size, feld, --counter, &posY, &posX);
            feld3[posY][posX] = counter;
            printf("Koordinaten Y= %d, X= %d, bei Counter: %d", posY, posX, counter);
            feld[posY][posX] = 0;



            feldausgabe(size, feld);
            feldausgabe(size, feld3);
            //scanf("%d");
            getnextpoint(posY, posX, size, feld, feld3, back);

        }else{
            feld[Y][X] = counter++;
            getnextpoint(kY, kX, size, feld, feld3, back);
        }

    }

}

//gibt die Koordinaten eines Punktes bei einem Bestimmten counter zurück
void posatcounter(int size, int feld[size][size], int step, int *posY, int *posX){

    int i, j=0;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if (feld[i][j] == step){
              *posY = i;
              *posX = j;
              break;
            }
        }

    }


}


//TODO Add Chars to the field maybe with cool output
void feldausgabe(int size, int feld[size][size]){
    //int vars
    int i, j;

    //
    printf("\n\n ");
    for(j=0; j<(size); j++){
        printf("|%2c ", alp[j]);
    }
        printf("\n");
    // set lines between the numbers vertical
    for(j=0; j<(size*2); j++){
        printf("--");
    }

    for(i=0; i<size; i++)
    {
        printf("\n");

        //print the decription on the left side
        printf("%d", i);
        //print the movement
        for(j=0; j<size; j++)
        {
            printf("|%2d ", feld[i][j]);

        }
        printf("\n");
        // set lines between the numbers vertical
        for(j=0; j<(size*2); j++){
            printf("--");
        }
    }
}

// add FUNC
// vill zur optimierung ifs verwenden?
int posLetterToInt(char posL){
    // putchar()
    switch(posL){
		case 'A':
			return 1;
		case 'B':
			return 2;
		case 'C':
			return 3;
		case 'D':
			return 4;
		case 'E':
			return 5;
		case 'F':
			return 6;
		case 'G':
			return 7;
		case 'H':
			return 8;
		default:
		printf("Es ist ein Fehler unterlaufen! Abbruch...");
		//wait(2);
		exit(1);
	}
}
