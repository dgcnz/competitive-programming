/** @file
 * @date                2021-01-10
 * @url                 https://codeforces.com/contest/1108/problem/D
 * @tags                greedy, implementation
 * @status              AC
 * @score               0
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         14
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Fix blocks of consecutive characters greedily.
 * [Editorial](https://codeforces.com/blog/entry/64751).
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

char mex(string alpha, vector<char> prohibited)
{
    for (auto c : alpha)
        if (find(all(prohibited), c) == prohibited.end())
            return c;
    return 0;
}

int solve(string &s)
{
    int i = 0, n = isz(s), ans = 0;
    s += " ";
    while (i < n)
    {
        int j = i + 1;
        while (j < n and s[i] == s[j])
            ++j;
        if (j - i > 1)
        {
            for (int k = i + 1; k < j - 1; k += 2)
                s[k] = mex("RGB", {s[i]}), ans++;
            if ((j - i) % 2 == 0)
                s[j - 1] = mex("RGB", {s[i], s[j]}), ans++;
        }
        i = j;
    }
    s.pop_back();

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int    n;
    string s;
    cin >> n >> s;

    cout << solve(s) << endl;
    cout << s << endl;
    return 0;
}
