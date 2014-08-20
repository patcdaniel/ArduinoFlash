/*
Squid mantle pressure recording experiment light trigger.

Using a photoresistor and a camera flash inorder to trigger
recording on an NI USB DAQ board.

Because the AD converter is a 10 bits at 0-5v, a threshold
can be set for what defines a trigger flash. This value is set
as an int ranging from 0-1023. When the photoresistor is fully
saturated with light, the resistance approaches 0 Ohmns and the
analogIn line is pulled near 1023.

@AUTHOR:Patrick Daniel
@DATE: 8/20/2014

*/

int triggerOut = 13;
int resistorIn = 0;
int threshold = 800;

void setup() {
  pinMode(triggerOut, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(resistorIn));
  if(analogRead(resistorIn) > threshold) {
    digitalWrite(triggerOut, HIGH);
    Serial.println("high");
    delay(500);
    digitalWrite(triggerOut,LOW);
  }
  else {
    digitalWrite(triggerOut, LOW);
    Serial.println("low");
  }
}
