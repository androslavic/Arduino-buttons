
#include "printf.h"


// High voltage time on output pins in miliseconds
int timeLimit = 7;

int cnt=0;
int sec=0;
int state=0;


//////////////////////////////////////////////////////////////////////

struct parameters{
  int input1;
  int input2;
  int output1;
  int output2;
  unsigned long CurrentTime;
  bool button1,button2;
  bool button1wasPressed=1,button2wasPressed=1;
  bool motorUpRunning = 0;
  bool motorDownRunning = 0;
  unsigned long StartTimeButton1 = 0,ElapsedTimeButton1 = 600;
  unsigned long StartTimeButton2 = 0,ElapsedTimeButton2 = 600;
  unsigned long StartTime1 = 0,ElapsedTime1 = 0;
  unsigned long StartTime2 = 0,ElapsedTime2 = 0;
  bool start=1;
  char type;
  };



// add NEW structure for a new input-output pair   (**1**)
struct parameters slave1,slave2,slave3,slave4,master;
bool masterLock=0;



void setup() {

/*                     SETUP
 * 
 * Setup function - used for setting parameters.
 * To add a new input-output pair, first initialize
 * a NEW structure (**1**) and add it to function
 * call at loop() function
 * 
 */  Serial.begin(9600);

  slave1.input1=A0;
  slave1.input2=A1;
  slave1.output1=11;
  slave1.output2=10;
  slave1.type='s';

  slave2.input1=A2;
  slave2.input2=A3;
  slave2.output1=9;
  slave2.output2=8;
  slave2.type='s';
  
  slave3.input1=A4;
  slave3.input2=A5;
  slave3.output1=7;
  slave3.output2=6;  
  slave3.type='s';

  slave4.input1=A6;
  slave4.input2=A7;
  slave4.output1=5;
  slave4.output2=4;  
  slave4.type='s';


  master.input1=12;
  master.input2=13;
  master.type='m';

  


}

void timeFunction (){

    delay(50);
    cnt++;
    if (cnt%20==0){
    sec++;
  
          printf("sec: %2d state: %d\r\n",sec,state);

    }
  }


void loop() {

  function(&slave1);
  function(&slave2);
  function(&slave3);
  function(&slave4);
  function(&master);
  timeFunction();
  
  
  

}




void function(struct parameters *arg)
{   

      
    struct parameters s;
   
    s=*arg;

    if (s.start)
    {
      pinMode(s.output1, OUTPUT);
      pinMode(s.output2, OUTPUT);
      pinMode(s.input1, INPUT);   
      pinMode(s.input2, INPUT);   
      digitalWrite(s.output1, LOW);   
      digitalWrite(s.output2, LOW); 
      s.StartTime1 = sec;
      s.StartTime2 = sec;
      s.start=0;
    }


      if(s.input1!=20)
      {
      s.button1 = !(digitalRead(s.input1));
      s.button2 = !(digitalRead(s.input2));
      }else
      {
      s.button1 = !(analogRead(s.input1)>500);
      s.button2 = !(analogRead(s.input2)>500);        
      }
      
    s.CurrentTime = sec;
    s.ElapsedTime1 = s.CurrentTime - s.StartTime1;
    s.ElapsedTime2 = s.CurrentTime - s.StartTime2;
    if(s.ElapsedTime1>timeLimit) { if (state==1)state=0;}
    if(s.ElapsedTime2>timeLimit) { if (state==2)state=0;}
    
    if (s.button1)
    {
         s.StartTime1 = sec;
       
       if(!s.button1wasPressed)
       {
         if(s.motorDownRunning){s.motorDownRunning=0;}
         else if(s.motorUpRunning) s.motorUpRunning=0;
         else                      s.motorUpRunning=1;
         if(s.type=='m'){
           if (state==1) state=0; 
           else if (state==0) state=1; 
           if (state==2) state=0; 
          }
        printf("State %d!\n",state);
         
       }
        s.button1wasPressed=1;
          if(s.type=='m')
          {
            masterLock=1;
            slave1.StartTime1=s.StartTime1;
            slave2.StartTime1=s.StartTime1;
            slave3.StartTime1=s.StartTime1;
            slave4.StartTime1=s.StartTime1;
          }else
          {
            masterLock=0;
          }
    }else s.button1wasPressed=0;
    if (s.button2)
    {       
         s.StartTime2 = sec;

       if(!s.button2wasPressed)
       {
         if(s.motorUpRunning){s.motorUpRunning=0;}
         else if(s.motorDownRunning) s.motorDownRunning=0;
         else                        s.motorDownRunning=1;
        if(s.type=='m') {
           if (state==0) state=2;
           if (state==1) state=0; 
        }           
        printf("State %d!\n",state);

       }  

        s.button2wasPressed=1;
          if(s.type=='m')
          {
            slave1.StartTime2=s.StartTime2;
            slave2.StartTime2=s.StartTime2;
            slave3.StartTime2=s.StartTime2;
            slave4.StartTime2=s.StartTime2;
            }
    }else s.button2wasPressed=0;

          if(s.type=='m')
          {
            masterLock=1;
          }else
          {
            masterLock=0;
          }
    if (!masterLock) 
    {
        if (s.motorDownRunning){digitalWrite(s.output1, HIGH);}else{digitalWrite(s.output1, LOW);}
        if (s.motorUpRunning)  {digitalWrite(s.output2, HIGH);}else{digitalWrite(s.output2, LOW);}    
    }

    if (state==0 && s.type=='m'){
        digitalWrite(slave1.output1, LOW);slave1.motorDownRunning=0;
        digitalWrite(slave2.output1, LOW);slave2.motorDownRunning=0;
        digitalWrite(slave3.output1, LOW);slave3.motorDownRunning=0;
        digitalWrite(slave4.output1, LOW);slave4.motorDownRunning=0;   
        digitalWrite(slave1.output2, LOW);slave1.motorUpRunning=0;
        digitalWrite(slave2.output2, LOW);slave2.motorUpRunning=0;
        digitalWrite(slave3.output2, LOW);slave3.motorUpRunning=0;
        digitalWrite(slave4.output2, LOW);slave4.motorUpRunning=0;
      }
    if (state==1 && s.type=='m'){
        digitalWrite(slave1.output1, LOW);slave1.motorDownRunning=0;
        digitalWrite(slave2.output1, LOW);slave2.motorDownRunning=0;
        digitalWrite(slave3.output1, LOW);slave3.motorDownRunning=0;
        digitalWrite(slave4.output1, LOW);slave4.motorDownRunning=0;
        digitalWrite(slave1.output2, HIGH);slave1.motorUpRunning=1;
        digitalWrite(slave2.output2, HIGH);slave2.motorUpRunning=1;
        digitalWrite(slave3.output2, HIGH);slave3.motorUpRunning=1;
        digitalWrite(slave4.output2, HIGH);slave4.motorUpRunning=1;
      }
    if (state==2 && s.type=='m'){
        digitalWrite(slave1.output1, HIGH);slave1.motorDownRunning=1;
        digitalWrite(slave2.output1, HIGH);slave2.motorDownRunning=1;
        digitalWrite(slave3.output1, HIGH);slave3.motorDownRunning=1;
        digitalWrite(slave4.output1, HIGH);slave4.motorDownRunning=1;
        digitalWrite(slave1.output2, LOW);slave1.motorUpRunning=0;
        digitalWrite(slave2.output2, LOW);slave2.motorUpRunning=0;
        digitalWrite(slave3.output2, LOW);slave3.motorUpRunning=0;
        digitalWrite(slave4.output2, LOW);slave4.motorUpRunning=0;
      }

      *arg=s;
  
}    
