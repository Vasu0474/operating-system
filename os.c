#include<iostream>
using namespace std;
int quantum = 10;
int a[100],f=0; int c=0;
//swap values
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 //sort the burst time according to arrival time
void selectionSort(int bursttime[],int arrivaltime[],int priority[],int id[],int n)
{
    int i, j, min1;

    for (i = 0; i < n-1; i++)
    {
        min1 = i;

        for (j = i+1; j < n; j++){
          if (arrivaltime[j] < arrivaltime[min1])
            {min1 = j;}
        
        
        /*if (arrivaltime[j] = arrivaltime[min1] && priority[i] < priority[min1]){
		min1 = j;
        }*/
        
        /*else if (arrivaltime[j] = arrivaltime[min1]){
		
        	if(priority[i] = priority[min1]){
        		if(id[i] < id[min1]){
					
            {min1 = j;}
			}
			else
			c++;
		}
        }
        else 
		c++;*/
    }


        swap(&arrivaltime[min1], &arrivaltime[i]);
        swap(&bursttime[min1], &bursttime[i]);
        swap(&priority[min1], &priority[i]);
        swap(&id[min1], &id[i]);
    }
}


void waiting(int n, int bt[], int wt[])
{
    int rem_bt[n];
    int i;
    for ( i = 0 ; i < n ; i++)
        rem_bt[i] =  bt[i];
 
    int t = 0;
    printf("\n\n|");
    while (1)
    {
        bool done = true;
 
        for (i = 0 ; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false; 
 
                if (rem_bt[i] > quantum)
                {   
                     printf("  P%d  |",(i+1));
                    t += quantum;
                    a[f] = t;
                    f = f+1;
                    rem_bt[i] -= quantum;
                }
                else
                {
                   printf("  P%d  |",(i+1));
                   t = t + rem_bt[i];
                    a[f] = t;
                    f = f+1;
   
                    wt[i] = t - bt[i];
 
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == true)
          break;
    }
}
 

void turn_around(int n, 
                  int bt[], int wt[], int tat[])
{
  
    int i;
    for (i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
 
void average(int n, int arrivaltime[],int bursttime[],int priority[],int id[])
{
  int wait[n], turn[n];
  int q=quantum; int i;
  int total_wait = 0,  total_turn = 0; 


  waiting(n,bursttime,wait);
  turn_around( n,bursttime, wait,turn);
   printf("\n");
  printf("%02d     ",0);
  
  for(i=0;i<f;i++){
    printf("%02d     ",a[i]);
  }
  
  printf("\n");

  printf("Processing details\n");

  printf("\n\n\n  Processes \t Burst-time \t Arrival time \t Waiting time \t Turn around time\n\n");

  printf("\n");
  for (i=0; i < n; i++)
  {
    total_wait= total_wait+ wait[i];
    total_turn = total_turn + turn[i];
    printf("\tF%d \t ",id[i]); printf("\t%d \t ",bursttime[i]);printf("\t%d \t ",arrivaltime[i]);  printf("\t%d \t ",wait[i]); printf("\t%d \t ",turn[i]);
    printf("\n");      
  }

  printf("\n");
  printf("Average waiting time = %f\n", ((float)total_wait / (float)n),"\n");
  printf("Average turn around time = %f\n", ((float)total_turn / (float)n), "\n");
  

  
}

 
// Driver code
int main()
{
  int n;
        printf("No of process\n");
        scanf("%d",&n);
        int i=0;
        int arrivaltime[n];
        int bursttime[n];
        int priority[n]; 
        int id[n];
        
        printf("Enter in following manner\n\n");
        printf("\n\n\nArrival time, Burst-time,priority\n\n");
     
        for(i = 0;i < n; i++){
            scanf("%d",&arrivaltime[i]);
            scanf("%d",&bursttime[i]);
            scanf("%d",&priority[i]);
            id[i] = i+1;
}

        selectionSort(bursttime,arrivaltime,priority,id,n);
 

        
        average(n,arrivaltime,bursttime,priority,id);
 
    }
  
