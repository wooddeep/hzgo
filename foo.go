package main

// //please replace the relative path about your env!
// //#cgo CFLAGS: -I . -I/Library/Java/JavaVirtualMachines/jdk1.8.0_60.jdk/Contents/Home/include -I/Library/Java/JavaVirtualMachines/jdk1.8.0_60.jdk/Contents/Home/include/darwin
// #cgo LDFLAGS: -L . -L /Library/Java/JavaVirtualMachines/jdk1.8.0_60.jdk/Contents/Home/jre/lib/server -ljvm
// #include "foo.h"
import "C"

import (
	"fmt"
	"os"
	"path/filepath"
)

type GoFoo struct {
	foo C.Foo
}

func New() GoFoo {
	var ret GoFoo
	ret.foo = C.FooInit()
	return ret
}
func (f GoFoo) Free() {
	C.FooFree(f.foo)
}
func (f GoFoo) Bar() {
	C.FooBar(f.foo)
}
func (f GoFoo) Action(path *C.char) {
	C.FooAction(f.foo, path)
}

func main() {
	dir, _ := filepath.Abs(filepath.Dir(os.Args[0]))
	classPath := fmt.Sprintf("-Djava.class.path=.:%s/%s", dir, "hazelcast-3.8.2.jar")
	foo := New()
	foo.Bar()
	foo.Action(C.CString(classPath))
	foo.Free()
}
