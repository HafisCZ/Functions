// 2016 (c) HIRAISHIN SOFTWARE

#include "Arduino.h"
#include "RuntimeProtocol.h"

RuntimeProtocol::RuntimeProtocol(protocol prcl) {
	predec = prcl;
}
	
void RuntimeProtocol::Start(long income) {
	if (predec == T_CLOCK) {
		compensation = 0;
		precedingMillis = 0;
		interruptDelay = delay;
	}
}

bool RuntimeProtocol::Update(bool condition) {
	if (predec == T_CLOCK) {
        unsigned long currentMillis = millis();
        if (condition && (currentMillis - precedingMillis >= (interruptDelay + compensation))) {
			precedingMillis = currentMillis;
			if (firstDefined) function();
			if (secondDefined) function2();
			return true;
        } else return false;
	}
}

void RuntimeProtocol::Modify(long updatedDelay) {
	if (predec == T_CLOCK) {
		interruptDelay = updatedDelay;
	}
}

void RuntimeProtocol::Attach(void (*code)(void)) {
	if (predec == T_CLOCK) {
		function = code;
		firstDefined = true;
	}
}

void RuntimeProtocol::Attach(void (*code)(void), void (*code2)(void)) {
	if (predec == T_CLOCK) {
		Attach(code);
		function2 = code2;
		secondDefined = true;
	}
}

void RuntimeProtocol::Compensate(long compTime) {
	if (predec == T_CLOCK) {
		compensation = compTime;
	}
}