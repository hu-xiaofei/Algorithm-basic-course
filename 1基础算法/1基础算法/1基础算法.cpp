#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

//��������

//const int N = 1e6 + 10;
//
//int n;
//int q[N];
//
//// ��������Quick Sort������
//// ������
////   q[]: �����������
////   l: ��ǰ���������߽磨��ʼ������
////   r: ��ǰ��������ұ߽磨����������
//void quick_sort(int q[], int l, int r)
//{
//    // �ݹ���ֹ��������������鳤�� <= 1��l >= r����ֱ�ӷ���
//    if (l >= r) return;
//
//    // ѡȡ��׼ֵ��pivot��������ѡ������ߵ�Ԫ�� q[l]
//    int x = q[l];
//
//    // ��ʼ������ָ�룺
//    // i: ��������ɨ�裬��ʼ��Ϊ l-1������ѭ������������
//    // j: ��������ɨ�裬��ʼ��Ϊ r+1������ѭ�������Լ���
//    int i = l - 1, j = r + 1;
//
//    // ��ʼ������partition������
//    while (i < j)
//    {
//        // ���������ҵ�һ�� >= x ��Ԫ��
//        do i++; while (q[i] < x);
//
//        // ���������ҵ�һ�� <= x ��Ԫ��
//        do j--; while (q[j] > x);
//
//        // ��� i < j������������Ԫ�أ�ʹ����ߵ� <= x���ұߵ� >= x
//        if (i < j) swap(q[i], q[j]);
//    }
//
//    // �ݹ�������벿�֣�l �� j��
//    quick_sort(q, l, j);
//
//    // �ݹ������Ұ벿�֣�j+1 �� r��
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

//�鲢����

//const int N = 1000010;
//
//int n;
//int q[N], tmp[N];
//
//// �鲢����Merge Sort������
//// ������
////   q[]: �����������
////   l: ��ǰ���������߽磨��ʼ������
////   r: ��ǰ��������ұ߽磨����������
//// ʹ��ȫ�ֻ��ⲿ����ĸ������� tmp[] ���кϲ�����
//void merge_sort(int q[], int l, int r)
//{
//    // �ݹ���ֹ��������������鳤�� <= 1��l >= r����ֱ�ӷ���
//    if (l >= r) return;
//
//    // �����м�� mid���൱�� (l + r) / 2������λ�������Ч��
//    int mid = l + r >> 1;
//
//    // �ݹ�������벿�� [l, mid]
//    merge_sort(q, l, mid);
//
//    // �ݹ������Ұ벿�� [mid + 1, r]
//    merge_sort(q, mid + 1, r);
//
//    // ��ʼ�ϲ���merge������
//    int k = 0;          // tmp[] ������
//    int i = l;          // ��벿�ֵ���ʼָ��
//    int j = mid + 1;    // �Ұ벿�ֵ���ʼָ��
//
//    // �Ƚ����������ֵ�Ԫ�أ���������� tmp[]
//    while (i <= mid && j <= r)
//        if (q[i] <= q[j]) tmp[k++] = q[i++];  // ��벿��Ԫ�ؽ�С������ tmp
//        else tmp[k++] = q[j++];               // �Ұ벿��Ԫ�ؽ�С������ tmp
//
//    // �����벿�ֻ���ʣ��Ԫ�أ�ֱ�ӷ��� tmp[]
//    while (i <= mid) tmp[k++] = q[i++];
//
//    // ����Ұ벿�ֻ���ʣ��Ԫ�أ�ֱ�ӷ��� tmp[]
//    while (j <= r) tmp[k++] = q[j++];
//
//    // ������õ� tmp[] ���ƻ�ԭ���� q[] �� [l, r] ����
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

//�������ֲ���

//bool check(int x) {/* ... */ } // ���x�Ƿ�����ĳ������
//
//// ����[l, r]�����ֳ�[l, mid]��[mid + 1, r]ʱʹ�ã�
//int bsearch_1(int l, int r)
//{
//    while (l < r)
//    {
//        int mid = l + r >> 1;
//        if (check(mid)) r = mid;    // check()�ж�mid�Ƿ���������
//        else l = mid + 1;
//    }
//    return l;
//}
//// ����[l, r]�����ֳ�[l, mid - 1]��[mid, r]ʱʹ�ã�
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

//����������

//bool check(double x) {/* ... */ } // ���x�Ƿ�����ĳ������
//
//double bsearch_3(double l, double r)
//{
//    const double eps = 1e-6;   // eps ��ʾ���ȣ�ȡ������Ŀ�Ծ��ȵ�Ҫ��
//    while (r - l > eps)
//    {
//        double mid = (l + r) / 2;
//        if (check(mid)) r = mid;
//        else l = mid;
//    }
//    return l;
//}

//�߾��ȼӷ�

//#include<vector>
//
//// C = A + B, A >= 0, B >= 0
//vector<int> add(vector<int>& A, vector<int>& B) {
//
//    // ��֤ A �ǽϳ��������򻯺�������
//    if (A.size() < B.size()) return add(B, A);
//
//    vector<int> C;  // �洢���
//    int t = 0;      // ��λ����ʼ 0��
//
//    // ��λ���
//    for (int i = 0; i < A.size(); i++) {
//        t += A[i];                   // �� A �ĵ�ǰλ
//        if (i < B.size()) t += B[i]; // �� B �ĵ�ǰλ��������ڣ�
//        C.push_back(t % 10);         // ��ǰλ���
//        t /= 10;                    // �����λ
//    }
//
//    // �������λ��λ
//    if (t) C.push_back(t);
//
//    return C;
//}
//
//int main()
//{
//	string a, b;
//	vector<int> A, B;
//	cin >> a >> b;//�������� "123" �� "456"
//
//    // ���ַ�������洢�� vector����λ��ǰ��
//	for (int i = a.size() - 1; i >= 0; i--)
//        A.push_back(a[i] - '0'); // "123" �� A = [3, 2, 1]
//	for (int i = b.size() - 1; i >= 0; i--)
//        B.push_back(b[i] - '0'); // "456" �� B = [6, 5, 4]
//
//	auto C = add(A, B);
//
//    // �����������λ��ǰ��
//	for (int i = C.size() - 1; i >= 0; i--)
//        printf("%d", C[i]); // ������� "579"
//	return 0;
//
//}

//�߾��ȼ���

#include<vector>

bool cmp(vector<int>& A, vector<int>& B) {
    // �Ƚ�λ��
    if (A.size() != B.size())
        return A.size() > B.size();

    // �Ӹ�λ����λ��λ�Ƚ�
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i])
            return A[i] > B[i];
    }
    return true;  // A == B
}

vector<int> sub(vector<int>& A, vector<int>& B) {
    vector<int> C;
    int t = 0;  // ��λ��־

    for (int i = 0; i < A.size(); i++) {
        t = A[i] - t;          // ��ȥ��λ
        if (i < B.size())
            t -= B[i];         // ��ȥ B �ĵ�ǰλ

        C.push_back((t + 10) % 10);  // ������
        //push_back���ڶ�̬����ĩβ���Ԫ��
        if (t < 0) t = 1;      // ��Ҫ��λ
        else t = 0;            // �����λ
    }

    // ȥ��ǰ���㣨���� "100" - "99" = "001" �� ����Ϊ "1"��
    while (C.size() > 1 && C.back() == 0)
        C.pop_back(); //pop_back��ɾ����̬��������һ��Ԫ��

    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b;  // �����ַ�����ʽ�Ĵ�����

    // ���ַ�������洢Ϊ vector����λ��ǰ��
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');  // "123" �� [3, 2, 1]
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    // ȷ�� A >= B�������账����
    if (cmp(A, B)) {
        auto C = sub(A, B);
        // ��������������λ��ǰ��
        for (int i = C.size() - 1; i >= 0; i--)
            printf("%d", C[i]);
    }
    else {
        auto C = sub(B, A);
        printf("-");  // ���Ϊ��
        for (int i = C.size() - 1; i >= 0; i--)
            printf("%d", C[i]);
    }
}