#include <sun/instrument/TransformerManager$TransformerInfo.h>

#include <java/lang/instrument/ClassFileTransformer.h>
#include <sun/instrument/TransformerManager.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ClassFileTransformer = ::java::lang::instrument::ClassFileTransformer;
using $TransformerManager = ::sun::instrument::TransformerManager;

namespace sun {
	namespace instrument {

$FieldInfo _TransformerManager$TransformerInfo_FieldInfo_[] = {
	{"this$0", "Lsun/instrument/TransformerManager;", nullptr, $FINAL | $SYNTHETIC, $field(TransformerManager$TransformerInfo, this$0)},
	{"mTransformer", "Ljava/lang/instrument/ClassFileTransformer;", nullptr, $FINAL, $field(TransformerManager$TransformerInfo, mTransformer)},
	{"mPrefix", "Ljava/lang/String;", nullptr, 0, $field(TransformerManager$TransformerInfo, mPrefix)},
	{}
};

$MethodInfo _TransformerManager$TransformerInfo_MethodInfo_[] = {
	{"<init>", "(Lsun/instrument/TransformerManager;Ljava/lang/instrument/ClassFileTransformer;)V", nullptr, 0, $method(static_cast<void(TransformerManager$TransformerInfo::*)($TransformerManager*,$ClassFileTransformer*)>(&TransformerManager$TransformerInfo::init$))},
	{"getPrefix", "()Ljava/lang/String;", nullptr, 0},
	{"setPrefix", "(Ljava/lang/String;)V", nullptr, 0},
	{"transformer", "()Ljava/lang/instrument/ClassFileTransformer;", nullptr, 0},
	{}
};

$InnerClassInfo _TransformerManager$TransformerInfo_InnerClassesInfo_[] = {
	{"sun.instrument.TransformerManager$TransformerInfo", "sun.instrument.TransformerManager", "TransformerInfo", $PRIVATE},
	{}
};

$ClassInfo _TransformerManager$TransformerInfo_ClassInfo_ = {
	$ACC_SUPER,
	"sun.instrument.TransformerManager$TransformerInfo",
	"java.lang.Object",
	nullptr,
	_TransformerManager$TransformerInfo_FieldInfo_,
	_TransformerManager$TransformerInfo_MethodInfo_,
	nullptr,
	nullptr,
	_TransformerManager$TransformerInfo_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.instrument.TransformerManager"
};

$Object* allocate$TransformerManager$TransformerInfo($Class* clazz) {
	return $of($alloc(TransformerManager$TransformerInfo));
}

void TransformerManager$TransformerInfo::init$($TransformerManager* this$0, $ClassFileTransformer* transformer) {
	$set(this, this$0, this$0);
	$set(this, mTransformer, transformer);
	$set(this, mPrefix, nullptr);
}

$ClassFileTransformer* TransformerManager$TransformerInfo::transformer() {
	return this->mTransformer;
}

$String* TransformerManager$TransformerInfo::getPrefix() {
	return this->mPrefix;
}

void TransformerManager$TransformerInfo::setPrefix($String* prefix) {
	$set(this, mPrefix, prefix);
}

TransformerManager$TransformerInfo::TransformerManager$TransformerInfo() {
}

$Class* TransformerManager$TransformerInfo::load$($String* name, bool initialize) {
	$loadClass(TransformerManager$TransformerInfo, name, initialize, &_TransformerManager$TransformerInfo_ClassInfo_, allocate$TransformerManager$TransformerInfo);
	return class$;
}

$Class* TransformerManager$TransformerInfo::class$ = nullptr;

	} // instrument
} // sun