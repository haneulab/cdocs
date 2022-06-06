**filename** : **cli.md**

**author** : **Dave Nguyen** [hxnguyen@ucdavis.edu](hxnguyen@ucdavis.edu)

**brief** : explain different linux command lines & basic linus operation.

**date** : **06/04/2022**

# Linux Commands Line Interface(CLI)
Command line is a way to interact with your computer by sending it text commands through *terminals*. (ex: Powershell for Window) It is the basic understanding of computer operation and it can offer numerious benefits of navigating through computer system. 
**PRIMARY EXAMPLE**: 
we have directory `ECS32C`. In it we have `homework`. `homework` contains 6 text files: 1, 2, 3, 4, 5, and 6 (.txt).  
**Terminology**: *directory* is a place that store all files, or can be called folder. *file* is where we write our codes. *path* is the link between different directories and/or files. 

## Different CLI
#### cd [Change Directory]
Change the current working directory to the specified directory. If no directory is given, `cd` change the current directory to the home directory (our beginning directory, typically it is `c:/user/"personalname"`). 
**examples**: we can go to homework from ECS32C: `cd homework`, or `cd ECS32C/homework`.

#### ls [list all files]
Lists the contents of the given directories. If no directories are specified it lists the contents of the current directory
**examples**: we want to list all the files in `homework`:
```
$ ls ECS32C/homework
1.txt 2.txt 3.txt 4.txt 5.txt 6.txt
```

#### pwd [**prints** the current **working directory** path]
Displays the directory that you are in.
**examples**: we are at `homework` we want to display where we are (current directory). 
```
$ pwd
/ECS32C/homework
```

#### cp [Copying File] (2 usages)
(1) `cp` takes in 2 arguments: source_file_name, destination_file_name. `cp` copies the source file to the destination file. Keep in mind that `cp` will overwrite the destination file if it exists and create it if it does not. 
(2) `cp` can take in file1 file2 file3 … directory. `cp` copy all of the listed files to the given directory. 

**examples**: Assume file 6 have:
```
$ cat 6.txt
hello
```
we want to `cp` file 6 and named it 7
```
$ cp 6.txt 7.txt
$ cat 7.txt
hello
```
we want to `cp` files 6 and 7 to directory `/example_cp`: 
```
$ cp 6.txt 7.txt example_cp
$ ls example_cp
6.txt 7.txt
```

#### mv [(1)Moving File or (2)Change File name]
(1) mv takes in 2 arguments(old_file_name and new_file_name). Rename the file with old_file_name to the new_file_name. 
**examples**: we want to change file 5 to file 5_5, we can write:
```
$ mv 5.txt 5_5.txt
```
(2) mv can takes in (file1 file2 file3… directory). Move the specified files to the directory. Conditionally, the directory must exist.
**examples**: In ECS32C directory we have a file: foo.txt. Since in ECS32C, we have the homework directory and foo.txt, we can move foo.txt to the homework directory: 
```
$ mv foo.txt homework
```

#### mkdir [Make Directory]
Create a new directory named dirName
**examples**: we want to create a new directory called `ECS32C_ex`. 
```
$ mkdir ECS32C_ex
```

#### rmdir [remove directory]
Remove the specified directory but only if it is empty. If the directory is not empty the command will fail
**examples**: Since ECS32C_ex does not have any files in it, we can safely remove it: 
```
$ rmdir ECS32C_ex
```

#### rm [remove file] [-f flag optional]
Remove the specified files. If -f is given it will not prompt you if you want to delete the file and it will delete it. Can be used to remove directory and all files contained within it. 
**examples**: We want to remove foo.txt in the homework directory:
```
$ ls homework
1 2 3 4 5 6 foo.txt 
$ rm foo.txt
$ ls homework 
1 2 3 4 5 6
``` 

#### cat [concatenate file]
Displays the content of a file. 
**examples**: suppose in file 6 we have content in it. We can display its context: 
```
$ cat 6.txt
blah blah 
what's sup, how yall doing~
``` 

#### grep [Global Regular Expression Print] (-v flag)
Search a file for a particular pattern, and display all lines that contains that particular pattern. 
-v: prints out all the lines that do not matches the pattern
**examples**: the syntax for grep is grep [flag] pattern [files]. Suppose we want to find "blah" in 6.txt
```
$ grep blah 6.txt
blah blah
$ grep -v blah 6.txt
what's sup, how yall doing~
```

#### wc [word count](-l flag)
Find out number of lines, word count, and characters count in the file(s) specified in the file arguments. wc can display multiple files as well. 
-l: prints number of lines only for the file(s) specified in the arguments
**examples**: we want to print 6.txt:
```
$ wc 6.txt
$ 5  7 33 6.txt
``` 
5: is number of lines, 7 is words count, 33 is characters count, and 6.txt is the file. If we use -l:
```
$ wc -l 6.txt
5 6.txt
```
If we want to display files 5 and 6:
```
$ wc 5.txt 6.txt
6   8 23 5.txt
5   7 33 6.txt 
11 15 56 total
```

#### head (-n flag)
Display the **first** n lines of a file. If n is not given it displays the first 10 lines. 
**examples**: We want to display 6.txt. We can write: 
```
$ head 6.txt 
blah blah 
what's sup, how yall doing~
Its your boi Gucci
```
If we want to display the first 2 lines: 
```
$ head -2 6.txt
blah blah 
what's sup, how yall doing~
```

#### tail (-n flag)
Display the *last* n lines of a file. If n is not given it displays the last 10 lines. 
**examples**: We want to display 6.txt. We can write: 
```
$ tail 6.txt
blah blah blah
blah blah blah
blah blah blah
blah blah blah
blah blah blah
blah blah blah
blah blah blah
blah blah blah
blah blah blah
blah blah blah
```
If we want to display the last 2 lines, we can write: 
```
$ tail -2 6.txt
blah blah blah
blah blah blah
```

***Online Resources*** 
*Some online resources that might be helful*
- [wc command in Linux with examples](https://www.geeksforgeeks.org/wc-command-linux-examples/)
- [grep command in Unix/Linux](https://www.geeksforgeeks.org/grep-command-in-unixlinux/)
