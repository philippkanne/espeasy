/*
 * Configuration.h
 *
 *  Created on: Mar 14, 2017
 *      Author: philipp
 */
#pragma once

#ifndef SRC_DEVICE_NODE_CONFIGURATION_H_
#define SRC_DEVICE_NODE_CONFIGURATION_H_

#include <IPAddress.h>

class Configuration {
public:
	Configuration();
	virtual ~Configuration();

	const IPAddress getIpAdress() {
		return IPAddress(192, 168, 178, 10);
	}

	const IPAddress getIpGateWay() {
		return IPAddress(192, 168, 178, 1);
	}

	const IPAddress getIpSubnet() {
		return IPAddress(255, 255, 255, 0);
	}

	const bool useDHCP() {
		return false;
	}

	const char* getWifiSSID() {
		return "mares.fb";
	}

	const char* getWifiPassword() {
		return "****";
	}

	const IPAddress getMQTTBroker() {
		return IPAddress(192, 168, 178, 4);
	}

	const char* getNodeName() {
		return "esp8266";
	}

};

#endif /* SRC_DEVICE_NODE_CONFIGURATION_H_ */
