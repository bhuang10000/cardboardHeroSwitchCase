/*
  Switch statement
 
 Demonstrates the use of a switch statement.  The switch
 statement allows you to choose from among a set of discrete values
 of a variable.  It's like a series of if statements.
 
 To see this sketch in action, but the board and sensor in a well-lit
 room, open the serial monitor, and and move your hand gradually
 down over the sensor.
 
 The circuit:
 * photoresistor from analog in 0 to +5V
 * 10K resistor from analog in 0 to ground
 
 created 1 Jul 2009
 modified 9 Apr 2012
 by Tom Igoe 
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/SwitchCase
 */



void setup() 
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(6,OUTPUT);
  //pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{  
  int sensorReading = analogRead(A0);
  int range = map(sensorReading, 0,1000, 0, 4);
  Serial.println(sensorReading);
  // do something different depending on the 
  // range value:
  switch (range) {
  case 0:    // your hand is on the sensor
     digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(6,LOW);
    break;
  case 1:    // your hand is close to the sensor
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(6,LOW);

    break;
  case 2:    // your hand is a few inches from the sensor
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH); 
    digitalWrite(11,LOW);
    digitalWrite(6,LOW);
    break;
  case 3:    // your hand is nowhere near the sensor
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(6,LOW);
    break;
  case 4:
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    analogWrite(6,HIGH);
  default:
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(6,HIGH);
    break;
  } 
  delay(100);        // delay in between reads for stability
}







