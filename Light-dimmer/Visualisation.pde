import processing.serial.*; 

Serial myPort;    // The serial port
String inString=null;  // Input string from serial port
int[] values={50,50,50,50,50,50,50,50,50,50,50};

void setup() { 
  size(500, 900); 

  textSize(20);
  myPort = new Serial(this, "COM6", 9600); 
  myPort.bufferUntil('\n');
  delay(2000);
  myPort.clear();    //clear the port buffer

} 

 void draw() { 
 background(255); 

    for (int i = 0; i < 7; i = i + 1) { 
       fill(205, 100, 0, 100);
       rect (20+i*60, 950, 40, -values[i], 3);
       fill(0, 70, 255);
       text( values[i], 20+i*60, 50); 
   }
  
  
}

void serialEvent(Serial p) { 

  inString = p.readStringUntil('\n'); 
  values = int(split(inString,' '));
    for (int i = 0; i < 8; i = i + 1)  
    {
      print(values[i] + " ");
    } 
      print("\n");

}
