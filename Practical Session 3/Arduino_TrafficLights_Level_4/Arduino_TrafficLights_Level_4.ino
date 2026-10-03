/*
 * MOUDLE(S) : 4601ICBTMA | 4604ICBTEL
 * SKETCH    : Arduino Traffic Light System - Level 4
 * AUTHOR    : Liyanage Kalana Perera (www.linkedin.com/in/liyanagekalana)
 * DATE      : 2026.10.03
 * 
 * REQUIRED LIBRARIES ->
 *                     >  None
 *
 * NOTES ->
 *        > This sketch will demonstrate how to build a Traffic Light System for level 4.
 *        > The required components are, 
 *          > 2 x RED LED
 *          > 1 x AMBER LED
 *          > 2 x GREEN LED
 *          > 3 x 100 Ohms Resistors                ---(Brown|Black|Brown)---
 *          > 1 x Push Button
 *          > 7 Segment Display - Common Anode (If using 74LS47)
 *          > 7 Segment Display - Common Cathode (If using CD4511 / 74LS48)
 *          > 2 x 1 K Ohms Resistors (For the 7-Segment Display COM pins) ---(Brown|Black|Red)---
 *
 *        > This program will drive "74LS47 / CD4511 / 74LS48" BCD to 7- Segment Display Driver(s).
 *        > CC = Common Cathode and CA = Common Anode.
 *        > Use 7-Segment Display polarity (CC or CA) based on the driver. Always refer the Datasheets of IC's.
 *
 *        > You need intermediate level C++ programming knwoledge to understand this sketch.
 *        > Go through your lecture notes and see if you can understand the code.
 * 
 */
// Define Pins.
#define PushButton  2 // GPIO 2 is now called "PushButton"
#define TrafficLED_R 3 // GPIO 3 is now called "TrafficLED_R"
#define TrafficLED_A 4 // GPIO 4 is now called "TrafficLED_A"
#define TrafficLED_G 5 // GPIO 5 is now called "TrafficLED_G"
#define PedestrianLED_R 6 // GPIO 6 is now called "PedestrianLED_R"
#define PedestrianLED_G 7 // GPIO 7 is now called "PedestrianLED_G"
#define A_PIN 8 // GPIO 8 is now called "A_PIN"
#define B_PIN 9 // GPIO 9 is now called "B_PIN"
#define C_PIN 10 // GPIO 10 is now called "C_PIN"
#define D_PIN 11 // GPIO 11 is now called "D_PIN"

// Dummy functions
void TrafficCON(); // Function to control Traffic Lights.
void PedCON(); // Funtion to control Pedestrian Lights.
void decimal_to_BCD(); // Function to drive 7-Segment Driver (74LS47 / CD4511 / 74LS48).

void setup() 
{
  pinMode(PushButton,INPUT_PULLUP); // Connect PushButton to GPIO 2.Use "INPUT_PULLUP" for Internal Pullup.
  pinMode(TrafficLED_R,OUTPUT); // Connect TrafficLED_R LED to GPIO 3.
  pinMode(TrafficLED_A,OUTPUT); // Connect TrafficLED_A LED to GPIO 4.
  pinMode(TrafficLED_G,OUTPUT); // Connect TrafficLED_G LED to GPIO 5.
  pinMode(PedestrianLED_R,OUTPUT); // Connect PedestrianLED_R LED to GPIO 6.
  pinMode(PedestrianLED_G,OUTPUT); // Connect PedestrianLED_G LED to GPIO 7.
  pinMode(A_PIN,OUTPUT); // Connect A from the Driver IC to GPIO 8.
  pinMode(B_PIN,OUTPUT); // Connect B from the Driver IC to GPIO 9.
  pinMode(C_PIN,OUTPUT); // Connect C from the Driver IC to GPIO 10.
  pinMode(D_PIN,OUTPUT); // Connect D from the Driver IC to GPIO 11.
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
    // Countdown Timer from 9 to 0.
    for(int i=9;i>=0;i--)
    {
      decimal_to_BCD(i);
      delay(1000);
    }
    //-----------------------------------------------
    delay(100); // Adjust the delay accordingly.
    PedCON(1,0); // RED LED = ON | GREEN LED = OFF
    delay(500); // Adjust the delay accordingly.
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
// 7-Segment Driver Control Function.
void decimal_to_BCD(int digit)
{
  switch(digit)
  {
    case 0: digitalWrite(A_PIN,LOW);
            digitalWrite(B_PIN,LOW);
            digitalWrite(C_PIN,LOW);
            digitalWrite(D_PIN,LOW);
            break;
    case 1: digitalWrite(A_PIN,HIGH);
            digitalWrite(B_PIN,LOW);
            digitalWrite(C_PIN,LOW);
            digitalWrite(D_PIN,LOW);
            break;
    case 2: digitalWrite(A_PIN,LOW);
            digitalWrite(B_PIN,HIGH);
            digitalWrite(C_PIN,LOW);
            digitalWrite(D_PIN,LOW);
            break;
    case 3: digitalWrite(A_PIN,HIGH);
            digitalWrite(B_PIN,HIGH);
            digitalWrite(C_PIN,LOW);
            digitalWrite(D_PIN,LOW);
            break;
    case 4: digitalWrite(A_PIN,LOW);
            digitalWrite(B_PIN,LOW);
            digitalWrite(C_PIN,HIGH);
            digitalWrite(D_PIN,LOW);
            break;
    case 5: digitalWrite(A_PIN,HIGH);
            digitalWrite(B_PIN,LOW);
            digitalWrite(C_PIN,HIGH);
            digitalWrite(D_PIN,LOW);
            break;
    case 6: digitalWrite(A_PIN,LOW);
            digitalWrite(B_PIN,HIGH);
            digitalWrite(C_PIN,HIGH);
            digitalWrite(D_PIN,LOW);
            break;
    case 7: digitalWrite(A_PIN,HIGH);
            digitalWrite(B_PIN,HIGH);
            digitalWrite(C_PIN,HIGH);
            digitalWrite(D_PIN,LOW);
            break;
    case 8: digitalWrite(A_PIN,LOW);
            digitalWrite(B_PIN,LOW);
            digitalWrite(C_PIN,LOW);
            digitalWrite(D_PIN,HIGH);
            break;
    case 9: digitalWrite(A_PIN,HIGH);
            digitalWrite(B_PIN,LOW);
            digitalWrite(C_PIN,LOW);
            digitalWrite(D_PIN,HIGH);
            break;
  }
}
