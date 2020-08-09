#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using ll = long long;

int main(void)
{
    int n, m, ai;
    cin >> n >> m;

    multiset<int> a;
    for (int i = 0; i < n; ++i)
        cin >> ai, a.insert(ai);

    vector<ii> queries;
    queries.resize(m);
    for (auto &[ci, bi] : queries)
        cin >> bi >> ci;

    sort(queries.begin(), queries.end(), greater<ii>());

    for (auto [ci, bi] : queries)
    {
        if (*a.begin() >= ci)
            break;

        while (bi--)
        {
            auto it = a.begin();
            if (*it >= ci)
                break;
            a.erase(it);
            a.insert(ci);
        }
    }

    cout << accumulate(a.begin(), a.end(), (ll)0);

    return 0;
}
