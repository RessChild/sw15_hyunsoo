#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// ��ɲ�
// ���� ������ ����� ����Ͽ�
// �ش� ������ ���� �ʿ��� �κи� Ȯ���ذ��� ����� ä��

class XY {
public:
	int x, y;
	XY() {}
	XY(int i_x, int i_y);
};

int sand, ani, length; // ��� ��, ���� ��, �����Ÿ�
vector<int> s_pos; // ����� ��ġ ����
vector<XY> a_pos; // ������ ��ġ����

int main() {
	cin >> sand >> ani >> length; // ��� ��, ���� ��, �����Ÿ� �Է�
	for (int k = 0; k < sand; k++) {
		int a;
		cin >> a;
		s_pos.push_back(a); // �� �����ġ �Է�
	}
	s_pos.push_back(2000000000); // ���� ������ ���� �� ���� �� ���� ���� �߰�
	// �ݺ������� ����ó���� ����ȭ�ϱ� ����
	
	for (int k = 0; k < ani; k++) {
		int x, y;
		cin >> x >> y;
		a_pos.push_back(XY(x, y)); // ������ ��ġ������ ����
	}

	sort(s_pos.begin(), s_pos.end()); // ��� ����
	sort(a_pos.begin(), a_pos.end(), [](XY a, XY b)->bool { // ���� ����
		if (a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	}); // x,y ���ؿ� ���� 

	int ans = 0, check[2] = { 0,1 }; // ���� �� �ִ� ���� ��, ��� ��ȣ
	for (int k = 0; k < a_pos.size(); k++) { //��� ������ �� ���鼭
		while (s_pos[check[1]] <= a_pos[k].x) { // �켱 ���δ� ���� ���� ������ �ݺ�
			// ������ ���� ���� �� ���� �� �����Ƿ� ���� x
			check[0]++;
			check[1]++; // ��� ��ĭ �� ������ �̵�
		} // �ش� ������ �������� �� �� ��밡 ������

		for (int i = 0; i < 2; i++) { // �� ��뿡�� ������ �� �� �ִ��� Ȯ��
			if (abs(s_pos[check[i]] - a_pos[k].x) + a_pos[k].y <= length) {
				ans++; // ���� �� ������ �� ����
				break; // �ݺ��� ��
			}
		}
	}

	cout << ans << endl; // ���
}

XY::XY(int i_x, int i_y) {
	x = i_x;
	y = i_y;
}