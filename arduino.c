#define sensorPin A0
#define buzzerPin 3
#define relayPin 2
void setup() {
  
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int val = digitalRead(sensorPin);
  Serial.println(val);

  static int cnt = 0;

  digitalWrite(relayPin, HIGH);

  if (val == 0) {
    cnt = 0;
    digitalWrite(buzzerPin, LOW);
  }
  else {
    cnt += 1;
    if (cnt >= 375) {
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(relayPin, LOW);
    }
  }
}