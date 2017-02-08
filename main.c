#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 4
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
int ex,ey = 0;
// global vars
short debug = 0;
int counter = 1;
char alp[26]={'A','B','C','D','E','F','G','H','I','J'}; //complete it later...
short close = 1;
int backbool = 0;
int backi = 0;
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

    ex = 3;
    ey = 3;
    //getnextpoint(ey,ex,size,feld, feld3, 0);
    printHeadline();
    return 0;
}
void printStrip(char lhml, char lhmr,char lv,int size){
	printf("%c", lhml);
	int i = 0;
	for(i=2;i<size;i++){
		printf("%c", lv);
	}
	printf("%c\n", lhmr);
}
int getInputAndConvert(){
	bool gueltig = false;
	char input[3];
	do{
		//check if first letter a alph and sec a number

		// get first char and set it to upper case - convert from alph to int
		// sec char to int

	}while(!gueltig);
}
void printHeadline(){
	// Const vars
	//oben links
	char elo = 201;
	char elu = 200;
	//oben rechts
	char ero = 187;
	char eru = 188;
	//leisten
	char lh = 186;
	char lv = 205;
	// leiste mit mttelabzweigung
	char lhml= 204;
	char lhmr = 185;
	int sizeh = 30;
	// Vars end

	//head
	printStrip(elo, ero, lv, sizeh);

	printf("%c", lh);
	//TODO center it charstring with for func to calc with sizeh
	printf("SPRINGERPROBLEM"); // zeichen von einem springer als logo
	printf("%c\n", lh);
	//mittel leiste
	printStrip(lhml, lhmr, lv, sizeh);
	//head END
	// content
	// OPTIONS HERE with calc to end and place char maybe func to center
	printf("%c   1. Beschreibung   %c\n",lh,lh);
	printf("%c   2. Beschreibung   %c\n",lh,lh);
	printf("%c   3. Beschreibung   %c\n",lh,lh);
	printf("%c   4. Beschreibung   %c\n",lh,lh);
	//mittel leiste
	printStrip(lhml, lhmr, lv, sizeh);

	// eingabe mit einer while abfrage
	printf("%c ", lh);
	int eingabe = 0;
	bool gueltig = false;
	do{
		scanf("%d", &eingabe);
		//open path
		if(eingabe == 1){
			gueltig = true;
			//close design
			printStrip(elu,eru,lv,sizeh);
			// start func with options
		}else if(eingabe == 2){
			gueltig = true;
			// start func with options
		}else if(eingabe == 3){
			gueltig = true;
			// start func with options
		}else if(eingabe == 4){
			gueltig = true;
			// start func with options
		}else{
			printf("%c Eingabe ungültig bitte versuchen Sie es erneut! %c", lv,lv);
		}

	}while(!gueltig);
	// abschluss ?

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
/*


*/


void getnextpoint(int Y, int X, int size, int feld[size][size], int feld3[size][size], int back){
    int nextPoint[8][3]; //speicher fuer die naechsten moeglichen Punkte
    int i, j = 0;

    //feldausgabe(size,feld);
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
       // printf("\n%d>=0 && %d<8 && %d>=0 && %d<8 && %d==0 && %d != %d",Y+kombis[i][0], Y+kombis[i][0], X+kombis[i][1], X+kombis[i][1],feld[Y+kombis[i][0]][X+kombis[i][1]], feld3[Y+kombis[i][0]][X+kombis[i][1]], (Y*10+X));
       //allgemeine abfrage ob im feld oder gültiger zug
       if(Y+kombis[i][0]>=0 && Y+kombis[i][0]<size && X+kombis[i][1]>=0 && X+kombis[i][1]<size && feld[Y+kombis[i][0]][X+kombis[i][1]]==0)
       {
           if(feld3[Y+kombis[i][0]][X+kombis[i][1]] != (Y*10+X)){
                nextPoint[i][0] = Y + kombis[i][0];
                nextPoint[i][1] = X + kombis[i][1];
                nextPoint[i][2] = getzuege(Y + kombis[i][0], X + kombis[i][1], size, feld, feld3);
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
    kX = kY = -1;
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

            //TODO for NxM Field backtrack

        }else if (counter >= (size*size) && kleinste ==100){
            feld[Y][X] = counter++;
            printf("Counter:%d finish", counter);
            feldausgabe(size,feld); // fertig
        }
    }else{
        //closed path
        //printf("\n %d != 100 && %d != (64) && %d == %d && %d == %d", kleinste, counter, ey, kY,ex,kX );
        if(counter==1 && ey == Y && ex == X && kleinste == 100){
            printf("Abbruch!");
            return 0;
        }else if(counter == (size*size) && (ey == kY && ex == kX)){
            // go on last coords
            feld[Y][X] = counter++;
            feld[kY][kX] = counter++;
            feldausgabe(size,feld);
            printf("\nLast Point reach!");
        }else if (counter <= (size*size) && kleinste == 100){
            //printf("\nKeine Loesung! b:%d", back);
            //TODO goback
            //printf("\nFirst field set to 1!");
            feld[ey][ex] = 1;
            feld[Y][X] = 0;
            int lastX = 0;
            int lastY = 0;
            if(back >= 1){
               // printf("\n%d", back);
                while(back >= 1){
                    for(i=0; i<size; i++){
                        for(j=0; j<size; j++){
                            if(feld[i][j] == counter-1 && counter != 0){
                                if(counter >= 2){
                                    counter--;
                                }
                                if(back == 1){
                                    feld3[lastY][lastX] = (i*10+j);
                                    backi = (i*10+j);
                                  // printf("\nWrite in Y:%d X:%d = %d", i, j, feld3[lastY][lastX]);
                                }else{
                                    if(backi != feld3[i][j]){
                                        feld3[i][j] = -1;
                                    }
                                }
                                feld[i][j] = 0;
                                //printf("\nY:%d X:%d" , j,i);
                                //feldausgabe(size,feld);
                                //feldausgabe(size,feld3);
                                lastY = i;
                                lastX = j;
                               // printf("\nGOTO to Y:%d X:%d Counter: %d Back: %d", lastY,lastX, counter, back);
                                //printf("\n-----------------------------");
                                back-=1;
                                if(back == 0){
                                   // printf("%d", back);
                                    getnextpoint(lastY, lastX, size, feld, feld3, back);
                                }
                            }
                        }
                    }
                }
            }else{
            if(feld3[Y][X] == -1){
                backbool = 1;
                back=0;
            }
            // i = Y und j = X
            // go back first back
            //printf("\nfirst back");
            for(i=0; i<size; i++)
            {
                for(j=0; j<size; j++)
                {
                 if(feld[i][j] == counter-1 && counter != 0){
                    if(counter >= 2){
                        counter--;
                    }
                    if(back == 0){
                        feld3[Y][X] = (i*10+j);
                        backi = (i*10+j);
                        //printf("\nWrite in Y:%d X:%d = %d", Y, X, feld3[Y][X]);
                    }else{
                        if(backi != feld3[i][j]){
                            feld3[i][j] = -1;
                        }
                    }
                    //feldausgabe(size,feld);
                    //feldausgabe(size,feld3);
                    //printf("\nGOTO in Y:%d X:%d ", i,j);
                    getnextpoint(i, j, size, feld, feld3, back);
                 }
                }
            }
            }


        }else if(kleinste != 100 && counter != (size*size+1)){ //&& ey != Y && ex != X
            if(debug == 1){
                printf("\nIch empfehle: X: %d, Y: %d, mit den Moeglichkeiten: %d\n-----------\n", kX, kY, kleinste);
            }
            feld[Y][X] = counter++;
            //printf("\n%d", feld[Y][X]);

            if(counter == ((size * size))){
               // gebe letztes feld frei damit er drauf laufen kann
              // printf("\nFirst field reset!");
                feld[ey][ex] = 0;
            }
            if(backbool == 1){
                back +=1;
            }
            //feldausgabe(size,feld);
            //feldausgabe(size,feld3);
            int useless = 0;
            //scanf("%d", &useless);
          getnextpoint(kY, kX, size, feld, feld3, back); //rekursion, solange es noch einen naechsten Punkt gibt

        }
    }
}

//TODO Add Chars to the field maybe with cool output
void feldausgabe(int size, int feld[size][size]){
    //int vars
    int i, j;

    //make some place to display the field
    printf("\n");
    for(j=0; j<(size); j++){
        //print the char at the top
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
