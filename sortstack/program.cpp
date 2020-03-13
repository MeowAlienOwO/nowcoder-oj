/**
 * author: meow
 * 题目描述
 * 一个栈中元素的类型为整型，现在想将该栈从顶到底按从大到小的顺序排序，只许申请一个栈。除此之外，可以申请新的变量，但不能申请额外的数据结构。如何完成排序？
 * 输入描述:
 * 第一行输入一个N，表示栈中元素的个数
 * 第二行输入N个整数a_i
 * 表示栈顶到栈底的各个元素
 * 输出描述:
 * 输出一行表示排序后的栈中栈顶到栈底的各个元素。
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

    int n;
    scanf("%d", &n);
    stack<int> s1;
    stack<int> s2;
    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = n-1; i >= 0; i--){
        s1.push(arr[i]);
    }
    int elem = s1.top();
    s1.pop();
    s2.push(elem);

    while(!s1.empty()){
        
        while(!s1.empty() && s2.top() < s1.top()){
            s2.push(s1.top());
            s1.pop();
        }

        if(s1.empty()){
            break;
        } else {
            int t;
            t = s1.top();
            s1.pop();

            // printf("ok, s2empty %d\n", s2.empty());
            while(!s2.empty() && t < s2.top()){
                s1.push(s2.top());
                s2.pop();
            }

            s2.push(t);
        }

    }

    while(!s2.empty()){
        printf("%d ", s2.top());
        s2.pop();
    }
    printf("\n");

    return EXIT_SUCCESS;
}