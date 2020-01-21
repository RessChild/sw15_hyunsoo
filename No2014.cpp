#include<iostream>
#include<queue>
#include<functional>
using namespace std;
// �Ҽ��� ��
// ������ ��� ���տ� ���� �켱���� ť�� ���
// but, push ���ǿ� ������ ���� �ʾƼ� �޸𸮰� ������ ������ �߻�

int arr[100]; // �Է� ���� ������ �迭
priority_queue<int,vector<int>,greater<int>> pq; // �������� �켱���� ť

int main() {
	int loop, idx;
	cin >> loop >> idx;

	for (int k = 0; k < loop; k++) {
		cin >> arr[k];
		pq.push(arr[k]); // ť�� ����
	}

	long long int num = 0;
	long long int before = 0;
	while (idx) { // ��ȣ�� ��ġ�� ������
		num= pq.top(); // �����͸� �ϳ� ��������
		pq.pop();
		if (num == before) continue; // ������ �ô��Ͱ� �����ϸ� �ǳʶ� (�ߺ� Ȯ��)
		for (int k = 0; k < loop; k++) {
			long long int n = arr[k] * num; // ���� ���� ���� ������ ��� ���� ����
			if (n < 2147483648) // ũ�������� �δ� ������ ť�� �ʹ� Ŀ���� ������ ����
				// so, ���ʿ��� �����ʹ� push ���� �ʾƼ� �ӵ��� ����
				pq.push((int)n); // �Էµ� �Ҽ����� ���� ť�� �߰�
		}
		before = num; //����
		idx--; // ��ȣǥ ����
	}
	cout << num << endl;
}