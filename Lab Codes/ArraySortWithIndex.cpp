#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    int num;
    vector<pair<int, int> > aset, bset;
    cin >> n ;
    for(int i=0; i<n; i++)
    {
        cin >> num;
        aset.push_back(make_pair(num, i));
    }

    // input complete;
    sort(aset.begin(), aset.end());
    //int ind1 = aset[0].second;
    for(int i=0; i<n; i++)
    {
        cout << aset[i].first << ' ' << aset[i].second << '\n';
    }

    return 0;
}
