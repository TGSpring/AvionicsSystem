# Avionics System

## Overview

The Avionics System is a comprehensive project aimed at simulating and analyzing various avionics data, including pitch, roll, yaw, sensor data, GPS data, and weather data. The system also integrates machine learning (ML) to analyze the collected data and predict trends.

## Branches

- **Main Branch**: Contains the core functionality of the avionics system without ML features.
- **ML_Attempt Branch**: Includes machine learning features to analyze and predict based on data.

## Features

- **Adjust Pitch, Roll, and Yaw**: Modify the aircraft's orientation.
- **Display Sensor, GPS, and Weather Data**: Show real-time data from various sources.
- **Run ML Analysis**: Apply machine learning to analyze historical data and predict trends.

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/AvionicsSystem.git
    ```
2. Navigate to the project directory:
    ```bash
    cd AvionicsSystem
    ```
3. Install required Python packages:
    ```bash
    pip install -r requirements.txt
    ```

## Usage

1. **Run the Application**:
    - Compile and run the C++ application to start the avionics system interface.
    - Use the menu to adjust settings, display data, or run ML analysis.

2. **Run ML Analysis**:
    - The ML model uses data from `flight_log.txt`.
    - Execute the ML analysis through the application menu option or manually run:
      ```bash
      python run_ml_model.py flight_log.txt results.csv
      ```

## Data Collection

Data collection is planned for future updates. The current system logs data to `flight_log.txt` which is used for ML analysis. This will include:
- **Sensor Data**: Altitude, airspeed, orientation.
- **GPS Data**: Latitude, longitude, altitude.
- **Weather Data**: Temperature, humidity, wind speed.

## Testing

Testing is the next phase and is not fully implemented yet. The plan includes:
- **Unit Testing**: Verify individual components (e.g., data preprocessing, ML model).
- **Integration Testing**: Ensure that the system components work together correctly.
- **End-to-End Testing**: Validate the entire workflow from data entry to ML analysis.

## Future Updates

1. **Enhanced Data Collection**: Implement advanced methods for collecting and logging data.
2. **Improved Testing**: Add comprehensive testing strategies to ensure system reliability and accuracy.

## Requirements

- Python 3.x
- Pandas
- Scikit-learn
- Matplotlib

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your changes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

