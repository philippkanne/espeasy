/*
 * INode.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: philipp
 */

#include <device/node/Node.h>
#include <device/DeviceController.h>
#include <logging/Logger.h>

Node::Node() {
	// TODO Auto-generated constructor stub

}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

String Node::toString() {
	return String("Anode");
}

void Node::boot() {
	for (auto const& device : _devices) {
		device->boot();
		delay(10);
	}
}

void Node::loop() {

	_wifi.connect();
	delay(1000);

	for (auto const& device : _devices) {
		device->loop();
		delay(10);
	}

}

void Node::addDevice(DeviceController* newOne) {
	Logger::instance().debug(
			String("Added ") + newOne->getDevice()->toString()
					+ String(" to node"));
	_devices.push_back(newOne);
}
