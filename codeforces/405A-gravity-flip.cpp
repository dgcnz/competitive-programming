#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main(void)
{
    int n;
    vi  v;
    cin >> n;
    v.resize(n);
    for (auto &x : v)
        cin >> x;

    sort(v.begin(), v.end());
    for (auto x : v)
        cout << x << " ";

    return 0;
}
