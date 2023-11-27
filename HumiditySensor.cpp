#include "HumiditySensor.h"
#include <iostream>

HumiditySensor::HumiditySensor() : currentHumidity(0) {}

int HumiditySensor::getHumidity() const {
    return currentHumidity;
}

void HumiditySensor::setHumidity(int humidity) {
    currentHumidity = humidity;
}

void HumiditySensor::displayHumidity() const {
    std::cout << "Current humidity: " << currentHumidity << "%" << std::endl;
   
}
