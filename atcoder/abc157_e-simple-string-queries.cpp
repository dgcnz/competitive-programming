/** @file
 * @date                2020-12-18
 * @url                 https://atcoder.jp/contests/abc157/tasks/abc157_e
 * @tags                segment_tree, data_structures
 * @status              AC
 * @score               2
 * @difficulty          1
 * @editorial           no
 * @reading_time        1
 * @thinking_time       5
 * @coding_time         15
 * @time_complexity     O(q \log{n})
 * @memory_complexity   O(n)
 * @idea
 * Build a segment tree where nodes store a frequency array of the characters in
 * their respective range.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(e) (e)
#endif
#include <atcoder/segtree>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

struct Node
{
    array<int, 26> cnt;
    Node() { fill(all(cnt), 0); }
    Node(int i) : Node() { cnt[i]++; }
};

Node op(Node a, Node b)
{
    Node ans;
    for (int i = 0; i < 26; ++i)
        ans.cnt[i] = a.cnt[i] + b.cnt[i];
    return ans;
}

Node e() { return Node(); }

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    int n, q;
    cin >> n;

    vector<Node> a(n);
    for (auto &x : a)
    {
        char ch;
        cin >> ch;
        x.cnt[ch - 'a']++;
    }

    atcoder::segtree<Node, op, e> st(a);

    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int  i;
            char ch;
            cin >> i >> ch, i--;
            st.set(i, Node(ch - 'a'));
        }
        else
        {
            int l, r;
            cin >> l >> r, l--;
            auto freq = st.prod(l, r).cnt;
            cout << count_if(all(freq), [](int x) { return x != 0; }) << endl;
        }
    }

    return 0;
}
