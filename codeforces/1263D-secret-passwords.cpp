/** @file
 * @date                2021-02-01
 * @url                 https://codeforces.com/problemset/problem/1263/D
 * @tags                dsu
 * @status              AC
 * @score               2
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       3
 * @coding_time         10
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Let's say we have a graph of the 26 alphabet characters. Each string
 * basically states that all the characters it contains are an equivalence class
 * (a connected component, in this setting).
 *
 * So, we'll insert the strings in that manner and then count the number of
 * equivalence classes (connected components) that are valid (note that some
 * characters might not have appeared in the strings).
 *
 * One password for each equivalence class is the minimum number of trials to
 * ensure the hack.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/dsu>
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
    int n;
    cin >> n;

    vector<vector<char>> cnt(n, vector<char>(26, 0));
    atcoder::dsu         dsu(26);
    vector<bool>         vis(26);

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        char ch = s.front();
        for (auto c : s)
        {
            vis[c - 'a'] = true;
            dsu.merge(ch - 'a', c - 'a');
        }
    }

    auto groups = dsu.groups();
    int  ans    = 0;
    for (auto g : groups)
        if (g.size() > 1 or vis[g.front()])
            ans++;

    cout << ans << endl;

    return 0;
}
