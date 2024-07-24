#include <stdio.h>
#include <stdlib.h>

// Define a structure called Person
struct Person {
    char name[50];
    int age;
    float height;
};

int main() {
    // Allocate memory for a variable of type struct Person
    struct Person *personPtr = (struct Person *)malloc(sizeof(struct Person));

    // Check if memory allocation was successful
    if (personPtr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize the members of the structure using the pointer
    // Assuming proper values for name, age, and height
    snprintf(personPtr->name, sizeof(personPtr->name), "Bob");
    personPtr->age = 25;
    personPtr->height = 6.1;

    // Access and print the members of the structure using the pointer
    printf("Name: %s\n", personPtr->name);
    printf("Age: %d\n", personPtr->age);
    printf("Height: %.1f\n", personPtr->height);

    // Free the allocated memory
    free(personPtr);

    return 0;
}

