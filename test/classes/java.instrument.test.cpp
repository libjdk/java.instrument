#include <java.instrument.test.h>

#include <java.instrument.h>
#include <java.base.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>

void java$instrument$test$PreloadClass(void* eventData) {
}

void java$instrument$test$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$instrument$test$PreloadClass(eventData);
	}
	if (eventType == JCPP_LIB_EVENT_TYPE_THREAD_START) {
		$onLibThreadStart(eventData);
	}
}

$StringArray* java$instrument$test$GetPackages() {
	return nullptr;
}

::java::lang::ClassEntry* java$instrument$test$GetClassEntry($String* name) {
	return nullptr;
}

$bytes* java$instrument$test$GetResource($String* name) {
	return nullptr;
}

void java$instrument$test::init() {
	::java$instrument::init();
	::java$base::init();
	::java::lang::Library lib = {
		"java.instrument.test", "17.35", "",
		nullptr,
		java$instrument$test$LibEventAction,
		java$instrument$test$GetPackages,
		java$instrument$test$GetClassEntry,
		java$instrument$test$GetResource
	};
	$System::addLibrary(&lib);
	$System::init();
}