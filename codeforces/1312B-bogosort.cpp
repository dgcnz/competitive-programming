#include <algorithm>
#include <iostream>

using namespace std;

const int NMAX = 100 + 11;

int n, a[NMAX];

int main(void)
{

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a, a + n, greater<int>());

        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";

        cout << endl;
    }
    return 0;
}
