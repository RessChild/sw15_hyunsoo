#include<iostream>
using namespace std;
// �ø���
// �޴� ���� ���� �� ������ ��� ����
// ���� �� ����� ����ϴ� ����� ������������
// ��� ���ܻ����� �ʹ� ũ�԰ɷ���
// �ִ��� Ǯ�̹���� �ܼ�ȭ


class Country { //����
public:
	int ident; //�ĺ���ȣ
	int gold; //�ݸ޴� ��
	int silver; //���޴�
	int bronze; //���޴�
	Country(); //������
};

int main() {
	int count; // ���� ���� ��
	int num; //�˰���� ���� ��ȣ
	cin >> count >> num;

	Country** part = new Country*[count]; //������ �����Ҵ�
	// ���� ������ �迭�� �Ҵ��� ������
	// ���� �������� ���Ǹ� ���ؼ�
	int pos; //���� ���ϴ� target�� ����ִ� ��ġ����
	for (int k = 0; k < count; k++) {
		part[k] = new Country();

		if (part[k]->ident == num) //���� ����� �˾ƾ��ϴ� ���̸�
			pos = k;
	}
	
	{
		Country* save = part[pos];
		part[pos] = part[0];
		part[0] = save; // ù��° ��� ���� ã�� ������ ���� ��ü
	}

	int rank = 1; //�ϴ� 1����� ����
	for (int k = 1; k < count; k++) {
		if (part[0]->gold < part[k]->gold) {
			//���� �ݸ޴��� �� ������
			rank++; //��ũ ����
		}
		else if (part[0]->gold == part[k]->gold) {
			//���� ���, ���޴޿� ���ؼ� �ݺ�����
			if (part[0]->silver < part[k]->silver) {
				rank++;
			}
			else if (part[0]->silver == part[k]->silver) {
				//���� ���, ���޴޷� ����
				if (part[0]->bronze < part[k]->bronze) {
					rank++;
				}
					//���� ���, �� �༮�� ��� ���� ����
					//so, ��ũ�� ���� x
			}
		}
	}
	
	cout << rank << endl;

	for (int k = 0; k < count; k++)
		delete part[k];
	delete[] part; //�޸� ����
}

Country::Country() {
	cin >> ident >> gold >> silver >> bronze; //�� �Է�
}