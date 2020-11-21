---
layout: post
title: 1392B Omkar Infinity Clock
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using ll = long long;
using vi = vector<int>;
int const NMAX = 2e5 + 11;
int n, a[NMAX];
ll k;
bool cyclic(void)
{
    bool zero = false;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < 0)
            return false;
        if (a[i] == 0)
            zero = true;
    }
    if (zero)
        return true;
    else
        return false;
}
void op(void)
{
    int d = *max_element(a, a + n);
    for (int i = 0; i < n; ++i)
        a[i] = d - a[i];
}
int main(void)
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        ll ki = 0;
        while (ki != k and not cyclic())
        {
            op();
            ++ki;
        }
        if ((k - ki) % 2 == 1)
            op();
        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}

```
