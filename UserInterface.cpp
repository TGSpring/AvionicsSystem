#include "UserInterface.h"
#include <iostream>
#include <fstream>
#include <limits>

void UserInterface::displayMenu() const {
    std::cout << "=== Avionics System Menu ===\n";
    std::cout << "1. Adjust Pitch\n";
    std::cout << "2. Adjust Roll\n";
    std::cout << "3. Adjust Yaw\n";
    std::cout << "4. Display Sensor Data\n";
    std::cout << "5. Display GPS Data\n";
    std::cout << "6. Display Weather Data\n";
    std::cout << "7. Exit\n";
    std::cout << "Choose an option: ";
}

double UserInterface::getValidAngle(const std::string& prompt) const {
    double angle;
    while (true) {
        std::cout << prompt;
        if (std::cin >> angle) {
            return angle;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid angle. Please enter a valid number.\n";
        }
    }
}

void UserInterface::handleInput(FlightControl& fc, SensorSim& ss, GPSsim& gps, WeatherSim& weather) {
    int choice = 0;

    while (true) {
        displayMenu();
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > 7) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid option. Please try again.\n";
            continue;
        }

        switch (choice) {
        case 1:
            fc.adjustPitch(getValidAngle("Enter pitch adjustment angle: "));
            logData(fc, ss, "Pitch"); // Log type example
            break;

        case 2:
            fc.adjustRoll(getValidAngle("Enter roll adjustment angle: "));
            logData(fc, ss, "Roll"); // Log type example
            break;

        case 3:
            fc.adjustYaw(getValidAngle("Enter yaw adjustment angle: "));
            logData(fc, ss, "Yaw"); // Log type example
            break;

        case 4:
            ss.updateSensor();
            std::cout << "Altitude: " << ss.getAltitude() << " ft\n";
            std::cout << "Airspeed: " << ss.getAirspeed() << " knots\n";
            std::cout << "Orientation: " << ss.getOrientation() << " degrees\n";
            std::cout << "Pitch: " << fc.getPitchAngle() << " degrees\n";
            std::cout << "Roll: " << fc.getRollAngle() << " degrees\n";
            std::cout << "Yaw: " << fc.getYawAngle() << " degrees\n";
            logData(fc, ss, "Sensor Data"); // Log type example
            break;

        case 5:
            displayGPSData(gps);
            break;
        case 6:
            displayWeatherData(weather);
            break;
        case 7:
            return;

        default:
            std::cout << "Invalid option. Please try again.\n";
        }
    }
}

void UserInterface::logData(const FlightControl& fc, const SensorSim& ss, const std::string& logType) const {
    std::ofstream logFile("flight_log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << "Log Type: " << logType << "\n";
        logFile << "Pitch: " << fc.getPitchAngle() << " degrees\n";
        logFile << "Roll: " << fc.getRollAngle() << " degrees\n";
        logFile << "Yaw: " << fc.getYawAngle() << " degrees\n";
        logFile << "Altitude: " << ss.getAltitude() << " ft\n";
        logFile << "Airspeed: " << ss.getAirspeed() << " knots\n";
        logFile << "Orientation: " << ss.getOrientation() << " degrees\n";
        logFile << "-------------------------\n";
        logFile.close();
    }
    else {
        std::cerr << "Unable to open log file\n";
    }
}

void UserInterface::displayGPSData(const GPSsim& gps) const {
    GPSdata data = gps.getCurrentData();
    std::cout << "GPS Data:\n";
    std::cout << "Latitude: " << data.latitude << "\n";
    std::cout << "Longitude: " << data.longitude << "\n";
    std::cout << "Altitude: " << data.altitude << " feet\n";
}

void UserInterface::displayWeatherData(const WeatherSim& weather) const {
    WeatherData data = weather.getCurrentData();
    std::cout << "Temperature: " << data.temperature << "C" << "\n";
    std::cout << "Humidity: " << data.humidity << "%" << "\n";
    std::cout << "Wind Speed: " << data.windSpeed << " m/s" "\n";

}