/**
 * author: meow
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

void reverse_print(int ptr, int n, int arr[]){
    if(ptr < n){
        reverse_print(ptr+1, n, arr);
        printf("%d ", arr[ptr]);
        return;
    } else{
        return;
    }
}


int main(){

    // freopen("input.txt","r",stdin); 
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    reverse_print(0, n, arr);





    return EXIT_SUCCESS;
}