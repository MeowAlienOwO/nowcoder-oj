/**
 * author: meow
 * 题目描述
 * 给定数组arr，设长度为n，输出arr的最长递增子序列。（如果有多个答案，请输出其中字典序最小的）
 * 输入描述:
 * 输出两行，第一行包括一个正整数n（n<=100000），代表数组长度。第二行包括n个整数，代表数组(1≤arr_i≤1e9)。
 * 输出描述:
 * 输出一行。代表你求出的最长的递增子序列。
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

int bsearch(vector<int>& arr, int target){
    int i = 0, j = arr.size() - 1;

    while(i <= j){

        int mid = i + int((j - i) / 2);

        if(arr[mid] < target){
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    return i;
}

int main(){

    // freopen("input.txt","r",stdin); 
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    vector<int> minsub;
    vector<int> len(n);

    for(int i = 0; i < n; i++){
        if(minsub.empty() || minsub.back() < arr[i]){
            minsub.push_back(arr[i]);
            len[i] = minsub.size();
        } else {
            int idx = bsearch(minsub, arr[i]);
            minsub[idx] = arr[i];
            len[i] = idx+1;
        }
    }

    int res[minsub.size()];
    int i = minsub.size()-1;
    int j = n-1;
    int next = INF;
    while(j >= 0 && i >= 0){
        if(arr[j] < next && arr[j] >= minsub[i] && len[j] >= i+1){
            res[i] = arr[j];
            next = res[i];
            i--;
        }
        j--;
    }

    for(int i = 0; i < minsub.size(); i++){
        printf("%d ", res[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}