#ifndef RIDE_H
#define RIDE_H

#include "Taxi.h"
#include "User.h"

class Ride {
private:
    Taxi taxi;
    User user;
    double distance;
    double fare;

public:
    Ride(const Taxi& taxi, const User& user, double distance);
    const Taxi& getTaxi() const;
    const User& getUser() const;
    double getDistance() const;
    double getFare() const;
    void calculateFare();
};

#endif
