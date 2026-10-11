#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 305
#define ui unsigned int

ui raw_w[MAX_N]; // raw_w[i]: 第i个物品的重量(原始)
ui dp_w[MAX_N]; // dp_w[i]: 前i个物品的重量和
ui dp_cost[MAX_N][MAX_N]; // dp_cost[i][j]: i~j的重量和ui
ui n;

int main() {
    cin >> n;

    for (ui i = 1; i <= n; i++) {
        cin >> raw_w[i];
    }
    memset(dp_cost, 0x3f, sizeof(dp_cost)); // 初始化为 极大值
    // dp_w[i] : 前i个物品的重量和
    for (ui i = 1; i <= n; ++i) {
        dp_w[i] = dp_w[i-1] + raw_w[i];
        dp_cost[i][i] = 0;  // 单个元素代价为0
    }

    // dp_cost[i][j] : i~j的重量和
    for (ui len = 2; len <= n; len++) { // 先枚举 短的区间长度
        for (ui l = 1; l <= n-len+1; l++) { // 枚举 左端点
            ui r = l+len-1; // 计算 右端点
            for (ui k = l; k < r; k++) { // 枚举 分割点
                // 左子区间 dp_cost[l][k] , 右子区间 dp_cost[k+1][r]
                dp_cost[l][r] = min(
                    dp_cost[l][r], 
                    dp_cost[l][k] + dp_cost[k+1][r] + 
                        min( dp_w[k]-dp_w[l-1], dp_w[r]-dp_w[k]) );
                        // dp_w[k]-dp_w[l-1] + dp_w[r]-dp_w[k]
            }
        }
    }

    cout << dp_cost[1][n] << endl;

    return 0;
}

