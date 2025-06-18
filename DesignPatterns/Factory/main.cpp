#include "factory.h"
#include <vector>

int main() {
    std::vector<std::unique_ptr<Sensor>> sensors;

    sensors.push_back(SensorFactory::createSensor("temperature", "TempSensor01"));
    sensors.push_back(SensorFactory::createSensor("pressure", "PressureSensor01"));
    sensors.push_back(SensorFactory::createSensor("humidity", "HumiditySensor01"));

    std::cout << "\n-- Reading all sensors --\n";
    for (const auto& sensor : sensors) {
        sensor->read();
        std::cout << *sensor << std::endl;
    }

    std::cout << "\n-- Cloning a sensor --\n";
    auto cloned = sensors[0]->clone();
    cloned->read();
    std::cout << *cloned << std::endl;

    std::cout << "\n-- End of main --\n";
    return 0;
}
