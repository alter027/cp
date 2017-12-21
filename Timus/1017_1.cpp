#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
ll dp[501][501];
ll solve(int sum, int mx) {//由未知的k个不同的小于mx数来组成sum，事实上，我们并不需要知道k是多少
    if (sum == 0) return 1;
    if (dp[sum][mx] != -1) return dp[sum][mx];
    ll ans = 0;
    for (int i = min(mx - 1, sum); i >= 1; --i) {//sum - i 出现负数的情况
        ans += solve(sum - i, i);
    }
    return dp[sum][mx] = ans;
}
int main() {
    ll N;
    cin >> N;
    memset(dp, -1, sizeof dp);
    ll ans = 0;
    for (int i = N - 1; i >= 1; --i) {//i不能从N开始枚举，为了避免只有一个台阶的情况
        ans += solve(N - i, i);
    }
    cout << ans << endl;
    return 0;
}