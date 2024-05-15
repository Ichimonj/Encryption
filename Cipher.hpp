#include<iostream>
using namespace std;
//Caesar Cipher
//Øטפנ Öוחאנÿ

/*
int main() {
	string msg = "dead reckoning";
	int    kay = 3;

	string coding   = Caesar::coding(msg, kay);
	cout << coding << endl;   //ghdg#uhfnrqlqj

	string decoding = Caesar::decoding(coding, kay);
	cout << decoding << endl; //dead reckoning
}
*/

namespace Caesar {
	//encryption
	string coding(const string& str, int shift) {
		string codingStr;
		for (size_t i = 0; i < str.size(); i++) {
			codingStr.push_back(str[i] + shift);
		}
		return codingStr;
	}


	//decryption
	string decoding(const string& str, int shift) {
		string codingStr;
		for (size_t i = 0; i < str.size(); i++) {
			codingStr.push_back(str[i] - shift);
		}
		return codingStr;
	}
}