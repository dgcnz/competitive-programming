#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using vi        = vector<int>;
using predicate = function<bool(int)>;

int    n, m;
vi     a;
string s, t;

bool ok(int q)
{
    vector<bool> usable(n, true);
    for (int i = 0; i < q; ++i)
        usable[a[i]] = false;

    int j = 0;
    for (int i = 0; i < n and j < m; ++i)
        if (usable[i] and t[j] == s[i])
            ++j;
    return j == m;
}

int bs(int l, int r, predicate p)
{
    while (l < r)
    {
        int m = l + (r - l + 1) / 2;
        if (p(m))
            l = m;
        else
            r = m - 1;
    }
    return l;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> s >> t;
    n = isz(s), m = isz(t);
    a.resize(n);

    for (auto &ai : a)
        cin >> ai, ai--;

    cout << bs(0, n, ok) << endl;
    return 0;
}
