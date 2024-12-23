#include<stdio.h>

int main() 
{
    int f[50], p, i, j, k, a, st, len, n, c;

    // Initialize the file allocation status to 0 (unallocated)
    for(i = 0; i < 50; i++) 
        f[i] = 0;

    // Input the number of already allocated blocks
    printf("Enter how many blocks are already allocated: ");
    scanf("%d", &p);

    // Input the allocated block numbers
    printf("Enter the block numbers that are already allocated: ");
    for(i = 0; i < p; i++) 
    {
        scanf("%d", &a);
        f[a] = 1;  // Mark the block as allocated
    }

    // Input the starting index and length for the new file
    printf("Enter the starting index block and length: ");
    scanf("%d%d", &st, &len);

    k = len;

    // Try to allocate the file blocks starting from 'st'
    for(j = st; j < (k + st); j++) 
    {
        if(f[j] == 0) 
        {
            f[j] = 1;  // Mark the block as allocated
            printf("\n%d -> %d", j, f[j]); // Output the block allocation
        } 
        else 
        {
            printf("\n%d -> File is already allocated", j);  // If block is already allocated
            k++;  // Increment length to allocate another block
        }
    }

    // Ask if the user wants to allocate another file
    printf("\nIf you want to enter one more file? (yes-1/no-0): ");
    scanf("%d", &c);

    // Repeat the process if the user enters 1
    if(c == 1) 
        goto X;  // Loop back for new file allocation
    else 
        return 0;  // Exit the program
}
