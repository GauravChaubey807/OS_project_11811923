#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>

void Timemag()
{
	int i, limit, total = 0, x, counter = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
    float average_wait_time, average_turnaround_time;
    printf("\nEnter Total Number of Processes: ");
    scanf("%d", &limit);
    x = limit;
    for(i = 0; i < limit; i++)
    {
        printf("\nEnter Details of Process[%d]\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];
    }
 
    printf("\nEnter Time Quantum: ");
    scanf("%d", &time_quantum);
    system("clear");
    printf("\nProcess ID\t   Arrival Time\t   Burst Time\t   Turnaround Time\t   Waiting Time\n");
    for(total = 0, i = 0; x != 0;)
    {
        if(temp[i] <= time_quantum && temp[i] > 0)
        {
            total = total + temp[i];
            temp[i] = 0;
            counter = 1;
        }
        else if(temp[i] > 0)
        {
            temp[i] = temp[i] - time_quantum;
            total = total + time_quantum;
        }
        if(temp[i] == 0 && counter == 1)
        {
        	x--;
            printf("\nProcess %d\t\t%d\t\t%d\t\t %d\t\t\t %d", i + 1, arrival_time[i], burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
            wait_time = wait_time + total - arrival_time[i] - burst_time[i];
            turnaround_time = turnaround_time + total - arrival_time[i];
            counter = 0;
        }
        if(i == limit - 1)
        {
            i = 0;
        }
        else if(arrival_time[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    average_wait_time = wait_time * 1.0 / limit;
    average_turnaround_time = turnaround_time * 1.0 / limit;
    printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
    printf("\nAvg Turn Around Time:\t%f\n", average_turnaround_time);

} 
int main()
{
	system("clear");
	int choice,i;
	printf("\n*********************************************************************************************************");
	printf("\n*                                       *************************                                       *");
	printf("\n*                                       *  OS PROJECTS CSE 316  *                                       *");
	printf("\n*                                       *************************                                       *");
	printf("\n*********************************************************************************************************");
	
	printf("\n\nPresented by : ");
	printf("\nGaurav Chaubey\n");
	printf("\nCSE - 316");
	printf("\nRoll No - 19");
	printf("\nReg No - 11811923");
	printf("\n(Press Enter)");
	getchar();
	system("clear");

	while(choice!=3)
	{
		
		printf("\n1. Student Queue");
		printf("\n2. Faculty Queue");
		printf("\n3. Exit");
		printf("\nChoose the option to proceed : ");
		scanf("%d",&choice);
		system("clear");
		if(choice==1||choice==2)
		{
			Timemag();
			printf("\n\n(Press Enter)");
			getchar();
			getchar();
			system("clear");
		}
	}
	return 0;	
}
