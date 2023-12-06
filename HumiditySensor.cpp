#include "HumiditySensor.h"
#include <iostream>

//constructor initializing currentHumidity to zero
HumiditySensor::HumiditySensor() : currentHumidity(0) {}

//Getter method to retrieve the current humidity value
int HumiditySensor::getHumidity() const {
    return currentHumidity;
}

//setter method to set the current humidity value 
void HumiditySensor::setHumidity(int humidity) {
    currentHumidity = humidity;
}

//method to display the current humidity value
void HumiditySensor::displayHumidity() const {
    std::cout << "Current humidity: " << currentHumidity << "%" << std::endl;

}
