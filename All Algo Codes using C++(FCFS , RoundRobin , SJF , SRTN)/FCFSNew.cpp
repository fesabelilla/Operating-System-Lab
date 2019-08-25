#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n;
    cout<<"Enter the number of process : ";
    cin>>n ;

    int bt[n+1],wt[n+1],tat[n+1];
    float awt = 0,atat = 0;

    cout<<"Enter the CPU time : ";
    for(int i = 0 ; i<n ; i++){
        cin>>bt[i];
    }
    wt[0] = 0;

    for(int i = 1 ; i<n ;i++){
            wt[i] = 0;
        for(int j = 0 ; j<i ;j++){
            wt[i]+=bt[j];
        }
    }

    for(int i = 0 ; i<n ;i++ ){
        tat[i] = bt[i] + wt[i];

        awt+=wt[i];
        atat+=tat[i];
    }

    awt = awt/n;
    atat = atat/n;

    for(int i = 0 ; i<n ; i++){
        cout<<"Process "<<i+1<<" : Waiting Time :"<<wt[i]<<" Turnaround Time : "<<tat[i]<<endl;
    }

    cout<<"Average Waiting Time : "<<awt<<endl;
    cout<<"Average Waiting Time : "<<atat<<endl;

    return 0;
}
