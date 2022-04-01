To use CSIF provided from school, we must assign our ssh into the virtual lab in UC Davis computer to login. Note you are are supposed to replace anything wrapped by <> with the actual content of yours.  

```bash
ssh <UCDEmailPrefix>@pc<PCNumber>.cs.ucdavis.edu
```

### Create Some Directory and File via CLI

```bash
mkdir lecture && touch ./lecture/main.c
```

### Writing Code In CLI

If you only have linux CLI environment, we can use 
**VIM** editor *terminal integrated text editor*. 

To start coding `main.c` file in current directory

```bash
vi main.c
#or
vi ./main.c
```

For more internal command usage for **VIM**, please refer to the documentation [VIM DOCS](#)

### Writing Code In IDE

It is really good if we can learn how to use VIM (terminal integrated text editor), but sometimes to keep up with your past experience, you may wonder if there is a way to code C in IDE. There are many ways, but I personally use `VSCode` (NOT Visaul Studio), with integrated ternimal. 

If you need help with setting up this environment for you to create, edit, delete and manage your codes using a text editorr VSCode, please let me know via discord or eamil `hanchoi@ucdavis.edu`, I will help you either before or after class.

---

## Window & Sub-Linux system Ubuntu

I personally use a kind of distributed subsystem for linux called `ubuntu` version `20.0.4`

If you are using Window, and do not know or have Ubuntu installed in your machine 

- [Install WSL (Window Subsystem For Linux)](https://docs.microsoft.com/en-us/windows/wsl/install)

If you are using Window and have Ubuntu installed but do not know what version you are in, in the ternimal, try the command

```bash
lsb_release -a

# then you will see something like below
Description:    Ubuntu 20.04.3 LTS
Release:        20.04
```

This means that I am using the `ubuntu 20` version. It is likely that yours is `ubuntu 18` or `ubuntu 20`. If you want to upgrade to `ubuntu 20`, 

- [Ubuntu 20.04 Upgrade Guide](https://docs.microsoft.com/en-us/windows/wsl/install#:~:text=To%20update%20from%20WSL%201,distribution%20to%20use%20WSL%202.)