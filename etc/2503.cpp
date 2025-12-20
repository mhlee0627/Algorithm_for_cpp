#include <bits/stdc++.h>
using namespace std;

int n;
int num[105];
pair<int, int> ret[105];

pair<int, int> baseball(int cur, int ref) {
	string cur_str = to_string(cur);
	string ref_str = to_string(ref);
	int stk = 0;
	int ball = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (cur_str[i] == ref_str[j]) {
				if (i == j) stk++;
				else ball++;
			}
		}
	}

	return {stk, ball};
}

bool checkvalid(int nn) {
	string nstr = to_string(nn);

	for (int i = 0; i < 3; i++) if (nstr[i] == '0') return false;

	if (nstr[0] == nstr[1]) return false;
	else if (nstr[0] == nstr[2]) return false;
	else if (nstr[1] == nstr[2]) return false;
	else return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		int s, b;
		cin >> s >> b;
		ret[i] = {s, b};
	}

	int r = 0;
	for (int i = 100; i < 1000; i++) {
		if (checkvalid(i)) {
			bool success = true;
			for (int j = 0; j < n; j++) {
				auto cur = baseball(num[j], i);
				if ((cur.first != ret[j].first) || (cur.second != ret[j].second)) success = false;
			}

			if (success) r++;
		}
	}

	cout << r << '\n';
}
