#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a, b;
int dp[1005][1005];
int n, m;

int main() {
    cin >> n;
    m = n;
    cin >> a;
    string b(a.rbegin(), a.rend());
    a = " " + a;
    b = " " + b;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
