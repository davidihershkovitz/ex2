#include <stdio.h>

int main()
{
    int choice;

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

        if (scanf("%d", &choice) != 1)
        {
            printf("This option is not available, please try again.\n");
            scanf("%*[^\n]");
            scanf("%*c");
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

        if (choice == 1)
        {
            char eye, nose, mouth;
            int size;

            printf("Enter symbols for the eyes, nose, and mouth:\n");
            if (scanf(" %c %c %c", &eye, &nose, &mouth) != 3)
            {
                printf("Invalid input. Please try again.\n");
                scanf("%*[^\n]");
                scanf("%*c");
                continue;
            }

            do
            {
                printf("Enter face size:\n");
                if (scanf("%d", &size) != 1 || size <= 0 || size % 2 == 0)
                {
                    printf("The face's size must be an odd and positive number, please try again:\n");
                    scanf("%*[^\n]");
                    scanf("%*c");
                    size = -1;
                }
            } while (size <= 0 || size % 2 == 0);

            int eye_spacing = size;
            int nose_spacing = (size + 1) / 2;

            printf("%c", eye);
            for (int i = 0; i < eye_spacing; i++)
            {
                printf(" ");
            }
            printf("%c\n", eye);

            for (int i = 0; i < nose_spacing; i++)
            {
                printf(" ");
            }
            printf("%c\n", nose);

            printf("\\");
            for (int i = 0; i < size; i++)
            {
                printf("_");
            }
            printf("/\n");
        }

        if (choice == 2)
        {
            int number, temp, digit_counter = 0, right_side = 0, left_side = 0;

            do
            {
                printf("Enter a number:\n");
                if (scanf("%d", &number) != 1 || number <= 0)
                {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%*[^\n]");
                    scanf("%*c");
                    number = -1;
                }
            } while (number <= 0);

            temp = number;
            while (temp > 0)
            {
                digit_counter++;
                temp /= 10;
            }

            if (digit_counter % 2 == 0)
            {
                printf("This number isn't balanced and destroys harmony.\n");
            }
            else
            {
                temp = number;
                int mid = digit_counter / 2;

                for (int i = 0; i < mid; i++)
                {
                    left_side += temp % 10;
                    temp /= 10;
                }

                temp /= 10; // Skip middle digit

                for (int i = 0; i < mid; i++)
                {
                    right_side += temp % 10;
                    temp /= 10;
                }

                if (left_side == right_side)
                {
                    printf("This number is balanced and brings harmony!\n");
                }
                else
                {
                    printf("This number isn't balanced and destroys harmony.\n");
                }
            }
        }

        if (choice == 3)
        {
            int number, sum = 0;

            do
            {
                printf("Enter a number:\n");
                if (scanf("%d", &number) != 1 || number <= 0)
                {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%*[^\n]");
                    scanf("%*c");
                    number = -1;
                }
            } while (number <= 0);

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

        if (choice == 4)
        {
            int number, prime = 1;

            do
            {
                printf("Enter a number:\n");
                if (scanf("%d", &number) != 1 || number <= 0)
                {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%*[^\n]");
                    scanf("%*c");
                    number = -1;
                }
            } while (number <= 0);

            if (number <= 1)
            {
                prime = 0;
            }
            else
            {
                for (int i = 2; i * i <= number; i++)
                {
                    if (number % i == 0)
                    {
                        prime = 0;
                        break;
                    }
                }
            }

            if (prime)
            {
                printf("This number completes the circle of joy!\n");
            }
            else
            {
                printf("The circle remains incomplete.\n");
            }
        }

        if (choice == 5)
        {
            int number;

            do
            {
                printf("Enter a number:\n");
                if (scanf("%d", &number) != 1 || number <= 0)
                {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%*[^\n]");
                    scanf("%*c");
                    number = -1;
                }
            } while (number <= 0);

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
                } while (current != 1 && current != 4);

                if (current == 1)
                {
                    printf("%d ", i);
                }
            }
            printf("\n");
        }

        if (choice == 6)
        {
            int smile = 0, cheer = 0, max = 0;
            int first_attempt = 1;

            while (1)
            {
                if (first_attempt)
                {
                    printf("Enter a smile and cheer number:\n");
                    first_attempt = 0;
                }

                if (scanf(" smile: %d, cheer: %d", &smile, &cheer) == 2 && smile > 0 && cheer > 0 && smile != cheer)
                {
                    break; // Valid input
                }
                else
                {
                    printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
                    scanf("%*[^\n]");
                    scanf("%*c");
                }
            }

            do
            {
                printf("Enter maximum number for the festival:\n");
                if (scanf("%d", &max) != 1 || max <= 0)
                {
                    printf("Only positive maximum number is allowed, please try again:\n");
                    scanf("%*[^\n]");
                    scanf("%*c");
                    max = -1;
                }
            } while (max <= 0);

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
    } while (1);

    return 0;
}
