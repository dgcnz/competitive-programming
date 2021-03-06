#include <iostream>

using namespace std;

const int NMAX = 1e5 + 11;

int  n, a[NMAX], b[NMAX];
bool prefplus[NMAX], prefminus[NMAX];

bool solve(void)
{
    for (int i = n - 1; i >= 0; --i)
    {
        if (b[i] > a[i] and not prefplus[i])
            return false;
        if (b[i] < a[i] and not prefminus[i])
            return false;
    }
    return true;
}

int main(void)
{

    int t;

    cin >> t;

    while (t--)
    {
        cin >> n;

        bool prefix_plus, prefix_minus;
        prefix_minus = prefix_plus = false;

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            prefplus[i]  = prefix_plus;
            prefminus[i] = prefix_minus;

            prefix_plus |= (a[i] == 1);
            prefix_minus |= (a[i] == -1);
        }

        for (int i = 0; i < n; ++i)
            cin >> b[i];

        cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}
