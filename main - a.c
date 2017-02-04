#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int x;
int y;
int VektorX;
int VektorY;
int PruefungX[100];
int PruefungY[100];

int counter=0;
int counter0 = 0;

    int i;
    int j;

    //Check 3
    int counter1 = 0;// er soll hochgezählt werden bis dieser gleich der Anzahl der noch freien Felder ist
     int counter2 = 0;
     bool zuruck = false;
    int tempX[20];
    int tempY[20];




//----------------------------------------------------------------------------------------
//wenn alle möglichen Felder vom Ausgangsfeld schon besetzt sind, dann soll er vom Ausgangsfeld eins zurück gehen
struct Fields
{
    int PositionX ;
    int PositionY ;


    int NachfolgerX;//er soll sich für jedes Feld den Nachfolger merken
    int NachfolgerY;

    int FieldpossibX[100];
    int FieldpossibY[100];
    int Anzahl;
    int AnzahlMAX;



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

            possibities[counter0].AnzahlMAX = possibities[counter0].Anzahl;

            printf("AnzahlMAX = %d  \n",possibities[counter0].AnzahlMAX);

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
          printf("Die Anzahl der Möglichkeiten für das Feld maximal sind %d,%d sind %d   \n",x,y,possibities[a].AnzahlMAX);
            possibities[a].Anzahl = possibities[a].AnzahlMAX; // TEST!!! 22.1.17
          for(b=0;b<possibities[a].AnzahlMAX;b++)
          {
              printf("Möglichkeiten X %d  \n",possibities[a].FieldpossibX[b]);
              printf("Möglichkeiten Y %d  \n",possibities[a].FieldpossibY[b]);

              for(z=0;z<counter;z++)
              {
                if((possibities[a].FieldpossibX[b]==PruefungX[z])&&(possibities[a].FieldpossibY[b]==PruefungY[z]))
                {

                    //Die Anzahl der Möglichkeiten soll verringert werden
                    //Test..

                    possibities[a].Anzahl--;
                    //counter2++;// sobald der counter2 der maximalen(wichtig)... Anzahl entspricht soll die funktion if ausgelöst werden


                    printf("Die Anzahl der Möglichkeiten für das Feld %d,%d sind nur noch %d   \n",x,y,possibities[a].Anzahl);

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
{   printf("Check3####### \n");
    int x1;
    int y1;
    int a;

    for(a=0;a<64;a++)
    {
        if((x==possibities[a].PositionX)&&(y==possibities[a].PositionY))//es wird x/y in der Struktur gesucht
        {
            if((possibities[a].Anzahl==0)&&(counter!=64)) //wenn die Anzahl 0 ist
                {
                     possibities[j].Anzahl = possibities[j].AnzahlMAX; //soll die Anzahl maximal gesetzt werden

                         int u;
                     for(u=0;u<counter1;u++)
                     {
                         if((!x==tempX[u])&&(!y==tempY[u]))
                         {
                           counter2++;
                           printf("counter2 wurde hochgezählt %d    \n",counter2);
                         }
                         else
                         {
                             tempX[counter1]=x;
                             tempY[counter1]=y;
                             counter1++;
                             printf("counter1 wurde hochgezählt auf %d  \n",counter1);
                            printf("x und y sind wo hochgezählt wurde %d,%d \n",x,y);
                         }
                     }





                     counter--;
                     x = PruefungX[counter];
                     y = PruefungY[counter];

                     printf("x/y sind jetzt %d,%d \n",x,y);







                     int search;

                     for(search=0;search<64;search++)
                     {
                         if((x==possibities[search].PositionX)&&(y==possibities[search].PositionY))
                         {  printf("##Die Anzahl ist %d \n",possibities[search].Anzahl);
                            printf("counter2 ist:",counter2);
                           if(counter2==possibities[search].Anzahl)
                           {
                               counter--;                 //soll ein Feld zurück gegangen werden
                               x=PruefungX[counter];
                               y=PruefungY[counter];

                               counter1=0;
                               counter2=0;

                           }
                         }
                     }




                }






        }


        }
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
void Merkenachfolger()
{
    possibities[counter].NachfolgerX=x;
    possibities[counter].NachfolgerY=y;
    printf("counter ist.....%d  \n",counter);
    printf("Der Nachfolger X/Y ist...%d,%d  \n",x,y);

}

void Berechnung()
{
    printf("Berechnung\n");
    x = x+VektorX;
    y = y+VektorY;

    Merkenachfolger();

    int r;
// wenn x und y schon in der Pruefung auftauchen, soll er neue Vektoren berechnen und dadurch dann ein neues x und y
    for(r=0;r<counter;r++)
    {
        if((PruefungX[r]==x)&&(PruefungY[r]==y))
        {   //counter--;
            x = PruefungX[counter-1];
            y = PruefungY[counter-1];
            Vektor();
            Berechnung();
        }

    }

    if(x>8||x<1)
    {   counter--;
        printf("counter%d    \n",counter);
        x = PruefungX[counter];
        y = PruefungY[counter];
         printf("Koordinate X: %d   \n",x);
         printf("Koordinate Y: %d   \n",y);

         // damit wenn er außerhalb des Feldes wieder zurückkehrt die Anzahl nicht minimiert wird
         int z;
         for(z=0;z<64;z++)
         {
             if((x==possibities[z].PositionX)&&(y==possibities[z].PositionY))
             {  //damit er die Anzahl nicht doppelt hochzählt
                 if(y<8||y>1)
                 {
                     possibities[z].Anzahl = possibities[z].AnzahlMAX;  //15.01.2017
                 }

             }
         }


    }

    if(y>8||y<1)
    {
        counter--;
        printf("counter%d    \n",counter);

        x = PruefungX[counter];
        y = PruefungY[counter];
         printf("Koordinate X: %d   \n",x);
         printf("Koordinate Y: %d   \n",y);

        int v;
        for(v=0;v<64;v++)
         {
             if((x==possibities[v].PositionX)&&(y==possibities[v].PositionY))
             {  //damit er die Anzahl nicht doppelt hochzählt
                 if(x<8||x>1)
                 {
                     possibities[v].Anzahl = possibities[v].AnzahlMAX;  //15.01.2017

                 }

             }
         }



    }

    printf("Neues Feld X:%d  \n",x);
    printf("Neues Feld Y:%d  \n",y);


}
//----------------------------------------------------------------------------------------

int Rekursion()
{
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
