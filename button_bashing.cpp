#include <iostream>
#include <vector>
using namespace std;


void bfs(int s)
{
  queue<int> q; // creates a queue of vertices to traverse
  q.push(s);
  visited[s] = 1; // make the current vertex visited

  while (!q.empty()) { // creates a loop through the entire connected segment
    int u = q.front();
    q.pop();

    for (auto &v : AL[u]) { // loops through all neighbours of vertex s
      if (!visited[v]) {
        visited[v] = 1; // sets all neighbours of s to visited if unvisited
        q.push(v); // push unvisited neighbours into the queue
      }
    }
  }
}

void dfs(int s, int counter)
{
  if (s == t) {
    return;
  }


}

int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n; // number of buttons
  int t; cin >> t; // desired time

  vector<int> buttons; // contains all the buttons

  for (int i = 0; i < n; i++) {
    int button; cin >> button;
    buttons.push_back(button);
  }

  AL.assign(3600, vector<int>());

  vector< vector<int> > AL;
  unordered_set<int> visited;
  queue<int> tree;

  tree.push(0);
  visited.push_back(0);

  while (!tree.empty()) {
    int x = tree.front(); // takes the top part of the queue
    tree.pop();

    if (x < 0 || visited.find() != visited.end() || x == t ) {
      continue;
    } // so this stops everything below from happening

    for (auto i : buttons) {
      visited.insert(x + i);
      if (x + i <= 3600) {
        AL[x + i].push_back(x); // fill adjacency list
      }
    }

    for (auto i : AL[x]) {
      tree.push(i);
    }
  }

  queue<int> search;
  search.push(0);
  unordered_set<int> found;
  int counter = 0;

  while(found.find(t) == find.end()) {

    int x = search.front();
    search.pop();

    for (auto i : AL[x]) {
      found.insert(i);
      queue.push(i);
    }
    counter++;
  }

  cout << counter;
}
