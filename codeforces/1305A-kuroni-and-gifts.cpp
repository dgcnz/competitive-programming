#include <algorithm>
#include <iostream>
#define NMAX 1010

using namespace std;

int n;

int a[NMAX];
int b[NMAX];

int main(void)
{

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        for (int i = 0; i < n; ++i)
            cin >> b[i];

        sort(a, a + n);
        sort(b, b + n);

        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";

        cout << endl;

        for (int i = 0; i < n; ++i)
            cout << b[i] << " ";
    }
    return 0;
}
