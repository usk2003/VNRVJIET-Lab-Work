#include <stdio.h>
#include <string.h>

int main() {
    char a[30], fs[50] = " ", t[3], sd, ed, x[3], s[3], d[3], y[3], ds[50] = " ";
    int i, len;

    // Input for characters to be stuffed
    printf("Enter characters to be stuffed: ");
    scanf("%s", a);

    // Input for starting and ending delimiters
    printf("\nEnter a character that represents starting delimiter: ");
    scanf(" %c", &sd);
    printf("\nEnter a character that represents ending delimiter: ");
    scanf(" %c", &ed);

    // Initialize the delimiters and the stuffed string
    x[0] = s[0] = s[1] = sd;
    x[1] = s[2] = '\0';
    y[0] = d[0] = d[1] = ed;
    d[2] = y[1] = '\0';

    // Add starting delimiter to the stuffed string
    strcat(fs, x);

    // Loop through input string and apply stuffing
    for (i = 0; i < strlen(a); i++) {
        t[0] = a[i];
        t[1] = '\0';

        // Check if character matches delimiters and stuff accordingly
        if (t[0] == sd) {
            strcat(fs, s);  // Stuff starting delimiter
        } else if (t[0] == ed) {
            strcat(fs, d);  // Stuff ending delimiter
        } else {
            strcat(fs, t);  // Append the character as it is
        }
    }

    // Add ending delimiter to the stuffed string
    strcat(fs, y);

    // Output the stuffed string
    printf("\nAfter stuffing: %s", fs);

    // Character de-stuffing from stuffed string
    len = strlen(fs);

    // Loop to remove the stuffed delimiters
    for (i = 2; i < len - 1; i++) {
        fs[i - 1] = fs[i];
    }
    fs[i - 1] = '\0';  // Null-terminate the string

    // Output the de-stuffed string
    printf("\nAfter de-stuffing: %s", fs);

    // Wait for user input before closing (for some compilers)
    getchar();

    return 0;
}
