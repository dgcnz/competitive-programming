#include <iostream>
#include <map>
#include <set>
#include <utility>

using namespace std;

// IDEA:
// - keep track of current price given stock on a map
// - use ordered set to maintain order
// - op 1 is insert
// - op 2 is replace = remove and insert
// - op 3 is just consult and remove

int main(void)
{
    int                    op, n, price;
    string                 stock, s;
    set<pair<int, string>> stocks;
    map<string, int>       stockprice;

    cin >> n;

    for (int day = 1; day <= n; ++day)
    {
        cin >> op;

        if (op == 1)
        {
            cin >> stock >> price;
            stockprice[stock] = price;
            stocks.insert({price, stock});
        }
        else if (op == 2)
        {
            cin >> stock >> price;
            stocks.erase({stockprice[stock], stock});
            stocks.insert({price, stock});
            stockprice[stock] = price;
        }
        else if (op == 3)
        {
            cin >> s;
            auto [price, stock] = *stocks.begin();
            cout << stock << " " << day << endl;
            stocks.erase(stocks.begin());
        }
    }

    return 0;
}
