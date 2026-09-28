/*
 * MOUDLE(S) : 4601ICBTMA | 4604ICBTEL
 * SKETCH    : Arduino Traffic Light System - Level 1
 * AUTHOR    : Liyanage Kalana Perera (www.linkedin.com/in/liyanagekalana)
 * DATE      : 2026.09.26
 * 
 * REQUIRED LIBRARIES ->
 *                     >  None
 *
 * NOTES ->
 *        > This sketch will demonstrate how to build a Traffic Light System for level 1.
 *        > The required components are, 
 *          > 1 x RED LED
 *          > 1 x AMBER LED
 *          > 1 x GREEN LED
 *          > 3 x 100 Ohms Resistors                ---(Brown|Black|Brown)---
 *        
 *        > This program will take the PB input and change the Traffic light state and Pedestrian light state
 */

void setup() 
{
  pinMode(3,OUTPUT); // Connect RED LED to GPIO 3.
  pinMode(4,OUTPUT); // Connect AMBER LED to GPIO 3.
  pinMode(5,OUTPUT); // Connect GREEN LED to GPIO 3.
}

void loop() 
{
  // This section is written based on "TrafficLightSequence.png" image available on the "Practical Session 3" folder.
  // RED LED = OFF | AMBER LED = OFF | GREEN LED = ON
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  delay(1000);
  // RED LED = OFF | AMBER LED = ON | GREEN LED = OFF
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  delay(1000);
  // RED LED = ON | AMBER LED = OFF | GREEN LED = OFF
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  delay(1000);
  // RED LED = ON | AMBER LED = ON | GREEN LED = OFF
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  delay(1000);
}
