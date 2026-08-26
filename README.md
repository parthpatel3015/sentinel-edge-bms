# Sentinel Edge BMS

An ESP32-based modular Battery Management System (BMS) simulation developed using Wokwi.

## Project Overview

This project focuses on monitoring battery cell voltages and analyzing the condition of a battery pack. The BMS program checks individual cell voltages and calculates important battery parameters such as voltage imbalance, State of Charge (SoC), adaptive threshold, imbalance trend, and battery status.

The design was tested with different battery pack sizes to check whether the same analysis logic can be used for different numbers of cells.

## Main Features

- Individual cell voltage monitoring
- Weakest cell identification
- Strongest cell identification
- Minimum and maximum cell voltage calculation
- Voltage imbalance calculation
- State of Charge (SoC) estimation
- Adaptive imbalance threshold
- Imbalance trend detection
- Imbalance fault detection
- Support for different cell configurations
- Serial Monitor based result display

## Configurations Tested

The BMS logic was tested with:

- 4-cell battery configuration
- 8-cell battery configuration
- 16-cell battery configuration

The 4-cell configuration was tested through multiple test steps from Step 0 to Step 6 to observe different imbalance conditions.

## BMS Analysis

For every analysis cycle, the program:

1. Reads the configured cell voltages.
2. Finds the weakest and strongest cells.
3. Calculates the minimum and maximum voltage.
4. Calculates the voltage imbalance.
5. Estimates the battery State of Charge.
6. Calculates an adaptive imbalance threshold.
7. Checks whether the imbalance is increasing, decreasing, or stable.
8. Determines whether the battery condition is normal or an imbalance fault.

## Adaptive Threshold

The imbalance threshold changes according to the estimated State of Charge.

| State of Charge | Adaptive Threshold |
|-----------------|-------------------|
| 80% and above   | 0.10 V |
| 50% – 79%       | 0.12 V |
| 20% – 49%       | 0.15 V |
| Below 20%       | 0.18 V |

## Project Files

### 4-Cell BMS

`BMS_4_Cell.ino`

Contains the 4-cell BMS test with automated test steps from Step 0 to Step 6.

### 8-Cell BMS

`BMS_8_Cell.ino`

Contains the BMS analysis configured for an 8-cell battery pack.

### 16-Cell BMS

`BMS_16_Cell.ino`

Contains the BMS analysis configured for a 16-cell battery pack.

## Development Platform

- ESP32
- Wokwi Simulator
- Arduino/C++
- Serial Monitor

## Testing

The system was tested using simulated cell-voltage values. The test results were observed through the Serial Monitor.

The 4-cell test included different voltage conditions to observe changes in imbalance and battery status. The 8-cell and 16-cell versions were then used to demonstrate that the BMS analysis can be extended to larger battery configurations.

## Project Objective

The main objective of this project is to develop a modular BMS analysis system that can monitor individual cell voltages and identify possible imbalance conditions while maintaining a scalable software structure.

## Author

Parth Patel
