#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

const int NMAX = 1e3 + 11;

ll n, d, x[NMAX];

bool simulate(ll start_time)
{
    ll cur_time = start_time;
    for (int i = 0; i < n; ++i)
    {
        cur_time = x[i] * ceil((cur_time * 1.0) / x[i]);
        if (cur_time > d)
            return false;
    }

    return true;
}

ll bs(ll low, ll high)
{
    auto p = [&](ll start) { return not simulate(start); };
    while (low < high)
    {
        ll mid = low + (high - low + 1) / 2;

        if (p(mid))
            high = mid - 1;
        else
            low = mid;
    }
    if (p(low))
        return 0;
    return low;
}

int main(void)
{
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc)
    {
        cin >> n >> d;
        for (int i = 0; i < n; ++i)
            cin >> x[i];
        cout << "Case #" << tc << ": " << bs(1, d) << endl;
    }
}
