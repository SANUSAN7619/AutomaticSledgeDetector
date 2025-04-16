#define TRIG_PIN 6 
#define ECHO_PIN 5 
#define LED_PIN 10 
void setup() { 
pinMode(TRIG_PIN, OUTPUT); 
pinMode(ECHO_PIN, INPUT); 
pinMode(LED_PIN, OUTPUT); 
Serial.begin(9600);  // For debugging 
} 
void loop() { 
// Send a trigger pulse 
digitalWrite(TRIG_PIN, LOW); 
delayMicroseconds(2); 
digitalWrite(TRIG_PIN, HIGH); 
delayMicroseconds(10); 
digitalWrite(TRIG_PIN, LOW); 
// Measure the echo time 
long duration = pulseIn(ECHO_PIN, HIGH); 
// Calculate distance in cm 

 float distance = (duration / 2.0) * 0.0343; 
// Print distance to Serial Monitor 
Serial.print("Distance: "); 
Serial.print(distance); 
Serial.println(" cm"); 
// Check if distance is below the threshold 
if (distance < 10) {  // Set threshold as 10 cm 
digitalWrite(LED_PIN, HIGH); // Turn on LED 
} else { 
digitalWrite(LED_PIN, LOW);  // Turn off LED 
} 
delay(500); // Wait before next measurement 
}