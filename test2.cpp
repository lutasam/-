#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <queue>
using namespace std;


// 公共变量区
char* s = "a=a*(b+1)/2+#";	// 输入串

int currPos = 0;			// 当前分析的字符位置
int sentenceUsedNow = 0;	// 为每个语法的编号，0 - 5
string alreadyAnalyse;		// 记录已经分析的串
fstream outputFile;			// 输出文件

// 文法区（已消除左递归）
void S();					// S  -> str=B
void B(string& b);			// B  -> CB'
void Bp(string& bp);		// B' -> +CB' | -CB' | e
void C(string& c);			// C  -> DC'
void Cp(string& cp);		// C' -> *DC' | /DC' | e
void D(string& d);			// D  -> str | num | (B)


// 方法区
bool isNumber(string& str);			// 识别数字  num
bool isSymbol(string& str);			// 识别标识符 str
void output();				// 输出每一步分析

int main() {				// 入口主函数
	// 文件读入
	outputFile.open("output2.txt");
	cout << setw(20) << "文法" << setw(20) << "分析串" << setw(20) << "分析字符" << setw(20) << "\t剩余串" << setw(20) << endl;
	outputFile << setw(20) << "文法" << setw(20) << "分析串" << setw(20) << "分析字符" << setw(20) << "\t剩余串" << setw(20) << endl;

	// 开始递归分析
	S();

	// 结果输出
	if (s[currPos] == '#') {
		cout << setw(20) << "通过！";
		outputFile << setw(20) << "通过！";
	}
	else {
		cout << setw(20) << "不通过！";
		outputFile << setw(20) << "不通过！";
	}
	cout << endl;
	return 0;
}

// 赋值语句 S->str=B
void S() {
	string arg1 = "", arg2 = "";
	string str = "";
	if (isSymbol(str)) {
		sentenceUsedNow = 0;
		output();
		arg1 += str;
		alreadyAnalyse += str;
		currPos++;
		if (s[currPos] == '=') {
			output();
			alreadyAnalyse += s[currPos];
			currPos++;
			B(arg2);
			cout << endl << "逆波兰式为：";
			cout << arg1 << arg2 << '=' << endl << endl; // 逆波兰式输出
		}
	}
}

// 表达式 B->CBp
void B(string& b) {
	sentenceUsedNow = 1;
	output();
	string temp1 = "", temp2 = "";
	C(temp1);
	Bp(temp2);
	b += temp1 + temp2;
}

// Bp->+CBp|-CBp|e
void Bp(string& bp) {
	if (s[currPos] == '+' || s[currPos] == '-') {
		sentenceUsedNow = 2;
		output();
		char temp = s[currPos];
		alreadyAnalyse += s[currPos];
		currPos++;

		string temp1 = "", temp2 = "";
		C(temp1);
		Bp(temp2);
		bp += temp1 + temp2 + temp;
	}
}

// 项 C->DCp
void C(string& c) {
	sentenceUsedNow = 3;
	output();

	string temp1 = "", temp2 = "";
	D(temp1);
	Cp(temp2);
	c += temp1 + temp2;
}

// Cp->*DCp|/DCp|e
void Cp(string& cp) {
	if (s[currPos] == '*' || s[currPos] == '/') {
		sentenceUsedNow = 4;
		output();
		char temp = s[currPos];
		alreadyAnalyse += s[currPos];
		currPos++;

		string temp1 = "", temp2 = "";
		D(temp1);
		Cp(temp2);
		cp += temp1 + temp2 + temp;
	}
}

// 因子 D->str|num|(B)
void D(string& d) {
	string str = "";
	if (isSymbol(str) || isNumber(str)) {
		sentenceUsedNow = 5;
		output();
		d += str;
		alreadyAnalyse += str;
		currPos++;
	}
	else if (s[currPos] == '(') {
		sentenceUsedNow = 5;
		output();
		alreadyAnalyse += s[currPos];
		currPos++;

		string b = "";
		B(b);
		d += b;
		if (s[currPos] == ')') {
			sentenceUsedNow = 5;
			output();
			alreadyAnalyse += s[currPos];
			currPos++;
		}
		else {
			cout << "不通过！" << endl;
			outputFile << "不通过！" << endl;
			exit(0);
		}
	}
	else {
		cout << "不通过！" << endl;
		outputFile << "不通过！" << endl;
		exit(0);
	}
}

// 无符号整数
bool isNumber(string& str) {

	if (s[currPos] >= '0' && s[currPos] <= '9') {
		str += s[currPos];
		while (s[currPos + 1] >= '0' && s[currPos + 1] <= '9') {
			str += s[currPos + 1];
			currPos++;
		}
		return true;
	}
	else {
		return false;
	}
}

// 标识符
bool isSymbol(string& str) {
	if (s[currPos] >= 'a' && s[currPos] <= 'z') {
		str += s[currPos];
		while (s[currPos + 1] >= 'a' && s[currPos + 1] <= 'z') {
			str += s[currPos + 1];
			currPos++;
		}
		return true;
	}
	else {
		return false;
	}
}

void output() {
	// 文法
	switch (sentenceUsedNow) {
	case 0:
		cout << "S->str=B" << setw(20);
		outputFile << "S->str=B" << setw(20);
		break;
	case 1:
		cout << "B->CBp | -B" << setw(20);
		outputFile << "B->CBp" << setw(20);
		break;
	case 2:
		cout << "Bp->+CBp|-CBp|e" << setw(20);
		outputFile << "Bp->+CBp|-CBp|e" << setw(20);
		break;
	case 3:
		cout << "C->DCp" << setw(20);
		outputFile << "C->DCp" << setw(20);
		break;
	case 4:
		cout << "Cp->*DCp|/DCp|e" << setw(20);
		outputFile << "Cp->*DCp|/DCp|e" << setw(20);
		break;
	case 5:
		cout << "D->str|num|(B)" << setw(20);
		outputFile << "D->str|num|(B)" << setw(20);
		break;
	default:
		cout << "内部错误！" << endl;
		outputFile << "内部错误！" << endl;
		exit(0);
	}

	// 分析串
	cout << alreadyAnalyse << setw(20);
	outputFile << alreadyAnalyse << setw(20);

	// 分析字符
	cout << s[currPos] << setw(20);
	outputFile << s[currPos] << setw(20);

	// 剩余串
	for (int i = currPos + 1; i < s[i] != '\0'; i++) {
		cout << s[i];
		outputFile << s[i];
	}
	cout << setw(20) << endl;
	outputFile << setw(20) << endl;
}