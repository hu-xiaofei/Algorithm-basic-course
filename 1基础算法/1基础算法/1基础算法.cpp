#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

//快速排序

//const int N = 1e6 + 10;
//
//int n;
//int q[N];
//
//// 快速排序（Quick Sort）函数
//// 参数：
////   q[]: 待排序的数组
////   l: 当前子数组的左边界（起始索引）
////   r: 当前子数组的右边界（结束索引）
//void quick_sort(int q[], int l, int r)
//{
//    // 递归终止条件：如果子数组长度 <= 1（l >= r），直接返回
//    if (l >= r) return;
//
//    // 选取基准值（pivot），这里选择最左边的元素 q[l]
//    int x = q[l];
//
//    // 初始化两个指针：
//    // i: 从左向右扫描，初始化为 l-1（会在循环中先自增）
//    // j: 从右向左扫描，初始化为 r+1（会在循环中先自减）
//    int i = l - 1, j = r + 1;
//
//    // 开始分区（partition）操作
//    while (i < j)
//    {
//        // 从左向右找第一个 >= x 的元素
//        do i++; while (q[i] < x);
//
//        // 从右向左找第一个 <= x 的元素
//        do j--; while (q[j] > x);
//
//        // 如果 i < j，交换这两个元素，使得左边的 <= x，右边的 >= x
//        if (i < j) swap(q[i], q[j]);
//    }
//
//    // 递归排序左半部分（l 到 j）
//    quick_sort(q, l, j);
//
//    // 递归排序右半部分（j+1 到 r）
//    quick_sort(q, j + 1, r);
//}
//
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//		scanf("%d", &q[i]);
//
//	quick_sort(q, 0, n - 1);
//	for (int i = 0; i < n; i++)
//		printf("%d", q[i]);
//	return 0;
//}

//归并排序

//const int N = 1000010;
//
//int n;
//int q[N], tmp[N];
//
//// 归并排序（Merge Sort）函数
//// 参数：
////   q[]: 待排序的数组
////   l: 当前子数组的左边界（起始索引）
////   r: 当前子数组的右边界（结束索引）
//// 使用全局或外部定义的辅助数组 tmp[] 进行合并操作
//void merge_sort(int q[], int l, int r)
//{
//    // 递归终止条件：如果子数组长度 <= 1（l >= r），直接返回
//    if (l >= r) return;
//
//    // 计算中间点 mid（相当于 (l + r) / 2，但用位运算更高效）
//    int mid = l + r >> 1;
//
//    // 递归排序左半部分 [l, mid]
//    merge_sort(q, l, mid);
//
//    // 递归排序右半部分 [mid + 1, r]
//    merge_sort(q, mid + 1, r);
//
//    // 开始合并（merge）操作
//    int k = 0;          // tmp[] 的索引
//    int i = l;          // 左半部分的起始指针
//    int j = mid + 1;    // 右半部分的起始指针
//
//    // 比较左右两部分的元素，按升序放入 tmp[]
//    while (i <= mid && j <= r)
//        if (q[i] <= q[j]) tmp[k++] = q[i++];  // 左半部分元素较小，放入 tmp
//        else tmp[k++] = q[j++];               // 右半部分元素较小，放入 tmp
//
//    // 如果左半部分还有剩余元素，直接放入 tmp[]
//    while (i <= mid) tmp[k++] = q[i++];
//
//    // 如果右半部分还有剩余元素，直接放入 tmp[]
//    while (j <= r) tmp[k++] = q[j++];
//
//    // 将排序好的 tmp[] 复制回原数组 q[] 的 [l, r] 区间
//    for (i = l, j = 0; i <= r; i++, j++)
//        q[i] = tmp[j];
//}
//
//int main()
//{
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//        scanf("%d", &q[i]);
//
//    merge_sort(q, 0, n - 1);
//
//    for (int i = 0; i < n; i++)
//        printf("%d", q[i]);
//    return 0;
//}

//整数二分查找

//bool check(int x) {/* ... */ } // 检查x是否满足某种性质
//
//// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
//int bsearch_1(int l, int r)
//{
//    while (l < r)
//    {
//        int mid = l + r >> 1;
//        if (check(mid)) r = mid;    // check()判断mid是否满足性质
//        else l = mid + 1;
//    }
//    return l;
//}
//// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
//int bsearch_2(int l, int r)
//{
//    while (l < r)
//    {
//        int mid = l + r + 1 >> 1;
//        if (check(mid)) l = mid;
//        else r = mid - 1;
//    }
//    return l;
//}

//浮点数二分

//bool check(double x) {/* ... */ } // 检查x是否满足某种性质
//
//double bsearch_3(double l, double r)
//{
//    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
//    while (r - l > eps)
//    {
//        double mid = (l + r) / 2;
//        if (check(mid)) r = mid;
//        else l = mid;
//    }
//    return l;
//}

//高精度加法

//#include<vector>
//
//// C = A + B, A >= 0, B >= 0
//vector<int> add(vector<int>& A, vector<int>& B) {
//
//    // 保证 A 是较长的数，简化后续代码
//    if (A.size() < B.size()) return add(B, A);
//
//    vector<int> C;  // 存储结果
//    int t = 0;      // 进位（初始 0）
//
//    // 逐位相加
//    for (int i = 0; i < A.size(); i++) {
//        t += A[i];                   // 加 A 的当前位
//        if (i < B.size()) t += B[i]; // 加 B 的当前位（如果存在）
//        C.push_back(t % 10);         // 当前位结果
//        t /= 10;                    // 计算进位
//    }
//
//    // 处理最高位进位
//    if (t) C.push_back(t);
//
//    return C;
//}
//
//int main()
//{
//	string a, b;
//	vector<int> A, B;
//	cin >> a >> b;//例如输入 "123" 和 "456"
//
//    // 将字符串逆序存储到 vector（低位在前）
//	for (int i = a.size() - 1; i >= 0; i--)
//        A.push_back(a[i] - '0'); // "123" → A = [3, 2, 1]
//	for (int i = b.size() - 1; i >= 0; i--)
//        B.push_back(b[i] - '0'); // "456" → B = [6, 5, 4]
//
//	auto C = add(A, B);
//
//    // 逆序输出（高位在前）
//	for (int i = C.size() - 1; i >= 0; i--)
//        printf("%d", C[i]); // 例如输出 "579"
//	return 0;
//
//}

//高精度减法

//#include<vector>
//
//bool cmp(vector<int>& A, vector<int>& B) {
//    // 比较位数
//    if (A.size() != B.size())
//        return A.size() > B.size();
//
//    // 从高位到低位逐位比较
//    for (int i = A.size() - 1; i >= 0; i--) {
//        if (A[i] != B[i])
//            return A[i] > B[i];
//    }
//    return true;  // A == B
//}
//
//vector<int> sub(vector<int>& A, vector<int>& B) {
//    vector<int> C;
//    int t = 0;  // 借位标志
//
//    for (int i = 0; i < A.size(); i++) {
//        t = A[i] - t;          // 减去借位
//        if (i < B.size())
//            t -= B[i];         // 减去 B 的当前位
//
//        C.push_back((t + 10) % 10);  // 处理负数
//        //push_back：在动态数组末尾添加元素
//        if (t < 0) t = 1;      // 需要借位
//        else t = 0;            // 无需借位
//    }
//
//    // 去除前导零（例如 "100" - "99" = "001" → 清理为 "1"）
//    while (C.size() > 1 && C.back() == 0)
//        C.pop_back(); //pop_back：删除动态数组的最后一个元素
//
//    return C;
//}
//
//int main()
//{
//    string a, b;
//    vector<int> A, B;
//
//    cin >> a >> b;  // 输入字符串形式的大整数
//
//    // 将字符串逆序存储为 vector（低位在前）
//    for (int i = a.size() - 1; i >= 0; i--)
//        A.push_back(a[i] - '0');  // "123" → [3, 2, 1]
//    //a[i] - '0' ：把a[i]由字符变为整型
//    for (int i = b.size() - 1; i >= 0; i--)
//        B.push_back(b[i] - '0');
//
//    // 确保 A >= B，否则需处理负数
//    if (cmp(A, B)) {
//        auto C = sub(A, B);
//        // 逆序输出结果（高位在前）
//        for (int i = C.size() - 1; i >= 0; i--)
//            printf("%d", C[i]);
//    }
//    else {
//        auto C = sub(B, A);
//        printf("-");  // 结果为负
//        for (int i = C.size() - 1; i >= 0; i--)
//            printf("%d", C[i]);
//    }
//}

//高精度乘法（大整数乘小整数）

//#include <vector>
//
////   A: 大整数，逆序存储（如数字123存储为[3, 2, 1]）
////   b: 整数乘数
//vector<int> mul(vector<int>& A, int b) {
//    vector<int> C;  // 存储结果的数组
//    int t = 0;      // 进位，初始化为0
//
//    // 遍历大整数A的每一位，直到所有位处理完且进位为0
//    for (int i = 0; i < A.size() || t; i++) {
//        // 如果当前位在A的范围内，计算当前位与b的乘积并加到进位t上
//        if (i < A.size()) t += A[i] * b;
//        // 将当前位的值（t % 10）存入结果数组C
//        C.push_back(t % 10);
//        // 更新进位t为t / 10
//        t /= 10;
//    }
//
//    // 去除结果中的前导零（例如，输入b=0时可能产生多个0）
//    while (C.size() > 1 && C.back() == 0) C.pop_back();
//
//    return C;  // 返回结果数组C
//}
//
//int main() {
//    string a;  // 存储输入的大整数（字符串形式）
//    int b;     // 存储输入的整数乘数
//    cin >> a >> b;  // 读取输入的大整数a和整数b
//
//    vector<int> A;  // 存储大整数a的逆序数字形式
//    // 将字符串a转换为逆序的数字数组A
//    for (int i = a.size() - 1; i >= 0; i--) {
//        A.push_back(a[i] - '0');  // 将字符转换为数字并逆序存储
//    }
//
//    // 调用mul函数计算A与b的乘积，结果存储在C中（逆序）
//    auto C = mul(A, b);
//
//    // 逆序输出结果数组C，得到正确的乘积结果
//    for (int i = C.size() - 1; i >= 0; i--) {
//        printf("%d", C[i]);
//    }
//
//    return 0;  // 程序正常结束
//}

//高精度除法（大整数除小整数）

//#include <vector>
//#include<algorithm> //支持reverse(C.begin(), C.end())
//
//vector<int> div(vector<int>& A, int b, int& r) {  // r是引用，用于返回余数
//    vector<int> C;  // 存储商的数组
//    r = 0;  // 初始化余数为0
//
//    // 从高位到低位逐位处理（因为A是逆序存储的，所以i从A.size()-1开始）
//    for (int i = A.size() - 1; i >= 0; i--) {
//        r = r * 10 + A[i];  // 当前被除数 = 余数 * 10 + 当前位
//        C.push_back(r / b);  // 当前位的商 = 被除数 / b
//        r %= b;              // 更新余数 = 被除数 % b
//    }
//
//    // 此时商C是高位在前，需要反转（因为主函数中A是逆序存储的）
//    reverse(C.begin(), C.end());
//
//    // 去除前导零（例如，商为[0,1,2] -> [1,2]）
//    while (C.size() > 1 && C.back() == 0) {
//        C.pop_back();
//    }
//
//    return C;  // 返回商（逆序存储）
//}
//
//int main() {
//    string a;  // 存储输入的大整数（字符串形式）
//    int b;     // 存储输入的整数除数
//
//    cin >> a >> b;  // 读取输入的大整数a和除数b
//
//    vector<int> A;  // 存储大整数a的逆序数字形式
//    // 将字符串a转换为逆序的数字数组A（例如，"123" -> [3, 2, 1]）
//    for (int i = a.size() - 1; i >= 0; i--) {
//        A.push_back(a[i] - '0');  // 字符转数字并逆序存储
//    }
//
//    int r;  // 存储余数
//    // 调用div函数计算A / b，商存储在C中（逆序），余数通过引用返回给r
//    auto C = div(A, b, r);
//
//    // 逆序输出商C（因为C是逆序存储的）
//    for (int i = C.size() - 1; i >= 0; i--) {
//        printf("%d", C[i]);
//    }
//    cout << endl << r << endl;  // 输出余数
//
//    return 0;
//}

//前缀和

//const int N = 100010;  // 定义数组的最大长度
//
//int n, m;       // n: 数组元素个数，m: 查询次数
//int a[N], s[N]; // a: 原始数组，s: 前缀和数组
//
//int main() {
//    // 读取输入的数组长度n和查询次数m
//    scanf("%d%d", &n, &m);
//
//    // 读取数组a的n个元素，从a[1]开始存储（方便计算前缀和）
//    for (int i = 1; i <= n; i++) {
//        scanf("%d", &a[i]);
//    }
//
//    // 计算前缀和数组s，s[i]表示a[1]到a[i]的和
//    for (int i = 1; i <= n; i++) {
//        s[i] = s[i - 1] + a[i];  // 递推公式：当前前缀和 = 前一个前缀和 + 当前元素
//    }
//
//    // 处理m次查询
//    while (m--) {
//        int l, r;  // 查询的区间左右端点
//        scanf("%d%d", &l, &r);  // 读取查询区间[l, r]
//
//        // 输出区间和：s[r] - s[l - 1]（利用前缀和快速计算区间和）
//        printf("%d\n", s[r] - s[l - 1]);
//    }
//
//    return 0;
//}

//二维前缀和

//const int N = 1010;  // 定义二维数组的最大尺寸
//
//int n, m, q;         // n: 行数，m: 列数，q: 查询次数
//int a[N][N], s[N][N]; // a: 原始二维数组，s: 二维前缀和数组
//
//int main() {
//    // 读取输入的行数n、列数m和查询次数q
//    scanf("%d%d%d", &n, &m, &q);
//
//    // 读取二维数组a的每个元素（从a[1][1]开始存储）
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            scanf("%d", &a[i][j]);
//        }
//    }
//
//    // 计算二维前缀和数组s
//    // s[i][j]表示从a[1][1]到a[i][j]的子矩阵和
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            // 递推公式：当前前缀和 = 上方前缀和 + 左侧前缀和 - 左上角前缀和 + 当前元素
//            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
//        }
//    }
//
//    // 处理q次查询
//    while (q--) {
//        int x1, y1, x2, y2;  // 查询的子矩阵左上角(x1,y1)和右下角(x2,y2)
//        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
//
//        // 计算子矩阵和：利用二维前缀和公式
//        // 和 = s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]
//        printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
//    }
//
//    return 0;  // 程序正常结束
//}

//差分

//const int N = 100010;  // 定义数组的最大长度
//
//int n, m;       // n: 数组长度，m: 操作次数
//int a[N], b[N]; // a: 原始数组，b: 差分数组
//
//// 例如：原数组 a = [3, 5, 2, 7] 
//// 则：  差分数组 b = [3, 2, -3, 5]（因为 5 - 3 = 2，2 - 5 = -3，7 - 2 = 5）
//
//// 差分操作函数：在区间 [l, r] 的每个元素上加 c
//void insert(int l, int r, int c) {
//    b[l] += c;      // 左边界加 c
//    b[r + 1] -= c;   // 右边界后一位减 c（抵消多余的影响）
//}
//
//int main() {
//    // 输入数组长度 n 和操作次数 m
//    scanf("%d%d", &n, &m);
//
//    // 读取原始数组 a（从 a[1] 开始存储）
//    for (int i = 1; i <= n; i++) {
//        scanf("%d", &a[i]);
//    }
//
//    // 初始化差分数组 b
//    // 将 a[i] 看作对区间 [i, i] 的插入操作
//    for (int i = 1; i <= n; i++) {
//        insert(i, i, a[i]);
//    }
//
//    // 处理 m 次操作
//    while (m--) {
//        int l, r, c;  // 操作区间 [l, r] 和值 c
//        scanf("%d%d%d", &l, &r, &c);
//        insert(l, r, c);  // 在差分数组上记录区间操作
//    }
//
//    // 通过差分数组 b 计算最终数组（前缀和操作）
//    for (int i = 1; i <= n; i++) {
//        b[i] += b[i - 1];  // 前缀和：b[i] = b[1] + b[2] + ... + b[i]
//    }
//
//    // 输出最终数组
//    for (int i = 1; i <= n; i++) {
//        printf("%d ", b[i]);
//    }
//
//    return 0;
//}

//矩阵差分

//using namespace std;
//
//const int N = 1010;  // 定义一个常量N，用于表示数组的大小，这里设为1010，可根据实际需求调整
//
//int n, m, q;  // 定义变量n（矩阵行数）、m（矩阵列数）、q（操作次数）
//int a[N][N], b[N][N];  // 定义两个二维数组，a用于存储原始矩阵，b用于存储差分矩阵
//
//// 定义二维差分的插入函数，用于对差分矩阵进行操作
//// x1, y1 表示子矩阵左上角坐标，x2, y2 表示子矩阵右下角坐标，c 表示要增加的值
//void insert(int x1, int y1, int x2, int y2, int c)
//{
//    b[x1][y1] += c;  // 对差分矩阵中(x1, y1)位置增加c，影响后续求和区域的值
//    b[x2 + 1][y1] -= c;  // 对差分矩阵中(x2 + 1, y1)位置减去c，消除超出子矩阵右边界的影响
//    b[x1][y2 + 1] -= c;  // 对差分矩阵中(x1, y2 + 1)位置减去c，消除超出子矩阵下边界的影响
//    b[x2 + 1][y2 + 1] += c;  // 对差分矩阵中(x2 + 1, y2 + 1)位置增加c，恢复右下角区域的影响
//}
//
//int main()
//{
//    scanf("%d%d%d", &n, &m, &q);  // 从输入读取矩阵行数n、列数m和操作次数q
//
//    for (int i = 1; i <= n; i++)  // 遍历矩阵的行
//    {
//        for (int j = 1; j <= m; j++)  // 遍历矩阵的列
//        {
//            scanf("%d", &a[i][j]);  // 读取原始矩阵a的每个元素
//        }
//    }
//
//    for (int i = 1; i <= n; i++)  // 遍历矩阵的行
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            insert(i, j, i, j, a[i][j]);  // 将原始矩阵元素逐个插入到差分矩阵中，相当于初始化差分矩阵
//        }
//    }
//
//    while (q--)  // 循环q次，进行q次操作
//    {
//        int x1, y1, x2, y2, c;
//        cin >> x1 >> y1 >> x2 >> y2 >> c;  // 读取每次操作的子矩阵坐标和增加的值
//        insert(x1, y1, x2, y2, c);  // 对差分矩阵进行操作
//    }
//
//    for (int i = 1; i <= n; i++)  // 遍历矩阵的行
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            // 通过前缀和的方式，由差分矩阵还原出最终矩阵，利用容斥原理
//            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
//        }
//    }
//
//    for (int i = 1; i <= n; i++)  // 遍历矩阵的行
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            printf("%d ", b[i][j]);  // 输出最终矩阵的每个元素
//        }
//        puts("");  // 换行
//    }
//
//    return 0;
//}

//双指针算法基础题

//#include <string.h>
//
//int main()
//{
//    char str[1000];  // 定义一个字符数组用于存储输入的字符串
//    //gets(str);       获取用户输入的字符串（注意：gets()函数不安全，不建议使用）
//    cin.getline(str, sizeof(str));  // 安全读取，自动处理缓冲区大小
//    int n = strlen(str);  // 计算输入字符串的长度
//
//    // 使用双指针算法遍历字符串
//    for (int i = 0; i < n; i++)
//    {
//        int j = i;  // 初始化指针j，用于标记单词的结束位置
//        // 移动指针j，直到遇到空格或字符串结束
//        while (j < n && str[j] != ' ') j++;
//
//        // 输出当前单词（从i到j-1的字符）
//        for (int k = i; k < j; k++) cout << str[k];
//        cout << endl;  // 输出换行符，分隔单词
//
//        i = j;  // 更新指针i到j的位置，跳过已处理的单词
//    }
//    return 0;
//}

//最长连续不重复子序列

//const int N = 100010;  // 定义常量 N，表示数组的最大可能长度
//
//int n;          // 存储输入的序列长度
//int a[N];       // 存储输入的整数序列
//int s[N];       // 哈希表，用于记录当前窗口中每个数字的出现次数
//
//int main()
//{
//    cin >> n;  // 输入序列的长度 n
//    for (int i = 0; i < n; i++) cin >> a[i];  // 输入序列的每个元素
//
//    int res = 0;  // 存储最终结果（最长不重复子序列的长度）
//
//    // 双指针算法：i 是右指针，j 是左指针
//    for (int i = 0, j = 0; i < n; i++)
//    {
//        s[a[i]]++;  // 将当前数字 a[i] 的出现次数 +1
//
//        // 如果 a[i] 的出现次数 > 1，说明有重复，移动左指针 j 直到无重复
//        while (s[a[i]] > 1)
//        {
//            s[a[j]]--;  // 将 a[j] 移出当前窗口（出现次数 -1）
//            j++;        // 左指针右移
//        }
//
//        // 更新最长子序列长度（i - j + 1 是当前窗口的长度）
//        res = max(res, i - j + 1);
//    }
//
//    cout << res << endl;  // 输出结果
//    return 0;
//}

//位运算：二进制中1的个数

//求n的第k位数字: n >> k & 1
//返回n的最后一位1：lowbit(n) = n & -n

//离散化（模板）

//vector<int> alls; // 存储所有待离散化的值
//sort(alls.begin(), alls.end()); // 将所有值排序
//alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素
//
//// 二分求出x对应的离散化的值
//int find(int x) // 找到第一个大于等于x的位置
//{
//    int l = 0, r = alls.size() - 1;
//    while (l < r)
//    {
//        int mid = l + r >> 1;
//        if (alls[mid] >= x) r = mid;
//        else l = mid + 1;
//    }
//    return r + 1; // 映射到1, 2, ...n
//}

//离散化——区间和

//#include <vector>
//#include <algorithm>
//
//typedef pair<int, int> PII;  // 定义pair类型别名，用于存储操作对
//
//const int N = 300010;  // 定义最大可能的数据范围
////插入n次，查询m次（2m个坐标），1<n,m<100000，所以最多300000个坐标
//
//int n, m;       // n表示插入操作次数，m表示查询操作次数
//int a[N], s[N]; // a数组存储离散化后的值，s数组是前缀和数组
//
//vector<int> alls;      // 存储所有需要离散化的坐标
//vector<PII> add, query; // add存储插入操作，query存储查询操作
//
////将原始的大范围坐标x映射到紧凑的离散化后的索引位置
//int find(int x)
//{
//    int l = 0, r = alls.size() - 1;
//    while (l < r)
//    {
//        int mid = l + r >> 1;  // 等价于(l + r)/2，二分查找
//        if (alls[mid] >= x) r = mid;  // 如果中间值大于等于x，缩小右边界
//        else l = mid + 1;      // 否则缩小左边界
//    }
//    return r + 1;  // 返回x在离散化数组中的位置（从1开始计数）
//}
//
//int main()
//{
//    //输入处理
//    cin >> n >> m;
//    for (int i = 0; i < n; i++)
//    {
//        int x, c;
//        cin >> x >> c;
//        add.push_back({ x, c });  // 存储插入操作：在位置x加上值c
//        alls.push_back(x);      // 将x加入待离散化列表
//    }
//
//
//    for (int i = 0; i < m; i++)
//    {
//        int l, r;  // 注意：原始代码中有拼写错误，应该是l不是1
//        cin >> l >> r;
//        query.push_back({ l, r });  // 存储查询操作：查询区间[l,r]
//        alls.push_back(l);        // 将查询区间端点加入待离散化列表
//        alls.push_back(r);
//    }
//
//    //离散化处理：排序所有坐标，去重，将原始插入操作映射到离散化后的位置
//    // 去重
//    sort(alls.begin(), alls.end());  // 对所有坐标排序
//    alls.erase(unique(alls.begin(), alls.end()), alls.end());  // 去除重复坐标
//
//    // 处理插入
//    for (auto item : add)
//    {
//        int x = find(item.first);  // 找到x的离散化位置
//        a[x] += item.second;       // 在离散化后的位置上加上值
//    }
//
//    // 预处理前缀和
//    for (int i = 1; i <= alls.size(); i++)
//        s[i] = s[i - 1] + a[i];  // 计算前缀和数组
//
//    // 处理询问
//    for (auto item : query)
//    {
//        int l = find(item.first), r = find(item.second);  // 离散化查询区间
//        cout << s[r] - s[l - 1] << endl;  // 使用前缀和快速计算区间和
//    }
//
//    return 0;
//}

//区间合并

#include <algorithm>
#include <vector>

typedef pair<int, int> PII;  // 定义pair类型别名，用于表示区间[first,second]

const int N = 100010;  // 定义最大可能的区间数量

int n;                 // 存储输入的区间数量
vector<PII> segs;      // 存储所有区间的向量

void merge(vector<PII>& segs)
{
    vector<PII> res;  // 存储合并后的结果区间

    sort(segs.begin(), segs.end());  // 首先对所有区间按左端点排序
    //默认按元素的 < 运算符比较（对 pair<int, int> 来说，先比较 first，再比较 second）

    int st = -2e9, ed = -2e9;  // 初始化当前合并区间的起点和终点为极小值
    for (auto seg : segs)       // 遍历所有区间
    {
        if (ed < seg.first)    // 如果当前区间与待合并区间无重叠
        {
            if (st != -2e9) res.push_back({ st, ed });  // 如果不是初始状态，保存当前合并区间
            st = seg.first, ed = seg.second;  // 开始一个新的合并区间
        }
        else  // 如果有重叠
        {
            ed = max(ed, seg.second);  // 合并区间，取右端点的最大值
        }
    }

    if (st != -2e9) res.push_back({ st, ed });  // 保存最后一个合并区间

    segs = res;  // 用合并后的结果替换原区间集合
}

int main()
{
    cin >> n;  // 输入区间数量

    for (int i = 0; i < n; i++)
    {
        int l, r;  // 注意：原始代码中有拼写错误，应该是l不是1
        cin >> l >> r;
        segs.push_back({ l, r });  // 存储每个区间
    }

    merge(segs);  // 调用合并函数

    cout << segs.size() << endl;  // 输出合并后的区间数量
    return 0;
}