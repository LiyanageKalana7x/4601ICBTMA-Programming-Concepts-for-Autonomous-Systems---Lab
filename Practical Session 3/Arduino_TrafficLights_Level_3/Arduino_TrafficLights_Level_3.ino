/*
 * MOUDLE(S) : 4601ICBTMA | 4604ICBTEL
 * SKETCH    : Arduino Traffic Light System - Level 3
 * AUTHOR    : Liyanage Kalana Perera (www.linkedin.com/in/liyanagekalana)
 * DATE      : 2026.09.26
 * 
 * REQUIRED LIBRARIES ->
 *                     >  None
 *
 * NOTES ->
 *        > This sketch will demonstrate how to build a Traffic Light System for level 3.
 *        > The required components are, 
 *          > 2 x RED LED
 *          > 1 x AMBER LED
 *          > 2 x GREEN LED
 *          > 3 x 100 Ohms Resistors                ---(Brown|Black|Brown)---
 *          > 1 x Push Button
 *
 *        > This is a much optimized yet advanced program using methods such as "#define","functions".
 *        > Here we used "#define" to define GPIO.
 *        > Here we use funtions to drive the Traffic lights,
 *          > TrafficCON(R_OUT,A_OUT,G_OUT) to drive Traffic Lights.
 *          > PedCON(R_OUT,G_OUT) to drive Pedestrian Lights.
 *
 *        > You need intermediate level C++ programming knwoledge to understand this sketch.
 *        > Go through your lecture notes and see if you can understand the code.
 * 
 */
// Define "Global" Variables.
int PushButton = 2; // GPIO 2 is now called "PushButton"
int TrafficLED_R = 3; // GPIO 3 is now called "TrafficLED_R"
int TrafficLED_A = 4; // GPIO 4 is now called "TrafficLED_A"
int TrafficLED_G = 5; // GPIO 5 is now called "TrafficLED_G"
int PedestrianLED_R = 6; // GPIO 6 is now called "PedestrianLED_R"
int PedestrianLED_G = 7; // GPIO 7 is now called "PedestrianLED_G"

// Dummy functions
void TrafficCON(); // Function to control Traffic Lights.
void PedCON(); // Funtion to control Pedestrian Lights.

void setup() 
{
  pinMode(PushButton,INPUT_PULLUP); // Connect PushButton to GPIO 2.Use "INPUT_PULLUP" for Internal Pullup.
  pinMode(TrafficLED_R,OUTPUT); // Connect TrafficLED_R LED to GPIO 3.
  pinMode(TrafficLED_A,OUTPUT); // Connect TrafficLED_A LED to GPIO 4.
  pinMode(TrafficLED_G,OUTPUT); // Connect TrafficLED_G LED to GPIO 5.
  pinMode(PedestrianLED_R,OUTPUT); // Connect PedestrianLED_R LED to GPIO 6.
  pinMode(PedestrianLED_G,OUTPUT); // Connect PedestrianLED_G LED to GPIO 7.
}

void loop() 
{
  // This section is written based on "TrafficLightSequence.png" image available on the "Practical Session 3" folder.
  // Checking the status of the PushButton. If the PushButton is pressed..Then...
  if(digitalRead(PushButton)!=1)
  {
    TrafficCON(0,1,0); // RED LED = OFF | AMBER LED = ON | GREEN LED = OFF
    PedCON(1,0); // RED LED = ON | GREEN LED = OFF
    delay(1000);
    TrafficCON(1,0,0); // RED LED = ON | AMBER LED = OFF | GREEN LED = OFF
    PedCON(1,0); // RED LED = ON | GREEN LED = OFF
    delay(1000);
    PedCON(0,1); // RED LED = OFF | GREEN LED = ON
    delay(3000); // Adjust the delay accordingly.
    PedCON(1,0); // RED LED = ON | GREEN LED = OFF
    delay(1000);
    TrafficCON(1,1,0);// RED LED = ON | AMBER LED = ON | GREEN LED = OFF
    PedCON(1,0); // RED LED = ON | GREEN LED = OFF
    delay(1000);
  }else
  {
    TrafficCON(0,0,1); // RED LED = OFF | AMBER LED = OFF | GREEN LED = ON
    PedCON(1,0); // RED LED = ON | GREEN LED = OFF
    delay(100);
  }
}

// Traffic Control Function.
// R,A, and G represent the LED states you want.
void TrafficCON(int R,int A,int G)
{
  // Switch Case to check "R" value.
  switch(R)
  {
    case 0: digitalWrite(TrafficLED_R,LOW);
            break;
    case 1: digitalWrite(TrafficLED_R,HIGH);
            break;
  }
  // Switch Case to check "A" value.
  switch(A)
  {
    case 0: digitalWrite(TrafficLED_A,LOW);
            break;
    case 1: digitalWrite(TrafficLED_A,HIGH);
            break;
  }
  // Switch Case to check "G" value.
  switch(G)
  {
    case 0: digitalWrite(TrafficLED_G,LOW);
            break;
    case 1: digitalWrite(TrafficLED_G,HIGH);
            break;
  }
}
// Pedestrian Control Function.
// R and G represent the LED states you want.
void PedCON(int R,int G)
{
  // Switch Case to check "R" value.
  switch(R)
  {
    case 0: digitalWrite(PedestrianLED_R,LOW);
            break;
    case 1: digitalWrite(PedestrianLED_R,HIGH);
            break;
  }
  // Switch Case to check "G" value.
  switch(G)
  {
    case 0: digitalWrite(PedestrianLED_G,LOW);
            break;
    case 1: digitalWrite(PedestrianLED_G,HIGH);
            break;
  }
}
