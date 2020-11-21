---
layout: post
title: 1641 Sum Of Three Values
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
int main(void)
{
    int n;
    ll x;
    cin >> n >> x;
    vii a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
    {
        int target = x - a[i].first;
        for (int j = i + 1, k = n - 1; j < k; ++j)
        {
            while (j < k and a[j].first + a[k].first > target)
                --k;
            if (j < k and a[j].first + a[k].first == target)
            {
                cout << a[i].second + 1 << " " << a[j].second + 1 << " "
                     << a[k].second + 1 << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}

```
