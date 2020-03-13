/**
 * author: meow
 * 题目描述
 * 给定一个整数n，代表汉诺塔游戏中从小到大放置n个圆盘，假设开始所有圆盘都在左边的柱子上，那么用最优的办法把所有圆盘都移动到右边的柱子上的过程，就称为最优移动轨迹。给定一个整型数组arr, 其中只含有1、2和3,代表所有圆盘目前的状态，1代表左柱，2代表中柱，3代表右柱，a[i]的值代表第i+1个圆盘的位置（a[i]下标从0开始）。比如，arr=[3,3,2,1], 代表第1个圆盘在右柱上、第2个圆盘在右柱上、第3个圆盘在中柱上、第4个圆盘在左柱上。如果arr代表的状态是最优移动轨迹过程中出现的状态，输出arr这种状态是最优移动轨迹中的第几个状态（由于答案可能较大，请输出对10^9+7取模后的答案）。如果arr代表的状态不是最优移动轨迹过程中出现的状态，则输出-1。
 * 
 * 输入描述:
 * 输入包括两行，第一行一个整数n(1≤n≤2*10^6)，表示圆盘的个数，第二行n个正整数，且均为1或2或3，第i个整数表示第i个圆盘位置。
 * 输出描述:
 * 输出一个整数，表示这种状态是第几个最优移动状态（输出对10^9+7取模后的答案），无解输出-1。
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <cmath>
#include <set>
#include <list>
#include <deque>
#include <map>
#include <queue>
#define LEFT 1
#define MID 2
#define RIGHT 3
#define MOD_NUM 1000000007
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1000000000;
const int maxn = 100;

int main()
{

    // freopen("input.txt","r",stdin);
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int res = 0;
    int from = LEFT;
    int to = RIGHT;
    int mid = MID;

    vector<int> helper(n); // 存储当大小为n的时候，1-n每一次移动到位所需要的步数2^i - 1
    // 大数移位会出问题，不能直接 O(1)
    int last = 1;
    for (int i = 0; i < n; i++)
    {
        helper[i] = last;
        last = (last << 1) % MOD_NUM;
    }

    for (int i = n - 1; i >= 0; i--) // 从大到小进行处理
    {
        if (arr[i] == mid) // 当前最大一个，只可能在from或者to，不可能在mid
        {
            cout << -1 << endl;
            return 0;
        }
        else if (arr[i] == from) // 最大的需要从from挪到to, 没有移动过
        {
            swap(mid, to);
        }
        else
        { //最大的已经在to了，需要加上当前移动的次数
            res = (res + helper[i]) % MOD_NUM;
            swap(from, mid);
        }
    }
    cout << res << endl;

    return EXIT_SUCCESS;
}