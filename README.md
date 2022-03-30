# ECS 32C Spring 2022

🚀 **Command Line Interface (CLI)**

An Interface (*oftne refered as command line*) where we write computational commands for the machine to take a specific action or actions.

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

Make new directories
```bash
mkdir newFolder
mkdir newFolderA newFolderB
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

**Working with Relative Paths**

Working with relative path pattern is often referred as writing file/directory names relative to your or the file's current path. To represent the current position (location) of the path, we 
express it as `.` *(dot)* notation

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

View Full Path to Current Directory

```bash
pwd
# /home/user/workspace/...
```