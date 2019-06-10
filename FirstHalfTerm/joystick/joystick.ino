#define THRESHOLD 100

double dt_last = 0.0;
String SWITCH = "OFF";

void setup() {
  // put your setup code here, to run once:
pinMode(5,INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  auto vry = analogRead(9);
  auto vrx = analogRead(10);
  if(!digitalRead(5)){
    SWITCH = "ON";    
  }
  else{
    SWITCH = "OFF";
  }

  auto dt_now = millis();

  if((dt_now - dt_last) > THRESHOLD){
  Serial.print("VRX: ");
  Serial.println(vrx);

  Serial.print("VRY: ");
  Serial.println(vry);

  Serial.print("SWITCH:");
  Serial.println(SWITCH);

  Serial.println("~~~~~~~~~~~~~~~~~~~");
  
  dt_last = dt_now;
  
  }
}
