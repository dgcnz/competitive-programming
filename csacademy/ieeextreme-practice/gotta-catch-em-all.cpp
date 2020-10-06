#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

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

using predicate = function<bool(int)>;

int const INF  = 1e9;
int const NMAX = 200 + 11;

int n, m, delta[NMAX][NMAX];

bool ok(int health)
{
    vector<vi> dp(n + 1, vi(m + 1, -INF));

    dp[1][1] = health;
    for (int r = 1; r <= n; ++r)
    {
        for (int c = 1; c <= m; ++c)
        {
            if (r == 1 and c == 1)
                continue;
            auto &ans = dp[r][c];
            ans       = max(dp[r - 1][c], dp[r][c - 1]) + delta[r][c];
            if (ans <= 0)
                ans = -INF;
        }
    }

    return dp[n][m] >= 1;
}

int bs(int l, int r, predicate p)
{
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (p(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        read_n(delta[i] + 1, m);

    cout << bs(1, 2e6, ok) << endl;
    return 0;
}
