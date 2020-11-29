#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll  = long long;
using ii  = pair<int, int>;
using vi  = vector<int>;
using vll = vector<ll>;

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void write(InputIterator first, InputIterator last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
}

int id(char c)
{
    switch (c)
    {
    case 'd':
        return 4;
    case 'r':
        return 3;
    case 'a':
        return 2;
    case 'h':
        return 1;
    default:
        return 0;
    }
}

ll solve(int n, string s, vll a)
{
    string t(" hard");
    vi     sorted[5];
    fill(sorted, sorted + 5, vi(1, 0));
    for (int i = 1; i <= n; ++i)
    {
        int j = id(s[i]);
        if (j > 0) // is hard
            sorted[j].push_back(i);
    }

    for (int i = 1; i <= 4; ++i)
    {
        if (isz(sorted[i]) == 0)
            return 0;
        sort(all(sorted[i]));
    }

    vll dp(n + 2, 1e17);
    int fst   = *sorted[id('h')].begin();
    sorted[0] = {-1, n + 1};
    dp[fst]   = a[fst];
    dp[0]     = 0;

    for (int i = fst + 1; i <= n; ++i)
    {
        int idd = id(s[i]);
        if (idd > 0)
        {
            auto &ans = dp[i];

            // Remove current letter and try with same letter on the left
            auto it = lower_bound(all(sorted[idd]), i);
            ans     = min(ans, dp[*prev(it)] + a[i]);

            // Try removing the previous letter
            it  = lower_bound(all(sorted[idd - 1]), i);
            ans = min(ans, dp[(n + 2 + *prev(it)) % (n + 2)]);
        }
    }
    return dp[sorted[id('d')].back()];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    int n;
    cin >> n;

    vll    a(n + 1);
    string s(n + 1, ' ');

    read_n(next(s.begin()), n);
    read_n(next(a.begin()), n);

    cout << solve(n, s, a) << endl;

    return 0;
}
