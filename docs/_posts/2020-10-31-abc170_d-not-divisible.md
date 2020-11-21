---
layout: post
title: Abc170_D Not Divisible
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using vi = vector<int>;
const int AMAX = 1e6 + 11;
int main(void)
{
    int n;
    vi a, freq;
    cin >> n;
    a.resize(n);
    for (auto &ai : a)
        cin >> ai;
    sort(a.begin(), a.end());
    freq.resize(AMAX);
    freq[a[0]]++;
    int ans = a[0] != a[1];
    for (int i = 1; i < n; ++i)
    {
        bool ok = true;
        if (i < n - 1 and a[i] == a[i + 1])
            ok = false;
        if (ok)
        {
            for (int d = 1; d * d <= a[i]; ++d)
            {
                if (a[i] % d == 0)
                {
                    if (freq[d] or freq[a[i] / d])
                    {
                        ok = false;
                        break;
                    }
                }
            }
        }
        ans += ok;
        freq[a[i]]++;
    }
    cout << ans << endl;
    return 0;
}

```
