#include "Timer.h"
#include "printf.h"


#define resolution 10


Timer t;                               

struct parameters{
  int input;
  int output;
  bool button=0;
  bool buttonPressed=0;
  int number;
  int value=0;
  int smjer=0;
  };

int tablica[10][2]={0};

struct parameters slave[10];
struct parameters master;

int i;


void setup() {

  slave[1].input=A0;
  slave[1].output=11;
  slave[1].number=1;
  slave[2].input=A2;
  slave[2].output=9;
  slave[2].number=2;
  slave[3].input=A4;
  slave[3].output=7;
  slave[3].number=3;
  slave[4].input=A6;
  slave[4].output=5;
  slave[4].number=4;
  slave[5].input=A1;
  slave[5].output=10;
  slave[5].number=5;
  slave[6].input=A3;
  slave[6].output=8;
  slave[6].number=6;
  slave[7].input=A5;
  slave[7].output=6;  
  slave[7].number=7;
  slave[8].input=A7;
  slave[8].output=4;  
  slave[8].number=8;
  slave[9].input=13;
  slave[9].output=3;  
  slave[9].number=9;

  master.input=12;
  master.output=2;  
  master.number=0;

 

  for (i=1;i<10;i++)
  {
      pinMode(slave[i].output, OUTPUT);
      pinMode(slave[i].input, INPUT);   
      digitalWrite(slave[i].output, LOW);   
  }


  int tickEvent = t.every(200, printValue);
  int tickEvent2 = t.every(200, stateUpdate);
//  int tickEvent3 = t.every(10, testUpdate);
  Serial.begin(9600);
}


void loop() {


  t.update();

}





void printValue(){

   printf(" [%2d] [%2d] [%2d] [%2d] [%2d] [%2d] [%2d] [%2d] ",tablica[1][1],tablica[1][0],tablica[2][1],tablica[2][0],tablica[3][1],tablica[3][0],tablica[4][1],tablica[4][0]);
   printf(" [%2d] [%2d] [%2d] [%2d] [%2d] [%2d] [%2d] [%2d] \n",tablica[5][1],tablica[5][0],tablica[6][1],tablica[6][0],tablica[7][1],tablica[7][0],tablica[8][1],tablica[8][0]);
}

  
