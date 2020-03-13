/**
 * 题目描述
 * 实现一个特殊功能的栈，在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作。
 * 输入描述:
 * 第一行输入一个整数N，表示对栈进行的操作总数。
 * 下面N行每行输入一个字符串S，表示操作的种类。
 * 如果S为"push"，则后面还有一个整数X表示向栈里压入整数X。
 * 如果S为"pop"，则表示弹出栈顶操作。
 * 如果S为"getMin"，则表示询问当前栈中的最小元素是多少。
 * 输出描述:
 * 对于每个getMin操作，输出一行表示当前栈中的最小元素是多少。
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
using namespace std;

typedef struct Node{
    int val;
    Node* prev;
    Node(int v){
        val = v;
        prev = NULL;
    }
} Node;

typedef struct Stack{
    Node* top;
    int min;
    Stack(){
        top = NULL; 
        min = INF;
    }

    Node* pop(){
        Node* elem = top;
        top = top->prev;
        if(min == elem->val){
            Node* ptr = top;
            min = INF;
            while(ptr){
                if(ptr->val < min){
                    min = ptr->val;
                } 
                ptr = ptr->prev;
            }
        }
        return elem;
    }

    void push(Node* elem){
        elem->prev = top;
        top = elem;
        if (elem->val < min){
            min = elem->val;
        }
    }

    int getMin(){
        return min;
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
            Node* elem = new Node(val);
            stack->push(elem);
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