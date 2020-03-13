/**
 * author: meow
 * 题目描述
 * 给定数组 arr 和整数 num，共返回有多少个子数组满足如下情况：
 * max(arr[i...j] - min(arr[i...j]) <= num
 * max(arr[i...j])表示子数组arr[i...j]中的最大值，min[arr[i...j])表示子数组arr[i...j]中的最小值。
 * 
 * 输入描述:
 * 第一行输入两个数 n 和 num，其中 n 表示数组 arr 的长度
 * 第二行输入n个整数X_i​，表示数组arr中的每个元素
 * 输出描述:
 * 输出给定数组中满足条件的子数组个数
 * 
 * 思路：
 * 基本型 n^2：l, r两个指针分别遍历 n，有两个问题：1.遍历所有数组需要n^2 2.维护局部最大最小值终归O(n)
 * 优化1： 两个指针指向头尾，分别走 n，则复杂度 2n
 * 优化2： 基于如上两个指针，将子数组看做变长的滑动窗口，维护max, min队列从而实现访问max,min值的O(1)
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
    int n, num;
    scanf("%d %d", &n, &num);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int l = 0, r = 0;
    int res = 0;
    deque<int> maxq;
    deque<int> minq;
    while(l < n){ // l作为子数组的左边界
        while(r < n){ // 先移动r
            while(!maxq.empty() && arr[maxq.back()] <= arr[r]){ // 此处等于号意义?没有过不了
                maxq.pop_back();
            } // 单调最大值队列，右边删除所有小于r指针位置的值
              // 1. 如果输入值为最优，则整个队列删除后入队
              // 2. 如果输入值次优，将被留在队列中直到左边或者右边删除
              // 最大值队列单调递减
            maxq.push_back(r);

            while(!minq.empty() && arr[minq.back()] >= arr[r]){
                minq.pop_back();
            } // 同理 单调最小值队列，单调递增
            minq.push_back(r);

            // 如果上一步不大于num，这一步要么最大值入列要么最小值入列导致差超过num
            // [l,r]范围内所有的子数组都有 max-min <= num，即有r - l个子数组符合条件(看做向右搜索)
            if(arr[maxq.front()] - arr[minq.front()] > num){
                break;
            }
            r++;
        }
        res += r - l;
        // 使用队列的好处：同时维护位置信息跟大小信息以及数据的顺序，可以看做是单一变量的min,max的高级版
        // O(1)即可维护窗口范围
        if(l == maxq.front()){
            maxq.pop_front();
        }
        if(l == minq.front()){
            minq.pop_front();
        }
        l++;
    }
    printf("%d\n", res);

    return EXIT_SUCCESS;
}