/**
 * author: meow
 * 题目描述
 * 给定两个字符串str1和str2,输出两个字符串的最长公共子串，如果最长公共子串为空，输出-1。
 * 输入描述:
 * 输入包括两行，第一行代表字符串str1，第二行代表字符串str2。(1≤length(str1),length(str2)≤5000)
 * 输出描述:
 * 输出包括一行，代表最长公共子串。
 * 
 * 示例1
 * 输入
 * 1AB2345CD
 * 12345EF
 * 
 * 输出
 * 2345
 * 
 * 备注:
 * 时间复杂度O(n^2)
 * 额外空间复杂度O(1)。（n可以为其中任意一个字符串长度）
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

string max_common_str(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();

    string res = "";
    for (int i = 0; i < m; i++)
    {
        string tmp = "";
        for (int j = 0; j < min(n, m - i + 1); j++)
        {
            if (str1[i + j] == str2[j])
            {
                tmp.push_back(str2[j]);
                if (tmp.length() >= res.length())
                {
                    res = tmp;
                }
            }
            else
            {

                tmp = "";
            }
        }
    }

    return res;
}
int main()
{

    // freopen("input.txt","r",stdin);
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    string res_str1 = max_common_str(str1, str2);
    string res_str2 = max_common_str(str2, str1);

    if (res_str1.length() == 0 && res_str2.length() == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << (res_str1.length() > res_str2.length() ? res_str1 : res_str2) << endl;
    }
    return EXIT_SUCCESS;
}