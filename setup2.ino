#include "lamps.h"

  

void setup() {

  pinMode(interruptPin, INPUT_PULLUP);
 // attachInterrupt(digitalPinToInterrupt(interruptPin), interruptFunction, RISING); 

  init(&slave[1],A0,11,1);
  init(&slave[2],A2,9,2);
  init(&slave[3],A4,7,3);
  init(&slave[4],A6,5,4);
  init(&slave[5],A1,10,5);
  init(&slave[6],A3,8,6);
  init(&slave[7],A5,6,7);
  init(&slave[8],A7,4,8);
  init(&master,12,2,0);

  int tickEvent = t.every(100, printValue);
  int tickEvent2 = t.every(1, stateUpdate);
  int tickEvent3 = t.every(10, interruptFunction);

  Serial.begin(9600);
}


void loop() {


  t.update();

}
