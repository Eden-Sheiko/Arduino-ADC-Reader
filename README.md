# Arduino ADC Reader

This project demonstrates how to read analog values from an ADC pin (A0) using an Arduino.

## Description

The code initializes the serial communication, configures the ADC for reading values from the A0 pin, and reads the digital value from the ADC in a loop. The digital value is printed to the Serial Monitor.

## Usage

1. Connect your Arduino board to your computer.
2. Open the Arduino IDE.
3. Copy the code provided below and paste it into a new Arduino sketch.
4. Select the correct board and port in the Arduino IDE.
5. Upload the sketch to your Arduino board.
6. Open the Serial Monitor to view the digital values read from the A0 pin.

```cpp
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
```
## Notes
* Make sure to connect the analog input to the A0 pin on your Arduino board.
* The delay between ADC readings can be adjusted by changing the value of delay(100); in the code.
