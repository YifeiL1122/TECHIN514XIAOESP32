#include <Arduino.h>


#define ADC_PIN1 2  
#define ADC_PIN2 3  


const float VREF = 3.3;    
const int ADC_RESOLUTION = 4096; 
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Setup complete! Waiting for data...");



 
  analogSetPinAttenuation(ADC_PIN1, ADC_11db);
  analogSetPinAttenuation(ADC_PIN2, ADC_11db);

  Serial.println("ESP32 Dual ADC Voltage Reader");
}

void loop() {
  int adcValue1 = analogRead(ADC_PIN1);
  int adcValue2 = analogRead(ADC_PIN2);

  float voltage1 = (adcValue1 * VREF) / ADC_RESOLUTION;
  float voltage2 = (adcValue2 * VREF) / ADC_RESOLUTION;

  Serial.print("A0 Voltage: ");
  Serial.print(voltage1, 3);  
  Serial.print(" V | A1 Voltage: ");
  Serial.print(voltage2, 3);  
  Serial.println(" V");

  delay(500);
}
