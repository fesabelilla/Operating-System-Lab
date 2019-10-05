#include<bits/stdc++.h>
using namespace std;

int req[10000];
bool visite[10000];
int n,head;

int minIndex(){
    int mx = INT_MAX;
    int mi = -1;

    for(int i = 0 ; i<n ;i++){
        if(visite[i] == true)
            continue;
        if(abs(head - req[i])< mx){
            mx = abs(head - req[i]);
            mi = i;
        }

    }
    visite[mi] = true;
    return mi;

}

int main()
{
    cout<<"Enter the number of requests : ";
    cin>>n;
    cout<<" Cylinder Requests: ";
    for(int i = 0 ; i<n ; i++){
        cin>>req[i];
    }
    cout<<" Enter Head : ";
    cin>>head;

    int total = 0;
    for(int i = 0 ; i<n ; i++){
            int temp = minIndex();
        total += abs(head - req[temp]);
        head = req[temp];
        cout<<" "<<head;
    }

    cout<<"\n"<<"Total Move : "<<total;

    return 0 ;
}
