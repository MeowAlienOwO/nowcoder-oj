/**
 * author: meow
 * 题目描述
 * 给定数组arr，设数组长度为n，arr中所有的值都为正整数且不重复。每个值代表一种面值的货币，每种面值的货币可以使用任意张，再给定一个整数aim，代表要找的钱数，求换钱的方法数有多少种。由于方法的种数比较大，所以要求输出对10^9+7进行取模后的答案。
 * 输入描述:
 * 输出包括两行，第一行包括两个整数n(0≤n≤1000)和aim(0≤aim≤20000)。第二行包含n个整数，表示arr数组)(1≤arr_i ≤1e9)。
 * 输出描述:
 * 输出一个整数，表示换钱的方法数对10^9+7取模后的答案。
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
const int MOD = 1e9+7;

int main(){

    // freopen("input.txt","r",stdin); 
    int n, aim;
    scanf("%d%d", &n, &aim);
    int coin[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &coin[i]);
    }

    vector<int> dp(aim+1, 0);
    dp[0] = 1;

    for(int j = 0; j < n; j++){ // 只用[0,j]种货币的情况下
        for(int i = coin[j]; i <= aim; i++){
            dp[i] = (dp[i]+dp[i - coin[j]]) % MOD;
        }
    }

    printf("%d\n", dp[aim]);


    return EXIT_SUCCESS;
}