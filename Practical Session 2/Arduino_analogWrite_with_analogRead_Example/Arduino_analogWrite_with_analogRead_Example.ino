/*
 * MOUDLE(S) : 4601ICBTMA | 4604ICBTEL
 * SKETCH    : Arduino analogWrite with analogRead Example
 * AUTHOR    : Liyanage Kalana Perera (www.linkedin.com/in/liyanagekalana)
 * DATE      : 2026.09.25
 * 
 * REQUIRED LIBRARIES ->
 *                     >  None
 *
 * NOTES ->
 *        > This sketch will demonstrate how to use analogRead() function.
 *        > analogRead() function will use to read analog inputs.
 *        > analogWrite() function will only work with "ANALOG" section pins (A0 to A5).
 *        > Use "INPUT" instead of "INPUT_PULLUP" when use analogRead() function.
 * 
 */

void setup() 
{
  pinMode(A0,INPUT); // Set the A0 as an "INPUT".
  pinMode(3,OUTPUT); // Set the GPIO 13 as an "OUTPUT".
}

void loop() 
{
  // The value of A0 will be set the PWM on GPIO 3.
  // The LED brightness will be based on the Potentiometer input.
  analogWrite(3,analogRead(A0));
}
