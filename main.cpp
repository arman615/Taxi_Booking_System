#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Taxi.h"
#include "User.h"
#include "Ride.h"

void registerTaxi(std::vector<Taxi>& taxis, const std::string& taxiNumber,
                  const std::string& driverName, const std::string& taxiClass) {
    Taxi newTaxi(taxiNumber, driverName, taxiClass);
    taxis.push_back(newTaxi);
    std::cout << "Taxi registered successfully.\n";
}

void registerUser(std::vector<User>& users, const std::string& name, const std::string& contactInfo) {
    User newUser(name, contactInfo);
    users.push_back(newUser);
    std::cout << "User registered successfully.\n";
}

bool isTaxiAvailable(const Taxi& taxi) {
    return taxi.getStatus() == "Available";
}

void bookTaxi(std::vector<Taxi>& taxis, std::vector<User>& users, std::vector<Ride>& rides,
              const std::string& taxiNumber, const std::string& userName, const std::string& userContactInfo,
              double distance) {
    Taxi* selectedTaxiPtr = nullptr;
    for (Taxi& taxi : taxis) {
        if (taxi.getTaxiNumber() == taxiNumber && isTaxiAvailable(taxi)) {
            selectedTaxiPtr = &taxi;
            break;
        }
    }
    if (selectedTaxiPtr == nullptr) {
        std::cout << "Invalid taxi selection or the taxi is already booked.\n";
        return;
    }

    User newUser(userName, userContactInfo);
    users.push_back(newUser);

    Ride newRide(*selectedTaxiPtr, newUser, distance);
    newRide.calculateFare();
    rides.push_back(newRide);

    selectedTaxiPtr->setStatus("Booked");
    std::cout << "Taxi booked successfully!\n";
}

void generateReceipt(const Ride& ride) {
    std::cout << "Receipt\n";
    std::cout << "Taxi Number: " << ride.getTaxi().getTaxiNumber() << std::endl;
    std::cout << "Driver Name: " << ride.getTaxi().getDriverName() << std::endl;
    std::cout << "User Name: " << ride.getUser().getName() << std::endl;
    std::cout << "Contact: " << ride.getUser().getContactInfo() << std::endl;
    std::cout << "Distance: " << ride.getDistance() << " km" << std::endl;
    std::cout << "Taxi Class: " << ride.getTaxi().getTaxiClass() << std::endl;
    std::cout << "Fare: $" << ride.getFare() << std::endl;
    std::cout << "-------------------------\n";
}

void saveReceiptToFile(const Ride& ride) {
    std::ofstream file("receipt.txt");
    if (file.is_open()) {
        file << "Receipt\n";
        file << "Taxi Number: " << ride.getTaxi().getTaxiNumber() << std::endl;
        file << "Driver Name: " << ride.getTaxi().getDriverName() << std::endl;
        file << "User Name: " << ride.getUser().getName() << std::endl;
        file << "Contact: " << ride.getUser().getContactInfo() << std::endl;
        file << "Distance: " << ride.getDistance() << " km" << std::endl;
        file << "Taxi Class: " << ride.getTaxi().getTaxiClass() << std::endl;
        file << "Fare: $" << ride.getFare() << std::endl;
        file << "-------------------------\n";
        file.close();
        std::cout << "Receipt saved to file successfully.\n";
    } else {
        std::cout << "Unable to save receipt to file.\n";
    }
}

int main() {
    std::vector<Taxi> taxis;
    std::vector<User> users;
    std::vector<Ride> rides;

    registerTaxi(taxis, "T001", "Hendo", "start");
    registerTaxi(taxis, "T002", "Vzgo", "comfort");
    registerTaxi(taxis, "T003", "Abo", "business");

    registerUser(users, "Arman", "arman@gmail.com");
    registerUser(users, "Gago", "gago@gmail.com");

    bookTaxi(taxis, users, rides, "T001", "Arman", "arman@gmail.com", 10.5);
    bookTaxi(taxis, users, rides, "T002", "Gago", "gago@gmail.com", 5.2);

    generateReceipt(rides[0]);
    generateReceipt(rides[1]);

    saveReceiptToFile(rides[0]);
    saveReceiptToFile(rides[1]);

    return 0;
}
