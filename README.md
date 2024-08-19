# Avionics System

## Overview

This project simulates an avionics system and includes features for managing flight controls, sensor data, GPS data, and weather information. The `ML_Attempt` branch specifically incorporates machine learning features for analyzing flight data.

## Features

### Main Branch
- **Flight Control Management**: Adjust pitch, roll, and yaw of the aircraft.
- **Sensor Data**: Display altitude, airspeed, and orientation from sensors.
- **GPS Data**: Retrieve and display GPS coordinates and altitude.
- **Weather Data**: Show temperature, humidity, and wind speed from weather sensors.

### ML_Attempt Branch
- **Machine Learning Integration**:
  - **Data Logging**: Collects flight data into `flight_log.txt`.
  - **Model Training**: Uses linear regression to analyze flight data.
  - **Visualization**: Generates plots of actual vs. predicted values from the ML model.
  - **Results Export**: Saves ML model predictions to `results.csv`.

## Requirements

- Python 3.x
- pandas
- scikit-learn
- matplotlib

## Usage
   - 1. Build and Run: Compile the code and execute the program. Navigate through the menu to use the different features.
   - 2. Run ML Analysis:
        - Ensuse "Flight_log.txt" contains data to be analyzed.
## Testing
- **Testing is an important part of the development process to ensure that all features are functioning correctly and the ML model performs as expected. The testing phase includes**:

- **Unit Testing**: Testing individual functions and methods to ensure they work as intended. This involves verifying that each component of the system, such as the ML data processing and model training functions, behaves correctly in isolation.
- **Integration Testing**: Ensuring that different parts of the system work together seamlessly. This involves testing the interactions between the user interface, data logging, and machine learning components to ensure that they function together without issues.
- **ML Model Evaluation**: Evaluating the performance of the machine learning model using different datasets and metrics. This will help in understanding how well the model generalizes to unseen data and its overall accuracy.

- Note: Testing is the next phase and is not fully implemented yet. As development progresses, more detailed testing will be added to ensure the reliability and robustness of the system.
## Installation

1. Clone the repository:

   ```sh
   git clone https://github.com/your-username/AvionicsSystem.git
   cd AvionicsSystem
