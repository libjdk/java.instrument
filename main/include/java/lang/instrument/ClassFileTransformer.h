#ifndef _java_lang_instrument_ClassFileTransformer_h_
#define _java_lang_instrument_ClassFileTransformer_h_
//$ interface java.lang.instrument.ClassFileTransformer
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace lang {
		class ClassLoader;
		class Module;
	}
}
namespace java {
	namespace security {
		class ProtectionDomain;
	}
}

namespace java {
	namespace lang {
		namespace instrument {

class $import ClassFileTransformer : public ::java::lang::Object {
	$interface(ClassFileTransformer, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual $bytes* transform(::java::lang::ClassLoader* loader, $String* className, $Class* classBeingRedefined, ::java::security::ProtectionDomain* protectionDomain, $bytes* classfileBuffer);
	virtual $bytes* transform(::java::lang::Module* module, ::java::lang::ClassLoader* loader, $String* className, $Class* classBeingRedefined, ::java::security::ProtectionDomain* protectionDomain, $bytes* classfileBuffer);
};

		} // instrument
	} // lang
} // java

#endif // _java_lang_instrument_ClassFileTransformer_h_