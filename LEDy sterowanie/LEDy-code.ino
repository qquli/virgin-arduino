/*LED (+button+potentiometer) */

const int ledPin = 14;  //PWM_SIGNAL_OUT
const int button = 0; 
const int analogPin = A0; //potentiometer

bool power = LOW;

ICACHE_RAM_ATTR void ButtonOnOff(){  //switch "On/Off"
  cli();          //disable interupts
  power = !power;
  delay(50);
  sei();          //enable interupts
}

void setup(){
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), ButtonOnOff, RISING);
}

void loop(){
  Serial.print(power);
if(power)
  analogWrite(ledPin,analogRead(analogPin)*2);
else
  analogWrite(ledPin,0);
}
