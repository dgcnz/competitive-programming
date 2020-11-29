#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) (c).begin(), (c).end()
#define isz(c) (int)(c).size()

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

int const INF = 1e9;

int n, atime, m1, m2;
vi  t, dep_left, dep_right, acc_time;

// optional<int> solve(void)
int solve(void)
{
    vector<vi> dp(n + 2, vi(atime + 1, INF));
    dp[1][0] = 0;
    for (int tt = 1; tt <= atime; ++tt)
    {
        for (int i = 1; i <= n; ++i) // station
        {
            auto &ans = dp[i][tt];
            ans       = min(INF, dp[i][tt - 1] + 1);

            // if there is a train at time: tt = dep + delta, then we could have
            // taken a train from i - 1 to i
            if (i - 1 >= 1 and tt - acc_time[i] >= 0 and
                binary_search(all(dep_left), tt - acc_time[i]))
            {
                ans = min(ans, dp[i - 1][tt - t[i]]); // ->
            }

            if (i + 1 <= n and tt - (acc_time[n] - acc_time[i]) >= 0 and
                binary_search(all(dep_right), tt - (acc_time[n] - acc_time[i])))
            {
                ans = min(ans, dp[i + 1][tt - t[i + 1]]); // <-
            }
        }
    }
    // return dp[n][atime] == INF ? nullopt : make_optional(dp[n][atime]);
    return dp[n][atime] == INF ? -1 : dp[n][atime];
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    int tc = 1;
    while (cin >> n and n)
    {
        cin >> atime;
        t.resize(n + 1, 0), read_n(t.begin() + 2, n - 1);
        acc_time.resize(n + 1, 0), partial_sum(all(t), begin(acc_time));
        cin >> m1;
        dep_left.resize(m1, 0), read_n(dep_left.begin(), m1);
        cin >> m2;
        dep_right.resize(m2, 0), read_n(dep_right.begin(), m2);

        cout << "Case Number " << tc << ": ";
        if (auto ans = solve(); ans != -1)
            cout << ans << endl;
        else
            cout << "impossible" << endl;

        tc++;
    }

    return 0;
}
