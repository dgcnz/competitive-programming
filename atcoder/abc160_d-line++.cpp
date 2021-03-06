#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main(void)
{
    int n, x, y;
    vi  cnt;

    cin >> n >> x >> y;
    cnt.resize(n, 0);

    for (int u = 1; u < n; ++u)
    {
        for (int v = u + 1; v <= n; ++v)
        {
            int dist = min({v - u,
                            abs(x - u) + 1 + abs(y - v),
                            abs(x - v) + 1 + abs(y - u)});
            cnt[dist]++;
        }
    }
    for (int k = 1; k < n; ++k)
        cout << cnt[k] << endl;

    return 0;
}
