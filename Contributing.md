# Contribution Guidelines

When decided to contribute to this repository, please read the following and keep the repo's contribution rule. This is so that the repository content is consistent in design & its format as well as the module relevancy to help readers to browse & learn more effectively.

## Contribution Steps

Below is the direction as to how to start contributing properly using appropriate tools. Also **NOTE** that there are things that contributors have to abide by within the repository rule which will be described in the section below [Contribution & Review Request Mininum Requirements](#contribution-review-request-minimum-requirement).

#### 🚀 Clone The Repository

#### 🚀 Create Your Branch

#### 🚀 Add Relevant Contents To Relevant Directory

#### 🚀 Clean Up Unnecessary Files Or Directories From Development Setting

#### Git Commit & Push to Your Branch

#### Submit a Pull Request & Wait for Approval

---

## Contribution Review Request Minimum Requirement

It is required that the future contributors keep the consistent syntax when it comes to **Creating Directoies and Files**. For both creating directories and files, it must follow the common **camelCase** rule.

For example, if you want to create a `.c` file that deals with topics of datatypes & you want to name is something like `data type.c`, then you may name the file as

`dataType.c`

`dataTypes.c`

but **NOT**,

`DataType.c`

`data-type.c`

`Datatype.c`

`dTypes.c`

`dataTyps.c`

_Do not shorten the standart name which the topic is refering to._

Hope that this is pretty straight forward.

Similarly for directory names, if you want to create a directory in your branch (which you want it to be merged to main later), then you have to name it using **camelCase**. Suppose that I want to create a directory and a file in it. The directory is about _struct pointers_, then you can name the directory in the following pattern.

`structPointers`

`structPointer`

`pointerOfStruct`

`pointersOfStruct`

but **NOT**,

`structpointers`

`struct-pointers`

`str-ptr`

`structPtr`

`strPointers`

_Do not shorten the full name which the topic is refering to._

For the programming style, it is freedom however you want to format. But **We Encourage** you do write the explanation text, function `argument` `return` types and its functionality with the best practices you know. At the end, the goal is to help others learn & use it in their project so if they have trouble understanding what the argument type or what they are even for, then it is actually bad that they lose the time reading our documentation, which we don't want to let happen.

## What CANNOT be changed

When you first clone the repo, you will see directories that has prefix of `core`. You may not modify the name of these directories, but you can absolutely add files or directories within them. They are there to be presented as the basic list of indexes that users can follow when learning the content.

## What CAN be changed

Any files written by YOU and YOU only in workspace directories `/coreXDirectory/` can be changed overtime. If you are not the previous author of a specific file `someFile.c` but you find an issue, you can submit an issue but not modify it.

Also, you can **append** your contributor info to the `Contributors.md` in the `master` branch.

These are the only things that you can change and anything else will be allowed.
