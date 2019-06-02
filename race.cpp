#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <istream>
#include <utility>
#include <sstream>
using namespace std;

typedef struct {
	string first; // first name
	string last; // last name
	string bib; // always 5 digits possibly with leading zeros
	string time_1; // timing for split 1
	string time_2; // timing for split 2
	string finish; // timing for finish
	int rank1;
	int rank2;
	int rankf;
} runner;


int location(vector<runner> runners, string bib)
{
	for (int i = 0; i < runners.size(); i++) {
		if (runners[i].bib == bib) {
			return i;
		}
	}
	return -1;
}

bool compare(pair<int,string> A, pair<int,string> B)
{
	return A.second < B.second;
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n;
	vector<runner> runners;

	//	while (cin >> n, n > 0) {
	cin >> n;

	cin.get(); // eats the line after input n

	while (n--) {
		string line; string part;
		getline(cin, line);

		runner temp;

		istringstream iss(line); // splits the line
		iss >> temp.first;
		iss >> temp.last;
		iss >> temp.bib;

		runners.push_back(temp);
	}

	int m = n * 3;

	while (m--) {
		string line;
		getline(cin, line);

		istringstream iss(line);
		string bib; iss >> bib;
		string point; iss >> point; // split point
		string time; iss >> time; // split timing

		int index = location(runners, bib);
		if (point == "F") {
			runners[index].finish = time;
		} else if (point == "S1") {
			runners[index].time_1 = time;
		} else if (point == "S2") {
			runners[index].time_2 = time;
		}
	}

	vector< pair<int,string> > split1;
	vector< pair<int,string> > split2;
	vector< pair<int,string> > thefinish;

	for (int i = 0; i < runners.size(); i++) {
		pair<int,string> temp1;

		temp1 = make_pair(i, runners[i].time_1);
		split1.push_back(temp1);
	}

	sort(split1.begin(), split1.end(), compare);

	vector< pair<int,int> > position1; // frist is rank,second is index
	pair<int,int> rank1;
	rank1 = make_pair(1, split1[0].first);
	position1.push_back(rank1);

	for (int i = 1; i < split1.size(); i++) {
		pair<int,int> temp11;

		temp11.second = split1[i].first; // set the second element as the orignal index

		if (split1[i].second == split1[i-1].second) {
			temp11.first = position1[i-1].first;
		} else {
			temp11.first = i + 1;
		}

		position1.push_back(temp11);
	}

	for (int i = 0; i < position1.size(); i++) {
		runners[position1[i].second].rank1 = position1[i].first;
	}

	cout << "NAME                " << "       BIB" << "    SPLIT1" << "      RANK" << "    SPLIT2" << "      RANK" << "    FINISH" <<
		"      RANK" << endl;

	for (int i = 0; i < runners.size(); i++) {
		cout << runners[i].last << ", " << runners[i].first;
		int spaces = 20 - runners[i].last.length() - runners[i].first.length();

		while (spaces--) { cout << " "; } // creates spacing;

		cout << "     " << runners[i].bib << "     " << runners[i].time_1 << "         " << runners[i].rank1 << endl;
	}

	runners.clear();

}
