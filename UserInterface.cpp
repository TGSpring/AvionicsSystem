#include "UserInterface.h"
#include <iostream>
#include <fstream>

void UserInterface::displayMenu() const {
	std::cout << "=== Avioncs System Menu ===\n";
	std::cout << "1. Adjust Pitch\n";
	std::cout << "2. Adjust Roll\n";
	std::cout << "3. Adjust Yaw\n";
	std::cout << "4. Display Sensor Data\n";
	std::cout << "5. Exit\n";
	std::cout << "Choose an option: ";
}

void UserInterface::handleInput(FlightControl& fc, SensorSim& ss) {
	int choice;
	double angle;
	

	while (true) {
		displayMenu();
		std::cin >> choice;

		//Error handling

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid Input. Please enter a number.\n";
			continue;
		}

		switch (choice) {
		case 1:
			std::cout << "Enter pitch adjustment angle: ";
			std::cin >> angle;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid angle. Please enter a number.\n";
			}

			fc.adjustPitch(angle);
			logData(fc, ss);
			break;

		case 2:
			std::cout << "Enter roll adjustment angle: ";
			std::cin >> angle;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid angle. Please enter a number.\n";
				continue;
			}

			fc.adjustRoll(angle);
			logData(fc, ss);
			break;
		case 3:
			std::cout << "Enter yaw adjustment angle: ";
			std::cin >> angle;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid angle. Please enter a number.\n";
				continue;
			}

			fc.adjustYaw(angle);
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
			return;

		default:
			std::cout << "Invalid option. Please try again.\n";
		}
	}
}

void UserInterface::logData(const FlightControl& fc, const SensorSim& ss) const {
	std::ofstream logFile("flight_log.txt", std::ios::app);
	if (logFile.is_open()) {
		logFile << "Pitch: " << fc.getRollAngle() << " degrees\n";
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