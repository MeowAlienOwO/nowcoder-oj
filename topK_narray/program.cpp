/**
 * author: meow
 * 
 * 题目描述
 * 有N个长度不一的数组，所有的数组都是有序的，请从大到小打印这N个数组整体最大的前K个数。
 * 例如，输入含有N行元素的二维数组可以代表N个一维数组。
 * 219, 405, 538, 845, 971
 * 148, 558
 * 52, 99, 348, 691
 * 再输入整数k=5，则打印：
 * Top 5: 971, 845, 691, 558, 538
 * [要求]
 * 时间复杂度为O(klogk)，空间复杂度为O(klogk)
 * 输入描述:
 * 第一行两个整数T, K。分别表示数组个数，需要打印前K大的元素
 * 接下来T行，每行输入格式如下：
 * 开头一个整数N，表示该数组的大小，接下来N个已排好序的数表示数组内的数
 * 输出描述:
 * 从大到小输出输出K个整数，表示前K大。
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

struct HeapNode
{
    int val;
    int row;
    int col;
    bool operator<(const HeapNode &a) const
    {
        return this->val < a.val;
    }
    bool operator>(const HeapNode &a) const
    {
        return this->val > a.val;
    }
};

int main()
{

    int t, k;
    scanf("%d%d\n", &t, &k);
    vector<vector<int>> arr2d;
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        vector<int> arr;
        for (int j = 0; j < n; j++)
        {
            int val;
            scanf("%d", &val);
            arr.push_back(val);
        }
        arr2d.push_back(arr);
    }

    // for (int i = 0; i < t; i++)
    // {
    //     for (int j = 0; j < arr2d[i].size(); j++)
    //     {
    //         cout << arr2d[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    priority_queue<HeapNode, vector<HeapNode>> queue;
    for (int i = 0; i < t; i++)
    {
        if (!arr2d[i].empty())
        {
            HeapNode node;
            node.val = arr2d[i].back();
            node.row = i;
            node.col = arr2d[i].size() - 1;
            queue.push(node);
        }
    }

    for (int i = 0; i < k; i++)
    {
        HeapNode node = queue.top();
        cout << node.val << " ";
        if (node.col > 0)
        {
            HeapNode next;
            next.val = arr2d[node.row][node.col - 1];
            next.row = node.row;
            next.col = node.col - 1;
            queue.pop();
            queue.push(next);
        }
        else
        {
            queue.pop();
        }
    }

    cout << endl;

    return EXIT_SUCCESS;
}