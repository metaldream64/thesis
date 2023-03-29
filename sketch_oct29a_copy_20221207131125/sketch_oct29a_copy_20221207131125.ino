#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  dht.begin();
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {

  delay(1000);

  float t = dht.readTemperature();

  if (isnan(t)) {
    Serial.println(F("Error with sensor!"));
    return;
  }

  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print('\n');

  if (t > 28) {
    digitalWrite(7, HIGH);
    delay(5000);
    return;
  } else {
    digitalWrite(7, LOW);
  }

  if (t < 27) {
    digitalWrite(4, HIGH);    
    delay(5000);
    return;
  } else {
    digitalWrite(4, LOW);
  }
}