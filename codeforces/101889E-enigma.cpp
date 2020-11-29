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

int const NMAX = 1e3 + 11;
int const XMAX = 1e3 + 11;

int    n, x;
string s;
bool   dp[NMAX][XMAX], vis[NMAX][XMAX];
char   ans[NMAX];

bool possible(int i, int rem)
{
    if (i == n)
        return rem == 0;

    auto &cur = dp[i][rem];
    if (vis[i][rem])
        return cur;

    vis[i][rem] = true;

    if (s[i] == '?')
    {
        for (int d = (i == 0); d <= 9; ++d)
        {
            ans[i] = d + '0';
            if (possible(i + 1, (10 * rem + d) % x))
                return cur = true;
            ans[i] = 0;
        }
    }
    else
    {
        int d  = s[i] - '0';
        ans[i] = d + '0';
        if (possible(i + 1, (10 * rem + d) % x))
            return cur = true;
        ans[i] = 0;
    }
    return cur = false;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    while (cin >> s >> x)
    {
        n = isz(s);
        memset(dp, 0, sizeof dp);
        memset(vis, 0, sizeof vis);
        memset(ans, 0, sizeof ans);
        if (possible(0, 0))
            write(ans, ans + n, ""), cout << endl;
        else
            cout << "*" << endl;
    }

    return 0;
}
