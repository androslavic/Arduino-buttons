void init (struct parameters *arg,int input, int output, int number){


  arg->input=input;
  arg->output=output;
  arg->number=number;

  pinMode(output, OUTPUT);
  pinMode(input, INPUT);   
  digitalWrite(output, LOW);   
  
  }
