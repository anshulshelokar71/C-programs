#include<stdio.h>

typedef struct hotelinfo
{
	char name[20];
	char address[20];
	float
	 grade;
	int noofrooms;
	int charges;
	
}hinfo;

int main()
{
	hinfo h[5];
	
	for (int i=0; i<5; i=i+1)
	{
		printf("\nTaking information for hotel no %d\n",i);
		printf("Enter the names of the hotels:-\n");
		scanf("%s",h[i].name);
		printf("Enter the address in brief:-\n");
		fgets(h[i].address,20,stdin);
		printf("Enter the grade ot of 10:-\n");
		scanf("%f",&h[i].grade);
		printf("Enter the numbers of rooms:-\n");
		scanf("%d",&h[i].noofrooms);
		printf("Enter averege charge of each room per day:-\n");
		scanf("%d",&h[i].charges);
		
	}
	
	float lb,ub;
	
	printf("Enter the particular section of grade in which hotels have to be displayed,Enter the upper and lower bound:-\n");
	scanf("%f %f",&lb,&ub);
	printf("\nEntering the hotels in desired grade range:-\n");
	for (int i=0; i<5; i=i+1)
	{
		if((lb<=h[i].grade)&&(h[i].grade<=ub))
		{	
			printf("Enter the name of the hotel:-\n");
			fgets(h[i].name,20,stdin);
			printf("Enter the address in brief:-\n");
			fgets(h[i].address,20,stdin);
			printf("Enter the grade ot of 10:-\n");
			scanf("%f",&h[i].grade);
			printf("Enter the numbers of rooms:-\n");
			scanf("%d",&h[i].noofrooms);
			printf("Enter averege charge of each room per day:-\n");
			scanf("%d",&h[i].charges);
		}
	}
	
	int maxcharge;
	printf("Enter the maxcharge for room:-\n");
	scanf("%d",&maxcharge);
	printf("\nEntering the hotels with desired max price:-\n");
	for (int i=0; i<5; i=i+1)
	{
		if(h[i].charges<=maxcharge)
		{	
			printf("Enter the name of the hotel:-\n");
			scanf("%s",h[i].name);
			printf("Enter the address in brief:-\n");
			fgets(h[i].address,20,stdin);
			printf("Enter the grade ot of 10:-\n");
			scanf("%f",&h[i].grade);
			printf("Enter the numbers of rooms:-\n");
			scanf("%d",&h[i].noofrooms);
			printf("Enter averege charge of each room per day:-\n");
			scanf("%d",&h[i].charges);
		}
	}
	
	
	
	
	
	return 0;
}

		
	
