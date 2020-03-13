/**
 * author: meow
 * 给定一个长度不小于2的数组arr，实现一个函数调整arr，要么让所有的偶数下标都是偶数，要么让所有的奇数下标都是奇数
 * 注意：1、数组下标从0开始！
 * 2、本题有special judge，你可以输出任意一组合法解！同时可以证明解一定存在
 * [要求]
 * 时间复杂度为O(n)，额外空间复杂度为O(1)
 * 
 * 输入描述:
 * 第一行一个整数N。表示数组长度
 * 接下来一行N个整数表示数组内的数
 * 输出描述:
 * 输出N个整数。表示调整后的数组
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
    // int odd_count = 0, even_count = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        // if(arr[i] % 2) odd_count++; else even_count++;
    }

    int odd = 1, even = 0;

    while(true){
        while(arr[odd] % 2){
            odd += 2;
        }
        while(!(arr[even] % 2)){
            even += 2;
        }
        if(odd < n && even < n){

            swap(arr[even], arr[odd]);
        } else {
            break;
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");



    

    return EXIT_SUCCESS;
}