#ifndef _java_lang_instrument_UnmodifiableClassException_h_
#define _java_lang_instrument_UnmodifiableClassException_h_
//$ class java.lang.instrument.UnmodifiableClassException
//$ extends java.lang.Exception

#include <java/lang/Exception.h>

namespace java {
	namespace lang {
		namespace instrument {

class $export UnmodifiableClassException : public ::java::lang::Exception {
	$class(UnmodifiableClassException, $NO_CLASS_INIT, ::java::lang::Exception)
public:
	UnmodifiableClassException();
	void init$();
	void init$($String* s);
	static const int64_t serialVersionUID = (int64_t)0x17D2C67BEFA339FA;
	UnmodifiableClassException(const UnmodifiableClassException& e);
	virtual void throw$() override;
	inline UnmodifiableClassException* operator ->() {
		return (UnmodifiableClassException*)throwing$;
	}
};

		} // instrument
	} // lang
} // java

#endif // _java_lang_instrument_UnmodifiableClassException_h_