#include <java/lang/instrument/UnmodifiableClassException.h>

#include <java/lang/Class.h>
#include <java/lang/ClassInfo.h>
#include <java/lang/Exception.h>
#include <java/lang/FieldInfo.h>
#include <java/lang/MethodInfo.h>
#include <java/lang/String.h>
#include <java/lang/reflect/Constructor.h>
#include <java/lang/reflect/Method.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace java {
	namespace lang {
		namespace instrument {

$FieldInfo _UnmodifiableClassException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(UnmodifiableClassException, serialVersionUID)},
	{}
};

$MethodInfo _UnmodifiableClassException_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(UnmodifiableClassException::*)()>(&UnmodifiableClassException::init$))},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(UnmodifiableClassException::*)($String*)>(&UnmodifiableClassException::init$))},
	{}
};

$ClassInfo _UnmodifiableClassException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.lang.instrument.UnmodifiableClassException",
	"java.lang.Exception",
	nullptr,
	_UnmodifiableClassException_FieldInfo_,
	_UnmodifiableClassException_MethodInfo_
};

$Object* allocate$UnmodifiableClassException($Class* clazz) {
	return $of($alloc(UnmodifiableClassException));
}

void UnmodifiableClassException::init$() {
	$Exception::init$();
}

void UnmodifiableClassException::init$($String* s) {
	$Exception::init$(s);
}

UnmodifiableClassException::UnmodifiableClassException() {
}

UnmodifiableClassException::UnmodifiableClassException(const UnmodifiableClassException& e) {
}

UnmodifiableClassException UnmodifiableClassException::wrapper$() {
	$pendingException(this);
	return *this;
}

void UnmodifiableClassException::throwWrapper$() {
	$pendingException(this);
	throw *this;
}

$Class* UnmodifiableClassException::load$($String* name, bool initialize) {
	$loadClass(UnmodifiableClassException, name, initialize, &_UnmodifiableClassException_ClassInfo_, allocate$UnmodifiableClassException);
	return class$;
}

$Class* UnmodifiableClassException::class$ = nullptr;

		} // instrument
	} // lang
} // java