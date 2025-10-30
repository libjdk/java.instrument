#include <sun/instrument/InstrumentationImpl$1.h>

#include <java/lang/reflect/AccessibleObject.h>
#include <sun/instrument/InstrumentationImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessibleObject = ::java::lang::reflect::AccessibleObject;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $InstrumentationImpl = ::sun::instrument::InstrumentationImpl;

namespace sun {
	namespace instrument {

$FieldInfo _InstrumentationImpl$1_FieldInfo_[] = {
	{"val$accessible", "Z", nullptr, $FINAL | $SYNTHETIC, $field(InstrumentationImpl$1, val$accessible)},
	{"val$ao", "Ljava/lang/reflect/AccessibleObject;", nullptr, $FINAL | $SYNTHETIC, $field(InstrumentationImpl$1, val$ao)},
	{}
};

$MethodInfo _InstrumentationImpl$1_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/reflect/AccessibleObject;Z)V", "()V", 0, $method(static_cast<void(InstrumentationImpl$1::*)($AccessibleObject*,bool)>(&InstrumentationImpl$1::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _InstrumentationImpl$1_EnclosingMethodInfo_ = {
	"sun.instrument.InstrumentationImpl",
	"setAccessible",
	"(Ljava/lang/reflect/AccessibleObject;Z)V"
};

$InnerClassInfo _InstrumentationImpl$1_InnerClassesInfo_[] = {
	{"sun.instrument.InstrumentationImpl$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _InstrumentationImpl$1_ClassInfo_ = {
	$ACC_SUPER,
	"sun.instrument.InstrumentationImpl$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_InstrumentationImpl$1_FieldInfo_,
	_InstrumentationImpl$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Object;>;",
	&_InstrumentationImpl$1_EnclosingMethodInfo_,
	_InstrumentationImpl$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.instrument.InstrumentationImpl"
};

$Object* allocate$InstrumentationImpl$1($Class* clazz) {
	return $of($alloc(InstrumentationImpl$1));
}

void InstrumentationImpl$1::init$($AccessibleObject* val$ao, bool val$accessible) {
	$set(this, val$ao, val$ao);
	this->val$accessible = val$accessible;
}

$Object* InstrumentationImpl$1::run() {
	$beforeCallerSensitive();
	$nc(this->val$ao)->setAccessible(this->val$accessible);
	return $of(nullptr);
}

InstrumentationImpl$1::InstrumentationImpl$1() {
}

$Class* InstrumentationImpl$1::load$($String* name, bool initialize) {
	$loadClass(InstrumentationImpl$1, name, initialize, &_InstrumentationImpl$1_ClassInfo_, allocate$InstrumentationImpl$1);
	return class$;
}

$Class* InstrumentationImpl$1::class$ = nullptr;

	} // instrument
} // sun