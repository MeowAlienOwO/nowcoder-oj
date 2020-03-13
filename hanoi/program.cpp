/**
 * author: meow
 * 题目描述
 * 汉诺塔问题比较经典，这里修改一下游戏规则：现在限制不能从最左侧的塔直接移动到最右侧，也不能从最右侧直接移动到最左侧，而是必须经过中间。求当塔有n层的时候，打印最优移动过程和最优移动总步数。
 * 输入描述:
 * 输入一个数n，表示塔层数
 * 输出描述:
 * 按样例格式输出最优移动过程和最优移动总步数
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

typedef struct Hanoi{
    map< string, stack<int> > m;
    Hanoi(int n){
        m["left"] = stack<int>();
        m["right"] = stack<int>();
        m["mid"] = stack<int>();
        for(int i = n; i > 0; i--){
            m["left"].push(i);
        }
    }

    void move(string from, string to){
        int top = m[from].top();
        m[from].pop();
        m[to].push(top);
        // printf("Move %d from %s to %s\n", top, from, to);
        cout << "Move " << top << " from " << from << " to " << to <<endl;
        // return top;
    }

    // from to 外部输入只能是 left, right，简单起见不考虑mid
    int hanoi(int n, string from, string to){
        if(n == 1){
            move(from, "mid");
            move("mid", to);
            return 2;
        } else {
            int step1 = hanoi(n-1, from, to);
            move(from, "mid");
            int step2 = hanoi(n-1, to, from);
            move("mid", to);
            int step3 = hanoi(n-1, from, to);
            return step1 + step2 + step3 + 2;
        }
    }
} Hanoi;


int main(){


    // freopen("input.txt","r",stdin); 
    int n;
    scanf("%d", &n);
    Hanoi h(n);

    printf("It will move %d steps.\n", h.hanoi(n, "left", "right"));

    return EXIT_SUCCESS;
}