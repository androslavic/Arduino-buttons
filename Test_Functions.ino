void testUpdate()
{

          if (tablica[1][1]<10) digitalWrite(slave[8].output, LOW);   else digitalWrite(slave[8].output, HIGH);
          if (tablica[1][1]<20) digitalWrite(slave[4].output, LOW);   else digitalWrite(slave[4].output, HIGH);
          if (tablica[1][1]<30) digitalWrite(slave[7].output, LOW);   else digitalWrite(slave[7].output, HIGH);
          if (tablica[1][1]<40) digitalWrite(slave[3].output, LOW);   else digitalWrite(slave[3].output, HIGH);
          if (tablica[1][1]<50) digitalWrite(slave[6].output, LOW);   else digitalWrite(slave[6].output, HIGH);
          if (tablica[1][1]<60) digitalWrite(slave[2].output, LOW);   else digitalWrite(slave[2].output, HIGH);
          if (tablica[1][1]<70) digitalWrite(slave[5].output, LOW);   else digitalWrite(slave[5].output, HIGH);
          if (tablica[1][1]<80) digitalWrite(slave[1].output, LOW);   else digitalWrite(slave[1].output, HIGH);
          if (tablica[1][1]<90) digitalWrite(slave[9].output, LOW);   else digitalWrite(slave[9].output, HIGH);
  
  
}



void printValue(){

  //printf("tablica[0][0] = %d",tablica[0][0]);
  printf("%d %d %d %d %d %d %d %d %d ",
  tablica[9][1],tablica[1][1],tablica[5][1],tablica[2][1],tablica[6][1],tablica[3][1],tablica[7][1],tablica[4][1],
  tablica[8][1]);
  printf("%d %d %d %d %d %d %d %d %d \n",
  tablica[9][0],tablica[1][0],tablica[5][0],tablica[2][0],tablica[6][0],tablica[3][0],tablica[7][0],tablica[4][0],
  tablica[8][0]);
  
//  printf("%4d%2d%4d%2d%4d%2d%4d%2d%4d%2d%4d%2d%4d%2d%4d%2d ",
//  tablica[1][1],tablica[1][0],tablica[2][1],tablica[2][0],tablica[3][1],tablica[3][0],tablica[4][1],tablica[4][0],
//  tablica[5][1],tablica[5][0],tablica[6][1],tablica[6][0],tablica[7][1],tablica[7][0],tablica[8][1],tablica[8][0]);
}

  
