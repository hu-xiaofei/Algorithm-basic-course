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

#include<vector>

bool cmp(vector<int>& A, vector<int>& B) {
    // 比较位数
    if (A.size() != B.size())
        return A.size() > B.size();

    // 从高位到低位逐位比较
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i])
            return A[i] > B[i];
    }
    return true;  // A == B
}

vector<int> sub(vector<int>& A, vector<int>& B) {
    vector<int> C;
    int t = 0;  // 借位标志

    for (int i = 0; i < A.size(); i++) {
        t = A[i] - t;          // 减去借位
        if (i < B.size())
            t -= B[i];         // 减去 B 的当前位

        C.push_back((t + 10) % 10);  // 处理负数
        //push_back：在动态数组末尾添加元素
        if (t < 0) t = 1;      // 需要借位
        else t = 0;            // 无需借位
    }

    // 去除前导零（例如 "100" - "99" = "001" → 清理为 "1"）
    while (C.size() > 1 && C.back() == 0)
        C.pop_back(); //pop_back：删除动态数组的最后一个元素

    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b;  // 输入字符串形式的大整数

    // 将字符串逆序存储为 vector（低位在前）
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');  // "123" → [3, 2, 1]
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    // 确保 A >= B，否则需处理负数
    if (cmp(A, B)) {
        auto C = sub(A, B);
        // 逆序输出结果（高位在前）
        for (int i = C.size() - 1; i >= 0; i--)
            printf("%d", C[i]);
    }
    else {
        auto C = sub(B, A);
        printf("-");  // 结果为负
        for (int i = C.size() - 1; i >= 0; i--)
            printf("%d", C[i]);
    }
}