
![chigraph logo](doc/images/chigraph.png)

[![Coveralls](https://img.shields.io/coveralls/chigraph/chigraph.svg?style=flat-square)](https://coveralls.io/github/chigraph/chigraph)    [![Gitter](https://img.shields.io/gitter/room/nwjs/nw.js.svg?style=flat-square)](https://gitter.im/chigraph/)


__Build Status__

Platform | Status
----- |  ---- 
| Linux/macOS    | [![Travis branch](https://img.shields.io/travis/chigraph/chigraph/master.svg?style=flat-square)](https://travis-ci.org/chigraph/chigraph) |
| Windows           |  [![AppVeyor](https://img.shields.io/appveyor/ci/guapotaco/chigraph-miekk.svg?style=flat-square)](https://ci.appveyor.com/project/GuapoTaco/chigraph-miekk) |


# What is chigraph?
Chigraph,  pronunced chai-graph, is a new systems programming language. It's fast. It's scalable. And, more importantly, it's easy to learn. How does it achieve such goals? By scrapping the age-old standard of text (not entirely though).

![Screenshot](doc/screenshots/HelloWorld.png)

# Components
Chigraph is made up of three components:

##libchig
Libchig is the chigraph library that provides all functions for chigraph clients, like code generation, graph representation, etc. Want to compile a chigraph module using libchig?

```C++
#include <chig/Context.hpp>

int main() {
    chig::Contxt myContext{"/path/to/workspace"};
	myContxt.loadModule("github.com/russelltg/hellochigraph");
	
	llvm::Module* mod;
	myContxt.compileModule("github.com/russelltg/hellochigraph", &mod);
}
```

And tada, you have yourself a [`llvm::Module`](http://llvm.org/docs/doxygen/html/classllvm_1_1Module.html) to do whatever you wish to. It'll have all it's dependencies linked in and a main function waiting to run.

##chig
chig is the command line interface to chigraph. It lets you compile and run chigraph modules:
```bash
$ pwd
~/chigrpah/src/github.com/russelltg/hellochigraph
$ chig run hellochigraph.chigmod
Hello World!
```

##chiggui
Chiggui is the graphical user interface for writing chigraph modules, written in Qt5 and KF5. It's cross-platform, easy to use, and simple. 

![screenshot](doc/screenshots/if.png)

# Licensing
It's free!
Chigraph is licensed under the [Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0) so anyone can use it for free, even in proprietary settings (solong you attribute me)

# Documentation
Documentation is hosted on github pages, [here](https://chigraph.github.io/chigraph).

# Installation

##Download installers/appimage
Installers and appimages are avaliable from the [releases page](https://github.com/chigraph/chigraph/releases) (coming soon) for those who don't want to build from sources.

##Building from source
See the [guide on building from source](doc/building.md)

# Get Involved
Getting involved is easy!
If you don't know where to get started, start looking at [filed github issues](https://github.com/chigraph/chigraph/issues) for inspiration. Then just file a PR!

If you have any questions, you're more than welcome to email me: [russellgreene8@gmail.com](mailto:russellgreene8@gmail.com)

# Authors

- Russell Greene (@russelltg) - Main contributor
- Aun-Ali Zaidi (@aunali1) - Helped with some platform stuff

> Written with [StackEdit](https://stackedit.io/).
