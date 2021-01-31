/** @file
 * @date                2021-01-31
 * @url                 https://atcoder.jp/contests/abc181/tasks/abc181_d
 * @tags                math, brute_force
 * @status              AC
 * @score               0
 * @difficulty          2
 * @editorial           yes
 * @reading_time        1
 * @thinking_time       10
 * @coding_time         15
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * It's a known rule that numbers whose last three digits are divisible by 8,
 * are also divisible by 8. We can therefore split the problem into two cases:
 *
 * 1. $x >= 100$: Do as said above
 * 2. $x < 100$: Brute_force all multiples of 8 and reverse multiples of 8,
 * $<100$.
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

bool solve(string s)
{
    if (s.size() <= 2)
    {
        int x = stoi(s);
        reverse(all(s));
        int y = stoi(s);
        if (x % 8 == 0 or y % 8 == 0)
            return true;
    }

    vector<int> cnt(10, 0);

    for (auto c : s)
        cnt[c - '0']++;

    for (int x = 104; x < 1000; x += 8)
    {
        auto d = cnt;
        for (char x : to_string(x))
            d[x - '0']--;
        if (all_of(all(d), [](int x) { return x >= 0; }))
            return true;
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    string s;
    cin >> s;

    cout << (solve(s) ? "Yes" : "No") << endl;
    return 0;
}
