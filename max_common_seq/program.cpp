/**
 * author: meow
 * 题目描述
 * 给定两个字符串str1和str2，输出连个字符串的最长公共子序列。如过最长公共子序列为空，则输出-1。
 * 输入描述:
 * 输出包括两行，第一行代表字符串str1，第二行代表str2。(1≤length(str1),length(str2)≤5000)
 * 输出描述:
 * 输出一行，代表他们最长公共子序列。如果公共子序列的长度为空，则输出-1。
 * 示例1
 * 输入
 * 1A2C3D4B56
 * B1D23CA45B6A
 * 输出
 * 123456
 * 说明
 * "123456"和“12C4B6”都是最长公共子序列，任意输出一个。
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
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // 最短编辑距离
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i] == str2[j]) // 相等时进行对角移动
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else // 否则进行曼哈顿移动
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int length = dp[m][n];
    char res[length + 1];
    res[length] = '\0';
    int i = m - 1;
    int j = n - 1;
    int k = length - 1;

    // 从最短编辑距离反推公共子序列
    // 从右下开始，如果上或者左与当前格相等，说明这一步增删了，曼哈顿移动
    // 如果上左相等，说明这一步对角移动，当前元素放入子序列
    while (k >= 0)
    {
        if (i >= 1 && dp[i - 1][j] == dp[i][j])
        {
            i--;
        }
        else if (j >= 1 && dp[i][j - 1] == dp[i][j])
        {
            j--;
        }
        else
        {
            res[k--] = str1[i];
            i--;
            j--;
        }
    }

    cout << string(res) << endl;

    return EXIT_SUCCESS;
}