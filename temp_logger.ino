// Temperature monitor
// Benson Kalahar
// Nov 2012
#define TEMP A0

//NOTE: DELAY_SECS should be significantly longer than SAMPLE_DELAY_MS
#define DELAY_SECS 10
#define SAMPLE_DELAY_MS 100

#define SLEEP_TIME DELAY_SECS * 1000
#define SAMPLE_COUNT (DELAY_SECS * 1000 / SAMPLE_DELAY_MS - 1)

void setup() {
  Serial.begin(9600);
  pinMode(TEMP, INPUT);
  delay(500);
  Serial.println("temp");
}

double analogAverage(int pin) {
  double sum = 0;
  for(int i = 0; i < SAMPLE_COUNT; i++) {
    sum += analogRead(pin);
    delay(SAMPLE_DELAY_MS);
  }
  return sum / (double)(SAMPLE_COUNT);
}

void loop() {
  double raw = analogAverage(TEMP);
//  float temp = -0.2658 * (float)raw + 98.0; // For the uno
  float temp = 0.2333 * (double)raw - 144.4667; // For the pro mini
  Serial.println(temp, 2);
  delay(SLEEP_TIME - SAMPLE_COUNT * SAMPLE_DELAY_MS);
}
