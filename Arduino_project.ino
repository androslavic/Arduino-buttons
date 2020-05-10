/*

 * 
 * 
 */




#include <printf.h>
#include "Timer.h"




// vrijeme visokog napona na izlazu u milisekundama
int timeLimit = 10000;

// vrijeme odziva tipke u milisekundama
int timeResponse = 150;



//////////////////////////////////////////////////////////////////////

struct parameters{
  int input1;
  int input2;
  int output1;
  int output2;
  unsigned long CurrentTime;
  bool button1,button2;
  bool button1wasPressed,button2wasPressed;
  bool motorUpRunning = 0;
  bool motorDownRunning = 0;
  bool buttonPressed1=0,buttonPressed2=0;
  unsigned long StartTimeButton1 = 0,ElapsedTimeButton1 = 600;
  unsigned long StartTimeButton2 = 0,ElapsedTimeButton2 = 600;
  unsigned long StartTime1 = 0,ElapsedTime1 = 0;
  unsigned long StartTime2 = 0,ElapsedTime2 = 0;
  bool start=1;
  char type;
  };



// dodati strukture za nove parametre    (**1**)
struct parameters slave1,slave2,slave3,slave4,master;
bool masterLock=0;


Timer timer;

void setup() {


/*                     SETUP
 * 
 * Setup funkcija služi za postavljanje parametara, odnosno
 * ulaznih i izlaznih pinova. Da bi se dodali novi parametri,
 * prvo treba inicijalizirati strukturu GORE pod (**1**). 
 * 
 */
  Serial.begin(9600);
  slave1.input1=2;
  slave1.input2=3;
  slave1.output1=5;
  slave1.output2=6;
  slave1.type='s';

  slave2.input1=A2;
  slave2.input2=A3;
  slave2.output1=7;
  slave2.output2=8;
  slave2.type='s';
  
  slave3.input1=A4;
  slave3.input2=A5;
  slave3.output1=9;
  slave3.output2=10;  
  slave3.type='s';


  master.input1=A0;
  master.input2=A1;
  master.type='m';

  
  int tickEvent1 = timer.every(50, func);


}

void loop() {
  
  timer.update();


}

void func()

{
  function(&slave1);
  function(&slave2);
  function(&slave3);
  function(&master);

  
}


void function(struct parameters *arg)
{   
    
    struct parameters s;
   
    // promjeni strukturu ovdje i DOLE
    s=*arg;

    if (s.start)
    {
      pinMode(s.output1, OUTPUT);
      pinMode(s.output2, OUTPUT);
      pinMode(s.input1, INPUT);   
      pinMode(s.input2, INPUT);   
      digitalWrite(s.output1, HIGH);   
      digitalWrite(s.output2, HIGH); 
      s.StartTime1 = millis();
      s.StartTime2 = millis();
      s.start=0;
      printf("slaveFunc: s.output1: %d , s.output2: %d  ",s.output1,s.output2);   
      printf("s.input1: %d , s.input2: %d \r\n",s.input1,s.input2);   
    }



      s.button1 = !(digitalRead(s.input1));
      s.button2 = !(digitalRead(s.input2));

      
    s.CurrentTime = millis();
    s.ElapsedTime1 = s.CurrentTime - s.StartTime1;
    s.ElapsedTime2 = s.CurrentTime - s.StartTime2;
    if(s.ElapsedTime1>timeLimit) s.motorUpRunning=0;  
    if(s.ElapsedTime2>timeLimit) s.motorDownRunning=0;
    
    if (s.button1)
    {
       
       if(!s.button1wasPressed)
       {
         if(s.motorDownRunning){s.motorDownRunning=0;}
         else if(s.motorUpRunning) s.motorUpRunning=0;
         else                      s.motorUpRunning=1;
         
         s.StartTime1 = millis();
         printf("slaveFunc: Pressed button 1 on %d!\n",s.input1);
       }
        s.button1wasPressed=1;
          if(s.type=='m')
          {
            masterLock=1;
          }else
          {
            masterLock=0;
          }
    }else s.button1wasPressed=0;
    if (s.button2)
    {       
       if(!s.button2wasPressed)
       {
         if(s.motorUpRunning){s.motorUpRunning=0;}
         else if(s.motorDownRunning) s.motorDownRunning=0;
         else                        s.motorDownRunning=1;
         
         s.StartTime2 = millis();
         printf("slaveFunc: Pressed button 2 on %d!\n",s.input2);
       }  

        s.button2wasPressed=1;
          if(s.type=='m')
          {
            masterLock=1;
          }else
          {
            masterLock=0;
          }
    }else s.button2wasPressed=0;


    if(s.type=='m' && (s.button2wasPressed || s.button1wasPressed))
    {
        if (s.motorDownRunning){digitalWrite(slave1.output1, HIGH);}else{digitalWrite(slave1.output1, LOW);}
        if (s.motorUpRunning)  {digitalWrite(slave1.output2, HIGH);}else{digitalWrite(slave1.output2, LOW);}  
        if (s.motorDownRunning){digitalWrite(slave2.output1, HIGH);}else{digitalWrite(slave2.output1, LOW);}
        if (s.motorUpRunning)  {digitalWrite(slave2.output2, HIGH);}else{digitalWrite(slave2.output2, LOW);}  
        if (s.motorDownRunning){digitalWrite(slave3.output1, HIGH);}else{digitalWrite(slave3.output1, LOW);}
        if (s.motorUpRunning)  {digitalWrite(slave3.output2, HIGH);}else{digitalWrite(slave3.output2, LOW);}  
        if (s.motorDownRunning){digitalWrite(slave4.output1, HIGH);}else{digitalWrite(slave4.output1, LOW);}
        if (s.motorUpRunning)  {digitalWrite(slave4.output2, HIGH);}else{digitalWrite(slave4.output2, LOW);}    
    } else if (!masterLock)
    {
        if (s.motorDownRunning){digitalWrite(s.output1, HIGH);}else{digitalWrite(s.output1, LOW);}
        if (s.motorUpRunning)  {digitalWrite(s.output2, HIGH);}else{digitalWrite(s.output2, LOW);}    
    }
    
        // promjeni strukturu ovdje i GORE
        *arg=s;
  
}    
