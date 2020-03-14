/**
 * author: meow
 * 题目描述
 * 给定一个double类型的数组arr，其中的元素可正、可负、可0，返回子数组累乘的最大乘积。
 * 例如，arr=[-2.5, 4, 0, 3, 0.5, 8, -1]，子数组[3, 0.5, 8]累乘可以获得最大的乘积12，所以返回12
 * [要求]
 * 时间复杂度为O(n), 空间复杂度为O(1)
 * 输入描述:
 * 第一行一个整数N。表示数组长度。
 * 接下来一行N个浮点数表示数组内的数
 * 输出描述:
 * 输出一个浮点数表示答案，保留到小数点后两位
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
    int n;
    scanf("%d", &n);
    double arr[n];
    for (int i = 0; i < n; i++)
    {
        // scanf("%f", &arr[i]);
        cin >> arr[i];
    }

    double max_prod = arr[0]; // 当前子数组最大乘积
    double min_prod = arr[0]; // 当前子数组最小乘积
    double res = arr[0];

    for (int i = 1; i < n; i++)
    {
        double tmp = max_prod;

        //最大值的来源有三种，如果arr[i]是正数，肯定与前面的最大值相乘得到最大值，
        //如果arr[i]是负数就会与前面的最小值相乘产生最大值。如果前面的为0或者负数，
        //arr[i]本身可能是最大值。
        max_prod = max(arr[i], //
                       max(tmp * arr[i], min_prod * arr[i]));
        // 保存最小值
        min_prod = min(arr[i], //
                       min(tmp * arr[i], min_prod * arr[i]));

        res = max(res, max_prod);
    }
    cout << res << endl;

    return EXIT_SUCCESS;
}