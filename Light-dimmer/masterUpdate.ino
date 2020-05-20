void masterUpdate(void){

// if master is active, all outputs are 0

  if (tablica[0][0]==1)
     for (i=1;i<slaveNumber+1;i++)
        digitalWrite(slave[i].output, LOW);              

   if (tablica[0][0]==0) digitalWrite(master.output, LOW);   else digitalWrite(master.output, HIGH);        
}
