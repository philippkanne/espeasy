/*
 * INode.h
 *
 *  Created on: Feb 28, 2017
 *      Author: philipp
 */

#ifndef SRC_DEVICE_NODE_NODE_H_
#define SRC_DEVICE_NODE_NODE_H_

#include <device/Device.h>
#include <device/DeviceController.h>
#include <configuration/WifiProvider.h>

#include <vector>

class Node: public Device {
public:
	Node();
	virtual ~Node();
	virtual String toString();
	virtual void boot();

	virtual void loop();
	void addDevice(DeviceController* newOne);

private:
	std::vector<DeviceController*> _devices;
	WifiProvider _wifi;
};

#endif /* SRC_DEVICE_NODE_NODE_H_ */
