//#include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	cin.get();

	int total = 2 * n; // total number of socks in the stack

	stack<int> original;
	stack<int> aux;
	queue<int> transfer;

	string line; int part;
	getline(cin, line);
	istringstream iss(line);

	while (iss >> part) {
		transfer.push(part);
	}
		

	while (!transfer.empty()) {
		original.push(transfer.front());
		transfer.pop();
	}

	int counter = 0;
	int moves = 0;

	while (!original.empty()) {

		while (!aux.empty() && !original.empty() && (aux.top() == original.top()) ) {
			original.pop();
			aux.pop();
			counter++;
			moves++;
		}

		if (!original.empty()) {
			aux.push(original.top());
			original.pop();
			moves++;
		}

	}


	if (aux.empty()) {
		cout << moves;
	} else {
		cout << "impossible";
	}


}
