#include<stdio.h>

// Function to reverse a number recursively
int pal_rec(int num) {
    static int rev = 0; // Static variable to hold the reversed number across recursive calls
    
    if (num == 0) {
        return rev;
    }
    
    rev = rev * 10 + num % 10;
    return pal_rec(num / 10);
}

// Function to check if a number is a palindrome iteratively
void pal(int num) {
    int original = num;
    int reversed = 0, remainder;
    
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num = num / 10;
    }
    
    if (original == reversed) {
        printf("Palindrome\n");
    } else {
        printf("Not palindrome\n");
    }
}

int main() {
    int num;
    printf("Enter num: ");
    scanf("%d", &num);
    
    // Check palindrome using iterative function
    pal(num);
    
    // Check palindrome using recursive function
    int reversed = pal_rec(num);
    if (num == reversed) {
        printf("Palindrome\n");
    } else {
        printf("Not palindrome\n");
    }
    
    return 0;
}

