void setup() {
  Serial.begin(9600);
  // Set the ADC input channel to ADC0 and the reference voltage to AVcc
  ADMUX &= ~(1 << MUX0); // Clear the MUX0 bit to set the input channel to ADC0
  ADMUX |= (1 << REFS0);
  // Enable the ADC and set the prescaler to 128
  ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

void loop() {
  // Start the ADC conversion
  ADCSRA |= (1 << ADSC);
  // Wait for the conversion to complete
  while (ADCSRA & (1 << ADSC));
  // Read the digital value from the ADC registers
  uint16_t digital_value = (ADCL | (ADCH << 8));
  // Print the digital value to the Serial Monitor
  Serial.println(digital_value);
  // Wait for some time before starting the next conversion
  delay(100);
}
