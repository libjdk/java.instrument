#include <java/lang/instrument/ClassFileTransformer.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/Module.h>
#include <java/security/ProtectionDomain.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $ProtectionDomain = ::java::security::ProtectionDomain;

namespace java {
	namespace lang {
		namespace instrument {

$MethodInfo _ClassFileTransformer_MethodInfo_[] = {
	{"transform", "(Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/lang/Class;Ljava/security/ProtectionDomain;[B)[B", "(Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/lang/Class<*>;Ljava/security/ProtectionDomain;[B)[B", $PUBLIC, nullptr, "java.lang.instrument.IllegalClassFormatException"},
	{"transform", "(Ljava/lang/Module;Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/lang/Class;Ljava/security/ProtectionDomain;[B)[B", "(Ljava/lang/Module;Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/lang/Class<*>;Ljava/security/ProtectionDomain;[B)[B", $PUBLIC, nullptr, "java.lang.instrument.IllegalClassFormatException"},
	{}
};

$ClassInfo _ClassFileTransformer_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.lang.instrument.ClassFileTransformer",
	nullptr,
	nullptr,
	nullptr,
	_ClassFileTransformer_MethodInfo_
};

$Object* allocate$ClassFileTransformer($Class* clazz) {
	return $of($alloc(ClassFileTransformer));
}

$bytes* ClassFileTransformer::transform($ClassLoader* loader, $String* className, $Class* classBeingRedefined, $ProtectionDomain* protectionDomain, $bytes* classfileBuffer) {
	return nullptr;
}

$bytes* ClassFileTransformer::transform($Module* module, $ClassLoader* loader, $String* className, $Class* classBeingRedefined, $ProtectionDomain* protectionDomain, $bytes* classfileBuffer) {
	return transform(loader, className, classBeingRedefined, protectionDomain, classfileBuffer);
}

$Class* ClassFileTransformer::load$($String* name, bool initialize) {
	$loadClass(ClassFileTransformer, name, initialize, &_ClassFileTransformer_ClassInfo_, allocate$ClassFileTransformer);
	return class$;
}

$Class* ClassFileTransformer::class$ = nullptr;

		} // instrument
	} // lang
} // java