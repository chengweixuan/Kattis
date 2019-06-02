#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n; // number of researchers
	int m; cin >> m; // locking time

	priority_queue<int, vector<int>, greater<int> > leaving; // leaving time
	priority_queue<int, vector<int>, greater<int> > arrival; // arrival time

	int temp;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; // arriving time
		int s; cin >> s; // staying time
		
		// into arrival
		arrival.push(a);
		// into leaving
		temp = a + s;
		leaving.push(temp);
	}

	int counter = 0;

	while ( !arrival.empty() ) {
		
		if (arrival.top() >= leaving.top() && arrival.top() <= ( leaving.top() + m) ) {
			counter++;
			leaving.pop();
			arrival.pop();
		} else if (arrival.top() > (leaving.top() + m) ) {
			leaving.pop();
		} else {

		arrival.pop();
		}
	}
	

	cout << counter;
}
