/*
 * DS1820TemperatureDevice.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: philipp
 */

#include <device/temperature/DS1820TemperatureDevice.h>
#include <logging/Logger.h>

DS1820TemperatureDevice::~DS1820TemperatureDevice() {
	// TODO Auto-generated destructor stub
}

void DS1820TemperatureDevice::boot() {
	Logger::instance().debug(toString() + String("booting device"));

	_oneWire = OneWire(_pin);
	_sensors = DallasTemperature(&_oneWire);
	_sensors.begin();

	delay(100);

	Logger::instance().debug(
			toString() + String("Found ")
					+ String(_sensors.getDeviceCount(), DEC) + " sensors.");

	if (!_sensors.getAddress(_address, _port)) {
		Logger::instance().error(
				toString() + String("Unable to find address for Device ")
						+ String(_port, DEC));
	} else {
		_sensors.setResolution(TEMP_12_BIT);
		Logger::instance().debug(
				toString() + String("Resolution is ")
						+ String(_sensors.getResolution(_address), DEC)
						+ String("bit"));
	}
}

float DS1820TemperatureDevice::getTemperature() {
	_sensors.requestTemperaturesByAddress(_address);
	float temp = _sensors.getTempC(_address);
	Logger::instance().debug(toString() + String(temp, DEC) + String(" °C"));
	return temp;
}

String DS1820TemperatureDevice::toString() {
	return String("[DS1820TemperatureDevice ") + getId() + String(", port=")
			+ String(_port) + String(", pin=") + String(_pin, DEC)
			+ String("] ");
}

