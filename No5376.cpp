#include<iostream>
#include<string>
using namespace std;
// �Ҽ��� �м���
// �־��� ���ѼҼ��� �м��� ǥ���ϱ� ���ؼ�
// �ݺ� ������ �����ϴ� ����� ��Ģ�� ���

long long int G(long long int a, long long int b) { // ��Ŭ���� ȣ���� (GCD)
	while (b != 0) {
		long long int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int loop;
	cin >> loop;

	for (int k = 0; k < loop; k++) {
		string str;
		cin >> str; // ��ȣ�� ���ԵǹǷ� ���ڿ� ���·� �Է�

		bool flag = false;
		long long int val = 0;
		long long int mul = 1; // �� �ݺ�����
		long long int a_val = 0;
		long long int a_mul = 1; // �ݺ�����
		for (int m = 2; m < str.length(); m++) { // �Էµ� ���ڿ��� ����
			switch (str[m]) {
			case '(': // ��ȣ�� ��� ���ѱ��� ����
				flag = true;
				break;
			case')': // ��ȣ�� ���� ��� ����ó��
				break;
			default: // �� ���� ��� ���� ���ں�
				a_val *= 10; 
				a_val += str[m] - '0'; // ���� ���� ����

				if (flag) { // �ݺ������� ���
					a_mul *= 10;
				}
				else { // �� �ݺ������� ���
					val *= 10;
					val += str[m] - '0';
					mul *= 10;
				}
				break;
			}
		}

		long long int t_mul = mul * a_mul; // ��ü �и� ��
		if (!flag) { // �ݺ������� ���ٸ� ����, �и𿡼� �� ���� ����
			mul = 0;
			val = 0;
		}

		long long int prnt = t_mul - mul;
		long long int cld = a_val - val;
		long long int gcd = G(prnt, cld);
		cout << cld / gcd << "/" << prnt / gcd << endl; // ��ȣ�Ŀ� ���� ���� �� ���
	}
}
