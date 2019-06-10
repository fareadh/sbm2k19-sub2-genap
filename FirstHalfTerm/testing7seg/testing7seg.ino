const int nilai[8]={10,7,27,26,25,11,1,4};
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0;i<=7;i++)
  {
    pinMode(nilai[i],OUTPUT);
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i=0;i<=7;i++)
  {
    digitalWrite(nilai[i],HIGH);
    Serial.println(nilai[i]);
    delay(500);
    digitalWrite(nilai[i],LOW);
    delay(500);
  }
}
