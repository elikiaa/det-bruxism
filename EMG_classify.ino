#include "model.h"
#include "FeatureExtraction.h"

#define PERIOD 1000  // period in us

double *features;
double sig[NSAMPLES];
byte pred_class;
byte counter = 0;
const int pinLED = 13;
const int pinEMG = A0;
unsigned long last_us = 0L;

void setup() {
  Serial.begin(115200);
  pinMode(pinEMG, INPUT);
  pinMode(pinLED, OUTPUT);
  
}

void loop() {
  if (micros () - last_us > PERIOD){ // get constant sampling rate of 1000 HZ reference: https://forum.arduino.cc/index.php?topic=467338.0
    last_us += PERIOD ;
    if (counter < NSAMPLES)
      sample ();
    else{
      counter = 0;
      sample ();
    }
  }
  FeatureExtraction fe(sig);
  features = fe.get_features();
  Serial.print(features[0]);
  Serial.print(features[4]);
  Serial.println(features[13]);
  pred_class = predict(fe.get_features());
  if (pred_class == 0) {
    digitalWrite(pinLED, LOW); 
  }
  else if (pred_class == 1) {
    digitalWrite(pinLED, HIGH);  
  }
}

void sample(){
  sig[counter] = map(analogRead(pinEMG), 0, 1023, 0, 5);
  //Serial.println(sig[counter]);
  counter += 1;
}
