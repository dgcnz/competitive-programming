/** @file
 * @date                2020-12-18
 * @url                 https://atcoder.jp/contests/abc157/tasks/abc157_c
 * @tags                implementation, greedy
 * @status              AC
 * @score               0
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       2
 * @coding_time         10
 * @time_complexity     O(m + n)
 * @memory_complexity   O(n)
 * @idea
 * Implement statement and handle edge cases. Fill every unknown space with a
 * $0$ if it's not the first digit ($1$ in that case).
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(e) (e)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vi s(n, -1);

    bool flag = true;
    while (m--)
    {
        int i, c;
        cin >> i >> c, i--;

        if (s[i] != -1 and s[i] != c)
            flag = false;
        if (i == 0 and c == 0 and n != 1)
            flag = false;
        s[i] = c;
    }

    if (flag)
    {
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == -1)
                s[i] = (i == 0 and n != 1);
            cout << s[i];
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
