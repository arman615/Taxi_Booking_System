#include "Taxi.h"

Taxi::Taxi(const std::string& taxiNumber, const std::string& driverName, const std::string& taxiClass)
    : taxiNumber(taxiNumber), driverName(driverName), status("Available"), taxiClass(taxiClass) {}

const std::string& Taxi::getTaxiNumber() const {
    return taxiNumber;
}

const std::string& Taxi::getDriverName() const {
    return driverName;
}

const std::string& Taxi::getStatus() const {
    return status;
}

void Taxi::setStatus(const std::string& status) {
    this->status = status;
}

const std::string& Taxi::getTaxiClass() const {
    return taxiClass;
}

