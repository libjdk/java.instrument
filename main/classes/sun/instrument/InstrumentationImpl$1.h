#ifndef _sun_instrument_InstrumentationImpl$1_h_
#define _sun_instrument_InstrumentationImpl$1_h_
//$ class sun.instrument.InstrumentationImpl$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace lang {
		namespace reflect {
			class AccessibleObject;
		}
	}
}

namespace sun {
	namespace instrument {

class InstrumentationImpl$1 : public ::java::security::PrivilegedAction {
	$class(InstrumentationImpl$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	InstrumentationImpl$1();
	void init$(::java::lang::reflect::AccessibleObject* val$ao, bool val$accessible);
	virtual $Object* run() override;
	bool val$accessible = false;
	::java::lang::reflect::AccessibleObject* val$ao = nullptr;
};

	} // instrument
} // sun

#endif // _sun_instrument_InstrumentationImpl$1_h_