#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	set<string> s;

	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;

		s.insert(str);
	}

	int size = s.size();
	
	vector<string> vec;

	for (auto itr = s.begin(); itr != s.end(); itr++) {
		vec.push_back(*itr);
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << vec[i] << ' ' << vec[j] << '\n';
		}
	}
}
