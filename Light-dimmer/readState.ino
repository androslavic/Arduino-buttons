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
