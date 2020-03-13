/**
 * author: meow
 * 题目描述
 * 给定数组arr，arr中所有的值都为正整数且不重复。每个值代表一种面值的货币，每种面值的货币可以使用任意张，再给定一个aim，代表要找的钱数，求组成aim的最少货币数。
 * 输入描述:
 * 输入包括两行，第一行两个整数n（0<=n<=1000）代表数组长度和aim（0<=aim<=5000），第二行n个不重复的正整数，代表(1≤arr_i ≤10^9)。
 * 输出描述:
 * 输出一个整数，表示组成aim的最小货币数，无解时输出-1.
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

    int n, aim;
    scanf("%d %d", &n, &aim);
    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int dp[aim+1];

    for(int i = 0; i < aim+1; i++){
        dp[i] = -1;
    }
    dp[0] = 0;

    for(int i = 1; i < aim+1; i++){
        for(int j = 0; j < n; j++){
            if(i-arr[j] >= 0 && dp[i-arr[j]] >= 0){
                if(dp[i] < 0){
                    dp[i] = INF;
                }
                dp[i] = min(dp[i], dp[i-arr[j]]+1);
            } 
        }
    }

    printf("%d\n", dp[aim]);
    return EXIT_SUCCESS;
}