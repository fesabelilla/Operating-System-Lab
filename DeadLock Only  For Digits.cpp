#include<bits/stdc++.h>
using namespace std;

#define white 0
#define gray 1
#define black 2

int n,m;
vector<int>arr[1000];
vector<int>cyclePath;
int color[1000];
int par[1000];

bool cycleFound = false;


void DFS(int u ){
color[u] = gray;

for(int i = 0 ; i<arr[u].size() ; i++){
    int v = arr[u][i];

    if(color[v] == gray){
        cycleFound = true;
        cyclePath.push_back(v);
        int temp = u;

        while(temp != v){
            cyclePath.push_back(temp);
            temp = par[temp];
        }
        return ;
    }

    if(color[v] == white){
        par[v] = u;
        DFS(v);
    }
}
color[u] = black;


}

int main()
{
    cin>>n>>m;

    for(int i = 0 ; i<m ;i++){
        int x,y;
        cin>>x>>y;
        arr[x].push_back(y);
    }
    for(int i = 1 ; i<=n ; i++){
        if(color[i] == white ){
            DFS(i);
        }
    }

    if(cycleFound){
        for(int i = 0 ; i<cyclePath.size() ; i++){
            cout<<cyclePath[i]<<"   ";
        }
        cout<<endl;
    }



}
