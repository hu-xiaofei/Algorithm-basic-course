#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//深度优先搜索树DFS

//const int N = 10;  // 定义最大可处理的数字为10
//int n;              // 用户输入的n，表示要生成1-n的排列
//int path[N];        // 存储当前路径/排列的数组
//bool st[N];         // 状态数组，记录数字是否被使用过（st[i]为true表示数字i已被使用）
//
//// 深度优先搜索函数
//void dfs(int u)     // u表示当前已经填了多少个数字（也是当前处理的层级）
//{
//    // 递归终止条件：当u等于n时，表示已经填满了n个数字
//    if (u == n)
//    {
//        // 输出当前生成的排列
//        for (int i = 0; i < n; i++) printf("%d ", path[i]);
//        puts("");  // 输出换行
//        return;     // 返回上一层
//    }
//
//    // 遍历所有可能的数字（1到n）
//    for (int i = 1; i <= n; i++)
//    {
//        if (!st[i])  // 如果数字i没有被使用过
//        {
//            path[u] = i;   // 将数字i放入当前位置
//            st[i] = true;  // 标记数字i为已使用
//            dfs(u + 1);    // 递归处理下一个位置
//            st[i] = false; // 回溯：恢复数字i为未使用状态
//        }
//    }
//}
//
//int main()
//{
//    cin >> n;   // 输入要排列的数字范围1-n
//    dfs(0);     // 从第0层开始DFS
//    return 0;
//}

//N皇后问题——全排列方式

//const int N = 20;  // 定义最大棋盘尺寸为20x20
//
//int n;             // 实际棋盘大小(n x n)
//char g[N][N];      // 棋盘数组，存储每个位置的状态（'Q'表示皇后，'.'表示空）
//bool col[N];       // 列标记数组，记录每列是否已有皇后
//bool dg[N];        // 正对角线标记数组（左上到右下）
//bool udg[N];       // 反对角线标记数组（右上到左下）
//
//void dfs(int u)    // 深度优先搜索函数，u表示当前处理的行号
//{
//    if (u == n)    // 递归终止条件：已经处理完所有行
//    {
//        for (int i = 0; i < n; i++) puts(g[i]);  // 打印当前棋盘布局
//        puts("");  // 打印空行分隔不同解
//        return;
//    }
//
//    // 尝试在当前行u的每一列放置皇后
//    for (int i = 0; i < n; i++)
//        // 检查第i列、两条对角线上是否都没有皇后
//        if (!col[i] && !dg[u + i] && !udg[n - u + i])
//        //dg[u + i]：正对角线（左上到右下），同一条对角线上u+i是常数
//        //udg[n - u + i]：反对角线（右上到左下），同一条对角线上n - u + i是常数
//        {
//            g[u][i] = 'Q';  // 放置皇后
//            col[i] = dg[u + i] = udg[n - u + i] = true;  // 标记列和对角线
//            dfs(u + 1);    // 递归处理下一行
//            // 回溯：恢复现场
//            col[i] = dg[u + i] = udg[n - u + i] = false;
//            g[u][i] = '.';
//        }
//}
//
//int main()
//{
//    cin >> n;  // 输入棋盘大小
//
//    // 初始化棋盘，全部置为'.'
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < n; j++)
//            g[i][j] = '.';
//
//    dfs(0);  // 从第0行开始搜索
//    return 0;
//}

//N皇后问题——逐格搜索方式

//const int N = 20;      // 最大棋盘尺寸
//int n;                 // 棋盘大小 n x n
//char g[N][N];          // 棋盘，存储皇后位置（'Q' 或 '.'）
//bool col[N];           // 列标记，记录某列是否已有皇后
//bool row[N];           // 行标记，记录某行是否已有皇后（这个版本新增）
//bool dg[N * 2];        // 正对角线标记（左上到右下）
//bool udg[N * 2];       // 反对角线标记（右上到左下）
//
//void dfs(int x, int y, int s)  // x: 当前行, y: 当前列, s: 已放置的皇后数量
//{
//    if (y == n) y = 0, x++;    // 列越界，换到下一行
//    if (x == n) {              // 行越界，检查是否找到解
//        if (s == n) {          // 如果放了 n 个皇后，打印解
//            for (int i = 0; i < n; i++) puts(g[i]);
//            puts("");
//        }
//        return;
//    }
//
//    //不放皇后
//    dfs(x, y + 1, s);  // 直接跳过当前格子，搜索下一个
//
//    //放皇后
//    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]) {
//        g[x][y] = 'Q';  // 放置皇后
//        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;  // 标记占用
//        dfs(x, y + 1, s + 1);  // 递归搜索下一个格子，皇后数量 +1
//        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false; // 回溯
//        g[x][y] = '.';  // 恢复棋盘
//    }
//}
//
//int main() {
//    cin >> n;  // 输入棋盘大小
//    for (int i = 0; i < n; i++)  // 初始化棋盘
//        for (int j = 0; j < n; j++)
//            g[i][j] = '.';
//    dfs(0, 0, 0);  // 从 (0, 0) 开始搜索，初始皇后数量 0
//    return 0;
//}

//BFS——走迷宫

////用队列，不是递归
//
//#include <cstring>
//#include <algorithm>
//
//typedef pair<int, int> PII;  // 定义坐标对类型
//
//const int N = 110;  // 网格的最大尺寸
//
//int n, m;           // 网格的行数和列数
//int g[N][N];        // 存储网格数据，0表示可通过，1表示障碍
//int d[N][N];        // 存储从起点到每个点的最短距离
//PII q[N * N];       // BFS使用的队列
//PII Prev[N][N];     // 存储每个点的前驱节点，用于回溯路径
//
//int bfs()
//{
//    int hh = 0, tt = 0;      // 队列的头和尾指针
//    q[0] = { 0, 0 };           // 队列初始化，起点(0,0)入队
//
//    memset(d, -1, sizeof d);  // 初始化距离数组为-1（表示未访问）
//    d[0][0] = 0;             // 起点距离设为0
//
//    // 四个方向的移动向量：上、右、下、左
//    int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
//
//    while (hh <= tt)         // 队列不为空时循环
//    {
//        auto t = q[hh++];    // 取出队首元素
//
//        // 检查四个相邻方向
//        for (int i = 0; i < 4; i++)
//        {
//            int x = t.first + dx[i], y = t.second + dy[i];  // 计算相邻坐标
//
//            // 检查相邻点是否有效：
//            // 1. 在网格范围内
//            // 2. 是可通行的(g[x][y] == 0)
//            // 3. 未被访问过(d[x][y] == -1)
//            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
//            {
//                d[x][y] = d[t.first][t.second] + 1;  // 更新距离
//                Prev[x][y] = t;                       // 记录前驱节点
//                q[++tt] = { x, y };                    // 新坐标入队
//            }
//        }
//    }
//
//    // 从终点回溯到起点，输出路径
//    int x = n - 1, y = m - 1;  // 从终点开始
//    while (x || y)              // 当没回到起点时继续
//    {
//        cout << x << ' ' << y << endl;  // 输出当前坐标
//        auto t = Prev[x][y];            // 获取前驱节点
//        x = t.first, y = t.second;      // 移动到前驱节点
//    }
//
//    return d[n - 1][m - 1];  // 返回到终点的最短距离
//}
//
//int main()
//{
//    cin >> n >> m;  // 输入网格尺寸
//
//    // 输入网格数据
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//            cin >> g[i][j];
//
//    cout << bfs() << endl;  // 调用BFS并输出结果
//
//    return 0;
//}

//树的DFS框架

//#include <cstring>
//#include <algorithm>
//
//const int N = 100010, M = N * 2;  // N是最大节点数，M是最大边数(无向图需要两倍)
//
//int n, m;           // n:节点数量, m:边数量
//int h[N], e[M], ne[M], idx;  // 邻接表存储图
//bool st[N];         // 标记数组，记录节点是否被访问过
//
//// 添加一条边a->b
//void add(int a, int b)
//{
//    e[idx] = b;      // 存储节点b的值
//    ne[idx] = h[a];   // 新边的next指针指向a原来的第一条边
//    h[a] = idx++;     // a的头指针指向新边，并增加idx计数器
//}
//
//// 深度优先搜索函数，u是当前节点
//void dfs(int u)
//{
//    st[u] = true;    // 标记当前节点已被访问
//
//    // 遍历u的所有邻接节点
//    for (int i = h[u]; i != -1; i = ne[i])
//    {
//        int j = e[i];  // 获取邻接节点j
//
//        // 如果j未被访问过，则递归访问
//        if (!st[j])
//            dfs(j);
//    }
//}
//
//int main()
//{
//    memset(h, -1, sizeof h);  // 初始化邻接表头指针为-1(表示空)
//
//    dfs(1);  // 从节点1开始深度优先搜索
//
//    return 0;
//}

//树的重心——DFS解决

//#include <cstring>
//#include <algorithm>
//
//const int N = 100010, M = N * 2;  // N是最大节点数，M是最大边数(无向图需要两倍)
//
//int n;              // 树的节点数量
//int h[N], e[M], ne[M], idx;  // 邻接表存储树结构
//bool st[N];         // 标记数组，记录节点是否被访问过
//int ans = N;        // 存储最终结果(最小化的最大连通块大小)，初始化为最大可能值N
//
//// 添加一条无向边a-b
//void add(int a, int b)
//{
//    e[idx] = b;      // 存储节点b的值
//    ne[idx] = h[a];   // 新边的next指针指向a原来的第一条边
//    h[a] = idx++;     // a的头指针指向新边，并增加idx计数器
//}
//
//// 返回以u为根的子树的大小，并计算删除u后的最大连通块大小
//int dfs(int u)
//{
//    st[u] = true;    // 标记当前节点u已被访问
//
//    int sum = 1;      // sum记录以u为根的子树的大小(包括u自己)，初始为1
//    int res = 0;      // res记录删除u后，各个连通块中的最大大小
//
//    // 遍历u的所有邻接节点
//    for (int i = h[u]; i != -1; i = ne[i])
//    {
//        int j = e[i];  // 获取邻接节点j
//
//        if (!st[j])    // 如果j未被访问过
//        {
//            int s = dfs(j);  // 递归计算以j为根的子树大小
//            res = max(res, s); // 用子树j的大小更新最大连通块大小
//            sum += s;         // 累加到u的子树大小中
//        }
//    }
//
//    // 计算删除u后，上方连通块的大小(n - sum)并更新res
//    res = max(res, n - sum);
//
//    // 用当前res更新全局最小值ans
//    ans = min(ans, res);
//
//    return sum;  // 返回以u为根的子树的大小
//}
//
//int main()
//{
//    cin >> n;  // 输入树的节点数
//    memset(h, -1, sizeof h);  // 初始化邻接表头指针为-1(表示空)
//
//    // 输入n-1条边，构建树
//    for (int i = 0; i < n - 1; i++)
//    {
//        int a, b;
//        cin >> a >> b;
//        add(a, b), add(b, a);  // 无向图需要添加双向边
//    }
//
//    dfs(1);  // 从节点1开始深度优先搜索(可以选任意节点作为起点)
//
//    cout << ans << endl;  // 输出结果(删除重心后最大连通块的最小可能大小)
//
//    return 0;
//}

//图中点的层——BFS解决

//#include <cstring>
//#include <algorithm>
//
//const int N = 100010;  // 定义最大节点数
//
//int n, m;       // n-节点数，m-边数
//int h[N], e[N], ne[N], idx;  // 邻接表存储图：h-头节点数组，e-边终点数组，ne-下一条边索引，idx-当前可用索引
//int d[N], q[N]; // d-距离数组，q-队列
//
//// 添加一条从a到b的边
//void add(int a, int b)
//{
//    e[idx] = b;      // 记录边的终点
//    ne[idx] = h[a],  // 新边指向原来的第一条边
//        h[a] = idx++;    // 头节点指向新边，并递增索引
//}
//
//// BFS函数，返回节点1到节点n的最短距离
//int bfs()
//{
//    int hh = 0, tt = 0;  // 队列头尾指针
//    q[0] = 1;           // 队列初始化，从节点1开始
//
//    memset(d, -1, sizeof d); // 初始化距离为-1（表示未访问）
//    d[1] = 0;               // 起点距离为0
//
//    while (hh <= tt)        // 队列不为空时循环
//    {
//        int t = q[hh++];    // 取出队头节点
//        for (int i = h[t]; i != -1; i = ne[i]) // 遍历t的所有邻接节点
//        {
//            int j = e[i];  // 获取邻接节点j
//            if (d[j] == -1) // 如果j未被访问过
//            {
//                d[j] = d[t] + 1; // 更新j的距离（父节点距离+1）
//                q[++tt] = j;     // 将j加入队列
//            }
//        }
//    }
//
//    return d[n]; // 返回节点n的距离（如果不可达则为-1）
//}
//
//int main()
//{
//    cin >> n >> m;  // 输入节点数和边数
//
//    memset(h, -1, sizeof h); // 初始化邻接表（所有头节点为-1）
//
//    for (int i = 0; i < m; i++) // 输入所有边
//    {
//        int a, b;
//        cin >> a >> b;
//        add(a, b);  // 添加边a→b（注意这是有向图）
//    }
//
//    cout << bfs() << endl; // 输出结果
//
//    return 0;
//}

//有向图的拓扑序列

//#include <cstring>
//#include <algorithm>
//
//const int N = 100010;  // 定义最大节点数
//
//int n, m;       // n-节点数，m-边数
//int h[N], e[N], ne[N], idx;  // 邻接表存储图
//int q[N], d[N]; // q-队列，d-入度数组
//
//// 添加一条从a到b的有向边
//void add(int a, int b)
//{
//    e[idx] = b,      // 记录边的终点b
//        ne[idx] = h[a],  // 新边指向原来的第一条边
//        h[a] = idx++;    // 头节点指向新边，并递增索引
//}
//
//// 拓扑排序函数，返回是否能拓扑排序
//bool topsort()
//{
//    int hh = 0, tt = -1;  // 队列头尾指针（初始队列为空）
//
//    // 1. 将所有入度为0的节点加入队列
//    for (int i = 1; i <= n; i++)
//        if (!d[i])        // 如果节点i的入度为0
//            q[++tt] = i;  // 加入队列
//
//    // 2. BFS处理队列中的节点
//    while (hh <= tt)      // 队列不为空时循环
//    {
//        int t = q[hh++];  // 取出队头节点t
//
//        // 遍历t的所有邻接节点
//        for (int i = h[t]; i != -1; i = ne[i])
//        {
//            int j = e[i];  // 获取邻接节点j
//            d[j]--;        // j的入度减1（相当于删除边t→j）
//
//            if (d[j] == 0) // 如果j的入度变为0
//                q[++tt] = j; // 将j加入队列
//        }
//    }
//
//    // 3. 判断是否所有节点都被排序
//    // 如果队列中正好有n个节点，说明拓扑排序成功
//    return tt == n - 1;
//}
//
//int main()
//{
//    cin >> n >> m;  // 输入节点数和边数
//
//    memset(h, -1, sizeof h); // 初始化邻接表（所有头节点为-1）
//
//    // 输入所有边并构建图和入度表
//    for (int i = 0; i < m; i++)
//    {
//        int a, b;
//        cin >> a >> b;
//        add(a, b);  // 添加边a→b
//        d[b]++;    // b的入度加1
//    }
//
//    // 执行拓扑排序并输出结果
//    if (topsort())  // 如果能拓扑排序
//    {
//        // 输出拓扑序列（队列q中存储的就是拓扑序列）
//        for (int i = 0; i < n; i++)
//            printf("%d ", q[i]);
//        puts("");
//    }
//    else            // 存在环，无法拓扑排序
//        puts("-1");
//
//    return 0;
//}

//朴素Dijkstra算法 O(n^2)——稠密图

//#include <cstring>
//#include <algorithm>
//
//const int N = 510;
//
//int n, m;          // n: 顶点数, m: 边数
//int g[N][N];        // 邻接矩阵存储图
//int dist[N];        // dist[i] 表示节点 1 到节点 i 的最短距离
//bool st[N];         // st[i] 标记节点 i 是否已确定最短路径
//
//int dijkstra()
//{
//    // 初始化所有距离为无穷大（0x3f3f3f3f）
//    memset(dist, 0x3f, sizeof dist);
//    dist[1] = 0;    // 起点到自身的距离为 0
//
//    // 迭代 n 次，每次确定一个节点的最短路径
//    for (int i = 0; i < n; i++)
//    {
//        int t = -1;
//        // 找到未确定最短路径的节点中距离起点最近的节点 t
//        for (int j = 1; j <= n; j++)
//            if (!st[j] && (t == -1 || dist[t] > dist[j]))
//                t = j;
//
//        st[t] = true; // 标记节点 t 的最短路径已确定
//
//        // 用节点 t 更新其他未确定节点的距离
//        for (int j = 1; j <= n; j++)
//            dist[j] = min(dist[j], dist[t] + g[t][j]);
//    }
//
//    // 如果终点 n 的距离未被更新，说明不可达
//    if (dist[n] == 0x3f3f3f3f) return -1;
//    return dist[n]; // 返回起点到终点的最短距离
//}
//
//int main()
//{
//    // 输入顶点数 n 和边数 m
//    scanf("%d%d", &n, &m);
//
//    // 初始化邻接矩阵 g，所有值设为无穷大（0x3f3f3f3f）
//    memset(g, 0x3f, sizeof g);
//
//    // 读取 m 条边的信息
//    while (m--)
//    {
//        int a, b, c;
//        scanf("%d%d%d", &a, &b, &c);
//        // 存储边权（取最小值处理重边）
//        g[a][b] = min(g[a][b], c);
//    }
//
//    // 调用 Dijkstra 算法，计算从节点 1 到节点 n 的最短距离
//    int t = dijkstra();
//
//    // 输出结果
//    printf("%d\n", t);
//
//    return 0;
//}

//堆优化版Dijkstra算法 O(mlogn)——稀疏图

//#include <cstring>
//#include <queue>
//
//typedef pair<int, int> PII;  // 定义 pair 类型，存储 {距离, 节点编号}
//
//const int N = 100010;        // 节点数上限
//
//int n, m;                    // n: 顶点数, m: 边数
//int h[N], w[N], e[N], ne[N], idx;  // 邻接表存储图
//int dist[N];                 // dist[i] 表示节点 1 到节点 i 的最短距离
//bool st[N];                  // st[i] 标记节点 i 是否已确定最短路径
//
//// 添加一条从 a 到 b 的边，边权为 c
//void add(int a, int b, int c) {
//    e[idx] = b;              // 存储终点 b
//    w[idx] = c;              // 存储边权 c
//    ne[idx] = h[a];          // 将新边插入链表头部
//    h[a] = idx++;            // 更新头指针，并递增 idx
//}
//
//int dijkstra() {
//    memset(dist, 0x3f, sizeof dist);  // 初始化所有距离为无穷大
//    dist[1] = 0;                      // 起点到自身的距离为 0
//
//    // 定义小根堆，按距离从小到大排序
//    priority_queue<PII, vector<PII>, greater<PII>> heap;
//    heap.push({ 0, 1 });                // 将起点 {0, 1} 入堆
//
//    while (heap.size()) {
//        auto t = heap.top();           // 取出当前距离最小的节点(优化点)
//        heap.pop();
//
//        int ver = t.second, distance = t.first;  // ver: 节点编号, distance: 当前距离
//        if (st[ver]) continue;        // 如果已确定最短路径，跳过
//
//        st[ver] = true;               // 标记 ver 的最短路径已确定
//
//        // 遍历 ver 的所有邻边
//        for (int i = h[ver]; i != -1; i = ne[i]) {
//            int j = e[i];             // 邻接节点 j
//            // 松弛操作：如果通过 ver 到 j 的距离更短
//            if (dist[j] > distance + w[i]) {
//                dist[j] = distance + w[i];
//                heap.push({ dist[j], j });  // 将新距离入堆
//            }
//        }
//    }
//
//    if (dist[n] == 0x3f3f3f3f) return -1;  // 终点不可达
//    return dist[n];                        // 返回最短距离
//}
//
//int main() {
//    scanf("%d%d", &n, &m);    // 输入顶点数 n 和边数 m
//    memset(h, -1, sizeof h);  // 初始化邻接表头指针为 -1（表示空链表）
//
//    while (m--) {
//        int a, b, c;
//        scanf("%d%d%d", &a, &b, &c);
//        add(a, b, c);         // 添加边（处理重边时无需特殊处理，优先队列会自动选择最短路径）
//    }
//
//    int t = dijkstra();       // 调用 Dijkstra 算法
//    printf("%d\n", t);        // 输出结果
//    return 0;
//}

//Bellman-ford算法 O(mn)

//#include <cstring>
//#include <algorithm> 
//
//const int N = 510, M = 10010;  // 最大顶点数和边数
//int n, m, k;                   // n:顶点数, m:边数, k:最多经过的边数
//int dist[N], backup[N];         // dist:距离数组, backup:备份数组
//
//struct Edge {
//    int a, b, w;                // 边的结构体:起点a,终点b,权重w
//}edges[M];                      // 存储所有边的数组
//
//int bellman_ford() {
//    memset(dist, 0x3f, sizeof dist);  // 初始化距离为"无穷大"
//    dist[1] = 0;                      // 起点到自己的距离为0
//
//    // 外层循环限制路径边数不超过k
//    for (int i =0 ; i < k; i++) {
//        memcpy(backup, dist, sizeof dist);  // 备份上一轮的距离
//
//        // 遍历所有边进行松弛操作
//        for (int j = 0; j < m; j++) {
//            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
//            dist[b] = min(dist[b], backup[a] + w);  // 松弛操作
//        }
//    }
//
//    // 判断是否可达
//    if (dist[n] > 0x3f3f3f3f / 2) return -1;  // 考虑负权边的影响
//    return dist[n];  // 返回最短距离
//}
//
//int main() {
//    scanf("%d%d%d", &n, &m, &k);  // 输入顶点数、边数、边数限制
//
//    // 输入所有边
//    for (int i = 0; i < m; i++) {
//        int a, b, w;
//        scanf("%d%d%d", &a, &b, &w);
//        edges[i] = { a, b, w };
//    }
//
//    int t = bellman_ford();  // 调用算法
//
//    if (t == -1) puts("impossible");  // 不可达
//    else printf("%d\n", t);           // 输出结果
//
//    return 0;
//}

//SPFA算法

//#include <cstring>
//#include <queue>
//#include <algorithm> 
//
//typedef pair<int, int> PII;  // 定义 pair 类型，存储 {距离, 节点编号}
//
//const int N = 100010;        // 节点数上限
//
//int n, m;                    // n: 顶点数, m: 边数
//int h[N], w[N], e[N], ne[N], idx;  // 邻接表存储图
//int dist[N];                 // dist[i] 表示节点 1 到节点 i 的最短距离
//bool st[N];                  // st[i] 标记节点 i 是否已确定最短路径
//
//// 添加一条从 a 到 b 的边，边权为 c
//void add(int a, int b, int c) {
//    e[idx] = b;              // 存储终点 b
//    w[idx] = c;              // 存储边权 c
//    ne[idx] = h[a];          // 将新边插入链表头部
//    h[a] = idx++;            // 更新头指针，并递增 idx
//}
//
//int spfa()
//{
//    memset(dist, 0x3f, sizeof dist); // 初始化所有节点距离为"无穷大"
//    dist[1] = 0; // 起点(假设为1)到自身的距离为0
//
//    queue<int> q;   // 创建队列用于SPFA算法
//    q.push(1);      // 起点入队
//    st[1] = true;   // 标记起点在队列中
//
//    while (q.size()) // 当队列不为空时循环
//    {
//        int t = q.front(); // 取出队首节点
//        q.pop();           // 队首节点出队
//        st[t] = false;    // 标记该节点已不在队列中
//
//        // 遍历节点t的所有邻接边
//        for (int i = h[t]; i != -1; i = ne[i])
//        {
//            int j = e[i]; // 获取邻接节点j
//            // 如果通过t到j的路径比当前已知的更短
//            if (dist[j] > dist[t] + w[i])
//            {
//                dist[j] = dist[t] + w[i]; // 更新到j的最短距离
//                if (!st[j]) // 如果j不在队列中
//                {
//                    q.push(j);  // j入队
//                    st[j] = true; // 标记j在队列中
//                }
//            }
//        }
//    }
//
//    // 检查终点n是否可达
//    if (dist[n] == 0x3f3f3f3f) // 如果距离仍是初始化的"无穷大"
//        return -1; // 不可达
//    return dist[n]; // 返回最短距离
//}
//
//int main()
//{
//    scanf("%d%d", &n, &m); // 读入节点数n和边数m
//
//    memset(h, -1, sizeof h); // 初始化邻接表，-1表示空
//
//    // 读入所有边
//    while (m--)
//    {
//        int a, b, c;
//        scanf("%d%d%d", &a, &b, &c); // 读入一条有向边a->b，权重c
//        add(a, b, c); // 添加到邻接表
//    }
//
//    int t = spfa(); // 调用SPFA算法计算最短路径
//
//    if (t == -1)
//        puts("impossible"); // 不可达
//    else
//        printf("%d\n", t); // 输出最短距离
//
//    return 0;
//}

//Floyd算法——O(n^3)

//#include <cstring>   // 用于memset等内存操作函数
//#include <algorithm> // 包含min等算法函数
//
//const int N = 210, INF = 1e9; // 定义常量：
//// N-最大节点数(210)
//// INF-表示无穷大(10^9)
//
//int n, m, Q;        // 变量定义：
//// n-节点数量
//// m-边数量
//// Q-查询次数
//
//int d[N][N];        // 距离矩阵d，d[i][j]表示i到j的最短距离
//
//void floyd()
//{
//    // 三重循环更新最短距离
//    for (int k = 1; k <= n; k++)        // 枚举中转节点k
//        for (int i = 1; i <= n; i++)    // 枚举起点i
//            for (int j = 1; j <= n; j++) // 枚举终点j
//                // 状态转移方程：比较直接路径和通过k中转的路径
//                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//    // 如果i->k->j比当前i->j路径更短，则更新
//}
//
//int main()
//{
//    // 读入节点数n、边数m和查询次数Q
//    scanf("%d%d%d", &n, &m, &Q);
//
//    // 初始化距离矩阵
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= n; j++)
//            if (i == j)
//                d[i][j] = 0;    // 节点到自身的距离为0
//            else
//                d[i][j] = INF;   // 初始时设其他距离为无穷大
//
//    // 读入所有边信息
//    while (m--)
//    {
//        int a, b, w;
//        scanf("%d%d%d", &a, &b, &w); // 读入一条从a到b的边，权重w
//        d[a][b] = min(d[a][b], w);   // 如果有重边，保留权重最小的
//        // 注意：这里是有向图，如果是无向图需要加上d[b][a] = min(d[b][a], w);
//    }
//
//    floyd(); // 调用Floyd算法计算所有节点对的最短路径
//
//    // 处理查询
//    while (Q--)
//    {
//        int a, b;
//        scanf("%d%d", &a, &b); // 读入查询的起点a和终点b
//
//        // 判断是否可达
//        if (d[a][b] > INF / 2)
//            puts("impossible"); // 距离大于INF/2视为不可达
//        else
//            printf("%d\n", d[a][b]); // 输出最短距离
//    }
//
//    return 0;
//}

//朴素版Prim——O(n^2)

//#include <cstring>
//#include <algorithm>
//
//const int N = 510, INF = 0x3f3f3f3f;
//
//int n, m;       // n-顶点数, m-边数
//int g[N][N];    // 邻接矩阵存储图
//int dist[N];    // 存储各点到当前最小生成树的距离
//bool st[N];     // 标记顶点是否已加入最小生成树
//
//int prim()
//{
//    memset(dist, 0x3f, sizeof dist);  // 初始化所有距离为无穷大
//
//    int res = 0;  // 存储最小生成树的权值和
//
//    // 循环n次，每次加入一个顶点到MST中
//    for (int i = 0; i < n; i++)
//    {
//        int t = -1;  // t存储当前距离MST最近的顶点
//
//        // 找出未加入MST的顶点中距离MST最近的顶点
//        for (int j = 1; j <= n; j++)
//            if (!st[j] && (t == -1 || dist[t] > dist[j]))
//                t = j;
//
//        // 如果不是第一次循环(i=0是初始化)且最近距离为INF，说明图不连通
//        if (i && dist[t] == INF) return INF;
//
//        // 如果不是第一次循环，将该边权值加入结果
//        if (i) res += dist[t];
//
//        // 更新其他顶点到MST的距离
//        for (int j = 1; j <= n; j++)
//            dist[j] = min(dist[j], g[t][j]);
//
//        st[t] = true;  // 标记顶点t已加入MST
//    }
//
//    return res;  // 返回最小生成树的权值和
//}
//
//int main()
//{
//    scanf("%d%d", &n, &m);  // 读入顶点数和边数
//
//    memset(g, 0x3f, sizeof g);  // 初始化邻接矩阵为无穷大
//
//    // 读入m条边
//    while (m--)
//    {
//        int a, b, c;
//        scanf("%d%d%d", &a, &b, &c);
//        g[a][b] = g[b][a] = min(g[a][b], c);  // 无向图，存储最小边权
//    }
//
//    int t = prim();  // 调用Prim算法
//
//    if (t == INF) puts("impossible");  // 图不连通，无法生成MST
//    else printf("%d\n", t);  // 输出MST权值和
//
//    return 0;
//}

//Kruskal算法

//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 200010;  // 最大边数
//
//int n, m;       // n-顶点数, m-边数
//int p[N];       // 并查集数组，用于判断连通性
//
//// 边的结构体定义
//struct Edge
//{
//    int a, b, w;  // a和b是边的两个顶点，w是边的权值
//
//    // 重载小于运算符，用于边按权值排序
//    bool operator< (const Edge& W)const
//    {
//        return w < W.w;  // 按权值从小到大排序
//    }
//}edges[N];  // 存储所有边的数组
//
//// 并查集的find函数，带路径压缩
//int find(int x)
//{
//    if (p[x] != x) p[x] = find(p[x]);  // 路径压缩
//    return p[x];
//}
//
//int main()
//{
//    scanf("%d%d", &n, &m);  // 读入顶点数和边数
//
//    // 读入所有边
//    for (int i = 0; i < m; i++)
//    {
//        int a, b, w;
//        scanf("%d%d%d", &a, &b, &w);
//        edges[i] = { a, b, w };
//    }
//
//    sort(edges, edges + m);  // 将所有边按权值从小到大排序
//    // sort函数会多次调用Edge的operator<来比较边，比较方式就是比较边的w(权值)成员
//
//    // 初始化并查集，每个顶点是自己的父节点
//    for (int i = 1; i <= n; i++) p[i] = i;
//
//    int res = 0, cnt = 0;  // res-最小生成树权值和，cnt-已选边数
//
//    // 遍历所有边
//    for (int i = 0; i < m; i++)
//    {
//        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
//
//        a = find(a), b = find(b);  // 找到两个顶点的根节点
//
//        // 如果两个顶点不在同一集合，说明加入这条边不会形成环
//        if (a != b)
//        {
//            p[a] = b;    // 合并两个集合
//            res += w;    // 累加边权
//            cnt++;     // 已选边数+1
//        }
//    }
//
//    // 最小生成树应有n-1条边，不足说明图不连通
//    if (cnt < n - 1) puts("impossible");
//    else printf("%d\n", res);  // 输出最小生成树权值和
//
//    return 0;
//}

//判断二分图——染色法

//#include <cstring>
//#include <algorithm>
//
//const int N = 100010, M = 200010;  // N是最大顶点数，M是最大边数
//
//int n, m;       // n:顶点数，m:边数
//int h[N], e[M], ne[M], idx;  // 邻接表存储图
//int color[N];    // 存储每个顶点的颜色(1或2)
//
//void add(int a, int b)
//{
//    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//    // 将b添加到a的邻接表中
//    // e[idx]存储边的终点b
//    // ne[idx]指向a原来的第一条边
//    // h[a]更新为指向这条新边
//    // idx递增为下一条边做准备
//}
//
//bool dfs(int u, int c)
//{
//    color[u] = c;  // 将顶点u染成颜色c
//
//    // 遍历u的所有邻接顶点
//    for (int i = h[u]; i != -1; i = ne[i])
//    {
//        int j = e[i];  // 邻接顶点j
//
//        if (!color[j])  // 如果j没有被染色
//        {
//            // 递归染色j为另一种颜色(3-c)
//            // 如果染色失败，返回false
//            if (!dfs(j, 3 - c)) return false;
//        }
//        else if (color[j] == c)  // 如果j已经被染色且颜色与u相同
//        {
//            return false;  // 不是二分图
//        }
//    }
//    return true;  // 所有邻接顶点都成功染色
//}
//
//int main()
//{
//    scanf("%d%d", &n, &m);  // 读取顶点数n和边数m
//    memset(h, -1, sizeof h); // 初始化邻接表
//
//    // 读取所有边并构建图
//    while (m--)
//    {
//        int a, b;
//        scanf("%d%d", &a, &b);
//        add(a, b), add(b, a);  // 无向图，添加双向边
//    }
//
//    bool flag = true;  // 标记是否是二分图
//
//    // 遍历所有顶点
//    for (int i = 1; i <= n; i++)
//        if (!color[i])  // 如果顶点i没有被染色
//        {
//            // 从i开始DFS染色，初始颜色为1
//            // 如果染色失败，设置flag为false并退出循环
//            if (!dfs(i, 1))
//            {
//                flag = false;
//                break;
//            }
//        }
//
//    if (flag) puts("Yes");  // 是二分图
//    else puts("No");        // 不是二分图
//
//    return 0;
//}

//二分图最大匹配数——匈牙利算法

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;  // N表示点的最大数量，M表示边的最大数量

int n1, n2, m;      // n1是二分图左部点数，n2是右部点数，m是总边数
int h[N], e[M], ne[M], idx;  // 邻接表存图：h是头节点数组，e存储边的终点，ne是next指针
int match[N];       // match[j] = x 表示右部点j当前匹配的左部点是x
bool st[N];         // st[j]标记右部点j是否在当前DFS中被访问过（避免重复搜索）

// 添加一条从a指向b的边（左部点a → 右部点b）
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 尝试为左部点x找一个匹配的右部点
bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {  // 遍历x的所有邻接边
        int j = e[i];                         // j是当前右部点
        if (!st[j]) {                         // 如果j未被访问过
            st[j] = true;                      // 标记为已访问
            // 如果j未被匹配，或者j的当前匹配点可以找到新的匹配
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;                  // 将j匹配给x
                return true;                   // 匹配成功
            }
        }
    }
    return false;  // 所有邻接点都无法匹配
}

// 尝试为左部点x找一个匹配的右部点
bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {  // 遍历x的所有邻接边
        int j = e[i];                         // j是当前右部点
        if (!st[j]) {                         // 如果j未被访问过
            st[j] = true;                      // 标记为已访问
            // 如果j未被匹配，或者j的当前匹配点可以找到新的匹配
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;                  // 将j匹配给x
                return true;                   // 匹配成功
            }
        }
    }
    return false;  // 所有邻接点都无法匹配
}

int main() {
    scanf("%d%d%d", &n1, &n2, &m);  // 输入左部点数n1、右部点数n2、边数m
    memset(h, -1, sizeof h);         // 初始化邻接表（头节点全部置-1）

    // 添加所有边（左部点 → 右部点）
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);  // 注意：这里默认是单向边（二分图左→右）
    }

    int res = 0;  // 记录最大匹配数
    for (int i = 1; i <= n1; i++) {  // 遍历所有左部点
        memset(st, false, sizeof st); // 每次DFS前清空访问标记
        if (find(i)) res++;           // 如果i能找到匹配，结果+1
    }

    printf("%d\n", res);  // 输出最大匹配数
    return 0;
}