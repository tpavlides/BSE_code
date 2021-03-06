/* Transmitter Code
*  Code to read Joystick position and transmit it with a NRF24L01+ to a receiver 
*/

#include <SPI.h>
#include <RF24.h>

// Radio Configuration

RF24 radio(9,10); //sets CE and CSN pins to 9 & 10

byte addresses[][6] = {"1Node","2Node"}; //sets addresses for communication
//change these values to have unique communication! they can be anything


bool radioNumber=1;
bool role = 1;  //Control transmit 1/receive 0


//Analog joystick pins
//int p1 = 0;       
int p2 = 1;      
int p3 = 2;        
int p4 = 3;
//int p5 = 4;  

struct package{
   //int b1 ;             // create struct for data package
   int b2 ;   
   int b3 ; 
   int b4 ;
   //int b5;   
} go;                  //initialize variable of struct type



void setup() {
    Serial.begin(9600);                   // Get ready to send data back for debugging purposes
    radio.begin();                        // Get the transmitter ready
    radio.setPALevel(RF24_PA_LOW);        // Set the power to low. Set to MAX if using over long range
    radio.openWritingPipe(addresses[1]);  // Where we send data out
    radio.openReadingPipe(1,addresses[0]); // Where we receive data back
    radio.setPayloadSize(32);   //Sets payload size, however this is the default of the library. 
// May want to make value smaller if you are sending a small amount of data per packet

}

void loop() {
    //go.b1 = analogRead(p1) ;             // Read the joystick values, puts values into package variables
    go.b2 = analogRead(p2) ;   
    go.b3 = analogRead(p3) ; 
    go.b4 = analogRead(p4) ; 
    //go.b5 = analogRead(p5) ;
 

    radio.stopListening();                                 // Stop listening and begin transmitting
    delay(50);                                            // to stop jittering data

    if(radio.write(&go, sizeof(go)))
    {
    Serial.println('sent go');   // writes values to receiver, prints confirmation
    }
    radio.startListening();   //listens for receiver's confirmation

}

