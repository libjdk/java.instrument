#ifndef _sun_instrument_InstrumentationImpl_h_
#define _sun_instrument_InstrumentationImpl_h_
//$ class sun.instrument.InstrumentationImpl
//$ extends java.lang.instrument.Instrumentation

#include <java/lang/Array.h>
#include <java/lang/instrument/Instrumentation.h>

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
	namespace lang {
		namespace reflect {
			class AccessibleObject;
		}
	}
}
namespace java {
	namespace security {
		class ProtectionDomain;
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
namespace sun {
	namespace instrument {
		class TransformerManager;
	}
}

namespace sun {
	namespace instrument {

class $import InstrumentationImpl : public ::java::lang::instrument::Instrumentation {
	$class(InstrumentationImpl, 0, ::java::lang::instrument::Instrumentation)
public:
	InstrumentationImpl();
	void init$(int64_t nativeAgent, bool environmentSupportsRedefineClasses, bool environmentSupportsNativeMethodPrefix);
	virtual void addTransformer(::java::lang::instrument::ClassFileTransformer* transformer) override;
	virtual void addTransformer(::java::lang::instrument::ClassFileTransformer* transformer, bool canRetransform) override;
	virtual void appendToBootstrapClassLoaderSearch(::java::util::jar::JarFile* jarfile) override;
	void appendToClassLoaderSearch0(int64_t nativeAgent, $String* jarfile, bool bootLoader);
	virtual void appendToSystemClassLoaderSearch(::java::util::jar::JarFile* jarfile) override;
	::java::util::Map* cloneAndCheckMap(::java::lang::Module* module, ::java::util::Map* map);
	::sun::instrument::TransformerManager* findTransformerManager(::java::lang::instrument::ClassFileTransformer* transformer);
	virtual $ClassArray* getAllLoadedClasses() override;
	$ClassArray* getAllLoadedClasses0(int64_t nativeAgent);
	virtual $ClassArray* getInitiatedClasses(::java::lang::ClassLoader* loader) override;
	$ClassArray* getInitiatedClasses0(int64_t nativeAgent, ::java::lang::ClassLoader* loader);
	virtual int64_t getObjectSize(Object$* objectToSize) override;
	int64_t getObjectSize0(int64_t nativeAgent, Object$* objectToSize);
	virtual bool isModifiableClass($Class* theClass) override;
	bool isModifiableClass0(int64_t nativeAgent, $Class* theClass);
	virtual bool isModifiableModule(::java::lang::Module* module) override;
	virtual bool isNativeMethodPrefixSupported() override;
	virtual bool isRedefineClassesSupported() override;
	virtual bool isRetransformClassesSupported() override;
	bool isRetransformClassesSupported0(int64_t nativeAgent);
	static void lambda$redefineModule$0(::java::lang::Module* module, $Class* service, $Class* p);
	static void lambda$redefineModule$1(::java::lang::Module* module, ::java::lang::Module* m);
	static void lambda$redefineModule$2(::java::lang::Module* module, $String* pkg, ::java::lang::Module* m);
	static void lambda$redefineModule$3(::java::lang::Module* module, $String* pkg, ::java::lang::Module* m);
	static void lambda$redefineModule$4(::java::lang::Module* module, $Class* service);
	static void lambda$redefineModule$5(::java::lang::Module* module, $Class* service, $Class* p);
	static void loadAgent($String* path);
	static void loadAgent0($String* path);
	void loadClassAndCallAgentmain($String* classname, $String* optionsString);
	void loadClassAndCallPremain($String* classname, $String* optionsString);
	void loadClassAndStartAgent($String* classname, $String* methodname, $String* optionsString);
	virtual void redefineClasses($Array<::java::lang::instrument::ClassDefinition>* definitions) override;
	void redefineClasses0(int64_t nativeAgent, $Array<::java::lang::instrument::ClassDefinition>* definitions);
	virtual void redefineModule(::java::lang::Module* module, ::java::util::Set* extraReads, ::java::util::Map* extraExports, ::java::util::Map* extraOpens, ::java::util::Set* extraUses, ::java::util::Map* extraProvides) override;
	virtual bool removeTransformer(::java::lang::instrument::ClassFileTransformer* transformer) override;
	virtual void retransformClasses($ClassArray* classes) override;
	void retransformClasses0(int64_t nativeAgent, $ClassArray* classes);
	static void setAccessible(::java::lang::reflect::AccessibleObject* ao, bool accessible);
	void setHasRetransformableTransformers(int64_t nativeAgent, bool has);
	void setHasTransformers(int64_t nativeAgent, bool has);
	virtual void setNativeMethodPrefix(::java::lang::instrument::ClassFileTransformer* transformer, $String* prefix) override;
	void setNativeMethodPrefixes(int64_t nativeAgent, $StringArray* prefixes, bool isRetransformable);
	$bytes* transform(::java::lang::Module* module, ::java::lang::ClassLoader* loader, $String* classname, $Class* classBeingRedefined, ::java::security::ProtectionDomain* protectionDomain, $bytes* classfileBuffer, bool isRetransformer);
	::sun::instrument::TransformerManager* mTransformerManager = nullptr;
	::sun::instrument::TransformerManager* mRetransfomableTransformerManager = nullptr;
	int64_t mNativeAgent = 0;
	bool mEnvironmentSupportsRedefineClasses = false;
	$volatile(bool) mEnvironmentSupportsRetransformClassesKnown = false;
	$volatile(bool) mEnvironmentSupportsRetransformClasses = false;
	bool mEnvironmentSupportsNativeMethodPrefix = false;
};

	} // instrument
} // sun

#endif // _sun_instrument_InstrumentationImpl_h_