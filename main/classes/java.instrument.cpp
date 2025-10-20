#include <java.instrument.h>

#include <java.base.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>
#include <module-info>

#include <java/lang/instrument/ClassDefinition.h>
#include <java/lang/instrument/ClassFileTransformer.h>
#include <java/lang/instrument/IllegalClassFormatException.h>
#include <java/lang/instrument/Instrumentation.h>
#include <java/lang/instrument/UnmodifiableClassException.h>
#include <java/lang/instrument/UnmodifiableModuleException.h>
#include <sun/instrument/InstrumentationImpl.h>
#include <sun/instrument/InstrumentationImpl$1.h>
#include <sun/instrument/TransformerManager.h>
#include <sun/instrument/TransformerManager$TransformerInfo.h>


#define $classEntry(name, clazz) {name, clazz::load$, $getMark(clazz)}
::java::lang::ClassEntry _java$instrument_classes_[] = {
	$classEntry("java.lang.instrument.ClassDefinition", ::java::lang::instrument::ClassDefinition),
	$classEntry("java.lang.instrument.ClassFileTransformer", ::java::lang::instrument::ClassFileTransformer),
	$classEntry("java.lang.instrument.IllegalClassFormatException", ::java::lang::instrument::IllegalClassFormatException),
	$classEntry("java.lang.instrument.Instrumentation", ::java::lang::instrument::Instrumentation),
	$classEntry("java.lang.instrument.UnmodifiableClassException", ::java::lang::instrument::UnmodifiableClassException),
	$classEntry("java.lang.instrument.UnmodifiableModuleException", ::java::lang::instrument::UnmodifiableModuleException),
	$classEntry("sun.instrument.InstrumentationImpl", ::sun::instrument::InstrumentationImpl),
	$classEntry("sun.instrument.InstrumentationImpl$1", ::sun::instrument::InstrumentationImpl$1),
	$classEntry("sun.instrument.TransformerManager", ::sun::instrument::TransformerManager),
	$classEntry("sun.instrument.TransformerManager$TransformerInfo", ::sun::instrument::TransformerManager$TransformerInfo)
};

const char* _java$instrument_packages_[] = {
	"java.lang.instrument",
	"sun.instrument"
};

void java$instrument$PreloadClass(void* eventData) {
	::java::lang::PreloadClassEvent* event = (::java::lang::PreloadClassEvent*)eventData;
	int32_t length = $lengthOf(_java$instrument_classes_);
	for (int i = 0; i < length; i++) {
		::java::lang::ClassEntry* classEntry = &_java$instrument_classes_[i];
		if (event->preinit) {
			if ($hasFlag(classEntry->mark, $PREINIT)) {
				classEntry->loader(nullptr, true);
				continue;
			}
		}
		if (event->preload) {
			if ($hasFlag(classEntry->mark, $PRELOAD) || $hasFlag(classEntry->mark, $PREINIT)) {
				classEntry->loader(nullptr, false);
			}
		}
	}
}

void java$instrument$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$instrument$PreloadClass(eventData);
	}
	if (eventType == JCPP_LIB_EVENT_TYPE_THREAD_START) {
		$onLibThreadStart(eventData);
	}
}

$StringArray* java$instrument$GetPackages() {
	int32_t length = $lengthOf(_java$instrument_packages_);
	$var($StringArray, packages, $new($StringArray, length));
	for (int32_t i = 0; i < length; i++) {
		packages->set(i, $str(_java$instrument_packages_[i]));
	}
	return packages;
}

::java::lang::ClassEntry* java$instrument$GetClassEntry($String* name) {
	int32_t begin = 0;
	int32_t end = $lengthOf(_java$instrument_classes_) - 1;
	while (begin <= end) {
		int32_t mid = begin + (end - begin) / 2;
		::java::lang::ClassEntry* classEntry = &_java$instrument_classes_[mid];
		int32_t ret = name->compareTo(classEntry->name);
		if (ret < 0) {
			end = mid - 1;
		} else if (ret > 0) {
			begin = mid + 1;
		} else {
			return classEntry;
		}
	}
	return nullptr;
}

$bytes* java$instrument$GetResource($String* name) {
	return nullptr;
}

void java$instrument::init() {
	::java$base::init();
	::java::lang::Library lib = {
		"java.instrument", "17.35", "",
		&_java$instrument_ModuleInfo_,
		java$instrument$LibEventAction,
		java$instrument$GetPackages,
		java$instrument$GetClassEntry,
		java$instrument$GetResource
	};
	$System::addLibrary(&lib);
}