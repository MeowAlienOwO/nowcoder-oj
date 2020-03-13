/**
 * author: meow
 * 题目描述
 * 假设有排成一行的N个位置，记为1~N，开始时机器人在M位置，机器人可以往左或者往右走，如果机器人在1位置，那么下一步机器人只能走到2位置，如果机器人在N位置，那么下一步机器人只能走到N-1位置。规定机器人只能走k步，最终能来到P位置的方法有多少种。由于方案数可能比较大，所以答案需要对1e9+7取模。
 * 输入描述:
 * 输出包括一行四个正整数N（2<=N<=5000）、M(1<=M<=N)、K(1<=K<=5000)、P(1<=P<=N)。
 * 输出描述:
 * 输出一个整数，代表最终走到P的方法数对10^9+7取模后的值。
 * 
 * 思路： DP
 * 对于第 k 步， 每一个点j有：
 * j == 1: 只能从 j = 2 走过来， dp[k-1][2]
 * j == n: 只能从 j = n-1 走过来，dp[k-1][n-1]
 * 其他位置：能从左右两端走过来，在j-1, j+1 各只有一种走法, dp[k-1][j-1] + dp[k-1][j+1]
 */
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1000000000;
const int maxn = 100;
const int MOD  = 1e9+7;


int main(){

    // freopen("input.txt","r",stdin); 
    int n, m, k, p;
    scanf("%d %d %d %d", &n, &m, &k, &p);

    vector<vector<int> > dp(k+1, vector<int>(n+2, 0));
    dp[0][m] = 1;

    for(int i = 1; i <= k; i++){
        for(int j = 1; j <=n; j++){
            if(j == 1){
                dp[i][j] = dp[i-1][2] % MOD;
            } else if(j == n){
                dp[i][j] = dp[i-1][n-1] % MOD;
            } else {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
            }
        }
    }

    printf("%d\n", dp[k][p]);

    return EXIT_SUCCESS;
}