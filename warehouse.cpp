#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	int t; cin >> t; // number of test cases

	unordered_map<string,int> toys;

	for (int j = 0; j < t; j++) { // overall loop

		int n; cin >> n; // number of shipments

		for (int i = 0; i < n; i++) {
			string name; cin >> name; // name of toy
			int number; cin >> number; // number of toys shipped

			toys[name] += number;
		}
		
		cout << toys.size() << endl;

		vector<pair<string,int>> printed(toys.begin(), toys.end());
		sort(printed.begin(), printed.end(), [] (pair<string,int> A, pair<string,int> B) {
				if (A.second == B.second) {
				return A.first < B.first;
				} else {
				return A.second > B.second;
				}
				});

		for (int i = 0; i < printed.size(); i++) {
			cout << printed[i].first << " " << printed[i].second << endl;
		}
		//for (auto &it : toys) {
		//	cout << it.first << " " << it.second << endl;
		//}

		toys.clear();
	}


}
