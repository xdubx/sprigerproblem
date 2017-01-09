#include <stdio.h>
#include <stdlib.h>


int x;
int y;
int VektorX;
int VektorY;
int PruefungX[100];
int PruefungY[100];

int counter=0;


    int i;
    int j;

    int counter0 = 0;

//----------------------------------------------------------------------------------------
//wenn alle möglichen Felder vom Ausgangsfeld schon besetzt sind, dann soll er vom Ausgangsfeld eins zurück gehen
struct Fields
{
    int PositionX ;
    int PositionY ;



    int FieldpossibX[100];
    int FieldpossibY[100];
    int Anzahl;



}possibities[64];

//----------------------------------------------------------------------------------------
void Setup()
{
    // es soll gespeichert werden, welche Felder von demjenigen Feld erreicht werden



    for(i=1;i<9;i++)//x
    {
        for(j=1;j<9;j++)//y
        {



            possibities[counter0].PositionX = i;
            possibities[counter0].PositionY = j;
            possibities[counter0].Anzahl = 0;

             printf("i = x Test: %d  \n",possibities[0].PositionX);
            printf("j = y Test: %d  \n",possibities[0].PositionY);//WTF?
            printf("counter0 %d \n",counter0);




            Moeglichkeiten();
            printf("Die Anzahl der Moeglichkeiten ist: %d  \n",possibities[counter0].Anzahl);

            counter0++;




        }


    }



}
//----------------------------------------------------------------------------------------
void Moeglichkeiten()
{
    int a;
    int b;
    int counter1 = 0;



   int VektorA[2] = {2,-2};
   int VektorB[2] = {1,-1};

    for(a=0;a<2;a++)
    {
        for(b=0;b<2;b++)
        {
            VektorX = VektorA[a];

            x = i+VektorX;

            VektorY = VektorB[b];

            y = j+VektorY;


            if((x<9)&&(y<9))
            {
                if((x>0)&&(y>0))
                {
                    possibities[counter0].FieldpossibX[counter1]=x;
                    printf("i %d    \n",i);
                    printf("j %d    \n",j);
                    printf("x: %d   \n",x);

                    possibities[counter0].FieldpossibY[counter1]=y;

                    printf("i %d    \n",i);
                    printf("j %d    \n",j);

                    printf("y: %d   \n",y);

                    counter1++;
                    possibities[counter0].Anzahl++;


                }

            }
        }
    }

    for(a=0;a<2;a++)
    {
        for(b=0;b<2;b++)
        {
            VektorX = VektorB[a];

            x = i+VektorX;

            VektorY = VektorA[b];

            y = j+VektorY;


            if((x<9)&&(y<9))
            {
                if((x>0)&&(y>0))
                {
                    possibities[counter0].FieldpossibX[counter1]=x;

                    printf("i %d    \n",i);
                    printf("j %d    \n",j);
                    printf("x: %d   \n",x);

                    possibities[counter0].FieldpossibY[counter1]=y;

                    printf("i %d    \n",i);
                    printf("j %d    \n",j);
                    printf("y: %d   \n",y);
                    possibities[counter0].Anzahl++;


                    counter1++;


                }


            }
        }
    }



   // printf("Moeglichkeit X Test: %d  \n", possibities[counter0].FieldpossibX[counter1]);
   // printf("Moeglichkeit Y Test: %d  \n",possibities[counter0].FieldpossibY[counter2]);



    counter1 = 0;


}


//----------------------------------------------------------------------------------------


void Eingabe()
{
    scanf("%d",&x);
    scanf("%d",&y);

    printf("Die X-Koordinate: %d    \n",x);
    printf("Die Y-Koordinate: %d    \n",y);
}
//----------------------------------------------------------------------------------------

void Vektor()
{   int a;
    int b;


    int Vektoren[4] = {1,2,-1,-2};



    do
    {
        a = rand()%+4;
        b = rand()%+4;


        if(a==0&&b==2||a==2&&b==0)
        {
            a=b;
        }
        if(a==1&&b==3||a==3&&b==1)
        {
            a=b;
        }
    }
    while(a==b);

    VektorX = Vektoren[a];
    VektorY = Vektoren[b];



   printf("Es wurde berechnet ...Vektor X:%d  \n",VektorX);
   printf("Es wurde berechnet...Vektor Y:%d  \n",VektorY);
}






//----------------------------------------------------------------------------------------



void Check()
{   printf("Check######\n");
  // int i;



   for(i=0;i<counter;i++)
   {
        //es soll überprüft werden, ob man schon mal auf der Position war.
         // wenn ja soll überprüft werden ob er schon auf allen Positionen war
         // wenn nein soll er auf die vorherige Position






     if((x==PruefungX[i])&&(y==PruefungY[i]))
     {
         if(counter == 64)
         {
             printf("Alle Felder wurden erreicht!   \n");
             printf("Die momentanten Koordinaten sind %d,%d",x,y);
         }


            counter--;
            printf("counter%d   \n",counter);
             x=PruefungX[counter];
             y=PruefungY[counter];

             printf("Koordinate X ist jetzt wieder: %d   \n",x);
             printf("Koordinate Y ist jetzt wieder: %d   \n",y);





     }



   }

}
//----------------------------------------------------------------------------------------
void Check2()
{  printf("Check2#######\n");
   int a;
   int b;
   int z;
   int counter2 = 0;

   for(a=0;a<64;a++)
   {

      if((x==possibities[a].PositionX)&&(y==possibities[a].PositionY))
      {
          printf("Die Anzahl der Möglichkeiten für das Feld %d,%d sind %d   \n",x,y,possibities[a].Anzahl);

          for(b=0;b<possibities[a].Anzahl;b++)
          {
              printf("Möglichkeiten X %d  \n",possibities[a].FieldpossibX[b]);
              printf("Möglichkeiten Y %d  \n",possibities[a].FieldpossibY[b]);

              for(z=0;z<counter;z++)
              {
                if((possibities[a].FieldpossibX[b]==PruefungX[z])&&(possibities[a].FieldpossibY[b]==PruefungY[z]))
                {
                    counter2++;

                   if(possibities[a].Anzahl==counter2)
                   {    //ich glaube es funktioniert, es muss hier nur noch eingetragen werden was dann passieren soll...
                        counter--;

                        x = PruefungX[counter];
                        y = PruefungY[counter];

                        //noch nicht ganz!!!....
                      printf("zurück auf das vorherige Feld %d, %d   \n",x,y);

                      counter2 = 0;

                   }




                    printf("Bereits gewesene Felder X %d    \n",PruefungX[z]);
                    printf("Bereits gewesene Felder Y %d    \n",PruefungY[z]);




                }
              }



          }





      }






   }





}
//----------------------------------------------------------------------------------------
void Check3()
{
//Für Feld 50 gibt es keine Moeglichkeit mehr, allerdings sind noch nicht alle Felder erreicht.
// Was soll jetzt passieren??
//Idee1: Er soll soweit zurück gehen, bis die Anzahl der Moeglichkeiten 2 ist und dann den anderen Weg wählen
//wenn dieser Weg ebenfalls nicht zum Ziel führt, soll er zurück gehen bis die Anzahl der Moeglichkeiten 3 ist.


}
//----------------------------------------------------------------------------------------
void Safe()
{


    PruefungX[counter]=x;
    PruefungY[counter]=y;

    counter++;
    printf("counter%d   \n",counter);


}

//----------------------------------------------------------------------------------------


void Berechnung()
{   printf("Berechnung\n");
    x = x+VektorX;
    y = y+VektorY;

    if(x>8||x<1)
    {   counter--;
        printf("counter%d    \n",counter);
        x = PruefungX[counter];
        y = PruefungY[counter];
         printf("Koordinate X: %d   \n",x);
         printf("Koordinate Y: %d   \n",y);
    }

    if(y>8||y<1)
    {
         counter--;
        printf("counter%d    \n",counter);

        x = PruefungX[counter];
        y = PruefungY[counter];
         printf("Koordinate X: %d   \n",x);
         printf("Koordinate Y: %d   \n",y);

    }

    printf("Neues Feld X:%d  \n",x);
    printf("Neues Feld Y:%d  \n",y);


}
//----------------------------------------------------------------------------------------

int Rekursion()
{
    //counter++;

    Check();
    Check2();
    Check3();
    Safe();
    Vektor();
    Berechnung();

            Rekursion();
}
//----------------------------------------------------------------------------------------
int main()
{
    Setup();




    Eingabe();


    Rekursion();



    return 0;
}
