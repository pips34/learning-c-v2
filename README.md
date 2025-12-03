# C course by Kris Jordan

[Course link](https://www.youtube.com/playlist?list=PLKUb7MEve0TjHQSKUWChAWyJPCpYMRovO).

This is my favorite C course, which I am re visiting, because I want to go back
to learning C, and the first time I went through the course I did not complete
it.

The course even introduces VIM to use as an editor and GIT for version control,
so genuinely good stuff for anyone looking to learn C and just intermediate
level programming in general (although I already know VIM / NeoVim and GIT, but
still).

Kris Jordan is a university professor that uploaded some of his content to
YouTube during the 2020 pandemic, so this resource is invaludable. The book
associated with the course, is "The C Programming Language", I might put it in
the repo if I manage to find the PDF (probably not a hard find tbh, since the
book is pretty famous), and there is also a small PDF book that he wrote
himself on how to code a shell, which I might also put in the repo, if I find
it.

## 1. Simple Hello World + Environment setup

The following setup is something I came up with myself, just to have an easier
time working with C.

I am using NeoVim for this, so I added the `clang` LSP to NeoVim to go through
the course, as well as some custom snippets using the `LuaSnip` plugin.

Here's the code for this section:

```c
#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
```

We write this in the file `hello.c` and compile it using `zig` instead of
`gcc`, by going `zig cc`. We also created the alias `zigcc` with include all
the -W\<whatever\> flags, by writting something like this:

```sh
alias zigcc='zig cc -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wstrict-prototypes -Werror'
```

in our `~/.bashrc` file, and I guess it should also work in a `~/.zshrc` file,
if you are using `zsh`.

We also create the directory `cdist` (for C distribution) to save our compiled
files. The reason we chose that name, is to be able to type `cdi` in the
terminal and have it autocomplete with the Tab key, so compiling looks
something like:

```bash
zigcc hello.c -o cdist/hello
```

And executing the generated binary looks like:

```bash
cdist/hello
```

Much better than the usual `./hello`, because I do not want to constantly reach
out for `.` + `SHIFT + 7`, since I am using a LATAM keyboard layout.

And using Tab completions does not really conflict with other commands, like
`distro` or `out123` / `outpsfheader`.

## 2. Empty for now
