# Sentinel Edge BMS

An ESP32-based modular Battery Management System (BMS) simulation developed using Wokwi.

## 1. Project Overview

This project focuses on monitoring individual battery cell voltages and analyzing the condition of a battery pack.

The BMS program analyzes cell voltage values and calculates important parameters such as:

- Weakest cell
- Strongest cell
- Minimum cell voltage
- Maximum cell voltage
- Voltage imbalance
- State of Charge (SoC)
- Adaptive imbalance threshold
- Imbalance trend
- Battery status

The system was tested with 4-cell, 8-cell, and 16-cell battery configurations to check the scalability of the BMS analysis logic.

## 2. Main Features

- Individual cell voltage monitoring
- Weakest and strongest cell identification
- Minimum and maximum voltage calculation
- Voltage imbalance calculation
- State of Charge estimation
- Adaptive imbalance threshold
- Imbalance trend detection
- Imbalance fault detection
- Scalable cell configuration
- Serial Monitor based output

## 3. Configurations Tested

### 4-Cell Configuration

The 4-cell BMS was tested using automated test Steps 0 to 6.

Different voltage conditions were used to observe balanced operation, increasing imbalance, decreasing imbalance, and normal recovery conditions.

### 8-Cell Configuration

The BMS was configured for eight cells using:

#define NUM_CELLS 8

The program successfully analyzed all eight cell voltages and identified the weakest and strongest cells.

### 16-Cell Configuration

The BMS was further configured for sixteen cells using:

#define NUM_CELLS 16

The same analysis logic was used to process all sixteen cells.

## 4. BMS Analysis

During each analysis cycle, the program:

1. Processes the configured cell voltages.
2. Identifies the weakest cell.
3. Identifies the strongest cell.
4. Finds the minimum and maximum cell voltage.
5. Calculates voltage imbalance.
6. Estimates the State of Charge (SoC).
7. Calculates the adaptive imbalance threshold.
8. Determines the imbalance trend.
9. Determines the battery status.

## 5. Voltage Imbalance

Voltage imbalance is calculated as the difference between the highest and lowest cell voltage.

Voltage Imbalance = Maximum Cell Voltage - Minimum Cell Voltage

The calculated imbalance is compared with the adaptive threshold to determine whether an imbalance fault exists.

## 6. State of Charge

The project uses the average cell voltage to estimate the battery State of Charge.

The estimated value is limited between 0% and 100%.

## 7. Adaptive Threshold

The imbalance threshold changes according to the estimated State of Charge.

| State of Charge | Adaptive Threshold |
|-----------------|-------------------|
| 80% and above   | 0.10 V |
| 50% - 79%       | 0.12 V |
| 20% - 49%       | 0.15 V |
| Below 20%       | 0.18 V |

## 8. Imbalance Trend

The program compares the current imbalance with the previous imbalance.

The trend is classified as:

- INCREASING
- DECREASING
- STABLE

This helps observe how the voltage difference between cells changes during testing.

## 9. Battery Status

The battery status is determined by comparing the calculated voltage imbalance with the adaptive threshold.

If the imbalance is greater than the threshold:

Battery Status: IMBALANCE FAULT

Otherwise:

Battery Status: NORMAL

## 10. Project Files

### 4-Cell BMS

BMS_4_Cell.ino

Contains the 4-cell BMS test with automated test Steps 0 to 6.

### 8-Cell BMS

BMS_8_Cell.ino

Contains the BMS analysis configured for an 8-cell battery pack.

### 16-Cell BMS

BMS_16_Cell.ino

Contains the BMS analysis configured for a 16-cell battery pack.

## 11. Wokwi Simulation Links

The three BMS configurations were implemented and tested using the Wokwi ESP32 simulator.

### 4-Cell BMS

https://wokwi.com/projects/473443955738040321

### 8-Cell BMS

https://wokwi.com/projects/473444401209904129

### 16-Cell BMS

https://wokwi.com/projects/473444531568904193

## 12. Development Platform

- ESP32
- Wokwi Simulator
- Arduino/C++
- Serial Monitor

## 13. Testing

The BMS was tested using simulated cell voltage values.

The 4-cell configuration was tested through Steps 0 to 6 to observe different imbalance conditions.

The 8-cell and 16-cell configurations were then tested to verify that the same BMS analysis structure could be extended to larger battery configurations.

The results were observed through the Serial Monitor.

## 14. Scalability

The project was designed so that the number of battery cells can be changed using the NUM_CELLS configuration.

The same core analysis functions were reused for:

- 4 cells
- 8 cells
- 16 cells

This demonstrates that the BMS software structure can be extended to different battery pack sizes without rewriting the complete analysis logic.

## 15. Project Objective

The objective of this project is to develop a modular BMS analysis system capable of monitoring individual cell voltages, identifying voltage imbalance, estimating battery State of Charge, and detecting possible imbalance faults.

## 16. Author

Parth Patel
