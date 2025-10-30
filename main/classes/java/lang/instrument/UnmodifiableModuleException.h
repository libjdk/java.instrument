#ifndef _java_lang_instrument_UnmodifiableModuleException_h_
#define _java_lang_instrument_UnmodifiableModuleException_h_
//$ class java.lang.instrument.UnmodifiableModuleException
//$ extends java.lang.RuntimeException

#include <java/lang/RuntimeException.h>

namespace java {
	namespace lang {
		namespace instrument {

class $export UnmodifiableModuleException : public ::java::lang::RuntimeException {
	$class(UnmodifiableModuleException, $NO_CLASS_INIT, ::java::lang::RuntimeException)
public:
	UnmodifiableModuleException();
	void init$();
	void init$($String* msg);
	static const int64_t serialVersionUID = (int64_t)0x5FEE2CF5D157A0C4;
	UnmodifiableModuleException(const UnmodifiableModuleException& e);
	virtual void throw$() override;
	inline UnmodifiableModuleException* operator ->() {
		return (UnmodifiableModuleException*)throwing$;
	}
};

		} // instrument
	} // lang
} // java

#endif // _java_lang_instrument_UnmodifiableModuleException_h_