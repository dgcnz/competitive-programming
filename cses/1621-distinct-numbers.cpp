#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

int main(void)
{
    int n;
    cin >> n;

    vi x(n);
    for (auto &xi : x)
        cin >> xi;

    sort(x.begin(), x.end());
    cout << distance(x.begin(), unique(x.begin(), x.end())) << endl;

    return 0;
}
