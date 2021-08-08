int Led1 = 12;
int Led2 = 10;
int Led3 = 8;

/*Leds connected to the sensors which lit up when connected to the PIR motion sensor*/

int Pir1 = 7;
int Pir2 = 5;
int Pir3 = 3;

/*the PIR motion sensor which will detect the motion*/

int Led4 = 13;

/*this Led will be connected timer interrupt*/

volatile byte led1 = 0;
volatile byte led2 = 0;
volatile byte led3 = 0;

/*current state of the interrupt LED*/

void setup()
{

    pinMode(Pir1, INPUT_PULLUP);
    pinMode(Pir2, INPUT_PULLUP);
    pinMode(Pir3, INPUT_PULLUP);

    pinMode(Led1, OUTPUT);
    pinMode(Led2, OUTPUT);
    pinMode(Led3, OUTPUT);

    pinMode(Led4, OUTPUT);

    /*input and output in the setup void for detecting motion in the input and send
it as output to LED */

    Serial.begin(9600);

    noInterrupts();

    PCICR |= 0b00000111;
    PCMSK2 |= 0b10101000;

    /*this will turn on the the leds connected at pin 7,5 and 3 on the digital side*/

    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;

    /*these 3 lines will set th TCCR1A, TCCR1B and intial conuter to 0*/

    OCR1A = 31249;

    /*(16000000/(1024*0.5))-1* setting the frequency for every 1/2 second*/

    TCCR1B |= (1 << CS12) | (1 << CS10);
    TIMSK1 |= (1 << OCIE1A);
    TCCR1B |= (1 << WGM12);

    interrupts();

    /*first turning on the CTC mode, then setting up a 1024 prescaler and then enaling timer interrupt*/
}

void loop()
{
}

/*empty loop*/

ISR(PCINT2_vect)
{

    if (led1 = PIND & B00001000)
    {
        Serial.println("Led1");
    }
    if (led2 = PIND & B00100000)
    {
        Serial.println("Led2");
    }
    if (led3 = PIND & B10000000)
    {
        Serial.println("Led3");
    }
}
/*this will be the intterupt function which will print to the serial monitor 
when motion is detected by the PIR motion sensor.*/

ISR(TIMER1_COMPA_vect)
{
    digitalWrite(Led4, digitalRead(Led4) ^ 1);
    Serial.print("TIMER STATUS:");
    Serial.println(digitalRead(Led4));
}

/*the next will be the timer interrupt function which will keep printing the 
timer status*/