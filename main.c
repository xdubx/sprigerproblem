#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//prototype functions
int checkCord(char pos[2]);
int calcWay(char pos[2]);
int jump(int pos[2], int dir, int jumps);
int preCalc(int pos1,int pos2, int dir);
void jumpBack(int pos[2], int dir);
char posIntToLetter(int posL);
int posLetterToInt(char posL);
int checkRange(int posX, int posY);
int createPlayField();
int searchArray(a, b, c);
int restoreArray(int posX, int posY);
// define gloabl vars
int posNummber;
int posLetter;
int positions[8][8][1];

int main(){
	printf("Springerfigur Position: z.B[A1]\n");
	// function to scan -> buch
	char pos[2];
	gets(pos);
	// starte rechenvorgang
	createPlayField();
	if(calcWay(pos) == 1){
		printf("Programm erfolgreich ausgefuerhrt.");
		exit(0);
	}else{
		exit(1);
	}
	return 0;
}


int checkCord(char pos[2]){
	// check if pos A - H and 1-8,
        // pos1 is nummeric
	if(isdigit(pos[0])){
        posNummber = 0;
        posLetter = 1;
	}else{
        posNummber = 1;
        posLetter = 0;
	}
	// gegebenfalls byte nehmen
	pos[posLetter] = toupper(pos[posLetter]); //to uppercases
	if(pos[posLetter] == 'A' || pos[posLetter] == 'B' || pos[posLetter] == 'C' || pos[posLetter] == 'D' || pos[posLetter] == 'E' || pos[posLetter] == 'F' || pos[posLetter] == 'G' || pos[posLetter] == 'H'){
		// char to int
		if((pos[posNummber] - '0') > 0 && (pos[posNummber] - '0') <= 8){
			return 1;
		}
	}
	return 0;
}
int calcWay(char pos[2]){
	int e = checkCord(pos);
	if(e == 0){
		printf("Es wurde keine gueltige Angabe gemacht!");
		//wait(5); // check if function exist
		return 0;
	}
	// do some awesome things
    int posToCalc[2];
    posToCalc[0] = posLetterToInt(pos[posLetter]);
    posToCalc[1] = pos[posNummber] - '0';
    int finish = 0;
	//TODO
	int i = 0;
	// for backtracking
	int j = 0;
	int z = 0;
    // rekrusive func
    jump(posToCalc, 0, 0);

	return 1;
}
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
char posIntToLetter(int posL){
	switch(posL){
		case 1:
			return 'A';
		case 2:
			return 'B';
		case 3:
			return 'C';
		case 4:
			return 'D';
		case 5:
			return 'E';
		case 6:
			return 'F';
		case 7:
			return 'G';
		case 8:
			return 'H';
		default:
		printf("Es ist ein Fehler unterlaufen! Abbruch...");
		//wait(2);
		exit(1);
	}
}
int jump(int pos[2], int dir, int jumps){
    if(dir > 7){
        dir = 0;
    }
/* ------------------------------
        Directions X
        0 = front left
        1 = front right
        2 = backward left
        3 = "" right
        Directions Y
        4 = front left
        5 = front right
        6 = backward left
        7 = backward right
 ------------------------------  */
    int posX = pos[0];
    int posY = pos[1];
	if(dir == 0){
        posX++;
        posX++;
        posY++;
	}else if(dir == 1){
        posX++;
        posX++;
        posY--;
	}else if(dir == 2){
	    posX--;
        posX--;
        posY++;
	}else if(dir == 3){
	    posX++;
        posX++;
        posY--;
    }else if(dir == 4){
	    posY++;
        posY++;
        posX++;
    }else if(dir == 5){
	    posY++;
        posY++;
        posX--;
    }else if(dir == 6){
	    posY--;
        posY--;
        posX++;
    }else if(dir == 7){
	    posY--;
        posY--;
        posX--;
	}else{
        printf("Fehler");
        exit(1);
	}
	if(jumps == 100){
        return 1;
	}
	jumps++;
	if(checkRange(posX, posY) == 1){
        if(posX != pos[0] && posY != pos[1] && searchArray(posX, posY, 0) == 1){
                if(preCalc(posX, posY, 0) == 1){
                                        // set hourse to calc point
                    pos[0] = posX;
                    pos[1] = posY;
                    searchArray(posX, posY, 1);
                    //printf("%i%i\n", pos[0], pos[1]);
                    printf("\n%i%i dir:%d", pos[0], pos[1], dir);
                    return jump(pos, dir, jumps);
                }else{
                    // go ba
                    printf("\tbacktrack");
                    jumpBack(pos, dir);
                    return jump(pos, ++dir, jumps);
                }

        }else{
            return jump(pos, ++dir, jumps);
        }
    }else{
        return jump(pos, ++dir, jumps);
    }
}
void jumpBack(int pos[2], int dir){
        if(dir > 7){
        dir = 0;
    }
/* ------------------------------
        Directions X
        0 = front left
        1 = front right
        2 = backward left
        3 = "" right
        Directions Y
        4 = front left
        5 = front right
        6 = backward left
        7 = backward right
 ------------------------------  */
    int posX = pos[0];
    int posY = pos[1];
	if(dir == 0){
        posX--;
        posX--;
        posY--;
	}else if(dir == 1){
        posX--;
        posX--;
        posY++;
	}else if(dir == 2){
	    posX++;
        posX++;
        posY--;
	}else if(dir == 3){
	    posX--;
        posX--;
        posY++;
    }else if(dir == 4){
	    posY--;
        posY--;
        posX--;
    }else if(dir == 5){
	    posY--;
        posY--;
        posX++;
    }else if(dir == 6){
	    posY++;
        posY++;
        posX--;
    }else if(dir == 7){
	    posY++;
        posY++;
        posX++;
	}else{
        printf("Fehler");
        exit(1);
	}
    if(checkRange(posX, posY) == 1){
        if(posX != pos[0] && posY != pos[1]){
            //add lost array int and set old pos
            printf("\n%d%d dir:%d", posX, posY, dir);
            pos[0] = posX;
            pos[1] = posY;
            restoreArray(posX, posY);
        }
    }
}
int preCalc(int pos1,int pos2, int dir){
    int trys = 0;
/* ------------------------------
        Directions X
        0 = front left
        1 = front right
        2 = backward left
        3 = "" right
        Directions Y
        4 = front left
        5 = front right
        6 = backward left
        7 = backward right
 ------------------------------  */
    int posX = pos1;
    int posY = pos2;
    int posX2 = posX;
    int posY2 = posY;
    int backtrackInt = 0;
    do{
     if(dir > 7){
        dir = 0;
    }
	if(dir == 0){
        posX++;
        posX++;
        posY++;
	}else if(dir == 1){
        posX++;
        posX++;
        posY--;
	}else if(dir == 2){
	    posX--;
        posX--;
        posY++;
	}else if(dir == 3){
	    posX++;
        posX++;
        posY--;
    }else if(dir == 4){
	    posY++;
        posY++;
        posX++;
    }else if(dir == 5){
	    posY++;
        posY++;
        posX--;
    }else if(dir == 6){
	    posY--;
        posY--;
        posX++;
    }else if(dir == 7){
	    posY--;
        posY--;
        posX--;
	}else{
        printf("Fehler");
        exit(1);
	}
    //printf("\t%d%d\n", posX, posY);
    if(checkRange(posX, posY) == 1){
        //printf("\t%d%d\n", posX, posY);
        if(posX != posX2 && posY != posY2 && searchArray(posX, posY, 0) == 1){
        // check if is in range
        //printf("\t%d%d %d\n", posX, posY, trys);
        // wenn keine 2 möglichen schritte möglich sind mache einen zurück und überspringe diesen
            if(trys == 1){
                printf("\t%d%d", posX, posY);
                return 1;
            }else{
                trys++;
                printf("\t%d%d", posX, posY);
                posX2=posX;
                posY2=posY;
            }
            //printf("%i%i\n", pos[0], pos[1]);
            //printf("%c%i\n", posIntToLetter(pos[0]), pos[1]);
        }else{
            posX=posX2;
            posY=posY2;
            dir++;
            backtrackInt++;
            //printf("%d\t", backtrackInt);
            if(backtrackInt > 16){
                return 0;
            }
        }
    }else{
        posX=posX2;
        posY=posY2;
        dir++;
        backtrackInt++;
        //printf("%d\t", backtrackInt);
        if(backtrackInt > 16){
            return 0;
        }
    }
    }while(trys < 3);
    return 0;
}
int checkRange(int posX, int posY){
    if(posX > 0 && posX < 9 && posY > 0 && posY < 9){
        // pos is in the playrange
        return 1;
    }else{
        // the pos is outside the playarea
        return 0;
    }
}
int createPlayField(){
    int i,j;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            int x = i;
            int z = j;
            int q = ((x+1)*10 + (z+1));
            positions[i][j][0] = q;
            positions[i][j][1] = 0;
            //printf("%d\t", positions[i][j][0]);
        }
    }
    return 1;
}
int searchArray(a, b, c){
    int i,j;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            int q = (a*10+b);
            //printf("%d\t", positions[i][j][0]);
                if(positions[i][j][0] == q){
                    //printf("%d\t", positions[i][j][0]);
                    if(c == 1){
                        //positions[i][j][1] = positions[i][j][0];
                        positions[i][j][0] = 0;
                        //printf("%d\t", positions[i][j][0]);
                        return 1;
                    }else{
                        return 1;
                    }
                }
        }
    }
    return 0;
}
int restoreArray(int posX, int posY){
    int i,j;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            int q = (posX*10+posY);
            //printf("%d\t", positions[i][j][0]);
                if((i+1) == posX && j == posY){
                    //printf("%d\t", positions[i][j][0]);
                        //positions[i][j][1] = positions[i][j][0];
                        positions[i][j][0] = (posX*10+posY);
                        //printf("%d\t", positions[i][j][0]);
                        return 1;
                    }
                }

    }
    return 0;
}
