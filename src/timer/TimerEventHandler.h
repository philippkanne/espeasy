/*
 * TimerEventHandler.h
 *
 *  Created on: Feb 28, 2017
 *      Author: philipp
 */

#ifndef SRC_TIMER_TIMEREVENTHANDLER_H_
#define SRC_TIMER_TIMEREVENTHANDLER_H_

#include <device/Device.h>

class TimerEventHandler {
public:
	TimerEventHandler();
	virtual ~TimerEventHandler();


	virtual void onTimer(Device* device);
};

#endif /* SRC_TIMER_TIMEREVENTHANDLER_H_ */
