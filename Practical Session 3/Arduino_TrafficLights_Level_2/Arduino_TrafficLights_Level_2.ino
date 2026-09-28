/*
 * MOUDLE(S) : 4601ICBTMA | 4604ICBTEL
 * SKETCH    : Arduino Traffic Light System - Level 2
 * AUTHOR    : Liyanage Kalana Perera (www.linkedin.com/in/liyanagekalana)
 * DATE      : 2026.09.26
 * 
 * REQUIRED LIBRARIES ->
 *                     >  None
 *
 * NOTES ->
 *        > This sketch will demonstrate how to build a Traffic Light System for level 2.
 *        > The required components are, 
 *          > 2 x RED LED
 *          > 1 x AMBER LED
 *          > 2 x GREEN LED
 *          > 3 x 100 Ohms Resistors                ---(Brown|Black|Brown)---
 *          > 1 x Push Button
 *
 *        > This program will take the PB input and change the Traffic light state and Pedestrian light state.
 *        > Here we used "Variables" to define GPIO.
 * 
 */
// Define "Global" Variables.
int PushButton = 2; // GPIO 2 is now called "PushButton"
int TrafficLED_R = 3; // GPIO 3 is now called "TrafficLED_R"
int TrafficLED_A = 4; // GPIO 4 is now called "TrafficLED_A"
int TrafficLED_G = 5; // GPIO 5 is now called "TrafficLED_G"
int PedestrianLED_R = 6; // GPIO 6 is now called "PedestrianLED_R"
int PedestrianLED_G = 7; // GPIO 7 is now called "PedestrianLED_G"

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
    // RED LED = OFF | AMBER LED = ON | GREEN LED = OFF
    digitalWrite(TrafficLED_R,LOW);
    digitalWrite(TrafficLED_A,HIGH);
    digitalWrite(TrafficLED_G,LOW);
    // RED LED = ON | GREEN LED = OFF
    digitalWrite(PedestrianLED_R,HIGH);
    digitalWrite(PedestrianLED_G,LOW);
    delay(1000);
    // RED LED = ON | AMBER LED = OFF | GREEN LED = OFF
    digitalWrite(TrafficLED_R,HIGH);
    digitalWrite(TrafficLED_A,LOW);
    digitalWrite(TrafficLED_G,LOW);
    // RED LED = ON | GREEN LED = OFF
    digitalWrite(PedestrianLED_R,HIGH);
    digitalWrite(PedestrianLED_G,LOW);
    delay(1000);
    // RED LED = OFF | GREEN LED = ON
    digitalWrite(PedestrianLED_R,LOW);
    digitalWrite(PedestrianLED_G,HIGH);
    delay(3000); // Adjust the delay accordingly.
    // RED LED = ON | GREEN LED = OFF
    digitalWrite(PedestrianLED_R,HIGH);
    digitalWrite(PedestrianLED_G,LOW);
    delay(1000);
    // RED LED = ON | AMBER LED = ON | GREEN LED = OFF
    digitalWrite(TrafficLED_R,HIGH);
    digitalWrite(TrafficLED_A,HIGH);
    digitalWrite(TrafficLED_G,LOW);
    // RED LED = ON | GREEN LED = OFF
    digitalWrite(PedestrianLED_R,HIGH);
    digitalWrite(PedestrianLED_G,LOW);
    delay(1000);
  }else
  {
    // RED LED = OFF | AMBER LED = OFF | GREEN LED = ON
    digitalWrite(TrafficLED_R,LOW);
    digitalWrite(TrafficLED_A,LOW);
    digitalWrite(TrafficLED_G,HIGH);
    // RED LED = ON | GREEN LED = OFF
    digitalWrite(PedestrianLED_R,HIGH);
    digitalWrite(PedestrianLED_G,LOW);
    delay(100);
  }
}
