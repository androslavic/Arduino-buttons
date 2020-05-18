void CheckButtonPressed(struct parameters *arg)
{   
    
    arg->button=readState(arg->input);

    
    if (arg->button)
    {
       tableUpdate(arg);
       
       if(!arg->buttonPressed)
       {
        arg->buttonPressed=1;
        if (arg->smjer==0) arg->smjer=1; else arg->smjer=0;
        arg->clickedTime=millis();
        arg->timeCheck=1;
       }
       
     }else 
     {
      arg->buttonPressed=0;
      if (arg->timeCheck)
      {
        arg->currentTime=millis();
        arg->timeCheck=0;
        if (arg->currentTime-arg->clickedTime<shortClickTime && arg->number!=0)
        {
         if  (tablica[arg->number][0]=1 && tablica[arg->number][1]!=resolution) 
             {
              tablica[arg->number][0]=0;
              tablica[arg->number][1]=0;          
              if (arg->smjer==0) arg->smjer=1; else arg->smjer=0;
             }
         else 
             {
              tablica[arg->number][0]=1;
              tablica[arg->number][1]=resolution;          
             }
        }
        
      }
    }    
}    
