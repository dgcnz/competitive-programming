#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

string solve(vector<ii> ab, [[maybe_unused]] int n)
{
    int m = ab.size();

    map<int, int> cnt;
    for (auto [a, b] : ab)
        cnt[a]++, cnt[b]++;

    for (auto [x, c] : cnt)
    {
        if (c == m)
            return "YES";
        if (c * 2 >= m) // At most 4 candidates
        {
            map<int, int> temp_cnt;
            for (auto [a, b] : ab) // O(m)
                if (a != x and b != x)
                    temp_cnt[a]++, temp_cnt[b]++;

            for (auto [y, rc] : temp_cnt)
                if (c + rc == m)
                    return "YES";
        }
    }
    return "NO";
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<ii> ab(m);
    for (auto &[a, b] : ab)
        cin >> a >> b;
    cout << solve(ab, n) << endl;
    return 0;
}
