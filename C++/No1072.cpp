#include<iostream>
using namespace std;
// ����
// ���ϴ� ���� ���� ������ �Ǵ��ؾ��ϹǷ�, �̺� Ž���� ���
// but, �� �ܿ� ������ ���� ��굵 ����

// ���� �������� int ������ �ѱ� �� ������,
// long long int �� ������� �ڵ� �ۼ�

#define MAX 1000000000 // �Ǵ� �ִ밪

long long int X, Y;
int Z;

bool Cal(long long int mid) { 
	int new_Z = (int)(((Y + mid) * 100) / (X + mid));
	return new_Z == Z; // �����Ѱ��� �Ǵ�
}

int main() {
	cin >> X >> Y;

	Z = (int)((Y * 100) / X); // ���� Ȯ��

	long long int f = 0, b = MAX;
	while (f <= b) { // �̺� Ž�� (�Ķ��Ʈ�� ��ġ)
		long long int mid = (f + b) / 2;
		if (Cal(mid)) f = mid + 1;
		else b = mid - 1;
	}

	if (f > MAX) f = -1; // ���� ���� �ִ밪�� �Ѿ�� -1
	cout << f << endl;
}