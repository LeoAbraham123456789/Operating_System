#include<stdio.h>
void main()
{
	int requestQueue[100],m,n,choice,start,i,trackmov,j;
	int temp[100],temps;
	char dir;
	printf("Enter the number of tracks:");
	scanf("%d",&n);
	printf("Input the number of tracks in request queue:");
	scanf("%d",&m);
	printf("Input the numbers in request queue:");
	for(i=0;i<m;++i)
	{
		scanf("%d",&requestQueue[i]);
	}
	printf("Input the Head Position:");
	scanf("%d",&start);
	printf("1.FCFS\n2.SCAN\n3.C-CSAN\nInput your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:	if(requestQueue[0]>start)
					trackmov=requestQueue[0]-start;
				else
					trackmov=start-requestQueue[0];
				for(i=0;i<m-1;++i)
				{
					if(requestQueue[i]>requestQueue[i+1])
						trackmov+=requestQueue[i]-requestQueue[i+1];
					else
						trackmov+=requestQueue[i+1]-requestQueue[i];
				}
				printf("Seek sequence is:");
				for(i=0;i<m;++i)
					printf("%d,",requestQueue[i]);
				printf("\nTotal seek count:%d",trackmov);
				break;
		case 2: 
				printf("Select Direction(L/R)");
				getchar();
				scanf("%c",&dir);
				if(dir=='r'||dir=='R')
				{
					trackmov=n-1-start;
					int small = requestQueue[0];
					for(i=1;i<m;++i)
					{
						if(requestQueue[i]<small)
						{
							small=requestQueue[i];
						}
					}
					trackmov+=n-1-small;
				printf("Seek sequence is:");
				for(i=0;i<m;++i)
				{
					temp[i]=requestQueue[i];
				}
				for(i=0;i<m;++i)
				{
					for(j=0;j<m-i-1;++j)
					{
						if(temp[j]>temp[j+1])
						{
							temps=temp[j];
							temp[j]=temp[j+1];
							temp[j+1]=temps;
						}
					}
				}

				for(i=0;i<m;++i)
				{
					if(temp[i]>start)
					printf("%d,",temp[i]);
				}
				printf("%d,",n-1);
				for(i=m-1;i>=0;--i)
				{
					if(temp[i]<start)
						printf("%d,",temp[i]);
				}
			}
			else if(dir=='l' || dir=='L')
			{
				trackmov=start;
				int large=requestQueue[0];
				printf("Seek Sequence is:");
				for(i=0;i<m;++i)
				{
					temp[i]=requestQueue[i];
				}
				for(i=0;i<m;++i)
				{
					if(requestQueue[i]>large)
						large=requestQueue[i];
				}
				trackmov+=large;
				for(i=0;i<m;++i)
				{
					for(j=0;j<m-i-1;++j)
					{
						if(temp[j]<temp[j+1])
						{
							temps=temp[j];
							temp[j]=temp[j+1];
							temp[j+1]=temps;
						}
					}
				}
				for(i=0;i<m;++i)
				{
					if(temp[i]<start)
						printf("%d,",temp[i]);
				}
				printf("0,");
				for(i=m-1;i>=0;--i)
				{
					if(temp[i]>start)
						printf("%d,",temp[i]);
				}
			}
				printf("\nTotal seek count:%d",trackmov);
				break;
	case 3:		trackmov=n-1-start;
				trackmov+=n-1;
				for(i=0;i<m;++i)
				{
					temp[i]=requestQueue[i];
				}
				for(i=0;i<m;++i)
				{
					for(j=0;j<m-i-1;++j)
					{
						if(temp[j]>temp[j+1])
						{
							temps=temp[j];
							temp[j]=temp[j+1];
							temp[j+1]=temps;
						}
					}
				}
				for(i=0;i<m;++i)
				{
					if(temp[i]>=start)
						break;
				}
				trackmov+=temp[i-1];
				for(i=0;i<m;++i)
				{
					if(temp[i]>start)
						printf("%d,",temp[i]);
				}
				printf("199,");
				printf("0,");
				for(i=0;i<m;++i)
				{
					if(temp[i]<start)
					{
						printf("%d,",temp[i]);
					}
				}
			
				printf("\nTotal seek count:%d",trackmov);
				break;

	}

}