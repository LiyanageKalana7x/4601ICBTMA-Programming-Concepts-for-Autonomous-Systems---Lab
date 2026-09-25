/*
 * MOUDLE(S) : 4601ICBTMA | 4604ICBTEL
 * SKETCH    : Arduino digitalWrite with digitalRead Example
 * AUTHOR    : Liyanage Kalana Perera (www.linkedin.com/in/liyanagekalana)
 * DATE      : 2026.09.25
 *
 * REQUIRED LIBRARIES ->
 *                     >  None
 * 
 * NOTES ->
 *        > This sketch will demonstrate how to use digitalRead() function.
 *        > digitalRead() function can be use to read a digital input.
 * 
 */

void setup() 
{
  pinMode(3,OUTPUT); // Set the GPIO 3 as an "OUTPUT".
  pinMode(2,INPUT_PULLUP);// Set the GPIO 2 as an "INPUT" with "Internal Pullup".
}

void loop() 
{
  // Read the status of "GPIO 2".
  if(digitalRead(2)!=1)
  {
    // If the PB is pressed. Then make GPIO 13 = HIGH.
    digitalWrite(3,HIGH); // Turn the "LED_BUILTIN" or GPIO 13 "ON / HIGH".
  }else
  {
    // If the PB is released. Then make GPIO 13 = LOW.
    digitalWrite(3,LOW); // Turn the "LED_BUILTIN" or GPIO 13 "OFF / LOW".
  }
  delay(10); // 10ms delay 
}
