#include<iostream>
#include<vector>
using namespace std;
// �Ҽ��� ������
// �迭�� �κ����� �Ǵ��ϴ� ������ ������ Ǯ�� ��� (��������)

#define MAX 4000001

bool arr[MAX];
vector<int> v; // �Ҽ��� ������ ����

void eratos() { // �����佺�׳׽��� ü
	for (int k = 2; k < MAX; k++) {
		if (arr[k]) continue;
		v.push_back(k);
		for (int m = 2; m * k < MAX; m++) {
			arr[m * k] = true;
		}
	}
}

int main() {
	eratos(); // �Ҽ� ȹ��

	int num;
	cin >> num;

	int f = 0, b = 0, sum = 0, cnt = 0;
	while (f != v.size() && v[f] <= num) { // ��� �Ҽ��� ���캸��
		if (sum < num && b < v.size()) sum += v[b++];
		else sum -= v[f++]; // ���� ũ�⿡ ���� ��,�� �����͸� �̵�

		if (sum == num) cnt++; // ���ϴ� ���̸� Ƚ�� ����
	}

	cout << cnt << endl;
}