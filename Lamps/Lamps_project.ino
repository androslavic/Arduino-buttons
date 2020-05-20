struct parameters{
  int input;
  int output;
  bool button;
  bool buttonPressed;
  int number;
  };

int tablica[10]={0};

struct parameters slave[10];
struct parameters master;



void setup() {


  int i;

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
}


void loop() {

  function(&master);
  function(&slave[1]);
  function(&slave[2]);
  function(&slave[3]);
  function(&slave[4]);
  function(&slave[5]);
  function(&slave[6]);
  function(&slave[7]);
  function(&slave[8]);
  function(&slave[9]);
  delay(50);

  int i;

  if (tablica[0]==0)
     for (i=1;i<10;i++)
        if (tablica[i]==0) digitalWrite(slave[i].output, LOW);   else digitalWrite(slave[i].output, HIGH);        
  else
     for (i=1;i<10;i++)
        digitalWrite(slave[i].output, LOW);              

   if (tablica[0]==0) digitalWrite(master.output, LOW);   else digitalWrite(master.output, HIGH);        
}




void function(struct parameters *arg)
{   
    
    struct parameters s;
   
    s=*arg;

    s.button=readState(s.input);
    
    if (s.button)
    {
       if(!s.buttonPressed)
       {
        tableUpdate(s.number);
       }
       
       s.buttonPressed=1;

    }else s.buttonPressed=0;

 
    
   *arg=s;
  
}    



int readState(int input){

  int output=0;
  
      if(input==20 || input==21)
      {
      output = !(analogRead(input)>500);
      }else
      {
      output= !(digitalRead(input));
      }
  return output;
}


void tableUpdate(int number){

  int i;

  if (number==0) if (tablica[0]==0) tablica[0]=1; else tablica[0]=0;

  else if(tablica[0]==0) if (tablica[number]==0) tablica[number]=1; else tablica[number]=0;

  else 
  {
    for (i=1;i<10;i++) tablica[i]= 0;
    tablica[0]= 0;
    tablica[number]=1;
  }
}

  
