// https://www.acmicpc.net/problem/2870
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// ó���� int�� ó���ߴµ�, ������ ���캸�� 100���� �̳��ε� ���ڰ� 100�ڸ��̸� ������ �����÷ο� �߻��̴�.
// string���� ó���ؾ��Ѵ�.
vector<string> v_num;
string number_1to9 = "123456789";
int n = 0;

void zero_rule(string &num_str, bool zero_flag) {
	if (num_str.size() != 0) {
		int pos, min_pos = 1004;
		for (char ch : number_1to9) {
			if ((pos = num_str.find(ch)) != string::npos) {
				zero_flag = false; // 0���θ� �̷������ �ƴϴ�.
				min_pos = min(min_pos, pos); // 0�̿��� ���ڰ� �����ϴ� ù �ε��� ���ϱ�.
			}
		}

		if (zero_flag == false) {
			num_str.erase(0, min_pos);
		}
		else {
			num_str = "0";	// 0 �������� 0 1���� �ʱ�ȭ.
		}
		v_num.push_back(num_str);
	}
}
bool cmp(const string& a, const string& b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	string gulza = "";
	for (int i = 0; i < n; i++) {
		cin >> gulza;
		string num_str = "";
		int gulza_size = gulza.size();
		int gulza_length = 0;
		bool zero_flag = true;

		for (char it : gulza) {
			gulza_length++;
	
			if (int(it) >= int('0') && int(it) <= int('9')) {
				num_str += it;
				zero_flag = true;
			}
			else {
				zero_rule(num_str, zero_flag);
				num_str = "";	// �ʱ�ȭ
			}

			// �������� ���� �� ��쿡�� vec�� push ���ش�. (it == *(gulza.end() - 1)) <- �̷��Ը� ���� ������ ������ �������� 33 �̷��� ������ ��� �ߺ����� �߰��ȴ�.
			// �׷��⿡ ���̵� ���� ���Ѵ�. (gulza_length == gulza_size) string�� ���������� ���̸� ���� Ȯ��.
			// �� ���ڿ� �߰���Ű�� �� ���ڿ��� �߰��ǰ� �ȴ�. ����, �� ���ڿ��� �ƴ� ��쵵 �˻��Ѵ�. (num_str.size() != 0)
			if (gulza_length == gulza_size && it == *(gulza.end() - 1) && num_str.size() != 0) {
				zero_rule(num_str, zero_flag);
			}
		}
	}

	sort(v_num.begin(), v_num.end(), cmp);
	for (auto& it : v_num) { cout << it << "\n";}

	return 0;
}

// ---------------------------------------------------------- �Լ�ȭ �Ƚ�Ű�� �� �ۼ��� �ڵ� -------------------------------------------------------------
//// https://www.acmicpc.net/problem/2870
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int n = 0;
//
//// ó���� int�� ó���ߴµ�, ������ ���캸�� 100���� �̳��ε� ���ڰ� 100�ڸ��̸� ������ �����÷ο� �߻��̴�.
//// string���� ó���ؾ��Ѵ�.
//vector<string> v_num;
//string number_1to9 = "123456789";
//
//bool cmp(const string& a, const string& b) {
//	if (a.size() == b.size()) return a < b;
//	return a.size() < b.size();
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n;
//	string gulza = "";
//	for (int i = 0; i < n; i++) {
//		cin >> gulza;
//		string num_str = "";
//		int gulza_size = gulza.size();
//		int gulza_length = 0;
//		bool zero_flag = true;
//
//		for (char it : gulza) {
//			gulza_length++;
//			
//			if (int(it) >= int('0') && int(it) <= int('9')) {
//				num_str += it;
//				zero_flag = true;
//			}
//			else {
//				if (num_str.size() != 0) {
//					int pos, min_pos = 1004;
//					for (char ch : number_1to9) {
//						if ( (pos = num_str.find(ch)) != string::npos) {
//							zero_flag = false; // 0���θ� �̷������ �ƴϴ�.
//							min_pos = min(min_pos, pos); // 0�̿��� ���ڰ� �����ϴ� ù �ε��� ���ϱ�.
//						}
//					}
//
//					if (zero_flag == false) {
//						num_str.erase(0, min_pos);
//					}
//					else {
//						num_str = "0";	// 0 �������� 0 1���� �ʱ�ȭ.
//					}
//					v_num.push_back(num_str);
//				}
//				num_str = "";	// �ʱ�ȭ
//			}
//
//			// �������� ���� �� ��쿡�� vec�� push ���ش�. (it == *(gulza.end() - 1)) <- �̷��Ը� ���� ������ ������ �������� 33 �̷��� ������ ��� �ߺ����� �߰��ȴ�.
//			// �׷��⿡ ���̵� ���� ���Ѵ�. (gulza_length == gulza_size) string�� ���������� ���̸� ���� Ȯ��.
//			// �� ���ڿ� �߰���Ű�� �� ���ڿ��� �߰��ǰ� �ȴ�. ����, �� ���ڿ��� �ƴ� ��쵵 �˻��Ѵ�. (num_str.size() != 0)
//			if (gulza_length == gulza_size && it == *(gulza.end() - 1) && num_str.size() != 0) {
//				if (num_str.size() != 0) {
//					int pos, min_pos = 1004;
//					for (char ch : number_1to9) {
//						if ((pos = num_str.find(ch)) != string::npos) {
//							zero_flag = false; // 0���θ� �̷������ �ƴϴ�.
//							min_pos = min(min_pos, pos); // 0�̿��� ���ڰ� �����ϴ� ù �ε��� ���ϱ�.
//						}
//					}
//
//					if (zero_flag == false) {
//						num_str.erase(0, min_pos);
//					}
//					else {
//						num_str = "0";	// 0 �������� 0 1���� �ʱ�ȭ.
//					}
//					v_num.push_back(num_str);
//				}
//			}
//		}
//	}
//
//	sort(v_num.begin(), v_num.end(), cmp);
//
//	for (auto& it : v_num) {
//		cout << it << "\n";
//	}
//
//	return 0;
//}