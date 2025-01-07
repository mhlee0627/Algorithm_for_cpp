#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, string> arr[100001];
pair<int, string> temp[100001];

void merge(int st, int en) {
    int mid = (st+en)/2;
    int lidx = st;
    int ridx = mid;

    for (int i = st; i < en; i++) {
        if (ridx == en) {
            temp[i] = arr[lidx++];
        }
        else if (lidx == mid) {
            temp[i] = arr[ridx++];
        }
        else if (arr[lidx].first <= arr[ridx].first) {
            temp[i] = arr[lidx++];
        }
        else {
            temp[i] = arr[ridx++];
        }
    }

    for (int i = st; i < en; i++) arr[i] = temp[i];
}

void merge_sort(int st, int en) {
    if (st+1 == en) return;
    int mid = (st+en)/2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    merge_sort(0, n);
    for (int i = 0; i < n; i++) cout << arr[i].first << " " << arr[i].second << "\n";

}