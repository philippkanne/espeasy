/*
 * TemperatureDevice.h
 *
 *  Created on: Feb 28, 2017
 *      Author: philipp
 */

#ifndef SRC_DEVICE_TEMPERATURE_TEMPERATUREDEVICE_H_
#define SRC_DEVICE_TEMPERATURE_TEMPERATUREDEVICE_H_

#include <device/Device.h>

class TemperatureDevice: public Device {
public:
	TemperatureDevice(String id = "Unknown", String name = "Unknown") :
			Device(id, name) {
	}
	;
	virtual ~TemperatureDevice();

	virtual float getTemperature();

};

#endif /* SRC_DEVICE_TEMPERATURE_TEMPERATUREDEVICE_H_ */
