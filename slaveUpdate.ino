void slaveUpdate(void){

  if (tablica[0][0]==0)
     for (i=1;i<slaveNumber+1;i++)
        if (tablica[i][0]==0) digitalWrite(slave[i].output, LOW);   
          else 
          {
            if (interrupt)
            {
              interrupt=0;
              interruptTime=millis();

            }
            currentTime=millis();
            // for each slave, check if time has passed to turn in on
            for (i=1;i<=slaveNumber;i++)  
            {
            // interrupt happens every 10ms
            // output is triggered after X ms
            // X is inversely proportional to tablica[i][1] value

              if (abs(currentTime-interruptTime) > (resolution - tablica[i][1])*timeFactor)
              {
                if (tablica[i][0]==1)
                  digitalWrite(slave[i].output, HIGH);  
                else      
                  digitalWrite(slave[i].output, LOW);  
              }

              
           }
          }
          
}
