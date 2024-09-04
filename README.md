# Avionics System Simulation

## Overview

The Avionics System Simulation project is designed to simulate avionics systems with real-time data integration. This branch, `real_data_attempt`, focuses on integrating real GPS data into the simulation.

## Current Features

- **Real-Time GPS Data Integration**: The project now fetches real GPS data using the Overpass API from OpenStreetMap.
- **Data Handling**: The system processes GPS data and updates the simulation accordingly.
- **File-Based Data Simulation**: In case of API issues, fallback to local file-based data retrieval.

## Setup

1. **Dependencies**:
   - [CURL](https://curl.se/)
   - [nlohmann/json](https://github.com/nlohmann/json)
   - [Python](https://www.python.org/) (for running the `fetch_gps_data.py` script)

2. **Configuration**:
   - Ensure that `curl` is installed and accessible.
   - The project uses `nlohmann/json` for JSON parsing. Ensure it's properly linked in your build system.
   - Update the API URL in the `GPSsim` class to the correct endpoint if needed.

3. **Building**:
   - Run the build command for your environment (e.g., `cmake` or `make`).

4. **Running**:
   - Ensure that `fetch_gps_data.py` is correctly placed in the project's root directory.
   - Execute the simulation program. The program will fetch and display real-time GPS data.

## Fetching GPS Data

The `fetch_gps_data.py` script is used to fetch real-time GPS data. Ensure that it is correctly configured to call the Overpass API and handle the response. The script writes data to `gps_data_json`, which the simulation then reads.

## Known Issues

- **API Data Handling**: If the API returns unexpected data, or if there's an issue with data retrieval, the system may not update correctly. Ensure the API is reachable and returning valid data.
- **Data Accuracy**: GPS data might not always be accurate depending on API responses and network conditions.

## Future Work

- **Enhance Data Validation**: Improve error handling and validation of GPS data.
- **Implement Additional Simulations**: Integrate weather data and other avionics components.
- **Testing**: Continue to develop and refine test cases for different scenarios.

## Contributing

If you'd like to contribute to the project, please fork the repository and create a pull request with your changes. Ensure that your code adheres to the project's style guidelines and includes appropriate tests.

## License

This project is licensed under the [MIT License](LICENSE).
