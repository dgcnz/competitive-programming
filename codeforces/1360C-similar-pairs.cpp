#include <algorithm>
#include <iostream>

using namespace std;

const int NMAX = 50;

int n, a[NMAX];

bool solve(void)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] % 2 == 0)
            cnt += 1;

    if (cnt % 2 == 0)
        return true;

    sort(a, a + n);

    for (int i = 1; i < n; ++i)
        if (a[i] - a[i - 1] == 1)
            return true;
    return false;
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        cout << (solve() ? "YES" : "NO") << endl;
    }
}
