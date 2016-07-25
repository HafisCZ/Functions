// 2016 (c) HIRAISHIN SOFTWARE

#ifndef RuntimeProtocol_h
#define RuntimeProtocol_h

#include "Arduino.h"

class RuntimeProtocol {
	
	private:
		long interruptDelay;
		long compensation;
		bool firstDefined = false;
		bool secondDefined = false;
		unsigned long precedingMillis;
		protocol predec;
		void (*function)(void);
		void (*function2)(void);

    public:
		enum protocol {T_CLOCK , X_VOID };
		RuntimeProtocol(protocol prcl);
		bool Update(bool condition);
		void Start(long income);
		void Modify(long updatedDelay);
		void Attach(void (*code)(void));
		void Attach(void (*code)(void), void (*code2)(void));
		void Compensate(long compTime);
};

#endif