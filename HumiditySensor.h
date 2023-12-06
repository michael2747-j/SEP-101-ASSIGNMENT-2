#pragma once
#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

class HumiditySensor {
private:
    int currentHumidity;  //data member to hold current humidity 

public:
    HumiditySensor();  // Constructor
    int getHumidity() const;
    void setHumidity(int humidity);
    void displayHumidity() const;
};

#endif // HUMIDITYSENSOR_H
