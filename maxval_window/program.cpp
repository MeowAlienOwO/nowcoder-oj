/**
 * author: meow
 * 双端队列解法
 */
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
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
    deque<int> q;
    int n, w;
    scanf("%d %d", &n, &w);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }


    // for(int i = 0; i < w; i++){
    //     while(!q.empty() && q.back() <= arr[i]){
    //         q.pop_back();
    //     }
    //     q.push_back(i);

    // }
    // printf("%d ", arr[q.front()]);


    for(int i = 0; i < n; i++){
        while(!q.empty() && arr[q.back()] < arr[i]){
            q.pop_back();
        }

        while(!q.empty() && q.front() < i - w + 1){
            q.pop_front();
        }

        q.push_back(i);

        if(i + 1 >= w){
            printf("%d ", arr[q.front()]);
        }

    }
    printf("\n");

    return EXIT_SUCCESS;
}