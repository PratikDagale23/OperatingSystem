#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    int num_pages, table_size;
    int reference_string[MAX];
    int page_table[MAX];

    printf("Name: Prawjal Arun Korade\n");
    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);
    printf("Enter number of frames: ");
    scanf("%d", &table_size);
    printf("Enter reference string: ");
    for (int i = 0; i < num_pages; i++)
    {
        scanf("%d", &reference_string[i]);
    }
    int page_faults = 0;
    for (int i = 0; i < table_size; i++)
    {
        page_table[i] = -1;
    }
    for (int i = 0; i < num_pages; i++)
    {
        int page_number = reference_string[i];
        int page_found = 0;
        int index_of_mru_page = 0;
        for (int j = 0; j < table_size; j++)
        {
            if (page_table[j] == page_number)
            {
                page_found = 1;
                index_of_mru_page = j;
                break;
            }
        }
        if (!page_found)
        {
            page_table[index_of_mru_page] = page_number;
            page_faults++;
            for (int j = index_of_mru_page; j > 0; j--)
            {
                page_table[j] = page_table[j - 1];
            }
            page_table[0] = page_number;
        }
        printf("Page table: ");
        for (int j = 0; j < table_size; j++)
        {
            if (page_table[j] == -1)
            {
                printf("- ");
            }
            else
            {
                printf("%d ", page_table[j]);
            }
        }
        printf("\n");
    }
    printf("Total page faults: %d\n", page_faults);
    return 0;
}
