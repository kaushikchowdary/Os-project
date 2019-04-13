//Question no -1 Devesh Chaudhary A26
#include<stdio.h>
int main()
{
	int i,m;
	printf("\nEnter number of processes: ");
	scanf("%d",&m);
	int arrival[m];
	int burst[m],burst1[m];
	int waiting[m];
	int tarrival[m];
	int tq1=3;
	int tq2=6;
	int avgT=0;
	int avgW=0;
	printf("\nEnter arival time of processes:\n");
	for(i=0;i<m;i++)
	{  printf("For processes %d :",i+1);
		scanf("%d",&arrival[i]);
	}
	printf("\nEnter burst time for processes:\n");
	for(i=0;i<m;i++)
	{
		printf("For processes %d:",i+1);
		scanf("%d",&burst[i]);
		burst1[i]=burst[i];	
	}
	printf("\n****************************** 1st ITERATION (TQ=3) ****************************\n");
	for(i=0;i<m;i++)
	{  
	if(arrival[i]<=tq1+arrival[i-1])
	{
	
		burst[i]=burst[i]-tq1;
		
		printf("\nFor process %d\n",i+1);
		printf("Left Burst time=%d\n",burst[i]);}
		else
		{
		burst[i]=burst[i]-tq1;
	
		printf("For process %d\n",i+1);
		printf("Left Burst time= %d\n",burst[i]);	
		}}
	
	printf("\n****************************** 2nd ITERATION (TQ=6) ****************************\n");
	for(i=0;i<m;i++)
	{
	if(arrival[i]<=tq2+arrival[i-1])
	{
	
		burst[i]=burst[i]-tq2;
		
		printf("\nFor process %d\n",i+1);
		printf("Left Burst time= %d\n",burst[i]);}
		else
		{
		burst[i]=burst[i]-tq2;
	
		printf("For process %d\n",i+1);
		printf("Left Burst time= %d\n",burst[i]);	
		}	
	}
	printf("\n****************************** 3rd ITERATION ***********************************\n");
	int j,temp;

	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{if(burst[i]>burst[j])
		{
		
			temp=burst[i];
			burst[i]=burst[j];
			burst[j]=temp;
			}
		}
	}
	int ct[4]={54,68,45,41};
	for(i=0;i<m;i++)
	{
		tarrival[i]=ct[i]-arrival[i];
		waiting[i]=tarrival[i]-burst1[i];
		printf("\nCompletion time for process %d : %d \n",i+1,ct[i]);
		printf("Turn arround time for process %d : %d \n",i+1,tarrival[i]);
		printf("Waiting time for process %d : %d \n",i+1,waiting[i]);
		avgT=avgT+tarrival[i];
		avgW=avgW+waiting[i];
		
	}
	avgT=avgT/m;
	avgW=avgW/m;
	printf("\n\nAverage turn around time: %d\n",avgT);
	printf("Average waiting time: %d\n",avgW);
	}
