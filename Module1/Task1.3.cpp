const uint8_t ledPinA = 13;
const uint8_t ledPinB = 12;
               
const uint8_t PirPinA = 2;
const uint8_t PirPinB = 3;
             
uint8_t pirStateA = LOW;
uint8_t pirStateB = LOW;

uint8_t led_stateA=LOW;
uint8_t led_stateB=LOW;


/*the first thing which i did for this task was to declare variables for Pins and LEDs and declare thier initial state as LOW. */

void setup() {
  pinMode(ledPinA, OUTPUT);    
  pinMode(PirPinA, INPUT_PULLUP);
  
  pinMode(ledPinB, OUTPUT);    
  pinMode(PirPinB, INPUT_PULLUP);
  
  Serial.begin(9600);
 
  attachInterrupt(digitalPinToInterrupt(PirPinA),toggleA,CHANGE);
  attachInterrupt(digitalPinToInterrupt(PirPinB),toggleB,CHANGE);
}

/*in the setup function, i have declared the input for both the LEDs and the PIR motion sensor, along with attaching the interrupts*/


void loop(){
}
/*empty loop*/
void toggleA(){
  led_stateA=!led_stateA;
  digitalWrite(ledPinA,led_stateA);
  Serial.println("PIR MOTION SENSOR A!"); 
  Serial.println(led_stateA);
}


void toggleB(){
  led_stateB=!led_stateB;
  digitalWrite(ledPinB,led_stateB);
  Serial.println("PIR MOTION SENSOR B!"); 
  Serial.println(led_stateB);
}

/*the two functions are declared over here, which will be the intterrupt for Sensor A and Sensor B. if the Sensor A starts to work, 
it will write Sensor A on serial monitor and if Sensor B detects motion, it will write Sensor B on the Serial Monitor*/


/*find the video at: https://youtu.be/k1We-uQFhto */