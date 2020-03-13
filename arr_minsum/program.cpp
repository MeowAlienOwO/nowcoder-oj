/**
 * author: meow
 * 
 * 题目描述
 * 数组小和的定义如下：
 * 例如，数组s = [1, 3, 5, 2, 4, 6]，在s[0]的左边小于或等于s[0]的数的和为0；在s[1]的左边小于或等于s[1]的数的和为1；在s[2]的左边小于或等于s[2]的数的和为1+3=4；在s[3]的左边小于或等于s[3]的数的和为1；
 * 在s[4]的左边小于或等于s[4]的数的和为1+3+2=6；在s[5]的左边小于或等于s[5]的数的和为1+3+5+2+4=15。所以s的小和为0+1+4+1+6+15=27
 * 给定一个数组s，实现函数返回s的小和
 * [要求]
 * 时间复杂度为O(nlogn)，空间复杂度为O(n)
 * 输入描述:
 * 第一行有一个整数N。表示数组长度
 * 接下来一行N个整数表示数组内的数
 * 输出描述:
 * 一个整数表示答案
 * 
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


ll merge(vector<int>& arr, int left, int mid, int right){
    vector<int> helper(right - left + 1, 0);

    ll res = 0;
    int i = 0;
    int l = left;
    int r = mid+1;
    while(l <= mid && r <= right){
        // 加和：左边的指针头小于右边的指针头时，必然小于右边的 [r, right]的所有数
        res += arr[l] <= arr[r]? arr[l] * (right - r +1) : 0;
        helper[i++] = arr[l] <= arr[r] ? arr[l++] : arr[r++];
    }
    // 一个数组写入完毕，处理剩余的序列
    // 理论上顺序无所谓
    while(r <= right){
        helper[i++] = arr[r++];
    }
    while(l <= mid){
        helper[i++] = arr[l++];
    }

    for(int j = left; j <= right; j++){
        arr[j] = helper[j - left];
    }

    return res;
}

ll sort_and_calc(vector<int>& arr, int left, int right){
    if(left >= right) return 0;
    else {
        int mid = int((left + right) / 2);
        return sort_and_calc(arr, left, mid) + sort_and_calc(arr, mid+1, right) + merge(arr, left, mid, right);
    }


}

int main(){

    // freopen("input.txt","r",stdin); 
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("%lld\n", sort_and_calc(arr, 0, n-1));
    return EXIT_SUCCESS;
}