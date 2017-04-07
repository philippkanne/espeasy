/*
 * DeviceController.h
 *
 *  Created on: Feb 28, 2017
 *      Author: philipp
 */

#ifndef SRC_DEVICE_DEVICECONTROLLER_H_
#define SRC_DEVICE_DEVICECONTROLLER_H_

#include "Device.h"
#include <timer/Timer.h>
#include <event/EventCallback.h>

class DeviceController {
public:
	DeviceController(Device* device) :
			_device(device) {
	}
	;

	virtual ~DeviceController();

	const void boot() {
		_device->boot();
	}

	void loop();

	const DeviceController* setTimer(Timer* timer) {
		_timer = timer;

		return this;
	}

	void setEndpoint(String endpoint);
	void subscribeTo(String topic);

	const DeviceController* onMessage(EventHandler handler) {
		_messageHandler = handler;

		return this;
	}

	const DeviceController* onTimer(EventHandler handler) {
		_timerHandler = handler;

		return this;
	}

	Device* getDevice() {
		return _device;
	}

private:
	Device* _device;
	Timer* _timer;

	EventHandler _timerHandler;
	EventHandler _messageHandler;
};

#endif /* SRC_DEVICE_DEVICECONTROLLER_H_ */
