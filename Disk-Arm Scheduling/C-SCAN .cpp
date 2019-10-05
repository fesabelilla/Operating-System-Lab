#include<bits/stdc++.h>
using namespace std;

int L, R;
int n;
int req[1000];
int head;
int curr_dir, read_dir;

bool vis[1000];

vector<int>seq;

bool find_req(){
  for (int i = 0; i < n; i++){
    if (vis[i] == true){
      continue;
    }
    if (req[i] == head){
      seq.push_back(req[i]);
      vis[i] = true;
      return true;
    }
  }
  return false;
}

int main(){
  cout << "Enter the number of the cylinder: ";
  cin >> R;
  L = 0;
  R--;
  cout << "Enter the number of req: ";
  cin >> n;
  cout << "Enter the requests: ";
  for (int i = 0; i < n; i++){
    cin >> req[i];
  }
  cout << "Enter the head position: ";
  cin >> head;
  cout << "Enter the current direction of head: ";
  cin >> curr_dir;
  cout << "Enter the read direction: ";
  cin >> read_dir;

  int total = 0;
  int cnt = 0;

  while (cnt < n){
    if (curr_dir == read_dir){
      if (find_req()){
        cnt++;
      }
    }
    if (curr_dir == 1){
      head++;
    }
    else {
      head--;
    }
    if (head == R){
      curr_dir = 0;
    }
    if (head == L){
      curr_dir = 1;
    }
    total++;
  }
  cout << "Total head movement: ";
  cout << total << "\n";
  cout << "Sequence: ";
  for (int i = 0; i < seq.size(); i++){
    cout << seq[i] << " ";
  }
  cout << "\n";
  return 0;
}
