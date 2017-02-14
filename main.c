#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
add backtrack for the closed path
*/
//-------- [DEBUG OPTIONS] ----------
short debug = 0; // set to 1 to show output
//-------- [DEBUG OPTIONS] ----------

// -------- [prototype functions] ----------
 int posLetterToInt(char posL);
 void printHeadline(int size, int feld[size][size], int feld3[size][size]);
// -------- [END prototype functions] ----------

// -------- [GLOBAL VARS] ----------
// FORMAT VARS abkürzungen von der zeichentabelle beschreibung der zeichen
char elo = 201;  // ╔
char elu = 200;  // ╚
char ero = 187;  // ╗
char eru = 188;  // ╝
char lh = 186;   // ═
char lv = 205;   // ║
char lhml= 204;  // ╠
char lhmr = 185; // ╣
char rdvl = 206; // ╬
char rdlu = 203; // ╦
char rdro = 202; // ╩
// define the size of the print format
int sizeh = 50;
// END FORMAT VARS

// PROGRAMM VARS
int ex,ey = 0;
int counter = 1;
char alp[26]={'A','B','C','D','E','F','G','H','I','J'}; //complete it later...
short close = 0;
int backbool = 0;
int backi = 0;
short foundS = 0;
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
// END PROGRAMM VARS
// -------- [GLOBAL VARS END] ----------

int main(){
    int size = SIZE;
    int feld[size][size];
    int feld3[size][size];
    int i, j;
    // create playfield
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            feld[i][j] = 0;
            feld3[i][j] = -1;
        }
    }
    printHeadline(size, feld, feld3);
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
void printTextCentered(char lh, int sizeh, char text[]){
    // check len
    int len = strlen(text);
    int spaceLR = (sizeh-len)/2;
    printf("%c", lh);
    int i;
    for(i=0; i< spaceLR;i++){
        printf(" ");
    }
    printf("%s",text);
    for(i=0; i< spaceLR-1;i++){
        printf(" ");
    }
    printf("%c\n", lh);
}
void getInputAndConvert(int *uy, int *ux, int size){
	bool valid = false;
	int inputx;
	char inputy;
	do{
		//check if first letter a alph and sec a number

		// get first char and set it to upper case - convert from alph to int
		// sec char to int
		scanf("%c", &inputx);       //we need this but I dont know why
        printf("Bitte Y Punkt  als Buchstaben angeben:");
        scanf("%c", &inputy);
        printf("Bitte X Punkt  als Zahl angeben:");
        scanf("%d", &inputx);
        if(posLetterToInt(inputy)>=0 && posLetterToInt(inputy)<size && inputx>=0 && inputx<=size) valid = true;
        //check if point is possible


	}while(!valid);
	printf("\nIhre Auswahl: %c%d\n", inputy, inputx );
	*uy = posLetterToInt(inputy);
	*ux = inputx;
}
void printHeadline(int size, int feld[size][size], int feld3[size][size]){
	//def vars
	char nameOfProgramm[] = "SPRINGERPROBLEM";
    char errorWithInput[] = "Eingabe ungultig!";
    char randomPoint[] = "Vom Programm wurde ein zufaelliger Punkt gewaehlt";
	//head
	printStrip(elo, ero, lv, sizeh);
	//print name of programm
    printTextCentered(lh,sizeh,nameOfProgramm);
	//mittel leiste
	printStrip(lhml, lhmr, lv, sizeh);
	//head END

	// content
	// OPTIONS HERE
	printf("%c   1. Offener Zug mit freiem Punkt              %c\n",lh,lh);
	printf("%c   2. Offener Zug mit vorgegebenem Punkt        %c\n",lh,lh);
	printf("%c   3. Geschlossener Zug mit freiem Punkt        %c\n",lh,lh);
	printf("%c   4. Geschlossener Zug mit vorgegebenem Punkt  %c\n",lh,lh);
	//mittel leiste
	printStrip(lhml, lhmr, lv, sizeh);

	// eingabe mit einer while abfrage
	printf("%c ", lh);
	int eingabe = 0;
	bool valid = false;
	int coords = 0;
	do{
		scanf("%d", &eingabe);
		//open path
		if(eingabe == 1){
			//close design
			valid = true;
			printStrip(elu,eru,lv,sizeh);
			close = 0; //Angabe für offenen Zug
			getInputAndConvert(&ey, &ex, size); //ask user for point
			getnextpoint(ey, ex, size, feld, feld3, 0);
			// start func with options
		}else if(eingabe == 2){
			valid = true;
			printStrip(elu,eru,lv,sizeh);
			close = 0; //open move
			getrandompoint(&ey, &ex, size);
            printTextCentered(lh, sizeh,randomPoint);
			getnextpoint(ey,ex,size,feld, feld3, 0);
		}else if(eingabe == 3){
			valid = true;
			printStrip(elu,eru,lv,sizeh);
			close = 1; //closed
			getInputAndConvert(&ey, &ex, size); //ask user for point
			getnextpoint(ey, ex, size, feld, feld3, 0);
		}else if(eingabe == 4){
			valid = true;
			printStrip(elu,eru,lv,sizeh);
			close = 1; //closed move
			getrandompoint(&ey, &ex, size);
			printTextCentered(lh, sizeh,randomPoint);
			getnextpoint(ey,ex,size,feld, feld3, 0);
			// start func with options
		}else{
            printTextCentered(lh,sizeh,errorWithInput);
            printf("%c ", lh);
		}

	}while(!valid);
	// abschluss ?

}

//check count for the next strokes
int getMove(int Y, int X, int size, int feld[size][size], int feld3[size][size]){
   int move = 0;
   int i, j;
   // const 8 for max count of strokes
   for(i=0; i<8; i++)
   {
       if(Y+kombis[i][0] >= 0 && Y+kombis[i][0] < 8 && X+kombis[i][1] >= 0 && X+kombis[i][1] < 8){
            if(feld[Y+kombis[i][0]][X+kombis[i][1]] == 0 && feld3[Y+kombis[i][0]][X+kombis[i][1]] != (Y*10+X)){
                move +=1;
            }
       }
   }
   return move;
}

/* main function - rekrusiv  */

void getnextpoint(int Y, int X, int size, int feld[size][size], int feld3[size][size], int back){

    int nextPoint[8][3]; //array for the next strokes
    int i, j = 0;

    if(foundS == 1){
        return 1;
    }

    if(debug == 1){
        printf("\nAktueller Standpunkt: Y: %d, X: %d", Y, X);
        printf("\tCounter: %d", counter);
    }

    // fill array
    for( i=0; i<8; i++)
    {
        for( j=0; j<3; j++)
        {
             nextPoint[i][j] = -1;
        }
    }

    for(i=0; i<8; i++)
    {
       //check if the stroke is in the field or blocked for backtracking
       if(Y+kombis[i][0]>=0 && Y+kombis[i][0]<size && X+kombis[i][1]>=0 && X+kombis[i][1]<size && feld[Y+kombis[i][0]][X+kombis[i][1]]==0)
       {
           if(feld3[Y+kombis[i][0]][X+kombis[i][1]] != (Y*10+X)){
                nextPoint[i][0] = Y + kombis[i][0];
                nextPoint[i][1] = X + kombis[i][1];
                nextPoint[i][2] = getMove(Y + kombis[i][0], X + kombis[i][1], size, feld, feld3);
           }
       }
    }
    if(debug == 1){
        printf("\n-----------");
        printf("\nY | X | M");
        for( i=0; i<8; i++)
        {
            printf("\n");
            for( j=0; j<3; j++)
            {
                printf("%d ", nextPoint[i][j]);
            }
        }
        printf("\n-----------");
    }
    //search next stroke with the min possibility
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

    //open = 0
    // closed != 0

    //open path
    if(close == 0){
        //recrussion still possibilitys given
        if (kleinste != 100){

            if(debug == 1){
                printf("\nIch empfehle: X: %d, Y: %d, mit den Moeglichkeiten: %d\n-----------\n", kX, kY, kleinste);
            }
            feld[Y][X] = counter++;
            getnextpoint(kY, kX, size, feld, feld3, back);

        }else if (counter < (size*size) && kleinste == 100){
            feld3[Y][X] = 1;
            printf("\n Backtrack!");
            //TODO for NxM Field backtrack

        }else if (counter == (size*size) && kleinste ==100){
            feld[Y][X] = counter++;
            printfield(size,feld);
            if(debug == 1){
                printf("\n Last Field: %d %d", y, x);
                printf("\n------------------------\nAlle Felder Besucht mit %d Zuegen\n------------------------", --counter);
            }
        }
    }else{
        //closed path
        if(counter==1 && ey == Y && ex == X && kleinste == 100){
            printf("Abbruch!");
            foundS = 1;
            return 0;
        }else if(counter == (size*size) && (ey == kY && ex == kX)){
            // go on last coords
            feld[Y][X] = counter++;
            feld[kY][kX] = counter++;
            printfield(size,feld);
            foundS = 1;
            //TODO
            //feature weitere möglichkeiten
            printf("\nLetzter Punkt wurde erreicht!\n");
        }else if (counter <= (size*size) && kleinste == 100){
            //def vars
            feld[ey][ex] = 1;
            feld[Y][X] = 0;
            int lastX = 0;
            int lastY = 0;
            //END def vars

            // fig go back to the last backtrack position or go one field back
            if(back >= 1){
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
                                //set last field in array feld3 to -1 -> unlock
                                }else{
                                    if(backi != feld3[i][j]){
                                        feld3[i][j] = -1;
                                    }
                                }
                                feld[i][j] = 0;
                                lastY = i;
                                lastX = j;
                                back-=1;
                                // starte rekrusion nachdem auf dem feld mit mehrenen zugmöglichkeiten
                                if(back == 0){
                                    getnextpoint(lastY, lastX, size, feld, feld3, back);
                                }
                            }
                        }
                    }
                }
            }else{
                //go back and clear the backcounter -> to it if all ways blocked
                if(feld3[Y][X] == -1){
                    // unlock backtracking for the counter in forward part
                    //-> found at line
                    backbool = 1;
                    back=0;
                }
                //go back
                for(i=0; i<size; i++){
                    for(j=0; j<size; j++){
                     if(feld[i][j] == counter-1 && counter != 0){
                        if(counter >= 2){
                            counter--;
                        }
                        //lock last field in array feld3
                        if(back == 0){
                            feld3[Y][X] = (i*10+j);
                            backi = (i*10+j);
                        }
                        getnextpoint(i, j, size, feld, feld3, back);
                     }
                    }
                }
            }//close else
        }else if(kleinste != 100 && counter != (size*size+1)){ //&& ey != Y && ex != X
            if(debug == 1){
                printf("\nIch empfehle: X: %d, Y: %d, mit den Moeglichkeiten: %d\n-----------\n", kX, kY, kleinste);
            }
            //write the stroke in the array
            feld[Y][X] = counter++;

            if(counter == (size * size)){
            // unlock last field for the last stroke
                feld[ey][ex] = 0;
            }
            //increase backcount for the backtracking opstion
            if(backbool == 1){
                back +=1;
            }
          getnextpoint(kY, kX, size, feld, feld3, back);

        }
    }
}

//TODO Add Chars to the field maybe with cool output
void printfield(int size, int feld[size][size]){
    //int varss
    int i, j;
    //print top
    printf("\n%c", elo);
    for(j=0; j<(size); j++){
        printf("%c%c%c%c",lv,lv,lv,rdlu);
    }
    printf("%c%c%c%c\n%c   ",lv,lv,lv,ero,lh);
    for(j=0; j<(size); j++){
        //print the char at the top
        printf("%c%2c ", lh, alp[j]);
    }
    printf("%c\n%c",lh,lhml);
    // set lines between the numbers vertical
    for(j=0; j<(size); j++){
        printf("%c%c%c%c",lv,lv,lv,rdvl);
    }
    printf("%c%c%c%c",lv,lv,lv,lhmr);
    for(i=0; i<size; i++)
    {
        printf("\n");

        //print the decription on the left side
        printf("%c%2d ",lh, i);
        //print the movement
        for(j=0; j<size; j++)
        {
            printf("%c%2d ", lh,feld[i][j]);

        }
        // set lines between the numbers vertical
        // if last line set other chars
        if(i==(size-1)){
            printf("%c\n%c", lh,elu);
            for(j=0; j<(size); j++){
                printf("%c%c%c%c",lv,lv,lv,rdro);
            }
            printf("%c%c%c%c", lv,lv,lv,eru);
        }else{
            printf("%c\n%c", lh,lhml);
            for(j=0; j<(size); j++){
                printf("%c%c%c%c",lv,lv,lv,rdvl);
            }
            printf("%c%c%c%c",lv,lv,lv,lhmr);
        }
    }
}

// add FUNC
// vill zur optimierung ifs verwenden?
int posLetterToInt(char posL){
    // putchar()
    switch(posL){
		case 'A': case 'a':
			return 0; break;
		case 'B': case 'b':
			return 1; break;
		case 'C': case 'c':
			return 2; break;
		case 'D': case 'd':
			return 3; break;
		case 'E': case 'e':
			return 4; break;
		case 'F': case 'f':
			return 5; break;
		case 'G': case 'g':
			return 6; break;
		case 'H': case 'h':
			return 7; break;
		case 'I': case 'i':
			return 8; break;
		case 'J': case 'j':
			return 9; break;
		case 'K': case 'k':
			return 10; break;
		default:
            printf("Es ist ein Fehler unterlaufen! Abbruch...");
		//wait(2);
		exit(1);
	}
}

void getrandompoint(int *y, int *x, int size)
{
    srand (time (NULL));
    *x = rand() % size;
    *y = rand() % size;
}
