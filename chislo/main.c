#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>  // For using _kbhit() and _getch()

void start_game() {
    int number, guess, attempts = 3;
    char play_again;

    // Initialize random number generator
    srand(time(NULL));
    number = rand() % 11; // The number to guess is between 0 and 10

    printf("A number between 0 and 10 has been chosen. You have 3 attempts to guess it.\n");

    while (attempts > 0) {
        printf("\nAttempt %d: Enter a number: ", 4 - attempts);

        // Using scanf_s for safe input
        scanf_s("%d", &guess);

        if (guess < 0 || guess > 10) {
            printf("The number must be between 0 and 10!\n");
            continue;
        }

        if (guess == number) {
            printf("Congratulations! You guessed the number %d.\n", number);
            break;
        }
        else if (guess < number) {
            printf("The guessed number is higher!\n");
        }
        else {
            printf("The guessed number is less!\n");
        }

        attempts--;
    }

    if (attempts == 0 && guess != number) {
        printf("Sorry, you didn't guess. The number was %d.\n", number);
    }

    printf("\nPress Q to exit or any other key to start a new game: ");
    play_again = _getch(); // Wait for key press

    if (play_again == 'Q' || play_again == 'q') {
        printf("\nYou exited the game.\n");
    }
    else {
        start_game(); // Restart the game
    }
}

int main() {
    printf("Welcome to the 'Guess the Number' game!\n");
    start_game();
    return 0;
}
