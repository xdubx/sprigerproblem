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
    getnextpoint(0,0,size,feld, feld3, 0);
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
/*
Wenn der Punkt 63 erreicht ist wird anfangsfeld freigegeben und versucht drauf zu laufen wenn das nicht mögich ist geht er zurück und
sperrt den ersten punkt. wird solange ausgeführt, dass if ex and ey == wusch coords haben


für das feld soll ein array aufgerufen werden um die pos zu sperren sonst läuft der immer in den anderne path oder eine struktur auf jedes feld legen
mit dem blockierten feld.
in feld 3 kommt die struktur oder einfach das blockierte feld + abfrage

darf nur schreiben wenn kurz vor dem nächsten feld zu springen
*/


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
        printf("\n%d>=0 && %d<8 && %d>=0 && %d<8 && %d==0 && %d != %d",Y+kombis[i][0], Y+kombis[i][0], X+kombis[i][1], X+kombis[i][1],feld[Y+kombis[i][0]][X+kombis[i][1]], feld3[Y+kombis[i][0]][X+kombis[i][1]], (Y*10+X));
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
        //closed path
        printf("\n %d != 100 && %d != (64) ", kleinste, counter);
        if(counter==1 && ey == Y && ex == X && kleinste == 100){
            printf("Abbruch!");
            return 0;
        }else if (counter <= (size*size) && kleinste == 100){
            printf("\nKeine Loesung! b:%d", back);
            //TODO goback
            // set reset
            // bevor die 0 gesetzt werden muss removed werden
            /*
                wenn er ein feld auf back dann bool = true und abck increase back zurücklaufen back decrease
                wenn wieder keine möglichkeit zurück clear field and write blocked way
            */
            printf("\nFirst field set to 1!");
            feld[ey][ex] = 1;
            feld[Y][X] = 0;

            if(back > 0){
                while(back > 0){
                    for(i=0; i<size; i++){
                        for(j=0; j<size; j++){
                            if(feld[i][j] == counter-1){
                                counter--;
                                if(back == 1){
                                    feld3[Y][X] = (i*10+j);
                                }
                                feld[i][j] = 0;
                                printf("Y:%d X:%d" , j,i);
                                feldausgabe(size,feld);
                                feldausgabe(size,feld3);
                                }
                        }
                    }


                    back-=1;
                }
                getnextpoint(i, j, size, feld, feld3, back);
            }

            if(feld3[Y][X] == -1){
                backbool = 1;
                back=0;
            }
            // i = Y und j = X
            // for the first back
            for(i=0; i<size; i++)
            {
                for(j=0; j<size; j++)
                {
                 if(feld[i][j] == counter-1){
                    counter--;
                    if(back == 1){
                        feld3[Y][X] = (i*10+j);
                    }
                    feldausgabe(size,feld);
                    feldausgabe(size,feld3);
                    getnextpoint(i, j, size, feld, feld3, back);
                 }
                }
            }
        }else if(kleinste != 100 && counter != (size*size)){ //&& ey != Y && ex != X
            if(debug == 1){
                printf("\nIch empfehle: X: %d, Y: %d, mit den Moeglichkeiten: %d\n-----------\n", kX, kY, kleinste);
            }
            feld[Y][X] = counter++;
            //printf("\n%d", feld[Y][X]);


            if(counter == ((size * size))){
               // gebe letztes feld frei damit er drauf laufen kann
               printf("First field reset!");
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

        }else if(counter == (size*size+1) && ey == kY && ex == kX){
            // go on last coords
            feldausgabe(size,feld);
            printf("Last Point reach!");
        }
    }
}
int haveaJump(int Y, int X,int size,int feld[size][size],int feld3[size][size]){
    int canjump,i = 0;
    for(i=0; i<8; i++){
       if(feld3[Y+kombis[i][0]][X+kombis[i][1]] != (Y*10+X)){
             if(getzuege(Y + kombis[i][0], X + kombis[i][1], size, feld, feld3) > 1){
                canjump = 1;
             }
       }
    }
    return canjump;
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
