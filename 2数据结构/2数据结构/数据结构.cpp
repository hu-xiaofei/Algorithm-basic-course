#define _CRT_SECURE_NO_WARNINGS
#include<iostream>;
using namespace std;

//单链表

//const int N = 100010;  // 定义链表最大长度
//
//// 全局变量定义
//int head, e[N], ne[N], idx;
//// head - 头节点的下标
//// e[i] - 节点i存储的值
//// ne[i] - 节点i的next指针(存储下一个节点的下标)
//// idx - 当前可用的节点索引
//
//// 初始化链表
//void init()
//{
//    head = -1;  // 头节点初始为-1，表示空链表
//    idx = 0;    // 从0开始分配节点
//}
//
//// 在链表头部插入节点
//void add_to_head(int x)
//{
//    e[idx] = x;    // 存储值x到新节点
//    ne[idx] = head; // 新节点的next指向原头节点
//    head = idx;     // 更新头节点为新节点
//    idx++;          // 移动到下一个可用索引
//}
//
//// 在指定位置k后插入节点
//void add(int k, int x)
//{
//    e[idx] = x;        // 存储值x到新节点
//    ne[idx] = ne[k];    // 新节点的next指向k节点原来的next
//    ne[k] = idx;        // k节点的next指向新节点
//    idx++;              // 移动到下一个可用索引
//}
//
//// 删除指定位置k后的节点
//void remove(int k)
//{
//    ne[k] = ne[ne[k]];  // 将k节点的next指向k+2节点，相当于跳过了k+1节点
//}
//
//int main()
//{
//    int m;
//    cin >> m;  // 输入操作次数m
//
//    init();  // 初始化链表
//
//    while (m--)  // 循环处理m个操作
//    {
//        int k, x;
//        char op;
//
//        cin >> op;  // 输入操作类型
//        if (op == 'H')  // 如果操作是在头部插入
//        {
//            cin >> x;  // 输入要插入的值x
//            add_to_head(x);  // 调用头部插入函数
//        }
//        else if (op == 'D')  // 如果操作是删除
//        {
//            cin >> k;  // 输入要删除的位置k
//            if (!k) head = ne[head];  // 如果k为0，删除头节点
//            remove(k - 1);  // 否则删除第k-1个节点后面的节点(因为数组下标从0开始)
//        }
//        else  // 其他情况视为在指定位置插入
//        {
//            cin >> k >> x;  // 输入位置k和值x
//            add(k - 1, x);  // 在第k-1个节点后插入新节点
//        }
//    }
//
//    // 遍历并输出链表
//    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
//    cout << endl;
//}

//双链表

////可以用结构体，但是比较复杂，不如直接用数组
//const int N = 100010;  // 定义链表最大容量
//
//int m;                 // 操作次数
//int e[N], l[N], r[N],  // e[]存储节点值，l[]存储左指针，r[]存储右指针
//int idx;               // 当前可用的节点索引
//
//// 初始化双链表
//void init()
//{
//    // 使用两个哨兵节点：0号节点作为左端点，1号节点作为右端点
//    // 初始时，0号节点的右指针指向1号节点
//    // 1号节点的左指针指向0号节点
//    r[0] = 1, l[1] = 0;
//    idx = 2;  // 前两个索引(0和1)已被占用，从2开始分配新节点
//}
//
//// 在节点k的右侧插入一个值为x的新节点
//void add(int k, int x)
//{
//    e[idx] = x;     // 存储值x到新节点
//    r[idx] = r[k];  // 新节点的右指针指向k节点原来的右节点
//    l[idx] = k;     // 新节点的左指针指向k节点
//    l[r[k]] = idx;  // k节点原来右节点的左指针指向新节点
//    r[k] = idx;     // k节点的右指针指向新节点
//    idx++;          // 移动到下一个可用索引
//}
//
//// 删除节点k
//void remove(int k)
//{
//    r[l[k]] = r[k];  // k节点左节点的右指针指向k的右节点
//    l[r[k]] = l[k];  // k节点右节点的左指针指向k的左节点
//}

//栈

//const int N = 100010;  // 定义栈的最大容量
//
//int stk[N],  // 用于存储栈元素的数组
//	tt;      // 栈顶指针（top pointer），指向当前栈顶元素的位置
//
//// 插入元素（入栈操作）
//stk[++tt] = x;
//// 1. 先将栈顶指针tt加1（前++操作）
//// 2. 然后将元素x存储到新的栈顶位置
//// 相当于：tt = tt + 1; stk[tt] = x;
//
//// 弹出元素（出栈操作）
//tt--;
//// 简单地将栈顶指针减1
//// 虽然原数据仍在数组中，但不再被视为栈的一部分
//
//// 判断栈是否为空
//if (tt > 0) not empty  // 栈不为空
//else empty             // 栈为空
//// 当tt > 0时表示栈中有元素
//// 当tt == 0时表示栈为空（因为插入时是先++再赋值）
//
//// 获取栈顶元素
//stk[tt];
//// 直接返回栈顶指针指向的元素
//// 注意：在访问前应该先检查栈是否为空

//队列、

//// 定义队列数组和指针
//int q[N],     // 用于存储队列元素的数组
//hh,       // 队头指针（head），指向队列第一个元素
//tt = -1;  // 队尾指针（tail），指向队列最后一个元素，初始化为-1表示空队列
//
//// 在队尾插入元素（入队操作）
//q[++tt] = x;
//// 1. 先将队尾指针tt加1（前++操作）
//// 2. 然后将元素x存储到新的队尾位置
//// 例如：初始tt=-1，插入第一个元素后tt=0，元素存储在q[0]
//
//// 在队头弹出元素（出队操作）
//hh++;
//// 简单地将队头指针加1
//// 虽然原数据仍在数组中，但不再被视为队列的一部分
//
//// 判断队列是否为空
//if (hh <= tt) not empty  // 队列不为空（队头指针<=队尾指针）
//else empty               // 队列为空
//// 当hh > tt时表示队列中没有元素
//
//// 取出队头元素（不删除）
//q[hh]
//// 直接返回队头指针指向的元素
//// 注意：在访问前应该先检查队列是否为空

//单调栈————寻找每个元素左边第一个比它小的数

//const int n = 100010;  // 定义最大数据量
//
//int n;                 // 输入的元素个数
//int stk[n], tt;        // 栈数组和栈顶指针(初始tt=0)
//
//int main()
//{
//    scanf("%d", &n);   // 读取元素个数n
//
//    for (int i = 0; i < n; i++)  // 遍历每个元素
//    {
//        int x;
//        scanf("%d", &x);  // 读取当前元素x
//
//        // 维护单调递增栈：弹出所有大于等于当前x的元素
//        // 这样栈顶就是第一个小于x的元素
//        while (tt && stk[tt] >= x) tt--;
//
//        // 如果栈不为空，输出栈顶元素（左边第一个比x小的数）
//        if (tt) printf("%d ", stk[tt]);
//        // 否则输出-1（没有比x小的元素）
//        else printf("-1 ");
//
//        // 将当前元素x压入栈中
//        stk[++tt] = x;
//    }
//
//    return 0;
//}

//单调队列————滑动窗口求最大最小值

//const int N = 1000010;  // 定义数组的最大长度
//
//int n, k;       // n: 数组长度, k: 窗口大小
//int a[N], q[N]; // a: 存储输入数组, q: 单调队列(存储的是下标)
//
//int main()
//{
//    scanf("%d%d", &n, &k);  // 读取数组长度n和窗口大小k
//    for (int i = 0; i < n; i++) scanf("%d", &a[i]); // 读取数组元素
//
//    // 第一部分：求滑动窗口最小值
//    int hh = 0, tt = -1; // 初始化队列头(hh)和尾(tt)指针
//    for (int i = 0; i < n; i++)
//    {
//        // 如果队列不为空（hh <= tt）且队头元素已不在当前窗口内（i - k + 1 > q[hh]），则移动队头指针
//        if (hh <= tt && i - k + 1 > q[hh]) hh++;
//
//        // 当队列不为空（hh <= tt）且队尾元素大于等于当前元素时，弹出队尾
//        while (hh <= tt && a[q[tt]] >= a[i]) tt--;
//
//        q[++tt] = i; // 将当前元素下标加入队尾
//
//        // 当窗口形成时(即i >= k-1)，输出（如果窗口小于k，则不输出）
//        if (i >= k - 1) printf("%d ", a[q[hh]]);
//    }
//    puts(""); // 输出换行
//
//    // 第二部分：求滑动窗口最大值
//    hh = 0, tt = -1; // 重新初始化队列
//    for (int i = 0; i < n; i++)
//    {
//        // 同上，判断队头是否滑出窗口
//        if (hh <= tt && i - k + 1 > q[hh]) hh++;
//
//        // 维护单调递减队列
//        // 当队列不为空且队尾元素小于等于当前元素时，弹出队尾
//        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
//
//        q[++tt] = i; // 将当前元素下标加入队尾
//
//        // 当窗口形成时，输出当前窗口最大值(队头元素)
//        if (i >= k - 1) printf("%d ", a[q[hh]]);
//    }
//    puts(""); // 输出换行
//
//    return 0;
//}

//KMP算法

//#include <iostream>
//using namespace std;
//
//const int N = 10010, M = 100010;  // 定义数组大小常量，N是模式串最大长度，M是主串最大长度
//int n, m;                         // n-模式串长度，m-主串长度
//char p[N], s[M];                   // p-模式串，s-主串（都从下标1开始存储）
//int ne[N];                         // next数组，用于KMP算法,（直接写next[]可能会报错）
//
//int main()
//{
//    // 输入数据：模式串长度n，模式串p（从p[1]开始存储），主串长度m，主串s（从s[1]开始存储）
//    cin >> n >> p + 1 >> m >> s + 1;
//
//    // 构建next数组的过程（预处理模式串）
//    for (int i = 2, j = 0; i <= n; i++)
//    {
//        // 当j不为0且当前字符不匹配时，回退j到ne[j]
//        while (j && p[i] != p[j + 1]) j = ne[j];
//        // 如果当前字符匹配，j向前移动
//        if (p[i] == p[j + 1]) j++;
//        // 记录当前位置i的next值
//        ne[i] = j;
//    }
//
//    // KMP匹配过程
//    for (int i = 1, j = 0; i <= m; i++)
//    {
//        // 当j不为0且当前字符不匹配时，利用next数组回退j
//        while (j && s[i] != p[j + 1]) j = ne[j];
//        // 如果当前字符匹配，j向前移动
//        if (s[i] == p[j + 1]) j++;
//        // 如果j等于模式串长度n，说明找到完整匹配
//        if (j == n)
//        {
//            // 输出匹配的起始位置（从0开始计数）
//            printf("%d ", i - n);
//            // 回退j以继续寻找其他可能的匹配
//            j = ne[j];
//        }
//    }
//
//    return 0;
//}

//Trie

////Trie:高效地存储和查找字符串集合的数据结构
//const int N = 100010;  // 定义Trie树的最大节点数量
//
//int son[N][26], cnt[N], idx;
//// son[N][26]: 每个节点最多有26个子节点（对应26个小写字母）
//// cnt[N]: 以当前节点结尾的单词数量
//// idx: 当前可用的节点编号（从1开始分配）
//
////插入操作
//void insert(char str[])
//{
//    int p = 0;  // 从根节点开始（根节点编号为0）
//    for (int i = 0; str[i]; i++)  // 遍历字符串中的每个字符
//    {
//        int u = str[i] - 'a';  // 将字符转换为0-25的数字（a-z）
//        if (!son[p][u]) son[p][u] = ++idx;  // 如果不存在对应子节点，则创建新节点
//        p = son[p][u];  // 移动到子节点
//    }
//    cnt[p]++;  // 标记单词结束，增加计数器
//}
//
////查询操作
//int query(char str[])
//{
//    int p = 0;  // 从根节点开始
//    for (int i = 0; str[i]; i++)  // 遍历字符串中的每个字符
//    {
//        int u = str[i] - 'a';  // 将字符转换为0-25的数字
//        if (!son[p][u]) return 0;  // 如果路径不存在，返回0（表示没找到）
//        p = son[p][u];  // 移动到子节点
//    }
//    return cnt[p];  // 返回以该节点结尾的单词数量
//}
//
//int main()
//{
//    int n;
//    scanf("%d", &n);  // 输入操作数量
//    while (n--)
//    {
//        char op[2];
//        char str[N];  // 这里代码中缺少str的定义，实际应该添加
//        scanf("%s%s", op, str);  // 输入操作类型和字符串
//        if (op[0] == 'I') insert(str);  // 插入操作
//        else printf("%d\n", query(str));  // 查询操作并输出结果
//    }
//    return 0;
//}

//并查集

//const int N = 100010;  // 定义最大元素数量
//int n, m;              // n-元素数量，m-操作数量
//int p[N];              // 父节点数组，用于表示每个元素的父节点
//
//// 查找函数：返回x的祖宗节点 + 路径压缩
//int find(int x) {
//    // 如果x不是自己的父节点（不是根节点）
//    if (p[x] != x)
//        p[x] = find(p[x]);  // 递归查找祖宗节点，并进行路径压缩
//    return p[x];            // 返回祖宗节点
//}
//
//int main() {
//    scanf("%d%d", &n, &m);  // 读取元素数量n和操作数量m
//
//    // 初始化并查集，每个元素的父节点指向自己
//    for (int i = 1; i <= n; i++) p[i] = i;
//
//    while (m--) {  // 处理每个操作
//        char op[2];  // 操作类型
//        int a, b;    // 操作涉及的两个元素
//        scanf("%s%d%d", op, &a, &b);  // 读取操作和元素
//        //推荐使用“%d”来读取字符串，因为如果用“%c”可能会读取空格或者回车
//
//        if (op[0] == 'M') {  // 如果是合并操作
//            p[find(a)] = find(b);  // 将a的祖宗节点的父节点设为b的祖宗节点
//        }
//        else {  // 如果是查询操作
//            // 判断a和b是否属于同一集合
//            if (find(a) == find(b))
//                puts("Yes");  // 属于同一集合
//            else
//                puts("No");   // 不属于同一集合
//        }
//    }
//
//    return 0;
//}

//手写堆

//#include <algorithm>  // 包含swap函数
//
//const int N = 100010;  // 定义堆的最大容量
//
//int n, m;      // n-堆中元素数量，m-要输出的前m个最小元素
//int h[N];      // 堆的存储数组(从索引1开始使用)
//int heap_size;      // 当前堆的大小
//
//// 下沉操作：调整以u为根的子树，使其满足堆的性质
//void down(int u) {
//    int t = u;  // t记录最小值的索引
//    // 如果左子节点存在且比当前节点小
//    if (u * 2 <= heap_size && h[u * 2] < h[t]) t = u * 2;
//    // 如果右子节点存在且比当前节点小
//    if (u * 2 + 1 <= heap_size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
//    // 如果最小值不是当前节点
//    if (u != t) {
//        swap(h[u], h[t]);  // 交换当前节点与最小值节点
//        down(t);           // 递归调整交换后的子树
//    }
//}
//
//// 上浮操作：将节点u向上调整到合适位置，以维护堆的性质
//void up(int u)
//{
//    // 当u不是根节点(u/2是父节点)，且父节点的值大于当前节点时
//    while (u / 2 && h[u / 2] > h[u])
//    {
//        // 交换当前节点与其父节点的值
//        swap(h[u / 2], h[u]);
//        // 将当前节点指针移动到父节点位置
//        u /= 2;
//    }
//}
//
//int main() {
//    scanf("%d%d", &n, &m);  // 读取元素数量n和要输出的前m个元素
//    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);  // 读取堆元素
//    heap_size = n;  // 初始化堆大小
//
//    // 建堆：从最后一个非叶子节点开始向下调整
//    // 时间复杂度O(n)，比逐个插入的O(nlogn)更优
//    for (int i = n / 2; i; i--) down(i);
//
//    // 输出前m个最小元素(堆排序的核心过程)
//    while (m--) {
//        printf("%d ", h[1]);  // 输出堆顶(当前最小值)
//        h[1] = h[heap_size];      // 用最后一个元素替换堆顶
//        heap_size--;              // 堆大小减1
//        down(1);             // 从新的堆顶开始向下调整
//    }
//
//    return 0;
//}

//堆——进阶版

//#include <algorithm>
//#include <string.h>
//
//const int N = 100010;
//
//int h[N], ph[N], hp[N], heap_size;
//// h[N] 是堆数组，存储实际的元素值
//// ph[N] ("pointer to heap") 保存第k个插入的点在堆中的位置
//// hp[N] ("heap to pointer") 保存堆中某个点是第几个插入的
//// heap_size 是当前堆的大小
//
//void heap_swap(int a, int b)
//{
//    swap(ph[hp[a]], ph[hp[b]]); // 交换两个元素在ph数组中的位置记录
//    swap(hp[a], hp[b]);         // 交换两个元素的插入次序记录
//    swap(h[a], h[b]);           // 交换两个元素的实际值
//}
//
//void down(int u)
//{
//    int t = u; // t保存最小值的下标，初始为当前节点
//    // 与左子节点比较
//    if (u * 2 <= heap_size && h[u * 2] < h[t]) t = u * 2;
//    // 与右子节点比较
//    if (u * 2 + 1 <= heap_size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
//    if (u != t) // 如果子节点比当前节点小
//    {
//        heap_swap(u, t); // 交换两者
//        down(t);        // 递归调整
//    }
//}
//
//void up(int u)
//{
//    while (u / 2 && h[u / 2] > h[u]) // 如果父节点存在且比当前节点大
//    {
//        heap_swap(u / 2, u); // 交换两者
//        u /= 2;              // 继续向上检查
//    }
//}
//
//int main()
//{
//    int n, m = 0; // n是操作次数，m记录插入的序号
//    scanf("%d", &n);
//
//    while (n--)
//    {
//        char op[10];
//        int k, x;
//
//        scanf("%s", op);
//        if (!strcmp(op, "I")) // 插入操作    strcmp(op, "I") 是 C/C++ 标准库函数，用于比较两个字符串 op 和 "I" 是否相同
//        {
//            scanf("%d", &x);
//            heap_size++; // 堆大小增加
//            m++;    // 插入序号增加
//            ph[m] = heap_size, hp[heap_size] = m; // 记录插入位置关系
//            h[heap_size] = x;    // 将x放入堆尾
//            up(heap_size);       // 上浮调整堆
//        }
//        else if (!strcmp(op, "PM")) printf("%d\n", h[1]); // 输出堆顶（最小值）
//        else if (!strcmp(op, "DM")) // 删除堆顶
//        {
//            heap_swap(1, heap_size); // 将堆顶与堆尾交换
//            heap_size--;             // 堆大小减小
//            down(1);           // 下沉调整堆
//        }
//        else if (!strcmp(op, "D")) // 删除第k个插入的元素
//        {
//            scanf("%d", &k);
//            k = ph[k];          // 找到第k个插入的元素在堆中的位置
//            heap_swap(k, heap_size); // 与堆尾交换
//            heap_size--;            // 堆大小减小
//            down(k), up(k);     // 调整堆（只需执行其中一个，这里都调用保证正确）
//        }
//        else // 修改第k个插入的元素
//        {
//            scanf("%d%d", &k, &x);
//            k = ph[k];      // 找到第k个插入的元素在堆中的位置
//            h[k] = x;       // 修改值
//            down(k), up(k); // 调整堆
//        }
//    }
//}

//哈希表——拉链法

//#include <cstring> // memset需要
//
//const int N = 100003;  // 哈希表的大小，通常选择一个质数以减少冲突
//
//int h[N], e[N], ne[N], idx;  // h:哈希表头指针数组, e:存储元素值, ne:存储下一个节点索引, idx:当前可用索引
//
//void insert(int x)
//{
//    int k = (x % N + N) % N;  // 计算哈希值，确保k为正数
//    e[idx] = x;               // 存储元素值x到e数组
//    ne[idx] = h[k];           // 新节点的next指向当前链表的头节点
//    h[k] = idx++;             // 更新头节点为当前新节点，并递增idx
//}
//
//bool find(int x)
//{
//    int k = (x % N + N) % N;  // 计算哈希值，与insert中一致
//    for (int i = h[k]; i != -1; i = ne[i])  // 遍历链表
//        if (e[i] == x)        // 如果找到相同的值
//            return true;       // 返回true
//
//    return false;             // 遍历完链表没找到，返回false
//}
//
//int main()
//{
//    int n;
//    scanf("%d", &n);          // 读取操作数量
//
//    memset(h, -1, sizeof h);  // 初始化哈希表头指针为-1（表示空链表）
//
//    while (n--)               // 处理n个操作
//    {
//        char op[2];
//        int x;
//        scanf("%s%d", op, &x);  // 读取操作类型和数值
//
//        if (*op == 'I')         // 如果是插入操作
//            insert(x);          // 调用插入函数
//        else                    // 否则是查询操作
//        {
//            if (find(x))        // 调用查找函数
//                puts("yes");    // 找到输出"yes"
//            else
//                puts("No");    // 未找到输出"No"（注意大小写不一致）
//        }
//    }
//
//    return 0;
//}

//哈希表——开放寻址法

//#include <cstring>
//
//const int N = 200003, null = 0x3f3f3f3f;
//// N: 哈希表大小，通常取数据规模的2-3倍的质数
//// null: 特殊值，表示空位置，0x3f3f3f3f是一个很大的数，通常不会用作实际数据
//
//int h[N];  // 哈希表数组
//
//int find(int x) //(蹲坑法寻找)
//{
//    int k = (x % N + N) % N;  // 计算初始哈希值，确保为正数
//
//    // 线性探测查找位置
//    while (h[k] != null && h[k] != x)  // 当位置不空且不是目标值时继续查找
//    {
//        k++;          // 检查下一个位置
//        if (k == N)   // 如果到达数组末尾
//            k = 0;    // 回到数组开头
//    }
//    return k;  // 返回找到的位置（可能是空位或目标位置）
//}
//
//int main()
//{
//    int n;
//    scanf("%d", &n);  // 读取操作数量
//
//    // 初始化哈希表，所有位置设为null
//    memset(h, 0x3f, sizeof h);  // 0x3f是0x3f3f3f3f的缩写形式
//
//    while (n--)  // 处理n个操作
//    {
//        char op[2];
//        int x;
//        scanf("%s%d", op, &x);  // 读取操作类型和数值
//
//        int k = find(x);  // 查找x应该在的位置
//
//        if (*op == 'I')   // 插入操作
//            h[k] = x;     // 在找到的位置插入x
//        else              // 查询操作
//        {
//            if (h[k] != null)  // 如果位置不为空
//                puts("Yes");   // 表示存在
//            else
//                puts("No");    // 表示不存在
//        }
//    }
//
//    return 0;
//}

//哈希表——字符串哈希方式

//typedef unsigned long long ULL; // 定义无符号长整型别名，用于存储哈希值,可以少打一些字
//
//const int N = 100010, P = 131; // N是字符串最大长度，P是哈希基数（通常取质数）
//
//int n, m;       // n:字符串长度，m:查询次数
//char str[N];    // 存储输入的字符串（从str[1]开始）
//ULL h[N], p[N]; // h[i]存储前i个字符的哈希值，p[i]存储P的i次方
//
//// 计算子串str[l..r]的哈希值
////使用unsigned long long可以自动处理溢出（利用模2^64的特性）
//ULL get(int l, int r)
//{
//    // 公式：h[r] - h[l-1] * p[r-l+1]
//    // 相当于将前l-1位的哈希值"左移"到与h[r]对齐后相减
//    return h[r] - h[l - 1] * p[r - l + 1];
//}
//
//int main() {
//    // 输入字符串长度n，查询次数m，以及字符串本身（从str[1]开始存储）
//    scanf("%d%d%s", &n, &m, str + 1);
//
//    // 初始化p[0] = P^0 = 1
//    p[0] = 1;
//
//    // 预处理计算哈希数组h和幂数组p
//    for (int i = 1; i <= n; i++)
//    {
//        p[i] = p[i - 1] * P; // p[i] = P^i
//        h[i] = h[i - 1] * P + str[i]; // 递推计算前i个字符的哈希值
//    }
//
//    // 处理m个查询
//    while (m--)
//    {
//        int l1, r1, l2, r2;
//        // 输入两个子串的起始和结束位置
//        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
//
//        // 比较两个子串的哈希值
//        if (get(l1, r1) == get(l2, r2)) puts("Yes");
//        else puts("No");
//    }
//    return 0;
//}

//STL（Standard Template Library，标准模板库）————提供了一系列通用的模板类和函数

//C++ STL 常用容器整理（代码注释版）

//#include <vector>
//#include <string>
//#include <queue>
//#include <stack>
//#include <deque>
//#include <utility>  // for pair
//
// // 1. vector（变长数组）示例
//void vector_example() {
//    std::vector<int> v;  // 声明整型vector
//
//    // 基本操作
//    v.push_back(1);      // 尾部插入元素 O(1) 均摊
//    v.pop_back();        // 删除尾部元素 O(1)
//    v.size();            // 元素个数 O(1)
//    v.empty();           // 判空 O(1)
//    v.clear();           // 清空 O(n)
//
//    // 访问元素
//    int a = v[0];        // 随机访问 O(1)
//    int b = v.front();    // 首元素 O(1)
//    int c = v.back();     // 尾元素 O(1)
//
//    // 遍历
//    for (auto x : v) { /*...*/ }
//    for (auto it = v.begin(); it != v.end(); ++it) { /*...*/ }
//}
//
//// 2. string（字符串）示例
//void string_example() {
//    std::string s = "hello";
//
//    // 基本操作
//    s.push_back('!');    // 尾部添加字符
//    s.pop_back();        // 删除尾部字符
//    s.size();            // 长度（同length()）
//    s.empty();           // 判空
//    s.clear();           // 清空
//
//    // 子串操作
//    std::string sub = s.substr(1, 3);  // 从位置1开始取3个字符
//    const char* cs = s.c_str();        // 转C风格字符串
//
//    // 拼接
//    s += " world";       // 字符串拼接
//}
//
//// 3. deque（双端队列）示例
//void deque_example() {
//    std::deque<int> dq;
//
//    // 双端操作
//    dq.push_back(2);     // 尾部插入 O(1)
//    dq.push_front(1);    // 头部插入 O(1)
//    dq.pop_back();       // 尾部删除 O(1)
//    dq.pop_front();      // 头部删除 O(1)
//
//    // 访问
//    int x = dq[0];       // 随机访问 O(1)
//    int y = dq.front();  // 头部元素 O(1)
//    int z = dq.back();   // 尾部元素 O(1)
//}
//
//// 4. stack（栈）示例
//void stack_example() {
//    std::stack<int> st;
//
//    st.push(1);          // 压栈 O(1)
//    st.pop();            // 弹栈 O(1)（无返回值）
//    int top = st.top();   // 查看栈顶 O(1)
//    st.size();           // 元素个数
//    bool e = st.empty(); // 判空
//}
//
//// 5. queue（队列）示例
//void queue_example() {
//    std::queue<int> q;
//
//    q.push(1);           // 入队 O(1)
//    q.pop();             // 出队 O(1)（无返回值）
//    int front = q.front();// 队首 O(1)
//    int back = q.back();  // 队尾 O(1)
//    q.size();            // 元素个数
//    bool e = q.empty();  // 判空
//}
//
//// 6. priority_queue（优先队列）示例
//void priority_queue_example() {
//    // 默认大根堆（降序）
//    std::priority_queue<int> max_heap;
//
//    // 小根堆（升序）声明方式
//    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
//
//    max_heap.push(3);     // 插入元素 O(logn)
//    max_heap.pop();       // 删除堆顶 O(logn)
//    int top = max_heap.top(); // 查看堆顶 O(1)
//}
//
//// 7. pair（键值对）示例
//void pair_example() {
//    std::pair<int, std::string> p1(1, "apple");
//    auto p2 = std::make_pair(2, "banana");  // 自动推导类型
//
//    // 访问成员
//    int id = p1.first;
//    std::string name = p1.second;
//
//    // 比较运算（先比较first，再比较second）
//    if (p1 < p2) { /*...*/ }
//}
//
//// 各容器特性总结：
////
////vector - 动态数组，支持快速随机访问
////string - 专为字符串设计，支持拼接和子串操作
////deque  - 双端队列，支持首尾快速插入删除
////stack  - LIFO（后进先出）结构
////queue  - FIFO（先进先出）结构
////priority_queue - 堆结构，默认大根堆
////pair   - 存储两个元素的简单结构体
////
////注：所有size()/empty()操作时间复杂度均为O(1)
////

 // C++ STL 关联容器与bitset整理（代码注释版）

//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <bitset>
//
//  // 1. set/multiset 示例
//void set_example() {
//    std::set<int> s;         // 有序集合（元素唯一）
//    std::multiset<int> ms;    // 有序多重集合（可重复）
//
//    // 插入元素
//    s.insert(3);             // O(logn)
//    ms.insert(3); ms.insert(3); // 可重复插入
//
//    // 查找操作
//    auto it = s.find(3);     // 返回迭代器，未找到返回end() O(logn)
//    int cnt = ms.count(3);    // 返回元素个数 O(k + logn)
//
//    // 删除操作
//    s.erase(3);              // 删除所有值为3的元素 O(k + logn)
//    ms.erase(ms.find(3));    // 只删除一个迭代器指向的元素 O(1)
//
//    // 边界查找
//    auto lb = s.lower_bound(2); // 第一个>=2的元素 O(logn)
//    auto ub = s.upper_bound(4); // 第一个>4的元素 O(logn)
//}
//
//// 2. map/multimap 示例
//void map_example() {
//    std::map<std::string, int> m;     // 有序映射（key唯一）
//    std::multimap<std::string, int> mm; // 有序多重映射（key可重复）
//
//    // 插入元素（pair）
//    m.insert({ "apple", 5 });          // O(logn)
//    mm.insert({ "apple", 5 }); mm.insert({ "apple", 3 });
//
//    // 访问元素（仅map有[]操作）
//    int val = m["apple"];            // 访问/创建 O(logn)
//    // mm["apple"]  // 错误！multimap没有[]运算符
//
//    // 查找与删除
//    auto it = m.find("apple");       // O(logn)
//    m.erase("apple");                // 按key删除 O(k + logn)
//    mm.erase(mm.find("apple"));      // 按迭代器删除 O(1)
//}
//
//// 3. 无序容器（哈希表实现）示例
//void unordered_example() {
//    std::unordered_set<int> us;      // 哈希集合
//    std::unordered_map<int, int> um; // 哈希映射
//
//    // 基本操作（与有序版本接口相同）
//    us.insert(3);                    // 平均O(1)
//    um[3] = 5;                       // 平均O(1)
//
//    // 特殊限制：
//    // 1. 无lower_bound/upper_bound
//    // 2. 迭代器不支持++/--遍历（无序）
//}
//
//// 4. bitset 示例
//void bitset_example() {
//    std::bitset<100> bs;            // 100位二进制数
//
//    // 位操作
//    bs.set();                       // 所有位置1
//    bs.reset();                     // 所有位置0
//    bs.flip(3);                     // 第3位取反
//    bs[5] = 1;                      // 单独访问某位
//
//    // 查询操作
//    int cnt = bs.count();           // 1的个数 O(n)
//    bool any = bs.any();            // 是否有1 O(n)
//    bool none = bs.none();          // 是否全0 O(n)
//
//    // 位运算（返回新bitset）
//    auto bs2 = ~bs;                 // 按位取反
//    auto bs3 = bs & bs2;            // 按位与
//    auto bs4 = bs | bs2;            // 按位或
//    auto bs5 = bs ^ bs2;            // 按位异或
//    auto bs6 = bs << 3;             // 左移
//    auto bs7 = bs >> 2;             // 右移
//}
//
//
// //* 容器特性对比：
// //*
// //* 有序容器（set/map）：
// //* - 基于红黑树实现，元素自动排序
// //* - 操作时间复杂度 O(logn)
// //* - 支持lower_bound/upper_bound
// //*
// //* 无序容器（unordered_xxx）：
// //* - 基于哈希表实现
// //* - 平均操作时间复杂度 O(1)
// //* - 不支持有序相关操作
// //*
// //* bitset：
// //* - 固定大小的位序列
// //* - 支持各种位运算
// //* - 适用于状态压缩、位标志等场景
// //*
// //* 注：multiset/multimap允许重复元素，erase(x)会删除所有x
// //