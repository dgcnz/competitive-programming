/** @file
 * @date                2021-01-07
 * @url                 https://codeforces.com/contest/1419/problem/D2
 * @tags                binary_search, greedy
 * @status              AC
 * @score               1
 * @difficulty          4
 * @editorial           yes
 * @reading_time        1
 * @thinking_time       30
 * @coding_time         30
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Given a number of desired cheap ice, $x$, pick the $x$ smallest numbers and
 * alternate them with the larges ones. Binary search to find $x$.
 *
 * [Editorial](https://codeforces.com/blog/entry/82817).
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

int bs(int l, int r, function<bool(int)> p)
{
    // 1 1 1 0 0
    while (l < r)
    {
        int m = l + (r - l + 1) / 2;
        if (p(m))
            l = m;
        else
            r = m - 1;
    }
    return l;
}

int solve(vi &a)
{
    int n = isz(a);
    sort(all(a));

    auto ok = [&a, n](int x) {
        for (int i = 0; i < x; i++)
        {
            int j = x - i - 1, l = n - i - 2, r = n - i - 1;
            if (!(a[l] > a[j] and a[j] < a[r]))
                return false;
        }
        return true;
    };

    int x = bs(0, (n - 1) / 2, ok);
    if (x == 0)
        return x;

    int i = n - 1;
    vi  left(a.begin(), a.begin() + x), right(a.begin() + x, a.end());
    while (left.size())
    {
        a[i--] = right.back();
        right.pop_back();
        a[i--] = left.back();
        left.pop_back();
    }
    while (right.size())
    {
        a[i--] = right.back();
        right.pop_back();
    }
    return x;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n;
    cin >> n;

    vi a(n);
    for (auto &ai : a)
        cin >> ai;

    cout << solve(a) << endl;
    for (auto ai : a)
        cout << ai << " ";
    cout << endl;
    return 0;
}
