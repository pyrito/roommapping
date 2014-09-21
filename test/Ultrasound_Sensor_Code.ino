// Pin number constants
const int triggerPin = 4;
const int echoPin = 3;

void setup() {
// initialize serial communication:
Serial.begin(9600);
}

void loop()
{
// establish variables for duration of the ping,
// and the distance result in inches and centimeters:
long duration, feet, inches, cm;

// The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
pinMode(triggerPin, OUTPUT);
digitalWrite(triggerPin, LOW);
delayMicroseconds(2);
digitalWrite(triggerPin, HIGH);
delayMicroseconds(5);
digitalWrite(triggerPin, LOW);

// The echo pin is used to read the signal from the PING))): a HIGH
// pulse whose duration is the time (in microseconds) from the sending
// of the ping to the reception of its echo off of an object.
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);

// convert the time into a distance
inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);
feet = microsecondsToFeet(duration);

//Serial.print(feet);
//Serial.print("feet, ");
//Serial.print(inches);
//Serial.print("in, ");
Serial.print(cm);
Serial.print("cm");
Serial.println();

delay(500);
}

long microsecondsToInches(long microseconds)
{
// According to Parallax's datasheet for the PING))), there are
// 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
// second). This gives the distance travelled by the ping, outbound
// and return, so we divide by 2 to get the distance of the obstacle.
// See:[...]
return microseconds / 74 / 2;
}

long microsecondsToFeet(long microseconds)
{
// According to Parallax's datasheet for the PING))), there are
// 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
// second). This gives the distance travelled by the ping, outbound
// and return, so we multiply by 12 to convert to feet and then by 2 to get the distance of the obstacle.
// See: [...]
return microseconds / 74 / 2 / 12;
}

long microsecondsToCentimeters(long microseconds)
{
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the
// object we take half of the distance travelled.
return microseconds / 29 / 2;
}

