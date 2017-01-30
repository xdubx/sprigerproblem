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

// TODO
Add cloesed Path
add backtrack

*/
//prototype functions
 int posLetterToInt(char posL);

// global vars
short debug = 0;
char alp[26]={'A','B','C','D','E','F','G','H','I','J'}; //complete it later...
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


    //Start // INPUT // TODO

    //printf("Bitte geben Sie die Startposition an:");
    //char input[2];
    //scanf("%c", input);

    //Split input to 2 chars and transform it to ints
    char x1,y1;
    getnextpoint(0,0,size,feld);
    return 0;
}




int getzuege(int Y, int X, int size, int feld[size][size]) //Hier wird die anzahl der naechsten Zuege ueberprueft
{
   int zuege = 0;
   int i, j;
   // const 8 für die max anzahl an zuegen
   for(i=0; i<8; i++)
   {
       if(Y+kombis[i][0] >= 0 && Y+kombis[i][0] < 8 && X+kombis[i][1] >= 0 && X+kombis[i][1] < 8 && feld[Y+kombis[i][0]][X+kombis[i][1]] == 0 ){
            zuege +=1;

       }
   }
   return zuege;

}



int counter = 1;


void getnextpoint(int Y, int X, int size, int feld[size][size]){
    int nextPoint[8][3]; //speicher fuer die naechsten moeglichen Punkte
    int i, j = 0;

    if(debug == 1){
        printf("\nAktueller Standpunkt: Y: %d, X: %d", Y, X);
        printf("\tCounter: %d", counter);
    }
    feld[Y][X] = counter++;

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

    if (kleinste != 100){
        if(debug == 1){
           // printf("\nIch empfehle: X: %d, Y: %d, mit den Moeglichkeiten: %d", kX, kY, kleinste);
        }
        getnextpoint(kY, kX, size, feld); //rekursion, solange es noch einen naechsten Punkt gibt
    }else{
        printf("Counter:%d", counter);
         feldausgabe(size,feld); // fertig
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

// ADD Controll of calc
