int analogPin = 0;     // potentiometer wiper (middle terminal) connected to analog pin 3
                       // outside leads to ground and +5V
int flexPin1 = A0;           // variable to store the value read
int flexPin2 = A1;
int flexPin3 = A2;
int flexPin4 = A3;
int flexPin5 = A4;

void setup()
{
  Serial.begin(9600);          //  setup serial
}

void loop()
{
  int flex1 = analogRead(flexPin1);    // read the input pin
  int flex2 = analogRead(flexPin2);
  int flex3 = analogRead(flexPin3);
  int flex4 = analogRead(flexPin4);
  int flex5 = analogRead(flexPin5);
  
  /*Serial.println(pinky);             // debug value
  Serial.println(ringfinger);
  Serial.println(middlefinger);
  Serial.println(indexfinger);
  Serial.println(thumb);*/
  
   /*int flex1 = analogRead(flexPin1);
   int flex2 = analogRead(flexPin2);
   int flex3 = analogRead(flexPin3);
   int flex4 = analogRead(flexPin4);
   int flex5 = analogRead(flexPin5);*/
 
  flex1 = map(flex1, 0, 760, 0, 100);   //Re-maps a number from one range to another 
//analogWrite(0, val);
  Serial.println(flex1);
  constrain(flex1, 0, 100);  // limits range of sensor values to between 1 and 100
  
  flex2 = map(flex2, 0, 760, 0, 100);
  Serial.println(flex2);
  constrain(flex2, 0, 100);
  
  flex3 = map(flex3, 0, 760, 0, 100);
  Serial.println(flex3);
  constrain(flex3, 0, 100);
  
  flex4 = map(flex4, 0, 760, 0, 100);
  Serial.println(flex4);
  constrain(flex4, 0, 100);
  
  flex5 = map(flex5, 0, 760, 0, 100);
  Serial.println(flex5);
  constrain(flex5, 0, 100);
  delay(500);
}
