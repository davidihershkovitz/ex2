/******************
Name: Davidi Hershkovitz
ID: 214165417
Assignment: ex2
*******************/

#include <stdio.h>

int main()
{
    int choice;
//menu
    do
    {
        printf("\nChoose an option:\n");
        printf("    1. Happy Face\n");
        printf("    2. Balanced Number\n");
        printf("    3. Generous Number\n");
        printf("    4. Circle Of Joy\n");
        printf("    5. Happy Numbers\n");
        printf("    6. Festival Of Laughter\n");
        printf("    7. Exit\n");
// handling the option that the user picks
        if (scanf("%d", &choice) != 1)
        {
            scanf("%*[^\n]");
            scanf("%*c");
            printf("This option is not available, please try again.\n");
            continue;
        }

        if (choice < 1 || choice > 7)
        {
            printf("This option is not available, please try again.\n");
            continue;
        }

        if (choice == 7)
        {
            printf("Thank you for your journey through Numeria!\n");
            break;
        }
// first task
        if (choice == 1)
        {
            char eye, nose, mouth;
            int size;

            // Get characters from user
            printf("Enter symbols for the eyes, nose, and mouth:\n");
            while (scanf(" %c %c %c", &eye, &nose, &mouth) != 3) {
                scanf("%*[^\n]");
                scanf("%*c");
            }

            // Get face size
            printf("Enter face size:\n");
            int valid_size = 0;
            while (!valid_size) {
                if (scanf("%d", &size) != 1) {
                    scanf("%*[^\n]");
                    scanf("%*c");
                    printf("The face's size must be an odd and positive number, please try again:\n");
                    continue;
                }
                if (size > 0 && size % 2 != 0) {
                    valid_size = 1;
                } else {
                    printf("The face's size must be an odd and positive number, please try again:\n");
                }
            }

            int eye_spacing = size;
            int nose_spacing = (size + 1) / 2;

            printf("%c", eye);
            for (int i = 0; i < eye_spacing; i++) {
                printf(" ");
            }
            printf("%c\n", eye);

            for (int i = 0; i < nose_spacing; i++) {
                printf(" ");
            }
            printf("%c\n", nose);

            printf("\\");
            for (int i = 0; i < size; i++) {
                printf("%c", mouth);
            }
            printf("/\n");
        }
        // task 2
        if (choice == 2)
        {
            int number;

            printf("Enter a number:\n");
            while (1) {
                if (scanf("%d", &number) != 1 || number <= 0) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%*[^\n]");
                    scanf("%*c");
                } else {
                    break;
                }
            }
// checking the num according to the instruction
            int temp = number;
            int digit_count = 0;
            while (temp > 0) {
                digit_count++;
                temp /= 10;
            }

            int divider = 1;
            for (int i = 1; i < digit_count; ++i) {
                divider *= 10;
            }

            int left_sum = 0, right_sum = 0;
            int current_digit;
            for (int i = 0; i < digit_count; ++i) {
                current_digit = number / divider;
                number = number % divider;
                divider /= 10;

                if (digit_count % 2 == 1 && i == digit_count / 2) {
                    continue;
                }

                if (i < digit_count / 2) {
                    left_sum += current_digit;
                } else {
                    right_sum += current_digit;
                }
            }

            if (left_sum == right_sum) {
                printf("This number is balanced and brings harmony!\n");
            } else {
                printf("This number isn't balanced and destroys harmony.\n");
            }
        }
        //task 3
        if (choice == 3)
        {
            int number, sum = 0;

            printf("Enter a number:\n");
            do
            {
                if (scanf("%d", &number) != 1 || number <= 0)
                {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%*[^\n]");
                    scanf("%*c");
                    number = -1;
                }
            }
            // checking the number according to the instructions
            while (number <= 0);

            for (int i = 1; i <= number / 2; i++)
            {
                if (number % i == 0)
                {
                    sum += i;
                }
            }

            if (sum > number)
            {
                printf("This number is generous!\n");
            }
            else
            {
                printf("This number does not share.\n");
            }
        }
        //task 4
        if (choice == 4)
        {
            int number, prime_original = 1, prime_reversed = 1;

            printf("Enter a number:\n");
            do
            {
                if (scanf("%d", &number) != 1 || number <= 0)
                {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%*[^\n]");
                    scanf("%*c");
                    number = -1;
                }
            }
            while (number <= 0);


            if (number <= 1)
            {
                prime_original = 0;
            }
            else
            {
                //checking the number according to the instructions
                for (int i = 2; i * i <= number; i++)
                {
                    if (number % i == 0)
                    {
                        prime_original = 0;
                        break;
                    }
                }
            }

            int reversed = 0, temp = number;
            while (temp > 0)
            {
                reversed = reversed * 10 + temp % 10;
                temp /= 10;
            }

            if (reversed <= 1)
            {
                prime_reversed = 0;
            }
            else
            {
                for (int i = 2; i * i <= reversed; i++)
                {
                    if (reversed % i == 0)
                    {
                        prime_reversed = 0;
                        break;
                    }
                }
            }
            if (prime_original && prime_reversed)
            {
                printf("This number completes the circle of joy!\n");
            }
            else
            {
                printf("The circle remains incomplete.\n");
            }
        }
//task 5
        if (choice == 5)
        {
            int number;
            printf("Enter a number:\n");
            do
            {
                //checking the number according to the instructions
                if (scanf("%d", &number) != 1 || number <= 0)
                {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%*[^\n]");
                    scanf("%*c");
                    number = -1;
                }
            }
            while (number <= 0);

            printf("Between 1 and %d only these numbers bring happiness: ", number);

            for (int i = 1; i <= number; i++)
            {
                int current = i;
                int sum_of_squares;

                do
                {
                    sum_of_squares = 0;

                    while (current > 0)
                    {
                        int digit = current % 10;
                        sum_of_squares += digit * digit;
                        current /= 10;
                    }
                    current = sum_of_squares;
                }
                while (current != 1 && current != 4);

                if (current == 1)
                {
                    printf("%d ", i);
                }
            }
            printf("\n");
        }
//task 6
        if (choice == 6)
        {
            int smile = 0, cheer = 0, max = 0;

            printf("Enter a smile and cheer number:\n");
            while (1)
            {
                if (scanf(" smile :%d %*[ ,] cheer :%d", &smile, &cheer) == 2 && smile > 0 && cheer > 0 && smile !=
                    cheer)
                {
                    break;
                }
                else
                {
                    printf(
                        "Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
                    scanf("%*[^\n]");
                    scanf("%*c");
                }
            }
            //checking the number according to the instructions
            printf("Enter maximum number for the festival:\n");
            while (1)
            {
                if (scanf("%d", &max) == 1 && max > 0)
                {
                    break;
                }
                else
                {
                    printf("Only positive maximum number is allowed, please try again:\n");
                    scanf("%*[^\n]");
                    scanf("%*c");
                }
            }

            for (int i = 1; i <= max; i++)
            {
                if (i % smile == 0 && i % cheer == 0)
                {
                    printf("Festival!\n");
                }
                else if (i % smile == 0)
                {
                    printf("Smile!\n");
                }
                else if (i % cheer == 0)
                {
                    printf("Cheer!\n");
                }
                else
                {
                    printf("%d\n", i);
                }
            }
        }
    }
    while (1);

    return 0;
}


