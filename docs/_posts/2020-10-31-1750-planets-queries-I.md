---
layout: post
title: 1750 Planets Queries I
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using vi = vector<int>;
const int NMAX = 2e5 + 11;
const int PTWO = 32;
int _succ[NMAX][PTWO];
int succ(int x, int k, int i = 0)
{
    if (k == 0)
        return x;
    if (k == 1)
        return _succ[x][i];
    int rem = k % 2;
    if (rem == 1)
        return _succ[succ(x, k / 2, i + 1)][i];
    else
        return succ(x, k / 2, i + 1);
}
int main(void)
{
    int n, q, x, k;
    cin >> n >> q;
    for (int u = 1; u <= n; ++u)
        cin >> _succ[u][0];
    for (int p = 1; p < PTWO; ++p)
    {
        for (int u = 1; u <= n; ++u)
        {
            _succ[u][p] = _succ[_succ[u][p - 1]][p - 1];
        }
    }
    while (q--)
    {
        cin >> x >> k;
        cout << succ(x, k) << endl;
    }
    return 0;
}

```
