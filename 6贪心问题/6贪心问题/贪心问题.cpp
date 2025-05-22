#define _CRT_SECURE_NO_WARNINGS

//区间选点

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//// 定义一个常量N，可能用于表示区间的最大数量
//const int N = 100010;
//int n;
//
//// 定义一个结构体Range，用于表示区间
//struct Range
//{
//    int l, r; // l表示区间左端点，r表示区间右端点
//    // 重载小于号运算符，用于在排序时按照区间右端点从小到大排序
//    bool operator< (const Range& W)const
//    {
//        return r < W.r;
//    }
//}range[N];
//
//int main()
//{
//    // 读取区间的数量n
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//    {
//        int l, r;
//        // 读取每个区间的左端点l和右端点r
//        scanf("%d%d", &l, &r);
//        range[i] = { l, r }; // 将读取到的区间存入数组range中
//    }
//
//    // 对区间数组range按照自定义的排序规则（右端点从小到大）进行排序
//    sort(range, range + n);
//
//    int res = 0, ed = -2e9; // res用于记录选取的点的数量，ed用于记录当前已覆盖区间的最右边界
//    for (int i = 0; i < n; i++)
//    {
//        // 如果当前区间的左端点大于已覆盖区间的最右边界
//        if (range[i].l > ed)
//        {
//            res++; // 需要新增一个点
//            ed = range[i].r; // 更新已覆盖区间的最右边界为当前区间的右端点
//        }
//    }
//
//    // 输出选取的点的数量
//    printf("%d\n", res);
//
//    return 0;
//}

//最不相交区间的数量

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int N = 100010; // 定义一个常量N，作为区间数组的最大容量，这里设置为100010，可根据题目数据范围调整
//
//int n; // 用于存储区间的数量
//struct Range // 定义一个结构体Range，用来表示区间
//{
//    int l, r; // l表示区间左端点，r表示区间右端点
//    bool operator< (const Range& W)const // 重载小于号运算符，用于自定义排序规则
//    {
//        return r < W.r; // 按照区间的右端点从小到大排序，这样后续贪心选择时，能优先选右端点小的区间，为后续选更多不相交区间创造条件
//    }
//}range[N]; // 定义一个Range类型的数组range，用于存储所有区间
//
//int main()
//{
//    scanf("%d", &n); // 读取区间的数量n
//    for (int i = 0; i < n; i++) // 循环n次，读取每个区间的左右端点
//    {
//        int l, r;
//        scanf("%d%d", &l, &r);
//        range[i] = { l, r }; // 将读取到的区间存入range数组
//    }
//
//    sort(range, range + n); // 对区间数组range按照自定义的排序规则（即按右端点从小到大）进行排序
//
//    int res = 0, ed = -2e9; // res用于记录不相交区间的最大数量，初始化为0；ed用于记录当前已选区间的最大右端点，初始化为一个极小值
//    for (int i = 0; i < n; i++) // 遍历排序后的区间数组
//        if (ed < range[i].l) // 如果当前已选区间的最大右端点ed小于当前区间的左端点
//        {
//            res++; // 能选这个区间，不相交区间数量加1
//            ed = range[i].r; // 更新当前已选区间的最大右端点为当前区间的右端点
//        }
//
//    printf("%d\n", res); // 输出不相交区间的最大数量
//    return 0;
//}

//区间分组

//#include <iostream>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//const int N = 100010; // 定义一个常量N，作为存储区间数组的最大容量，这里设置为100010，可根据实际需求调整
//int n; // 用于存储区间的数量
//
//struct Range // 定义一个结构体Range，用来表示区间
//{
//    int l, r; // l表示区间左端点，r表示区间右端点
//    bool operator< (const Range& W)const // 重载小于号运算符，用于自定义排序规则
//    {
//        return l < W.l; // 按照区间的左端点从小到大排序，方便后续按顺序处理区间
//    }
//}range[N]; // 定义一个Range类型的数组range，用于存储所有区间
//
//int main()
//{
//    scanf("%d", &n); // 读取区间的数量n
//    for (int i = 0; i < n; i++) // 循环n次，读取每个区间的左右端点
//    {
//        int l, r;
//        scanf("%d%d", &l, &r);
//        range[i] = { l, r }; // 将读取到的区间存入range数组
//    }
//
//    sort(range, range + n); // 对区间数组range按照自定义的排序规则（即按左端点从小到大）进行排序
//
//    priority_queue<int, vector<int>, greater<int>> heap;
//    // 定义一个小顶堆heap，用于存储每个分组中区间的最大右端点值。小顶堆能方便地获取当前所有分组中最小的最大右端点
//    for (int i = 0; i < n; i++)
//    {
//        auto r = range[i]; // 取出当前区间r
//        if (heap.empty() || heap.top() >= r.l) // 如果堆为空，或者堆顶元素（当前所有分组中最小的最大右端点）大于等于当前区间的左端点
//            heap.push(r.r); // 说明当前区间不能加入现有的分组，需要新建一个分组，将当前区间的右端点加入堆
//        else
//        {
//            int t = heap.top(); // 取出堆顶元素（即某个分组中当前最大右端点）
//            heap.pop(); // 弹出堆顶元素
//            heap.push(r.r); // 将当前区间的右端点加入堆，更新该分组的最大右端点
//        }
//    }
//
//    printf("%d\n", heap.size()); // 堆的大小就是最终区间分组的数量，输出分组数量
//    return 0;
//}

//区间覆盖

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int N = 100010;
//int n;
//
//struct Range
//{
//    int l, r;
//    bool operator< (const Range& W)const
//    {
//        return l < W.l; // 重载小于号运算符，按照区间左端点从小到大排序
//    }
//}range[N];
//
//int main()
//{
//    int st, ed;
//    scanf("%d%d", &st, &ed); // 读取目标区间的起始点st和结束点ed
//    scanf("%d", &n); // 读取区间的数量n
//    for (int i = 0; i < n; i++)
//    {
//        int l, r;
//        scanf("%d%d", &l, &r);
//        range[i] = { l, r }; // 将每个区间的左右端点存入range数组
//    }
//
//    sort(range, range + n); // 对区间数组按照左端点从小到大排序
//
//    int res = 0; // 记录覆盖目标区间所需的最少区间数量，初始化为0
//    bool success = false; // 标记是否成功覆盖目标区间，初始化为false
//    for (int i = 0; i < n; i++)
//    {
//        int j = i, r = -2e9; // j用于在当前循环中遍历区间，r用于记录当前能扩展到的最右边界，初始化为极小值
//        while (j < n && range[j].l <= st)
//        {
//            // 当还没遍历完所有区间，且区间左端点小于等于当前目标起始点st时
//            r = max(r, range[j].r); // 更新当前能扩展到的最右边界
//            j++;
//        }
//
//        if (r < st)
//        {
//            // 如果当前能扩展到的最右边界小于当前目标起始点st
//            res = -1; // 说明无法覆盖，设置结果为 -1
//            break;
//        }
//
//        res++; // 找到一个能覆盖一部分的区间，区间数量加1
//        if (r >= ed)
//        {
//            // 如果当前能扩展到的最右边界大于等于目标区间结束点ed
//            success = true; // 说明成功覆盖目标区间
//            break;
//        }
//
//        st = r; // 更新目标起始点为当前能扩展到的最右边界
//        i = j - 1; // 因为while循环中j多自增了一次，所以这里调整i的值
//    }
//
//    if (!success) res = -1; // 如果最终没有成功覆盖，设置结果为 -1
//    printf("%d\n", res); // 输出覆盖目标区间所需的最少区间数量，若无法覆盖则输出 -1
//    return 0;
//}

//合并果子——哈夫曼树问题

//#include <iostream>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//int main()
//{
//    int n;
//    scanf("%d", &n); // 读取果子堆的数量n
//
//    priority_queue<int, vector<int>, greater<int>> heap;
//    // 创建一个小顶堆heap，用于存储果子堆的数量。小顶堆能方便地获取当前最小的两个果子堆数量
//    while (n--)
//    {
//        int x;
//        scanf("%d", &x);
//        heap.push(x); // 将每个果子堆的数量依次加入小顶堆
//    }
//
//    int res = 0;
//    while (heap.size() > 1)
//    {
//        int a = heap.top(); heap.pop(); // 取出当前堆中数量最小的果子堆，记录其数量为a，并从堆中删除
//        int b = heap.top(); heap.pop(); // 取出当前堆中剩余果子堆里数量最小的，记录其数量为b，并从堆中删除
//        res += a + b; // 将合并这两堆果子的代价（a + b）累加到总代价res中
//        heap.push(a + b); // 将合并后的果子堆数量重新加入堆中
//    }
//
//    printf("%d\n", res); // 输出合并所有果子堆的最小总代价
//    return 0;
//}

//排队打水

//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long LL; // 定义长整型别名LL
//
//const int N = 100010; // 定义最大人数
//
//int n;       // 人数
//int t[N];    // 存储每个人打水所需的时间
//
//int main()
//{
//    scanf("%d", &n); // 输入人数
//    for (int i = 0; i < n; i++) scanf("%d", &t[i]); // 输入每个人的打水时间
//
//    sort(t, t + n); // 将打水时间按从小到大排序
//
//    LL res = 0; // 初始化总等待时间
//    for (int i = 0; i < n; i++)
//        res += t[i] * (n - i - 1); // 计算总等待时间
//
//    printf("%lld\n", res); // 输出结果
//
//    return 0;
//}

//货仓选址——找中位数

//#include <iostream>
//#include <algorithm> // 包含sort函数
//
//using namespace std;
//
//const int N = 100010; // 定义最大商店数量
//
//int n;       // 商店数量
//int a[N];    // 存储商店位置的数组
//
//int main()
//{
//    scanf("%d", &n); // 输入商店数量
//    for (int i = 0; i < n; i++) scanf("%d", &a[i]); // 输入每个商店的位置
//
//    // 关键步骤1：对商店位置排序
//    sort(a, a + n);
//
//    int res = 0; // 存储总距离结果
//
//    // 关键步骤2：计算所有商店到中位数的距离之和
//    for (int i = 0; i < n; i++)
//        res += abs(a[i] - a[n / 2]); // 累加每个商店到中位数的距离
//                                     //abs 是 绝对值函数
//
//    printf("%d\n", res); // 输出结果
//
//    return 0;
//}

//耍杂技的牛

//#include <iostream>
//#include <algorithm> // 包含sort函数
//#include <utility>   // 包含pair类型
//
//using namespace std;
//
//typedef pair<int, int> PII; // 定义pair类型，存储两个整数
//
//const int N = 50010; // 最大牛的数量
//
//int n;      // 牛的数量
//PII cow[N]; // 存储每头牛的信息
//
//int main()
//{
//    scanf("%d", &n); // 输入牛的数量
//    for (int i = 0; i < n; i++)
//    {
//        int w, s;
//        scanf("%d%d", &w, &s); // 输入每头牛的重量和力量
//        // 关键步骤1：将(w+s, w)存入数组
//        cow[i] = { w + s, w };
//    }
//
//    // 关键步骤2：按照w+s的值从小到大排序
//    sort(cow, cow + n);
//
//    int res = -2e9; // 初始化为极小值，存储最终结果(最小化最大风险值)
//    int sum = 0;    // 累积上方牛的重量总和
//
//    for (int i = 0; i < n; i++)
//    {
//        int w = cow[i].second;          // 当前牛的重量
//        int s = cow[i].first - w;       // 当前牛的力量
//        res = max(res, sum - s);        // 计算当前牛的风险值，并更新最大值
//        sum += w;                       // 将当前牛的重量加入总重量
//    }
//
//    printf("%d\n", res); // 输出结果
//    return 0;
//}