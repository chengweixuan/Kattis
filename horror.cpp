// horror solution done by h number of dijkstra's
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n; // number of movies
  int h; cin >> h; // number of movies on the horror list
  int l; cin >> l; // number of similarities

  vector< vector<int> > AL;
  vector<int> dist;

  AL.assign(n, vector<int>());
  dist.assign(n, 1e9);

  vector<int> starts; // stores the starting points
  for (int i = 0; i < h; i++) {
    int start; cin >> start;
    starts.push_back(start);
    dist[start] = 0;
  }
  // creates AL
  for (int i = 0; i < l; i++) {
    int a; cin >> a;
    int b; cin >> b;

    AL[a].push_back(b);
    AL[b].push_back(a);
  }
  // run dikstra's h number of times
  for (int i = 0; i < h; i++) {
    queue<int> q;
    q.push(starts[i]);

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (auto &j : AL[u]) {
        if (dist[u] + 1 < dist[j]) {
          q.push(j);
          dist[j] = dist[u] + 1;
        }
      }
    }
  }

  int max = 0;
  for (int i = 0; i < n; i++) {
    if (dist[i] > max) {
      max = dist[i];
    }
  }

  priority_queue<int, vector<int>, greater<int>> pq;
  // use a pq to find the max element
  for (int i = 0; i < n; i++) {
    if (dist[i] == max) {
      pq.push(i);
    }
  }

  cout << pq.top();

}
