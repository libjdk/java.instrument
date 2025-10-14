#ifndef _sun_instrument_TransformerManager$TransformerInfo_h_
#define _sun_instrument_TransformerManager$TransformerInfo_h_
//$ class sun.instrument.TransformerManager$TransformerInfo
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace lang {
		namespace instrument {
			class ClassFileTransformer;
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

class TransformerManager$TransformerInfo : public ::java::lang::Object {
	$class(TransformerManager$TransformerInfo, $NO_CLASS_INIT, ::java::lang::Object)
public:
	TransformerManager$TransformerInfo();
	void init$(::sun::instrument::TransformerManager* this$0, ::java::lang::instrument::ClassFileTransformer* transformer);
	virtual $String* getPrefix();
	virtual void setPrefix($String* prefix);
	virtual ::java::lang::instrument::ClassFileTransformer* transformer();
	::sun::instrument::TransformerManager* this$0 = nullptr;
	::java::lang::instrument::ClassFileTransformer* mTransformer = nullptr;
	$String* mPrefix = nullptr;
};

	} // instrument
} // sun

#endif // _sun_instrument_TransformerManager$TransformerInfo_h_