#include <java/lang/instrument/UnmodifiableModuleException.h>

#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;

namespace java {
	namespace lang {
		namespace instrument {

$FieldInfo _UnmodifiableModuleException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnmodifiableModuleException, serialVersionUID)},
	{}
};

$MethodInfo _UnmodifiableModuleException_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(UnmodifiableModuleException::*)()>(&UnmodifiableModuleException::init$))},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(UnmodifiableModuleException::*)($String*)>(&UnmodifiableModuleException::init$))},
	{}
};

$ClassInfo _UnmodifiableModuleException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.lang.instrument.UnmodifiableModuleException",
	"java.lang.RuntimeException",
	nullptr,
	_UnmodifiableModuleException_FieldInfo_,
	_UnmodifiableModuleException_MethodInfo_
};

$Object* allocate$UnmodifiableModuleException($Class* clazz) {
	return $of($alloc(UnmodifiableModuleException));
}

void UnmodifiableModuleException::init$() {
	$RuntimeException::init$();
}

void UnmodifiableModuleException::init$($String* msg) {
	$RuntimeException::init$(msg);
}

UnmodifiableModuleException::UnmodifiableModuleException() {
}

UnmodifiableModuleException::UnmodifiableModuleException(const UnmodifiableModuleException& e) : $RuntimeException(e) {
}

void UnmodifiableModuleException::throw$() {
	throw *this;
}

$Class* UnmodifiableModuleException::load$($String* name, bool initialize) {
	$loadClass(UnmodifiableModuleException, name, initialize, &_UnmodifiableModuleException_ClassInfo_, allocate$UnmodifiableModuleException);
	return class$;
}

$Class* UnmodifiableModuleException::class$ = nullptr;

		} // instrument
	} // lang
} // java