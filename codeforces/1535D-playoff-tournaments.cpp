#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

struct Node
{
    int  cntl, cntr;
    char cmp;
    int  answer() const
    {
        if (cmp == '?')
            return cntl + cntr;
        else if (cmp == '0')
            return cntl;
        else
            return cntr;
    }
    friend ostream &operator<<(ostream &os, const Node &node)
    {
        os << node.cmp << " " << node.answer() << " " << node.cntl << " "
           << node.cntr;
        return os;
    }
};

struct DataStructure
{
    int          k;
    vector<Node> t;
    vector<int>  parent;
    DataStructure(int k, string s)
        : k(k), t((1 << k) - 1), parent((1 << k) - 1, -1)
    {
        int m = (1 << (k - 1));
        for (int i = 0; i < m; ++i)
            t[i] = {1, 1, s[i]};

        int prv = 0, i = m;
        m /= 2;
        while (m)
        {
            for (int k = 0; k < m; ++k)
            {
                t[i + k]    = {t[prv].answer(), t[prv + 1].answer(), s[i + k]};
                parent[prv] = i + k;
                parent[prv + 1] = i + k;
                prv += 2;
            }
            i += m;
            m /= 2;
        }
    }
    ll   answer() const { return t.back().answer(); }
    void update(int pos, char c)
    {
        t[pos].cmp = c;
        while (parent[pos] != -1)
        {
            if (pos % 2 == 0)
                t[parent[pos]].cntl = t[pos].answer();
            else
                t[parent[pos]].cntr = t[pos].answer();

            pos = parent[pos];
        }
    }
};

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int k;
    cin >> k;
    string s;
    cin >> s;

    DataStructure ds(k, s);
    int           q;
    cin >> q;
    while (q--)
    {
        int  p;
        char c;
        cin >> p >> c, p--;
        ds.update(p, c);
        cout << ds.answer() << endl;
    }
    return 0;
}
