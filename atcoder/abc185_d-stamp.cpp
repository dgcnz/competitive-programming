/** @file
 * @date                2020-12-13
 * @url                 https://atcoder.jp/contests/abc185/tasks/abc185_d
 * @tags                implementation, greedy
 * @status              AC
 * @score               2
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       3
 * @coding_time         10
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Assume that array $A$ is sorted.
 *
 * Compute in $O(n)$ the length of all the white stripes (consecutive blocks of
 * white squares). Note that the optimal answer is taking a stamp with size
 * equals to the minimum length of such stripes (if bigger, then it wouldn't
 * fit). The answer would then be:
 *
 * $$ ans = \sum_{s \in S} ceil(s, k) $$
 *
 * Where $S$ is the set of stripe lengths and $k$ the minimum element of such
 * set.
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

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}

inline ll ceil(ll a, ll b) { return (a + b - 1) / b; }

ll solve(vector<ll> a)
{
    sort(all(a));

    ll         prev = 0;
    vector<ll> stripes;
    for (auto ai : a)
    {
        if (ai - prev - 1 > 0)
            stripes.push_back(ai - prev - 1);
        prev = ai;
    }
    if (stripes.empty())
        return 0;

    ll k = *min_element(all(stripes)), ans = 0;
    for (auto st : stripes)
        ans += ceil(st, k);
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    if (m != 0)
    {
        vector<ll> a(m + 1);
        read_n(begin(a), m);
        a[m] = n + 1;
        cout << solve(a) << endl;
    }
    else
        cout << 1 << endl;
    return 0;
}
