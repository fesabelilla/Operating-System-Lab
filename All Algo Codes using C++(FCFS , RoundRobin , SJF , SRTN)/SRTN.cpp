#include<bits/stdc++.h>

using namespace std;

int main()
{
   int n ;
   cout<<"Enter the number of process : ";
   cin>>n;

   int bt[10],att[10],x[10],wt[10],tat[10],smallest,time ,end1 ,counter=0;

   cout<<"Enter Burst Time & Arrival time :  "<<endl;
   for(int i = 0 ; i<n ; i++){
    cin>>bt[i]>>att[i];
   }

   for(int i = 0 ; i<n ;i++)
    x[i] = bt[i];

   bt[9] = 9999;
   for(time  = 0 ; counter != n ;time++){
    smallest = 9;
   for(int i = 0 ; i<n ; i++){
    if(att[i]<=time && bt[i]<bt[smallest]&&bt[i]>0)
        smallest = i;
   }

   bt[smallest]--;

   if(bt[smallest]==0){
    counter++;
    end1 = time+1;
    wt[smallest] = end1-att[smallest]-x[smallest];
    tat[smallest] = end1-att[smallest];
   }

   }


   double totalWT , totalTAT;

   cout<<"Process No  "<<"  Burst Time  "<<"  Waiting Time  "<<"  Turnaround Time "<<endl;
   for(int i = 0 ; i<n ; i++){
   cout<<i+1<<"\t\t"<<x[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;

   totalWT +=wt[i];
   totalTAT +=tat[i];
   }

   cout<<endl<<"Total Waiting time : "<<totalWT/n<<endl;
   cout<<endl<<"Total Turnaround time : "<<totalTAT/n<<endl;


    return 0;
}
