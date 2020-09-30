## Dynamic Array

*Learning purposes only. =D*

A simple and naive implementation of a resizable array in C.

### Running tests

This project uses [Meson](https://mesonbuild.com/Quick-guide.html).

After cloning:

```bash
$ meson builddir
```

It will generate the `buildir`, then you can run the tests:

```bash
$ meson test -C builddir/ -v 
```

Testing using Valgrind (a tool to find memory leaks):

```bash
$ meson test -C builddir/ -v --wrap=valgrind
```

### What see next?

- [Doubly-linked list](https://github.com/KennedyTedesco/doubly-linked-list) and its iterator
