#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* tab = NULL;

    // Array of 3 int
    tab = malloc(3 * sizeof(int));

    if (tab == NULL)
    {
        fprintf(stderr, "Allocation impossible");
        exit(EXIT_FAILURE);
    }

    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;

    int* temp = NULL;
    // Realloc free tab and copy data
    temp = realloc(tab, 4 * sizeof(int));

    if (temp == NULL)
    {
        fprintf(stderr, "Reallocation impossible");
        free(tab);
        exit(EXIT_FAILURE);
    }
    else
    {
        tab = temp;
    }

    tab[3] = 4;

    for (int i = 0; i < 4; i++)
    {
        printf("tab[%d] = %d \n", i, tab[i]);
    }
        
    free(tab);
}