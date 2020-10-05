#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;
using ii  = pair<int, int>;
using vi  = vector<int>;
using vii = vector<ii>;

int main(void)
{
    int n, m;
    cin >> n >> m;

    set<ii> h;

    for (int i = 0; i < n; ++i)
    {
        int hi;
        cin >> hi;
        h.emplace(hi, i);
    }

    for (int i = 0; i < m; ++i)
    {
        int ti;
        cin >> ti;
        auto it = h.upper_bound({ti, 1e9});
        if (it != h.begin())
        {
            --it;
            cout << it->first << endl;
            h.erase(it);
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
