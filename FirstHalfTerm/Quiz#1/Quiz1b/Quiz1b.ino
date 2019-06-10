#define TOTAL_PIN 4

int LED[TOTAL_PIN];

void OFF(){
for(int i=0; i<TOTAL_PIN; i++){
  digitalWrite(LED[i],LOW);
} 
}

void setup() {
LED[0] = 27;
LED[1] = 26;
LED[2] = 25;
LED[3] = 18; 
for(int i=0; i<TOTAL_PIN; i++){
  pinMode(LED[i],OUTPUT);
}

}

void loop() {
  for(int i=0; i<TOTAL_PIN; i++){
    digitalWrite(LED[i],HIGH);
    delay(200);
    OFF();
  }
  for(int i=TOTAL_PIN-1; i>=0; i--){
    digitalWrite(LED[i],HIGH);
    delay(200);
    OFF();
  }

}
