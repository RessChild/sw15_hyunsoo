// ���м���

#include<iostream>
using namespace std;
int main() {
	int vacation;
	int lang, math, cando_l, cando_m;
	cin >> vacation >> math >> lang >> cando_m >> cando_l;
	//�� �Է¹ް�
	int need = lang / cando_l > math / cando_m ? (lang + cando_l - 1) / cando_l : (math + cando_m - 1) / cando_m;
		//�� ��� �� �� ū ���� ����
		// �� �������� �ʴ� �̻�, �������� ���ؼ��� �Ϸ縦 �� �Һ��ؾ���.
		// but, �ܼ��� ����� +1�� �ϱ� ���ؼ� ������ ���������� Ȯ���ϴ� ������ �ʿ�,
		// ���� �ذ��� ���� �Ϲ�ȭ�� ������ ǥ��
	cout << vacation - need << endl;
}