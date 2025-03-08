#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set<string> us;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	string name;
	string cmd;
	for (int i = 0; i < n; i++) {
		cin >> name >> cmd;
		if (cmd == "enter") {
			us.insert(name);
		}
		else {
			us.erase(name);
		}
	}

	vector<string> vec;
	for (auto elem : us) {
		vec.push_back(elem);
	}	

	sort(vec.begin(), vec.end());

	for (int i = vec.size()-1; i >= 0; i--) {
		cout << vec[i] << '\n';
	}

}
