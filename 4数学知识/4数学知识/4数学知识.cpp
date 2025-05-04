#define _CRT_SECURE_NO_WARNINGS

//质数的判定——试除法

//bool is_prime(int n)
//{
//    // 如果n小于2，直接返回false，因为质数定义是大于1的自然数
//    if (n < 2) return false;
//
//    // 遍历从2到√n的所有可能因数
//    // 不推荐写法：i<=sqrt(n) 或者 i*i<=n (防止整数溢出)
//    for (int i = 2; i <= n / i; i++)
//        // 如果n能被i整除，说明n不是质数
//        if (n % i == 0)
//            return false;
//
//    // 如果循环结束都没有找到因数，说明n是质数
//    return true;
//}

//分离质因数——试除法

////将一个合数(大于1的非质数)分解为若干个质数相乘的形式的过程
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//// 质因数分解函数
//void divide(int n)
//{
//    // 遍历可能的质因数，从2开始到√n
//    for (int i = 2; i <= n / i; i++)
//        // 如果i是n的因数
//        if (n % i == 0) // 这里的i一定是质数
//        {
//            int s = 0; // 记录当前质因数的指数
//            // 不断除以i，直到不能整除为止
//            while (n % i == 0)
//            {
//                n /= i;
//                s++;
//            }
//            // 输出质因数及其指数
//            printf("%d %d\n", i, s);
//        }
//
//    // 处理剩下的质因数（如果n>1，说明n本身就是一个质数）
//    if (n > 1) printf("%d %d\n", n, 1);
//    puts(""); // 输出空行分隔不同数的分解结果
//}
//
//int main()
//{
//    int n;
//    scanf("%d", &n); // 输入要分解的数的个数
//    while (n--) // 循环处理每个数
//    {
//        int x;
//        scanf("%d", &x); // 输入待分解的数
//        divide(x); // 调用分解函数
//    }
//}
////输出：例如12：2 2 / 3 1->(表示12=2^2+3^1)

//筛质数——埃氏筛法 O(nloglogn)(比O(n)稍大）

////筛选小于等于给定数字n的所有质数
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 1000010;
//
//int primes[N], cnt;       // 存储质数的数组和计数器
//bool st[N];               // 标记数组，st[i]为true表示i不是质数
//
//void get_primes(int n)    // 筛质数的主要函数
//{
//    for (int i = 2; i <= n; i++)
//    {
//        if (!st[i])       // 如果i是质数
//        {
//            primes[cnt++] = i;  // 将其加入质数数组
//            for (int j = i + i; j <= n; j += i) st[j] = true; // 标记i的倍数
//        }
//    }
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//    get_primes(n);
//    cout << cnt << endl;  // 输出小于等于n的质数个数
//}

//筛质数——线性筛法 O(n)

//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 10000010;  // 定义筛法的上限
//
//int primes[N], cnt;      // primes数组存储质数，cnt记录质数个数
//bool st[N];              // st数组标记是否为合数（true表示是合数）
//
//void get_primes(int n)   // 线性筛法主函数
//{
//    for (int i = 2; i <= n; i++)
//    {
//        if (!st[i]) primes[cnt++] = i;  // i是质数（因其从未被标记过），加入primes数组
//        for (int j = 0; primes[j] <= n / i; j++)
//        {
//            st[primes[j] * i] = true;     // primes[j](质数队列)*i（质数）（一定为合数）标记合数
//            if (i % primes[j] == 0) break; // 关键优化，保证线性复杂度
//                                           // 达成i % primes[j] == 0，primes[j]一定是i的最小质因子
//                                           //合数一定会被筛掉
//        }
//    }
//}
//
//int main()
//{
//    int n;
//    cin >> n;            // 输入上限n
//    get_primes(n);       // 执行筛法
//    cout << cnt << endl; // 输出质数个数
//    return 0;
//}

//约数——试除法 O(√n)

//#include <iostream>   // 输入输出
//#include <algorithm>  // 排序算法
//#include <vector>     // 动态数组
//using namespace std;  
//
//vector<int> get_divisors(int n)
//{
//    vector<int> res;  // 用于存储结果的向量
//
//    // 遍历从1到√n的所有可能约数
//    for (int i = 1; i <= n / i; i++)
//        if (n % i == 0)  // 如果i能整除n，说明i是n的约数
//        {
//            res.push_back(i);  // 将i加入结果
//
//            // 如果i和n/i不是同一个数，把n/i也加入结果
//            if (i != n / i) res.push_back(n / i);
//        }
//
//    // 对结果进行排序
//    sort(res.begin(), res.end());
//    return res;
//}
//
//int main()
//{
//    int n;
//    cin >> n;  // 输入要处理的数字个数
//
//    while (n--)  // 处理每个数字
//    {
//        int x;
//        cin >> x;  // 输入数字x
//
//        // 获取x的所有约数
//        auto res = get_divisors(x);
//
//        // 输出结果
//        for (auto t : res) cout << t << ' ';
//        cout << endl;
//    }
//}

//求约个数

//如果一个数 N 的质因数分解为：N = p₁ ^ a₁ × p₂ ^ a₂ × ... × pₖ ^ aₖ
//那么 N 的约数个数为：(a₁ + 1) ×(a₂ + 1) × ... ×(aₖ + 1)
//
//#include <iostream>
//#include <algorithm>
//#include <unordered_map>  // 使用哈希表存储质因数及其指数
//using namespace std;
//
//typedef long long LL;      // 定义长整型别名
//const int mod = 1e9 + 7;   // 模数
//
//int main() {
//    int n;
//    cin >> n;  // 输入数字的个数
//
//    unordered_map<int, int> primes;  // 存储质因数及其总指数
//
//    while (n--) { 
//        int x;
//        cin >> x;  // 输入每个数字
//
//        // 对x进行质因数分解
//        for (int i = 2; i <= x / i; i++) {  // 只需检查到√x
//            while (x % i == 0) {             // 若能整除
//                x /= i;
//                primes[i]++;  // 质因数i的指数+1
//                //不需要初始化，直接通过 primes[key] 访问时，如果 key 不存在，会自动插入该键
//            }
//        }
//
//        if (x > 1) primes[x]++;  // 处理剩余的质因数
//    }
//    LL res = 1;
//    for (auto prime : primes) {
//        res = res * (prime.second + 1) % mod;  // 应用约数个数公式
//    }
//    cout << res << endl;
//}

//约数求和

//#include <iostream>
//#include <algorithm>
//#include <unordered_map>  // 使用哈希表存储质因数及其指数
//using namespace std;
//
//typedef long long LL;      // 定义长整型别名
//const int mod = 1e9 + 7;   // 模数
//
//int main() {
//    int n;
//    cin >> n;  // 输入数字的个数
//
//    unordered_map<int, int> primes;
//    while (n--) {
//        int x;
//        cin >> x;
//
//        // 质因数分解
//        for (int i = 2; i <= x / i; i++) {
//            while (x % i == 0) {
//                x /= i;
//                primes[i]++; // 记录质因数i的指数
//            }
//        }
//        if (x > 1) primes[x]++; // 处理剩余的质因数
//    }
//
//    LL res = 1;
//    for (auto prime : primes) {
//        int p = prime.first, a = prime.second;
//        LL t = 1;
//        while (a--) {
//            t = (t * p + 1) % mod; // 计算1 + p + p² + ... + p^a
//        }
//        res = res * t % mod; // 累乘各项
//    }
//    cout << res << endl;
//}

//最大公约数——欧几里得算法

////欧几里得算法：gcd(a, b) = gcd(b, a mod b)
////a和b的最大公约数等于b和a模b的最大公约数
//#include <iostream>  // 用于输入输出操作
//using namespace std;
//
//// 递归实现欧几里得算法***得出a和b的最小公因数
//int gcd(int a, int b) {
//    return b ? gcd(b, a % b) : a;
//}
//
//int main() {
//    int n;
//    scanf("%d", &n); 
//
//    while (n--) {
//        int a, b;
//        scanf("%d%d", &a, &b);  // 输入两个整数
//
//        // 计算并输出GCD
//        printf("%d\n", gcd(a, b));
//    }
//
//    return 0;
//}

//欧拉函数——用定义求法

//欧拉函数φ(n)（记作phi(n)）表示小于或等于n的正整数中与n互质的数的个数
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;  // 输入要计算的数字个数
//
//    while (n--) {  // 处理每个数字
//        int a;
//        cin >> a;  // 输入当前数字
//
//        int res = a;  // 初始化结果为a本身
//
//        // 质因数分解并计算欧拉函数值
//        for (int i = 2; i <= a / i; i++) {
//            if (a % i == 0) {  // 如果i是a的质因数
//                res = res / i * (i - 1);  // 应用欧拉函数公式
//                //等同于：res = res (1 - 1/i)
//                while (a % i == 0) a /= i;  // 去除所有i因子
//            }
//        }
//
//        // 处理剩余的质因数（如果a>1说明a本身是质数）
//        if (a > 1) res = res / a * (a - 1);
//
//        cout << res << endl;  // 输出结果
//    }
//
//    return 0;
//}

//欧拉函数——线性筛法

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//typedef long long LL;
//const int N = 1000010;
//
//int primes[N], cnt;  // 存储质数的数组和计数器
//int phi[N];         // 存储欧拉函数值的数组
//bool st[N];         // 标记是否为合数
//
//LL get_eulers(int n) {
//    phi[1] = 1;  // 特殊情况：φ(1)=1
//
//    // 线性筛法过程
//    for (int i = 2; i <= n; i++) {
//        if (!st[i]) {  // 如果i是质数
//            primes[cnt++] = i;  // 存储质数
//            phi[i] = i - 1;     // 质数的φ值=i-1
//        }
//
//        // 用当前质数筛去合数
//        for (int j = 0; primes[j] <= n / i; j++) {
//            st[primes[j] * i] = true;  // 标记合数
//
//            if (i % primes[j] == 0) {
//                // 情况1：primes[j]是i的最小质因数***具体推导方法另见资料
//                phi[primes[j] * i] = phi[i] * primes[j];
//                break;
//            }
//            else {
//                // 情况2：primes[j]与i互质***
//                phi[primes[j] * i] = phi[i] * (primes[j] - 1);
//            }
//        }
//    }
//
//    // 计算1到n所有欧拉函数值的和
//    LL res = 0;
//    for (int i = 1; i <= n; i++) res += phi[i];
//    return res;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    cout << get_eulers(n) << endl;
//    return 0;
//}

//欧拉定理

//a^φ(n) ≡ 1 (mod n)
//a的φ(n)次方除以n的余数是1

//快速幂

//#include <iostream>
//#include <cstdio>  // 用于 scanf 和 printf
//
//using namespace std;
//
//typedef long long LL;  // 定义 long long 类型别名，防止溢出
//
////*
//// * 快速幂取模函数：计算 a^k % p
//// * @param a 底数
//// * @param k 指数
//// * @param p 模数
//// * @return 计算结果 (a^k % p)
//// 
//int qmi(int a, int k, int p) {
//    int res = 1;               // 初始化结果为 1
//    while (k) {                // 当指数 k 不为 0 时循环
//        if (k & 1)             // 如果 k 的二进制最低位是 1（奇数）
//            res = (LL)res * a % p;  // 更新结果（注意强制转换防止溢出）
//        k >>= 1;               // 右移一位，相当于 k /= 2
//        a = (LL)a * a % p;     // 底数平方并取模
//    }
//    return res;
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);           // 输入测试用例数量
//    while (n--) {              // 处理每个测试用例
//        int a, k, p;
//        scanf("%d%d%d", &a, &k, &p);  // 输入底数、指数、模数
//        printf("%d\n", qmi(a, k, p));  // 输出 a^k % p
//    }
//    return 0;
//}

//快速幂求逆元

//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//typedef long long LL;  // 防溢出
//
//int qmi(int a, int k, int p) {
//    int res = 1;
//    while (k) {
//        if (k & 1) res = (LL)res * a % p;  // 如果当前二进制位为1，累乘到结果
//        k >>= 1;                           // 右移一位，相当于 k /= 2
//        a = (LL)a * a % p;                 // 底数平方
//    }
//    return res;
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);          // 输入测试用例数量
//    while (n--) {
//        int a, p;
//        scanf("%d%d", &a, &p); // 输入 a 和模数 p
//        int res = qmi(a, p - 2, p); // 计算 a^{p-2} mod p（即逆元）
//        if (a % p) printf("%d\n", res); // 如果 a 和 p 互质，输出逆元
//        else puts("impossible");        // 否则输出不可能
//    }
//    return 0;
//}

//扩展欧几里得算法

//#include <iostream>
//using namespace std;
//
////a⋅x+b⋅y=gcd(a,b)
//int exgcd(int a, int b, int& x, int& y) {
//    if (!b) {                   // 递归终止条件：b = 0
//        x = 1, y = 0;          // 此时 gcd(a, 0) = a，系数为 x=1, y=0
//        return a;               // 返回 a 作为 GCD
//    }
//
//    int d = exgcd(b, a % b, y, x); // 递归计算 gcd(b, a % b)，并交换 x 和 y
//                                    //原理详见上欧几里得算法
//    y -= a / b * x;             // 更新 y 的值
//    return d;                   // 返回 GCD
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);           // 输入测试用例数量
//
//    while (n--) {              // 处理每个测试用例
//        int a, b, x, y;
//        scanf("%d%d", &a, &b); // 输入整数 a 和 b
//
//        exgcd(a, b, x, y);     // 计算 x 和 y
//
//        printf("%d %d\n", x, y); // 输出 x 和 y
//    }
//}

//线性同余方程——扩展欧几里得算法

//#include <iostream>
//using namespace std;
//
//typedef long long LL;  // 定义长整型别名，防止乘法溢出
//
//int exgcd(int a, int b, int& x, int& y) {
//    if (!b) {                   // 递归终止条件：b = 0
//        x = 1, y = 0;          // 此时 gcd(a,0)=a，解为 x=1, y=0
//        return a;               // 返回最大公约数
//    }
//    int d = exgcd(b, a % b, y, x); // 递归计算，交换x和y以简化回溯
//    y -= a / b * x;             // 更新y的值
//    return d;                   // 返回gcd(a,b)
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);           // 输入测试用例数量
//
//    while (n--) {              // 处理每个测试用例
//        int a, b, m;
//        scanf("%d%d%d", &a, &b, &m); // 输入a, b, m（方程: a*x ≡ b mod m）
//        int x, y;
//        int d = exgcd(a, m, x, y);   // 求解a*x + m*y = d（d是gcd(a,m)）
//
//        if (b % d) puts("impossible"); // 若d不整除b，方程无解
//        else {
//            // 解为 x0 = x * (b/d) mod (m/d)，调整到最小正整数
//            LL x0 = (LL)x * (b / d) % m;
//            x0 = (x0 % m + m) % m;    // 保证x0为正
//            printf("%lld\n", x0);
//        }
//    }
//    return 0;
//}

//中国剩余定理

//高斯消元法

//#include <iostream>
//#include <algorithm> // 用于 swap()
//#include <cmath> // fabs:用于计算浮点数的绝对值
//
//using namespace std;
//
//const int N = 110;
//const double eps = 1e-6;  // 1e-6:是一个经验值,表示一个很小的数用于浮点数比较
//                          //eps（epsilon）是一个误差容忍值，用于判断两个浮点数是否“近似相等”
//
//int n;
//double a[N][N];  // 增广矩阵，存储系数和常数项
//
//int gauss() {
//    int c, r;  // c: 列(column), r: 行(row)
//
//    // 高斯消元主循环
//    for (c = 0, r = 0; c < n; c++) {
//        // 1. 找到当前列绝对值最大的行
//        int t = r;
//        for (int i = r; i < n; i++)
//            if (fabs(a[i][c]) > fabs(a[t][c]))
//                t = i;
//
//        // 如果当前列全为0，跳过处理
//        if (fabs(a[t][c]) < eps) continue;
//
//        // 2. 将最大行交换到当前行
//        for (int i = c; i <= n; i++) swap(a[t][i], a[r][i]);
//
//        // 3. 将当前行的首元素变为1
//        for (int i = n; i >= c; i--) a[r][i] /= a[r][c];
//
//        // 4. 用当前行消去下面所有行的当前列
//        for (int i = r + 1; i < n; i++)  // 遍历当前行 r 下面的所有行 i
//            if (fabs(a[i][c]) > eps)     // 如果 a[i][c] 不是 0（避免无效计算）
//                for (int j = n; j >= c; j--)  // 从右往左更新行 i 的所有元素
//                    a[i][j] -= a[r][j] * a[i][c]; // 行变换：行 i -= 行 r × a[i][c]
//
//        r++;  // 处理下一行
//    }
//
//    // 判断解的情况
//    if (r < n) {               // 如果有效行数 r < n，说明消元后存在全零行
//        // 检查是否有矛盾方程
//        for (int i = r; i < n; i++) // 检查所有剩余行
//            if (fabs(a[i][n]) > eps)// 如果常数项不为 0
//                return 2;           // 无解（矛盾方程）
//        return 1;                   // 否则有无穷多解
//    }
//
//    // 回代求解
//    for (int i = n - 1; i >= 0; i--)      // 从最后一行往上回代
//        for (int j = i + 1; j < n; j++)   // 遍历当前行右边的所有列
//            a[i][n] -= a[i][j] * a[j][n]; // 更新常数项：减去已知变量的贡献
//
//    return 0; // 有唯一解
//}
//
//int main() {
//    cin >> n;  // 输入方程个数/未知数个数
//
//    // 输入增广矩阵
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < n + 1; j++)
//            cin >> a[i][j];
//
//    // 调用高斯消元
//    int t = gauss();
//
//    // 输出结果
//    if (t == 0) {
//        // 唯一解，输出解向量
//        for (int i = 0; i < n; i++) printf("%.2lf\n", a[i][n]);
//    }
//    else if (t == 1) puts("Infinite group solutions");  // 无穷多解
//    else puts("No solution");  // 无解
//
//    return 0;
//}

//求组合数1——递推思想

//#include <iostream>
//#include <algorithm>  // 包含算法库，虽然这里没用到但习惯性保留
//
//using namespace std;  // 使用标准命名空间
//
//const int N = 2010;      // 定义组合数表的最大范围
//const int mod = 1e9 + 7; // 定义模数，10^9+7是常用的大质数
//
//int c[N][N];  // 定义组合数表，c[a][b]表示C(a,b)即从a个中选b个的组合数
//
//// 初始化函数：预计算所有可能的组合数
//void init()
//{
//    // 遍历所有可能的a值（0到N-1）
//    for (int i = 0; i < N; i++)
//        // 对于每个a，遍历所有可能的b值（0到a，因为b>a时C(a,b)=0）
//        for (int j = 0; j <= i; j++)
//            if (!j)
//                // 基本情况：C(a,0) = 1（从a个中选0个只有1种方法）
//                c[i][j] = 1;
//            else
//                // 递推公式：C(a,b) = C(a-1,b) + C(a-1,b-1)
//                // 并对结果取模防止溢出
//                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
//}
//
//int main()
//{
//    init();  // 程序开始先初始化组合数表
//
//    int n;   // 定义查询次数
//    scanf("%d", &n);  // 读取查询次数
//
//    // 处理每个查询
//    while (n--)
//    {
//        int a, b;
//        scanf("%d%d", &a, &b);  // 读取a和b
//        printf("%d\n", c[a][b]); // 直接输出预计算好的结果
//        // 注意：这里假设输入的a<N且b<=a，实际应用中可能需要检查
//    }
//
//    return 0;  // 程序正常结束
//}

//求组合数2——预处理思想

//#include <iostream>
//#include <algorithm>  // 包含算法库，虽然这里没用到但习惯性保留
//
//using namespace std;  // 使用标准命名空间
//
//typedef long long LL;  // 定义LL为long long类型，防止计算时溢出
//const int N = 100010;  // 预处理的最大范围
//const int mod = 1e9 + 7;  // 常用的质数模数
//
//int fact[N];    // 存储阶乘 fact[i] = i! % mod
//int infact[N];  // 存储阶乘的逆元 infact[i] = (i!)^-1 % mod
//
//// 快速幂算法：计算 a^k % p
//int qmi(int a, int k, int p)
//{
//    int res = 1;  // 初始化结果为1
//    while (k)
//    {
//        if (k & 1) res = (LL)res * a % p;  // 如果k的二进制最低位是1，乘上a
//        a = (LL)a * a % p;  // a平方
//        k >>= 1;  // k右移一位
//    }
//    return res;
//}
//
//int main()
//{
//    // 初始化阶乘和阶乘逆元数组
//    fact[0] = infact[0] = 1;  // 0! = 1，0!的逆元也是1
//
//    // 预处理计算1~N-1的阶乘和它们的逆元
//    for (int i = 1; i < N; i++)
//    {
//        fact[i] = (LL)fact[i - 1] * i % mod;  // 计算i! = (i-1)! * i
//        // 计算i!的逆元 = ((i-1)!的逆元) * (i的逆元)
//        // 使用费马小定理：i的逆元 = i^(mod-2) % mod
//        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
//    }
//
//    int n;  // 查询次数
//    scanf("%d", &n);  // 读取查询次数
//
//    // 处理每个查询
//    while (n--)
//    {
//        int a, b;
//        scanf("%d%d", &a, &b);  // 读取a和b
//
//        // 计算组合数C(a,b) = a! / (b! * (a-b)!)
//        // 在模运算下转换为：a! * (b!)^-1 * ((a-b)!)^-1 % mod
//        printf("%d\n", (LL)fact[a] * infact[b] % mod * infact[a - b] % mod);
//    }
//
//    return 0;
//}

//求组合数3——卢卡斯定理

////卢卡斯定理适用于大组合数取模（a, b 极大，p 是质数）
//#include <iostream>
//using namespace std;
//typedef long long LL;
//
//int p;
//
//// 快速幂计算 a^k % p
//int qmi(int a, int k) {
//    int res = 1;
//    while (k) {
//        if (k & 1) res = (LL)res * a % p;  // 如果k的二进制最低位是1，乘上a
//        a = (LL)a * a % p;  // a平方
//        k >>= 1;  // k右移一位
//    }
//    return res;
//}
//
//// 计算 C(a, b) % p（a, b < p）
//int C(int a, int b) {
//    int res = 1;
//    for (int i = 1, j = a; i <= b; i++, j--) {
//        res = (LL)res * j % p;  // 计算分子：a * (a-1) * ... * (a-b+1)
//        res = (LL)res * qmi(i, p - 2) % p;  // 乘以分母的逆元：1/i! ≡ i^(p-2) mod p
//    }
//    return res;
//}
//
//// 卢卡斯定理递归计算 C(a, b) % p
//int lucas(LL a, LL b) {
//    if (a < p && b < p) return C(a, b);  // 递归终止条件
//    return (LL)C(a % p, b % p) * lucas(a / p, b / p) % p;  // 递归分解
//    //卢卡斯定理直接用，别管证明了
//}
//
//int main() {
//    int n;
//    cin >> n;  // 输入查询次数
//    while (n--) {
//        LL a, b;
//        cin >> a >> b >> p;  // 输入a, b, p（p必须是质数）
//        cout << lucas(a, b) << endl;  // 输出C(a, b) % p
//    }
//    return 0;
//}

//求组合数4——分解质因数

//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int N = 5010;
//int primes[N], cnt;     // 存储所有≤N的质数
//int sum[N];             // 存储每个质数的指数
//bool st[N];             // 筛法标记数组
//
//// （线性筛）
//void get_primes(int n) {
//    for (int i = 2; i <= n; i++) {
//        if (!st[i]) primes[cnt++] = i;  // i是质数，加入primes数组
//        for (int j = 0; primes[j] <= n / i; j++) {
//            st[primes[j] * i] = true;   // 筛掉合数 primes[j]*i
//            if (i % primes[j] == 0) break;  // 保证每个合数只被最小质因子筛掉
//        }
//    }
//}
//
//// 计算n!中包含质数p的指数（Legendre公式）
//int get(int n, int p) {
//    int res = 0;
//    while (n) {
//        res += n / p;  // 累加p的倍数贡献
//        n /= p;        // 计算更高次幂的贡献
//    }
//    return res;
//}
//
//// 高精度乘法：大整数a × 小整数b
//vector<int> mul(vector<int> a, int b) {
//    vector<int> c;
//    int t = 0;  // 进位
//    for (int i = 0; i < a.size(); i++) {
//        t += a[i] * b;      // 当前位乘积 + 进位
//        c.push_back(t % 10); // 取个位数
//        t /= 10;            // 计算进位
//    }
//    while (t) {             // 处理剩余进位
//        c.push_back(t % 10);
//        t /= 10;
//    }
//    return c;
//}
//
//int main() {
//    int a, b;
//    cin >> a >> b;  // 输入a和b
//
//    // 1. 筛出所有≤a的质数
//    get_primes(a);
//
//    // 2. 计算组合数C(a,b)的质因数分解
//    for (int i = 0; i < cnt; i++) {
//        int p = primes[i];
//        // 用Legendre公式计算C(a,b)中p的指数
//        sum[i] = get(a, p) - get(b, p) - get(a - b, p);
//        //即a!/(b!*(a-b)!)
//    }
//
//    // 3. 高精度计算最终结果
//    vector<int> res;
//    res.push_back(1);  // 初始化为1
//
//    // 将质因数的乘积计算出来
//    for (int i = 0; i < cnt; i++)
//        for (int j = 0; j < sum[i]; j++)
//            res = mul(res, primes[i]);  // 连乘primes[i]^sum[i]
//
//    // 4. 输出结果（逆序打印）
//    for (int i = res.size() - 1; i >= 0; i--)
//        printf("%d", res[i]);
//    puts("");
//
//    return 0;
//}

//卡特兰数

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//typedef long long LL;  // 使用long long防止溢出
//const int mod = 1e9 + 7;  // 标准质数模数
//
//// 快速幂函数：计算 a^k % p
//int qmi(int a, int k, int p) {
//    int res = 1;
//    while (k) {
//        if (k & 1) res = (LL)res * a % p;  // 如果k的最低位是1，乘上a
//        a = (LL)a * a % p;  // a平方
//        k >>= 1;  // k右移一位
//    }
//    return res;
//}
//
//int main() {
//    int n;
//    cin >> n;  // 输入n，计算第n个卡特兰数
//
//    int a = 2 * n, b = n;  // 卡特兰数公式中的C(2n, n)
//    int res = 1;
//
//    // 计算分子部分：(2n)! / (n)! = (2n) * (2n-1) * ... * (n+1)
//    for (int i = a; i > a - b; i--)
//        res = (LL)res * i % mod;
//
//    // 计算分母部分的逆元：1 / (n)! = (n!)^(mod-2) % mod
//    for (int i = 1; i <= b; i++)
//        res = (LL)res * qmi(i, mod - 2, mod) % mod;
//
//    // 卡特兰数公式的额外除法转乘法：(C(2n, n) / (n+1)) 
//    res = (LL)res * qmi(n + 1, mod - 2, mod) % mod;
//
//    cout << res << endl;  // 输出结果
//    return 0;
//}

//容斥原理

//Nim游戏

//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//    int n;          // 表示石子堆的数量
//    int res = 0;    // 用于存储所有石子堆数量的异或结果（初始化为0）
//
//    scanf("%d", &n); // 输入石子堆的数量n
//    while (n--)    // 循环读取每一堆的石子数量（共n堆）
//    {
//        int x;       // 当前堆的石子数量
//        scanf("%d", &x); // 输入当前堆的石子数量x
//        res ^= x;    // 将当前堆的石子数量x与res进行异或运算（关键步骤）
//    }
//
//    if (res) puts("Yes"); // 如果res不为0，输出"Yes"（先手必胜）
//    else puts("No");      // 否则输出"No"（先手必败）
//
//    return 0;    // 退出程序
//}

//Nim游戏——集合

#include <iostream>
#include <unordered_set>
#include <cstring>
using namespace std;

const int N = 110, M = 10010;  // N: 最大石子堆数, M: 最大石子数
int s[N], f[M];                // s[]: 每次可取的石子数集合, f[]: SG函数值的记忆化存储
int m, n;                      // m: 可取石子数的规则数, n: 实际石子堆数

// 计算x的SG函数值（关键函数）
int sg(int x) {
    if (f[x] != -1) return f[x];  // 记忆化：已计算过则直接返回
    unordered_set<int> S;          // 存储x的所有后继状态的SG值

    // 遍历所有可能的取法
    for (int i = 0; i < m; i++) {
        int sum = s[i];           // 当前规则允许取的石子数
        if (x >= sum) {
            S.insert(sg(x - sum)); // 递归计算后继状态的SG值并存入集合
                                   //S.insert(value) 向集合 S 中插入一个元素 value
        }
    }

    // 求Mex（最小非负整数不在S中）
    for (int i = 0; ; i++) {
        if (!S.count(i)) {         // S.count(value) 检查集合 S 中是否存在元素 value
            return f[x] = i;       // 找到Mex并存入记忆化数组
        }
    }
}

int main() {
    cin >> m;
    for (int i = 0; i < m; i++) cin >> s[i];  // 输入可取石子数的规则
    cin >> n;
    memset(f, -1, sizeof f);       // 初始化SG函数记忆化数组为-1（未计算）
    int res = 0;

    // 处理每堆石子
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;                  // 当前堆的石子数
        res ^= sg(x);              // 异或各堆的SG值
    }

    // 判断胜负
    if (res) puts("Yes");          // 异或结果非零，先手必胜
    else puts("No");               // 否则先手必败
    return 0;
}