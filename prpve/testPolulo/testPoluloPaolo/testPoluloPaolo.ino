/*     Simple Stepper Motor Control Exaple Code
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */

// defines pins numbers
const int stepPin = 9; 
const int dirPin = 8; 
 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
 
}
void loop() {

    digitalWrite(stepPin,HIGH); 
    delay(5); 
    digitalWrite(stepPin,LOW); 
    delay(5); 
 
}
