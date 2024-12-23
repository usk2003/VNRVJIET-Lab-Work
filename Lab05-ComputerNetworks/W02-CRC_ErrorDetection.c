#include <stdio.h>
#include <string.h>

#define N 4 // Assuming the generator polynomial is 4 bits long.

char data[28];      // Adjusted size based on the expected maximum input data size.
char check_value[28];
char gen_poly[10];  // Maximum length for the generator polynomial.
int data_length, i, j;

// XOR function to simulate the division in CRC
void XOR() {
    for (j = 1; j < N; j++) {
        check_value[j] = (check_value[j] == gen_poly[j]) ? '0' : '1';
    }
}

// CRC calculation function
void crc() {
    // Initialize check_value with data (append 0's to the end)
    for (i = 0; i < N; i++) {
        check_value[i] = data[i];
    }

    // Loop over the data to perform the division
    do {
        if (check_value[0] == '1') {
            XOR();  // If the leading bit is '1', perform XOR with the generator polynomial.
        }

        // Shift the check_value to the left by 1 bit.
        for (j = 0; j < N - 1; j++) {
            check_value[j] = check_value[j + 1];
        }

        // Move the next bit from the data into the check_value.
        check_value[j] = data[i++];
    } while (i < data_length + N - 1);  // Process the data till the padded size.
}

int main() {
    printf("\nEnter data to be transmitted: ");
    scanf("%s", data);

    printf("\nEnter the Generating polynomial: ");
    scanf("%s", gen_poly);

    // Get the length of the data to be transmitted.
    data_length = strlen(data);

    // Pad the data with N-1 zeros (for CRC calculation).
    for (i = data_length; i < data_length + N - 1; i++) {
        data[i] = '0';
    }
    data[i] = '\0';  // Null-terminate the string after padding.

    printf("\nData padded with N-1 zeros: %s", data);

    // Initialize the check_value array with '0's before starting CRC calculation.
    memset(check_value, '0', sizeof(check_value));

    // Perform CRC calculation
    crc();

    printf("\nCRC or Check value is: %s", check_value);

    // Append the CRC to the original data.
    for (i = data_length; i < data_length + N - 1; i++) {
        data[i] = check_value[i - data_length];
    }
    data[data_length + N - 1] = '\0';  // Null-terminate the final data string.

    printf("\nFinal data to be sent: %s", data);

    printf("\n");
    return 0;
}
