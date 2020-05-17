void function(struct parameters *arg)
{   
    
    struct parameters s;
   
    s=*arg;

    s.button=readState(s.input);

    
    if (s.button)
    {
       tableUpdate(s.number,&s.smjer,s.buttonPressed);
       
       if(!s.buttonPressed)
       {
        s.buttonPressed=1;
        if (s.smjer==0) s.smjer=1; else s.smjer=0;
       }
       
     }else s.buttonPressed=0;

    
   *arg=s;
  
}    
