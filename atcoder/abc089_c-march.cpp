/** @file
 * @date                2020-12-09
 * @url                 https://atcoder.jp/contests/abc089/tasks/abc089_c
 * @tags                counting
 * @status              AC
 * @score               1
 * @difficulty          0
 * @editorial           no
 * @reading_time        1
 * @thinking_time       1
 * @coding_time         5
 * @time_complexity     O(1)
 * @memory_complexity   O(n)
 * @idea
 * Mantain count of strings that start with one of "MARCH" letters.
 * Count all possible triplets.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
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
    const string march = "MARCH";
    array<ll, 5> cnt;
    fill(all(cnt), 0);

    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (auto it = find(all(march), s[0]); it != end(march))
            cnt[distance(begin(march), it)]++;
    }

    ll ans = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = i + 1; j < 4; ++j)
            for (int k = j + 1; k < 5; ++k)
                ans += cnt[i] * cnt[j] * cnt[k];

    cout << ans << endl;

    return 0;
}
