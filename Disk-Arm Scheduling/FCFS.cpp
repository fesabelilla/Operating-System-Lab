#include<bits/stdc++.h>
using namespace std;

int req[1000];

int main()
{
    int n ;
    cout<<"Enter the number of requests : ";
    cin>>n;

    cout<<"Enter Cylinder Requests : ";

    for(int i = 0 ; i<n ; i++)
        cin>>req[i];

    int h;
    cout<<"Enter Head Start Point : ";
    cin>>h;
    int totalCylinderMovement = 0 ;
    for(int i = 0 ; i<n ; i++){
        totalCylinderMovement += abs(h - req[i]);
        h = req[i];

        cout<<"  "<<req[i];
    }

    cout<<endl;
    cout<<"Total Cylinder movement :  "<<totalCylinderMovement;

    return 0;
}
