/*
 * MOUDLE(S) : 4601ICBTMA | 4604ICBTEL
 * SKETCH    : Serial Monitor and Serial Plotter Example
 * AUTHOR    : Liyanage Kalana Perera (www.linkedin.com/in/liyanagekalana)
 * DATE      : 2026.09.26
 * 
 * REQUIRED LIBRARIES ->
 *                     >  None
 *
 * NOTES ->
 *        > This sketch will demonstrate how to use "Serial Monitor" and "Serial Plotter".
 *        > "Serial Monitor" is a tool that we can use to "read" the Serial Communication of the Arduino and to read input values from "analogRead".
 *        > "Serial Plotter" is a tool that we can use to "plot" the Serial Communication of the Arduino and to read input values from "analogRead".
 *
 *          
 */

void setup() 
{
  pinMode(A0,INPUT); // Analog Input goes to "A0".
  Serial.begin(9600); // Initialize Serial Communication. 9600 is the Baud rate (the number of times a signal changes or pulses per second in a communication channel)
}

void loop() 
{
  Serial.println(analogRead(A0)); // This function will write the values from "analogRead" into the Serial Monitor and Plotter.
  delay(100);
}