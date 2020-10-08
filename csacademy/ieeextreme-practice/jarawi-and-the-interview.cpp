#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll        = long long;
using ii        = pair<int, int>;
using vi        = vector<int>;
using predicate = function<bool(int)>;

int const NMAX = 1e6 + 11;

int              n, m;
string           s, pi;
vector<set<int>> sorted_s(26);
int              next_ch[26][NMAX];

bool ok(int suffix_size)
{
    int ix = 0;
    for (int i = m - suffix_size + 1; i <= m; ++i)
    {
        ix = next_ch[pi[i] - 'a'][ix];
        if (ix == n + 1)
            return false;
    }
    return true;
}

// true true true  false false // last true
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
    int q;
    cin >> s;

    n = isz(s);
    s = ' ' + s;
    for (int i = 1; i <= n; ++i)
        next_ch[s[i] - 'a'][i - 1] = i;

    for (int c = 0; c < 26; ++c)
    {
        int last = n + 1;
        for (int i = n; i >= 0; --i)
        {
            if (next_ch[c][i])
                last = next_ch[c][i];
            else
                next_ch[c][i] = last;
        }
    }

    cin >> q;
    while (q--)
    {
        cin >> pi;
        m  = isz(pi);
        pi = ' ' + pi;
        cout << bs(0, m, ok) << endl;
    }

    return 0;
}
