/*
 * MOUDLE(S) : 4601ICBTMA | 4604ICBTEL
 * SKETCH    : Arduino digitalWrite with delay Example
 * AUTHOR    : Liyanage Kalana Perera (www.linkedin.com/in/liyanagekalana)
 * DATE      : 2026.09.25
 * 
 * REQUIRED LIBRARIES ->
 *                     >  None
 *
 * NOTES ->
 *        > This sketch will demonstrate how to use delay() function.
 *        > delay() funtion can use to "pause" the program for a while and return the value in "milliseconds".
 * 
 */

void setup() 
{
  //LED_BUILTIN can be use when you want to use the on-board LED ("L" LED on the board)
  pinMode(LED_BUILTIN,OUTPUT); // Set the "LED_BUILTIN" or GPIO 13 as an "OUTPUT".
}

void loop() 
{
  digitalWrite(LED_BUILTIN,HIGH); // Turn the "LED_BUILTIN" or GPIO 13 "ON / HIGH".
  delay(1000); // 1s delay (1s = 1000 ms)
  digitalWrite(LED_BUILTIN,LOW); // Turn the "LED_BUILTIN" or GPIO 13 "OFF / LOW".
  delay(1000); // 1s delay (1s = 1000 ms) 
}
