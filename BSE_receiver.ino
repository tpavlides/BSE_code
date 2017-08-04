/*  Receiver Code 
*   Code to receive data from NRF24L01+ */


#include <SPI.h>
#include <RF24.h>
#include <Servo.h> //Includes servo library

Servo pinky, ringfinger, middlefinger, indexfinger, thumb;

//int servoPin1 = 3;
int servoPin2 = 3;
int servoPin3 = 5;
int servoPin4 = 6;
//int servoPin5 = 10;

/*int flexPin1 = A0;
int flexPin2 = A1;
int flexPin3 = A2;
int flexPin4 = A3; 
int flexPin5 = A4;*/ 

//Radio Configuration

RF24 radio(9,10);
byte addresses[][6] = {"1Node","2Node"}; // make sure this matches the transmitter adresses

bool radioNumber=0;
bool role = 0;  //Control transmit/receive

struct package{
   //int b1 ;             //Create struct and create variable with that data-type
   int b2 ;   
   int b3 ; 
   int b4 ; 
   //int b5 ;  
} go;

void setup() { 
    //Attach the servo objects to their respective pins
  //pinky.attach(servoPin1);
  ringfinger.attach(servoPin2);
  middlefinger.attach(servoPin3);
  indexfinger.attach(servoPin4);
  //thumb.attach(servoPin5);
  
  /* set each servo pin to output; I'm not acutally sure if this is even necessary, 
  but I did just in case it is */
  //pinMode(servoPin1, OUTPUT);
  pinMode(servoPin2, OUTPUT);
  pinMode(servoPin3, OUTPUT);
  pinMode(servoPin4, OUTPUT);
  //pinMode(servoPin5, OUTPUT);
  
 /* //Set each flex sensor pin to input: this is necessary
 // pinMode(flexPin1, INPUT);
  pinMode(flexPin2, INPUT);
  pinMode(flexPin3, INPUT);
  pinMode(flexPin4, INPUT);
  //pinMode(flexPin5, INPUT);*/
  
    Serial.begin(9600);        
    radio.begin();             // Initializes radio
    radio.setPALevel(RF24_PA_LOW);   // Sets power output to low.
    radio.openWritingPipe(addresses[0]); //opens writing pipeline
    radio.openReadingPipe(1,addresses[1]); //opens reading pipeline
    radio.setPayloadSize(32); //sets payload size, but this is default
    radio.startListening();
}
void loop() {

 delay(50);               //increase for debuggy, decrease to decrease jitter
    if(radio.available()){
        radio.read(&go,sizeof(go)); //reads value of go

    } else {  
    }
    
    //Serial.print(go.b1);    //prints all 4 values from joysticks
    Serial.print("\t");
    Serial.print(go.b2);
    Serial.print("\t");
    Serial.print(go.b3);
    Serial.print("\t");
    Serial.println(go.b4);
  
  /*//Defines analog input variables
  //int flex1 = analogRead(flexPin1);
  int flex2 = analogRead(flexPin2);
  int flex3 = analogRead(flexPin3);
  int flex4 = analogRead(flexPin4);
  //int flex5 = analogRead(flexPin5);*/
  
  /* Defines "pos" variables as being proportional to the flex inputs. 
  The 400 to 700 value range seemed adequate for my sensors, 
  but you can change yours accordingly. */
  
  /*int pos1 = map(flex1, 400, 700, 0, 180);
  Serial.print(flex1);
  pos1 = constrain(pos1, 0, 180);*/
  
  int pos2 = map(go.b2, 400, 700, 0, 180);
  Serial.print(go.b2);
  pos2 = constrain(pos2, 0, 180);
  
  int pos3 = map(go.b3, 400, 700, 0, 180);
  Serial.print(go.b3);
  pos3 = constrain(pos3, 0, 180);
  
  int pos4 = map(go.b4, 480, 640, 0, 180);
  Serial.print(go.b4);
  pos4 = constrain(pos4, 0, 180);
  
  /*int pos5 = map(flex5, 400, 700, 0, 180);
  Serial.print(flex5);
  pos5 = constrain(pos5, 0, 180);*/     
  
  //Tells servos to move by the amount specified in the "pos" variables
  //pinky.write(pos1);
  ringfinger.write(pos2);
  middlefinger.write(pos3);
  indexfinger.write(pos4);
  //thumb.write(pos5);
             
    }

