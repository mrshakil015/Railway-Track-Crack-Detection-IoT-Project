int in1 = 13;
int in2 = 6;
int in3 = 4;
int in4 = 5;
int ENA = 9;
int ENB = 10;
int speed = 220;
int trigpin = 11;
int echopin = 12;
int buzzer=A0;
float distance;
float duration;
int led = 7;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(led, OUTPUT);
 pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = (duration * 0.034) / 2;
  Serial.print("the distance is = ");
  Serial.print(distance);
  Serial.print("cm\n");
  if (distance > 2.5)
  {
    tone(buzzer,450);
    digitalWrite(led, HIGH);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  else
  {
    noTone(buzzer);
    digitalWrite(led, LOW);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
   
  }
}
