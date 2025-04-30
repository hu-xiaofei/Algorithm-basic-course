#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�������������DFS

//const int N = 10;  // �������ɴ��������Ϊ10
//int n;              // �û������n����ʾҪ����1-n������
//int path[N];        // �洢��ǰ·��/���е�����
//bool st[N];         // ״̬���飬��¼�����Ƿ�ʹ�ù���st[i]Ϊtrue��ʾ����i�ѱ�ʹ�ã�
//
//// ���������������
//void dfs(int u)     // u��ʾ��ǰ�Ѿ����˶��ٸ����֣�Ҳ�ǵ�ǰ����Ĳ㼶��
//{
//    // �ݹ���ֹ��������u����nʱ����ʾ�Ѿ�������n������
//    if (u == n)
//    {
//        // �����ǰ���ɵ�����
//        for (int i = 0; i < n; i++) printf("%d ", path[i]);
//        puts("");  // �������
//        return;     // ������һ��
//    }
//
//    // �������п��ܵ����֣�1��n��
//    for (int i = 1; i <= n; i++)
//    {
//        if (!st[i])  // �������iû�б�ʹ�ù�
//        {
//            path[u] = i;   // ������i���뵱ǰλ��
//            st[i] = true;  // �������iΪ��ʹ��
//            dfs(u + 1);    // �ݹ鴦����һ��λ��
//            st[i] = false; // ���ݣ��ָ�����iΪδʹ��״̬
//        }
//    }
//}
//
//int main()
//{
//    cin >> n;   // ����Ҫ���е����ַ�Χ1-n
//    dfs(0);     // �ӵ�0�㿪ʼDFS
//    return 0;
//}

//N�ʺ����⡪��ȫ���з�ʽ

//const int N = 20;  // ����������̳ߴ�Ϊ20x20
//
//int n;             // ʵ�����̴�С(n x n)
//char g[N][N];      // �������飬�洢ÿ��λ�õ�״̬��'Q'��ʾ�ʺ�'.'��ʾ�գ�
//bool col[N];       // �б�����飬��¼ÿ���Ƿ����лʺ�
//bool dg[N];        // ���Խ��߱�����飨���ϵ����£�
//bool udg[N];       // ���Խ��߱�����飨���ϵ����£�
//
//void dfs(int u)    // �����������������u��ʾ��ǰ������к�
//{
//    if (u == n)    // �ݹ���ֹ�������Ѿ�������������
//    {
//        for (int i = 0; i < n; i++) puts(g[i]);  // ��ӡ��ǰ���̲���
//        puts("");  // ��ӡ���зָ���ͬ��
//        return;
//    }
//
//    // �����ڵ�ǰ��u��ÿһ�з��ûʺ�
//    for (int i = 0; i < n; i++)
//        // ����i�С������Խ������Ƿ�û�лʺ�
//        if (!col[i] && !dg[u + i] && !udg[n - u + i])
//        //dg[u + i]�����Խ��ߣ����ϵ����£���ͬһ���Խ�����u+i�ǳ���
//        //udg[n - u + i]�����Խ��ߣ����ϵ����£���ͬһ���Խ�����n - u + i�ǳ���
//        {
//            g[u][i] = 'Q';  // ���ûʺ�
//            col[i] = dg[u + i] = udg[n - u + i] = true;  // ����кͶԽ���
//            dfs(u + 1);    // �ݹ鴦����һ��
//            // ���ݣ��ָ��ֳ�
//            col[i] = dg[u + i] = udg[n - u + i] = false;
//            g[u][i] = '.';
//        }
//}
//
//int main()
//{
//    cin >> n;  // �������̴�С
//
//    // ��ʼ�����̣�ȫ����Ϊ'.'
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < n; j++)
//            g[i][j] = '.';
//
//    dfs(0);  // �ӵ�0�п�ʼ����
//    return 0;
//}

//N�ʺ����⡪�����������ʽ

//const int N = 20;      // ������̳ߴ�
//int n;                 // ���̴�С n x n
//char g[N][N];          // ���̣��洢�ʺ�λ�ã�'Q' �� '.'��
//bool col[N];           // �б�ǣ���¼ĳ���Ƿ����лʺ�
//bool row[N];           // �б�ǣ���¼ĳ���Ƿ����лʺ�����汾������
//bool dg[N * 2];        // ���Խ��߱�ǣ����ϵ����£�
//bool udg[N * 2];       // ���Խ��߱�ǣ����ϵ����£�
//
//void dfs(int x, int y, int s)  // x: ��ǰ��, y: ��ǰ��, s: �ѷ��õĻʺ�����
//{
//    if (y == n) y = 0, x++;    // ��Խ�磬������һ��
//    if (x == n) {              // ��Խ�磬����Ƿ��ҵ���
//        if (s == n) {          // ������� n ���ʺ󣬴�ӡ��
//            for (int i = 0; i < n; i++) puts(g[i]);
//            puts("");
//        }
//        return;
//    }
//
//    //���Żʺ�
//    dfs(x, y + 1, s);  // ֱ��������ǰ���ӣ�������һ��
//
//    //�Żʺ�
//    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]) {
//        g[x][y] = 'Q';  // ���ûʺ�
//        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;  // ���ռ��
//        dfs(x, y + 1, s + 1);  // �ݹ�������һ�����ӣ��ʺ����� +1
//        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false; // ����
//        g[x][y] = '.';  // �ָ�����
//    }
//}
//
//int main() {
//    cin >> n;  // �������̴�С
//    for (int i = 0; i < n; i++)  // ��ʼ������
//        for (int j = 0; j < n; j++)
//            g[i][j] = '.';
//    dfs(0, 0, 0);  // �� (0, 0) ��ʼ��������ʼ�ʺ����� 0
//    return 0;
//}

//BFS�������Թ�

////�ö��У����ǵݹ�
//
//#include <cstring>
//#include <algorithm>
//
//typedef pair<int, int> PII;  // �������������
//
//const int N = 110;  // ��������ߴ�
//
//int n, m;           // ���������������
//int g[N][N];        // �洢�������ݣ�0��ʾ��ͨ����1��ʾ�ϰ�
//int d[N][N];        // �洢����㵽ÿ�������̾���
//PII q[N * N];       // BFSʹ�õĶ���
//PII Prev[N][N];     // �洢ÿ�����ǰ���ڵ㣬���ڻ���·��
//
//int bfs()
//{
//    int hh = 0, tt = 0;      // ���е�ͷ��βָ��
//    q[0] = { 0, 0 };           // ���г�ʼ�������(0,0)���
//
//    memset(d, -1, sizeof d);  // ��ʼ����������Ϊ-1����ʾδ���ʣ�
//    d[0][0] = 0;             // ��������Ϊ0
//
//    // �ĸ�������ƶ��������ϡ��ҡ��¡���
//    int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };
//
//    while (hh <= tt)         // ���в�Ϊ��ʱѭ��
//    {
//        auto t = q[hh++];    // ȡ������Ԫ��
//
//        // ����ĸ����ڷ���
//        for (int i = 0; i < 4; i++)
//        {
//            int x = t.first + dx[i], y = t.second + dy[i];  // ������������
//
//            // ������ڵ��Ƿ���Ч��
//            // 1. ������Χ��
//            // 2. �ǿ�ͨ�е�(g[x][y] == 0)
//            // 3. δ�����ʹ�(d[x][y] == -1)
//            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
//            {
//                d[x][y] = d[t.first][t.second] + 1;  // ���¾���
//                Prev[x][y] = t;                       // ��¼ǰ���ڵ�
//                q[++tt] = { x, y };                    // ���������
//            }
//        }
//    }
//
//    // ���յ���ݵ���㣬���·��
//    int x = n - 1, y = m - 1;  // ���յ㿪ʼ
//    while (x || y)              // ��û�ص����ʱ����
//    {
//        cout << x << ' ' << y << endl;  // �����ǰ����
//        auto t = Prev[x][y];            // ��ȡǰ���ڵ�
//        x = t.first, y = t.second;      // �ƶ���ǰ���ڵ�
//    }
//
//    return d[n - 1][m - 1];  // ���ص��յ����̾���
//}
//
//int main()
//{
//    cin >> n >> m;  // ��������ߴ�
//
//    // ������������
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//            cin >> g[i][j];
//
//    cout << bfs() << endl;  // ����BFS��������
//
//    return 0;
//}

//����DFS���

//#include <cstring>
//#include <algorithm>
//
//const int N = 100010, M = N * 2;  // N�����ڵ�����M��������(����ͼ��Ҫ����)
//
//int n, m;           // n:�ڵ�����, m:������
//int h[N], e[M], ne[M], idx;  // �ڽӱ�洢ͼ
//bool st[N];         // ������飬��¼�ڵ��Ƿ񱻷��ʹ�
//
//// ���һ����a->b
//void add(int a, int b)
//{
//    e[idx] = b;      // �洢�ڵ�b��ֵ
//    ne[idx] = h[a];   // �±ߵ�nextָ��ָ��aԭ���ĵ�һ����
//    h[a] = idx++;     // a��ͷָ��ָ���±ߣ�������idx������
//}
//
//// �����������������u�ǵ�ǰ�ڵ�
//void dfs(int u)
//{
//    st[u] = true;    // ��ǵ�ǰ�ڵ��ѱ�����
//
//    // ����u�������ڽӽڵ�
//    for (int i = h[u]; i != -1; i = ne[i])
//    {
//        int j = e[i];  // ��ȡ�ڽӽڵ�j
//
//        // ���jδ�����ʹ�����ݹ����
//        if (!st[j])
//            dfs(j);
//    }
//}
//
//int main()
//{
//    memset(h, -1, sizeof h);  // ��ʼ���ڽӱ�ͷָ��Ϊ-1(��ʾ��)
//
//    dfs(1);  // �ӽڵ�1��ʼ�����������
//
//    return 0;
//}

//�������ġ���DFS���

//#include <cstring>
//#include <algorithm>
//
//const int N = 100010, M = N * 2;  // N�����ڵ�����M��������(����ͼ��Ҫ����)
//
//int n;              // ���Ľڵ�����
//int h[N], e[M], ne[M], idx;  // �ڽӱ�洢���ṹ
//bool st[N];         // ������飬��¼�ڵ��Ƿ񱻷��ʹ�
//int ans = N;        // �洢���ս��(��С���������ͨ���С)����ʼ��Ϊ������ֵN
//
//// ���һ�������a-b
//void add(int a, int b)
//{
//    e[idx] = b;      // �洢�ڵ�b��ֵ
//    ne[idx] = h[a];   // �±ߵ�nextָ��ָ��aԭ���ĵ�һ����
//    h[a] = idx++;     // a��ͷָ��ָ���±ߣ�������idx������
//}
//
//// ������uΪ���������Ĵ�С��������ɾ��u��������ͨ���С
//int dfs(int u)
//{
//    st[u] = true;    // ��ǵ�ǰ�ڵ�u�ѱ�����
//
//    int sum = 1;      // sum��¼��uΪ���������Ĵ�С(����u�Լ�)����ʼΪ1
//    int res = 0;      // res��¼ɾ��u�󣬸�����ͨ���е�����С
//
//    // ����u�������ڽӽڵ�
//    for (int i = h[u]; i != -1; i = ne[i])
//    {
//        int j = e[i];  // ��ȡ�ڽӽڵ�j
//
//        if (!st[j])    // ���jδ�����ʹ�
//        {
//            int s = dfs(j);  // �ݹ������jΪ����������С
//            res = max(res, s); // ������j�Ĵ�С���������ͨ���С
//            sum += s;         // �ۼӵ�u��������С��
//        }
//    }
//
//    // ����ɾ��u���Ϸ���ͨ��Ĵ�С(n - sum)������res
//    res = max(res, n - sum);
//
//    // �õ�ǰres����ȫ����Сֵans
//    ans = min(ans, res);
//
//    return sum;  // ������uΪ���������Ĵ�С
//}
//
//int main()
//{
//    cin >> n;  // �������Ľڵ���
//    memset(h, -1, sizeof h);  // ��ʼ���ڽӱ�ͷָ��Ϊ-1(��ʾ��)
//
//    // ����n-1���ߣ�������
//    for (int i = 0; i < n - 1; i++)
//    {
//        int a, b;
//        cin >> a >> b;
//        add(a, b), add(b, a);  // ����ͼ��Ҫ���˫���
//    }
//
//    dfs(1);  // �ӽڵ�1��ʼ�����������(����ѡ����ڵ���Ϊ���)
//
//    cout << ans << endl;  // ������(ɾ�����ĺ������ͨ�����С���ܴ�С)
//
//    return 0;
//}

//ͼ�е�Ĳ㡪��BFS���

//#include <cstring>
//#include <algorithm>
//
//const int N = 100010;  // �������ڵ���
//
//int n, m;       // n-�ڵ�����m-����
//int h[N], e[N], ne[N], idx;  // �ڽӱ�洢ͼ��h-ͷ�ڵ����飬e-���յ����飬ne-��һ����������idx-��ǰ��������
//int d[N], q[N]; // d-�������飬q-����
//
//// ���һ����a��b�ı�
//void add(int a, int b)
//{
//    e[idx] = b;      // ��¼�ߵ��յ�
//    ne[idx] = h[a],  // �±�ָ��ԭ���ĵ�һ����
//        h[a] = idx++;    // ͷ�ڵ�ָ���±ߣ�����������
//}
//
//// BFS���������ؽڵ�1���ڵ�n����̾���
//int bfs()
//{
//    int hh = 0, tt = 0;  // ����ͷβָ��
//    q[0] = 1;           // ���г�ʼ�����ӽڵ�1��ʼ
//
//    memset(d, -1, sizeof d); // ��ʼ������Ϊ-1����ʾδ���ʣ�
//    d[1] = 0;               // ������Ϊ0
//
//    while (hh <= tt)        // ���в�Ϊ��ʱѭ��
//    {
//        int t = q[hh++];    // ȡ����ͷ�ڵ�
//        for (int i = h[t]; i != -1; i = ne[i]) // ����t�������ڽӽڵ�
//        {
//            int j = e[i];  // ��ȡ�ڽӽڵ�j
//            if (d[j] == -1) // ���jδ�����ʹ�
//            {
//                d[j] = d[t] + 1; // ����j�ľ��루���ڵ����+1��
//                q[++tt] = j;     // ��j�������
//            }
//        }
//    }
//
//    return d[n]; // ���ؽڵ�n�ľ��루������ɴ���Ϊ-1��
//}
//
//int main()
//{
//    cin >> n >> m;  // ����ڵ����ͱ���
//
//    memset(h, -1, sizeof h); // ��ʼ���ڽӱ�����ͷ�ڵ�Ϊ-1��
//
//    for (int i = 0; i < m; i++) // �������б�
//    {
//        int a, b;
//        cin >> a >> b;
//        add(a, b);  // ��ӱ�a��b��ע����������ͼ��
//    }
//
//    cout << bfs() << endl; // ������
//
//    return 0;
//}

//����ͼ����������

//#include <cstring>
//#include <algorithm>
//
//const int N = 100010;  // �������ڵ���
//
//int n, m;       // n-�ڵ�����m-����
//int h[N], e[N], ne[N], idx;  // �ڽӱ�洢ͼ
//int q[N], d[N]; // q-���У�d-�������
//
//// ���һ����a��b�������
//void add(int a, int b)
//{
//    e[idx] = b,      // ��¼�ߵ��յ�b
//        ne[idx] = h[a],  // �±�ָ��ԭ���ĵ�һ����
//        h[a] = idx++;    // ͷ�ڵ�ָ���±ߣ�����������
//}
//
//// �����������������Ƿ�����������
//bool topsort()
//{
//    int hh = 0, tt = -1;  // ����ͷβָ�루��ʼ����Ϊ�գ�
//
//    // 1. ���������Ϊ0�Ľڵ�������
//    for (int i = 1; i <= n; i++)
//        if (!d[i])        // ����ڵ�i�����Ϊ0
//            q[++tt] = i;  // �������
//
//    // 2. BFS��������еĽڵ�
//    while (hh <= tt)      // ���в�Ϊ��ʱѭ��
//    {
//        int t = q[hh++];  // ȡ����ͷ�ڵ�t
//
//        // ����t�������ڽӽڵ�
//        for (int i = h[t]; i != -1; i = ne[i])
//        {
//            int j = e[i];  // ��ȡ�ڽӽڵ�j
//            d[j]--;        // j����ȼ�1���൱��ɾ����t��j��
//
//            if (d[j] == 0) // ���j����ȱ�Ϊ0
//                q[++tt] = j; // ��j�������
//        }
//    }
//
//    // 3. �ж��Ƿ����нڵ㶼������
//    // ���������������n���ڵ㣬˵����������ɹ�
//    return tt == n - 1;
//}
//
//int main()
//{
//    cin >> n >> m;  // ����ڵ����ͱ���
//
//    memset(h, -1, sizeof h); // ��ʼ���ڽӱ�����ͷ�ڵ�Ϊ-1��
//
//    // �������б߲�����ͼ����ȱ�
//    for (int i = 0; i < m; i++)
//    {
//        int a, b;
//        cin >> a >> b;
//        add(a, b);  // ��ӱ�a��b
//        d[b]++;    // b����ȼ�1
//    }
//
//    // ִ����������������
//    if (topsort())  // �������������
//    {
//        // ����������У�����q�д洢�ľ����������У�
//        for (int i = 0; i < n; i++)
//            printf("%d ", q[i]);
//        puts("");
//    }
//    else            // ���ڻ����޷���������
//        puts("-1");
//
//    return 0;
//}

//����Dijkstra�㷨 O(n^2)��������ͼ

//#include <cstring>
//#include <algorithm>
//
//const int N = 510;
//
//int n, m;          // n: ������, m: ����
//int g[N][N];        // �ڽӾ���洢ͼ
//int dist[N];        // dist[i] ��ʾ�ڵ� 1 ���ڵ� i ����̾���
//bool st[N];         // st[i] ��ǽڵ� i �Ƿ���ȷ�����·��
//
//int dijkstra()
//{
//    // ��ʼ�����о���Ϊ�����0x3f3f3f3f��
//    memset(dist, 0x3f, sizeof dist);
//    dist[1] = 0;    // ��㵽����ľ���Ϊ 0
//
//    // ���� n �Σ�ÿ��ȷ��һ���ڵ�����·��
//    for (int i = 0; i < n; i++)
//    {
//        int t = -1;
//        // �ҵ�δȷ�����·���Ľڵ��о����������Ľڵ� t
//        for (int j = 1; j <= n; j++)
//            if (!st[j] && (t == -1 || dist[t] > dist[j]))
//                t = j;
//
//        st[t] = true; // ��ǽڵ� t �����·����ȷ��
//
//        // �ýڵ� t ��������δȷ���ڵ�ľ���
//        for (int j = 1; j <= n; j++)
//            dist[j] = min(dist[j], dist[t] + g[t][j]);
//    }
//
//    // ����յ� n �ľ���δ�����£�˵�����ɴ�
//    if (dist[n] == 0x3f3f3f3f) return -1;
//    return dist[n]; // ������㵽�յ����̾���
//}
//
//int main()
//{
//    // ���붥���� n �ͱ��� m
//    scanf("%d%d", &n, &m);
//
//    // ��ʼ���ڽӾ��� g������ֵ��Ϊ�����0x3f3f3f3f��
//    memset(g, 0x3f, sizeof g);
//
//    // ��ȡ m ���ߵ���Ϣ
//    while (m--)
//    {
//        int a, b, c;
//        scanf("%d%d%d", &a, &b, &c);
//        // �洢��Ȩ��ȡ��Сֵ�����رߣ�
//        g[a][b] = min(g[a][b], c);
//    }
//
//    // ���� Dijkstra �㷨������ӽڵ� 1 ���ڵ� n ����̾���
//    int t = dijkstra();
//
//    // ������
//    printf("%d\n", t);
//
//    return 0;
//}

//���Ż���Dijkstra�㷨 O(mlogn)����ϡ��ͼ

//#include <cstring>
//#include <queue>
//
//typedef pair<int, int> PII;  // ���� pair ���ͣ��洢 {����, �ڵ���}
//
//const int N = 100010;        // �ڵ�������
//
//int n, m;                    // n: ������, m: ����
//int h[N], w[N], e[N], ne[N], idx;  // �ڽӱ�洢ͼ
//int dist[N];                 // dist[i] ��ʾ�ڵ� 1 ���ڵ� i ����̾���
//bool st[N];                  // st[i] ��ǽڵ� i �Ƿ���ȷ�����·��
//
//// ���һ���� a �� b �ıߣ���ȨΪ c
//void add(int a, int b, int c) {
//    e[idx] = b;              // �洢�յ� b
//    w[idx] = c;              // �洢��Ȩ c
//    ne[idx] = h[a];          // ���±߲�������ͷ��
//    h[a] = idx++;            // ����ͷָ�룬������ idx
//}
//
//int dijkstra() {
//    memset(dist, 0x3f, sizeof dist);  // ��ʼ�����о���Ϊ�����
//    dist[1] = 0;                      // ��㵽����ľ���Ϊ 0
//
//    // ����С���ѣ��������С��������
//    priority_queue<PII, vector<PII>, greater<PII>> heap;
//    heap.push({ 0, 1 });                // ����� {0, 1} ���
//
//    while (heap.size()) {
//        auto t = heap.top();           // ȡ����ǰ������С�Ľڵ�(�Ż���)
//        heap.pop();
//
//        int ver = t.second, distance = t.first;  // ver: �ڵ���, distance: ��ǰ����
//        if (st[ver]) continue;        // �����ȷ�����·��������
//
//        st[ver] = true;               // ��� ver �����·����ȷ��
//
//        // ���� ver �������ڱ�
//        for (int i = h[ver]; i != -1; i = ne[i]) {
//            int j = e[i];             // �ڽӽڵ� j
//            // �ɳڲ��������ͨ�� ver �� j �ľ������
//            if (dist[j] > distance + w[i]) {
//                dist[j] = distance + w[i];
//                heap.push({ dist[j], j });  // ���¾������
//            }
//        }
//    }
//
//    if (dist[n] == 0x3f3f3f3f) return -1;  // �յ㲻�ɴ�
//    return dist[n];                        // ������̾���
//}
//
//int main() {
//    scanf("%d%d", &n, &m);    // ���붥���� n �ͱ��� m
//    memset(h, -1, sizeof h);  // ��ʼ���ڽӱ�ͷָ��Ϊ -1����ʾ������
//
//    while (m--) {
//        int a, b, c;
//        scanf("%d%d%d", &a, &b, &c);
//        add(a, b, c);         // ��ӱߣ������ر�ʱ�������⴦�����ȶ��л��Զ�ѡ�����·����
//    }
//
//    int t = dijkstra();       // ���� Dijkstra �㷨
//    printf("%d\n", t);        // ������
//    return 0;
//}

//Bellman-ford�㷨 O(mn)

//#include <cstring>
//#include <algorithm> 
//
//const int N = 510, M = 10010;  // ��󶥵����ͱ���
//int n, m, k;                   // n:������, m:����, k:��ྭ���ı���
//int dist[N], backup[N];         // dist:��������, backup:��������
//
//struct Edge {
//    int a, b, w;                // �ߵĽṹ��:���a,�յ�b,Ȩ��w
//}edges[M];                      // �洢���бߵ�����
//
//int bellman_ford() {
//    memset(dist, 0x3f, sizeof dist);  // ��ʼ������Ϊ"�����"
//    dist[1] = 0;                      // ��㵽�Լ��ľ���Ϊ0
//
//    // ���ѭ������·������������k
//    for (int i =0 ; i < k; i++) {
//        memcpy(backup, dist, sizeof dist);  // ������һ�ֵľ���
//
//        // �������б߽����ɳڲ���
//        for (int j = 0; j < m; j++) {
//            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
//            dist[b] = min(dist[b], backup[a] + w);  // �ɳڲ���
//        }
//    }
//
//    // �ж��Ƿ�ɴ�
//    if (dist[n] > 0x3f3f3f3f / 2) return -1;  // ���Ǹ�Ȩ�ߵ�Ӱ��
//    return dist[n];  // ������̾���
//}
//
//int main() {
//    scanf("%d%d%d", &n, &m, &k);  // ���붥��������������������
//
//    // �������б�
//    for (int i = 0; i < m; i++) {
//        int a, b, w;
//        scanf("%d%d%d", &a, &b, &w);
//        edges[i] = { a, b, w };
//    }
//
//    int t = bellman_ford();  // �����㷨
//
//    if (t == -1) puts("impossible");  // ���ɴ�
//    else printf("%d\n", t);           // ������
//
//    return 0;
//}

//SPFA�㷨

//#include <cstring>
//#include <queue>
//#include <algorithm> 
//
//typedef pair<int, int> PII;  // ���� pair ���ͣ��洢 {����, �ڵ���}
//
//const int N = 100010;        // �ڵ�������
//
//int n, m;                    // n: ������, m: ����
//int h[N], w[N], e[N], ne[N], idx;  // �ڽӱ�洢ͼ
//int dist[N];                 // dist[i] ��ʾ�ڵ� 1 ���ڵ� i ����̾���
//bool st[N];                  // st[i] ��ǽڵ� i �Ƿ���ȷ�����·��
//
//// ���һ���� a �� b �ıߣ���ȨΪ c
//void add(int a, int b, int c) {
//    e[idx] = b;              // �洢�յ� b
//    w[idx] = c;              // �洢��Ȩ c
//    ne[idx] = h[a];          // ���±߲�������ͷ��
//    h[a] = idx++;            // ����ͷָ�룬������ idx
//}
//
//int spfa()
//{
//    memset(dist, 0x3f, sizeof dist); // ��ʼ�����нڵ����Ϊ"�����"
//    dist[1] = 0; // ���(����Ϊ1)������ľ���Ϊ0
//
//    queue<int> q;   // ������������SPFA�㷨
//    q.push(1);      // ������
//    st[1] = true;   // �������ڶ�����
//
//    while (q.size()) // �����в�Ϊ��ʱѭ��
//    {
//        int t = q.front(); // ȡ�����׽ڵ�
//        q.pop();           // ���׽ڵ����
//        st[t] = false;    // ��Ǹýڵ��Ѳ��ڶ�����
//
//        // �����ڵ�t�������ڽӱ�
//        for (int i = h[t]; i != -1; i = ne[i])
//        {
//            int j = e[i]; // ��ȡ�ڽӽڵ�j
//            // ���ͨ��t��j��·���ȵ�ǰ��֪�ĸ���
//            if (dist[j] > dist[t] + w[i])
//            {
//                dist[j] = dist[t] + w[i]; // ���µ�j����̾���
//                if (!st[j]) // ���j���ڶ�����
//                {
//                    q.push(j);  // j���
//                    st[j] = true; // ���j�ڶ�����
//                }
//            }
//        }
//    }
//
//    // ����յ�n�Ƿ�ɴ�
//    if (dist[n] == 0x3f3f3f3f) // ����������ǳ�ʼ����"�����"
//        return -1; // ���ɴ�
//    return dist[n]; // ������̾���
//}
//
//int main()
//{
//    scanf("%d%d", &n, &m); // ����ڵ���n�ͱ���m
//
//    memset(h, -1, sizeof h); // ��ʼ���ڽӱ�-1��ʾ��
//
//    // �������б�
//    while (m--)
//    {
//        int a, b, c;
//        scanf("%d%d%d", &a, &b, &c); // ����һ�������a->b��Ȩ��c
//        add(a, b, c); // ��ӵ��ڽӱ�
//    }
//
//    int t = spfa(); // ����SPFA�㷨�������·��
//
//    if (t == -1)
//        puts("impossible"); // ���ɴ�
//    else
//        printf("%d\n", t); // �����̾���
//
//    return 0;
//}

//Floyd�㷨����O(n^3)

//#include <cstring>   // ����memset���ڴ��������
//#include <algorithm> // ����min���㷨����
//
//const int N = 210, INF = 1e9; // ���峣����
//// N-���ڵ���(210)
//// INF-��ʾ�����(10^9)
//
//int n, m, Q;        // �������壺
//// n-�ڵ�����
//// m-������
//// Q-��ѯ����
//
//int d[N][N];        // �������d��d[i][j]��ʾi��j����̾���
//
//void floyd()
//{
//    // ����ѭ��������̾���
//    for (int k = 1; k <= n; k++)        // ö����ת�ڵ�k
//        for (int i = 1; i <= n; i++)    // ö�����i
//            for (int j = 1; j <= n; j++) // ö���յ�j
//                // ״̬ת�Ʒ��̣��Ƚ�ֱ��·����ͨ��k��ת��·��
//                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//    // ���i->k->j�ȵ�ǰi->j·�����̣������
//}
//
//int main()
//{
//    // ����ڵ���n������m�Ͳ�ѯ����Q
//    scanf("%d%d%d", &n, &m, &Q);
//
//    // ��ʼ���������
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= n; j++)
//            if (i == j)
//                d[i][j] = 0;    // �ڵ㵽����ľ���Ϊ0
//            else
//                d[i][j] = INF;   // ��ʼʱ����������Ϊ�����
//
//    // �������б���Ϣ
//    while (m--)
//    {
//        int a, b, w;
//        scanf("%d%d%d", &a, &b, &w); // ����һ����a��b�ıߣ�Ȩ��w
//        d[a][b] = min(d[a][b], w);   // ������رߣ�����Ȩ����С��
//        // ע�⣺����������ͼ�����������ͼ��Ҫ����d[b][a] = min(d[b][a], w);
//    }
//
//    floyd(); // ����Floyd�㷨�������нڵ�Ե����·��
//
//    // �����ѯ
//    while (Q--)
//    {
//        int a, b;
//        scanf("%d%d", &a, &b); // �����ѯ�����a���յ�b
//
//        // �ж��Ƿ�ɴ�
//        if (d[a][b] > INF / 2)
//            puts("impossible"); // �������INF/2��Ϊ���ɴ�
//        else
//            printf("%d\n", d[a][b]); // �����̾���
//    }
//
//    return 0;
//}

//���ذ�Prim����O(n^2)

//#include <cstring>
//#include <algorithm>
//
//const int N = 510, INF = 0x3f3f3f3f;
//
//int n, m;       // n-������, m-����
//int g[N][N];    // �ڽӾ���洢ͼ
//int dist[N];    // �洢���㵽��ǰ��С�������ľ���
//bool st[N];     // ��Ƕ����Ƿ��Ѽ�����С������
//
//int prim()
//{
//    memset(dist, 0x3f, sizeof dist);  // ��ʼ�����о���Ϊ�����
//
//    int res = 0;  // �洢��С��������Ȩֵ��
//
//    // ѭ��n�Σ�ÿ�μ���һ�����㵽MST��
//    for (int i = 0; i < n; i++)
//    {
//        int t = -1;  // t�洢��ǰ����MST����Ķ���
//
//        // �ҳ�δ����MST�Ķ����о���MST����Ķ���
//        for (int j = 1; j <= n; j++)
//            if (!st[j] && (t == -1 || dist[t] > dist[j]))
//                t = j;
//
//        // ������ǵ�һ��ѭ��(i=0�ǳ�ʼ��)���������ΪINF��˵��ͼ����ͨ
//        if (i && dist[t] == INF) return INF;
//
//        // ������ǵ�һ��ѭ�������ñ�Ȩֵ������
//        if (i) res += dist[t];
//
//        // �����������㵽MST�ľ���
//        for (int j = 1; j <= n; j++)
//            dist[j] = min(dist[j], g[t][j]);
//
//        st[t] = true;  // ��Ƕ���t�Ѽ���MST
//    }
//
//    return res;  // ������С��������Ȩֵ��
//}
//
//int main()
//{
//    scanf("%d%d", &n, &m);  // ���붥�����ͱ���
//
//    memset(g, 0x3f, sizeof g);  // ��ʼ���ڽӾ���Ϊ�����
//
//    // ����m����
//    while (m--)
//    {
//        int a, b, c;
//        scanf("%d%d%d", &a, &b, &c);
//        g[a][b] = g[b][a] = min(g[a][b], c);  // ����ͼ���洢��С��Ȩ
//    }
//
//    int t = prim();  // ����Prim�㷨
//
//    if (t == INF) puts("impossible");  // ͼ����ͨ���޷�����MST
//    else printf("%d\n", t);  // ���MSTȨֵ��
//
//    return 0;
//}

//Kruskal�㷨

//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 200010;  // ������
//
//int n, m;       // n-������, m-����
//int p[N];       // ���鼯���飬�����ж���ͨ��
//
//// �ߵĽṹ�嶨��
//struct Edge
//{
//    int a, b, w;  // a��b�Ǳߵ��������㣬w�Ǳߵ�Ȩֵ
//
//    // ����С������������ڱ߰�Ȩֵ����
//    bool operator< (const Edge& W)const
//    {
//        return w < W.w;  // ��Ȩֵ��С��������
//    }
//}edges[N];  // �洢���бߵ�����
//
//// ���鼯��find��������·��ѹ��
//int find(int x)
//{
//    if (p[x] != x) p[x] = find(p[x]);  // ·��ѹ��
//    return p[x];
//}
//
//int main()
//{
//    scanf("%d%d", &n, &m);  // ���붥�����ͱ���
//
//    // �������б�
//    for (int i = 0; i < m; i++)
//    {
//        int a, b, w;
//        scanf("%d%d%d", &a, &b, &w);
//        edges[i] = { a, b, w };
//    }
//
//    sort(edges, edges + m);  // �����б߰�Ȩֵ��С��������
//    // sort�������ε���Edge��operator<���Ƚϱߣ��ȽϷ�ʽ���ǱȽϱߵ�w(Ȩֵ)��Ա
//
//    // ��ʼ�����鼯��ÿ���������Լ��ĸ��ڵ�
//    for (int i = 1; i <= n; i++) p[i] = i;
//
//    int res = 0, cnt = 0;  // res-��С������Ȩֵ�ͣ�cnt-��ѡ����
//
//    // �������б�
//    for (int i = 0; i < m; i++)
//    {
//        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
//
//        a = find(a), b = find(b);  // �ҵ���������ĸ��ڵ�
//
//        // ����������㲻��ͬһ���ϣ�˵�����������߲����γɻ�
//        if (a != b)
//        {
//            p[a] = b;    // �ϲ���������
//            res += w;    // �ۼӱ�Ȩ
//            cnt++;     // ��ѡ����+1
//        }
//    }
//
//    // ��С������Ӧ��n-1���ߣ�����˵��ͼ����ͨ
//    if (cnt < n - 1) puts("impossible");
//    else printf("%d\n", res);  // �����С������Ȩֵ��
//
//    return 0;
//}

//�ж϶���ͼ����Ⱦɫ��

//#include <cstring>
//#include <algorithm>
//
//const int N = 100010, M = 200010;  // N����󶥵�����M��������
//
//int n, m;       // n:��������m:����
//int h[N], e[M], ne[M], idx;  // �ڽӱ�洢ͼ
//int color[N];    // �洢ÿ���������ɫ(1��2)
//
//void add(int a, int b)
//{
//    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//    // ��b��ӵ�a���ڽӱ���
//    // e[idx]�洢�ߵ��յ�b
//    // ne[idx]ָ��aԭ���ĵ�һ����
//    // h[a]����Ϊָ�������±�
//    // idx����Ϊ��һ������׼��
//}
//
//bool dfs(int u, int c)
//{
//    color[u] = c;  // ������uȾ����ɫc
//
//    // ����u�������ڽӶ���
//    for (int i = h[u]; i != -1; i = ne[i])
//    {
//        int j = e[i];  // �ڽӶ���j
//
//        if (!color[j])  // ���jû�б�Ⱦɫ
//        {
//            // �ݹ�ȾɫjΪ��һ����ɫ(3-c)
//            // ���Ⱦɫʧ�ܣ�����false
//            if (!dfs(j, 3 - c)) return false;
//        }
//        else if (color[j] == c)  // ���j�Ѿ���Ⱦɫ����ɫ��u��ͬ
//        {
//            return false;  // ���Ƕ���ͼ
//        }
//    }
//    return true;  // �����ڽӶ��㶼�ɹ�Ⱦɫ
//}
//
//int main()
//{
//    scanf("%d%d", &n, &m);  // ��ȡ������n�ͱ���m
//    memset(h, -1, sizeof h); // ��ʼ���ڽӱ�
//
//    // ��ȡ���б߲�����ͼ
//    while (m--)
//    {
//        int a, b;
//        scanf("%d%d", &a, &b);
//        add(a, b), add(b, a);  // ����ͼ�����˫���
//    }
//
//    bool flag = true;  // ����Ƿ��Ƕ���ͼ
//
//    // �������ж���
//    for (int i = 1; i <= n; i++)
//        if (!color[i])  // �������iû�б�Ⱦɫ
//        {
//            // ��i��ʼDFSȾɫ����ʼ��ɫΪ1
//            // ���Ⱦɫʧ�ܣ�����flagΪfalse���˳�ѭ��
//            if (!dfs(i, 1))
//            {
//                flag = false;
//                break;
//            }
//        }
//
//    if (flag) puts("Yes");  // �Ƕ���ͼ
//    else puts("No");        // ���Ƕ���ͼ
//
//    return 0;
//}

//����ͼ���ƥ���������������㷨

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;  // N��ʾ������������M��ʾ�ߵ��������

int n1, n2, m;      // n1�Ƕ���ͼ�󲿵�����n2���Ҳ�������m���ܱ���
int h[N], e[M], ne[M], idx;  // �ڽӱ��ͼ��h��ͷ�ڵ����飬e�洢�ߵ��յ㣬ne��nextָ��
int match[N];       // match[j] = x ��ʾ�Ҳ���j��ǰƥ����󲿵���x
bool st[N];         // st[j]����Ҳ���j�Ƿ��ڵ�ǰDFS�б����ʹ��������ظ�������

// ���һ����aָ��b�ıߣ��󲿵�a �� �Ҳ���b��
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// ����Ϊ�󲿵�x��һ��ƥ����Ҳ���
bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {  // ����x�������ڽӱ�
        int j = e[i];                         // j�ǵ�ǰ�Ҳ���
        if (!st[j]) {                         // ���jδ�����ʹ�
            st[j] = true;                      // ���Ϊ�ѷ���
            // ���jδ��ƥ�䣬����j�ĵ�ǰƥ�������ҵ��µ�ƥ��
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;                  // ��jƥ���x
                return true;                   // ƥ��ɹ�
            }
        }
    }
    return false;  // �����ڽӵ㶼�޷�ƥ��
}

// ����Ϊ�󲿵�x��һ��ƥ����Ҳ���
bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {  // ����x�������ڽӱ�
        int j = e[i];                         // j�ǵ�ǰ�Ҳ���
        if (!st[j]) {                         // ���jδ�����ʹ�
            st[j] = true;                      // ���Ϊ�ѷ���
            // ���jδ��ƥ�䣬����j�ĵ�ǰƥ�������ҵ��µ�ƥ��
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;                  // ��jƥ���x
                return true;                   // ƥ��ɹ�
            }
        }
    }
    return false;  // �����ڽӵ㶼�޷�ƥ��
}

int main() {
    scanf("%d%d%d", &n1, &n2, &m);  // �����󲿵���n1���Ҳ�����n2������m
    memset(h, -1, sizeof h);         // ��ʼ���ڽӱ�ͷ�ڵ�ȫ����-1��

    // ������бߣ��󲿵� �� �Ҳ��㣩
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);  // ע�⣺����Ĭ���ǵ���ߣ�����ͼ����ң�
    }

    int res = 0;  // ��¼���ƥ����
    for (int i = 1; i <= n1; i++) {  // ���������󲿵�
        memset(st, false, sizeof st); // ÿ��DFSǰ��շ��ʱ��
        if (find(i)) res++;           // ���i���ҵ�ƥ�䣬���+1
    }

    printf("%d\n", res);  // ������ƥ����
    return 0;
}