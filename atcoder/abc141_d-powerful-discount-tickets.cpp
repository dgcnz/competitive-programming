#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void)
{
    int                         n, m, ai;
    multiset<int, greater<int>> s;

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> ai, s.insert(ai);

    while (m--)
    {
        int biggest = *s.begin();
        if (biggest == 0)
            break;
        s.erase(s.begin());
        s.insert(biggest / 2);
    }

    cout << accumulate(s.begin(), s.end(), (ll)0) << endl;

    return 0;
}
