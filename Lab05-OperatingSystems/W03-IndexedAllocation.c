#include<stdio.h>

int f[50], i, k, j, inde[50], n, c, count = 0, p;

int main() 
{
    // Initialize the file blocks to 0 (unallocated)
    for(i = 0; i < 50; i++) 
        f[i] = 0;

    // Loop for file allocation
    x:
    printf("Enter index block: ");
    scanf("%d", &p);

    // Check if the index block is already allocated
    if(f[p] == 0) 
    {
        f[p] = 1;  // Mark the block as allocated
        printf("Enter number of files on index: ");
        scanf("%d", &n);  // Read the number of files
    } 
    else 
    {
        printf("Block already allocated\n");
        goto x;  // Repeat if block is already allocated
    }

    // Read the file indices
    for(i = 0; i < n; i++) 
        scanf("%d", &inde[i]);

    // Check if any of the file blocks are already allocated
    for(i = 0; i < n; i++) 
    {
        if(f[inde[i]] == 1) 
        {
            printf("Block already allocated\n");
            goto x;  // Repeat if any block is already allocated
        }
    }

    // Mark the file blocks as allocated
    for(j = 0; j < n; j++) 
        f[inde[j]] = 1;

    printf("\nFile allocated successfully.\n");
    printf("File indexed:\n");

    // Display the allocation details
    for(k = 0; k < n; k++) 
        printf("%d -> %d: %d\n", p, inde[k], f[inde[k]]);

    // Ask the user if they want to enter more files
    printf("Enter 1 to enter more files and 0 to exit: ");
    scanf("%d", &c);

    // If the user enters 1, repeat the process
    if(c == 1) 
        goto x;
    else 
        return 0;  // Exit the program
}
