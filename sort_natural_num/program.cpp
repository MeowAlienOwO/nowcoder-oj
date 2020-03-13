/**
 * author: meow
 * 
 *题目描述
 * 给定一个长度为N的整形数组arr，其中有N个互不相等的自然数1-N。请实现arr的排序，但是不要把下标0 \sim N-10∼N−1位置上的数通过直接赋值的方式替换成1 \sim N1∼N
 * [要求]
 * 时间复杂度为O(n)，空间复杂度为O(1)
 * 
 * 输入描述:
 * 第一行有一个整数N。表示数组长度
 * 接下来一行有N个互不相等的自然数1-N。
 * 输出描述:
 * 输出N个整数表示排序后的结果 
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
    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i <= n; i++){
        while(arr[i] != i){ // 一次不够，要换到对为止
            swap(arr[i], arr[arr[i]]);
        }
    }

    for(int i = 1; i <= n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");



    return EXIT_SUCCESS;
}