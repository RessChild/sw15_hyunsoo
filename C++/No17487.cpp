#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
// Ÿ�ڿ���

string str; // ���ڿ��� �Է¹���

int main() {

	int left, right, check; //����, ������, �й� ������ ��
	left = right = check = 0; // �� 0���� ����
	
	getline(cin,str); //getline �� ���� ������ ������ ���� �Է�
	for (int k = 0; k < str.size(); k++) { // �� ���ڿ� ����
		char a = str.at(k);
	
		switch (a) { 
		case 'q': // ���� ���̸� (�ҹ��� ����)
		case 'w':
		case 'e':
		case 'r':
		case 't':
		case 'y':

		case 'a':
		case 's':
		case 'd':
		case 'f':
		case 'g':

		case 'z':
		case 'x':
		case 'c':
		case 'v':
		case 'b':
			left += 1; // ���� +1
			break;
		case 'u': // ������ ���̸� (�ҹ��� ����)
		case 'i':
		case 'o':
		case 'p':

		case 'h':
		case 'j':
		case 'k':
		case 'l':

		case 'n':
		case 'm':
			right += 1;
			break;
		case ' ': // ������ ���
			check += 1; // üũ +1
			break;
		default: // �� ���� ��� (�빮��)
			check += 1; // üũ +1
			switch (a) // ���������� �ٽ� ��, �츦 ����
			{
			case 'Q':
			case 'W':
			case 'E':
			case 'R':
			case 'T':
			case 'Y':

			case 'A':
			case 'S':
			case 'D':
			case 'F':
			case 'G':

			case 'Z':
			case 'X':
			case 'C':
			case 'V':
			case 'B':
				left += 1;
				break;
			case 'U':
			case 'I':
			case 'O':
			case 'P':

			case 'H':
			case 'J':
			case 'K':
			case 'L':

			case 'N':
			case 'M':
				right += 1;
				break;
			}
			break;
		}
	}

	while (check != 0) { // �й谡���� ���� 0�� �ɶ����� �õ�
		int minus = left - right; // �� ���� ���̸� ���
		if (minus > 0) { // ��� = ������ �� ����
			int add = min(minus, check); // ���� ���� ���� ��, �������� ����
			check -= add; 
			right += add; //����
		}
		else if(minus < 0){ // ���� = �������� �� ����
			int add = min(-1 * minus, check);
			check -= add;
			left += add; // ����
		}
		else { // ���� ���, �޼����̹Ƿ� �޼� +1
			check -= 1;
			left += 1;
		}
	}

	cout << left << " " << right; // ���
}