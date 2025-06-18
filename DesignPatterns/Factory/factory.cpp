#include "factory.h"

// ---------------- Sensor base ----------------
Sensor::Sensor(std::string name) : name(std::move(name)) {
    std::cout << "Sensor [" << this->name << "] created.\n";
}

Sensor::Sensor(const Sensor& other) : name(other.name) {
    std::cout << "Sensor [" << this->name << "] copied.\n";
}

Sensor::~Sensor() {
    std::cout << "Sensor [" << this->name << "] destroyed.\n";
}

std::ostream& operator<<(std::ostream& os, const Sensor& sensor) {
    os << "Sensor: " << sensor.name;
    return os;
}

// ---------------- TemperatureSensor ----------------
TemperatureSensor::TemperatureSensor(std::string name) : Sensor(std::move(name)) {}

TemperatureSensor::TemperatureSensor(const TemperatureSensor& other) : Sensor(other) {}

TemperatureSensor::~TemperatureSensor() {}

void TemperatureSensor::read() {
    std::cout << "[" << name << "] Reading temperature data...\n";
}

std::unique_ptr<Sensor> TemperatureSensor::clone() const {
    return std::make_unique<TemperatureSensor>(*this);
}

// ---------------- PressureSensor ----------------
PressureSensor::PressureSensor(std::string name) : Sensor(std::move(name)) {}

PressureSensor::PressureSensor(const PressureSensor& other) : Sensor(other) {}

PressureSensor::~PressureSensor() {}

void PressureSensor::read() {
    std::cout << "[" << name << "] Reading pressure data...\n";
}

std::unique_ptr<Sensor> PressureSensor::clone() const {
    return std::make_unique<PressureSensor>(*this);
}

// ---------------- HumiditySensor ----------------
HumiditySensor::HumiditySensor(std::string name) : Sensor(std::move(name)) {}

HumiditySensor::HumiditySensor(const HumiditySensor& other) : Sensor(other) {}

HumiditySensor::~HumiditySensor() {}

void HumiditySensor::read() {
    std::cout << "[" << name << "] Reading humidity data...\n";
}

std::unique_ptr<Sensor> HumiditySensor::clone() const {
    return std::make_unique<HumiditySensor>(*this);
}

// ---------------- SensorFactory ----------------
std::unique_ptr<Sensor> SensorFactory::createSensor(const std::string& type, const std::string& name) {
    if (type == "temperature") {
        return std::make_unique<TemperatureSensor>(name);
    } else if (type == "pressure") {
        return std::make_unique<PressureSensor>(name);
    } else if (type == "humidity") {
        return std::make_unique<HumiditySensor>(name);
    } else {
        std::cerr << "Unknown sensor type: " << type << std::endl;
        return nullptr;
    }
}
