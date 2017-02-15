#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define SIZE 8
/*
usefull explanations
        x
   ---------->
   |
y  |    field[y][x];
   |
   |
   V
// TODO
add backtrack for the closed path
*/
//-------- [DEBUG OPTIONS] ----------
short debug = 0; // set to 1 to show output
start_t, end_t, total_t;
//-------- [DEBUG OPTIONS] ----------

// -------- [prototype functions] ----------
 int posLetterToInt(char posL);
 void printHeadline(int size, int field[size][size], int field2[size][size]);
// -------- [END prototype functions] ----------

// -------- [GLOBAL VARS] ----------
// FORMAT VARS
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
int ex,ey = 0;      //startpoint
int counter = 1;    //count the moves
short close = 0;    //closed move =1; open move = 0;
int backbool = 0;
int backi = 0;
short foundS = 0;
char capitalalp [26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char lowercasealp[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
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
    int field[size][size];      //main playfield
    int field2[size][size];     //field for backtracking
    int i, j;
    // create playfield
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            field[i][j] = 0;
            field2[i][j] = -1;
        }
    }
    printHeadline(size, field, field2);
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
	int inputy;
	char inputx;
	do{
		//check if first letter a alph and sec a number

		// get first char and set it to upper case - convert from alph to int
		// sec char to int
		scanf("%c", &inputx);       //we need this but I dont know why
        printf("Bitte X Punkt  als Buchstaben angeben:");
        scanf("%c", &inputx);
        printf("Bitte Y Punkt  als Zahl angeben:");
        scanf("%d", &inputy);
        if(posLetterToInt(inputx)>=0 && posLetterToInt(inputx)<size && inputy>=0 && inputy<size) valid = true;
        //check if point is possible


	}while(!valid);
	printf("\nIhre Auswahl: %c%d\n", inputx, inputy );
	*uy = inputy;
	*ux = posLetterToInt(inputx);
}
void printHeadline(int size, int field[size][size], int field2[size][size]){
	//def vars
	char nameOfProgramm[] = "SPRINGERPROBLEM";
    char errorWithInput[] = "Eingabe ungultig!";
    char randomPoint[] = "Vom Programm wurde ein zufaelliger Punkt gewaehlt";
	//head
	printStrip(elo, ero, lv, sizeh);
	//print name of programm
    printTextCentered(lh,sizeh,nameOfProgramm);
	//middle strip
	printStrip(lhml, lhmr, lv, sizeh);
	//head END

	// content
	// OPTIONS HERE
	printf("%c   1. Offener Zug mit freiem Punkt              %c\n",lh,lh);
	printf("%c   2. Offener Zug mit vorgegebenem Punkt        %c\n",lh,lh);
	printf("%c   3. Geschlossener Zug mit freiem Punkt        %c\n",lh,lh);
	printf("%c   4. Geschlossener Zug mit vorgegebenem Punkt  %c\n",lh,lh);
	//middle strip
	printStrip(lhml, lhmr, lv, sizeh);

	// input with while loop
	printf("%c ", lh);
	char eingabe = '0';
	bool valid = false;
	int coords = 0;
	do{
		scanf("%c", &eingabe);
		//check user input
		if(eingabe == '1'){
			//close design
			valid = true;
			printStrip(elu,eru,lv,sizeh);
			close = 0; //open move
			getInputAndConvert(&ey, &ex, size); //ask user for point
			start_t = clock(); //start timer to get sequence time
			getnextpoint(ey, ex, size, field, field2, 0); //start solution
		}else if(eingabe == '2'){
			valid = true;
			printStrip(elu,eru,lv,sizeh);
			close = 0; //open move
			getrandompoint(&ey, &ex, size);
            printTextCentered(lh, sizeh,randomPoint);
            start_t = clock(); //start timer to get sequence time
			getnextpoint(ey,ex,size,field, field2, 0); //start solution
		}else if(eingabe == '3'){
			valid = true;
			printStrip(elu,eru,lv,sizeh);
			close = 1; //closed move
			getInputAndConvert(&ey, &ex, size); //ask user for point
			start_t = clock(); //start timer to get sequence time
			getnextpoint(ey, ex, size, field, field2, 0); //start solution
		}else if(eingabe == '4'){
			valid = true;
			printStrip(elu,eru,lv,sizeh);
			close = 1; //closed move
			getrandompoint(&ey, &ex, size);
			printTextCentered(lh, sizeh,randomPoint);
			start_t = clock(); //start timer to get sequence time
			getnextpoint(ey,ex,size,field, field2, 0); //start solution
		}else{
            printTextCentered(lh,sizeh,errorWithInput);
		}

	}while(!valid);

}

//check count for the next strokes
int getMove(int Y, int X, int size, int field[size][size], int field2[size][size]){
   int move = 0;
   int i, j;
   // const 8 for max count of strokes
   for(i=0; i<8; i++)
   {
       if(Y+kombis[i][0] >= 0 && Y+kombis[i][0] < 8 && X+kombis[i][1] >= 0 && X+kombis[i][1] < 8){
            if(field[Y+kombis[i][0]][X+kombis[i][1]] == 0 && field2[Y+kombis[i][0]][X+kombis[i][1]] != (Y*10+X)){
                move +=1;
            }
       }
   }
   return move;
}

/* main function - rekrusiv  */

void getnextpoint(int Y, int X, int size, int field[size][size], int field2[size][size], int back){

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
       if(Y+kombis[i][0]>=0 && Y+kombis[i][0]<size && X+kombis[i][1]>=0 && X+kombis[i][1]<size && field[Y+kombis[i][0]][X+kombis[i][1]]==0)
       {
           if(field2[Y+kombis[i][0]][X+kombis[i][1]] != (Y*10+X)){
                nextPoint[i][0] = Y + kombis[i][0];
                nextPoint[i][1] = X + kombis[i][1];
                nextPoint[i][2] = getMove(Y + kombis[i][0], X + kombis[i][1], size, field, field2);
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
    //search next stroke with the minimal possibility
    int least, kX, kY;
    kX = kY = -1;
    least = 100;
    for(i=0; i<8; i++)
    {
        if (nextPoint[i][2]<least && nextPoint[i][2]>-1 )
        {
            kY = nextPoint[i][0];
            kX = nextPoint[i][1];
            least = nextPoint[i][2];
        }
    }

    //open = 0
    // closed != 0

    //open path
    if(close == 0){
        //recrussion still possibilitys given
        if (least != 100){

            if(debug == 1){
                printf("\nIch empfehle: X: %d, Y: %d, mit den Moeglichkeiten: %d\n-----------\n", kX, kY, least);
            }
            field[Y][X] = counter++;
            getnextpoint(kY, kX, size, field, field2, back);

        }else if (counter < (size*size) && least == 100){
            field2[Y][X] = 1;
            printf("\n Backtrack!");
            //TODO for NxM Field backtrack

        }else if (counter == (size*size) && least ==100){
            field[Y][X] = counter++;
            printfield(size,field);
            if(debug == 1){
//                printf("\n Last Field: %d %d", y, x);
                printf("\n------------------------\nAlle Felder Besucht mit %d Zuegen\n------------------------", --counter);
            }
        }
    }else{
        //closed path
        if(counter==1 && ey == Y && ex == X && least == 100){
            printf("Keine Loesung fuer diesen Punkt!");
            foundS = 1;
            return 0;
        }else if(counter == (size*size) && (ey == kY && ex == kX)){
            // go on last coords
            field[Y][X] = counter++;
            field[kY][kX] = counter++;
            printfield(size,field);
            foundS = 1;
            printf("\nLetzter Punkt wurde erreicht!\n");

        }else if (counter <= (size*size) && least == 100){
            //def vars
            field[ey][ex] = 1;
            field[Y][X] = 0;
            int lastX = 0;
            int lastY = 0;
            //END def vars

            // fig go back to the last backtrack position or go one field back
            if(back >= 1){
                while(back >= 1){
                    for(i=0; i<size; i++){
                        for(j=0; j<size; j++){
                            if(field[i][j] == counter-1 && counter != 0){
                                if(counter >= 2){
                                    counter--;
                                }
                                if(back == 1){
                                    field2[lastY][lastX] = (i*10+j);
                                    backi = (i*10+j);
                                //set last field in array feld3 to -1 -> unlock
                                }else{
                                    if(backi != field2[i][j]){
                                        field2[i][j] = -1;
                                    }
                                }
                                field[i][j] = 0;
                                lastY = i;
                                lastX = j;
                                back-=1;
                                // start recurrence
                                if(back == 0){
                                    getnextpoint(lastY, lastX, size, field, field2, back);
                                }
                            }
                        }
                    }
                }
            }else{
                //go back and clear the backcounter -> to it if all ways blocked
                if(field2[Y][X] == -1){
                    // unlock backtracking for the counter in forward part
                    //-> found at line
                    backbool = 1;
                    back=0;
                }
                //go back
                for(i=0; i<size; i++){
                    for(j=0; j<size; j++){
                     if(field[i][j] == counter-1 && counter != 0){
                        if(counter >= 2){
                            counter--;
                        }
                        //lock last field in array field2
                        if(back == 0){
                            field2[Y][X] = (i*10+j);
                            backi = (i*10+j);
                        }
                        getnextpoint(i, j, size, field, field2, back);
                     }
                    }
                }
            }//close else
        }else if(least != 100 && counter != (size*size+1)){ //&& ey != Y && ex != X
            if(debug == 1){
                printf("\nIch empfehle: X: %d, Y: %d, mit den Moeglichkeiten: %d\n-----------\n", kX, kY, least);
            }
            //write the stroke in the array
            field[Y][X] = counter++;

            if(counter == (size * size)){
            // unlock last field for the last stroke
                field[ey][ex] = 0;
            }
            //increase backcount for the backtracking opstion
            if(backbool == 1){
                back +=1;
            }
          getnextpoint(kY, kX, size, field, field2, back);

        }
    }
}

//TODO Add Chars to the field maybe with cool output
void printfield(int size, int field[size][size]){
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
        printf("%c%2c ", lh, capitalalp[j]);
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
            printf("%c%2d ", lh,field[i][j]);

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
    end_t = clock();            //stop counter
    total_t = end_t-start_t;    //calculate sequence time

    printf("\n");
    if(total_t<1)
    {
        printf("Das Programm hat weniger als eine ms benoetigt");
    }
    printf("Das Programm hat %d ms benoetigt.",total_t);

}

int posLetterToInt(char posL){
    //convert char form alphabet into an int
    int i;
    for(i=0; i<26; i++) if(capitalalp[i] == posL || lowercasealp[i] == posL) return i; //try capital- and lower case letters

}

void getrandompoint(int *y, int *x, int size)
{
    //return an random point
    srand (time (NULL));
    *x = rand() % size;
    *y = rand() % size;
}
