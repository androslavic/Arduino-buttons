void tableUpdate(int number, int* smjer, int buttonPressed){

  if (!buttonPressed)
    {

     if (number==0) if (tablica[0][0]==0) tablica[0][0]=1; else tablica[0][0]=0;

     else if(tablica[0][0]==0) 
            
             if (tablica[number][0]==0)
             {
              tablica[number][0]=1; 
              tablica[number][1]=resolution;
              *smjer=1;

             }
             else if (tablica[number][1]==0)
             {
              tablica[number][0]=0;
              *smjer=0;
              }

            else 
            {  
              for (i=1;i<10;i++) tablica[i][0]= 0;
              tablica[0][0]= 0;
              tablica[number][0]=1;
            }

//      if(tablica[number][1]==0) tablica[number][1]=resolution; 
//      else if(tablica[number][1]==resolution){tablica[number][1]=0;tablica[number][0]=0; }

    }else
    {
      if (*smjer==1) if (tablica[number][1]>0 && tablica[number][1]<=resolution)  tablica[number][1]-=1; 
      if (*smjer==0) if (tablica[number][1]>=0  && tablica[number][1]<resolution) tablica[number][1]+=1; 
      if (tablica[number][1]==0) tablica[number][0]=0; else tablica[number][0]=1; 
    }
}

  
