#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;


int f1(int n){
  if (n / 1000 != 9) return n + 1000;
  else return n; 
}

int f2(int n){
  if (n % 10 != 1) return n - 1;
  else return n;
}

int f3(int n){
  int a1 = n / 1000;
  int a2 = n / 100 % 10;
  int a3 = n / 10 % 10;
  int a4 = n % 10; 
  return a4 * 1000 + a1 * 100 + a2 * 10 + a3;
}

int f4(int n){
  int a1 = n / 1000;
  int a2 = n / 100 % 10;
  int a3 = n / 10 % 10;
  int a4 = n % 10;
  return a2 * 1000 + a3 * 100 + a4 * 10 + a1;
}

int main() { 
  // freopen("input.in", "r", stdin);
  int s;
  cin >> s;
  int end;
  cin >> end;
  
  map<int,int> distance;
  map<int,int> p;
  queue<int> q;
  
  q.push(s);
  p[s] = -1;
  distance[s] = 0;
  
  while(!q.empty()){
    int v = q.front();
    int a = f1(v);
    int b = f2(v);
    int c = f3(v);
    int d = f4(v);
    // cout << v << endl;
    // cout << a << " " << b << " " << c << " " << d << endl << endl;
    if (distance.count(a) == 0){
      // cout << a << endl;
      q.push(a);
      distance[a] = distance[v] + 1;
      p[a] = v;
    }
    if (distance.count(b) == 0){
      // cout << b << endl;
      q.push(b);
      distance[b] = distance[v] + 1;
      p[b] = v;
    }
    if (distance.count(c) == 0){
      // cout << c << endl;
      q.push(c);
      distance[c] = distance[v] + 1;
      p[c] = v;
    }
    if (distance.count(d) == 0){
      // cout << d << endl;
      q.push(d);
      distance[d] = distance[v] + 1;
      p[d] = v;
    }
    // cout << endl;
    if (a == end || b == end || c == end || d == end){
      vector<int> path;
      for (int v = end; v != -1; v = p[v]){
        path.push_back(v);
      }
      // cout << endl;
      reverse(path.begin(), path.end());
      for (auto i : path){
        cout << i << endl;
      }
      // cout << "YES" << endl;
      return 0;
    }
    q.pop();
  }
}