---
layout: post
title: 873B Balanced Substring
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
int solve1(vi a)
{
    int n = (int)a.size(), ans = 0;
    for (int l = 0; l < n - 1; ++l)
        for (int r = l + 1; r < n; ++r)
            if (accumulate(a.begin() + l, a.begin() + r + 1, 0) == 0)
                ans = max(ans, (r - l + 1));
    return ans;
}
vi prefix_sum(vi a)
{
    int n = (int)a.size();
    vi pa(n);
    for (int i = 0; i < n; ++i)
        pa[i] = a[i] + (i == 0 ? 0 : pa[i - 1]);
    return pa;
}
int solve2(vi a)
{
    int n = (int)a.size(), ans = 0;
    vi pa = prefix_sum(a);
    auto sum = [&pa](int l, int r) { return pa[r] - (l == 0 ? 0 : pa[l - 1]); };
    for (int l = 0; l < n - 1; ++l)
        for (int r = l + 1; r < n; ++r)
            if (sum(l, r) == 0)
                ans = max(ans, (r - l + 1));
    return ans;
}
int solve3(vi a)
{
    int n = (int)a.size(), ans = 0;
    map<int, int> sum_ix;
    sum_ix[0] = -1;
    int ps = 0;
    for (int i = 0; i < n; ++i)
    {
        ps += a[i];
        if (sum_ix.find(ps) == sum_ix.end())
            sum_ix[ps] = i;
        else
            ans = max(ans, i - sum_ix[ps]);
    }
    return ans;
}
int main(void)
{
    int n;
    string s;
    cin >> n >> s;
    vi a(n);
    transform(s.begin(), s.end(), a.begin(), [](char c) { return c == '0' ? -1 : +1; });
    cout << solve3(a) << endl;
    return 0;
}

```
