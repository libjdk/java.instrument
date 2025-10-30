#include <sun/instrument/InstrumentationImpl.h>

#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/Module.h>
#include <java/lang/NoSuchMethodException.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/instrument/ClassDefinition.h>
#include <java/lang/instrument/ClassFileTransformer.h>
#include <java/lang/instrument/Instrumentation.h>
#include <java/lang/instrument/UnmodifiableModuleException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/reflect/AccessibleObject.h>
#include <java/lang/reflect/Executable.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Modifier.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/ProtectionDomain.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractMap.h>
#include <java/util/AbstractSet.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/HashMap.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/function/Consumer.h>
#include <java/util/jar/JarFile.h>
#include <jdk/internal/loader/BootLoader.h>
#include <jdk/internal/module/Modules.h>
#include <sun/instrument/InstrumentationImpl$1.h>
#include <sun/instrument/TransformerManager.h>
#include <jcpp.h>

using $ClassDefinitionArray = $Array<::java::lang::instrument::ClassDefinition>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Iterable = ::java::lang::Iterable;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NoSuchMethodException = ::java::lang::NoSuchMethodException;
using $NullPointerException = ::java::lang::NullPointerException;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Void = ::java::lang::Void;
using $ClassDefinition = ::java::lang::instrument::ClassDefinition;
using $ClassFileTransformer = ::java::lang::instrument::ClassFileTransformer;
using $Instrumentation = ::java::lang::instrument::Instrumentation;
using $UnmodifiableModuleException = ::java::lang::instrument::UnmodifiableModuleException;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $AccessibleObject = ::java::lang::reflect::AccessibleObject;
using $Executable = ::java::lang::reflect::Executable;
using $Method = ::java::lang::reflect::Method;
using $Modifier = ::java::lang::reflect::Modifier;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ProtectionDomain = ::java::security::ProtectionDomain;
using $AbstractList = ::java::util::AbstractList;
using $AbstractMap = ::java::util::AbstractMap;
using $AbstractSet = ::java::util::AbstractSet;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $HashMap = ::java::util::HashMap;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Consumer = ::java::util::function::Consumer;
using $JarFile = ::java::util::jar::JarFile;
using $ZipFile = ::java::util::zip::ZipFile;
using $BootLoader = ::jdk::internal::loader::BootLoader;
using $Modules = ::jdk::internal::module::Modules;
using $InstrumentationImpl$1 = ::sun::instrument::InstrumentationImpl$1;
using $TransformerManager = ::sun::instrument::TransformerManager;

namespace sun {
	namespace instrument {

class InstrumentationImpl$$Lambda$lambda$redefineModule$0 : public $Consumer {
	$class(InstrumentationImpl$$Lambda$lambda$redefineModule$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Module* module, $Class* service) {
		$set(this, module, module);
		this->service = service;
	}
	virtual void accept(Object$* p) override {
		InstrumentationImpl::lambda$redefineModule$0(module, service, $cast($Class, p));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<InstrumentationImpl$$Lambda$lambda$redefineModule$0>());
	}
	$Module* module = nullptr;
	$Class* service = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo InstrumentationImpl$$Lambda$lambda$redefineModule$0::fieldInfos[3] = {
	{"module", "Ljava/lang/Module;", nullptr, $PUBLIC, $field(InstrumentationImpl$$Lambda$lambda$redefineModule$0, module)},
	{"service", "Ljava/lang/Class;", nullptr, $PUBLIC, $field(InstrumentationImpl$$Lambda$lambda$redefineModule$0, service)},
	{}
};
$MethodInfo InstrumentationImpl$$Lambda$lambda$redefineModule$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Module;Ljava/lang/Class;)V", nullptr, $PUBLIC, $method(static_cast<void(InstrumentationImpl$$Lambda$lambda$redefineModule$0::*)($Module*,$Class*)>(&InstrumentationImpl$$Lambda$lambda$redefineModule$0::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo InstrumentationImpl$$Lambda$lambda$redefineModule$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.instrument.InstrumentationImpl$$Lambda$lambda$redefineModule$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* InstrumentationImpl$$Lambda$lambda$redefineModule$0::load$($String* name, bool initialize) {
	$loadClass(InstrumentationImpl$$Lambda$lambda$redefineModule$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* InstrumentationImpl$$Lambda$lambda$redefineModule$0::class$ = nullptr;

class InstrumentationImpl$$Lambda$lambda$redefineModule$1$1 : public $Consumer {
	$class(InstrumentationImpl$$Lambda$lambda$redefineModule$1$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Module* module) {
		$set(this, module, module);
	}
	virtual void accept(Object$* m) override {
		InstrumentationImpl::lambda$redefineModule$1(module, $cast($Module, m));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<InstrumentationImpl$$Lambda$lambda$redefineModule$1$1>());
	}
	$Module* module = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo InstrumentationImpl$$Lambda$lambda$redefineModule$1$1::fieldInfos[2] = {
	{"module", "Ljava/lang/Module;", nullptr, $PUBLIC, $field(InstrumentationImpl$$Lambda$lambda$redefineModule$1$1, module)},
	{}
};
$MethodInfo InstrumentationImpl$$Lambda$lambda$redefineModule$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Module;)V", nullptr, $PUBLIC, $method(static_cast<void(InstrumentationImpl$$Lambda$lambda$redefineModule$1$1::*)($Module*)>(&InstrumentationImpl$$Lambda$lambda$redefineModule$1$1::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo InstrumentationImpl$$Lambda$lambda$redefineModule$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.instrument.InstrumentationImpl$$Lambda$lambda$redefineModule$1$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* InstrumentationImpl$$Lambda$lambda$redefineModule$1$1::load$($String* name, bool initialize) {
	$loadClass(InstrumentationImpl$$Lambda$lambda$redefineModule$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* InstrumentationImpl$$Lambda$lambda$redefineModule$1$1::class$ = nullptr;

class InstrumentationImpl$$Lambda$lambda$redefineModule$2$2 : public $Consumer {
	$class(InstrumentationImpl$$Lambda$lambda$redefineModule$2$2, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Module* module, $String* pkg) {
		$set(this, module, module);
		$set(this, pkg, pkg);
	}
	virtual void accept(Object$* m) override {
		InstrumentationImpl::lambda$redefineModule$2(module, pkg, $cast($Module, m));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<InstrumentationImpl$$Lambda$lambda$redefineModule$2$2>());
	}
	$Module* module = nullptr;
	$String* pkg = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo InstrumentationImpl$$Lambda$lambda$redefineModule$2$2::fieldInfos[3] = {
	{"module", "Ljava/lang/Module;", nullptr, $PUBLIC, $field(InstrumentationImpl$$Lambda$lambda$redefineModule$2$2, module)},
	{"pkg", "Ljava/lang/String;", nullptr, $PUBLIC, $field(InstrumentationImpl$$Lambda$lambda$redefineModule$2$2, pkg)},
	{}
};
$MethodInfo InstrumentationImpl$$Lambda$lambda$redefineModule$2$2::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Module;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(InstrumentationImpl$$Lambda$lambda$redefineModule$2$2::*)($Module*,$String*)>(&InstrumentationImpl$$Lambda$lambda$redefineModule$2$2::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo InstrumentationImpl$$Lambda$lambda$redefineModule$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.instrument.InstrumentationImpl$$Lambda$lambda$redefineModule$2$2",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* InstrumentationImpl$$Lambda$lambda$redefineModule$2$2::load$($String* name, bool initialize) {
	$loadClass(InstrumentationImpl$$Lambda$lambda$redefineModule$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* InstrumentationImpl$$Lambda$lambda$redefineModule$2$2::class$ = nullptr;

class InstrumentationImpl$$Lambda$lambda$redefineModule$3$3 : public $Consumer {
	$class(InstrumentationImpl$$Lambda$lambda$redefineModule$3$3, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Module* module, $String* pkg) {
		$set(this, module, module);
		$set(this, pkg, pkg);
	}
	virtual void accept(Object$* m) override {
		InstrumentationImpl::lambda$redefineModule$3(module, pkg, $cast($Module, m));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<InstrumentationImpl$$Lambda$lambda$redefineModule$3$3>());
	}
	$Module* module = nullptr;
	$String* pkg = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo InstrumentationImpl$$Lambda$lambda$redefineModule$3$3::fieldInfos[3] = {
	{"module", "Ljava/lang/Module;", nullptr, $PUBLIC, $field(InstrumentationImpl$$Lambda$lambda$redefineModule$3$3, module)},
	{"pkg", "Ljava/lang/String;", nullptr, $PUBLIC, $field(InstrumentationImpl$$Lambda$lambda$redefineModule$3$3, pkg)},
	{}
};
$MethodInfo InstrumentationImpl$$Lambda$lambda$redefineModule$3$3::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Module;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(InstrumentationImpl$$Lambda$lambda$redefineModule$3$3::*)($Module*,$String*)>(&InstrumentationImpl$$Lambda$lambda$redefineModule$3$3::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo InstrumentationImpl$$Lambda$lambda$redefineModule$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.instrument.InstrumentationImpl$$Lambda$lambda$redefineModule$3$3",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* InstrumentationImpl$$Lambda$lambda$redefineModule$3$3::load$($String* name, bool initialize) {
	$loadClass(InstrumentationImpl$$Lambda$lambda$redefineModule$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* InstrumentationImpl$$Lambda$lambda$redefineModule$3$3::class$ = nullptr;

class InstrumentationImpl$$Lambda$lambda$redefineModule$4$4 : public $Consumer {
	$class(InstrumentationImpl$$Lambda$lambda$redefineModule$4$4, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Module* module) {
		$set(this, module, module);
	}
	virtual void accept(Object$* service) override {
		InstrumentationImpl::lambda$redefineModule$4(module, $cast($Class, service));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<InstrumentationImpl$$Lambda$lambda$redefineModule$4$4>());
	}
	$Module* module = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo InstrumentationImpl$$Lambda$lambda$redefineModule$4$4::fieldInfos[2] = {
	{"module", "Ljava/lang/Module;", nullptr, $PUBLIC, $field(InstrumentationImpl$$Lambda$lambda$redefineModule$4$4, module)},
	{}
};
$MethodInfo InstrumentationImpl$$Lambda$lambda$redefineModule$4$4::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Module;)V", nullptr, $PUBLIC, $method(static_cast<void(InstrumentationImpl$$Lambda$lambda$redefineModule$4$4::*)($Module*)>(&InstrumentationImpl$$Lambda$lambda$redefineModule$4$4::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo InstrumentationImpl$$Lambda$lambda$redefineModule$4$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.instrument.InstrumentationImpl$$Lambda$lambda$redefineModule$4$4",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* InstrumentationImpl$$Lambda$lambda$redefineModule$4$4::load$($String* name, bool initialize) {
	$loadClass(InstrumentationImpl$$Lambda$lambda$redefineModule$4$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* InstrumentationImpl$$Lambda$lambda$redefineModule$4$4::class$ = nullptr;

class InstrumentationImpl$$Lambda$lambda$redefineModule$5$5 : public $Consumer {
	$class(InstrumentationImpl$$Lambda$lambda$redefineModule$5$5, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Module* module, $Class* service) {
		$set(this, module, module);
		this->service = service;
	}
	virtual void accept(Object$* p) override {
		InstrumentationImpl::lambda$redefineModule$5(module, service, $cast($Class, p));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<InstrumentationImpl$$Lambda$lambda$redefineModule$5$5>());
	}
	$Module* module = nullptr;
	$Class* service = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo InstrumentationImpl$$Lambda$lambda$redefineModule$5$5::fieldInfos[3] = {
	{"module", "Ljava/lang/Module;", nullptr, $PUBLIC, $field(InstrumentationImpl$$Lambda$lambda$redefineModule$5$5, module)},
	{"service", "Ljava/lang/Class;", nullptr, $PUBLIC, $field(InstrumentationImpl$$Lambda$lambda$redefineModule$5$5, service)},
	{}
};
$MethodInfo InstrumentationImpl$$Lambda$lambda$redefineModule$5$5::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Module;Ljava/lang/Class;)V", nullptr, $PUBLIC, $method(static_cast<void(InstrumentationImpl$$Lambda$lambda$redefineModule$5$5::*)($Module*,$Class*)>(&InstrumentationImpl$$Lambda$lambda$redefineModule$5$5::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo InstrumentationImpl$$Lambda$lambda$redefineModule$5$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.instrument.InstrumentationImpl$$Lambda$lambda$redefineModule$5$5",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* InstrumentationImpl$$Lambda$lambda$redefineModule$5$5::load$($String* name, bool initialize) {
	$loadClass(InstrumentationImpl$$Lambda$lambda$redefineModule$5$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* InstrumentationImpl$$Lambda$lambda$redefineModule$5$5::class$ = nullptr;

$CompoundAttribute _InstrumentationImpl_MethodAnnotations_getObjectSize013[] = {
	{"Ljdk/internal/vm/annotation/IntrinsicCandidate;", nullptr},
	{}
};

$FieldInfo _InstrumentationImpl_FieldInfo_[] = {
	{"mTransformerManager", "Lsun/instrument/TransformerManager;", nullptr, $PRIVATE | $FINAL, $field(InstrumentationImpl, mTransformerManager)},
	{"mRetransfomableTransformerManager", "Lsun/instrument/TransformerManager;", nullptr, $PRIVATE, $field(InstrumentationImpl, mRetransfomableTransformerManager)},
	{"mNativeAgent", "J", nullptr, $PRIVATE | $FINAL, $field(InstrumentationImpl, mNativeAgent)},
	{"mEnvironmentSupportsRedefineClasses", "Z", nullptr, $PRIVATE | $FINAL, $field(InstrumentationImpl, mEnvironmentSupportsRedefineClasses)},
	{"mEnvironmentSupportsRetransformClassesKnown", "Z", nullptr, $PRIVATE | $VOLATILE, $field(InstrumentationImpl, mEnvironmentSupportsRetransformClassesKnown)},
	{"mEnvironmentSupportsRetransformClasses", "Z", nullptr, $PRIVATE | $VOLATILE, $field(InstrumentationImpl, mEnvironmentSupportsRetransformClasses)},
	{"mEnvironmentSupportsNativeMethodPrefix", "Z", nullptr, $PRIVATE | $FINAL, $field(InstrumentationImpl, mEnvironmentSupportsNativeMethodPrefix)},
	{}
};

$MethodInfo _InstrumentationImpl_MethodInfo_[] = {
	{"<init>", "(JZZ)V", nullptr, $PRIVATE, $method(static_cast<void(InstrumentationImpl::*)(int64_t,bool,bool)>(&InstrumentationImpl::init$))},
	{"addTransformer", "(Ljava/lang/instrument/ClassFileTransformer;)V", nullptr, $PUBLIC},
	{"addTransformer", "(Ljava/lang/instrument/ClassFileTransformer;Z)V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"appendToBootstrapClassLoaderSearch", "(Ljava/util/jar/JarFile;)V", nullptr, $PUBLIC},
	{"appendToClassLoaderSearch0", "(JLjava/lang/String;Z)V", nullptr, $PRIVATE | $NATIVE, $method(static_cast<void(InstrumentationImpl::*)(int64_t,$String*,bool)>(&InstrumentationImpl::appendToClassLoaderSearch0))},
	{"appendToSystemClassLoaderSearch", "(Ljava/util/jar/JarFile;)V", nullptr, $PUBLIC},
	{"cloneAndCheckMap", "(Ljava/lang/Module;Ljava/util/Map;)Ljava/util/Map;", "(Ljava/lang/Module;Ljava/util/Map<Ljava/lang/String;Ljava/util/Set<Ljava/lang/Module;>;>;)Ljava/util/Map<Ljava/lang/String;Ljava/util/Set<Ljava/lang/Module;>;>;", $PRIVATE, $method(static_cast<$Map*(InstrumentationImpl::*)($Module*,$Map*)>(&InstrumentationImpl::cloneAndCheckMap))},
	{"findTransformerManager", "(Ljava/lang/instrument/ClassFileTransformer;)Lsun/instrument/TransformerManager;", nullptr, $PRIVATE, $method(static_cast<$TransformerManager*(InstrumentationImpl::*)($ClassFileTransformer*)>(&InstrumentationImpl::findTransformerManager))},
	{"getAllLoadedClasses", "()[Ljava/lang/Class;", nullptr, $PUBLIC},
	{"getAllLoadedClasses0", "(J)[Ljava/lang/Class;", nullptr, $PRIVATE | $NATIVE, $method(static_cast<$ClassArray*(InstrumentationImpl::*)(int64_t)>(&InstrumentationImpl::getAllLoadedClasses0))},
	{"getInitiatedClasses", "(Ljava/lang/ClassLoader;)[Ljava/lang/Class;", nullptr, $PUBLIC},
	{"getInitiatedClasses0", "(JLjava/lang/ClassLoader;)[Ljava/lang/Class;", nullptr, $PRIVATE | $NATIVE, $method(static_cast<$ClassArray*(InstrumentationImpl::*)(int64_t,$ClassLoader*)>(&InstrumentationImpl::getInitiatedClasses0))},
	{"getObjectSize", "(Ljava/lang/Object;)J", nullptr, $PUBLIC},
	{"getObjectSize0", "(JLjava/lang/Object;)J", nullptr, $PRIVATE | $NATIVE, $method(static_cast<int64_t(InstrumentationImpl::*)(int64_t,Object$*)>(&InstrumentationImpl::getObjectSize0)), nullptr, nullptr, _InstrumentationImpl_MethodAnnotations_getObjectSize013},
	{"isModifiableClass", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<*>;)Z", $PUBLIC},
	{"isModifiableClass0", "(JLjava/lang/Class;)Z", "(JLjava/lang/Class<*>;)Z", $PRIVATE | $NATIVE, $method(static_cast<bool(InstrumentationImpl::*)(int64_t,$Class*)>(&InstrumentationImpl::isModifiableClass0))},
	{"isModifiableModule", "(Ljava/lang/Module;)Z", nullptr, $PUBLIC},
	{"isNativeMethodPrefixSupported", "()Z", nullptr, $PUBLIC},
	{"isRedefineClassesSupported", "()Z", nullptr, $PUBLIC},
	{"isRetransformClassesSupported", "()Z", nullptr, $PUBLIC},
	{"isRetransformClassesSupported0", "(J)Z", nullptr, $PRIVATE | $NATIVE, $method(static_cast<bool(InstrumentationImpl::*)(int64_t)>(&InstrumentationImpl::isRetransformClassesSupported0))},
	{"lambda$redefineModule$0", "(Ljava/lang/Module;Ljava/lang/Class;Ljava/lang/Class;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($Module*,$Class*,$Class*)>(&InstrumentationImpl::lambda$redefineModule$0))},
	{"lambda$redefineModule$1", "(Ljava/lang/Module;Ljava/lang/Module;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($Module*,$Module*)>(&InstrumentationImpl::lambda$redefineModule$1))},
	{"lambda$redefineModule$2", "(Ljava/lang/Module;Ljava/lang/String;Ljava/lang/Module;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($Module*,$String*,$Module*)>(&InstrumentationImpl::lambda$redefineModule$2))},
	{"lambda$redefineModule$3", "(Ljava/lang/Module;Ljava/lang/String;Ljava/lang/Module;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($Module*,$String*,$Module*)>(&InstrumentationImpl::lambda$redefineModule$3))},
	{"lambda$redefineModule$4", "(Ljava/lang/Module;Ljava/lang/Class;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($Module*,$Class*)>(&InstrumentationImpl::lambda$redefineModule$4))},
	{"lambda$redefineModule$5", "(Ljava/lang/Module;Ljava/lang/Class;Ljava/lang/Class;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($Module*,$Class*,$Class*)>(&InstrumentationImpl::lambda$redefineModule$5))},
	{"loadAgent", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($String*)>(&InstrumentationImpl::loadAgent))},
	{"loadAgent0", "(Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $NATIVE, $method(static_cast<void(*)($String*)>(&InstrumentationImpl::loadAgent0))},
	{"loadClassAndCallAgentmain", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(InstrumentationImpl::*)($String*,$String*)>(&InstrumentationImpl::loadClassAndCallAgentmain)), "java.lang.Throwable"},
	{"loadClassAndCallPremain", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(InstrumentationImpl::*)($String*,$String*)>(&InstrumentationImpl::loadClassAndCallPremain)), "java.lang.Throwable"},
	{"loadClassAndStartAgent", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(InstrumentationImpl::*)($String*,$String*,$String*)>(&InstrumentationImpl::loadClassAndStartAgent)), "java.lang.Throwable"},
	{"redefineClasses", "([Ljava/lang/instrument/ClassDefinition;)V", nullptr, $PUBLIC | $TRANSIENT, nullptr, "java.lang.ClassNotFoundException"},
	{"redefineClasses0", "(J[Ljava/lang/instrument/ClassDefinition;)V", nullptr, $PRIVATE | $NATIVE, $method(static_cast<void(InstrumentationImpl::*)(int64_t,$ClassDefinitionArray*)>(&InstrumentationImpl::redefineClasses0)), "java.lang.ClassNotFoundException"},
	{"redefineModule", "(Ljava/lang/Module;Ljava/util/Set;Ljava/util/Map;Ljava/util/Map;Ljava/util/Set;Ljava/util/Map;)V", "(Ljava/lang/Module;Ljava/util/Set<Ljava/lang/Module;>;Ljava/util/Map<Ljava/lang/String;Ljava/util/Set<Ljava/lang/Module;>;>;Ljava/util/Map<Ljava/lang/String;Ljava/util/Set<Ljava/lang/Module;>;>;Ljava/util/Set<Ljava/lang/Class<*>;>;Ljava/util/Map<Ljava/lang/Class<*>;Ljava/util/List<Ljava/lang/Class<*>;>;>;)V", $PUBLIC},
	{"removeTransformer", "(Ljava/lang/instrument/ClassFileTransformer;)Z", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"retransformClasses", "([Ljava/lang/Class;)V", "([Ljava/lang/Class<*>;)V", $PUBLIC | $TRANSIENT},
	{"retransformClasses0", "(J[Ljava/lang/Class;)V", "(J[Ljava/lang/Class<*>;)V", $PRIVATE | $NATIVE, $method(static_cast<void(InstrumentationImpl::*)(int64_t,$ClassArray*)>(&InstrumentationImpl::retransformClasses0))},
	{"setAccessible", "(Ljava/lang/reflect/AccessibleObject;Z)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($AccessibleObject*,bool)>(&InstrumentationImpl::setAccessible))},
	{"setHasRetransformableTransformers", "(JZ)V", nullptr, $PRIVATE | $NATIVE, $method(static_cast<void(InstrumentationImpl::*)(int64_t,bool)>(&InstrumentationImpl::setHasRetransformableTransformers))},
	{"setHasTransformers", "(JZ)V", nullptr, $PRIVATE | $NATIVE, $method(static_cast<void(InstrumentationImpl::*)(int64_t,bool)>(&InstrumentationImpl::setHasTransformers))},
	{"setNativeMethodPrefix", "(Ljava/lang/instrument/ClassFileTransformer;Ljava/lang/String;)V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"setNativeMethodPrefixes", "(J[Ljava/lang/String;Z)V", nullptr, $PRIVATE | $NATIVE, $method(static_cast<void(InstrumentationImpl::*)(int64_t,$StringArray*,bool)>(&InstrumentationImpl::setNativeMethodPrefixes))},
	{"transform", "(Ljava/lang/Module;Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/lang/Class;Ljava/security/ProtectionDomain;[BZ)[B", "(Ljava/lang/Module;Ljava/lang/ClassLoader;Ljava/lang/String;Ljava/lang/Class<*>;Ljava/security/ProtectionDomain;[BZ)[B", $PRIVATE, $method(static_cast<$bytes*(InstrumentationImpl::*)($Module*,$ClassLoader*,$String*,$Class*,$ProtectionDomain*,$bytes*,bool)>(&InstrumentationImpl::transform))},
	{}
};

#define _METHOD_INDEX_appendToClassLoaderSearch0 4
#define _METHOD_INDEX_getAllLoadedClasses0 9
#define _METHOD_INDEX_getInitiatedClasses0 11
#define _METHOD_INDEX_getObjectSize0 13
#define _METHOD_INDEX_isModifiableClass0 15
#define _METHOD_INDEX_isRetransformClassesSupported0 20
#define _METHOD_INDEX_loadAgent0 28
#define _METHOD_INDEX_redefineClasses0 33
#define _METHOD_INDEX_retransformClasses0 37
#define _METHOD_INDEX_setHasRetransformableTransformers 39
#define _METHOD_INDEX_setHasTransformers 40
#define _METHOD_INDEX_setNativeMethodPrefixes 42

$InnerClassInfo _InstrumentationImpl_InnerClassesInfo_[] = {
	{"sun.instrument.InstrumentationImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _InstrumentationImpl_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.instrument.InstrumentationImpl",
	"java.lang.Object",
	"java.lang.instrument.Instrumentation",
	_InstrumentationImpl_FieldInfo_,
	_InstrumentationImpl_MethodInfo_,
	nullptr,
	nullptr,
	_InstrumentationImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.instrument.InstrumentationImpl$1"
};

$Object* allocate$InstrumentationImpl($Class* clazz) {
	return $of($alloc(InstrumentationImpl));
}

void InstrumentationImpl::init$(int64_t nativeAgent, bool environmentSupportsRedefineClasses, bool environmentSupportsNativeMethodPrefix) {
	$set(this, mTransformerManager, $new($TransformerManager, false));
	$set(this, mRetransfomableTransformerManager, nullptr);
	this->mNativeAgent = nativeAgent;
	this->mEnvironmentSupportsRedefineClasses = environmentSupportsRedefineClasses;
	this->mEnvironmentSupportsRetransformClassesKnown = false;
	this->mEnvironmentSupportsRetransformClasses = false;
	this->mEnvironmentSupportsNativeMethodPrefix = environmentSupportsNativeMethodPrefix;
}

void InstrumentationImpl::addTransformer($ClassFileTransformer* transformer) {
	addTransformer(transformer, false);
}

void InstrumentationImpl::addTransformer($ClassFileTransformer* transformer, bool canRetransform) {
	$synchronized(this) {
		if (transformer == nullptr) {
			$throwNew($NullPointerException, "null passed as \'transformer\' in addTransformer"_s);
		}
		if (canRetransform) {
			if (!isRetransformClassesSupported()) {
				$throwNew($UnsupportedOperationException, "adding retransformable transformers is not supported in this environment"_s);
			}
			if (this->mRetransfomableTransformerManager == nullptr) {
				$set(this, mRetransfomableTransformerManager, $new($TransformerManager, true));
			}
			$nc(this->mRetransfomableTransformerManager)->addTransformer(transformer);
			if ($nc(this->mRetransfomableTransformerManager)->getTransformerCount() == 1) {
				setHasRetransformableTransformers(this->mNativeAgent, true);
			}
		} else {
			$nc(this->mTransformerManager)->addTransformer(transformer);
			if ($nc(this->mTransformerManager)->getTransformerCount() == 1) {
				setHasTransformers(this->mNativeAgent, true);
			}
		}
	}
}

bool InstrumentationImpl::removeTransformer($ClassFileTransformer* transformer) {
	$synchronized(this) {
		if (transformer == nullptr) {
			$throwNew($NullPointerException, "null passed as \'transformer\' in removeTransformer"_s);
		}
		$var($TransformerManager, mgr, findTransformerManager(transformer));
		if (mgr != nullptr) {
			mgr->removeTransformer(transformer);
			if (mgr->getTransformerCount() == 0) {
				if (mgr->isRetransformable()) {
					setHasRetransformableTransformers(this->mNativeAgent, false);
				} else {
					setHasTransformers(this->mNativeAgent, false);
				}
			}
			return true;
		}
		return false;
	}
}

bool InstrumentationImpl::isModifiableClass($Class* theClass) {
	if (theClass == nullptr) {
		$throwNew($NullPointerException, "null passed as \'theClass\' in isModifiableClass"_s);
	}
	return isModifiableClass0(this->mNativeAgent, theClass);
}

bool InstrumentationImpl::isModifiableModule($Module* module) {
	if (module == nullptr) {
		$throwNew($NullPointerException, "\'module\' is null"_s);
	}
	return true;
}

bool InstrumentationImpl::isRetransformClassesSupported() {
	if (!this->mEnvironmentSupportsRetransformClassesKnown) {
		this->mEnvironmentSupportsRetransformClasses = isRetransformClassesSupported0(this->mNativeAgent);
		this->mEnvironmentSupportsRetransformClassesKnown = true;
	}
	return this->mEnvironmentSupportsRetransformClasses;
}

void InstrumentationImpl::retransformClasses($ClassArray* classes) {
	if (!isRetransformClassesSupported()) {
		$throwNew($UnsupportedOperationException, "retransformClasses is not supported in this environment"_s);
	}
	if ($nc(classes)->length == 0) {
		return;
	}
	retransformClasses0(this->mNativeAgent, classes);
}

bool InstrumentationImpl::isRedefineClassesSupported() {
	return this->mEnvironmentSupportsRedefineClasses;
}

void InstrumentationImpl::redefineClasses($ClassDefinitionArray* definitions) {
	if (!isRedefineClassesSupported()) {
		$throwNew($UnsupportedOperationException, "redefineClasses is not supported in this environment"_s);
	}
	if (definitions == nullptr) {
		$throwNew($NullPointerException, "null passed as \'definitions\' in redefineClasses"_s);
	}
	for (int32_t i = 0; i < $nc(definitions)->length; ++i) {
		if (definitions->get(i) == nullptr) {
			$throwNew($NullPointerException, "element of \'definitions\' is null in redefineClasses"_s);
		}
	}
	if ($nc(definitions)->length == 0) {
		return;
	}
	redefineClasses0(this->mNativeAgent, definitions);
}

$ClassArray* InstrumentationImpl::getAllLoadedClasses() {
	return getAllLoadedClasses0(this->mNativeAgent);
}

$ClassArray* InstrumentationImpl::getInitiatedClasses($ClassLoader* loader) {
	return getInitiatedClasses0(this->mNativeAgent, loader);
}

int64_t InstrumentationImpl::getObjectSize(Object$* objectToSize) {
	if (objectToSize == nullptr) {
		$throwNew($NullPointerException, "null passed as \'objectToSize\' in getObjectSize"_s);
	}
	return getObjectSize0(this->mNativeAgent, objectToSize);
}

void InstrumentationImpl::appendToBootstrapClassLoaderSearch($JarFile* jarfile) {
	appendToClassLoaderSearch0(this->mNativeAgent, $($nc(jarfile)->getName()), true);
}

void InstrumentationImpl::appendToSystemClassLoaderSearch($JarFile* jarfile) {
	appendToClassLoaderSearch0(this->mNativeAgent, $($nc(jarfile)->getName()), false);
}

bool InstrumentationImpl::isNativeMethodPrefixSupported() {
	return this->mEnvironmentSupportsNativeMethodPrefix;
}

void InstrumentationImpl::setNativeMethodPrefix($ClassFileTransformer* transformer, $String* prefix) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (!isNativeMethodPrefixSupported()) {
			$throwNew($UnsupportedOperationException, "setNativeMethodPrefix is not supported in this environment"_s);
		}
		if (transformer == nullptr) {
			$throwNew($NullPointerException, "null passed as \'transformer\' in setNativeMethodPrefix"_s);
		}
		$var($TransformerManager, mgr, findTransformerManager(transformer));
		if (mgr == nullptr) {
			$throwNew($IllegalArgumentException, "transformer not registered in setNativeMethodPrefix"_s);
		}
		$nc(mgr)->setNativeMethodPrefix(transformer, prefix);
		$var($StringArray, prefixes, mgr->getNativeMethodPrefixes());
		setNativeMethodPrefixes(this->mNativeAgent, prefixes, mgr->isRetransformable());
	}
}

void InstrumentationImpl::redefineModule($Module* module, $Set* extraReads$renamed, $Map* extraExports$renamed, $Map* extraOpens$renamed, $Set* extraUses$renamed, $Map* extraProvides$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Map, extraExports, extraExports$renamed);
	$var($Set, extraReads, extraReads$renamed);
	$var($Map, extraOpens, extraOpens$renamed);
	$var($Map, extraProvides, extraProvides$renamed);
	$var($Set, extraUses, extraUses$renamed);
	if (!$nc(module)->isNamed()) {
		return;
	}
	if (!isModifiableModule(module)) {
		$throwNew($UnmodifiableModuleException, $($nc(module)->getName()));
	}
	$assign(extraReads, $new($HashSet, static_cast<$Collection*>(extraReads)));
	if (extraReads->contains(nullptr)) {
		$throwNew($NullPointerException, "\'extraReads\' contains null"_s);
	}
	$assign(extraExports, cloneAndCheckMap(module, extraExports));
	$assign(extraOpens, cloneAndCheckMap(module, extraOpens));
	$assign(extraUses, $new($HashSet, static_cast<$Collection*>(extraUses)));
	if (extraUses->contains(nullptr)) {
		$throwNew($NullPointerException, "\'extraUses\' contains null"_s);
	}
	$var($Map, tmpProvides, $new($HashMap));
	{
		$var($Iterator, i$, $nc($($nc(extraProvides)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$Class* service = $cast($Class, $nc(e)->getKey());
				if (service == nullptr) {
					$throwNew($NullPointerException, "\'extraProvides\' contains null"_s);
				}
				$var($List, providers, $new($ArrayList, $cast($Collection, $(e->getValue()))));
				if (providers->isEmpty()) {
					$throwNew($IllegalArgumentException, "list of providers is empty"_s);
				}
				providers->forEach(static_cast<$Consumer*>($$new(InstrumentationImpl$$Lambda$lambda$redefineModule$0, module, service)));
				tmpProvides->put(service, providers);
			}
		}
	}
	$assign(extraProvides, tmpProvides);
	extraReads->forEach(static_cast<$Consumer*>($$new(InstrumentationImpl$$Lambda$lambda$redefineModule$1$1, module)));
	{
		$var($Iterator, i$, $nc($($nc(extraExports)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($String, pkg, $cast($String, $nc(e)->getKey()));
				$var($Set, targets, $cast($Set, e->getValue()));
				$nc(targets)->forEach(static_cast<$Consumer*>($$new(InstrumentationImpl$$Lambda$lambda$redefineModule$2$2, module, pkg)));
			}
		}
	}
	{
		$var($Iterator, i$, $nc($($nc(extraOpens)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($String, pkg, $cast($String, $nc(e)->getKey()));
				$var($Set, targets, $cast($Set, e->getValue()));
				$nc(targets)->forEach(static_cast<$Consumer*>($$new(InstrumentationImpl$$Lambda$lambda$redefineModule$3$3, module, pkg)));
			}
		}
	}
	extraUses->forEach(static_cast<$Consumer*>($$new(InstrumentationImpl$$Lambda$lambda$redefineModule$4$4, module)));
	{
		$var($Iterator, i$, $nc($(extraProvides->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$Class* service = $cast($Class, $nc(e)->getKey());
				$var($List, providers, $cast($List, e->getValue()));
				$nc(providers)->forEach(static_cast<$Consumer*>($$new(InstrumentationImpl$$Lambda$lambda$redefineModule$5$5, module, service)));
			}
		}
	}
}

$Map* InstrumentationImpl::cloneAndCheckMap($Module* module, $Map* map) {
	$useLocalCurrentObjectStackCache();
	if ($nc(map)->isEmpty()) {
		return $Collections::emptyMap();
	}
	$var($Map, result, $new($HashMap));
	$var($Set, packages, $nc(module)->getPackages());
	{
		$var($Iterator, i$, $nc($($nc(map)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				$var($String, pkg, $cast($String, $nc(e)->getKey()));
				if (pkg == nullptr) {
					$throwNew($NullPointerException, "package cannot be null"_s);
				}
				if (!$nc(packages)->contains(pkg)) {
					$throwNew($IllegalArgumentException, $$str({pkg, " not in module"_s}));
				}
				$var($Set, targets, $new($HashSet, $cast($Collection, $(e->getValue()))));
				if (targets->isEmpty()) {
					$throwNew($IllegalArgumentException, "set of targets is empty"_s);
				}
				if (targets->contains(nullptr)) {
					$throwNew($NullPointerException, "set of targets cannot include null"_s);
				}
				result->put(pkg, targets);
			}
		}
	}
	return result;
}

$TransformerManager* InstrumentationImpl::findTransformerManager($ClassFileTransformer* transformer) {
	if ($nc(this->mTransformerManager)->includesTransformer(transformer)) {
		return this->mTransformerManager;
	}
	if (this->mRetransfomableTransformerManager != nullptr && $nc(this->mRetransfomableTransformerManager)->includesTransformer(transformer)) {
		return this->mRetransfomableTransformerManager;
	}
	return nullptr;
}

bool InstrumentationImpl::isModifiableClass0(int64_t nativeAgent, $Class* theClass) {
	bool $ret = false;
	$prepareNative(InstrumentationImpl, isModifiableClass0, bool, int64_t nativeAgent, $Class* theClass);
	$ret = $invokeNative(InstrumentationImpl, isModifiableClass0, nativeAgent, theClass);
	$finishNative();
	return $ret;
}

bool InstrumentationImpl::isRetransformClassesSupported0(int64_t nativeAgent) {
	bool $ret = false;
	$prepareNative(InstrumentationImpl, isRetransformClassesSupported0, bool, int64_t nativeAgent);
	$ret = $invokeNative(InstrumentationImpl, isRetransformClassesSupported0, nativeAgent);
	$finishNative();
	return $ret;
}

void InstrumentationImpl::setHasTransformers(int64_t nativeAgent, bool has) {
	$prepareNative(InstrumentationImpl, setHasTransformers, void, int64_t nativeAgent, bool has);
	$invokeNative(InstrumentationImpl, setHasTransformers, nativeAgent, has);
	$finishNative();
}

void InstrumentationImpl::setHasRetransformableTransformers(int64_t nativeAgent, bool has) {
	$prepareNative(InstrumentationImpl, setHasRetransformableTransformers, void, int64_t nativeAgent, bool has);
	$invokeNative(InstrumentationImpl, setHasRetransformableTransformers, nativeAgent, has);
	$finishNative();
}

void InstrumentationImpl::retransformClasses0(int64_t nativeAgent, $ClassArray* classes) {
	$prepareNative(InstrumentationImpl, retransformClasses0, void, int64_t nativeAgent, $ClassArray* classes);
	$invokeNative(InstrumentationImpl, retransformClasses0, nativeAgent, classes);
	$finishNative();
}

void InstrumentationImpl::redefineClasses0(int64_t nativeAgent, $ClassDefinitionArray* definitions) {
	$prepareNative(InstrumentationImpl, redefineClasses0, void, int64_t nativeAgent, $ClassDefinitionArray* definitions);
	$invokeNative(InstrumentationImpl, redefineClasses0, nativeAgent, definitions);
	$finishNative();
}

$ClassArray* InstrumentationImpl::getAllLoadedClasses0(int64_t nativeAgent) {
	$var($ClassArray, $ret, nullptr);
	$prepareNative(InstrumentationImpl, getAllLoadedClasses0, $ClassArray*, int64_t nativeAgent);
	$assign($ret, $invokeNative(InstrumentationImpl, getAllLoadedClasses0, nativeAgent));
	$finishNative();
	return $ret;
}

$ClassArray* InstrumentationImpl::getInitiatedClasses0(int64_t nativeAgent, $ClassLoader* loader) {
	$var($ClassArray, $ret, nullptr);
	$prepareNative(InstrumentationImpl, getInitiatedClasses0, $ClassArray*, int64_t nativeAgent, $ClassLoader* loader);
	$assign($ret, $invokeNative(InstrumentationImpl, getInitiatedClasses0, nativeAgent, loader));
	$finishNative();
	return $ret;
}

int64_t InstrumentationImpl::getObjectSize0(int64_t nativeAgent, Object$* objectToSize) {
	int64_t $ret = 0;
	$prepareNative(InstrumentationImpl, getObjectSize0, int64_t, int64_t nativeAgent, Object$* objectToSize);
	$ret = $invokeNative(InstrumentationImpl, getObjectSize0, nativeAgent, objectToSize);
	$finishNative();
	return $ret;
}

void InstrumentationImpl::appendToClassLoaderSearch0(int64_t nativeAgent, $String* jarfile, bool bootLoader) {
	$prepareNative(InstrumentationImpl, appendToClassLoaderSearch0, void, int64_t nativeAgent, $String* jarfile, bool bootLoader);
	$invokeNative(InstrumentationImpl, appendToClassLoaderSearch0, nativeAgent, jarfile, bootLoader);
	$finishNative();
}

void InstrumentationImpl::setNativeMethodPrefixes(int64_t nativeAgent, $StringArray* prefixes, bool isRetransformable) {
	$prepareNative(InstrumentationImpl, setNativeMethodPrefixes, void, int64_t nativeAgent, $StringArray* prefixes, bool isRetransformable);
	$invokeNative(InstrumentationImpl, setNativeMethodPrefixes, nativeAgent, prefixes, isRetransformable);
	$finishNative();
}

void InstrumentationImpl::setAccessible($AccessibleObject* ao, bool accessible) {
	$init(InstrumentationImpl);
	$beforeCallerSensitive();
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($InstrumentationImpl$1, ao, accessible)));
}

void InstrumentationImpl::loadClassAndStartAgent($String* classname, $String* methodname, $String* optionsString) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ClassLoader, mainAppLoader, $ClassLoader::getSystemClassLoader());
	$Class* javaAgentClass = $nc(mainAppLoader)->loadClass(classname);
	$var($Method, m, nullptr);
	$var($NoSuchMethodException, firstExc, nullptr);
	bool twoArgAgent = false;
	try {
		$load($Instrumentation);
		$assign(m, $nc(javaAgentClass)->getDeclaredMethod(methodname, $$new($ClassArray, {
			$String::class$,
			$Instrumentation::class$
		})));
		twoArgAgent = true;
	} catch ($NoSuchMethodException& x) {
		$assign(firstExc, x);
	}
	if (m == nullptr) {
		try {
			$assign(m, $nc(javaAgentClass)->getDeclaredMethod(methodname, $$new($ClassArray, {$String::class$})));
		} catch ($NoSuchMethodException& x) {
			$throw(firstExc);
		}
	}
	if (!$Modifier::isPublic($nc(m)->getModifiers())) {
		$var($String, msg, $str({"method "_s, classname, "."_s, methodname, " must be declared public"_s}));
		$throwNew($IllegalAccessException, msg);
	}
	bool var$0 = !$Modifier::isPublic($nc(javaAgentClass)->getModifiers());
	if (var$0 && !$nc($($nc(javaAgentClass)->getModule()))->isNamed()) {
		setAccessible(m, true);
	}
	if (twoArgAgent) {
		$nc(m)->invoke(nullptr, $$new($ObjectArray, {
			$of(optionsString),
			$of(this)
		}));
	} else {
		$nc(m)->invoke(nullptr, $$new($ObjectArray, {$of(optionsString)}));
	}
}

void InstrumentationImpl::loadClassAndCallPremain($String* classname, $String* optionsString) {
	loadClassAndStartAgent(classname, "premain"_s, optionsString);
}

void InstrumentationImpl::loadClassAndCallAgentmain($String* classname, $String* optionsString) {
	loadClassAndStartAgent(classname, "agentmain"_s, optionsString);
}

$bytes* InstrumentationImpl::transform($Module* module$renamed, $ClassLoader* loader, $String* classname, $Class* classBeingRedefined, $ProtectionDomain* protectionDomain, $bytes* classfileBuffer, bool isRetransformer) {
	$useLocalCurrentObjectStackCache();
	$var($Module, module, module$renamed);
	$var($TransformerManager, mgr, isRetransformer ? this->mRetransfomableTransformerManager : this->mTransformerManager);
	if (module == nullptr) {
		if (classBeingRedefined != nullptr) {
			$assign(module, classBeingRedefined->getModule());
		} else {
			$assign(module, (loader == nullptr) ? $BootLoader::getUnnamedModule() : $nc(loader)->getUnnamedModule());
		}
	}
	if (mgr == nullptr) {
		return nullptr;
	} else {
		return $nc(mgr)->transform(module, loader, classname, classBeingRedefined, protectionDomain, classfileBuffer);
	}
}

void InstrumentationImpl::loadAgent($String* path) {
	$init(InstrumentationImpl);
	loadAgent0(path);
}

void InstrumentationImpl::loadAgent0($String* path) {
	$init(InstrumentationImpl);
	$prepareNativeStatic(InstrumentationImpl, loadAgent0, void, $String* path);
	$invokeNativeStatic(InstrumentationImpl, loadAgent0, path);
	$finishNativeStatic();
}

void InstrumentationImpl::lambda$redefineModule$5($Module* module, $Class* service, $Class* p) {
	$init(InstrumentationImpl);
	$Modules::addProvides(module, service, p);
}

void InstrumentationImpl::lambda$redefineModule$4($Module* module, $Class* service) {
	$init(InstrumentationImpl);
	$Modules::addUses(module, service);
}

void InstrumentationImpl::lambda$redefineModule$3($Module* module, $String* pkg, $Module* m) {
	$init(InstrumentationImpl);
	$Modules::addOpens(module, pkg, m);
}

void InstrumentationImpl::lambda$redefineModule$2($Module* module, $String* pkg, $Module* m) {
	$init(InstrumentationImpl);
	$Modules::addExports(module, pkg, m);
}

void InstrumentationImpl::lambda$redefineModule$1($Module* module, $Module* m) {
	$init(InstrumentationImpl);
	$Modules::addReads(module, m);
}

void InstrumentationImpl::lambda$redefineModule$0($Module* module, $Class* service, $Class* p) {
	$init(InstrumentationImpl);
	$useLocalCurrentObjectStackCache();
	if ($nc(p)->getModule() != module) {
		$throwNew($IllegalArgumentException, $$str({p, " not in "_s, module}));
	}
	if (!$nc(service)->isAssignableFrom(p)) {
		$throwNew($IllegalArgumentException, $$str({p, " is not a "_s, service}));
	}
}

void clinit$InstrumentationImpl($Class* class$) {
	$beforeCallerSensitive();
	{
		$System::loadLibrary("instrument"_s);
	}
}

InstrumentationImpl::InstrumentationImpl() {
}

$Class* InstrumentationImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(InstrumentationImpl$$Lambda$lambda$redefineModule$0::classInfo$.name)) {
			return InstrumentationImpl$$Lambda$lambda$redefineModule$0::load$(name, initialize);
		}
		if (name->equals(InstrumentationImpl$$Lambda$lambda$redefineModule$1$1::classInfo$.name)) {
			return InstrumentationImpl$$Lambda$lambda$redefineModule$1$1::load$(name, initialize);
		}
		if (name->equals(InstrumentationImpl$$Lambda$lambda$redefineModule$2$2::classInfo$.name)) {
			return InstrumentationImpl$$Lambda$lambda$redefineModule$2$2::load$(name, initialize);
		}
		if (name->equals(InstrumentationImpl$$Lambda$lambda$redefineModule$3$3::classInfo$.name)) {
			return InstrumentationImpl$$Lambda$lambda$redefineModule$3$3::load$(name, initialize);
		}
		if (name->equals(InstrumentationImpl$$Lambda$lambda$redefineModule$4$4::classInfo$.name)) {
			return InstrumentationImpl$$Lambda$lambda$redefineModule$4$4::load$(name, initialize);
		}
		if (name->equals(InstrumentationImpl$$Lambda$lambda$redefineModule$5$5::classInfo$.name)) {
			return InstrumentationImpl$$Lambda$lambda$redefineModule$5$5::load$(name, initialize);
		}
	}
	$loadClass(InstrumentationImpl, name, initialize, &_InstrumentationImpl_ClassInfo_, clinit$InstrumentationImpl, allocate$InstrumentationImpl);
	return class$;
}

$Class* InstrumentationImpl::class$ = nullptr;

	} // instrument
} // sun