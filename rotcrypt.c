#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define LOWER_BOUND_UPPERCASE 65  // a
#define UPPER_BOUND_UPPERCASE 90  // z
#define LOWER_BOUND_LOWERCASE 97  // A
#define UPPER_BOUND_LOWERCASE 122 // Z

bool is_uppercase_letter(int index) {
	return
        (index >= LOWER_BOUND_UPPERCASE &&
         index <= UPPER_BOUND_UPPERCASE);
}

bool is_lowercase_letter(int index) {
    return
        (index >= LOWER_BOUND_LOWERCASE &&
         index <= UPPER_BOUND_LOWERCASE);
}

bool is_ascii_letter(int index) {
    return 
        (is_uppercase_letter(index) ||
         is_lowercase_letter(index));
}

char get_rot_char(char c, int shift) {
    int inputInt = (int) c;
    int outputInt = inputInt;
    if (is_ascii_letter(inputInt)) {
        outputInt = inputInt + shift;
        
        bool is_lowercase = is_lowercase_letter(inputInt);

        int lower_bound = 
            is_lowercase
		        ? LOWER_BOUND_LOWERCASE
		        : LOWER_BOUND_UPPERCASE;
        int upper_bound = 
            is_lowercase
                ? UPPER_BOUND_LOWERCASE 
                : UPPER_BOUND_UPPERCASE;

        if (outputInt > upper_bound) {
            /* Illegal; wrap back to begin */
            // Calculate delta
            outputInt -= upper_bound;
            // Get wrapped index
            outputInt += lower_bound - 1;
        }
    }
    return (char) outputInt;
}

int main(int argc, char* argv[]) {
	int input_length = strlen(argv[1]);
    char string_input[input_length];
    strcpy(string_input, argv[1]);
    int i;
    for (i = 0; i < input_length; i++) {
        printf("%c", get_rot_char(string_input[i], 13));
    }
    return 0;
}
