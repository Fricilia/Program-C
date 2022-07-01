const int triggerPin = 7;
const int echoPin = 6;
const int relay = 13;

long duration, cm;
void setup() 
{
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relay, OUTPUT);

  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  cm = konversiSenti(duration);

//  if(cm < 30 && cm > 0){
//    digitalWrite(relay, HIGH);
//  }
//  else{
//    digitalWrite(relay, LOW);
//  }

  Serial.print("jarak ");
  Serial.print(cm);
  Serial.print(" cm ");
  Serial.println();

  delay(100);
}

long konversiSenti(long microseconds)
{
  return microseconds / 29 / 12;
}
