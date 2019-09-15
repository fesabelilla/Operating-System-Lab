/*
Name : Md. Zahid Fesabelilla
Section : B(B1)
ID : 160204082
Year.Semester: 3.2

*/
#include<bits/stdc++.h>
using namespace std;

const int P = 7;
const int R = 3 ;

void calculateNeed(int need[P][R], int maxm[P][R],int allot[P][R]){

    for (int i = 0 ; i < P ; i++){
        for (int j = 0 ; j < R ; j++){
            need[i][j] = maxm[i][j] - allot[i][j];
              }
        }
        cout<<endl;
        cout<<" Need "<<endl;
        cout<<"x"<<" y"<<" z"<<endl;

    for (int i = 0 ; i < P ; i++){
        for (int j = 0 ; j < R ; j++){
            cout<< need[i][j] << " ";
              }
            cout<<endl;
        }
}

bool isSafe(int processes[], int avail[], int maxm[][R],int allot[][R]){
    int need[P][R];
    bool finish[P] = {0};
    int safeSeq[P];
    int work[R];

    calculateNeed(need, maxm, allot);

    for (int i = 0; i < R ; i++){
        work[i] = avail[i];
    }

    int counter = 0;
    while (counter < P)
    {
           bool found = false;
        for (int p = 0; p < P; p++)
        {
            if (finish[p] == 0)
            {
                   int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;

                if (j == R)
                {
                    for (int k = 0 ; k < R ; k++)
                        work[k] += allot[p][k];
                    safeSeq[counter++] = p;

                    finish[p] = 1;
                    found = true;
                }
            }
        }
        if (found == false)
        {
            cout << "System is not in safe state";
            return false;
        }
    }
    cout <<"The safe sequence is: "<<endl;

    for (int i = 0; i < P ; i++){
        cout << safeSeq[i] << " ";
    }
    return true;
}

int main()
{
    int processes[P];
    for(int i = 0 ; i < P ; i++){
        processes[i] = i;
    }


    int allot[P][R];
     cout<<"Enter the Value of Allocation : "<<endl;
     for(int i = 0 ; i<P ; i++){
        for(int j = 0 ; j<R ; j++){
            cin>>allot[i][j];
        }
     }

     cout<<"Enter the maximum Value : "<<endl;
     int maxm[P][R];
     for(int i = 0 ; i<P ; i++){
        for(int j = 0 ; j<R ; j++){
            cin>>maxm[i][j];
        }
     }

    int sum[R];
    int avail[R];

    for(int i = 0 ; i < R ; i++){
        sum[i] = 0 ;
        avail[i] = 0;
    }
    //for sum of allocations
    for(int i = 0 ; i<R ; i++){
        for(int j = 0 ; j<P ; j++){
            sum[i] += allot[j][i];
        }
     }
     cout<<endl;

    int Resources[R+1];
    cout<<"Enter Resources : ";
    for(int i = 0 ; i<R ; i++){
        cin>>Resources[i];
    }


    for(int i = 0 ; i<R ; i++){
        avail[i] = Resources[i] - sum[i];
    }

    cout<<"Available instance : ";
    for(int i = 0 ; i<R ; i++){
        cout<<avail[i]<<"  ";
    }

   isSafe(processes, avail, maxm, allot);

    return 0;
}
