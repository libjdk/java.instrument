#include <sun/instrument/TransformerManager.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/Module.h>
#include <java/lang/instrument/ClassFileTransformer.h>
#include <java/security/ProtectionDomain.h>
#include <sun/instrument/TransformerManager$TransformerInfo.h>
#include <jcpp.h>

using $TransformerManager$TransformerInfoArray = $Array<::sun::instrument::TransformerManager$TransformerInfo>;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $ClassFileTransformer = ::java::lang::instrument::ClassFileTransformer;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $TransformerManager$TransformerInfo = ::sun::instrument::TransformerManager$TransformerInfo;

namespace sun {
	namespace instrument {

$FieldInfo _TransformerManager_FieldInfo_[] = {
	{"mTransformerList", "[Lsun/instrument/TransformerManager$TransformerInfo;", nullptr, $PRIVATE, $field(TransformerManager, mTransformerList)},
	{"mIsRetransformable", "Z", nullptr, $PRIVATE, $field(TransformerManager, mIsRetransformable)},
	{}
};

$MethodInfo _TransformerManager_MethodInfo_[] = {
	{"<init>", "(Z)V", nullptr, 0, $method(static_cast<void(TransformerManager::*)(bool)>(&TransformerManager::init$))},
	{"addTransformer", "(Ljava/lang/instrument/ClassFileTransformer;)V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"getNativeMethodPrefixes", "()[Ljava/lang/String;", nullptr, 0},
	{"getSnapshotTransformerList", "()[Lsun/instrument/TransformerManager$TransformerInfo;", nullptr, $PRIVATE, $method(static_cast<$TransformerManager$TransformerInfoArray*(TransformerManager::*)()>(&TransformerManager::getSnapshotTransformerList))},
	{"getTransformerCount", "()I", nullptr, 0},
	{"includesTransformer", "(Ljava/lang/instrument/ClassFileTransformer;)Z", nullptr, $SYNCHRONIZED},
	{"isRetransformable", "()Z", nullptr, 0},
	{"removeTransformer", "(Ljava/lang/instrument/ClassFileTransformer;)Z", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"setNativeMethodPrefix", "(Ljava/lang/instrument/ClassFileTransformer;Ljava/lang/String;)Z", nullptr, 0},
	{"transform", "(Ljava/lang/Module;Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/lang/Class;Ljava/security/ProtectionDomain;[B)[B", "(Ljava/lang/Module;Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/lang/Class<*>;Ljava/security/ProtectionDomain;[B)[B", $PUBLIC},
	{}
};

$InnerClassInfo _TransformerManager_InnerClassesInfo_[] = {
	{"sun.instrument.TransformerManager$TransformerInfo", "sun.instrument.TransformerManager", "TransformerInfo", $PRIVATE},
	{}
};

$ClassInfo _TransformerManager_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.instrument.TransformerManager",
	"java.lang.Object",
	nullptr,
	_TransformerManager_FieldInfo_,
	_TransformerManager_MethodInfo_,
	nullptr,
	nullptr,
	_TransformerManager_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.instrument.TransformerManager$TransformerInfo"
};

$Object* allocate$TransformerManager($Class* clazz) {
	return $of($alloc(TransformerManager));
}

void TransformerManager::init$(bool isRetransformable) {
	$set(this, mTransformerList, $new($TransformerManager$TransformerInfoArray, 0));
	this->mIsRetransformable = isRetransformable;
}

bool TransformerManager::isRetransformable() {
	return this->mIsRetransformable;
}

void TransformerManager::addTransformer($ClassFileTransformer* transformer) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($TransformerManager$TransformerInfoArray, oldList, this->mTransformerList);
		$var($TransformerManager$TransformerInfoArray, newList, $new($TransformerManager$TransformerInfoArray, $nc(oldList)->length + 1));
		$System::arraycopy(oldList, 0, newList, 0, oldList->length);
		newList->set(oldList->length, $$new($TransformerManager$TransformerInfo, this, transformer));
		$set(this, mTransformerList, newList);
	}
}

bool TransformerManager::removeTransformer($ClassFileTransformer* transformer) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		bool found = false;
		$var($TransformerManager$TransformerInfoArray, oldList, this->mTransformerList);
		int32_t oldLength = $nc(oldList)->length;
		int32_t newLength = oldLength - 1;
		int32_t matchingIndex = 0;
		for (int32_t x = oldLength - 1; x >= 0; --x) {
			if ($nc(oldList->get(x))->transformer() == transformer) {
				found = true;
				matchingIndex = x;
				break;
			}
		}
		if (found) {
			$var($TransformerManager$TransformerInfoArray, newList, $new($TransformerManager$TransformerInfoArray, newLength));
			if (matchingIndex > 0) {
				$System::arraycopy(oldList, 0, newList, 0, matchingIndex);
			}
			if (matchingIndex < (newLength)) {
				$System::arraycopy(oldList, matchingIndex + 1, newList, matchingIndex, (newLength) - matchingIndex);
			}
			$set(this, mTransformerList, newList);
		}
		return found;
	}
}

bool TransformerManager::includesTransformer($ClassFileTransformer* transformer) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		{
			$var($TransformerManager$TransformerInfoArray, arr$, this->mTransformerList);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($TransformerManager$TransformerInfo, info, arr$->get(i$));
				{
					if ($nc(info)->transformer() == transformer) {
						return true;
					}
				}
			}
		}
		return false;
	}
}

$TransformerManager$TransformerInfoArray* TransformerManager::getSnapshotTransformerList() {
	return this->mTransformerList;
}

$bytes* TransformerManager::transform($Module* module, $ClassLoader* loader, $String* classname, $Class* classBeingRedefined, $ProtectionDomain* protectionDomain, $bytes* classfileBuffer) {
	$useLocalCurrentObjectStackCache();
	bool someoneTouchedTheBytecode = false;
	$var($TransformerManager$TransformerInfoArray, transformerList, getSnapshotTransformerList());
	$var($bytes, bufferToUse, classfileBuffer);
	for (int32_t x = 0; x < $nc(transformerList)->length; ++x) {
		$var($TransformerManager$TransformerInfo, transformerInfo, transformerList->get(x));
		$var($ClassFileTransformer, transformer, $nc(transformerInfo)->transformer());
		$var($bytes, transformedBytes, nullptr);
		try {
			$assign(transformedBytes, $nc(transformer)->transform(module, loader, classname, classBeingRedefined, protectionDomain, bufferToUse));
		} catch ($Throwable& t) {
		}
		if (transformedBytes != nullptr) {
			someoneTouchedTheBytecode = true;
			$assign(bufferToUse, transformedBytes);
		}
	}
	$var($bytes, result, nullptr);
	if (someoneTouchedTheBytecode) {
		$assign(result, bufferToUse);
	} else {
		$assign(result, nullptr);
	}
	return result;
}

int32_t TransformerManager::getTransformerCount() {
	$var($TransformerManager$TransformerInfoArray, transformerList, getSnapshotTransformerList());
	return $nc(transformerList)->length;
}

bool TransformerManager::setNativeMethodPrefix($ClassFileTransformer* transformer, $String* prefix) {
	$useLocalCurrentObjectStackCache();
	$var($TransformerManager$TransformerInfoArray, transformerList, getSnapshotTransformerList());
	for (int32_t x = 0; x < $nc(transformerList)->length; ++x) {
		$var($TransformerManager$TransformerInfo, transformerInfo, transformerList->get(x));
		$var($ClassFileTransformer, aTransformer, $nc(transformerInfo)->transformer());
		if (aTransformer == transformer) {
			transformerInfo->setPrefix(prefix);
			return true;
		}
	}
	return false;
}

$StringArray* TransformerManager::getNativeMethodPrefixes() {
	$useLocalCurrentObjectStackCache();
	$var($TransformerManager$TransformerInfoArray, transformerList, getSnapshotTransformerList());
	$var($StringArray, prefixes, $new($StringArray, $nc(transformerList)->length));
	for (int32_t x = 0; x < transformerList->length; ++x) {
		$var($TransformerManager$TransformerInfo, transformerInfo, transformerList->get(x));
		prefixes->set(x, $($nc(transformerInfo)->getPrefix()));
	}
	return prefixes;
}

TransformerManager::TransformerManager() {
}

$Class* TransformerManager::load$($String* name, bool initialize) {
	$loadClass(TransformerManager, name, initialize, &_TransformerManager_ClassInfo_, allocate$TransformerManager);
	return class$;
}

$Class* TransformerManager::class$ = nullptr;

	} // instrument
} // sun