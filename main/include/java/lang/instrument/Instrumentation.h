#ifndef _java_lang_instrument_Instrumentation_h_
#define _java_lang_instrument_Instrumentation_h_
//$ interface java.lang.instrument.Instrumentation
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace lang {
		class ClassLoader;
		class Module;
	}
}
namespace java {
	namespace lang {
		namespace instrument {
			class ClassDefinition;
			class ClassFileTransformer;
		}
	}
}
namespace java {
	namespace util {
		class Map;
		class Set;
	}
}
namespace java {
	namespace util {
		namespace jar {
			class JarFile;
		}
	}
}

namespace java {
	namespace lang {
		namespace instrument {

class $import Instrumentation : public ::java::lang::Object {
	$interface(Instrumentation, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual void addTransformer(::java::lang::instrument::ClassFileTransformer* transformer, bool canRetransform) {}
	virtual void addTransformer(::java::lang::instrument::ClassFileTransformer* transformer) {}
	virtual void appendToBootstrapClassLoaderSearch(::java::util::jar::JarFile* jarfile) {}
	virtual void appendToSystemClassLoaderSearch(::java::util::jar::JarFile* jarfile) {}
	virtual $ClassArray* getAllLoadedClasses() {return nullptr;}
	virtual $ClassArray* getInitiatedClasses(::java::lang::ClassLoader* loader) {return nullptr;}
	virtual int64_t getObjectSize(Object$* objectToSize) {return 0;}
	virtual bool isModifiableClass($Class* theClass) {return false;}
	virtual bool isModifiableModule(::java::lang::Module* module) {return false;}
	virtual bool isNativeMethodPrefixSupported() {return false;}
	virtual bool isRedefineClassesSupported() {return false;}
	virtual bool isRetransformClassesSupported() {return false;}
	virtual void redefineClasses($Array<::java::lang::instrument::ClassDefinition>* definitions) {}
	virtual void redefineModule(::java::lang::Module* module, ::java::util::Set* extraReads, ::java::util::Map* extraExports, ::java::util::Map* extraOpens, ::java::util::Set* extraUses, ::java::util::Map* extraProvides) {}
	virtual bool removeTransformer(::java::lang::instrument::ClassFileTransformer* transformer) {return false;}
	virtual void retransformClasses($ClassArray* classes) {}
	virtual void setNativeMethodPrefix(::java::lang::instrument::ClassFileTransformer* transformer, $String* prefix) {}
};

		} // instrument
	} // lang
} // java

#endif // _java_lang_instrument_Instrumentation_h_