/** @file
 * @date                2020-11-24
 * @url                 https://www.spoj.com/problems/BRCKTS/
 * @tags                data_structures, segment_tree
 * @status              AC
 * @score               4
 * @difficulty          3
 * @editorial           no
 * @reading_time        2
 * @thinking_time       2
 * @coding_time         15
 * @time_complexity     O(m \log{n})
 * @memory_complexity   O(n)
 * @idea
 * - Build a segment tree where nodes represent the unmatched left and right
 * parenthesis.
 * - Merging nodes $L$ and $R$, would mean matching the unmatched right
 * parenthesis of $R$ with the unmatched left parenthesis of $L$.
 * - Checking if the string is unbalanced would be the same as checking if the
 * root segment tree node has 0 left and right unmatched parenthesis;
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

template <typename T, typename Container>
struct SegmentTree
{
    int       n;
    vector<T> t;
    SegmentTree(Container &a) : n(a.size())
    {
        t.resize(4 * n);
        build(a, 1, 0, n - 1);
    }
    void build(Container &a, int v, int tl, int tr)
    {
        if (tl == tr)
            t[v] = T(a[tl]);
        else
        {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    inline T merge(T a, T b) { return a + b; }
    T        query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return T();
        if (l == tl and r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return merge(query(v * 2, tl, tm, l, min(r, tm)),
                     query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    void update(int v, int tl, int tr, int pos, T new_val)
    {
        if (tl == tr)
            t[v] = new_val;
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
};

struct Node
{
    int umleft, umright;

    Node() { umleft = umright = -1; } // this is the unit node
    Node(int umleft, int umright) : umleft(umleft), umright(umright) {}
    explicit Node(char c) : umleft(c == '('), umright(c == ')') {}

    bool operator==(Node const &other) const
    {
        return umleft == other.umleft and umright == other.umright;
    }
    Node operator+(Node const &right_node) const
    {
        if (this->operator==(Node()))
            return right_node;
        if (right_node == Node())
            return *this;

        int matches = min(umleft, right_node.umright);
        return {right_node.umleft + umleft - matches,
                right_node.umright + umright - matches};
    }
    bool balanced(void) const { return umleft == 0 and umright == 0; }
};

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t = 10;
    while (t--)
    {
        int    n, m;
        string brackets;
        cin >> n >> brackets >> m;
        SegmentTree<Node, string> st(brackets);

        cout << "Test " << 10 - t << ":\n";
        while (m--)
        {
            int k;
            cin >> k;
            if (k == 0)
            {
                cout << (st.query(1, 0, n - 1, 0, n - 1).balanced() ? "YES"
                                                                    : "NO")
                     << '\n';
            }
            else
            {
                k--;
                brackets[k] = (brackets[k] == '(' ? ')' : '(');
                st.update(1, 0, n - 1, k, Node(brackets[k]));
            }
        }
    }
    return 0;
}
