# A reformatter for qml

This is a CLI wrapper of the reformatter borrowed from the QtCreator project.
It makes it possible to do shell bashing.

## Get the source

Will also init the qt-creator submodule.
 
```
git clone --recursive https://github.com/labsin/qmljsreformatte
```

# Build

You need to have a full Qt developement installation in your path.

```
mkdir build && cd build
cmake ../
make
```

# Run

`/qmljsreformatter -h` will print out the help file.
