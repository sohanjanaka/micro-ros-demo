
void setup() {
  Serial.begin(115200); // Serial communication
}

float cal_ultrasonic(int us_pin){

  pinMode(us_pin, OUTPUT); // US SIG pin output

  // Sends 10 µs pulse to SIG-pin
  digitalWrite(us_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(us_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(us_pin, LOW);

  // change SIG pin to input
  pinMode(us_pin, INPUT);

  // Measures duration of the pulse from the sig pin
  float duration_us = pulseIn(us_pin, HIGH);
  float distance_cm = 0.017 * duration_us;

  return distance_cm;
}

void loop() {
  float d = cal_ultrasonic(2);
  Serial.println(d);
  delay(50); // Delay 0,5 second
}