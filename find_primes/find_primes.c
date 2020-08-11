#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX_DIGITS 9

int get_int(char *prompt);

int main(void) {
    char start_prompt[] = "Enter a starting number: ";
    char end_prompt[] = "Enter an ending number: ";

    // Obtain integers defining prime number search range from the user
    int start = get_int(start_prompt);
    int end = get_int(end_prompt);

    // Validate user input
    if (start < 1 || end < 1) {
        printf("Error: Start and end must be positive integers\n");
        return 1;
    }
    if (start > end) {
        printf("Error: End must be greater then start\n");
        return 1;
    }

    printf("Primes between %d and %d:\n", start, end);

    // Skip 1 during prime search
    if (start < 2) {
        start = 2;
    }

    int prime_flag = 0;
    int prime_count = 0;
    for (int i = start; i <= end; i++) 
    {
        // A number is prime when flag == 1, else prime_flag = 0
        // Starting assumption: all numbers are prime.
        // Update prime_flag = 0 if num is divisible by i > 1 and < num
        prime_flag = 1;
        for (int n = 2; n < i; n++)
        {
            if (i % n == 0)
            {
                // Not a prime; stop search; test next n
                prime_flag = 0;
                break;
            }
        }
        
        // n is prime; print n
        if (prime_flag == 1)
        {
            printf("%d\n", i);
            prime_count ++;
        }
    }

    if (prime_count == 0)
    {
        printf("None\n");
    }
}

// Gets an integer from the user; Quit on invalid input
int get_int(char *prompt) {

    // MAX_DIGITS + 2 to account for \n and \0 at end of string
    char buf[MAX_DIGITS + 2];
    char *p;
    int i;

    printf("%s", prompt);

    if (fgets(buf, sizeof(buf), stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] != '\n')
        {
            printf("[Error]: Too many characters: max is %d digits.\n", MAX_DIGITS);
            exit(1);
        }
        
        i = strtol(buf, &p, 10);
        
        if (buf[0] == '\n' && (*p != '\n' && *p != '\0'))
        {
            printf("[ERROR]: input must be an integer.\n");
            exit(1);
        }
    }
    return i;
}