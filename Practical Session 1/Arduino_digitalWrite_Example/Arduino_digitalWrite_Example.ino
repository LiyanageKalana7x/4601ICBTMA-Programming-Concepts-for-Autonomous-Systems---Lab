/*
 * MOUDLE(S) : 4601ICBTMA | 4604ICBTEL
 * SKETCH    : Arduino digitalWrite Example
 * AUTHOR    : Liyanage Kalana Perera (www.linkedin.com/in/liyanagekalana)
 * DATE      : 2026.09.25
 * 
 * REQUIRED LIBRARIES ->
 *                     >  None
 *
 * NOTES ->
 *        > This sketch will demonstrate how to use digitalWrite() function.
 * 
 */

void setup() 
{
  pinMode(13,OUTPUT); // Set the "LED_BUILTIN" or GPIO 13 as an "OUTPUT".
}

void loop() 
{
  digitalWrite(13,HIGH); // Turn the "LED_BUILTIN" or GPIO 13 "ON / HIGH".
}
