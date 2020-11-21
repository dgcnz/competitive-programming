---
layout: post
title: 12086 Potentiometers
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using vi = vector<int>;
const int NMAX = 2e5 + 11;
struct fenwick
{
    int n;
    vi bit;
    fenwick() {}
    fenwick(int n_) : n(n_ + 1) { bit.assign(n_ + 1, 0); };
    void update(int i, int delta)
    {
        while (i < n)
        {
            bit[i] += delta;
            i += i & -i;
        }
    }
    int psum(int r)
    {
        int ans = 0;
        while (r > 0)
        {
            ans += bit[r];
            r -= r & -r;
        }
        return ans;
    }
    int sum(int l, int r) { return psum(r) - psum(l - 1); }
};
int n, potmeter[NMAX];
fenwick t;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y, r, test = 1;
    char type;
    while (cin >> n)
    {
        if (n == 0)
            break;
        else if (test != 1)
            cout << endl;
        t = fenwick(n);
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            potmeter[i] = x;
            t.update(i, x);
        }
        cout << "Case " << test << ":" << endl;
        while (cin >> type and type != 'E')
        {
            if (type == 'S')
            {
                cin >> x >> r;
                t.update(x, r - potmeter[x]);
                potmeter[x] = r;
            }
            else if (type == 'M')
            {
                cin >> x >> y;
                cout << t.sum(x, y) << endl;
            }
        }
        cin.ignore(), cin.ignore();
        test += 1;
    }
    return 0;
}

```
