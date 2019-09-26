#include <iostream>
#include <string>
#include <vector>
using namespace std;

void evaluatePostFix(string);

int main() {
	
	evaluatePostFix("4+4");

	system("pause");
	return 0;
}



/*
1. Read a string of a mathematical expression
2. Extract operands and operators and push them into a stack
3. Calculate the values starting from the top of the stack



*/

void evaluatePostFix(string par) {
	vector <char> stack;
	string postfixExp = "";
	/*string infixExp;*/
	for (char& ch : par) {
		if (isdigit(ch)) {
			stack.push_back(ch);
		}
		else {
			switch (ch) {
			case '+':
				cout << "A '+' was encountered." << endl;
			default:
				cout << "The end of the switch." << endl;
			}
		}
	}
	int stackSize = stack.size();
	for (int i = 0; i < stackSize; i++) {
		cout << stack[i] << ' ';
	} cout << endl;
}