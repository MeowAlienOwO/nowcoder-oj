/**
 * author: meow
 */
#include<unordered_map>
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
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    unordered_map<int, int> m;
    m[0] = -1;
    
    int len = 0;

    int curr_sum = 0;
    for(int i = 0; i < n; i++){
        curr_sum += arr[i];
        // m.insert();
        // m[k-curr_sum] = min(i, m.count(k-curr_sum) > 0? m[k-curr_sum] : INF);
        if(m.find(curr_sum) == m.end()){
            m[curr_sum] = i;
        }
        if(m.find(curr_sum-k) != m.end()){
            len = max(i - m[curr_sum-k], len);
        } 
    }


    printf("%d\n", len);



    return EXIT_SUCCESS;
}