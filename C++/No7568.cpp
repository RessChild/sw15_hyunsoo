// ��ġ
// ���ı����� Ȯ���ؼ� ������ Ǯ�����ߴµ�
// �׷��� ���� �ܼ� ��, ������� �ذ��� ����
// but, �ٸ� ����� ���� �� ���� ����

#include<iostream>
using namespace std;

class Size {
public:
	int weight, height; //Ű, ������
	Size();
	Size(int i_w, int i_h);
};

Size* list[50]; //�ִ� 50��
int order[50]; //���� ��Ͽ�

int main() {
	int people;
	cin >> people; //��� ��

	for (int k = 0; k < people; k++) {
		int i_w, i_h;
		cin >> i_w >> i_h;
		list[k] = new Size(i_w, i_h); //��� ������ ��ü�� ����� �迭�� ����
	}

	for (int i = 0; i < people; i++) {
		order[i]++; //�ϴ� ��� 1������ ���� (1���� ����)
		for (int k = 0; k < people; k++) { //������ �õ��� ����
			if (list[i]->weight < list[k]->weight) {
				// �ڿ� ���� ���� ���԰� ���ʺ��� ���ſ��
				if (list[i]->height < list[k]->height) { //�����Ե� Ȯ��
					order[i]++; // ������ ��ġū�ְ� �ϳ� ������
				}
			}
		} //���� ��
	}
	
	for (int k = 0; k < people; k++) {
		cout << order[k] << endl; //��� ���
	}
}

Size::Size() {}
Size::Size(int i_w, int i_h) {
	weight = i_w;
	height = i_h;
}