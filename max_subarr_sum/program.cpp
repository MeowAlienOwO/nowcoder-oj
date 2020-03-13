/**
 * author: meow
 * 题目描述
 * 给定一个数组arr，返回子数组的最大累加和
 * 例如，arr = [1, -2, 3, 5, -2, 6, -1]，所有子数组中，[3, 5, -2, 6]可以累加出最大的和12，所以返回12.
 * [要求]
 * 时间复杂度为O(n)，空间复杂度为O(1)
 * 
 * 输入描述:
 * 第一行一个整数N。表示数组长度
 * 接下来一行N个整数表示数组内的元素
 * 输出描述:
 * 输出一个整数表示答案
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
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int s = 0;
    int res = arr[0];
    for(int i = 0; i < n; i++){
        s += arr[i];
        res = max(res, s);
        if(s < 0){
            s = 0;
        }
    }

    printf("%d\n", res);


    return EXIT_SUCCESS;
}