
const int buttonPin = 2;     // the number of the forward/reverse pin
const int pwmOutputLine = 6;     // the number pwm output

const int minOnTime = 600;    // micro seconds
const int maxOnTime = 2400;   // micro seconds
int zeroOnTime = ( minOnTime + maxOnTime ) / 2;
const int pwmPeriod = 10000;  // PWM period 10,000 uS => 100 Hz

const int debug  = 0;

int goForward( int );

void setup() 
{ 
  
  Serial.begin(9600);
  pinMode(pwmOutputLine, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() 
{
  // read the input on analog pin 0:
  // Read the forward/revers switch value
  int potValue = analogRead(A0);
  int buttonState = digitalRead(buttonPin);
  int onTime;
  
  // print out the value you read:

  float potRatio = (float)potValue / 1024.0;
  if ( potRatio < ( 5.0 / 1024.0 ))
    potRatio = 0.0;
  
  if ( goForward( buttonState ))
  {
      onTime = zeroOnTime + potRatio * ( maxOnTime - zeroOnTime );
  }
  else
  {
      onTime = zeroOnTime - potRatio * ( zeroOnTime - minOnTime );
  }
 
  digitalWrite(pwmOutputLine, HIGH);
  delayMicroseconds( onTime ); 
  digitalWrite(pwmOutputLine, LOW);
  delayMicroseconds(10000 - onTime);

  if ( debug )
  {
    Serial.print("Button State ");
    Serial.println(buttonState);    
    Serial.print("Pot Value ");
    Serial.println(potValue);
    Serial.print("PotRatio ");
    Serial.println(potRatio);
    Serial.print("onTime ");
    Serial.println(onTime);    
    Serial.println(""); 

    delay(1000);        // delay in between reads 
  }
}

/*
 * goForward will return check the state of the 
 * forward/reverse switch and return true if we 
 * are commanding a positive voltage out
 * of the speed controller
 */
int goForward( int buttonState )
{
  int retVal;
  if ( 1 == buttonState )
  {
    retVal = 1;
  }
  else
  {
    retVal = 0;
  }
  return( retVal );
}
