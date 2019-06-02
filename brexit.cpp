// Brexit orignal implementation
// gives example of vertex deletion
#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

  int c; cin >> c; // number of countries
  int p; cin >> p; // number of partnerships
  int x; cin >> x; // home country
  int l; cin >> l; // leaving country

  x--; l--;

  vector< set<int> > AL;
  vector<int> count;

  AL.assign(c, set<int>());
  count.assign(c, 0);

  for (int i = 0; i < p; i++) {
    int a; cin >> a; a--;
    int b; cin >> b; b--;
    // bidirectional graph
    AL[a].insert(b);
    AL[b].insert(a);
  }
  // keeps track of the orignal number of partners
  for (int i = 0; i < c; i++) {
    count[i] = AL[i].size();
  }

  queue<int> q;
  q.push(l);
  // start bfs cascading from leaving country
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    if (AL[u].size() <= count[u]/2 || u == l) { // if leaving
      // add all neigbours of the country if its leaving
      for (auto &i : AL[u]) {
        q.push(i);
      }
      // deletes this vertex from the AL
      for (auto &i : AL[u]) {
        auto it = AL[i].find(u);
        AL[i].erase(it);
      }
      AL[u].clear();
    }
  }

  if (AL[x].size() <= count[x]/2) {
    cout << "leave";
  } else {
    cout << "stay";
  }

}
