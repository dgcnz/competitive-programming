---
layout: post
title: 1420A Cubes Sorting
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
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        for (auto &ai : a)
            cin >> ai;
        bool ans = is_sorted(a.begin(), a.end(), [](int a, int b) { return a >= b; });
        cout << (ans ? "NO" : "YES") << endl;
    }
    return 0;
}

```
