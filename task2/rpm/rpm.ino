
//Encoder sensor
#define outputA PB12
int encoderValue;                   //number of pulses
int encoder_rev = 2500;
long previousMillis = 0;
long currentMillis = 0;
float rpm;


void setup() {
  Serial3.begin (9600);

  //Encoder sensor
  pinMode(outputA, INPUT_PULLUP);
  attachInterrupt(outputA, updateEncoder, RISING);
  previousMillis = millis();
}

void loop() {
  //Encoder sensor
  currentMillis = millis();
  if ((currentMillis - previousMillis) > 1000) {
    previousMillis = currentMillis;
    rpm = (encoderValue * 60 / encoder_rev);
    encoderValue = 0;
  }
  Serial3.print("SPEED: ");
  Serial3.println(rpm);
}
void updateEncoder()
{
  encoderValue++;
}
