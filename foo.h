#ifndef _MY_PACKAGE_FOO_H_
#define _MY_PACKAGE_FOO_H_

#ifdef __cplusplus
extern "C" {
#endif

	typedef void* Foo;
	Foo FooInit(void);
	void FooFree(Foo);
	void FooBar(Foo);
	void FooAction(Foo, char*);

#ifdef __cplusplus
}
#endif

#endif
