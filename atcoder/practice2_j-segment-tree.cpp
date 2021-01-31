/** @file
 * @date                2021-01-15
 * @url                 https://atcoder.jp/contests/practice2/tasks/practice2_j
 * @tags                data_structures, segment_tree, binary_search
 * @status              AC
 * @score               3
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       10
 * @coding_time         20
 * @time_complexity     O(q \log{n})
 * @memory_complexity   O(n)
 * @idea
 * [AC-Library
 * test](https://atcoder.github.io/ac-library/production/document_en/segtree.html)
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/segtree>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

using S = int;
S    op(S a, S b) { return max(a, b); }
S    e() { return -1; }
bool f(S target, S v) { return v < target; }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    vi a(n);
    for (auto &ai : a)
        cin >> ai;

    using RangeMax = atcoder::segtree<S, op, e>;
    using placeholders::_1;

    RangeMax st(a);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, v;
            cin >> x >> v, x--;
            st.set(x, v);
        }
        else if (type == 2)
        {
            int l, r;
            cin >> l >> r, l--;
            auto ans = st.prod(l, r);
            cout << ans << endl;
        }
        else // 3
        {
            int x, v;
            cin >> x >> v, x--;
            auto ans = st.max_right(x, bind(f, v, _1));
            cout << ans + 1 << endl;
        }
    }

    return 0;
}
