#ifndef _java_lang_instrument_ClassDefinition_h_
#define _java_lang_instrument_ClassDefinition_h_
//$ class java.lang.instrument.ClassDefinition
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace lang {
		namespace instrument {

class $export ClassDefinition : public ::java::lang::Object {
	$class(ClassDefinition, $NO_CLASS_INIT, ::java::lang::Object)
public:
	ClassDefinition();
	void init$($Class* theClass, $bytes* theClassFile);
	$Class* getDefinitionClass();
	$bytes* getDefinitionClassFile();
	$Class* mClass = nullptr;
	$bytes* mClassFile = nullptr;
};

		} // instrument
	} // lang
} // java

#endif // _java_lang_instrument_ClassDefinition_h_