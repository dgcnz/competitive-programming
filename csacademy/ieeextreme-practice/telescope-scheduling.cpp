#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll  = long long;
using ii  = pair<int, int>;
using iii = array<int, 3>;
using vi  = vector<int>;

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

int solve(int n, vector<iii> stars)
{
    sort(all(stars));
    vi dp(n + 1, 0);

    for (int i = 1; i <= n; ++i)
    {
        auto [ei, si, di] = stars[i];
        dp[i]             = dp[i - 1];

        auto it = lower_bound(all(stars), iii{si, 0, 0});
        if (it != stars.begin())
        {
            --it;
            int j = distance(stars.begin(), it);
            dp[i] = max(dp[i], dp[j] + di);
        }
    }
    return dp[n];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vector<iii> stars(n + 1);
    stars[0] = {-1, -1, -1};
    for (int i = 1; i <= n; ++i)
        cin >> stars[i][1] >> stars[i][0] >> stars[i][2];

    cout << solve(n, stars) << endl;

    return 0;
}
