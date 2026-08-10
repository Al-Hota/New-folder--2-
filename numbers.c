#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
} RandValue;

void safe_input_check(int *x){
    if (scanf("%d", x) != 1) {
        printf("Invalid input.\n");
        exit(1);
    }
}

void letterpool(char *value, int size){
    for(int i = 0; i < size; i++){
        value[i] = rand() % 26 + 65; // Generates random uppercase letters (ASCII A-Z)
    }
    for (int i = 0; i < size; i++) {
        printf("%c ", value[i]); // Print the random letters
    }
    
}



int main(void) {
    int size;
    printf("Enter the number of random letters to generate: ");
    safe_input_check(&size);
    char *value = malloc(size * sizeof(char)); // Allocate memory for the array
    if (value == NULL){
        printf("memory allocation failed\n");
        return 1;
    }
    letterpool(value, size);
    free(value); // Free the allocated memory
    return value[size - 1]; // Return the last generated random letter as an integer
    printf("The last generated random letter is: %c\n", value[size - 1]); // Print the last generated random letter
    return 0;
}