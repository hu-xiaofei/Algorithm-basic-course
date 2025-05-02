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