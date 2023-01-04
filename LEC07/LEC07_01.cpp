#include <iostream>
#include <vector>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    vector<int> arr;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    vector<int> dp(n);
    dp[0] = arr[0];
    for (int i = 1; i < n; ++i)
    {
        dp[i] = dp[i - 1] + arr[i];
    }

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0)
        {
            cout << dp[b] << endl;
        }
        else
        {
            cout << dp[b] - dp[a - 1] << endl;
        }
    }

    return 0;
}