
int ledPin = 13;               
int inputPin = 2;               
int pirState = LOW;            
int val = 0;  
/* so basically here i am just giving the pins for the led and the sensor. also i am declaring the initial state of PIR motion sensor here*/
 
void setup() {
  pinMode(ledPin, OUTPUT);    
  pinMode(inputPin, INPUT);    
 
  Serial.begin(9600);
}

/*the setup is just to declare the input and output for the program*/
 
void loop(){
  val = digitalRead(inputPin); 
  if (val == HIGH) {            
    digitalWrite(ledPin, HIGH); 
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW);
    if (pirState == HIGH){
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
}

/*here is the main logic of the whole program. there is a basically if else statement where if the motion is detected by the sensor, the LED will turn on and motion detected will be printed on the serial monitor. if the motion is not detected, the LED
will remain off/turn off and will write motion undetected in the sereial monitor*/

/* click the link to check out the video of the whole thing working: https://youtu.be/aEX97L46A_w */ 
