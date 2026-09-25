/*
 * MOUDLE(S) : 4601ICBTMA | 4604ICBTEL
 * SKETCH    : Arduino analogWrite Example
 * AUTHOR    : Liyanage Kalana Perera (www.linkedin.com/in/liyanagekalana)
 * DATE      : 2026.09.25
 * 
 * REQUIRED LIBRARIES ->
 *                     >  None
 *
 * NOTES ->
 *        > This sketch will demonstrate how to use analogWrite() function.
 *        > analogWrite() function will drive PWM from the GPIO.
 *        > analogWrite() function can only be use with "PWM" pins.
 *        > "PWM" pins are located on "DIGITAL" side and printed "~" before the pin number.
 * 
 */

void setup() 
{
  pinMode(3,OUTPUT); // Set the GPIO 13 as an "OUTPUT".
}

void loop() 
{
  // GPIO 3 go from 0 to 255. LED will slowly light up.
  for(int i = 0;i<=255;i++)
  {
    analogWrite(3,i); // Assign the "i" value as the PWM.
    delay(10);
  }
  delay(1000);
  // GPIO 3 go from 255 to 0. LED will slowly go off.
  for(int i = 255;0<=i;i--)
  {
    analogWrite(3,i); // Assign the "i" value as the PWM.
    delay(10);
  }
  delay(1000);
}
