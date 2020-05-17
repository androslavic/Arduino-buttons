void function(struct parameters *arg)
{   
    
    struct parameters s;
   
    s=*arg;

    s.button=readState(s.input);
    
    if (s.button)
    {
       if(!s.buttonPressed)
       {
        s.buttonPressed=1;
        tableUpdate(s.number,s.smjer,s.buttonPressed);
        if (s.smjer==0 ) s.smjer=1; else s.smjer=0;
        if (tablica[s.number][1]==resolution)  s.smjer=1;
        if (tablica[s.number][1]==0)  s.smjer=0;
       }else
        tableUpdate(s.number,s.smjer,s.buttonPressed);

       
    }else s.buttonPressed=0;

    
   *arg=s;
  
}    
