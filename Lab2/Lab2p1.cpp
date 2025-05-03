#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int isPalindrome(int *num);
int isArmstrong(int *num);
int isPerfect(int *num);

int main() {
    int *choice = (int*)malloc(sizeof(int));
    int *num = (int*)malloc(sizeof(int));
    
    printf("Enter a number: ");
    scanf("%d", num);
    
    do {
        printf("\n1. Palindrome number\n");
        printf("2. Armstrong number\n");
        printf("3. Perfect number\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", choice);

        switch (*choice) {
            case 1:
                if (isPalindrome(num) == 1) {
                    printf("It is a palindrome number.\n");
                } else {
                    printf("It is not a palindrome number.\n");
                }
                break;

            case 2:
                if (isArmstrong(num) == 1) {
                    printf("It is an Armstrong number.\n");
                } else {
                    printf("It is not an Armstrong number.\n");
                }
                break;

            case 3:
                if (isPerfect(num) == 1) {
                    printf("It is a perfect number.\n");
                } else {
                    printf("It is not a perfect number.\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (*choice != 4);

    free(choice);
    free(num);
    return 0;
}

// Function to check if a number is a palindrome
int isPalindrome(int *num) {
    int *temp = (int*)malloc(sizeof(int));
    int *rev = (int*)malloc(sizeof(int));
    int *digit = (int*)malloc(sizeof(int));
    int result;

    *temp = *num;
    *rev = 0;

    while (*temp > 0) {
        *digit = *temp % 10;
        *rev = (*rev) * 10 + *digit;
        *temp /= 10;
    }

    if (*num == *rev) {
        result = 1;
    } else {
        result = 0;
    }

    free(temp);
    free(digit);
    free(rev);

    return result;
}

// Function to check if a number is an Armstrong number
int isArmstrong(int *num) {
    int *temp = (int*)malloc(sizeof(int));
    int *cnt = (int*)malloc(sizeof(int));
    int *sum = (int*)malloc(sizeof(int));
    int *digit = (int*)malloc(sizeof(int));
    int result;

    *temp = *num;
    *cnt = 0;
    *sum = 0;

    // Counting number of digits
    int *tempCount = (int*)malloc(sizeof(int));
    *tempCount = *temp;
    while (*tempCount > 0) {
        (*cnt)++;
        *tempCount /= 10;
    }
    free(tempCount);

    *temp = *num;  // Reset temp for calculation

    while (*temp > 0) {
        *digit = *temp % 10;
        *sum += pow(*digit, *cnt);
        *temp /= 10;
    }

    if (*num == *sum) {
        result = 1;
    } else {
        result = 0;
    }

    free(temp);
    free(cnt);
    free(sum);
    free(digit);

    return result;
}

// Function to check if a number is a perfect number
int isPerfect(int *num) {
    int *sum = (int*)malloc(sizeof(int));
    int *i = (int*)malloc(sizeof(int));
    int result;

    *sum = 0;

    for (*i = 1; *i <= *num / 2; (*i)++) {
        if (*num % *i == 0) {
            *sum += *i;
        }
    }

    if (*num == *sum) {
        result = 1;
    } else {
        result = 0;
    }

    free(sum);
    free(i);

    return result;
}
