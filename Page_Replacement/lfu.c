#include <stdio.h>
void print(int frameno, int frame[])
{
    int j;
    for (j = 0; j < frameno; j++)
        printf("%d\t", frame[j]);
    printf("\n");
}
int main()
{
    int i, j, k, n, page[50], frameno, frame[10], move = 0, flag, count = 0, count1[10] = {0},
                                                  repindex, leastcount, current=0, counts=0, flag2=0;
    float rate;
    printf("Enter the number of pages\n");
    scanf("%d", &n);
    printf("Enter the page reference numbers\n");
    for (i = 0; i < n; i++)
        scanf("%d", &page[i]);
    printf("Enter the number of frames\n");
    scanf("%d", &frameno);
    for (i = 0; i < frameno; i++)
        frame[i] = -1;
    printf("Page reference string\tFrames\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t\t", page[i]);
        flag = 0;
        for (j = 0; j < frameno; j++)
        {
            if (page[i] == frame[j])
            {
                flag = 1;
                count1[j]++;
                printf("No replacement\n");
                break;
            }
        }
        if (flag == 0 && count < frameno)
        {
            frame[move] = page[i];
            count1[move] = 1;
            move = (move + 1) % frameno;
            count++;
            print(frameno, frame);
        }
        else if (flag == 0)
        {
            repindex = 0;
            leastcount = count1[current];
            counts=0;
            for (j = current; counts!=frameno; j=(j+1)%frameno)
            {

                if (count1[j] < leastcount)
                {
                    repindex = j;
                    leastcount = count1[j];
                    current=(j+1)%frameno;
                    flag2=1;
                }
                counts=counts+1;
            }
            if(flag2==0)
            {
                repindex=current;
                current=(current+1)%frameno;
            }
            flag2=0;
            frame[repindex] = page[i];
            count1[repindex] = 1;
            count++;
            print(frameno, frame);
        }
    }
    rate = (float)count / (float)n;
    printf("Number of page faults is %d\n", count);
    printf("Fault rate is %f\n", rate);
    return 0;
}