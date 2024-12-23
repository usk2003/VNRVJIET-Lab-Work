#include<stdio.h>

int main() 
{
    int f[50], i, st, j, len, c, k;
    
    // Initialize the disk blocks to 0 (unallocated)
    for(i = 0; i < 50; i++) 
        f[i] = 0;

    // Loop for file allocation
    X:
    printf("\nEnter the starting block & length of the file: ");
    scanf("%d%d", &st, &len);

    // Try to allocate the file blocks
    for(j = st; j < (st + len); j++) 
    {
        if(f[j] == 0) 
        {
            f[j] = 1;
            printf("\n%d -> %d", j, f[j]); // Show allocated block
        } 
        else 
        {
            printf("Block already allocated\n");
            break; // Stop allocation if a block is already allocated
        }
    }

    // Check if the file was successfully allocated
    if(j == (st + len)) 
        printf("\nThe file is allocated to the disk.\n");

    // Ask the user if they want to allocate more files
    printf("\nIf you want to enter more files? (y-1/n-0): ");
    scanf("%d", &c);

    // Based on user input, either repeat or exit
    if(c == 1) 
        goto X; // Repeat file allocation process
    else 
        return 0; // Exit the program
}
