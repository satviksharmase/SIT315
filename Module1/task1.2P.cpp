const uint8_t ledPin = 13;               
const uint8_t inputPin = 2;  
             
uint8_t pirState = LOW;            
int val = 0; 
uint8_t led_state=LOW;

/*here the PIR motion sensor is connected with the 2nd pin and the LED is connected with the 13th pin. further declaring
the initial state of PIR and LED as low*/

void setup() {
  pinMode(ledPin, OUTPUT);    
  pinMode(inputPin, INPUT_PULLUP);
  
  Serial.begin(9600);
 
  attachInterrupt(digitalPinToInterrupt(inputPin),toggle,CHANGE);

  /*here setup is done where we are attaching the interrupt so that if the loop does not work, the interrupt works*/
}

 
void loop(){
}

/*empty loop*/

void toggle(){
  led_state=!led_state;
  digitalWrite(ledPin,led_state);
  Serial.println("motion detected/undetected"); 
  Serial.println(led_state);
}

/*the interrupt function is declared over here and it will change the state of LED when a motion is detected or undetected*/

/*check out the working, click on the link: https://www.youtube.com/watch?v=UKwhWqNKORg&ab_channel=SatvikSharma */
