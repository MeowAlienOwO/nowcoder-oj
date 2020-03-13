/**
 * author: meow
 * 
 * 思路：用一个栈存储最小值
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

typedef struct Stack{

    stack<int> s;
    stack<int> helper;

    void pop(){

        if(!helper.empty() && helper.top() == s.top()){
            helper.pop();
        }

        s.pop();

    }

    void push(int elem){
        s.push(elem);
        if(helper.empty() || helper.top() > elem){
            helper.push(elem);
        }

    }

    int getMin(){
        return helper.top();
    }
} Stack;




int main(){

    // freopen("input.txt","r",stdin); 
    int n;
    scanf("%d", &n);
    Stack* stack = new Stack();
    for(int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;
        if(cmd.compare("push") == 0){
            int val;
            cin >> val;
            stack->push(val);
        } else if (cmd.compare("pop") == 0){
            stack->pop();
        } else if (cmd.compare("getMin") == 0) {
            printf("%d\n", stack->getMin());
        }

        // scanf("%d %d", c, d);
        // printf("%d\n", int(b + c / d));
    }

    return EXIT_SUCCESS;
}