void masterUpdate(void){


  if (tablica[0][0]==0)
     for (i=1;i<10;i++)
        if (tablica[i][0]==0) digitalWrite(slave[i].output, LOW);        
  else
     for (i=1;i<10;i++)
        digitalWrite(slave[i].output, LOW);              

   if (tablica[0][0]==0) digitalWrite(master.output, LOW);   else digitalWrite(master.output, HIGH);        
}
