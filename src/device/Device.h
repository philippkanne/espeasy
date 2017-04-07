/*
 * Device.h
 *
 *  Created on: Feb 10, 2017
 *      Author: philipp
 */

#ifndef SRC_DEVICE_DEVICE_H_
#define SRC_DEVICE_DEVICE_H_

#include "Arduino.h"

class Device {
public:
	Device(String id = String("unknown"), String name = String("unknown")) :
			_id(id), _name(name) {
	}
	;
	virtual ~Device();

	const String getName() const {
		return _name;
	}

	const String getId() const {
		return _id;
	}

	virtual String toString();
	virtual void boot();

private:
	String _name;
	String _id;

};

#endif /* SRC_DEVICE_DEVICE_H_ */
