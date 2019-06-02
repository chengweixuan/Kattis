// keeping track of cycles using DFS
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string> > AL;
unordered_map<string, int> visited;
unordered_map<string, int> explored;
bool cycle = false;

void dfs(string s)
{
  visited[s] = 1; // mark visited

  for (auto &i : AL[s]) {

    if (visited[i] == 0) {
     dfs(i);
   } else if (visited[i] == 1){  // if DFS reaches a visited vertex
      cycle = true; // there is a cycle present
      return;
    }
  }
  visited[s] = 2; // sets completed DFS traversals as 2
}

int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n; // number of flights
  cin.get();

  for (int i = 0; i < n; i++) {
    string origin; cin >> origin;
    string destination; cin >> destination;

    AL[origin].push_back(destination);
    visited[origin] = 0;
  }

  string x;

  while (cin >> x) {
    cycle = false;
    for (auto &i : visited) {
      i.second = 0;
    }
    dfs(x);
    cout << x << " ";
    if (cycle) {
      cout << "safe" << endl;
    } else {
      cout << "trapped" << endl;
    }

  }

}
