#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main(void)
{
    int t, n;
    vi  a;
    cin >> t;
    while (t--)
    {
        cin >> n;
        a.resize(n);
        for (auto &ai : a)
            cin >> ai;

        int  x  = a[0] + a[1];
        auto it = lower_bound(a.begin(), a.end(), x);

        if (it == a.end())
            cout << -1 << endl;
        else
        {
            cout << 1 << " " << 2 << " " << distance(a.begin(), it) + 1 << endl;
        }
    }

    return 0;
}
