/*
   EMG Measurements

   Reads serial data from EMG sensor (Sparkfun MyoWare Muscle Sensor Development Kit) and saves data
   to file.

   v1.0: 27.01.2020
   by Hella Toto-Kiesa
*/

int EMGPin = A0;      // pin at which the EMG Muscle sensor is connected
int EMGdata = 0;      // variable to store the analog data read from the sensor

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // setup serial
}

void loop() {
  // put your main code here, to run repeatedl
  EMGdata =  analogRead(EMGPin);
  Serial.println(EMGdata);
  delay(10); // ms
}
