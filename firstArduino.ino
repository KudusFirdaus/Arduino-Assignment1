int ledPin = 13;
int startValue = 5;

void flashLED(int times){
  for(int i=0; i<times; i++){
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  delay(200);
  }
}
void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("===Smart Countdown Starting===");

  while(startValue>0){
    Serial.print("Count: ");
    Serial.println(startValue);

    flashLED(3);
    delay(1000);
    startValue = startValue - 1;
  }
  Serial.println("===Countdown Complete===");
  digitalWrite(ledPin, HIGH);
  delay(5000);
  digitalWrite(ledPin, LOW);

}

void loop(){

}