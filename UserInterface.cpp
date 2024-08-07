#include "UserInterface.h"
#include <iostream>

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

		switch (choice) {
		case 1:
			std::cout << "Enter pitch adjustment angle: ";
			std::cin >> angle;
			fc.adjustPitch(angle);
			break;
		case 2:
			std::cout << "Enter roll adjustment angle: ";
			std::cin >> angle;
			fc.adjustRoll(angle);
			break;
		case 3:
			std::cout << "Enter yaw adjustment angle: ";
			std::cin >> angle;
			fc.adjustYaw(angle);
			break;
		case 4:
			ss.updateSensor();
			std::cout << "Altitude: " << ss.getAltitude() << " ft\n";
			std::cout << "Airspeed: " << ss.getAirspeed() << " knots\n";
			std::cout << "Orientation: " << ss.getOrientation() << " degrees\n";
			std::cout << "Pitch: " << fc.getPitchAngle() << " degrees\n";
			std::cout << "Roll: " << fc.getRollAngle() << " degrees\n";
			std::cout << "Yaw: " << fc.getYawAngle() << " degrees\n";
			break;
		case 5:
			return;

		default:
			std::cout << "Invalid option. Please try again.\n";
		}
	}
}