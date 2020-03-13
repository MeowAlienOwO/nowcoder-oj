/**
 * author: meow
 * 题目描述
 * 给定一个数组arr，该数组无序，但每个值均为正数，再给定一个正数k。求arr的所有子数组中所有元素相加和为k的最长子数组的长度
 * 例如，arr = [1, 2, 1, 1, 1], k = 3
 * 累加和为3的最长子数组为[1, 1, 1]，所以结果返回3
 * [要求]
 * 时间复杂度为O(n)，空间复杂度为O(1)
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

int main(){

    int n, k;
    scanf("%d %d\n", &n, &k);
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> prefix_arr(n+1);
    for(int i = 1; i < n+1; i++){
        prefix_arr[i] = prefix_arr[i-1] + arr[i-1];
    }

    int i = 0;
    int j = 1; // i < j
    int len = 1;
    while(i < j && j < n+1){
        if(j - i <= len){
            j++;
        } else{
            int sum = prefix_arr[j] - prefix_arr[i];
            if(sum == k){
                len = max(len, j - i);
                j++;
            } else if (sum < k){
                j++;
            } else {
                i++;
            }

        }
    }

    printf("%d\n", len);

    return EXIT_SUCCESS;
}