#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a;
string b;
int dp[2005][2005]; // dp[i][j]: a前i个，b前j个的编辑距离

int main() {
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    for (int i = 0; i <= a.length(); i++) dp[i][0] = i;
    for (int i = 0; i <= b.length(); i++) dp[0][i] = i;

    for (int i = 1; i <= a.length(); i++) { // 遍历a数组 前i项
        for (int j = 1; j <= b.length(); j++) { // 遍历b数组 前j项
            if (a[i] == b[j]) {
                // 如果相等，取前一项的值
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // 如果不相等，取前一项的较小值
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }
    cout << dp[a.length()][b.length()] << endl;

    return 0;
}

