#include "Arduino.h"
#include "Timer.h"
#include <logging/Logger.h>

Timer::Timer() :
		_active(true), _now(millis()), _interval(1000) {
}

void Timer::activate() {
	_active = true;
}

void Timer::deactivate() {
	_active = false;
}

bool Timer::isActive() {
	return _active;
}

void Timer::reset() {
	_now = millis();
}

bool Timer::check() {
	if (!isActive()) {
		Logger::instance().debug("Timer is deactivated!\n");
		return false;
	}

	if (isActive() && millis() >= (_now + _interval)) {
		Logger::instance().debug("Timer is active now!!\n");
		reset();
		return true;
	}

	return false;
}

void Timer::setInterval(uint32_t milis) {
	_interval = milis;
}
