/**
 * author: meow
 * 
 * 题目描述
 * 有一个整型数组arr和一个大小为w的窗口从数组的最左边滑到最右边，窗口每次向右边滑一个位置，求每一种窗口状态下的最大值。（如果数组长度为n，窗口大小为w，则一共产生n-w+1个窗口的最大值）
 * 输入描述:
 * 第一行输入n和w，分别代表数组长度和窗口大小
 * 第二行输入n个整数X_i ，表示数组中的各个元素
 * 输出描述:
 * 输出一个长度为n-w+1的数组res，res[i]表示每一种窗口状态下的最大值
 * 
 * 思路：
 * 1. 维护一个指针指向local maximum
 * 2. 窗口每移动一格，判断：
 *    a) 读入的新数字是否大于local minimum, 是则替换
 *    b) 移除的位置是否超过local minimum，是则重新搜索
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

typedef struct MaxVal {
    int val;
    int pos;
} MaxVal;

MaxVal search_max(int* arr, int l, int r){
    MaxVal m;
    m.val = arr[l];
    m.pos = 0;
    for(int i = l; i < r; i++){
        if(arr[i] > m.val){
            m.val = arr[i];
            m.pos = i;
        }
    }
    return m;
}

int main(){

    // freopen("input.txt","r",stdin); 
    int n, w;
    scanf("%d %d", &n, &w);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }


    MaxVal m;
    m.val = -INF;
    m.pos = -1;

    for(int i = 0; i < n-w+1; i++){

        if(i > m.pos){
            m = search_max(arr, i, i + w);
        } else {
            if(m.val <= arr[i+w-1]){
                m.val = arr[i+w-1];
                m.pos = i+w-1;
            }
        }
        printf("%d ", m.val);
    }

    printf("\n");

    return EXIT_SUCCESS;
}