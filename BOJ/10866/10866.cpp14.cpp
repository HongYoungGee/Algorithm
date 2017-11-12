#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    
	deque<int> dq;
    
	int N;
	cin >> N;
    
	for (int i = 0; i < N; i++) {
		string s;
		int X;
		cin >> s;
		if (s == "push_back") {
			cin >> X;
			dq.push_back(X);
		} else if (s == "push_front") {
			cin >> X;
			dq.push_front(X);
		} else if (s == "pop_front") {
			if (dq.empty())
				cout << -1 <<endl;
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		} else if (s == "pop_back") {
			if (dq.empty())
				cout << -1 <<endl;
			else {
				cout << dq.back() <<endl;
				dq.pop_back();
			}
		} else if (s == "size") {
			cout << dq.size() <<endl;
		} else if (s == "empty") {
			cout << dq.empty() <<endl;
		} else if (s == "front") {
			if (dq.empty())
				cout << -1 << endl;
			else
				cout << dq.front() <<endl;
		} else if (s == "back") {
			if (dq.empty())
				cout << -1 << endl;
			else
				cout << dq.back() << endl;
		}
	}
}