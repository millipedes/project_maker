# :dragon: Personal Project Maker
## :dart: Project Description/Goal
This project is meant to produce a binary used to automatically generate
projects based off flags provided by the user. Currently supported types are:
- C
- LaTeX

However, this project also dynamically makes Makefiles as well. The supported
types (along with their interface with respect to the Makefile) are as follows:

- C (gcc)
- LaTeX (pdflatex)
- plantuml (plantuml)
- github (git)

Beta Disclaimer: This project is still meant as beta software at the moment.
However, this does not mean it is not functional as I am currently using it
daily and fix problems as I come across them.

## :floppy_disk: Installation
### :penguin: Linux
The installation steps are very primitive at the moment. First, we must make the
bin directory after cloning the repo, i.e.:
```
$ git clone https://github.com/millipedes/project_maker.git
$ cd project_maker/
$ mkdir bin
```

One feature of this program is the ability to clone cookie cutter files of the
supported formats (C and LaTeX). Thus you should make default files for the
program to make (in future versions, default files will be provided).

Then, go to the file `src/constants_macros/include/constants.h` and change
the paths to reflect your default files.

Then, while in the same directory, `make` the binary and confirm that it worked:
```
$ make
$ ls ./bin/main
```
If you wish to use this binary system wide (and you are not on NixOS) then you
can move the binary to `/usr/bin/`, but before you do read the next paragraph.

:exclamation: To move the binary to `/usr/bin/` you need root privlidges.
Additionally, make double sure that you do not accidentally overwrite a binary
that alredy exists in `/usr/bin/`. For example, if you wanted to name the binary
`my_binary`, before moving the binary to `/usr/bin/` it would be advisable to
run:
```
$ sudo ls /usr/bin/my_binary
```
and see that there are no existing files with that name. If there is not and you
believe that your package manager will not write over `my_binary` in the future
accidentally (or worse confuse it for another), then perform (from the root of
the git clone):
```
$ sudo mv ./bin/main /usr/bin/my_binary
```

### Windows and Mac
For WindowsOS and MacOS users, I cannot support these operating systems. If you
are a fan of the project through a friend or VM and want to write a WindowsOS or
MacOS interface, I would happily accept your PR under the condition it was
formatted to the rest of the code base.

## :star2: Currently Offered Features
The following example is meant to demonstrate the functionality of this program:
```
$ ./project_maker_binary t latex_project_dir/file C c_dir/file
```
### :mag: Tests
I have written a `test.sh` file. If you run this test.sh file in the root of the
git repo after making the binary it will overwrite the Makefile and make a
directory called `test/` with some files in it. This file is meant to be
demonstratative of what the program can do.

## :scroll: Immediately on the List to be Implemented
