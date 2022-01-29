// POC LEM CAS 6-NP

// Hardware mapping...
#define ADC_REFERENCE                 5
#define ZERO_STATE_VOLTAGE            2.46

// Difining constants...
const int MOVING_AVERAGE_SIZE =           8;
const int MOVING_AVARAGE_SUM_MAX_INDEX =  (MOVING_AVERAGE_SIZE - 1);

float mapDiscreteValueToVoltage(int discreteValue);
float mapVoltageToCurrent(float voltage);
float applyMovingAvarage(float voltage);
void fillInWithZeros(float arr[], int elementsCount);

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  Serial.println("Starting program...");
}

void loop() {
  int discreteValue = analogRead(0);

  float voltage = mapDiscreteValueToVoltage(discreteValue);
  Serial.print("Measured voltage: ");
  Serial.println(voltage);
  Serial.print("That means ");
  
  float current = mapVoltageToCurrent(voltage);
  float currentMovingAverage = applyMovingAvarage(current);
  
  Serial.print(currentMovingAverage);
  Serial.println(" amps!");
  delay(250);
}


float mapDiscreteValueToVoltage(int discreteValue) {
  return discreteValue / 1023.0 * ADC_REFERENCE; 
}

float mapVoltageToCurrent(float voltage) {
  return (2 * (voltage - ZERO_STATE_VOLTAGE)) / 0.625;
}

float applyMovingAvarage(float voltage) {
  static bool firstExecution = true;
  static float measures[MOVING_AVERAGE_SIZE];
  static int index = 0;
  
  float movingAverageSum = 0;
  
  if (firstExecution) {
    fillInWithZeros(measures, MOVING_AVERAGE_SIZE);
    firstExecution = false;
  }
  
  if (index > 7) {
    index = 0;
  }

  measures[index] = voltage;

  for (int i = 0; i < MOVING_AVARAGE_SUM_MAX_INDEX; i++) {
    movingAverageSum += measures[i];
  }
  index++;
  
  return movingAverageSum / MOVING_AVERAGE_SIZE;
}

void fillInWithZeros(float arr[], int elementsCount) {
    for (int i = 0; i < elementsCount; i++) {
        arr[i] = 0;
    }
}
