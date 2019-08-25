#include<bits/stdc++.h>
using namespace std;

void findWaitingTime(int n,int q,int bt[],int tat[],int wt[])
{
    int t = 0 ;
    int rem[n+1];
    for(int i = 0 ; i<n ; i++)
    {
        rem[i] = bt[i];
    }

    while(1)
    {

        bool done = true;

        for(int i = 0 ; i<n ;i++){
            if(rem[i]>0){
                done = false;

                if(rem[i]>q){
                    t +=q;
                    rem[i] -=q;
                }
                else{
                    t +=rem[i];
                    wt[i] = t - bt[i];
                    rem[i] = 0;
                }

            }
        }
        if(done == true)
            break;
    }

}


void findTurnaroundTime(int n,int q,int bt[],int tat[],int wt[])
{
for(int i = 0 ; i<n ; i++){
 tat[i] =  bt[i] + wt[i];
}

}

void avgTime(int n, int bt[], int q)
{
    int tat[n+1], wt[n+1];
    findWaitingTime(n,q,bt,tat,wt);

    findTurnaroundTime(n,q,bt,tat,wt);

    double totalWT,totalTAT;

    cout<<"Processes\tBurstTime\tWaitingTime\tTurnAroundTime"<<endl;
    for(int i = 0 ; i<n ; i++){
        totalWT += wt[i];
        totalTAT += tat[i];
        cout<<"  "<<i+1<<"  \t\t"<<bt[i]<<"  \t\t"<<wt[i]<<"  \t\t"<<tat[i]<<endl;
}
cout<<"Average waiting time : "<<totalWT/n<<endl;
cout<<"Average turn around time : "<<totalTAT/n<<endl;

}


int main()
{
    int n ;

    cout<<"Enter the number of process :  ";
    cin>>n ;
    int bt[n+1];

    cout<<"Enter CPU time : ";
    for(int i = 0 ; i<n ; i++)
    {
        cin>>bt[i];
    }
    int q ;

    cout<<"Enter time Quantum : ";
    cin>>q;



    avgTime(n,bt,q);



    return 0;
}
