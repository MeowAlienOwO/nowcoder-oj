/**
 * author: meow
 * 题目描述
 * 给n个信封的长度和宽度。如果信封A的长和宽都小于信封B，那么信封A可以放到信封B里，请求出信封最多可以嵌套多少层。
 * 输入描述:
 * 输出包含多行，第一行包括一个整数，代表信封的个数(1≤n≤10^5)。接下来n行，每行两个整数l_i和w_i
 *  ，代表信封的长度和宽度(−1e9≤l_i,w_i≤1e9)。
 * 输出描述:
 * 输出包括一行，代表信封最多嵌套多少层。
 * 
 * 思路：排序后，最长子序列，由于已经排序，所以只要求出最长子序列，一定是可嵌套的。
 * 注意排序顺序跟比较顺序
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
typedef struct Envelope{
    int l, w;
} Envelope;

bool sort_rule(Envelope e1, Envelope e2){
    return e1.l < e2.l;
}

int main(){

    // freopen("input.txt","r",stdin); 
    int n;
    scanf("%d", &n);
    vector<Envelope> envs(n);
    for(int i = 0; i < n; i++){
        int l, w;
        scanf("%d %d", &l, &w);
        Envelope e;
        e.l = l;
        e.w = w;
        envs[i] = e;
    }

    sort(envs.begin(), envs.end(), sort_rule);
    vector<int> tail;
    tail.push_back(envs[0].w);

    for(int i = 1; i < n; i++){
        int left = 0;
        int right = tail.size()-1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(tail[mid] < envs[i].w){
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        if(left >= tail.size()){
            tail.push_back(envs[i].w);
        } else{
            tail[left] = envs[i].w;
        }
    }
    printf("%ld\n", tail.size());
    return EXIT_SUCCESS;
}