#pragma once

#ifndef WINDSENSOR_H
#define WINDSENSOR_H

class WindSensor {
private:
    float currentWindSpeed; //data member to hold current wind speed

public:
    WindSensor();  // Constructor
    float getWindSpeed() const;
    void setWindSpeed(float windSpeed);
    void displayWindSpeed() const;
};

#endif // WINDSENSOR_H
