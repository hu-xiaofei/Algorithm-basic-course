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

//树的重心

#include <cstring>
#include <algorithm>

const int N = 100010, M = N * 2;  // N是最大节点数，M是最大边数(无向图需要两倍)

int n;              // 树的节点数量
int h[N], e[M], ne[M], idx;  // 邻接表存储树结构
bool st[N];         // 标记数组，记录节点是否被访问过
int ans = N;        // 存储最终结果(最小化的最大连通块大小)，初始化为最大可能值N

// 添加一条无向边a-b
void add(int a, int b)
{
    e[idx] = b;      // 存储节点b的值
    ne[idx] = h[a];   // 新边的next指针指向a原来的第一条边
    h[a] = idx++;     // a的头指针指向新边，并增加idx计数器
}

// 返回以u为根的子树的大小，并计算删除u后的最大连通块大小
int dfs(int u)
{
    st[u] = true;    // 标记当前节点u已被访问

    int sum = 1;      // sum记录以u为根的子树的大小(包括u自己)，初始为1
    int res = 0;      // res记录删除u后，各个连通块中的最大大小

    // 遍历u的所有邻接节点
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];  // 获取邻接节点j

        if (!st[j])    // 如果j未被访问过
        {
            int s = dfs(j);  // 递归计算以j为根的子树大小
            res = max(res, s); // 用子树j的大小更新最大连通块大小
            sum += s;         // 累加到u的子树大小中
        }
    }

    // 计算删除u后，上方连通块的大小(n - sum)并更新res
    res = max(res, n - sum);

    // 用当前res更新全局最小值ans
    ans = min(ans, res);

    return sum;  // 返回以u为根的子树的大小
}

int main()
{
    cin >> n;  // 输入树的节点数
    memset(h, -1, sizeof h);  // 初始化邻接表头指针为-1(表示空)

    // 输入n-1条边，构建树
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);  // 无向图需要添加双向边
    }

    dfs(1);  // 从节点1开始深度优先搜索(可以选任意节点作为起点)

    cout << ans << endl;  // 输出结果(删除重心后最大连通块的最小可能大小)

    return 0;
}