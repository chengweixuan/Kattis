#include <iostream>
#include <map>
#include <string>
#include <cctype>
using namespace std;


int main()
{
	int n; // number of animals

	map<string,int> zoo;
	int case_no = 1;
	locale loc;
	int counter = 0;

	while (cin >> n, n > 0) {

		cin.get(); // consumes line after n
		counter++;

		for (int i = 0; i < n; i++) {
			string line;

			getline(cin, line); // takes in as an entire line

			istringstream iss(line);
			string last;
			while (iss >> last) {} // only takes in the last part


			for (int j = 0; j < last.length(); j++) {

				if (last[j] <= 'Z' && last[j] >= 'A') {
					last[j] -= 'A';
					last[j] += 'a';
				}
			}
			zoo[last]++; 
		}

		cout << "List " << case_no << ":" << endl;

		for (auto i : zoo) {
			cout << i.first << " | " << i.second << endl;
		}

		case_no++;
		zoo.clear();
	}

}
