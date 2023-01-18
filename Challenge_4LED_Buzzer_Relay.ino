const int relay = D9;
int button1 = D2;
int button2 = D3;
int led1 = D7;
int led2 = D6;
int led3 = D5;
int led4 = D4;
int buzzer = D8;
int buttonStatus1 = 0;
int buttonStatus2 = 0;

void setup() {
  Serial.begin(115200);
  // relay
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH); 
  Serial.println("relay hidup");
  delay(5000);
  digitalWrite(relay, LOW); 
  Serial.println("relay mati");
  delay(5000);
  digitalWrite(relay, HIGH); 
  Serial.println("relay hidup");
  delay(5000);
  
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT); 
  pinMode(led4, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() { 
  // button 1, 2 led
  buttonStatus1 = digitalRead(button1);
  if(buttonStatus1 == HIGH){
    digitalWrite(led1, HIGH); 
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    Serial.println("Button menyalakan 2 LED");
  }else{
    digitalWrite(led1, LOW); 
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }

  // button 2, 4 led + buzzer
  buttonStatus2 = digitalRead(button2);
  if(buttonStatus2 == HIGH){
    digitalWrite(led1, HIGH); 
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    tone(D8,500);
    Serial.println("Button menyalakan 4 LED dan Buzzer");
  }else{
    digitalWrite(led1, LOW); 
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    noTone(D8);
  }
}
