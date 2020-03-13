/**
 * author: meow
 * 题目描述
 *       给定一个数组arr,长度为n。代表排有分数的气球。 每打爆一个气球都能获得分数，假设打爆气球的分数为X，获得分数的规则如下:
 *       1)如果被打爆气球的左边有没被打爆的气球，找到离被打爆气球最近的气球，假设分数为L:如果被打爆气球的右边有没被打爆的气球，找到离被打爆气球最近的气球，假设分数为R.获得分数为L*X*R
 *       2)如果被打爆的气球的左边有没被打爆的气球，找到离被打爆气球最近的气球，假设分数为L:如果被打爆气球的右边所有气球都已经被打爆，获得分数为L*X。
 *       3)如果被打爆气球的左边所有的气球都已经被打爆:如果被打爆气球的右边有没被打爆的气球，找到离被打爆气球最近的气球。获得分数为X*R.
 *       4)如果被打爆气球的左边和右边所有的气球都已经被打爆。获得分数为X。
 *       目标是打爆所有气球，获得每次打爆的分数。通过选择打爆气球的顺序，可以得到不同的总分，请返回能获得的最大分数。
 * 输入描述:
 * 输出包括两行，第一行包括一个整数n（0<=n<=500），第二行包括n个整数，代表数组arr （1<=arr[i]<=100）。
 * 输出描述:
 * 输出包括一个整数，代表可能获得的最大分数。
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

int main(){

    // freopen("input.txt","r",stdin); 
    int n;
    scanf("%d", &n);
    int arr[n+2];
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    arr[0] = 1;
    arr[n+1] = 1;

    vector<vector<int> > dp(n+2, vector<int>(n+2, 0));

    for(int i = 1; i <= n; i++){
        dp[i][i] = arr[i-1] * arr[i] * arr[i+1];
    }

    for(int len = 1; len <= n-1; len++){ //dp 从小区间到大区间搜索，否则会出现子区间的分数为0
        for(int l = 1; l <= n-len; l++){
            int r = l + len;
            for(int k = l; k <= r; k++){
                // k 是区间内最后一个被打掉的，邻居是 l-1, r+1
                dp[l][r] = max(dp[l][r], dp[l][k-1] + dp[k+1][r] + arr[l-1] * arr[k] * arr[r+1]);
            }


        }
    }

    printf("%d\n", dp[1][n]);

    return EXIT_SUCCESS;
}