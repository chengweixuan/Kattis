// conformity done on C++
#include <bits/stdc++.h>
using namespace std;


int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n; // number of frosts
  cin.get();

  vector< set<string> > subjects;
  vector<int> popularity;

  subjects.assign(n, set<string>()); // sorts all subjects
  popularity.assign(n, 0); // tracks popularity

  for (int i = 0; i < n; i++) {
    string line; getline(cin, line);
    istringstream iss(line);

    string subject;
    while (iss >> subject) {
      subjects[i].insert(subject);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        if (subjects[i] == subjects[j]) {
          popularity[i]++;
        }
      }
    }
  }

  int max = 0;
  for (auto i : popularity) {
    if (i > max) {
      max = i;
    }
  }
  // tracks which suject combinations are most popular
  set< set<string> > popular;
  for (int i = 0; i < n; i++) {
    if (popularity[i] == max) {
      popular.insert(subjects[i]);
    }
  }

  int counter = 0;
  for (auto i : subjects) {
    if (popular.find(i) != popular.end()) {
      counter++;
    }
  }

  cout << counter;

}
