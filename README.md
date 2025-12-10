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

## 2. Bits

Code for this lesson (`./2/bitfields.c`):

```c
#include <stdio.h>

int main(void) {
    unsigned char a = 0b11100110;
    printf("%d\n", a);

    signed char b = 0b11100110;
    printf("%d\n", b);

    unsigned char h = 0xE6;
    printf("%d\n", h);

    signed char g = 0xE6;
    printf("%d\n", g);
    return 0;
}
```

If you compile and run it, you will find that the variable contains the same
bytes under the hood, but since we are labeling one as `unsigned` and the other
one as `signed`, the output of the `printf` function shows 230 for the unsigned
one and -26 for the signed one.

And we obtain the same result with hexadecimals.

Standard types defined in `stdint.h`:

| Type           | Type in `stdint.h` | Bytes | Signed | Min                        | Max                       |
| -------------- | ------------------ | ----- | ------ | -------------------------- | ------------------------- |
| char           | uint8_t            | 1     | No     | 0                          | 256                       |
| signed char    | int8_t             | 1     | Yes    | -128                       | 127                       |
| unsigned short | uint16_t           | 2     | No     | 0                          | 65,535                    |
| short          | int16_t            | 2     | Yes    | -32,768                    | 32,767                    |
| unsigned int   | uint32_t           | 4     | No     | 0                          | 4,294,967,295             |
| int            | int32_t            | 4     | Yes    | -2,147,483,648             | 2,147,483,647             |
| unsigned long  | uint64_t           | 8     | No     | 0                          | 4,294,967,295             |
| long           | int64_t            | 8     | Yes    | -9,223,372,036,854,775,808 | 9,223,372,036,854,775,807 |

Mysterious behavior (`./2/mystery.c`):

```c
#include <stdio.h>

int main(void) {
    unsigned int a, b;

    a = 1;
    b = 2;

    printf("a-b = %d\n", a - b);

    if (a - b > 0)
        printf("a > b\n");
    else if (a - b == 0)
        printf("a == b\n");
    else
        printf("a < b\n");

    return 0;
}
```

Compile and run the code above. The output is:

```
-1
a > b
```

Why? If these values are unsigned, why is `a - b = -1`? And if it is, then why
is `a > b`?

Well, when we have `a - b`, the result technically is `2,147,483,647`, so `a -
b` is greater than 0, that is why `a > b` is being printed. However, when we
use `%d` in the `printf` function, we are telling it to interpret the value as
a signed integer, which is why we get `-1` there.

## 3. Empty for now
