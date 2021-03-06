# yuca v0.1.1
<img src="https://i.imgur.com/zZvZ9kK.png"/>

**Yuca: A light-weight, in-memory, fast and simple to use search engine library.**

If your app can't handle or doesn't really need installing a full featured and heavy search engine like Lucene, nor you want to depend on a SQL database for indexing and doing simple search based strings you can use Yuca to index documents under any number of arbitrary keys which can be grouped under tags.

The shared library currently weighs ~170kb without any packing optimizations, we hope to reduce the size further in the near future.

## BUILDING

Requirements:
 - cmake 3.8, make
 - C++11 compiler (clang recommended)

Instructions:

The first time, create your Makefile with cmake
```
$ cmake .
```
then after that just build
```
$ make -j 8
```

Shared and static libraries will be available on the root folder of the project, as well as `yuca_demo_shared` and `yuca_demo_static` executables you can use to test that everything has been compiled and linked correctly with both the shared and dynamic libraries.

There's a also `yuca_tests` executable in case you want to make sure all the unit tests are passing.

## BUILDING JAVA (SWIG/JNI) WRAPPER

The `swig` folder holds swig scripts and high level wrappers to use yuca from other programming languages, the first being `java`.

The current intention is to have the `swig/build.sh` be a one step build process to create bindings for other languages.

For now it's a very rough script that will create java bindings, currently supports bindings for Java on MacOS since we're still early in the development of the bindings. In the long run, options will be passed to build.sh to output bindings for the language and architecture of your choice.

To build JNI bingings, fist make sure to have built the C++ library as explained in the previous build instructions section and then:

```
$ cd swig
$ ./build.sh
```

This will output programatically created C++ JNI code and Java code to access the JNI native wrappers inside a `swig/java` folder. In there we have a java package which is Java Programmer friendly `com.guacal.yuca.*` In there you will find the main classes to use Yuca in your Java/Android app `Indexer`, `Document`, `StringKey`, `SearchRequest`, `SearchResult`.

## Debug Build

If you want to build libraries with debug symbols edit `CMakeLists.txt` and uncomment the `CMAKE_BUILD_TYPE` setting, 
```
# If you need step by step debugging, uncomment below,
# or invoke `cmake -DCMAKE_BUILD_TYPE=Debug .` in the command line
#set(CMAKE_BUILD_TYPE Debug)
```

you will have to execute `cmake .` again, perform a `make clean` and rebuild with `make -j 8`


 
## Feedback and patches welcome
 
 Please open an issue on the github issue tracker if you have any problems, ideas.
 If you feel like extending or patching, please open an issue first so that you don't waste your time coding something that might not be accepted for a good reason.

## Not supported for now
 - Index serialization. For now the index is only meant to be used in-memory. Will have to think deeply on how to go
   about this in an incremental/decremental manner so that serialization is optimal and we don't have to save the entire
   index every time. Not a priority at this moment.

### LIBRARY BINARY DISTRIBUTION GOALS:
 - static library: yuca.lib (windows x64), yuca.a (linux x64, mac x64)
 - shared library: yuca.dll (windows x64), yuca.so (linux x64, android arm, android arm64), yuca.dylib (mac x64)

### LIBRARY BINDING COMPATIBILITY GOALS:
 - JNI/Java SE bindings, yuca.jar (windows x64, linux x64, mac x64)
 - JNI/Android bindings, yuca.jar (arm, arm64)
 - Javascript/NodeJS bindings
 - Python bindings
 - Go bindings
 - PHP bindings
 
 *This project is available under The MIT License, Released publicly Wed. May 9th of 2018*
