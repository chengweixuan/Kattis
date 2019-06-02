#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


int main()
{
	int n; cin >> n;  // number of guests
	
	unordered_map<int,vector<int>> table;
	int guest;
	for (int i = 0; i < n; i++) {
		// inserting elements into the vectors at each key
		cin >> guest;
		table[guest].push_back(i);
	}

	int level = 1e9; // set level awkwardness to max possible first
	
	// for case that all languages are unique
	if (table.size() == n) {
		level = n;
		cout << level;
		return 0;
	}

	for (auto &key : table) {
		if (key.size() > 1) {
		for (int i = 1; i < key.second.size(); i++) {
			if ( (key.second[i] - key.second[i-1]) < level) {
				level = (key.second[i] - key.second[i-1]);
			}
		}
		}
	}
	cout << level;
	return 0;
}
