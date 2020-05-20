#include "Timer.h"
#include "printf.h"

#define resolution 999
#define timeFactor 10

// timeFactor * resolution -> 10ms

#define slaveNumber 8
#define shortClickTime 150

const byte interruptPin = 3;
volatile byte interrupt = 0;
int interruptTime=0;


Timer t;  
int i;                             

struct parameters{
  int input;
  int output;
  bool button=0;
  bool buttonPressed=0;
  int number;
  int value=0;
  int smjer=1;
  int clickedTime=0;
  int currentTime=0;
  int timeCheck=0;
  int interruptTime=0;  
  };

int tablica[10][2]={0};

struct parameters slave[10];
struct parameters master;
