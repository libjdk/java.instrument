#include <java/lang/instrument/ClassDefinition.h>

#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;

namespace java {
	namespace lang {
		namespace instrument {

$FieldInfo _ClassDefinition_FieldInfo_[] = {
	{"mClass", "Ljava/lang/Class;", "Ljava/lang/Class<*>;", $PRIVATE | $FINAL, $field(ClassDefinition, mClass)},
	{"mClassFile", "[B", nullptr, $PRIVATE | $FINAL, $field(ClassDefinition, mClassFile)},
	{}
};

$MethodInfo _ClassDefinition_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/Class;[B)V", "(Ljava/lang/Class<*>;[B)V", $PUBLIC, $method(static_cast<void(ClassDefinition::*)($Class*,$bytes*)>(&ClassDefinition::init$))},
	{"getDefinitionClass", "()Ljava/lang/Class;", "()Ljava/lang/Class<*>;", $PUBLIC, $method(static_cast<$Class*(ClassDefinition::*)()>(&ClassDefinition::getDefinitionClass))},
	{"getDefinitionClassFile", "()[B", nullptr, $PUBLIC, $method(static_cast<$bytes*(ClassDefinition::*)()>(&ClassDefinition::getDefinitionClassFile))},
	{}
};

$ClassInfo _ClassDefinition_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.lang.instrument.ClassDefinition",
	"java.lang.Object",
	nullptr,
	_ClassDefinition_FieldInfo_,
	_ClassDefinition_MethodInfo_
};

$Object* allocate$ClassDefinition($Class* clazz) {
	return $of($alloc(ClassDefinition));
}

void ClassDefinition::init$($Class* theClass, $bytes* theClassFile) {
	if (theClass == nullptr || theClassFile == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, mClass, theClass);
	$set(this, mClassFile, theClassFile);
}

$Class* ClassDefinition::getDefinitionClass() {
	return this->mClass;
}

$bytes* ClassDefinition::getDefinitionClassFile() {
	return this->mClassFile;
}

ClassDefinition::ClassDefinition() {
}

$Class* ClassDefinition::load$($String* name, bool initialize) {
	$loadClass(ClassDefinition, name, initialize, &_ClassDefinition_ClassInfo_, allocate$ClassDefinition);
	return class$;
}

$Class* ClassDefinition::class$ = nullptr;

		} // instrument
	} // lang
} // java