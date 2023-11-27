#pragma once
#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

class HumiditySensor {
private:
    int currentHumidity;

public:
    HumiditySensor();  // Constructor
    int getHumidity() const;
    void setHumidity(int humidity);
    void displayHumidity() const;
};

#endif // HUMIDITYSENSOR_H
