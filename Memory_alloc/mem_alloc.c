#include<stdio.h>
void main()
{
    int memory[10], n, req, choice, j;
    printf("Enter the number of free memory locations: ");
    scanf("%d", &n);
    printf("Enter the size of free memory locations: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &memory[i]);
    }
    do{
        printf("\nFree Memory Spaces Available are: ");
        for(int i=0; i<n; i++)
        {
            printf("%d ", memory[i]);
        }
        printf("\n\t\t\t\tMemory Allocation\n\t\t\t\t=================\n\t1. First Fit\n\t2. Best Fit\n\t3. Worst Fit\n Enter Your Choice.....\n");
        scanf("%d", &choice);
        printf("Enter the memory space required: ");
        scanf("%d", &req);
        switch(choice)
        {
            case 1: for(j=0; j<n; j++)
                    {
                        if(req<=memory[j])
                        {
                            printf("%d is allocated\n", memory[j]);
                            for(int i=j; i<(n-1); i++)
                            {
                                memory[i]=memory[i+1];
                            }
                            n--;
                            break;
                        }
                    }
                    if(j==n)
                    {
                        printf("\nNo free memory available for that size...\n");
                    }
                    break;
            case 2: int min=-1, flag=0;
                    for(j=0; j<n; j++)
                    {
                        if(req<=memory[j])
                        {
                            if(min==-1)
                            {
                                min=j;
                            }
                            else{
                                if(memory[j]<memory[min])
                                {
                                    min=j;
                                }
                                
                            }
                            flag=1;
                        }    
                    }
                    if(flag==1)
                    {
                        printf("%d is allocated\n", memory[min]);
                        for(int i=min; i<(n-1); i++)
                        {
                            memory[i]=memory[i+1];
                        }
                        n--;
                    }
                    else
                    {
                        printf("\nNo free memory available for that size...\n");
                    }
                    break;
            case 3: int max=-1; 
                    flag=0;
                    for(j=0; j<n; j++)
                    {
                        if(req<=memory[j])
                        {
                            if(max==-1)
                            {
                                max=j;
                            }
                            else{
                                if(memory[j]>=memory[max])
                                {
                                    max=j;
                                }
                                
                            }
                            flag=1;
                        }
                    }
                    if(flag==1)
                    {
                        printf("%d is allocated\n", memory[max]);
                        for(int i=max; i<(n-1); i++)
                        {
                            memory[i]=memory[i+1];
                        }
                        n--;
                    }
                    else
                    {
                        printf("\nNo free memory available for that size...\n");
                    }
                    break;
        }
    }while(1);
}