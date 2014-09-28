
const int pingPin = 7;
int i;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  ping();
  //Serial.print('H');
  //delay(1000);
  //Serial.print('i');
  //delay(1000);
 //i = Serial.read();
 // Serial.print(i);
}

void ping()
{
   long duration, inches, cm;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  
 inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
 // Serial.print("in, ");
  //Serial.print(cm);
  //Serial.print("cm");
  Serial.println();
  
  delay(500);
}

long microsecondsToInches(long microseconds)
{

  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{

  return microseconds / 29 / 2;
}
