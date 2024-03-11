#include <stdio.h>
#include <stdlib.h>

// creates the function that will calculate the possible combinations of scoring plays
void score_combinations(int score) {
    // initialize the abbreviated variables for the scoring plays which include:
    // touchdowns, 2-point conversions, field goals, and safeties
    int td2p, td1p, td, fg, safety;

    // create a nested for loop to calculate the possible combinations of scoring plays
    // starting with the 2-point conversions, then the field goals, then the touchdowns, and finally the safeties
    for (td2p = 0; td2p * 8 <= score; td2p++)
        // loop that checks for the 2-point conversions
        for (td1p = 0; td1p * 7 + td2p * 8 <= score; td1p++)
            // loop that checks for the touchdowns
            for (td = 0; td * 6 + td1p * 7 + td2p * 8 <= score; td++)
                // loop that checks for the field goals
                for (fg = 0; fg * 3 + td * 6 + td1p * 7 + td2p * 8 <= score; fg++)
                    // loop that checks for the safeties
                    for (safety = 0; safety * 2 + fg * 3 + td * 6 + td1p * 7 + td2p * 8 <= score; safety++)
                        // if the sum of the scoring plays is equal to the score, print the possible combinations
                        if (+ safety * 2 + fg * 3 + td * 6 + td1p * 7 + td2p * 8 == score)
                            // prints the combination of plays in the format of the sample output
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2p, td1p, td, fg, safety);
}

// creates the main function to prompt the user for input
int main() {
    // create a variable to store the user input
    int user_input;
    // prompt the user for input and store the value in the user_input variable
    while (user_input != 0 && user_input != 1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &user_input);
        // if the user input is 0 or 1, break the loop and end the program
        if (user_input == 0 || user_input == 1) {
            break;
        }
        // if the user input is not 0 or 1, calculate the scores by passing the user input to the score_combinations function
        printf("possible combinations of scoring plays:\n");
        score_combinations(user_input);
    }
}