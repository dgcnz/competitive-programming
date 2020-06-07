#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;
using pii = pair<int, int>;

const int NMAX = 1e3 + 11;

pii a[NMAX];

int main(void)
{
    int n, ai;

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> ai;
        a[i - 1] = {ai, i};
    }
    sort(a, a + n);

    if (a[0].first == a[n - 1].first)
        cout << "Exemplary pages." << endl;
    else
    {
        int diff = a[n - 1].first - a[0].first;
        if (diff % 2 == 0)
        {
            bool recoverable = false;
            int  normal      = a[0].first + diff / 2;

            if (n == 2)
                recoverable = true;
            else if (n == 3 and a[1].first == normal)
                recoverable = true;
            else if (n >= 4 and a[1].first == normal and
                     a[n - 2].first == normal)
                recoverable = true;

            if (recoverable)
                cout << diff / 2 << " ml. from cup #" << a[0].second
                     << " to cup #" << a[n - 1].second << "." << endl;
            else
                cout << "Unrecoverable configuration." << endl;
        }
        else
            cout << "Unrecoverable configuration." << endl;
    }
    return 0;
}
