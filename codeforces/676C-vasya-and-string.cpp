/** @file
 * @date                2021-01-22
 * @url                 http://codeforces.com/contest/676/problem/C
 * @tags                two_pointers
 * @status              AC
 * @score               3
 * @difficulty          2
 * @editorial           no
 * @reading_time        1
 * @thinking_time       15
 * @coding_time         10
 * @time_complexity     O(n)
 * @memory_complexity   O(n)
 * @idea
 * Without loss of generality, we want to find the largest substring consisting
 * of `a`s. To make this task easier, we can fix the right border, $r$ of this
 * hypothetical subarray.
 *
 * Note that for a given $r$, to find the longest substring ending at $r$ we
 * should try to expand the left border as much as possible.
 *
 * So, following this idea, we can try all $r$'s and find their corresponding
 * $l$'s using the two pointers technique or binary search.
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

int solve(string s, int k)
{
    int n = isz(s);
    vi  a(n, 0), b(n, 0);

    for (int i = 0; i < n; ++i)
    {
        a[i] += s[i] == 'a';
        b[i] += s[i] == 'b';
        if (i > 0)
            a[i] += a[i - 1], b[i] += b[i - 1];
    }

    auto cnt = [](vi &c, int l, int r) {
        return c[r] - (l > 0 ? c[l - 1] : 0);
    };

    int ans = 0;
    for (int r = 0, la = 0, lb = 0; r < n; ++r)
    {
        // false false true true
        while (cnt(b, la, r) > k)
            ++la;
        while (cnt(a, lb, r) > k)
            ++lb;
        ans = max({ans, r - la + 1, r - lb + 1});
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, k;

    string s;
    cin >> n >> k >> s;
    cout << solve(s, k) << endl;

    return 0;
}
