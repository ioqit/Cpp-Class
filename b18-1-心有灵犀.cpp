#include <iostream>
#include <algorithm>
using namespace std;

int a[1005];
int b[1005];
int dp[1005][1005]; // dp[i][j]: a前i个，b前j个的LCS
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    for (int i = 1; i <= n; i++) { // 遍历a数组 前i项
        for (int j = 1; j <= n; j++) { // 遍历b数组 前j项
            if (a[i] == b[j]) {
                // 如果相等，取前一项的值加1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // 如果不相等，取前一项的较大值
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][n] << endl;

    return 0;
}

