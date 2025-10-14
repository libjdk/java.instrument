#ifndef _sun_instrument_TransformerManager_h_
#define _sun_instrument_TransformerManager_h_
//$ class sun.instrument.TransformerManager
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
			class ClassFileTransformer;
		}
	}
}
namespace java {
	namespace security {
		class ProtectionDomain;
	}
}
namespace sun {
	namespace instrument {
		class TransformerManager$TransformerInfo;
	}
}

namespace sun {
	namespace instrument {

class $export TransformerManager : public ::java::lang::Object {
	$class(TransformerManager, $NO_CLASS_INIT, ::java::lang::Object)
public:
	TransformerManager();
	void init$(bool isRetransformable);
	virtual void addTransformer(::java::lang::instrument::ClassFileTransformer* transformer);
	virtual $StringArray* getNativeMethodPrefixes();
	$Array<::sun::instrument::TransformerManager$TransformerInfo>* getSnapshotTransformerList();
	virtual int32_t getTransformerCount();
	virtual bool includesTransformer(::java::lang::instrument::ClassFileTransformer* transformer);
	virtual bool isRetransformable();
	virtual bool removeTransformer(::java::lang::instrument::ClassFileTransformer* transformer);
	virtual bool setNativeMethodPrefix(::java::lang::instrument::ClassFileTransformer* transformer, $String* prefix);
	virtual $bytes* transform(::java::lang::Module* module, ::java::lang::ClassLoader* loader, $String* classname, $Class* classBeingRedefined, ::java::security::ProtectionDomain* protectionDomain, $bytes* classfileBuffer);
	$Array<::sun::instrument::TransformerManager$TransformerInfo>* mTransformerList = nullptr;
	bool mIsRetransformable = false;
};

	} // instrument
} // sun

#endif // _sun_instrument_TransformerManager_h_