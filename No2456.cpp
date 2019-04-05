#include<iostream>
using namespace std;
// ���� �б�ȸ���̴�
// ������ ����� ���о
// ������ �ƴ� "���"�� ���� �������� ����

int ticket[9];
// �� �ĺ� 1,2,3�� ���� ǥ�� ������ ����
// ���������� �����Ͽ� �ʱ�ȭ ���� (�ڵ� 0)
// 9���� �迭�� ������ ������ ���ó���� ����
// �ĺ� 1 = 0~2�� ��, �ĺ� 2 = 3~5�� ��, �ĺ� 3 = 6~8�� ��

int main() {
	int vote; // ��ǥ �ο� ��
	cin >> vote;
	for (int k = 0; k < vote; k++) {
		int rank; // �� �ĺ��� ���� ��ũ ��
		for (int i = 0; i < 3; i++) {
			cin >> rank;
			rank--; //��ũ�� ���� (�Է��� 1~3�̹Ƿ�)
			ticket[i * 3 + rank]++;
			//���������� �� ������ Ƽ�� ����
		}
	}

	int best = 0; 
	for (int i = 0; i < 3; i++)
		best += ticket[i] * (i + 1); // 1�� �ĺ��� �� ��
	int win = 0; // �켱 1�� �ĺ��� �̰�ٰ� ����

	for (int k = 1; k < 3; k++) {
		int compare = 0;
		for (int i = 0; i < 3; i++)
			compare += ticket[3 * k + i] * (i + 1);
			// ���� ���� ����� 1,2,3���� ������ ����

		if (best < compare) { // �񱳰��� �� ũ�� 
			best = compare;
			win = k; // ���� ����
		}
		else if (best == compare) { // ���� ���� ����

			for (int i = 0; i < 3; i++) {
				int save;
				if (win == -1) { //���� ����� ���
					// -1�����δ� �ε��� ������ �Ұ��ϹǷ�
					// 0���� ���� ��������
					// ������ ���൵, �ĺ� 1,2�� ������ ����
					save = 0;
				}
				else
					save = win;
				if (ticket[save * 3 + i] != ticket[k * 3 + i]) { // ���� �ʰ�
					if (ticket[save * 3 + i] < ticket[k * 3 + i]) {// ���� �� ���� ������ ����
						best = compare;
						win = k; // ���� ����
					}
					break; //�� �̻� �� �ʿ� ����
				}
				if (i == 2) { // ���޴ޱ��� �ôµ� ������ �ȳ��ٸ�
					//�γ��� ����
					win = -1; //�ϴ��� ���ڰ� ����
				}
			}
		}
	}
	cout << win + 1 <<" "<< best << endl; //���
}