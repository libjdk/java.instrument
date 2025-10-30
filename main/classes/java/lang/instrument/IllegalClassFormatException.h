#ifndef _java_lang_instrument_IllegalClassFormatException_h_
#define _java_lang_instrument_IllegalClassFormatException_h_
//$ class java.lang.instrument.IllegalClassFormatException
//$ extends java.lang.Exception

#include <java/lang/Exception.h>

namespace java {
	namespace lang {
		namespace instrument {

class $export IllegalClassFormatException : public ::java::lang::Exception {
	$class(IllegalClassFormatException, $NO_CLASS_INIT, ::java::lang::Exception)
public:
	IllegalClassFormatException();
	void init$();
	void init$($String* s);
	static const int64_t serialVersionUID = (int64_t)0xCAAF68D0D8C00767;
	IllegalClassFormatException(const IllegalClassFormatException& e);
	virtual void throw$() override;
	inline IllegalClassFormatException* operator ->() {
		return (IllegalClassFormatException*)throwing$;
	}
};

		} // instrument
	} // lang
} // java

#endif // _java_lang_instrument_IllegalClassFormatException_h_