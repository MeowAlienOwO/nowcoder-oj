/**
 * author: meow
 * 题目描述
 * 用两个栈实现队列，支持队列的基本操作。
 * 
 * 输入描述:
 * 第一行输入一个整数N，表示对队列进行的操作总数。
 * 下面N行每行输入一个字符串S，表示操作的种类。
 * 如果S为"add"，则后面还有一个整数X表示向队列尾部加入整数X。
 * 如果S为"poll"，则表示弹出队列头部操作。
 * 如果S为"peek"，则表示询问当前队列中头部元素是多少。
 * 
 * 输出描述:
 * 对于每一个为"peek"的操作，输出一行表示当前队列中头部元素是多少。
 * 
 * 1<=N<=1000000
 * -1000000<=X<=1000000
 * 数据保证没有不合法的操作
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

typedef struct Queue{

    stack<int> s1; // in stack
    stack<int> s2; // out stack
    Queue(){
        s1 = stack<int>();
        s2 = stack<int>();
    }

    void movestack(){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }

    int peek(){
        // movestack();
        // return s2.top();
        if(s2.empty()){
            movestack();
        }
        return s2.top();
    }

    void add(int elem){
        s1.push(elem);
    }

    int poll(){
        if(s2.empty()){
            movestack();
        }
        int top = s2.top();
        s2.pop();
        return top;
    }


} Queue;

int main(){

    // freopen("input.txt","r",stdin); 
    int n;
    scanf("%d", &n);
    Queue* queue = new Queue();
    for(int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;
        if(0 == cmd.compare("add")){
            int val;
            cin >> val;
            queue->add(val);

        } else if (0 == cmd.compare("poll")) {
            queue->poll();
        } else if (0 == cmd.compare("peek")) {
            printf("%d\n", queue->peek());
        }
    }

    return EXIT_SUCCESS;
}