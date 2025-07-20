#define PWM_PIN 9  // OC1A

void setup() {
  pinMode(PWM_PIN, OUTPUT);

  Serial.begin(9600);

  TCCR1A = (1 << COM1A1); 
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11); 
  TCCR1A |= (1 << WGM11);

  ICR1 = 1999;  
}

void loop() {
  for (int dutyCyclePercent = 0; dutyCyclePercent <= 100; dutyCyclePercent += 10) {
    OCR1A = (dutyCyclePercent * ICR1) / 100;

    Serial.print("Duty Cycle: ");
    Serial.print(dutyCyclePercent);
    Serial.println("%");

    delay(1000); 
  }
}
