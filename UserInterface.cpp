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
    std::cout << "5. Exit\n";
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

void UserInterface::handleInput(FlightControl& fc, SensorSim& ss) {
    int choice = 0;

    while (true) {
        displayMenu();
        std::cin >> choice;

        // Input validation for menu choice
        if (std::cin.fail() || choice < 1 || choice > 5) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid option. Please try again.\n";
            continue;
        }

        switch (choice) {
        case 1:
            fc.adjustPitch(getValidAngle("Enter pitch adjustment angle: "));
            logData(fc, ss);
            break;
        case 2:
            fc.adjustRoll(getValidAngle("Enter roll adjustment angle: "));
            logData(fc, ss);
            break;
        case 3:
            fc.adjustYaw(getValidAngle("Enter yaw adjustment angle: "));
            logData(fc, ss);
            break;
        case 4:
            ss.updateSensor();
            std::cout << "Altitude: " << ss.getAltitude() << " ft\n";
            std::cout << "Airspeed: " << ss.getAirspeed() << " knots\n";
            std::cout << "Orientation: " << ss.getOrientation() << " degrees\n";
            std::cout << "Pitch: " << fc.getPitchAngle() << " degrees\n";
            std::cout << "Roll: " << fc.getRollAngle() << " degrees\n";
            std::cout << "Yaw: " << fc.getYawAngle() << " degrees\n";
            logData(fc, ss);
            break;
        case 5:
            return; // Exit the loop
        default:
            std::cout << "Invalid option. Please try again.\n";
        }
    }
}

void UserInterface::logData(const FlightControl& fc, const SensorSim& ss) const {
    std::ofstream logFile("flight_log.txt", std::ios::app);
    if (logFile.is_open()) {
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
