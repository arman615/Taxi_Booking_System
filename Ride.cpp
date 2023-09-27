#include "Ride.h"

Ride::Ride(const Taxi& taxi, const User& user, double distance)
    : taxi(taxi), user(user), distance(distance), fare(0) {}

const Taxi& Ride::getTaxi() const {
    return taxi;
}

const User& Ride::getUser() const {
    return user;
}

double Ride::getDistance() const {
    return distance;
}

double Ride::getFare() const {
    return fare;
}

void Ride::calculateFare() {
    if (taxi.getTaxiClass() == "start") {
        fare = distance * 1.0;
    } else if (taxi.getTaxiClass() == "comfort") {
        fare = distance * 1.8;
    } else if (taxi.getTaxiClass() == "business") {
        fare = distance * 3.0;
    }
}
