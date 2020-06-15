#include <vector>

using namespace std;
using vi = vector<int>;

struct FenwickTree
{
    int n;
    vi  bit; // binary indexed tree

    FenwickTree(int n) : n(n) { bit.assign(n, 0); }

    FenwickTree(vi a) : FenwickTree(a.size())
    {
        for (int i = 0; i < n; i++)
            add(i, a[i]);
    }

    int sum(int r)
    {
        int ret = 0;
        while (r >= 0)
        {
            ret += bit[r];
            r = (r & (r + 1)) - 1;
        }
        return ret;
    }

    int sum(int l, int r) { return sum(r) - sum(l - 1); }

    void add(int i, int delta)
    {
        while (i < n)
        {
            bit[i] += delta;
            i = i | (i + 1);
        }
    }
};
