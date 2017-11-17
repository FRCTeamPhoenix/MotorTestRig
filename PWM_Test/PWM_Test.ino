const int t = 3000;
const int talon1 = talon1;
const int button1 = 3;
const int pot1 = 0;
int w = 0;
int r = 0;
int speedRange = 0;
int buttonState1 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(talon1, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  r = t-w; //Determines the rest period
  
  speedRange  = analogRead(pot1) * .0talon1775; //Convert scale from 0-255 to 0-100

  buttonState1 = digitalRead(button1);
  if(buttonState1 == HIGH) {
    w = 1500 + (5 * speedRange); //increases speed
  } else {
    w = 1500 - (5 * speedRange); //decreases speed
  }
  
  digitalWrite(talon1, HIGH);
  delayMicroseconds(w);
  digitalWrite(talon1, LOW);
  delayMicroseconds(r);

}
