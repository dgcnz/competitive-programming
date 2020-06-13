#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

struct fenwick
{
    int n;
    vi  bit;

    fenwick() {}
    fenwick(int n_) : n(n_ + 1) { bit.assign(n_ + 1, 0); }
    void update(int i, int delta)
    {
        while (i < n)
        {
            bit[i] += delta;
            i += (i & -i);
        }
    }
    int prefix_sum(int r) const
    {
        int ans = 0;
        while (r > 0)
        {
            ans += bit[r];
            r -= (r & -r);
        }
        return ans;
    }
    int sum(int l, int r) const { return prefix_sum(r) - prefix_sum(l - 1); }
};

fenwick zcnt, ncnt;
vi      a;

void change(int i, int v)
{
    if ((a[i] == 0 and v == 0) or (a[i] < 0 and v < 0))
        return;
    if (a[i] == 0)
    {
        zcnt.update(i, -1);
        if (v < 0)
            ncnt.update(i, +1);
    }
    else if (a[i] < 0)
    {
        ncnt.update(i, -1);
        if (v == 0)
            zcnt.update(i, +1);
    }
    else // a[i] > 0
    {
        if (v == 0)
            zcnt.update(i, +1);
        else if (v < 0)
            ncnt.update(i, +1);
    }
}

char product(int l, int r)
{

    int zeros = zcnt.sum(l, r);

    if (zeros > 0)
        return '0';

    int neg = ncnt.sum(l, r);
    if (neg % 2 == 0)
        return '+';
    else
        return '-';
}

int main(void)
{
    int  n, k, l, r, j, x;
    char type;

    while (cin >> n >> k)
    {
        a = vi(n + 1);
        // zcnt: zero count, ncnt: negative num count
        zcnt = fenwick(n);
        ncnt = fenwick(n);

        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            if (a[i] == 0)
                zcnt.update(i, 1);
            else if (a[i] < 0)
                ncnt.update(i, 1);
        }

        while (k--)
        {
            cin >> type;
            if (type == 'C') // change (update)
            {
                cin >> j >> x; // j : index, x : value
                change(j, x);
                a[j] = x;
            }
            else // product (query)
            {
                cin >> l >> r;
                cout << product(l, r);
            }
        }
        cout << endl;
    }

    return 0;
}
