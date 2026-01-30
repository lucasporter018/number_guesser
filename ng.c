// This prgram is just a fun little number guesser game


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main() {


    int randomNum, guessedNum, count;
    bool playing;
    char response;

    count = 0;
    // Ask user to start the game 
    printf("Welcome to the the number guessing game!\n" 
       "Would you like to play (Y/N)? ");
    scanf("%s", &response);

    // Check to see if user wants to play
    if (response == 'Y' || response == 'y') {
        playing = true;
    }

    // Generate a new random number
    srand(time(NULL));
    randomNum = (rand() % 10) + 1;

    while (playing) {
       
        // Increment the counter
        count++; 
        // Prompt user for the number
        printf("Enter a number (1 - 10): ");
        scanf("%d", &guessedNum);     

        // Check to see if guessed number is valid
        while (guessedNum <= 0 || guessedNum > 10) {
            printf("Error: Please enter a number between 1 and 10\n");
            printf("Enter a number (1 - 10): ");
            scanf("%d", &guessedNum); 
        }

        // Check to see if number guessed is correct
        if (guessedNum == randomNum) {
            // If correct, ask user to play again
            printf("Correct!\n");
            if (count == 1) {
                printf("It took you %d try!", count);
            } else {
               printf("It took you %d tries!\n", count);
            }
            printf("Play again (Y/N)? ");
            scanf("%s", &response);
            // Check user response
            if (response == 'Y' || response == 'y') {
               count = 0;
               playing = true; 
               randomNum = (rand() % 11) + 1;
            } else {
                playing = false;
            }
        } else {
            printf("Wrong!\n");
            if (guessedNum > randomNum) {
                printf("To high...\n");
            } else {
                printf("To low...\n");
            }
        }
    }
}
