#include <java/lang/instrument/IllegalClassFormatException.h>

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

$FieldInfo _IllegalClassFormatException_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(IllegalClassFormatException, serialVersionUID)},
	{}
};

$MethodInfo _IllegalClassFormatException_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(IllegalClassFormatException::*)()>(&IllegalClassFormatException::init$))},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(IllegalClassFormatException::*)($String*)>(&IllegalClassFormatException::init$))},
	{}
};

$ClassInfo _IllegalClassFormatException_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.lang.instrument.IllegalClassFormatException",
	"java.lang.Exception",
	nullptr,
	_IllegalClassFormatException_FieldInfo_,
	_IllegalClassFormatException_MethodInfo_
};

$Object* allocate$IllegalClassFormatException($Class* clazz) {
	return $of($alloc(IllegalClassFormatException));
}

void IllegalClassFormatException::init$() {
	$Exception::init$();
}

void IllegalClassFormatException::init$($String* s) {
	$Exception::init$(s);
}

IllegalClassFormatException::IllegalClassFormatException() {
}

IllegalClassFormatException::IllegalClassFormatException(const IllegalClassFormatException& e) {
}

IllegalClassFormatException IllegalClassFormatException::wrapper$() {
	$pendingException(this);
	return *this;
}

void IllegalClassFormatException::throwWrapper$() {
	$pendingException(this);
	throw *this;
}

$Class* IllegalClassFormatException::load$($String* name, bool initialize) {
	$loadClass(IllegalClassFormatException, name, initialize, &_IllegalClassFormatException_ClassInfo_, allocate$IllegalClassFormatException);
	return class$;
}

$Class* IllegalClassFormatException::class$ = nullptr;

		} // instrument
	} // lang
} // java