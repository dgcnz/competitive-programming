#include <bits/stdc++.h>
#define sz(c) (int)c.size()
#define all(c) c.begin(), c.end()

using namespace std;
using vi = vector<int>;

int main(void)
{
    int        n, m;
    vi         f;
    vector<vi> bs;
    cin >> n >> m;

    f.resize(n, 0), bs.resize(n);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b, --a, --b;
        bs[a].push_back(b);
    }

    auto dist = [n](int l, int r) -> int { return (r - l + n) % n; };
    for (int i = 0; i < n; ++i)
    {
        if (sz(bs[i]) > 0)
        {
            int closest = *min_element(all(bs[i]), [i, dist](int a, int b) {
                return dist(i, a) < dist(i, b);
            });
            f[i]        = (sz(bs[i]) - 1) * n + dist(i, closest);
        }
    }

    for (int start = 0; start < n; ++start)
    {
        int ans = 0;
        for (int delta = 0; delta < n; ++delta)
        {
            auto fi = f[(start + delta) % n];
            ans     = max(ans, fi + (fi > 0) * delta);
        }
        cout << ans << " ";
    }

    return 0;
}
