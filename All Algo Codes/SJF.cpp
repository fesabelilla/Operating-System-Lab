#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cout<<"Enter the number of process : ";
    cin>>n;

    int bt[n+1],wt[n+1],tat[n+1],p[n+1];
    double atat , awt ;

    cout<<"Enter Burst Time : "<<endl;
    for(int i = 0 ; i<n ; i++ ){
        cout<<"p"<<i+1<<" : ";
        cin>>bt[i];
        p[i] = i+1 ;
    }
 //selection sort
    int pos , temp , total = 0,twt = 0,ttat = 0;
    for(int i = 0 ; i<n ; i++){
            pos = i;
        for(int j = i+1 ; j < n ; j++ ){
            if(bt[j] < bt[pos]){
                pos = j;
            }
        }
        swap(bt[i],bt[pos]);
        swap(p[i],p[pos]);
    }

    wt[0] = 0 ;

    for(int i = 1 ; i<n ; i++){
        wt[i] = 0;
        for(int j = 0 ; j<i ; j++){
            wt[i]+=bt[j];
            twt+=wt[i];
        }

        awt = twt/n;
        for(int i = 0 ; i<n ; i++){
            tat[i] = bt[i]+wt[i];
            ttat+=tat[i];
        }
        atat = ttat/n;


    }
    for(int i = 0 ; i<n ; i++){
            cout<<"Process p"<<p[i]<<" Burst Time : "<<bt[i]<<" Waiting Time :"<<wt[i]<<" Turnaround Time : "<<tat[i]<<endl;
    }


    return 0;
}




