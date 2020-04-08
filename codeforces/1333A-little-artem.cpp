#include <iostream>

using namespace std;

int main(void)
{
    int t, n, m;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        bool black = true;

        for (int row = 0; row < n; ++row)
        {
            for (int col = 0; col < m; ++col)
            {
                if (row == 0 and col == 1 and (n * m) % 2 == 0)
                    cout << (black ? "W" : "B");
                else
                    cout << (black ? "B" : "W");

                black = !black;
            }
            cout << endl;
        }
    }

    return 0;
}
