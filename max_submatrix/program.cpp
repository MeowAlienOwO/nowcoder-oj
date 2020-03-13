/**
 * 题目描述
 * 给定一个整型矩阵 map，其中的值只有 0 和 1 两种，求其中全是 1 的所有矩形区域中，最大的矩形区域里 1 的数量。
 * 输入描述:
 * 第一行输入两个整数 n 和 m，代表 n*m 的矩阵
 * 接下来输入一个 n*m 的矩阵
 * 输出描述:
 * 输出其中全是1的所有矩形区域中，最大的矩形区域里 1 的数量。
 * author: meow
 * 
 * 思路：直方图，每一行看做一个单位高度为1的直方图
 * 0 1 0 1 = _|-|_|-|
 * 用一个单调递增栈来描述直方图横向大小。
 * 规则：
 * 1. 当s为空或者 height[j] > height[s.top()] 入栈
 * 2. 当s不为空且 height[j] <= height[s.top()] 出栈，此时j是右边第一个小于 s.top()的，栈中第二个元素(k)是左边第一个小于s.top的
 * 面积计算： area = (j - k + 1) * height[s.top()]
 * 极限情况: k不存在：area = 1 * height[s.top()]
 * 遍历完，s非空
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
    int n, m;
    scanf("%d %d", &n, &m);
    int** arr = (int**)malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++){
        arr[i] = (int*)malloc(m*sizeof(int));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int res = 0;
    int* heights = (int*) malloc(m * sizeof(int));
    memset(heights, 0, m * sizeof(int));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            heights[j] = arr[i][j] == 1? heights[j]+1 : 0;
        }

        stack<int> s;
        for(int j = 0; j < m; j++){
            if(s.empty() || heights[j] > heights[s.top()]){
                s.push(j);
            } else {
                while(!s.empty() && heights[j] <= heights[s.top()]){
                    int top = s.top();
                    s.pop();
                    int area = (s.empty()? j : (j - s.top() - 1)) * heights[top];
                    res = max(area, res);
                }
            }
            s.push(j);

        }
    }

    printf("%d\n", res);

    return EXIT_SUCCESS;
}