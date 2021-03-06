#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
using vll = vector<ll>;

int main(void)
{
    int n;
    cin >> n;

    vll p(n);
    for (auto &pi : p)
        cin >> pi;

    sort(p.begin(), p.end());

    int pivot = p[n / 2];
    cout << accumulate(p.begin(), p.end(), 0LL, [pivot](ll acc, ll x) {
        return acc + abs(pivot - x);
    }) << endl;

    return 0;
}
