/*
 * Main.cpp
 *
 *  Created on: Feb 10, 2017
 *      Author: philipp
 */
#include <device/node/Node.h>
#include "Arduino.h"
#include <logging/Logger.h>
#include <device/temperature/DS1820TemperatureDevice.h>
#include <device/DeviceController.h>
#include <device/Device.h>
#include <event/Event.h>

Node* node = new Node();
TemperatureDevice* temp = new DS1820TemperatureDevice("1", "DS1820", 2, 0);
DeviceController* tempCtrl = new DeviceController(temp);

void printTemp(Event* e, Device* d) {
	// Logger::instance().debug(d->toString());

	TemperatureDevice* d2 = static_cast<TemperatureDevice*>(d);
	float temp = d2->getTemperature();
	Logger::instance().debug(String(temp));

}

void setup() {
	Serial.begin(9600);
	Logger::instance().setLogLevel(DEBUG);

	Timer* t = new Timer();

	tempCtrl->setTimer(t);
	tempCtrl->onTimer(printTemp);

	node->addDevice(tempCtrl);
	node->boot();
}

void loop() {
	node->loop();
}

