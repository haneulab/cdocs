**filename** : **structs.md**

**author** : **Haneul Choi** [hanchoi@ucdavis.edu](hanchoi@ucdavis.edu)

**brief** : exploring the basic understanding & usage of struct instances.

**date** : **06/03/2022**

# Structs

In this file, we will explore the concept of `struct` in C programming language. For those who have previous experience with other programming languages such as `python`, `javascript`, `java`, ..., you can think of `struct` as a class object, although there are some limitations in C as to how much you can control & attaching methods is not something you can do in C's `struct` object.

In order to ease your understanding of `struct` and its usage, please go to `/pointers_arrays_string` directory and learn about **pointers** & **arrays** & **strings** first if you have not yet done so.

## What is a Struct?

```c
...
struct Student
{
    // the following are instance variables
    // we can design a struct object that
    // represent a student in a university.
    // example variables needed to store
    // information about this student can be
    // the following list.

    int id; // unique student id : 132942
    char *firstname; // student firstname : "John"
    char *lastname; // student lastname : "Doe"
    int unisCompleted; // accumulated total units completed : 180
    char **classesTaken; // accumulated list of classes taken {"ECS32C", "MAT167", ...}
    float gpa; // accumulated GPA : 3.97

    float currentGPA; // current GPA : 3.50
    char **currentClasses; // current classes taking : {"PHI112", "ECS50", ...}
};
```

Basic declaration of a `struct` in C is as simple as writing the keyword `struct` followed by the name of the object you want to use. In the above example, I used an example of `struct Student` to represent a student in a university and also I defined its member variables when declaring the object.

To instantiate the `struct` object `struct Student`, please take a look at the following code.

### Basic Usage

```c
...
struct Student {
    int id; // unique student id : 132942
    char *firstname; // student firstname : "John"
    char *lastname; // student lastname : "Doe"
    int unisCompleted; // accumulated total units completed : 180
    char **classesTaken; // accumulated list of classes taken {"ECS32C", "MAT167", ...}
    float gpa; // accumulated GPA : 3.97

    float currentGPA; // current GPA : 3.50
    char **currentClasses; // current classes taking : {"PHI112", "ECS50", ...}
};

int main()
{
    struct Student JohnDoe;

    JohnDoe.id = 101105; // int
    JohnDoe.firstname = "John"; // char *
    JohnDoe.lastname = "Doe"; // char *

    return 0;
}
```

In the program above, the only instance variables that I instantiate along with the `struct JohnDoe` are `JohnDoe.id`, `JohnDoe.firstname`, and `JohnDoe.lastname`. Meaning that this object `struct JohnDoe` is missing the rest of the instance members to start with. This means that at the current state, the program won't be able to retrieve any value of members of `JohnDoe` such as `JohnDoe.unitsCompleted`, `JohnDoe.classesTaken`, and so on.

Because this file is just a basic exploration about how to declare & use `struct`, we won't go into deep how we can intantiate all the members more efficiently depending on its need.

But for this, we can simply remember that to acces a member in a `struct` we can use `.` followed by the member `key`, such as below.

`JohnDoe.firstname`

`JohnDoe.lastname`

`JohnDoe.id`

## Example Code For Another Struct Usage

```c
#include <stdio.h>

struct House
{
    char *address;
    int numOfRoom;
    float numOfBathroom;
    double netPrice;

    int garage; // 0 if no garage else 1
    int yard;   // 0 if no yard else 1
    int pool;   // 0 if no pool else 1
};

void describeHouse(struct House someHouse)
{
    printf("House @ %s\n%d rooms with %.2f bathrooms\nprice is %.2f\n==specification ==\ngarage: %d\nyard: %d\npool: %d.\n", someHouse.address, someHouse.numOfRoom, someHouse.numOfBathroom, someHouse.netPrice, someHouse.garage, someHouse.yard, someHouse.pool);
}

int main()
{
    struct House AmazingHouse;
    AmazingHouse.address = "123 Example Ave";
    AmazingHouse.numOfRoom = 3;
    AmazingHouse.numOfBathroom = 2.5;
    AmazingHouse.netPrice = 950000.00;

    AmazingHouse.garage = 1; // has garage
    AmazingHouse.yard = 1;   // has yard
    AmazingHouse.pool = 0;   // doesn't have a pool

    describeHouse(AmazingHouse);

    /**
    House @ 123 Example Ave
    3 rooms with 2.50 bathrooms
    price is 950000.00
    ==specification ==
    garage: 1
    yard: 1
    pool: 0.
    */

    return 0;
}
```
