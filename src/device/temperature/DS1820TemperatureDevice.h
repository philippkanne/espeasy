/*
 * DS1820TemperatureDevice.h
 *
 *  Created on: Feb 28, 2017
 *      Author: philipp
 */

#ifndef SRC_DEVICE_TEMPERATURE_DS1820TEMPERATUREDEVICE_H_
#define SRC_DEVICE_TEMPERATURE_DS1820TEMPERATUREDEVICE_H_

#include <device/temperature/TemperatureDevice.h>
#include <DallasTemperature.h>

class DS1820TemperatureDevice: public TemperatureDevice {
public:
	DS1820TemperatureDevice(String id = "Unknown", String name = "Unknown",
			int pin = -1, int port = -1) :
			TemperatureDevice(id, name), _pin(pin), _port(port) {
	}
	;

	virtual ~DS1820TemperatureDevice();

	virtual void boot();
	virtual float getTemperature();
	virtual String toString();

private:
	int _pin;
	int _port;

	OneWire _oneWire = OneWire(_pin);
	DallasTemperature _sensors;
	DeviceAddress _address;

};

#endif /* SRC_DEVICE_TEMPERATURE_DS1820TEMPERATUREDEVICE_H_ */
