#include <stdio.h>
#define MAX 100
int main()
{
    int no_pages, no_frames;
    int pages[MAX];
    int frames[MAX];
    printf("\nName: Prajwal Arun Korade");
    printf("\nEnter number of pages : ");
    scanf("%d", &no_pages);
    printf("Enter number of frames : ");
    scanf("%d", &no_frames);
    pages[no_pages], frames[no_frames];
    int current_frame = 0, page_fault = 0, is_valid;
    printf("\nPages are : ");
    for (int i = 0; i < no_pages; i++)
        scanf("%d", &pages[i]);
    for (int i = 0; i < no_frames; i++)
        frames[i] = -1;
    printf("\tRef string\t Page frames\n");
    for (int i = 0; i < no_pages; i++)
    {
        printf("%d\t\t", pages[i]);
        is_valid = 0;
        for (int k = 0; k < no_frames; k++)
        {
            if (pages[i] == frames[k])
            {
                is_valid = 1;
                break;
            }
        }
        if (is_valid == 0)
        {
            frames[current_frame] = pages[i];
            current_frame = (current_frame + 1) % no_frames;
            page_fault++;
        }
        for (int l = 0; l < no_frames; l++)
        {
            printf("%d\t", frames[l]);
        }
        printf("\n");
    }
    printf("Page fault is %d ", page_fault);
    return 0;
}
