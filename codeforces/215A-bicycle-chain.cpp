#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main(void)
{
    int n, m;
    vi  a, b;
    cin >> n;

    a.resize(n);
    for (auto &ai : a)
        cin >> ai;

    cin >> m;
    b.resize(m);
    for (auto &bi : b)
        cin >> bi;

    reverse(b.begin(), b.end());
    multiset<int, greater<int>> ms;

    for (auto bi : b)
    {
        for (auto ai : a)
        {
            if (bi % ai == 0)
            {
                ms.insert(bi / ai);
            }
        }
    }

    cout << ms.count(*ms.begin()) << endl;

    return 0;
}
