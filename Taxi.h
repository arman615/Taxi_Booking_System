#ifndef TAXI_H
#define TAXI_H

#include <string>

class Taxi {
private:
    std::string taxiNumber;
    std::string driverName;
    std::string status;
    std::string taxiClass;

public:
    Taxi(const std::string& taxiNumber, const std::string& driverName, const std::string& taxiClass);
    const std::string& getTaxiNumber() const;
    const std::string& getDriverName() const;
    const std::string& getStatus() const;
    void setStatus(const std::string& status);
    const std::string& getTaxiClass() const;
};

#endif //TAXI_H
