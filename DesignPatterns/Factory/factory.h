#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <memory>
#include <string>

// Sensor base class
class Sensor {
public:
    Sensor(std::string name);
    Sensor(const Sensor& other);
    virtual ~Sensor();

    virtual void read() = 0;
    virtual std::unique_ptr<Sensor> clone() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Sensor& sensor);

protected:
    std::string name;
};

// Concrete Sensor: Temperature
class TemperatureSensor : public Sensor {
public:
    TemperatureSensor(std::string name);
    TemperatureSensor(const TemperatureSensor& other);
    ~TemperatureSensor();

    void read() override;
    std::unique_ptr<Sensor> clone() const override;
};

// Concrete Sensor: Pressure
class PressureSensor : public Sensor {
public:
    PressureSensor(std::string name);
    PressureSensor(const PressureSensor& other);
    ~PressureSensor();

    void read() override;
    std::unique_ptr<Sensor> clone() const override;
};

// Concrete Sensor: Humidity
class HumiditySensor : public Sensor {
public:
    HumiditySensor(std::string name);
    HumiditySensor(const HumiditySensor& other);
    ~HumiditySensor();

    void read() override;
    std::unique_ptr<Sensor> clone() const override;
};

// Factory Class
class SensorFactory {
public:
    static std::unique_ptr<Sensor> createSensor(const std::string& type, const std::string& name);
};

#endif // FACTORY_H
