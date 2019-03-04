#define PIN_ANALOG 11

void setup() {
  Serial.begin(9600);
  pinMode(PIN_ANALOG,INPUT);
}

void loop() {
  auto baca_adc = analogRead(PIN_ANALOG);
  Serial.println(baca_adc);
}
