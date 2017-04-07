/*
 * WifiProvider.cpp
 *
 *  Created on: Mar 14, 2017
 *      Author: philipp
 */

#include <configuration/WifiProvider.h>
#include <configuration/Configuration.h>
#include <configuration/ConfigurationProvider.h>
#include <logging/Logger.h>

#include <ESP8266WiFi.h>

WifiProvider::WifiProvider() {

	WiFi.persistent(false);
	WiFi.mode(WIFI_STA);
	WiFi.disconnect();
}

WifiProvider::~WifiProvider() {
	// TODO Auto-generated destructor stub
}

void WifiProvider::connect() {
	if (!WiFi.isConnected()) {
		Logger::instance().debug(String("WifiProvider: Wifi is not connected"));
		Configuration* conf =
				ConfigurationProvider::instance().getConfiguration();
		if (!conf->useDHCP()) {
			Logger::instance().debug(String("WifiProvider: using static ip"));
			WiFi.config(conf->getIpAdress(), conf->getIpGateWay(),
					conf->getIpGateWay());
		}

		Logger::instance().debug(String("WifiProvider: start reconnect"));
		WiFi.hostname(conf->getNodeName());
		WiFi.begin(conf->getWifiSSID(), conf->getWifiPassword());
		delay(10);

		int attempt = 0;
		while (WiFi.status() != WL_CONNECTED) {
			delay(500);
			Logger::instance().debug(String("WifiProvider: waiting for connection ... "));
			attempt++;

			if (attempt > 100){
				Logger::instance().error(String("WifiProvider: can't connect to SSID ") + conf->getWifiSSID());
				ESP.reset();
			}
		}
	}

	Logger::instance().debug(String("WifiProvider: Wifi is connected"));
}

void WifiProvider::disconnect() {
	WiFi.disconnect();
}
