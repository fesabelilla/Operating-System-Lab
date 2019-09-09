#include<bits/stdc++.h>
using namespace std;

#define white 0
#define gray 1
#define black 2

int n;
vector<char> arr[100];
vector<char> deadLock;
char node[100];
char pos[100];
int color[1000];

bool findDL = false;

void FDL(char u)
{
    int n = u - 'A';
    color[n] = gray;

    cout<<arr[u].size();
    for(int i = 0; i< arr[u].size() ; i++)
    {
        char v = arr[u][i];
        int node1 = v - 'A';
        if(color[node1] == gray)
        {
            findDL = true;
            deadLock.push_back('A'+node1);

            char temp = u;

            while(temp != v)
            {
                deadLock.push_back(temp);
                temp = pos[temp];
            }
            return ;

        }
        if(color[node1] == white)
        {
            pos['A'+node1] = u;
            FDL(v);
        }

    }

    color[u] = black;
}

int main()
{
    //freopen("deadLock.txt","r",stdin);

    cin>>n;
    for(int i = 0 ; i<n ; i++)
    {
        char x,y;
        cin>>x>>y;
        //cout<<x<<" "<<y<<endl;
        arr[x].push_back(y);
    }

    for(int i = 0 ; i<n ; i++)
    {
        cin>>node[i];
        if(color[node[i]-'A'] == white)
            FDL(node[i]);
    }

    for(int i = 0 ; i<deadLock.size() ; i++)
    {
        cout<<deadLock[i]<<" ";
    }
    cout<<endl;


    // for(int i = 1 ; i<n ; i++)
    //{
    //  if(color[i] == white)
    //{
    //   FDL(i);
    //}
    //}



    return 0;
}

