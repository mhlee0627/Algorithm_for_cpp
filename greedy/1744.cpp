#include <bits/stdc++.h>
using namespace std;

int n;
int arr[55];

void print() {
	cout << '\n';
	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
	cout << '\n';
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr+n);

	int zero = 0;
	int one = 0;
	int mn = 0;
	int pn = 0;
    for (int i = 0; i < n; i++) {
		if (arr[i] == 0) zero++;
		else if (arr[i] == 1) one++;
		else if (arr[i] > 1) pn++;
		else mn++;
	}

	//cout << "zero: " << zero << '\n';
	//cout << "pn: " << pn << '\n';
	//cout << "mn: " << mn << '\n';

	int sum = 0;
	
	for (int i = 0; i < mn-1; i += 2) {
		sum += (arr[i] * arr[i+1]);
		//cout << "s1: " << sum << '\n';
	}

	if (mn%2 == 1 && zero == 0) {
		sum += arr[mn-1];
		//cout << "s2: " << sum << '\n';
	}

	int index = mn + zero;
	
	if (one > 0) {
		sum += one;
		index += one;
	}

	if (pn%2 == 1) {
		sum += arr[index];
		index++;
		//cout << "s3: " << sum << '\n';
	}

	for (index; index < n; index += 2) {
		sum += (arr[index] * arr[index+1]);
		//cout << "s4: " << sum << '\n';
	}

	cout << sum << '\n';
}
