#pragma once
#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

class TemperatureSensor {
private:
    float currentTemperature;  //data member to hold current temperature

public:
    TemperatureSensor();  // Constructor
    float getTemperature() const;
    void setTemperature(float temperature);
    void displayTemperature() const;
};

#endif // TEMPERATURESENSOR_H
