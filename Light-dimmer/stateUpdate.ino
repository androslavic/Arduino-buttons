void stateUpdate(){
  
  CheckButtonPressed(&master);
  CheckButtonPressed(&slave[1]);
  CheckButtonPressed(&slave[2]);
  CheckButtonPressed(&slave[3]);
  CheckButtonPressed(&slave[4]);
  CheckButtonPressed(&slave[5]);
  CheckButtonPressed(&slave[6]);
  CheckButtonPressed(&slave[7]);
  CheckButtonPressed(&slave[8]);
  CheckButtonPressed(&slave[9]);

  masterUpdate();
  slaveUpdate();


  }
