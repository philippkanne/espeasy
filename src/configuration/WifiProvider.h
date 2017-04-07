/*
 * WifiProvider.h
 *
 *  Created on: Mar 14, 2017
 *      Author: philipp
 */

#ifndef SRC_CONFIGURATION_WIFIPROVIDER_H_
#define SRC_CONFIGURATION_WIFIPROVIDER_H_

class WifiProvider {
public:
	WifiProvider();
	virtual ~WifiProvider();

	void connect();

	void disconnect();

};

#endif /* SRC_CONFIGURATION_WIFIPROVIDER_H_ */
