#include "foo.hpp"
#include "foo.h"

#include "jni.h"
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int HelloWorld(char* p) {
    JavaVMOption options[1]; // A list of options to build a JVM from C++
    JNIEnv *env;
    JavaVM *jvm;
    JavaVMInitArgs vm_args; // Arguments for the JVM (see below)
    jclass cls;
    jmethodID constructor;
    jobject simpleJNITestInstance;

    options[0].optionString = p; //(char *)"-Djava.class.path=.:/Users/lihan/Downloads/ccalljava/hazelcast-3.8.2.jar";

    memset(&vm_args, 0, sizeof(vm_args));
    vm_args.version = JNI_VERSION_1_6;
    vm_args.nOptions = 1;
    vm_args.options = options;

    long status = JNI_CreateJavaVM(&jvm, (void **)&env, &vm_args);

    if (status != JNI_ERR) {
        cls = env->FindClass("com/wooddeep/HZ");
        if (cls != 0) {
            printf("Class found \n");
            constructor = env->GetMethodID(cls, "<init>", "()V");
            if (constructor != 0) {
                printf("Constructor found \n");
                jobject simpleJNITestInstance = env->NewObject(cls, constructor);
                if (simpleJNITestInstance != 0) {
                    printf("Instance created \n");
                    jstring jstr1 = env->NewStringUTF("First string");
                    jstring jstr2 = env->NewStringUTF("Second string");

                    jmethodID addValue = env->GetMethodID(cls, "addValue", "(Ljava/lang/String;)V");
                    env->CallObjectMethod(simpleJNITestInstance, addValue, jstr1);
                    env->CallObjectMethod(simpleJNITestInstance, addValue, jstr1);

                    jmethodID printValues = env->GetMethodID(cls, "printValues", "()V");
                    env->CallObjectMethod(simpleJNITestInstance, printValues);

                    jint listSize;
                    jmethodID getSize = env->GetMethodID(cls, "getSize", "()I");
                    listSize = env->CallIntMethod(simpleJNITestInstance, getSize);

                    printf("#The size of the Java list is: %d\n", listSize);
                }
            } else {
                printf("I could not create constructor\n");
            }
        }

        jvm->DestroyJavaVM();
        printf("All done, bye bye!\n");
        return 0;
    } else {
        return -1;
    }
}

Foo FooInit() {
	cxxFoo * ret = new cxxFoo(1);
	return (void*)ret;
}

void FooFree(Foo f) {
	cxxFoo * foo = (cxxFoo*)f;
	delete foo;
}

void FooBar(Foo f) {
	cxxFoo * foo = (cxxFoo*)f;
	foo->Bar();
}

void FooAction(Foo f, char* p) {
    printf("%s\n", p);
    HelloWorld(p);
}
