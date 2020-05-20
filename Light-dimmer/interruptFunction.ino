void interruptFunction(){

  interrupt=1;  
     for (i=1;i<slaveNumber+1;i++)
        digitalWrite(slave[i].output, LOW);  
  
  }
