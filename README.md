# ECS 32C Spring 2022

🚀 **Command Line Interface (CLI)**

An Interface (_oftne refered as command line_) where we write computational commands for the machine to take a specific action or actions.

View current directories items

```bash
# list general items
ls
# list all items including .(dotfiles)
ls -la
```

Make new files

```bash
touch newFile.txt
touch fileA.txt fileB.txt fileC.txt
```

Remove Files

```bash
rm newFile.txt
rm fileA.txt fileB.txt fileC.txt
```

Make new directories

```bash
mkdir newFolder
mkdir newFolderA newFolderB
```

Remove directories

```bash
# if the folder "foo" is empty
rmdir foo
# if the folder is not empty (WARNING using this command)
rm -rf foo
```

Read File In CLI

```bash
cat myFile.txt
```

Directional Commands

```bash
# go into a directory folderA
cd folderA
# go out of current directory
cd ..
```

View Full Path to Current Directory

```bash
pwd
# /home/user/workspace/...
```

---

### Relative Paths

**Working with Relative Paths**

Working with relative path pattern is often referred as writing file/directory names relative to your or the file's current path. To represent the current position (location) of the path, we
express it as `.` _(dot)_ notation

```bash
# I am in a folder called "workspace"

# create three folders in current directory
mkdir workA workB workC
# create three folders using relative paths in the current directory
mkdir ./workA ./workB ./workC
```

```bash
# create folder "newFolder" and a file "newFile.txt in it using relative path pattern
mkdir ./newFolder && touch ./newFolder/newFile.txt
```

---

## Working with Full CLI

Many times, we work with commands with extra options attached to them.

```bash
# make one directory
mkdir foo
# make a nested directory simultaneuously 
mkdir foo/nestedFoo # this will not work!!

# instead we add option to indicate the nested order of the making directories
mkdir -p foo/nestedFoo # this creates a parent folder foo, then children directroy nestedFood
```
