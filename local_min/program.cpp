/**
 * author: meow
 * 题目描述
 * 定义局部最小的概念。arr长度为1时，arr[0]是局部最小。arr的长度为N(N>1)时，如果arr[0]<arr[1]，那么arr[0]是局部最小；如果arr[N-1]<arr[N-2]，那么arr[N-1]是局部最小；如果0<i<N-1，既有arr[i]<arr[i-1]，又有arr[i]<arr[i+1]，那么arr[i]是局部最小。
 * 给定无序数组arr，已知arr中任意两个相邻的数不相等。写一个函数，只需返回arr中任意一个局部最小出现的位置即可
 * [要求]
 * 时间复杂度为O(\log n)，空间复杂度为O(1)
 * 输入描述:
 * 第一行有一个整数N。标书数组长度
 * 接下来一行，每行N个整数表示数组中的数
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
    if(n == 1){
        cout << 0 << endl;
        return 0;
    } else {
        if(arr[n-1] < arr[n-2]){
            cout << n-1 <<endl;
            return 0;
        } 
        if(arr[0] < arr[1]){
            cout << 0 << endl;
        }
    }

    int l = 0, r = n-1;
    while(l <= r){
        int mid = int((l + r) / 2);
        if(arr[mid-1] > arr[mid] && arr[mid+1] > arr[mid]){
            cout << mid << endl;
            return 0;
        } else if(arr[mid-1] < arr[mid]){
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    return EXIT_SUCCESS;
}