void roundRobin() {
    int i,j,n,time,remain,flag=0,tq;
    int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];
    printf("Enter Total Process:\t ");
    scanf("%d",&n);
    remain=n;
    printf("Enter Time Quantum:\t");
    scanf("%d",&tq);
    for(i=0;i<n;i++)
    {
      printf("Burst Time for Process Process Number %d :",i+1);
     at[i]=0;
      scanf("%d",&bt[i]);
      rt[i]=bt[i];
    }
    printf("\n\nProcess\t Turnaround Time Waiting Time\n\n");
    for(time=0,i=0;remain!=0;)
    {
      if(rt[i]<=tq && rt[i]>0)
      {
        time+=rt[i];
        rt[i]=0;
        flag=1;
      }

      else if(rt[i]>0)
      {
        rt[i]-=tq;
        time+=tq;
      }

      if(rt[i]==0 && flag==1)
      {
        remain--;
        printf("P[%d]\t\t%d\t\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
        wait_time+=time-at[i]-bt[i];
        turnaround_time+=time-at[i];
        flag=0;
      }
      if(i==n-1)
        i=0;
      else if(at[i+1]<=time)
        i++;
      else
        i=0;
    }
    printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
    printf("Avg Turnaround Time = %f\n",turnaround_time*1.0/n);
}