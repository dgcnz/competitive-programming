#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
using ii  = pair<int, ll>;
using vii = vector<ii>;

inline ll iceil(ll a, ll b) { return (a + b - 1) / b; }

int main(void)
{
    int n;
    vii a;

    cin >> n;

    a.resize(n);
    for (auto &[k, c] : a)
        cin >> k >> c;

    sort(a.begin(), a.end());

    for (int i = 1; i < n; ++i)
    {
        int dk = a[i].first - a[i - 1].first;
        if (dk < 15)
            a[i].second =
                max(a[i].second, iceil(a[i - 1].second, (1LL << (2 * dk))));
    }

    do
    {
        auto [k, c] = a.back();
        a.emplace_back(k + 1, iceil(c, (1LL << 2)));
    } while (a.back().second != 1);

    cout << a.back().first << endl;

    return 0;
}
