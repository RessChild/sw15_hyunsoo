#include<iostream>
using namespace std;
// �ȳ�
// h,e,l,o,w �� ���� count �ϰ�
// ���� ���� ���� �����ϸ� ��

int main() {
	
	int loop;
	cin >> loop; // �׽�Ʈ ���̽�
	cin.get(); // getchar�� ������ ���ֱ� ���� ��������


	int answer[50] = {}; //�� ���̽� �� ����
	for (int k = 0; k < loop; k++) {
		
		int list[4] = {};
			// ���� �Ҵ�
			// ������� h, e, l, o
		while (true) {
			char get;
			cin.get(get);
			if (get != '\n') {
			
				switch (get) { // �� ������ ī��Ʈ
				case 'h':
					list[0]++;
					break;
				case 'e':
					list[1]++;
					break;
				case 'l':
					list[2]++;
					break;
				case 'o':
					list[3]++;
					break;
				default:
					break;
				}
			}
			else
				break;
		}


		int least = 10001; //�ּҰ�
		for (int i = 0; i < 4; i++) {
			if (i == 2 && list[i] / 2 < least) {
				least = list[i] / 2; // l�� ���� ����
			}
			else if (list[i] < least)
				least = list[i]; // �� ���� ���
		}
		answer[k] = least; // ���� ����
	}
	for (int k = 0; k < loop; k++)
		cout << "#" << k + 1 << " " << answer[k] << endl; // ���
}