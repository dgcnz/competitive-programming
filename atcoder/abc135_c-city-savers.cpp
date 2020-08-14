#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;

int main(void)
{
    int n;
    ll  cur_killed, total_killed;
    vi  a, b;
    cin >> n;
    a.resize(n + 1), b.resize(n);

    for (auto &ai : a)
        cin >> ai;
    for (auto &bi : b)
        cin >> bi;

    total_killed = 0;
    for (int i = 0; i < n; ++i)
    {
        cur_killed = min(b[i], a[i] + a[i + 1]);
        total_killed += cur_killed;
        a[i + 1] -= max(0LL, cur_killed - a[i]);
    }

    cout << total_killed << endl;

    return 0;
}
