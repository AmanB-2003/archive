#include <stdio.h>

int process[3]={1,2,3};
int n = 3;
int burst_time[3]={11,5,4};
int priority[3]= {10,30,20};
int waiting_time[3];
int quantum = 2;

void reorder_process(int p[],int bt[]){
    printf("Resetting Processes...\n");
    p[0] = 1; p[1] = 2; p[2] = 3;
    bt[0] = 11; bt[1] = 5; bt[2] = 4; 
}

void sort_process_by_burst_time(int p[],int bt[],int wt[],int n){
    for (int i = 0; i < n; i++)
    {   for (int j = 0; j <n-1; j++)
      {  if(bt[j]>bt[j+1]){   
          //swap
            int temp = bt[j+1];
            bt[j+1]=bt[j];
            bt[j]=temp;

            temp = p[j+1];
            p[j+1]=p[j];
            p[j]=temp;
        }
      }
    }    
}

void sort_process_by_priority(int p[],int bt[],int prirty[],int n){
    for (int i = 0; i < n; i++)
    {   for (int j = 0; j <n-1; j++)
      {  if(prirty[j]<prirty[j+1]){   
           //swap
            int temp = bt[j+1];
            bt[j+1]=bt[j];
            bt[j]=temp;

            temp = p[j+1];
            p[j+1]=p[j];
            p[j]=temp;

            temp = prirty[j+1];
            prirty[j+1]=prirty[j];
            prirty[j]=temp;
        }
      }
    }    
}

void calculate_waiting_time(int wt[],int bt[],int n){
    wt[0] = 0;
    for (int i = 1; i < n+1 ; i++)
    {  wt[i] = wt[i-1] + bt[i-1]; 
    }
    
}

void print_gantt_chart(int p[],int bt[],int wt[],int n){
    //printing top bar
    printf(" ");
    for (int i = 0; i < n ; i++)
    { for(int j=0; j<bt[i]; j++){
       printf("--");
    }printf(" ");
    }printf("\n|");

    //printing middle part
    for (int i = 0; i < n; i++)
    {  for (int j = 0; j < bt[i]; j++)
        { printf(" "); }
     printf("p%d",p[i]);
       for (int j = 0; j < bt[i]-2; j++)
        { printf(" "); }printf("|");
    }printf("\n");

    //printing bottom bar
    printf(" ");
    for (int i = 0; i < n ; i++)
    { for(int j=0; j<bt[i]; j++){
       printf("--");
    }printf(" ");
    }printf("\n");

    //printing waiting time
    int minus = 0;
    for (int i = 0; i < n+1 ; i++)
    {  if(wt[i]<10)  printf("%d",wt[i]);
       if(wt[i]>=10){
           minus = 1;
           printf("%d",wt[i]);}
       for (int j = 0; j < 2*bt[i]-minus; j++)
       {printf(" ");}  minus = 0; 
    }
}

void round_robin(int p[],int bt[],int wt[],int n,int q){
    //Make a copy of bt to store remaining burst times
    int rem_bt[n];
    for (int i = 0; i < n; i++)
    {  rem_bt[i] = bt[i];}

    //printing top bar
    printf(" ");
    for (int i = 0; i < n ; i++)
    { for(int j=0; j<bt[i]; j++){
       printf("----");
    }
    }printf("\n|");
    
    int t=0;   //Current time
    //Keep traversing processes in round robin manner
    //until all of them are done.
    while (1)
    {  /*    while loop for repeating   */
       int done = 1;

       for(int i=0 ; i<n ;i++){
           if (rem_bt[i]>0)
           {    if (rem_bt[i]>q){
                  t+= q;
                  //Decrease the remaining burst time
                  rem_bt[i] -= q;

                  for (int j = 0; j < q; j++)
                    { printf(" "); }
                  printf("p%d",p[i]);
                  for (int j = 0; j < q; j++)
                    { printf(" "); }printf("%d",t);
    }
              // If burst time is smaller than or equal to
              // quantum. Last cycle for this process
              else{
                  wt[i] = t;
                  t = t + rem_bt[i];
                   for (int j = 0; j < rem_bt[i]; j++)
                 { printf(" "); }
                 printf("p%d",p[i]);
                 for (int j = 0; j < rem_bt[i]; j++)
                    { printf(" "); }printf("%d",t);

                  rem_bt[i]=0;
           }
       }
       }
           int r=0;
           while (r<n)
           {  if (rem_bt[r]>0)
               {  done = 0;
                 break; }
                 else{done = 1;} 
                 r++;   
           }
           
       if (done == 1)
        {   break;  }
    } 


    //printing bottom bar
    printf("  |\n ");
    for (int i = 0; i < n ; i++)
    { for(int j=0; j<bt[i]; j++){
       printf("----");
    }
    }printf("\n"); 
}

int main(){

    //FCFS
    printf("\n===First Come First Scheduling===\n");
    calculate_waiting_time(waiting_time,burst_time,n);
    print_gantt_chart(process,burst_time,waiting_time,n);
    reorder_process(process,burst_time);

    //SJF
    printf("\n===Shortest Job First Scheduling(Non-Premptive)===\n");
    sort_process_by_burst_time(process,burst_time,waiting_time,n);
    calculate_waiting_time(waiting_time,burst_time,n);
    print_gantt_chart(process,burst_time,waiting_time,n);
    reorder_process(process,burst_time);

    //Priority
    printf("\n===Priority Scheduling(Non-Premptive)===\n");
    sort_process_by_priority(process,burst_time,priority,n);
    calculate_waiting_time(waiting_time,burst_time,n);
    print_gantt_chart(process,burst_time,waiting_time,n);
    reorder_process(process,burst_time);

    //Round Robin
    printf("\n===Round Robin Scheduling===\n");
    round_robin(process,burst_time,waiting_time,n,quantum);

}

