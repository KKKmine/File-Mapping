#include <iostream>
#include <string>
#include "FileMapping.h"
using namespace std;

int main() {
	FileMapping fm("hello");
	if (fm.isOpen()) {
		int mode;
		cout << "Sender input 0, Recvier input 1 : ";
		cin >> mode;
		// Sender
		if (mode == 0) {
			char msg[] = "_ YOOOOOOOOOOOOOOOO Hello";
			fm.SendMsg(msg, (strlen(msg) + 1) * sizeof(char), true);

			int num[] = { 0, 20, 30, 5 };
			fm.SendMsg(num, 4 * sizeof(int), true);
		}
		// Recvier
		else {
			char msg[50];
			fm.RecvMsg(msg, 50 * sizeof(char), true);
			cout << "Get Message : " << msg << "\n";

			int num[10];
			int getSize = fm.RecvMsg(num, 10 * sizeof(int), true);
			cout << "Get Message : ";
			for (int i = 0; i < getSize / sizeof(int); i++) {
				cout << num[i] << " ";
			}
			cout << "\n";
		}
	}
	else {
		cout << "File Mapping Failed\n";
	}
	system("pause");
	return 0;
}