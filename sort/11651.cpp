#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> arr[100000];
pair<int, int> tmp[100000];

void merge(int st, int en) {
    int mid = (st+en)/2;
    int lidx = st;
    int ridx = mid;

    for (int i = st; i < en; i++) {
        if (ridx == en) tmp[i] = arr[lidx++];
        else if (lidx == mid) tmp[i] = arr[ridx++];
        else if (arr[lidx].second < arr[ridx].second) tmp[i] = arr[lidx++];
        else if (arr[lidx].second == arr[ridx].second) {
            if (arr[lidx].first < arr[ridx].first) tmp[i] = arr[lidx++];
            else tmp[i] = arr[ridx++];
        }
        else tmp[i] = arr[ridx++];
    }

    for (int i = st; i < en; i++) arr[i] = tmp[i];
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
        cin >> arr[i].first >> arr[i].second;
    }

    merge_sort(0, n);
    for (int i = 0; i < n; i++) cout << arr[i].first << " " << arr[i].second << "\n";
}