// CD

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); // standard

	int N, M;
	while (cin >> N >> M, (N || M)) {
		// what data structure that you need to solve this problem?
		unordered_set <int> jack;

		int ans = 0; // compute this value
		for (int i = 0; i < N; ++i) {
			int id; cin >> id;
			// what will you do with Jack's CD
			jack.insert(id); 

		}

		for (int i = 0; i < M; ++i) {
			int id; cin >> id;
			// what will you do with Jill's CD
			if (jack.find(id) != jack.end()) {
				ans++;
			} 

		}

		cout << ans << endl;
	}

	return 0;
}
