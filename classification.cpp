#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n; // number of categories

	unordered_map<string, vector<string> > data;

	for (int i = 0; i < n; i++) {
		string subject; cin >> subject;
		int words; cin >> words;

		for (int j = 0; j < words; j++) {
			string word; cin >> word;

			data[subject].push_back(word);
		}
	}

	vector<string> statement;
	string x;

	while (cin >> x) {
		statement.push_back(x);
	}


	unordered_map<string, int> occur;
	for (auto i : data) {
		occur[i.first] = 0;
	}


	int track = 0;

	for (auto i : data) {
		for (auto j : i.second) {
			for (int k = 0; k < statement.size(); k++) {
				if (j == statement[k]) {
					occur[i.first]++;
				}
			}
		}
	}

	int max = 0;
	for (auto i : occur) {
		if (i.second > max) {
			max = i.second;
		}
	}

	vector<string> answers;

	for (auto i : occur) {
		if (i.second == max) {
			answers.push_back(i.first);
		}
	}

	sort(answers.begin(), answers.end());

	for (auto i : answers) {
		cout << i << endl;
	}


}
