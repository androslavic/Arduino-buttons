void tableUpdate(struct parameters *arg){

  

  if (!arg->buttonPressed)
    {
     //toggle if master is pressed 
     if (arg->number==0) if (tablica[0][0]==0) tablica[0][0]=1; else tablica[0][0]=0;
     
     //if master is not active
     else if(tablica[0][0]==0) 
        {
             //if slave was turned off, set it to MAX value 
             if (tablica[arg->number][0]==0)
             {
              tablica[arg->number][0]=1; 
              arg->smjer=1;

             }
             // if slave has been lowered to the 0 value, turn it off
             else if (tablica[arg->number][1]==0)
             {
              tablica[arg->number][0]=0;
              arg->smjer=0;
              }

            // 
             else if (tablica[0][0]==1)
            {  
              for (i=1;i<slaveNumber+1;i++) tablica[i][0]= 0;
              tablica[0][0]= 0;
              tablica[arg->number][0]=1;
            }
        }
        // if master is active, reset all states and turn on selected 
        else if (tablica[0][0]==1)
        {
          for (i=1;i<10;i++) 
          {
            tablica[i][0]= 0;
            tablica[i][1]= 0;
          }
          tablica[0][0]= 0;
          tablica[arg->number][0]=1;  
          tablica[arg->number][1]=resolution;
        } 
  
    }else
    {
      if (arg->smjer==1) if (tablica[arg->number][1]>0 && tablica[arg->number][1]<=resolution)  tablica[arg->number][1]-=1; 
      if (arg->smjer==0) if (tablica[arg->number][1]>=0  && tablica[arg->number][1]<resolution) tablica[arg->number][1]+=1; 
      if (arg->number!=0) if (tablica[arg->number][1]==0) tablica[arg->number][0]=0; else tablica[arg->number][0]=1; 
    }
}

  
