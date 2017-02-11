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
    // Erstelle das Schachfeld
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            //printf("%d ", 0);
            feld[i][j] = 0;
            feld3[i][j] = -1;
        }
        //printf("\n");
    }
    //Start // INPUT // TODO

    ex = 0;
    ey = 0;
    //printf("%d");
    printHeadline(size, feld, feld3);
    //getnextpoint(ey,ex,size,feld, feld3, 0);

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
int getInputAndConvert(int size){
	bool gueltig = false;
    char c1 = 'N';
    int i1;
	do{
            printf("%c",c1);
		//check if first letter a alph and sec a number
        scanf("%d", &c1);
        //c1 = toupper(c1);
        printf("%c",c1);
        if(posLetterToInt(c1)>=0 && posLetterToInt(c1)<size && i1>0 && i1<=size){

            return (posLetterToInt(c1)*10+i1);
        }

	}while(!gueltig);
	return 0;
}
void printHeadline(int size, int feld[size][size], int feld3[size][size]){
	//def vars
	char nameOfProgramm[] = "SPRINGERPROBLEM";
    char errorWithInput[] = "Eingabe ungultig!";
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
	bool gueltig = false;
	int coords = 0;
	do{
		scanf("%d", &eingabe);
		//open path
		if(eingabe == 1){

            coords = getInputAndConvert(size);
            //close design
			printStrip(elu,eru,lv,sizeh);
			//getnextpoint(posLetterToInt(c1),eingabe-1,size,feld, feld3, 0);
			// start func with options
		}else if(eingabe == 2){
			gueltig = true;
			printStrip(elu,eru,lv,sizeh);
			close = 0; //Angabe für offenen Zug
			ey=0; ex=0;
			getnextpoint(ey,ex,size,feld, feld3, 0);//random hinzufügen
			// start func with options
		}else if(eingabe == 3){
			gueltig = true;
			printStrip(elu,eru,lv,sizeh);
			close = 1; //Angabe für geschlossenen Zug
			// start func with options
		}else if(eingabe == 4){
			gueltig = true;
			printStrip(elu,eru,lv,sizeh);
			close = 1; //Angabe für geschlossenen Zug
			ey=0; ex=0;
			getnextpoint(ey,ex,size,feld, feld3, 0);//random hinzufügen
			// start func with options
		}else{
            printTextCentered(lh,sizeh,errorWithInput);
            printf("%c ", lh);
		}

	}while(!gueltig);
	// abschluss ?

}

//Hier wird die anzahl der naechsten Zuege ueberprueft
int getzuege(int Y, int X, int size, int feld[size][size], int feld3[size][size]){
   int zuege = 0;
   int i, j;
   // const 8 für die max anzahl an zuegen
   for(i=0; i<8; i++)
   {
       if(Y+kombis[i][0] >= 0 && Y+kombis[i][0] < 8 && X+kombis[i][1] >= 0 && X+kombis[i][1] < 8){
            if(feld[Y+kombis[i][0]][X+kombis[i][1]] == 0 && feld3[Y+kombis[i][0]][X+kombis[i][1]] != (Y*10+X)){
                zuege +=1;
            }
       }
   }
   return zuege;
}

/* Hauptfunktion - wird rekrusiv aufgerufen */

void getnextpoint(int Y, int X, int size, int feld[size][size], int feld3[size][size], int back){

    int nextPoint[8][3]; //speicher fuer die naechsten moeglichen Punkte
    int i, j = 0;

    if(debug == 1){
        printf("\nAktueller Standpunkt: Y: %d, X: %d", Y, X);
        printf("\tCounter: %d", counter);
    }

    // Berechnung für die nächstgen Zuege -> Arrays werden mit allen möglichen Zügen gefüllt
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
           if(feld3[Y+kombis[i][0]][X+kombis[i][1]] != (Y*10+X)){
                nextPoint[i][0] = Y + kombis[i][0];
                nextPoint[i][1] = X + kombis[i][1];
                nextPoint[i][2] = getzuege(Y + kombis[i][0], X + kombis[i][1], size, feld, feld3);
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
    //Suche den Zug mit den geringsten Möglichkeiten
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
        //rekursion, solange es noch eine möglichkeit gibt
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
            feldausgabe(size,feld); // fertig
            if(debug == 1){
                printf("\n------------------------\nAlle Felder Besucht mit %d Zuegen\n------------------------", --counter);
            }
        }
    }else{
        //closed path
        if(counter==1 && ey == Y && ex == X && kleinste == 100){
            printf("Abbruch!");
            return 0;
        }else if(counter == (size*size) && (ey == kY && ex == kX)){
            // go on last coords
            feld[Y][X] = counter++;
            feld[kY][kX] = counter++;
            feldausgabe(size,feld);
            // cool output
            printf("\nLast Point reach!\n");
        }else if (counter <= (size*size) && kleinste == 100){
            //def vars
            feld[ey][ex] = 1;
            feld[Y][X] = 0;
            int lastX = 0;
            int lastY = 0;
            //END def vars

            //entscheidung zwischen zurücklaufen auf das ursprungsfeld mit mehr zügen oder einfach ein schritt zurück
            if(back >= 1){
                //laufe zurück bis
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
                //Gehe zurück und setze den Backcounter frei.
                if(feld3[Y][X] == -1){
                    //-> found at line
                    // zuständig das beim vorlaufen ein counter hochgezählt wird
                    backbool = 1;
                    //back counter zum zählen
                    back=0;
                }
                //laufe zurück und sperre das letzte feld
                for(i=0; i<size; i++){
                    for(j=0; j<size; j++){
                     if(feld[i][j] == counter-1 && counter != 0){
                        if(counter >= 2){
                            counter--;
                        }
                        if(back == 0){
                            //sperre feld3 damit der zug darauf verhindert wird
                            feld3[Y][X] = (i*10+j);
                            backi = (i*10+j);
                        }else{
                            if(backi != feld3[i][j]){
                                feld3[i][j] = -1;
                            }
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
            //füge den zug hinzu
            feld[Y][X] = counter++;

            if(counter == (size * size)){
               // gebe letztes feld frei damit der Springer drauf laufen kann
                feld[ey][ex] = 0;
            }
            //gebe die backbool frei
            if(backbool == 1){
                back +=1;
            }
          getnextpoint(kY, kX, size, feld, feld3, back);

        }
    }
}

//TODO Add Chars to the field maybe with cool output
void feldausgabe(int size, int feld[size][size]){
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
		case 'A':
			return 0;
		case 'B':
			return 1;
		case 'C':
			return 2;
		case 'D':
			return 3;
		case 'E':
			return 4;
		case 'F':
			return 5;
		case 'G':
			return 6;
		case 'H':
			return 7;
		default:
		printf("Es ist ein Fehler unterlaufen! Abbruch...");
		//wait(2);
		exit(1);
	}
}
