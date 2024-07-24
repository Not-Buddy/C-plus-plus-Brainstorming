#include <stdio.h>

// Define a structure called Person
struct Person {
    char name[50];
    int age;
    float height;
};

int main() {
    // Declare and initialize a variable of type struct Person
    struct Person person1 = {"Alice", 30, 5.5};

    // Access and print the members of the structure
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Height: %.1f\n", person1.height);

    return 0;
}

