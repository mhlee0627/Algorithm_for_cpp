#include <bits/stdc++.h>
using namespace std;

string in;
bool parr[13];
bool karr[13];
bool harr[13];
bool tarr[13];

int func(char a, char b) {
	return (a - '0') * 10 + (b - '0');
}

int func2(bool arr[]) {
	int ret = 0;

	for (int i = 1; i <= 13; i++) {
		if (arr[i] == false) ret++;
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> in;

	for (int i = 0; i < in.size(); i += 3) {
		char card = in[i];
		char a = in[i+1];
		char b = in[i+2];
		int idx = func(a, b);

		if (card == 'P') {
			if (parr[idx]) {
				cout << "GRESKA\n";
				return 0;
			}
			else {
				parr[idx] = true;
			}
		}
		else if (card == 'K') {
			if (karr[idx]) {
				cout << "GRESKA\n";
				return 0;
			}
			else {
				karr[idx] = true;
			}
		}
		else if (card == 'H') {
			if (harr[idx]) {
				cout << "GRESKA\n";
				return 0;
			}
			else {
				harr[idx] = true;
			}
		}
		else {
			if (tarr[idx]) {
				cout << "GRESKA\n";
				return 0;
			}
			else {
				tarr[idx] = true;
			}
		}
	}

	cout << func2(parr) << ' ' << func2(karr) << ' ' << func2(harr) << ' ' << func2(tarr) << '\n';
}
