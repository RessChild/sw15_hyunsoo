#include<iostream>
#include<algorithm>
using namespace std;
// ȫ���̿� ��Ÿ��
// ���� �������� ���������� Ǯ���� �õ�
// but, ����ó���� �ʹ� ������ �ð��ʰ�

int stick, roller; // ���� ��, �ѷ� ��
int r_count, brush; // �ѷ��� Ƚ��, ĩ���� �ؾ��ϴ� ����
int success[1000000]; // ĥ�ϴµ� ������ ���� ����
int height[1000000]; // ���� ���� üũ

int main() {
	cin >> stick >> roller; // �� �Է�
	for (int k = 0; k < stick; k++)
		cin >> height[k]; // ���̰� �Է�

	int index = 0; // ���� �ε��� ��ġ
	int last_h = 0; // ���������� ĥ�� ����
	bool out = false; // ������ ����

	while (!out) { //��� ��ƽ�� �� �� �� ����
		// ���⼭ ����ó�� �ʿ�
		if (index >= stick) // ĥ�ϴ� ������ ũ�⸦ ������� ����
			break;

		if (last_h >= height[index]) { // ���� �ִ� ���̺��� ���� �������� ĥ�ߴٸ�
			last_h = height[index]; // ������ ĥ�� ����� �ִ� �̾߱�
			int add = 0;
			for (int k = 0; k < roller && height[index] >= last_h; k++) {
				// ���� ���̰� ������ �� ĥ��
				success[index + add] = last_h;
				if ( height[index] == last_h) //���̰� ������쿡�� �� ĥ������ �ε��� �̵�
					index += 1; // ������ �ű�鼭
				else
					add++;

				if (index + add >= stick) {
					out = true;
					break;
				}
			}
		}
		else {
			if (index + roller >= stick)
				out = true; // �̹��� ����
			int* mini;

			if (!out) // ���� ���� ���� ��������
				mini = min_element(&height[index], &(height[index]) + roller);
			//���� ��ġ~ �ѷ��� ���� �� �ִ� �� ����
			else // ���� �������̸�
				mini = min_element(&height[stick - roller], &(height[stick]));
				// �ѷ��� �� �� �ִ� �ִ� ũ�⸸ŭ �о����
			for (int k = 0; k < roller; k++)
				success[index + k] = max(success[index + k], *mini);
			// �̹� ĥ���� ���� �̹��� ĥ�� �� �� ū ������ ����
			last_h = *mini; // ���������� ĥ�� �� ����
			index = (mini - height); // �� �ּ��� ���̰� = �ε��� ��ȣ
				// ���� �ش� ��ġ�� �̹� �� ĥ�ѻ��� -> ���� ��ġ�� �Ѿ (+1)

			while (index != stick && success[index] == height[index])
				index++; //������ �����ʰ� �� ĥ�� ���ڸ� ����Ű�� ������ �������� �ѱ�
		}
		r_count++; 
	}
	for (int k = 0; k < stick; k++)
		brush += height[k] - success[k]; // ĥ�ؾ� �ϴ� ���� ����
	cout << brush << endl << r_count << endl; // ���
}

// ������� : ���������� ���밡 ���� ��, ���̰� ª�Ƽ� ��ĥ�ϰ� �� ��� -> ����ó�� �ʿ�