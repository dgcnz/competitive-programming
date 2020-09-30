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

int solve(int n, int c, vi w, vi f)
{
    vector<vi> dp(n + 1, vi(c + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int cc = 1; cc <= c; ++cc)
        {
            auto &ans = dp[i][cc];
            ans       = dp[i - 1][cc];
            if (w[i - 1] <= cc)
                ans = max(ans, dp[i - 1][cc - w[i - 1]] + f[i - 1]);
        }
    }

    return dp[n][c];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> c >> n;
        vi w(n), f(n);
        for (int i = 0; i < n; ++i)
            cin >> w[i] >> f[i];

        cout << solve(n, c, w, f) << endl;
    }
    return 0;
}
