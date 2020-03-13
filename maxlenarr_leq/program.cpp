/**
 * author: meow
 * 给定一个无序数组arr，其中元素可正、可负、可0。给定一个整数k，求arr所有的子数组中累加和小于或等于k的最长子数组长度
 * 例如：arr = [3, -2, -4, 0, 6], k = -2. 相加和小于等于-2的最长子数组为{3, -2, -4, 0}，所以结果返回4
 * [要求]
 * 时间复杂度为O(n)，空间复杂度为O(n)
 * 输入描述:
 * 第一行两个整数N, k。N表示数组长度，k的定义已在题目描述中给出
 * 第二行N个整数表示数组内的数
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

int bsearch(int* arr, int end, int target){
    int i = 0;
    int j = end;
    int ans = -1; // if no satisfying in 0..end
    while(i <= j){ // equal should not ignore
        int mid = int((i + j) / 2);
        if(arr[mid] < target){
            i = mid + 1;
        } else {
            j = mid - 1;
            ans = mid;
        }
    }
    return ans;
}

int main(){

    // freopen("input.txt","r",stdin); 
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int maxsum[n+1];
    int prefix[n+1];
    prefix[0] = 0;
    maxsum[0] = 0;

    int maxlen = 0;

    for(int i = 0; i < n; i++){
        prefix[i+1] = prefix[i] + arr[i];
        maxsum[i+1] = max(maxsum[i], prefix[i+1]); // follow prefix 
    }

    for(int i = 0; i < n; i++){
        int j = bsearch(maxsum, i+1, prefix[i+1] - k);
        int len = j < 0 ? 0 : i - j + 1;
        maxlen = max(len, maxlen);
    }

    printf("%d\n", maxlen);

    return EXIT_SUCCESS;
}