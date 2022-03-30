# ECS 32C Spring 2022

The contents in this repository are related to ECS 32C (Data Structure Implementation) taught by
professor Aaron Kaloti.

I am one of the students in this course, and I find it useful to take notes each lecture in order to
catch up with the current topics as well as preparing for the next topics.

Often times, it is easy to fall behind when lost in a certain topic, thus this repository is there to be
referred back to a specific topic discussed in this course.

---

## Directories

Each directories is named after each lecture session. Going into that specific directory will have
topics learned in that lecture.

**Basic Understanding Checklist**

[✔️ Command Line Interface (CLI)](#cli)
[✔️ Python to C](#python)

---

<h3 id="cli">🚀 Command Line Interface (CLI)</h3>

When we click things to open or close, we are using **GUI** short for *graphical user interface*. As we further our programming skills and applications, we often find it more efficient in workflow to use **CLI** short fo *command line interface*. The easiest way to know the difference between these two is that we are using a set of predefined commands for our computers to do something instead of us clicking for them to do something.

In this module, we will go over the most basic and most useful commands implemented in Linux/Unix systems.

**Directories** are folders that may or may not contain nested files or nested sub directories.
**Files** are specified items noted with its extension (to which the file is referring to). For example, the computer knows a file `foo.py` is a python file because of `.py` behind the filename. Likewise, we can tell `main.c` is a C file because of its explicit file extension regardles of the filename. There are also `dot files`, often these dot files are expressed as something like `.gitignore`, `.env`, `.something`. Dot files usually store secured informations that you do not want to expose to the public environment.  If you ever used `git` and `github` to upload your local files to the cloud, you probabily saw `.DS_Store` often created depending on the IDE you are using. Technically, this file is secured file that stores important information about your computer. Thus, ideally you don't want them to be uploaded to github public repository.

**🧵 Creating Files**

```bash
# Create foo.c file in current directory
touch foo.c
# or
touch ./foo.c

# You can also create a file bar.txt with text init already
echo "Hello World" > bar.txt

# If you want to create multiple files at the same time
touch foo.txt bar.txt some.txt
```

**🧵 Removing Files**

```bash
# remove a single file foo.txt
rm foo.txt
# or
rm ./foo.txt

# remove multiple files manually
rm foo.txt bar.txt some.txt

# remove all existing files with extension .txt
rm *.txt
#or
rm ./*.txt
```

**🧵 Creating Folders**

```bash
# create a single folder in current directory
mkdir foo
# or
mkdir ./foo

# create multiple folders in current directory
mkdir foo bar some

# create nested folders
mkdir foo/bar/some
# or
mkdir ./foo/bar/some
```

**🧵 Removing Folders**

```bash
# remove an empty directory 
rmdir foo
# or
rmdir ./foo

# remove by force a non-empty directory
# **WARNING** using this command incorrectly may result deleting important components in your system.
rm -rf foo
# or 
rm -rf ./foo
```

**🧵 Change of Directories**

You want to jump around (locate yourself) to different directories, then we use `cd` base command with the folder you want to enter.

**Single dot** `.` represents current directory.

**Double dots** `..` represents previous (parent) directory.

We wil use relative path strings for our commands. What a relative path means is that if we have a file `foo.txt` in current directory, the relative path for that file is `./foo.txt`. But if we have `bar.txt` in a folder `some` in the current directory, the path to `bar.txt` relative to our current directory is `./some/bar.txt`

```bash
# go in to a directory foo
cd ./foo
# go to the parent directory
cd ..
# go to bar directory inside foo directory
cd ./foo/bar
# go to the grandparent directory
cd ../..


# go to foo/bar directory and create helloworld.c file
cd ./foo/bar && touch ./helloworld.c
# you're in bar directory, now come out of the foo directory and delete foo directory
cd ../.. && rm -rf ./foo
```

**🧵 Reading Files in CLI**

```bash
# you have a file ./foo.txt, read it to cli
cat foo.txt
# or
cat ./foo.txt
```

**🧵 Check Current Directory's Absolute Path**

Unlike relative path, the absolute path stands for the path to a file or directory starting from the absolute folder (root directory).

In Linux/Unix systems, there is alwaya a single root directory which you can go to by command `cd` or `cd ~`.

From the root directory, you want to go to a specific directory `bar`, then you may do that by applying absolute path with command `cd /workspace/foo/bar/`

If you want to check the absolute path at the current directory, you can do that by a simple command `pwd` in current directory.

```bash
# check the full path of the current directory
pwd
```

---

<h3 id="python">🚀 Python To C</h3>

Even though the programming languages `C` and `Python` are very distinct, there are some common concepts we can bring to this course.

**🧵 Importing Libraries (Modules)**

When importing modules to your file, we often specify the key word `from` and/or `import` with `module_name` like `typing`, `random`, and `requests`. The keyword importing a module in `C` is `#include` followed by the module name.

```python
import requests
from random import randint
# import and from are keywords
# requests and random are modules (libraries)
# randint is a function inside random module
```

```c
#include <stdio.h>
// #include is a keyword for import
// <> is the bracket to include a module init
// stdio.h is a library (module) 
```

**🧵 Functions**

There are some syntactic differences between python functions and c functions

```python
# python hello world function
def main() -> None:
    print("Hello World!")
```

```c
// c hello world function
void main()
{
    printf("Hello World!");
}
```

When a python function returns nothing, we specify with a type `None` at the end with an arrow. In C, we specify `void` in fron of the function name that indicates that the function will not return any value.