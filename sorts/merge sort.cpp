/*
*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|     ( website: himanshu010.github.io/Portfolio_website )  |
|                                                           |
|                                                           |
*-----------------------------------------------------------*
*/
#include<bits/stdc++.h>
#define moduli 998244353
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
#define PQ priority_queue
using namespace std;


void merge(int *a, int n, int s, int mid, int e) {
    int temp[e - s + 1];
    int i = s, j = mid + 1, k = 0;
    while (i <= mid and j <= e) {
        if (a[i] <= a[j]) {
            temp[k] = a[i];
            i++;
        }
        else {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= e) {
        temp[k++] = a[j++];
    }

    for (int i = s; i <= e; ++i)
    {
        a[i] = temp[i - s];
    }
}

void mergeSort(int *a, int n, int s, int e) {
    if (s >= e) {
        return;
    }
    int mid = s + (e - s) / 2;
    merge(a, n, s, mid, e);
    mergeSort(a, n, s, mid);
    mergeSort(a, n, mid + 1, e);
}

void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    mergeSort(a, n, 0, n - 1);
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << ' ';
    }
    cout << endl;

}
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}