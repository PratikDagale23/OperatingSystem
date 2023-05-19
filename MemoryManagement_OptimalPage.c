#include <stdio.h>
#include <stdlib.h>
# define MAX 100
int main()
{
    int num_pages, table_size;
    int reference_string[MAX];
    int page_table[MAX];

    printf("Name: Prajwal Arun Korade\n");
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
        for (int j = 0; j < table_size; j++)
        {
            if (page_table[j] == page_number)
            {
                page_found = 1;
                break;
            }
        }
        if (!page_found)
        {
            int farthest_page = -1;
            int farthest_distance = -1;
            for (int j = 0; j < table_size; j++)
            {
                int page_found_in_future = 0;
                for (int k = i + 1; k < num_pages; k++)
                {
                    if (page_table[j] == reference_string[k])
                    {
                        page_found_in_future = 1;
                        if (k - i > farthest_distance)
                        {
                            farthest_distance = k - i;
                            farthest_page = j;
                        }
                        break;
                    }
                }
                if (!page_found_in_future)
                {
                    farthest_page = j;
                    break;
                }
            }
            page_table[farthest_page] = page_number;
            page_faults++;
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
