
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void nextState(char ch_value);

char string_test[] = "aaaab";
int i;

typedef enum {
    state_start = 0,
    state_1 = 1,
    state_2 = 3,
    state_halt = 2
} FSM_States_t;

FSM_States_t current_state;

void nextState(char ch_value) {
    if (current_state == state_start) {

        if (ch_value == 'a') {
            current_state = state_1;
        } else if (ch_value == 'b') {
            current_state = state_halt;
        }

    } else if (current_state == state_1) {

        if (ch_value == 'a') {
            current_state = state_start;
        } else if (ch_value == 'b') {
            current_state = state_halt;
        }

    } else if (current_state == state_halt) {

        if (ch_value == 'a') {
            current_state = state_2;
        } else if (ch_value == 'b') {
            current_state = state_2;
        }

    } else if (current_state == state_2) {

        if (ch_value == 'a') {
            current_state = state_2;
        } else if (ch_value == 'b') {
            current_state = state_2;
        }
    }
}

int main(int argc, char** argv) {
    int len_of_string = strlen(string_test);
    current_state = state_start;

    for (i = 0; i < len_of_string; i++) {
        nextState(string_test[i]);
    }

    if (state_halt == current_state) {
        printf("%s\n", "accepted");
    } else {
        printf("%s\n", "not accepted");
    }

    return (EXIT_SUCCESS);
}

