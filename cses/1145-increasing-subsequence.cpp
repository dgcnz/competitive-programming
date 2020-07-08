#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main(void)
{
    int n, x;
    vi  dp;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> x;

        // *it can only be >= than x, therefore, replacing it is always optimal
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it != dp.end())
            *it = x;
        else
            dp.push_back(x);
    }

    cout << dp.size() << endl;

    return 0;
}
