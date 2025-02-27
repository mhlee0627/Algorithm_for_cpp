#include <bits/stdc++.h>
using namespace std;

int n, k;
tuple<int, int, int> t[100005];
long long sum;

bool cmp0(tuple<int, int, int> &a, tuple<int, int, int> &b) {
	return get<0>(a) > get<0>(b);
}

bool cmp1(tuple<int, int, int> &a, tuple<int, int, int> &b) {
	return get<1>(a) > get<1>(b);
}

bool cmp2(tuple<int, int, int> &a, tuple<int, int, int> &b) {
	return get<2>(a) > get<2>(b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		t[i] = {a+b, a+c, b+c};
	}

	long long ab = 0;
	long long bc = 0;
	long long ac = 0;

	sort(t, t+n, cmp0);
	for (int i = 0; i < k; i++) {
		ab += get<0>(t[i]);
		bc += get<1>(t[i]);
		ac += get<2>(t[i]);
	}
	sum = max(sum, ab);
	sum = max(sum, bc);
	sum = max(sum, ac);


	ab = 0;
	bc = 0;
	ac = 0;

	sort(t, t+n, cmp1);
	for (int i = 0; i < k; i++) {
		ab += get<0>(t[i]);
		bc += get<1>(t[i]);
		ac += get<2>(t[i]);
	}
	sum = max(sum, ab);
	sum = max(sum, bc);
	sum = max(sum, ac);

	ab = 0;
	bc = 0;
	ac = 0;

	sort(t, t+n, cmp2);
	for (int i = 0; i < k; i++) {
		ab += get<0>(t[i]);
		bc += get<1>(t[i]);
		ac += get<2>(t[i]);
	}
	sum = max(sum, ab);
	sum = max(sum, bc);
	sum = max(sum, ac);

	cout << sum << '\n';
}
