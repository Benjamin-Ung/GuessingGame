//This is for part 2 of the in-class exercise
/*
Outline:
print out introduction info
prompt for user input (1,2,3) based on choices
switch()
    case 1: play game
    case 2: change limit
        check if it is valid input
    case 3: quit
        end program

seperate game function to run game/ takes in limit from main
    reads user input using scanf
    reply higher or lower depending on the random number
    quits the session if user types q
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void game(int limit){
    bool playing = true;
    int guess;
    char temp[10];
    time_t t;
    srand((unsigned)time(&t));

    int number = (rand() % limit-1) + 1;      //0-limit - 1 shifted to 1 - limit

    while(playing){
        printf("Guess a number from 1 - %d\n", limit);

        //actual user input scanf
        scanf("%s", &temp);

        //is the input a 'q', if not start comparing
        if(temp[0] == 'q'){   
            playing = false;
        }else{
            //subtract ascii value of 0 to find int value
            sscanf(temp,"%d", &guess);

            if(guess == number){                                            //number is guessed
                printf("Congratulations! You guessed the number!\n");
                playing = false;                                            //turn off session
            }else if(guess > number){
                //guess too high
                printf("lower\n");        
            }else if(guess < number){
                //guess too low
                printf("higher\n");
            }
        }
    }
}


int main(){
    int limit = 10, newLimit = 0, input = 2;
    int max = 100;
    bool running = true;

    //until prompted. The game will continue in the while loop
    while(running){
        printf("Hello. This is a guessing game. What option would you like?\n");
        printf("Press 1 to play a game\n");
        printf("Press 2 to change the max number\n");
        printf("Press 3 to quit\n");

        //reading user input
        scanf("%d",&input);

        //what are the cases for input
        switch(input){
            case 1:
                //playing game
                game(limit);
                break;
            case 2:
                //changing limit
                printf("What would you like to change the limit to? Max value is %d. The current number is %d\n", max, limit);
                scanf("%d",&newLimit);
                if(newLimit < 0){
                    printf("The limit must be greater than 0.\n");
                }else if(newLimit > max){
                    printf("The limit must be less than the max\n");
                }else{
                    limit = newLimit;
                    printf("limit changed to %d\n", limit);
                }
                break;
            case 3:
                //quiting game
                printf("Powering off. Thanks for playing!\n");
                running = false;
                break;
            default:
                //unknown input
                printf("that is not a valid command. Please try again.\n");
        }
    }
    return 0;
}

