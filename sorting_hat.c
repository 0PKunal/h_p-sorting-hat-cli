#include <stdio.h>
#include <string.h>

// Function to ask a question and update house scores based on the answer
void ask_question(const char *question, const char *options[], int scores[][4], int house_scores[]) {
    printf("\n%s\n", question);
    for (int i = 0; options[i] != NULL; i++) {
        printf("    %d) %s\n", i + 1, options[i]);
    }

    int answer;
    while (1) {
        printf("Enter your answer: ");
        if (scanf("%d", &answer) == 1 && answer >= 1 && options[answer - 1] != NULL) {
            for (int i = 0; i < 4; i++) {
                house_scores[i] += scores[answer - 1][i];
            }
            break;
        } else {
            printf("Invalid input. Please enter a number corresponding to the options.\n");
            while (getchar() != '\n'); // Clear input buffer
        }
    }
    printf("--------------------\n");
}

int main() {
    // Initialize scores for each house
    const char *houses[] = {"Gryffindor", "Ravenclaw", "Hufflepuff", "Slytherin"};
    int house_scores[4] = {0, 0, 0, 0};

    // Questions and scoring logic
    const char *questions[] = {
        "Q1) Do you like Dawn or Dusk?",
        "Q2) When I’m dead, I want people to remember me as:",
        "Q3) Which kind of instrument most pleases your ear?"
    };

    const char *options[][5] = {
        {"Dawn", "Dusk", NULL},
        {"The Good", "The Great", "The Wise", "The Bold", NULL},
        {"The violin", "The trumpet", "The piano", "The drum", NULL}
    };

    int scores[][4][4] = {
        {{1, 1, 0, 0}, {0, 0, 1, 1}},
        {{0, 0, 2, 0}, {0, 0, 0, 2}, {0, 2, 0, 0}, {2, 0, 0, 0}},
        {{0, 0, 0, 4}, {0, 0, 4, 0}, {0, 4, 0, 0}, {4, 0, 0, 0}}
    };

    // Ask each question
    for (int i = 0; i < 3; i++) {
        ask_question(questions[i], options[i], scores[i], house_scores);
    }

    // Determine the house with the highest score
    int top_score = house_scores[0];
    int top_index = 0;
    for (int i = 1; i < 4; i++) {
        if (house_scores[i] > top_score) {
            top_score = house_scores[i];
            top_index = i;
        }
    }

    // Print the results
    printf("House Scores:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s: %d\n", houses[i], house_scores[i]);
    }

    printf("\nCongratulations! You belong to: %s\n", houses[top_index]);

    return 0;
}