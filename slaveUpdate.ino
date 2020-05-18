void slaveUpdate(void){

  if (tablica[0][0]==0)
     for (i=1;i<slaveNumber+1;i++)
        if (tablica[i][0]==0) digitalWrite(slave[i].output, LOW);   
          else 
          {
            digitalWrite(slave[i].output, HIGH);        
            slave[i].value=tablica[i][1];
          }
          // implementation of timer and pulse needed

}
