#include "Timer.h"
#include "printf.h"

#define resolution 999

#define slaveNumber 9
#define shortClickTime 150

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
  
  };

int tablica[10][2]={0};

struct parameters slave[10];
struct parameters master;