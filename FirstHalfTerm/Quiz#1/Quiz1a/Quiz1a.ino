#define TOTAL_PIN 2

int LED[TOTAL_PIN];

void OFF(){
for(int i=0; i<TOTAL_PIN; i++){
  digitalWrite(LED[i],LOW);
} 
}

void setup() {
LED[0] = 25;
LED[1] = 27; 
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

}
