/******************
Name:Davidi Hershkovitz
ID:214165417
Assignment: ex2
*******************/

#include <stdio.h>

int main()
{
	int choice;
	while (1)
	{
		printf("Choose an option:\n");
		printf("    1. Happy Face\n");
		printf("    2. Balanced Number\n");
		printf("    3. Generous Number\n");
		printf("    4. Circle Of Joy\n");
		printf("    5. Happy Numbers\n");
		printf("    6. Festival Of Laughter\n");
		printf("    7. Exit\n");
		scanf("%d", &choice);

		if (choice < 1 || 7 < choice) {
			printf("This option is not available, please try again.\n");
			continue;
		}

		if (choice == 7) {
			printf("Thank you for your journey through Numeria!\n");
			break;
		}

		if (choice == 1) {
			char eye, nose, mouth;
			int size;

			printf("Enter symbols for the eyes, nose, and mouth:\n");
			scanf(" %c", &eye);
			scanf(" %c", &nose);
			scanf(" %c", &mouth);

			do {
				printf("Enter face size:\n");
				scanf("%d", &size);

				if (size <= 0 || size % 2 == 0) {
					printf("The face's size must be an odd and positive number, please try again:\n");
				}
			} while (size <= 0 || size % 2 == 0);

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

		if (choice == 2)
		{
			int number, temp, digit_counter = 0, right_side = 0, left_side = 0;
			do
			{
				printf("Enter a number:\n");
				scanf("%d", &number);

				if (number <= 0) {
					printf("Only positive number is allowed, please try again:\n");
				}
			} while (number <= 0);

			temp = number;
			while (temp > 0) {
				digit_counter++;
				temp = temp / 10;
			}

			if (digit_counter % 2 == 0) {
				printf("This number isn't balanced and destroys harmony.\n");
			} else {
				temp = number;
				int mid = (digit_counter / 2);

				for (int i = 0; i < mid; i++) {
					left_side += temp % 10;
					temp = temp / 10;
				}

				temp = temp / 10; // Skip the middle digit

				for (int i = 0; i < mid; i++) {
					right_side += temp % 10;
					temp = temp / 10;
				}

				if (left_side == right_side) {
					printf("This number is balanced and brings harmony!\n");
				} else {
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
				scanf("%d", &number);
				if (number <= 0){
					printf("Only positive number is allowed, please try again:\n");}
			}	while (number <= 0);

			for (int i = 1; i <= number / 2; i++) {
				if (number % i == 0)
				{
					sum += i; }
			}
			if (sum > number) {
				printf("This number is generous!\n");
			} else {
				printf("This number does not share.\n");
			}
		}
		if (choice == 4)
		{
			int number, prime = 1;
			do
			{
				printf("Enter a number:\n");
				scanf("%d", &number);
				if (number <= 0){
					printf("Only positive number is allowed, please try again:\n");
				}
			}while (number <= 0);


				if (number <= 1){
					prime = 0;
				}
				else
				{
					for (int i = 2; i * i <= number; i++)
					{
						if (number % i == 0){
							prime = 0;
							break;
						}
					}
				}

			if (prime) {
				printf("This number completes the circle of joy!\n");
						} else { printf("The circle remains incomplete.\n");
						}
					}
				}





					return 0;
}




























			// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
			/* Example:
			* n = 3:
			* 0   0
			*   o
			* \___/
			*/


			// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
			// and the sum of all digits to the right of the middle digit(s) are equal
			/* Examples:
			Balanced: 1533, 450810, 99
			Not blanced: 1552, 34
			Please notice: the number has to be bigger than 0.
			*/

			// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
			/* Examples:
			Abudant: 12, 20, 24
			Not Abudant: 3, 7, 10
			Please notice: the number has to be bigger than 0.
			*/

			// Case 4: determine wether a number is a prime.
			/* Examples:
			This one brings joy: 3, 5, 11
			This one does not bring joy: 15, 8, 99
			Please notice: the number has to be bigger than 0.
			*/


			// Happy numbers: Print all the happy numbers between 1 to the given number.
			// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
			/* Examples:
			Happy :) : 7, 10
			Not Happy :( : 5, 9
			Please notice: the number has to be bigger than 0.
			*/

			// Festival of Laughter: Prints all the numbers between 1 the given number:
			// and replace with "Smile!" every number that divided by the given smile number
			// and replace with "Cheer!" every number that divided by the given cheer number
			// and replace with "Festival!" every number that divided by both of them
			/* Example:
			6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
			*/

