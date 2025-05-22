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

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int N = 1010;  // 定义最大字符串长度
//
//int n, m;       // 两个字符串的长度
//char a[N], b[N]; // 存储两个字符串（从索引1开始）
//int f[N][N];     // DP数组，f[i][j]表示a[1..i]和b[1..j]的LCS长度
//
//int main() {
//    // 输入两个字符串的长度
//    scanf("%d%d", &n, &m);
//    // 输入两个字符串（从索引1开始存储）
//    scanf("%s%s", a + 1, b + 1);
//
//    // 动态规划求解过程
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            // 情况1：不考虑a[i]，继承f[i-1][j]的值
//            // 情况2：不考虑b[j]，继承f[i][j-1]的值
//            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
//
//            // 情况3：当a[i]等于b[j]时，可以形成更长的公共子序列
//            if (a[i] == b[j]) {
//                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
//            }
//        }
//    }
//
//    // 输出结果：f[n][m]就是两个完整字符串的LCS长度
//    printf("%d\n", f[n][m]);
//
//    return 0;
//}

//石子合并

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int N = 310;  // 定义最大石子堆数
//
//int n;       // 石子堆数
//int s[N];    // 前缀和数组，s[i]表示前i堆石子的总重量
//int f[N][N]; // DP数组，f[l][r]表示合并区间[l,r]的石子所需的最小代价
//
//int main() {
//    // 输入石子堆数
//    scanf("%d", &n);
//
//    // 输入每堆石子的重量，并计算前缀和
//    for (int i = 1; i <= n; i++) {
//        scanf("%d", &s[i]);
//        s[i] += s[i - 1]; // 前缀和：s[i] = s[1] + s[2] + ... + s[i]
//    }
//
//    // 动态规划过程
//    // 枚举区间长度len，从2开始（因为合并至少需要两堆石子）
//    for (int len = 2; len <= n; len++) {
//        // 枚举区间起点i，计算区间终点r = i + len - 1
//        for (int i = 1; i + len - 1 <= n; i++) {
//            int l = i;                     // 区间左端点
//            int r = i + len - 1;           // 区间右端点
//            f[l][r] = 1e8;                 // 初始化为极大值，方便后续取min
//
//            // 枚举分割点k，将区间[l,r]分成[l,k]和[k+1,r]两部分
//            for (int k = l; k < r; k++) {
//                // 状态转移方程：
//                // 合并[l,k]的代价f[l][k] + 合并[k+1,r]的代价f[k+1][r] + 当前合并的代价s[r] - s[l-1]
//                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
//            }
//        }
//    }
//
//    // 输出合并全部石子堆的最小代价，即f[1][n]
//    printf("%d\n", f[1][n]);
//    return 0;
//}

//计数问题

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int power10(int x) {
//    int res = 1;
//    while (x--) res *= 10; // 通过循环将res乘以10共x次，计算10的x次方
//    return res;
//}
//
//int get(vector<int> num, int l, int r) {
//    int res = 0;
//    for (int i = l; i >= r; i--)
//        res = res * 10 + num[i]; // 从num数组的l位置到r位置，按位组合成一个整数
//    return res;
//}
//
//int count(int n, int x) {
//    if (!n) return 0; // 如果n为0，直接返回0，因为0中不存在任何数字
//
//    vector<int> num;
//    while (n) { // 将整数n的每一位数字按从低位到高位的顺序存储到num向量中
//        num.push_back(n % 10);
//        n /= 10;
//    }
//
//    n = num.size(); // 获取数字n的位数
//    int res = 0;
//    for (int i = n - 1 - !x; i >= 0; i--) { // 从最高位开始遍历数字n的每一位
//        if (i < n - 1) {
//            res += get(num, n - 1, i + 1) * power10(i); // 计算当前位左边部分组成的数乘以10的i次方，累加到结果中
//            if (!x) res -= power10(i); // 如果要统计的数字x是0，需要减去一些重复计算的情况
//        }
//        if (num[i] == x) res += get(num, i - 1, 0) + 1; // 如果当前位数字等于要统计的x，加上当前位右边部分组成的数加1
//        else if (num[i] > x) res += power10(i); // 如果当前位数字大于x，加上10的i次方
//    }
//    return res;
//}
//
//int main() {
//    int a, b;
//    while (cin >> a >> b, a || b) { // 持续读取输入的两个整数a和b，直到a和b都为0
//        if (a > b) swap(a, b); // 如果a大于b，交换a和b的值，保证a <= b
//
//        for (int i = 0; i < 10; i++)
//            cout << count(b, i) - count(a - 1, i) << ' '; // 对于0 - 9每个数字，计算其在区间[a, b]中出现的次数并输出
//        cout << endl;
//    }
//    return 0;
//}

//蒙德里安的梦想

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int N = 12, M = 1 << N; // N是最大行数，M是最大状态数(2^N)
//
//int n, m;
//long long f[N][M]; // f[i][j]表示前i-1列已填满，第i列状态为j的方案数
//bool st[M]; // st[i]表示状态i是否合法(连续的0是否为偶数个)
//
//int main()
//{
//    int n, m;
//    while (cin >> n >> m, n || m) // 循环读取输入，直到n和m都为0
//    {
//        memset(f, 0, sizeof f); // 初始化动态规划数组
//
//        // 预处理所有状态的合法性
//        for (int i = 0; i < 1 << n; i++)
//        {
//            st[i] = true;
//            int cnt = 0; // 连续0的计数器
//            for (int j = 0; j < n; j++)
//                if (i >> j & 1) // 如果当前位是1
//                {
//                    if (cnt & 1) st[i] = false; // 如果前面连续的0是奇数个，状态不合法
//                    cnt = 0;
//                }
//                else cnt++; // 当前位是0，计数器加1
//            if (cnt & 1) st[i] = false; // 检查最后的连续0是否为奇数个
//        }
//
//        f[0][0] = 1; // 初始状态：第0列没有伸出到第1列的情况有1种方案
//
//        // 动态规划过程
//        for (int i = 1; i <= m; i++) // 遍历每一列
//            for (int j = 0; j < 1 << n; j++) // 遍历当前列的所有可能状态
//                for (int k = 0; k < 1 << n; k++) // 遍历前一列的所有可能状态
//                    if ((j & k) == 0 && st[j | k]) // 两列状态不冲突且合并状态合法
//                        f[i][j] += f[i - 1][k]; // 状态转移
//
//        cout << f[m][0] << endl; // 输出结果：第m列没有伸出到m+1列的情况数
//    }
//    return 0;
//}

//最短Hamilton路径

//#include <cstring>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int N = 20, M = 1 << N;  // N是最大点数，M是状态数(2^N)
//
//int n;               // 实际点数
//int w[N][N];         // 邻接矩阵存储图的权重
//int f[M][N];         // DP数组，f[i][j]表示状态i下终点为j的最短路径
//
//int main() {
//    cin >> n;
//    // 读取图的权重
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < n; j++)
//            cin >> w[i][j];
//
//    // 初始化DP数组为极大值
//    memset(f, 0x3f, sizeof f);
//    f[1][0] = 0;  // 初始状态：只经过0号点(状态1)，终点为0，路径长度为0
//
//    // 动态规划过程
//    for (int i = 0; i < 1 << n; i++)      // 枚举所有状态
//        for (int j = 0; j < n; j++)       // 枚举可能的终点
//            if (i >> j & 1)               // 如果状态i包含j点
//                for (int k = 0; k < n; k++)  // 枚举可能的前一个点
//                    if ((i - (1 << j)) >> k & 1)  // 如果状态i去掉j点后包含k点
//                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
//
//    // 输出结果：经过所有点(状态为2^n-1)，终点为n-1的最短路径
//    cout << f[(1 << n) - 1][n - 1] << endl;
//    return 0;
//}

//没有上司的舞会

//#include <iostream>
//#include <cstring>
//using namespace std;
//
//const int N = 6010; // 定义一个常量N，可能表示节点的最大数量
//
//int n; // 表示节点的实际数量
//int happy[N]; // 数组happy用于存储每个节点对应的 “快乐值”（权值）
//int h[N], e[N], ne[N], idx; // h数组是邻接表表头数组，e数组存储边的终点，ne数组存储同一起点下一条边的编号，idx用于记录边的编号
//int f[N][2]; // 二维数组f，f[i][0]表示不选节点i时，以i为根的子树能获得的最大快乐值；f[i][1]表示选节点i时，以i为根的子树能获得的最大快乐值
//bool has_father[N]; // 布尔数组，用于标记每个节点是否有父节点
//
//// 函数功能：向邻接表中添加一条从a到b的边
//void add(int a, int b) {
//    e[idx] = b; // 将边的终点存入e数组
//    ne[idx] = h[a]; // 将同一起点a的上一条边的编号存入ne数组
//    h[a] = idx++; // 更新起点a对应的表头，指向下一条边，并让边编号idx自增
//}
//
//// 函数功能：以节点u为根进行深度优先搜索，计算选和不选节点u时的最大快乐值
//void dfs(int u) {
//    f[u][1] = happy[u]; // 选择节点u时，初始快乐值为节点u自身的快乐值
//
//    for (int i = h[u]; i != -1; i = ne[i]) { // 遍历节点u的所有子节点
//        int j = e[i]; // 获取子节点j
//        dfs(j); // 递归访问子节点j
//
//        // 不选节点u时，其最大快乐值是所有子节点选或不选情况下的最大值之和
//        f[u][0] += max(f[j][0], f[j][1]);
//        // 选择节点u时，其最大快乐值是加上所有子节点不选情况下的快乐值之和
//        f[u][1] += f[j][0];
//    }
//}
//
//int main() {
//    scanf("%d", &n); // 读取节点数量
//    for (int i = 1; i <= n; i++) scanf("%d", &happy[i]); // 读取每个节点的快乐值
//
//    memset(h, -1, sizeof h); // 将邻接表表头数组h初始化为 -1，表示没有边
//
//    for (int i = 0; i < n - 1; i++) { // 读取n - 1条边的信息，因为n个节点的树有n - 1条边
//        int a, b;
//        scanf("%d%d", &a, &b);
//        has_father[a] = true; // 标记节点a有父节点
//        add(b, a); // 添加一条从b到a的边，这里b是a的父节点
//    }
//
//    int root = 1;
//    while (has_father[root]) root++; // 找到没有父节点的根节点
//
//    dfs(root); // 从根节点开始进行深度优先搜索
//
//    // 输出选择根节点或不选择根节点情况下的最大快乐值
//    printf("%d\n", max(f[root][0], f[root][1]));
//
//    return 0;
//}

//滑雪

//#include <iostream>
//#include <cstring>
//using namespace std;
//
//const int N = 310; // 定义一个常量N，可能表示地形矩阵的最大规模
//
//int n, m; // n表示地形矩阵的行数，m表示地形矩阵的列数
//int h[N][N]; // 二维数组h用于存储地形矩阵，h[i][j]表示坐标(i, j)处的高度
//int f[N][N]; // 二维数组f用于存储动态规划的结果，f[i][j]表示从坐标(i, j)出发能滑出的最长路径长度
//int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 }; // dx和dy数组表示在二维平面上四个方向的偏移量，分别是上、右、下、左
//
//// 函数功能：计算从坐标(x, y)出发能滑出的最长路径长度
//int dp(int x, int y) {
//    int& v = f[x][y]; // 取f[x][y]的引用，方便后续操作
//    if (v != -1) return v; // 如果f[x][y]已经计算过（值不为 -1 ），直接返回其值
//
//    v = 1; // 初始化从当前点出发的路径长度为1，即至少包含当前点自身
//    for (int i = 0; i < 4; i++) { // 遍历四个方向
//        int a = x + dx[i], b = y + dy[i]; // 计算相邻点的坐标
//        // 判断相邻点是否在地形矩阵范围内，且高度比当前点低
//        if (a >= 1 && a <= n && b >= 1 && b <= m && h[a][b] < h[x][y])
//            v = max(v, dp(a, b) + 1); // 更新最长路径长度，取当前v和相邻点最长路径加1后的较大值
//    }
//    return v; // 返回从坐标(x, y)出发能滑出的最长路径长度
//}
//
//int main() {
//    scanf("%d%d", &n, &m); // 读取地形矩阵的行数n和列数m
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//            scanf("%d", &h[i][j]); // 读取地形矩阵每个位置的高度值
//
//    memset(f, -1, sizeof f); // 将动态规划数组f初始化为 -1，表示都还未计算过
//
//    int res = 0;
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//            res = max(res, dp(i, j)); // 遍历地形矩阵每个点，计算并更新能滑出的最长路径长度
//
//    printf("%d\n", res); // 输出最长路径长度
//    return 0;
//}