/**
 * author: meow
 * 
 * 题目描述
 * 给定一个数组arr，返回不包含本位置值的累乘数组
 * 例如，arr=[2,3,1,4]，返回[12, 8, 24, 6]，即除自己外，其他位置上的累乘
 * [要求]
 * 时间复杂度为O(n)，额外空间复杂度为O(1)
 * 
 * 输入描述:
 * 第一行有两个整数N, P。分别表示序列长度，模数(即输出的每个数需要对此取模)
 * 接下来一行N个整数表示数组内的数
 * 输出描述:
 * 输出N个整数表示答案
 * 
 * 没仔细想 O(1)空间怎么写
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
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1000000000;
const int maxn = 100;

int main()
{

    // freopen("input.txt","r",stdin);
    int n, p;
    scanf("%d%d", &n, &p);
    int arr[n];
    int zero_count = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] == 0)
        {
            zero_count++;
        }
    }

    ll prod[n + 1];
    prod[0] = 1;

    for (int i = 0; i < n; i++)
    {
        prod[i + 1] = (arr[i] * prod[i]) % p;
    }

    ll prod_right[n + 1];
    prod_right[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        prod_right[i] = (arr[i] * prod_right[i + 1]) % p;
    }

    for (int i = 0; i < n; i++)
    {
        cout << prod[i] * prod_right[i + 1] % p << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}