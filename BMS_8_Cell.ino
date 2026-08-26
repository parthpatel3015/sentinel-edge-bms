/*
   Modular BMS Engine
   8 cell test
*/

#define NUM_CELLS 8

struct BMSData {

  float cellVoltage[NUM_CELLS];

  int weakestCell;
  int strongestCell;

  float minimumVoltage;
  float maximumVoltage;
  float imbalance;

  float previousImbalance;
  float imbalanceChange;

  float soc;
  float adaptiveThreshold;

  bool imbalanceIncreasing;
  bool imbalanceDecreasing;
  bool imbalanceFault;
};

BMSData bms;


// --------------------------------------------------

float calculateSoC(float averageVoltage) {

  float soc = ((averageVoltage - 3.20) / 1.00) * 100.0;

  if (soc > 100.0)
    soc = 100.0;

  if (soc < 0.0)
    soc = 0.0;

  return soc;
}


// --------------------------------------------------

float calculateAdaptiveThreshold(float soc) {

  if (soc >= 80.0)
    return 0.10;

  else if (soc >= 50.0)
    return 0.12;

  else if (soc >= 20.0)
    return 0.15;

  else
    return 0.18;
}


// --------------------------------------------------

void analyzeBattery() {

  float totalVoltage = 0.0;

  bms.minimumVoltage = bms.cellVoltage[0];
  bms.maximumVoltage = bms.cellVoltage[0];

  bms.weakestCell = 0;
  bms.strongestCell = 0;


  for (int i = 0; i < NUM_CELLS; i++) {

    totalVoltage += bms.cellVoltage[i];


    if (bms.cellVoltage[i] < bms.minimumVoltage) {

      bms.minimumVoltage = bms.cellVoltage[i];
      bms.weakestCell = i;
    }


    if (bms.cellVoltage[i] > bms.maximumVoltage) {

      bms.maximumVoltage = bms.cellVoltage[i];
      bms.strongestCell = i;
    }
  }


  float averageVoltage = totalVoltage / NUM_CELLS;


  bms.soc = calculateSoC(averageVoltage);


  bms.imbalance =
      bms.maximumVoltage - bms.minimumVoltage;


  bms.imbalanceChange =
      bms.imbalance - bms.previousImbalance;


  if (bms.imbalanceChange > 0.005) {

    bms.imbalanceIncreasing = true;
    bms.imbalanceDecreasing = false;
  }

  else if (bms.imbalanceChange < -0.005) {

    bms.imbalanceIncreasing = false;
    bms.imbalanceDecreasing = true;
  }

  else {

    bms.imbalanceIncreasing = false;
    bms.imbalanceDecreasing = false;
  }


  bms.adaptiveThreshold =
      calculateAdaptiveThreshold(bms.soc);


  bms.imbalanceFault =
      bms.imbalance > bms.adaptiveThreshold;


  bms.previousImbalance =
      bms.imbalance;
}


// --------------------------------------------------

void printBMSData() {

  Serial.println();
  Serial.println("========================================");
  Serial.println("          8 CELL TEST");
  Serial.println("========================================");

  Serial.print("Configured cells: ");
  Serial.println(NUM_CELLS);

  Serial.println();


  for (int i = 0; i < NUM_CELLS; i++) {

    Serial.print("Cell ");
    Serial.print(i + 1);
    Serial.print(" : ");

    Serial.print(bms.cellVoltage[i], 3);

    Serial.println(" V");
  }


  Serial.println("........................................");


  Serial.print("Weakest Cell       : Cell ");
  Serial.println(bms.weakestCell + 1);


  Serial.print("Strongest Cell     : Cell ");
  Serial.println(bms.strongestCell + 1);


  Serial.print("Minimum Voltage    : ");
  Serial.print(bms.minimumVoltage, 3);
  Serial.println(" V");


  Serial.print("Maximum Voltage    : ");
  Serial.print(bms.maximumVoltage, 3);
  Serial.println(" V");


  Serial.print("Voltage Imbalance  : ");
  Serial.print(bms.imbalance, 3);
  Serial.println(" V");


  Serial.print("SoC                : ");
  Serial.print(bms.soc, 1);
  Serial.println(" %");


  Serial.print("Adaptive Threshold : ");
  Serial.print(bms.adaptiveThreshold, 3);
  Serial.println(" V");


  Serial.print("Imbalance Trend    : ");

  if (bms.imbalanceIncreasing)
    Serial.println("INCREASING");

  else if (bms.imbalanceDecreasing)
    Serial.println("DECREASING");

  else
    Serial.println("STABLE");


  Serial.print("Battery Status     : ");

  if (bms.imbalanceFault)
    Serial.println("IMBALANCE FAULT");

  else
    Serial.println("NORMAL");


  Serial.println("========================================");
}


// --------------------------------------------------

void setup() {

  Serial.begin(115200);

  delay(1000);


  Serial.println();
  Serial.println("========================================");
  Serial.println("          8 CELL TEST");
  Serial.println("========================================");

  Serial.print("Configured cells: ");
  Serial.println(NUM_CELLS);


  bms.cellVoltage[0] = 4.10;
  bms.cellVoltage[1] = 4.09;
  bms.cellVoltage[2] = 4.11;
  bms.cellVoltage[3] = 4.08;

  bms.cellVoltage[4] = 4.10;
  bms.cellVoltage[5] = 4.07;
  bms.cellVoltage[6] = 4.12;
  bms.cellVoltage[7] = 4.04;


  bms.previousImbalance = 0.0;


  analyzeBattery();

  printBMSData();
}


// --------------------------------------------------

void loop() {

  static unsigned long lastAnalysis = 0;

  unsigned long currentTime = millis();


  if (currentTime - lastAnalysis >= 1000) {

    lastAnalysis = currentTime;

    analyzeBattery();

    printBMSData();
  }
}