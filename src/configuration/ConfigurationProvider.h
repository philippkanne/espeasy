/*
 * ConfigurationProvider.h
 *
 *  Created on: Mar 17, 2017
 *      Author: philipp
 */

#ifndef SRC_CONFIGURATION_CONFIGURATIONPROVIDER_H_
#define SRC_CONFIGURATION_CONFIGURATIONPROVIDER_H_

#include "Configuration.h"

class ConfigurationProvider {
public:
	static ConfigurationProvider& instance() {
		// The only instance
		// Guaranteed to be lazy initialized
		// Guaranteed that it will be destroyed correctly
		static ConfigurationProvider instance;
		return instance;
	}

	Configuration* getConfiguration() {
		Configuration* conf = new Configuration();
		return conf;
	}

private:
	ConfigurationProvider();
	ConfigurationProvider(const ConfigurationProvider&);
	ConfigurationProvider& operator=(const ConfigurationProvider&); // Not Implemented
};

#endif /* SRC_CONFIGURATION_CONFIGURATIONPROVIDER_H_ */
