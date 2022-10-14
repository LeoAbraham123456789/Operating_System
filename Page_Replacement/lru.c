#include <stdio.h>

void main()
{
    int nf, np, pgf = 0, count = 0, temp1, temp2, flag = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &nf);
    printf("Enter the number of pages: ");
    scanf("%d", &np);
    int fr[nf], pg, frd[nf];
    for (int i = 0; i < nf; i++)
    {
        fr[i] = -1;
        frd[i] = nf - i - 1;
    }
    printf("Enter the pages: ");
    for (int j = 0; j < np; j++)
    {
        scanf("%d", &pg);
        flag = 0;
        if (count < nf)
        {
            fr[count] = pg;
            pgf++;
            count++;
        }
        else
        {
            for (int k = 0; k < nf && flag == 0; k++)
            {
                if (pg == fr[k])
                {
                    // temp1 = frd[0];
                    // frd[0]=k;
                    for (int l = 0; l < nf; l++)
                    {
                        // temp2 = frd[l];
                        // if (temp2 != k)
                        // {
                        //     frd[l] = temp1;
                        //     if (l != (nf - 1))
                        //         temp1 = frd[l+1];
                        // }
                        if(frd[l]==k)
                        {
                            for(int t=l; t>0; t--)
                            {
                                frd[t]=frd[t-1];
                            }
                            break;
                        }
                    }
                    frd[0]=k;
                    flag = 1;
                }
            }
            if (flag != 1)
            {
                
                fr[frd[nf - 1]] = pg;
                pgf++;
                temp1 = frd[nf - 1];
                for (int m = nf - 1; m > 0; m--)
                {
                    frd[m] = frd[m - 1];
                }
                frd[0] = temp1;
            }
            for (int i = 0; i < nf; i++)
            {
                printf("%d ", frd[i]);
            }
        }
        for (int i = 0; i < nf; i++)
        {
            printf("%d ", fr[i]);
        }
    }
}