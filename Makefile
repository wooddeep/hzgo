.PHONY: clean hz clean

TARGET=foo

JVM_LIB_PATH = $(JAVA_HOME)/jre/lib/server

LDFLAGS = -L ${JVM_LIB_PATH} -ljvm 

$(TARGET): libfoo.a
	go build .

libfoo.a: foo.o cfoo.o foo.go
	ar r $@ $^

%.o: %.cpp
	g++  -O2 -o $@ -c $^

hz: 
	cd java && mvn compile && cd ..
	cp -r java/target/classes/com ./

run:
	@export LD_LIBRARY_PATH=${JVM_LIB_PATH};./foo

clean:
	rm -f *.o *.so *.a $(TARGET)
	rm -fr com
	cd java && mvn clean
