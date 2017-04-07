/*
 * DeviceController.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: philipp
 */

#include <device/DeviceController.h>
#include <event/Event.h>

DeviceController::~DeviceController() {
	// TODO Auto-generated destructor stub
}

void DeviceController::loop() {
	if (_timer != NULL) {
		if (_timer->check()) {


			Event* e = new Event();
			_timerHandler(e, _device);
		}
	}
}

void DeviceController::setEndpoint(String endpoint) {

}

void DeviceController::subscribeTo(String topic) {

}


