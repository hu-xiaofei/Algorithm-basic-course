#define _CRT_SECURE_NO_WARNINGS

//01背包问题——每种物品只有1个（选或不选）

//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 1010;  // 定义物品数量和背包容量的最大可能值
//
//int n, m;       // n: 物品数量，m: 背包容量
//int v[N], w[N]; // v[i]: 第i个物品的体积，w[i]: 第i个物品的价值
//int f[N][N];    // DP表，f[i][j]表示前i个物品在容量j下的最大价值
//
//int main() {
//    // 输入物品数量和背包容量
//    cin >> n >> m;
//
//    // 输入每个物品的体积和价值（从1开始存储，方便后续操作）
//    for (int i = 1; i <= n; i++)
//        cin >> v[i] >> w[i];
//
//    // 动态规划核心逻辑
//    for (int i = 1; i <= n; i++)          // 遍历每个物品
//        for (int j = 0; j <= m; j++) {    // 遍历每种可能的背包容量
//            // 默认不选第i个物品，继承前i-1个物品的结果
//            f[i][j] = f[i - 1][j];
//
//            // 如果当前背包容量j足够装下第i个物品，尝试选择它
//            if (j >= v[i])
//                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
//            // 比较不选和选第i个物品的更大价值
//        }
//
//    // 输出前n个物品在容量m下的最大价值
//    cout << f[n][m] << endl;
//
//    return 0;
////}
//
//空间优化做法
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 1010;  // 定义物品数量和背包容量的最大可能值
//
//int n, m;       // n: 物品数量，m: 背包容量
//int v[N], w[N]; // v[i]: 第i个物品的体积，w[i]: 第i个物品的价值
//int f[N];       // 一维DP数组，f[j]表示容量为j时的最大价值
//
//int main() {
//    // 输入物品数量和背包容量
//    cin >> n >> m;
//
//    // 输入每个物品的体积和价值（从1开始存储，方便后续操作）
//    for (int i = 1; i <= n; i++)
//        cin >> v[i] >> w[i];
//
//    // 动态规划核心逻辑（空间优化版）
//    for (int i = 1; i <= n; i++)          // 遍历每个物品
//        for (int j = m; j >= v[i]; j--) { // 逆序遍历背包容量
//            // 决策：是否选择第i个物品
//            f[j] = max(f[j], f[j - v[i]] + w[i]);
//            // f[j]: 不选当前物品
//            // f[j - v[i]] + w[i]: 选当前物品（需确保j >= v[i]）
//        }
//
//    // 输出容量为m时的最大价值
//    cout << f[m] << endl;
//
//    return 0;
//}

//完全背包问题——每种物品有无限个

//朴素做法
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int N = 1010;  // 定义物品数量和背包容量的最大可能值
//
//int n, m;       // n: 物品数量，m: 背包容量
//int v[N], w[N]; // v[i]: 第i个物品的体积，w[i]: 第i个物品的价值
//int f[N][N];    // DP表，f[i][j]表示前i种物品在容量j下的最大价值
//
//int main() {
//    // 输入物品数量和背包容量
//    cin >> n >> m;
//
//    // 输入每个物品的体积和价值（从1开始存储，方便后续操作）
//    for (int i = 1; i <= n; i++)
//        cin >> v[i] >> w[i];
//
//    // 动态规划核心逻辑
//    for (int i = 1; i <= n; i++)          // 遍历每种物品
//        for (int j = 0; j <= m; j++)      // 遍历每种可能的背包容量
//            for (int k = 0; k * v[i] <= j; k++) {  // 遍历当前物品的选择次数k
//                // 更新f[i][j]，比较不选当前物品和选k次当前物品的价值
//                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
//            }
//
//    // 输出前n种物品在容量m下的最大价值
//    cout << f[n][m] << endl;
//
//    return 0;
//}
////进阶做法
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 1010;  // 定义物品数量和背包容量的最大可能值
//
//int n, m;       // n: 物品数量，m: 背包容量
//int v[N], w[N]; // v[i]: 第i个物品的体积，w[i]: 第i个物品的价值
//int f[N][N];    // DP表，f[i][j]表示前i种物品在容量j下的最大价值
//
//int main() {
//    // 输入物品数量和背包容量
//    cin >> n >> m;
//
//    // 输入每个物品的体积和价值（从1开始存储，方便后续操作）
//    for (int i = 1; i <= n; i++)
//        cin >> v[i] >> w[i];
//
//    // 动态规划核心逻辑
//    for (int i = 1; i <= n; i++)          // 遍历每种物品
//        for (int j = 0; j <= m; j++) {    // 遍历每种可能的背包容量
//            // 默认不选当前物品，继承前i-1种物品的结果
//            f[i][j] = f[i - 1][j];
//
//            // 如果当前背包容量j足够装下第i种物品
//            if (j >= v[i])
//                // 决策：比较不选当前物品和选当前物品（可重复选）
//                // 注意这里是f[i][j - v[i]]，不是f[i-1][j - v[i]]
//                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
//        }
//
//    // 输出前n种物品在容量m下的最大价值
//    cout << f[n][m] << endl;
//
//    return 0;
//}
////终极做法（降成一维）
//#include <iostream>
//#include <algorithm>  // 使用max函数需要包含该头文件
//
//using namespace std;
//
//const int N = 1010;  // 定义物品数量和背包容量的最大可能值
//
//int n, m;       // n: 物品种类数，m: 背包总容量
//int v[N], w[N]; // v[i]: 第i种物品的体积，w[i]: 第i种物品的价值
//int f[N];       // 一维DP数组，f[j]表示背包容量为j时的最大价值
//
//int main() {
//    // 输入物品种类数和背包总容量
//    cin >> n >> m;
//
//    // 输入每种物品的体积和价值（从1开始存储）
//    for (int i = 1; i <= n; i++)
//        cin >> v[i] >> w[i];
//
//    // 动态规划核心过程
//    for (int i = 1; i <= n; i++) {          // 遍历每种物品
//        for (int j = v[i]; j <= m; j++) {   // 正序遍历背包容量
//            // 状态转移方程：
//            // 比较"不选当前物品"和"选当前物品"两种情况
//            f[j] = max(
//                f[j],            // 不选当前物品，保持之前的结果
//                f[j - v[i]] + w[i]  // 选当前物品，用j-v[i]容量的最优解加上当前物品价值
//            );
//            // 因为j是正序遍历，f[j-v[i]]可能已经包含当前物品，实现重复选择
//        }
//    }
//
//    // 输出背包容量为m时的最大价值
//    cout << f[m] << endl;
//
//    return 0;
//}

//多重背包问题——每种物品有有限个（c_i个）

//暴力版
//
//#include <iostream>
//#include <algorithm>  // 包含max函数
//
//using namespace std;
//
//const int N = 110;  // 定义最大物品数量和背包容量
//
//int n, m;           // n-物品数量，m-背包容量
//int v[N], w[N], s[N]; // v-物品体积，w-物品价值，s-物品数量限制
//int f[N][N];        // DP数组，f[i][j]表示前i个物品，容量为j时的最大价值
//
//int main()
//{
//    // 输入物品数量和背包容量
//    cin >> n >> m;
//
//    // 输入每个物品的体积、价值和数量限制
//    for (int i = 1; i <= n; i++)
//        cin >> v[i] >> w[i] >> s[i];
//
//    // 动态规划求解
//    for (int i = 1; i <= n; i++)        // 遍历每个物品
//        for (int j = 0; j <= m; j++)     // 遍历每种背包容量
//            for (int k = 0; k <= s[i] && k * v[i] <= j; k++) // 遍历当前物品可以选的数量
//                // 状态转移方程：
//                // 比较不选当前物品和选k个当前物品的情况
//                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
//
//    // 输出结果：前n个物品，容量为m时的最大价值
//    cout << f[n][m] << endl;
//
//    return 0;
//}
//
////二进制优化版
//
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 25000, M = 2010;  // N是拆分后的最大物品数，M是最大背包容量
//
//int n, m;       // n-原始物品数量，m-背包容量
//int v[N], w[N]; // v-拆分后物品体积，w-拆分后物品价值
//int f[M];       // DP数组，f[j]表示容量为j时的最大价值（使用滚动数组优化）
//
//int main()
//{
//    cin >> n >> m;
//    int cnt = 0;  // 计数器，记录拆分后的物品总数
//
//    // 第一部分：二进制拆分物品
//    for (int i = 1; i <= n; i++)
//    {
//        int a, b, s;  // a-体积，b-价值，s-数量
//        cin >> a >> b >> s;
//
//        int k = 1;  // 从1开始拆分（2^0）
//        while (k <= s)  // 二进制拆分过程
//        {
//            cnt++;  // 新增一个拆分物品
//            v[cnt] = a * k;  // 拆分后物品体积 = 单个体积×数量k
//            w[cnt] = b * k;  // 拆分后物品价值 = 单个价值×数量k
//            s -= k;    // 从总数中减去已拆分的数量
//            k *= 2;   // 每次k乘以2（1,2,4,8...）
//        }
//
//        // 处理剩余的部分（无法用2的幂次表示的部分）
//        if (s > 0)
//        {
//            cnt++;
//            v[cnt] = a * s;
//            w[cnt] = b * s;
//        }
//    }
//
//    n = cnt;  // 更新物品总数为拆分后的数量
//
//    // 第二部分：0-1背包解法
//    for (int i = 1; i <= n; i++)       // 遍历每个拆分后的物品
//        for (int j = m; j >= v[i]; j--) // 逆序遍历背包容量
//            f[j] = max(f[j], f[j - v[i]] + w[i]);  // 标准0-1背包状态转移
//
//    cout << f[m] << endl;  // 输出最大价值
//    return 0;
//}

//分组背包问题

//#include <iostream>
//#include <algorithm>  // 包含max函数
//using namespace std;
//
//const int N = 110; // 定义数组大小，可根据实际情况调整
//
//int n, m; // n 表示物品的组数，m 表示背包的容量
//int v[N][N], w[N][N], s[N]; // v[i][k] 表示第 i 组第 k 个物品的体积，w[i][k] 表示价值，s[i] 表示第 i 组的物品数量
//int f[N]; // 动态规划数组，f[j] 表示容量为 j 时背包能装下的最大价值
//
//int main() {
//    cin >> n >> m; // 输入物品的组数和背包容量
//
//    // 读取每组物品的信息
//    for (int i = 1; i <= n; i++) {
//        cin >> s[i]; // 输入第 i 组的物品数量
//        for (int j = 0; j < s[i]; j++) {
//            cin >> v[i][j] >> w[i][j]; // 输入第 i 组第 j 个物品的体积和价值
//        }
//    }
//
//    // 分组背包动态规划核心逻辑
//    for (int i = 1; i <= n; i++) { // 遍历每一组物品
//        for (int j = m; j >= 0; j--) { // 背包容量从大到小遍历（保证每组最多选一个物品）
//            for (int k = 0; k < s[i]; k++) { // 遍历第 i 组的每个物品
//                if (v[i][k] <= j) { // 如果第 i 组第 k 个物品的体积不超过当前背包容量 j
//                    // 更新 f[j]：取不选该物品（f[j]）和选该物品（f[j - v[i][k]] + w[i][k]）的较大值
//                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
//                }
//            }
//        }
//    }
//
//    cout << f[m] << endl; // 输出背包容量为 m 时的最大价值
//
//    return 0;
//}

//数字三角形

//#include <cstdio>
//#include <algorithm>
//using namespace std;
//
//const int N = 510;       // 最大行数
//const int INF = 1e9;      // 定义一个足够大的数表示无穷小
//
//int n;                    // 数字三角形的行数
//int a[N][N];              // 存储数字三角形，a[i][j]表示第i行第j列的数字
//int f[N][N];              // DP数组，f[i][j]表示从顶部到(i,j)位置的最大路径和
//
//int main() {
//    // 输入数字三角形的行数
//    scanf("%d", &n);
//
//    // 输入数字三角形的数据
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= i; j++) {
//            scanf("%d", &a[i][j]);
//        }
//    }
//
//    // 初始化DP数组为负无穷
//    // 这样在后续计算中，无效的位置会被自动排除
//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j <= i + 1; j++) {
//            f[i][j] = -INF;
//        }
//    }
//
//    // 设置起点：顶部第一个数字
//    f[1][1] = a[1][1];
//
//    // 动态规划过程：从第二行开始计算
//    for (int i = 2; i <= n; i++) {
//        for (int j = 1; j <= i; j++) {
//            // 状态转移方程：
//            // 当前位置的最大和 = 从左上或正上方向下来的较大值 + 当前数字
//            f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);
//        }
//    }
//
//    // 在最后一行寻找最大值
//    int res = -INF;
//    for (int i = 1; i <= n; i++) {
//        res = max(res, f[n][i]);
//    }
//
//    // 输出结果
//    printf("%d\n", res);
//
//    return 0;
//}

//最长上升子序列

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int N = 1010;  // 定义最大数据范围
//
//int n;       // 序列长度
//int a[N];    // 存储原始序列，a[i]表示第i个元素
//int f[N];    // DP数组，f[i]表示以第i个数结尾的最长上升子序列长度
//
//int main() {
//    // 输入序列长度
//    scanf("%d", &n);
//
//    // 输入序列元素
//    for (int i = 1; i <= n; i++) {
//        scanf("%d", &a[i]);
//    }
//
//    // 动态规划求解过程
//    for (int i = 1; i <= n; i++) {
//        f[i] = 1;  // 初始情况：每个元素本身构成长度为1的子序列
//
//        // 检查前面所有可能构成上升子序列的元素
//        for (int j = 1; j < i; j++) {
//            // 如果前面的元素比当前元素小，可以构成上升子序列
//            if (a[j] < a[i]) {
//                // 更新f[i]为当前最大值：保持原值或接在a[j]后面
//                f[i] = max(f[i], f[j] + 1);
//            }
//        }
//    }
//
//    // 找出所有f[i]中的最大值，即整个序列的最长上升子序列长度
//    int res = 0;
//    for (int i = 1; i <= n; i++) {
//        res = max(res, f[i]);
//    }
//
//    // 输出结果
//    printf("%d\n", res);
//
//    return 0;
//}

//最长公共子序列

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;  // 定义最大字符串长度

int n, m;       // 两个字符串的长度
char a[N], b[N]; // 存储两个字符串（从索引1开始）
int f[N][N];     // DP数组，f[i][j]表示a[1..i]和b[1..j]的LCS长度

int main() {
    // 输入两个字符串的长度
    scanf("%d%d", &n, &m);
    // 输入两个字符串（从索引1开始存储）
    scanf("%s%s", a + 1, b + 1);

    // 动态规划求解过程
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 情况1：不考虑a[i]，继承f[i-1][j]的值
            // 情况2：不考虑b[j]，继承f[i][j-1]的值
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);

            // 情况3：当a[i]等于b[j]时，可以形成更长的公共子序列
            if (a[i] == b[j]) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
    }

    // 输出结果：f[n][m]就是两个完整字符串的LCS长度
    printf("%d\n", f[n][m]);

    return 0;
}