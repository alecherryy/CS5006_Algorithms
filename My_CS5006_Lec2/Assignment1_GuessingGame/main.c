// CS 5006 - Guessing game

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    /* constant for number of games */
    const int ROUNDS = 5;

    int secret_num, user_guess, rounds_played, game_num, game_summary[ROUNDS];
    
    /* use time to seed */
    srand(time(NULL));	
    
    /* initialize rounds_played at 0 */     
    rounds_played = 0;	
   
    /* player however many rounds are specified in the constant */
    for (rounds_played; rounds_played < ROUNDS; rounds_played++) {
        printf("===========================\nPick a number from 1 to 10\n===========================\n");
	
        /* generate a random number between 1 and 10 */
	secret_num = 1 + rand()% 10;
	user_guess = 0;
        /* count how many guesses */
        int counter = 0;
        
        /* keep prompting user for answer until it's correct */
        while (printf("Your guess: ") > 0 && scanf("%d", &user_guess) != secret_num) {

            counter++;
            
           /* low hint */ 
            if ( user_guess<secret_num ) {
                printf("You guessed too low!\n");
            }

            /* high hint */  
            else if ( user_guess>secret_num ) {
                printf("You guessed too high!\n");
            } 
           
            /* correct */  
            else {
                printf("You guessed correctly!\n");
                game_summary[rounds_played] = counter;
                break;
            }
        }
    } 
    
    /* print out summary of the game */    
    printf("===========================\nYour game summery\n===========================\n");
    game_num = 0; 

    for (game_num; game_num < ROUNDS; game_num++) {
	printf("In round %d, you guessed %d times\n",game_num,game_summary[game_num]);
    }
}
