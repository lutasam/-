//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <string>
//#include <stack>
//#include <vector>
//#include <fstream>
//
//using namespace std;
//
//// 四元式
//class FourElement {
//public:
//	FourElement() {}
//	FourElement(string op, string arg1, string arg2, string result) {
//		this->op = op;
//		this->arg1 = arg1;
//		this->arg2 = arg2;
//		this->result = result;
//	}
//	string op;	// 操作符
//	string arg1;  // 参数1
//	string arg2;  // 参数2
//	string result;  // 变量
//};
//
//// 公共变量区
//const char* reserveWord[] = { "int", "for" };  // 关键字（只考虑int和for）
//// LR(1)分析表
//char* lr1[][19] = {
//"0","0","0","0","0","S2","0","0","0","0","0","0","0","0","0","0","0","0","1",
//"acc","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","S3","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","S5","0","0","0","0","0","4","0","0","0","0","0","0",
//"0","0","0","S6","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","S7","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","S12","0","S11","0","0","0","0","8","0","0","10","9","0",
//"0","0","0","0","0","0","S16","0","S15","0","0","0","0","0","0","0","14","13","0",
//"0","0","0","S17","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","0","0","0","S18","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","0","S19","0","R7","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","0","R8","0","R8","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","0","R9","0","R9","0","0","0","0","0","0","0","0","0",
//"0","0","0","R4","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","R7","0","0","0","S20","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","R8","0","0","0","R8","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","R9","0","0","0","R9","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","S22","0","0","0","0","0","21","0","0","0","0","0","0",
//"0","0","0","0","0","0","S16","0","S15","0","0","0","0","0","0","0","14","23","0",
//"0","0","0","0","0","0","S12","0","S11","0","0","0","0","0","0","0","10","24","0",
//"0","0","0","0","0","0","S16","0","S15","0","0","0","0","0","0","0","14","25","0",
//"0","0","S26","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","S27","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","R5","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","0","0","0","R6","0","0","0","0","0","0","0","0","0",
//"0","0","0","R6","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","0","0","0","0","S28","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","S32","0","S31","0","0","0","0","0","0","0","30","29","0",
//"0","0","0","0","0","S36","S5","0","0","0","0","0","37","0","33","35","0","0","34",
//"0","0","R4","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","R7","0","0","0","0","S38","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","R8","0","0","0","0","R8","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","R9","0","0","0","0","R9","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","0","0","0","0","0","S39","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","0","0","0","0","0","R2","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","0","0","0","0","0","R3","0","0","0","0","0","0","0",
//"0","S40","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","S41","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","S32","0","S31","0","0","0","0","0","0","0","30","42","0",
//"R1","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","S5","0","0","0","0","0","43","0","0","0","0","0","0",
//"0","0","0","0","0","0","S5","0","0","0","0","R10","37","0","0","44","0","0","0",
//"0","0","R6","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","S45","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","0","0","0","0","0","R11","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","S12","0","S11","0","0","0","0","46","0","0","10","9","0",
//"0","0","0","S47","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","S22","0","0","0","0","0","48","0","0","0","0","0","0",
//"0","0","S49","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","0","0","0","0","S50","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","S36","S5","0","0","0","0","0","37","0","51","35","0","0","34",
//"0","0","0","0","0","0","0","0","0","0","0","S52","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","0","0","0","0","0","R1","0","0","0","0","0","0","0"
//};
//stack<int> state_stack;		// 状态栈
//stack<string> op_stack;		// 符号栈
//stack<string> arg_stack;	// 操作数栈
//stack<int> judge_stack;		// 判断语义栈
//vector<FourElement> increaseList; // for第三项语义栈
//vector<FourElement> fourElements; // 四元式vector
//string currSymbol = "";		// 读取的字符
//string tempS = "";			// 文件中读取字符的临时变量
//string head = "T";			// 四元式变量名
//int currElement = 1;		// 变量名的个数
//string headF = "F";
//int currF = 1;
//bool hasBeenReducedByB = false;
//bool isFirst = true;
//
//bool needRead = true;		// 读入 | 时为false
//bool isReadOK = true;		// 是否结束语法分析
//int hasBeenReduced = 0;		// 规约状态
//int state = 0;				// 当前的状态
//
//
//// 词法分析
//bool isReverseWord(char str[]);
//bool isNumber(char c);
//bool isLetter(char c);
//
//// 语法分析
//void pop(int n);			// 状态栈出栈n个
//void wrong(int state, int col);	// 语法分析出错
//void shift(int state);		// 移位
//void r1();					// r1规约
//void r2();					// r2规约
//void r3();					// r3规约
//void r4();					// r4规约
//void r5();					// r5规约
//void r6();					// r6规约
//void r7();					// r7规约
//void r8();					// r8规约
//void r9();					// r9规约
//void r10();					// r10规约
//void r11();					// r11规约
//void success();				// 分析成功
//
//// 总控程序
//void wordAnalyse();
//void translate();
//
//
//int main() {				// 入口主函数
//	wordAnalyse();
//	translate();
//	return 0;
//}
//
//// 保留字
//bool isReverseWord(char str[])
//{
//	for (int i = 0; i < 2; i++)
//	{
//		if (strcmp(reserveWord[i], str) == 0)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//// 数字
//bool isNumber(char c)
//{
//	if (c >= '0' && c <= '9')
//	{
//		return true;
//	}
//	return false;
//}
//
//// 字母
//bool isLetter(char c)
//{
//	if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
//	{
//		return true;
//	}
//	return false;
//}
//
//// 运算符
//bool isOperator(char c)
//{
//	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '%' || c == '^' || c == '&' || c == '|' || c == '!' || c == '<' || c == '>')
//	{
//		return true;
//	}
//	return false;
//}
//
//// 界符
//bool isBounder(char c)
//{
//	if (c == ',' || c == ';' || c == '(' || c == ')' || c == '{' || c == '}' || c == '#' || c == '\'' || c == '\"')
//	{
//		return true;
//	}
//	return false;
//}
//
//// 有点小问题  最好每个字符前后加个空格分割  否则有可能会出错
//void wordAnalyse() {
//	cout << "========================================" << endl;
//	cout << "词法分析" << endl;
//	cout << "========================================" << endl;
//	FILE* inputFile = fopen("words.txt", "r");
//	ofstream outputFile("wordAnalyseResult.txt");
//	ofstream nextFile("refinedWords.txt");
//
//	nextFile << "| ";
//
//	char c;
//	while ((c = fgetc(inputFile)) != EOF)
//	{
//		if (c != ' ')
//		{
//			if (isLetter(c) || c == '_')
//			{
//				int i = 1;
//				char str[100];
//				str[0] = c;
//				while ((c = fgetc(inputFile)) != EOF && c != ' ' && !isBounder(c) && (isLetter(c) || isNumber(c) || c == '_' || c == '.'))
//				{
//					str[i++] = c;
//				}
//				if (!isBounder(c) && c != ' ') {
//					cout << "错误" << endl;
//					outputFile << "错误" << endl;
//					exit(0);
//				}
//				str[i] = '\0';
//				if (isReverseWord(str))
//				{
//					if (strcmp("for", str) == 0) {
//						nextFile << '0' << ' ' << "for" << " | ";
//						cout << "保留字:\t" << "<0, " << str << '>' << endl;
//						outputFile << "保留字:\t" << "<0, " << str << '>' << endl;
//					}
//					else {
//						nextFile << '5' << ' ' << "int" << " | ";
//						cout << "保留字:\t" << "<5, " << str << '>' << endl;
//						outputFile << "保留字:\t" << "<5, " << str << '>' << endl;
//					}
//				}
//				else
//				{
//					nextFile << '3' << ' ' << str << " | ";
//					cout << "标识符:\t" << "<3, " << str << '>' << endl;
//					outputFile << "标识符:\t" << "<3, " << str << '>' << endl;
//				}
//			}
//			if (isNumber(c))
//			{
//				int i = 1;
//				bool alreadyHasE = false;
//				bool alreadyHasPoint = false;
//				bool alreadyHasMinus = true;
//				char str[100];
//				str[0] = c;
//				while ((c = fgetc(inputFile)) != EOF)
//				{
//					if (c != ' ' && !isBounder(c) && isNumber(c)) {
//						str[i++] = c;
//					}
//					else if (c == '.' && !alreadyHasPoint) {
//						str[i++] = c;
//					}
//					else if ((c == 'e' || c == 'E') && !alreadyHasE) {
//						str[i++] = c;
//						alreadyHasPoint = false;
//						alreadyHasMinus = false;
//					}
//					else if (c == '-' && !alreadyHasMinus) {
//						str[i++] = c;
//					}
//					else {
//						break;
//					}
//				}
//				if (!isBounder(c) && c != ' ') {
//					cout << "错误" << endl;
//					outputFile << "错误" << endl;
//					exit(0);
//				}
//				else {
//					str[i] = '\0';
//					nextFile << '4' << ' ' << str << " | ";
//					cout << "常量数:\t" << "<4, " << str << '>' << endl;
//					outputFile << "常量数:\t" << "<4, " << str << '>' << endl;
//				}
//			}
//			if (isOperator(c))
//			{
//				if (c == '=') {
//					nextFile << '2' << ' ' << '=' << " | ";
//					cout << "赋值符:\t" << "<2, " << c << c << '>' << endl;
//					outputFile << "赋值符:\t" << "<2, " << c << c << '>' << endl;
//				}
//				else if (c == '>' || c == '<') {
//					nextFile << '6' << ' ' << c;
//					char ano_c = fgetc(inputFile);
//					if (ano_c == '=') {
//						nextFile << ano_c;
//						cout << "逻辑符:\t" << "<6, " << c << ano_c << '>' << endl;
//						outputFile << "逻辑符:\t" << "<6, " << c << ano_c << '>' << endl;
//					}
//					else {
//						cout << "逻辑符:\t" << "<6, " << c << '>' << endl;
//						outputFile << "逻辑符:\t" << "<6, " << c << '>' << endl;
//					}
//					nextFile << " | ";
//				}
//				else {
//					nextFile << '1' << ' ' << c << " | ";
//					cout << "运算符:\t" << "<1, " << c << '>' << endl;
//					outputFile << "运算符:\t" << "<1, " << c << '>' << endl;
//				}
//			}
//			if (isBounder(c))
//			{
//				if (c == '(') {
//					nextFile << '8' << ' ' << c << " | ";
//					cout << "界限符:\t" << "<8, " << c << '>' << endl;
//					outputFile << "界限符:\t" << "<8, " << c << '>' << endl;
//				}
//				else if (c == ')') {
//					nextFile << '9' << ' ' << c << " | ";
//					cout << "界限符:\t" << "<9, " << c << '>' << endl;
//					outputFile << "界限符:\t" << "<9, " << c << '>' << endl;
//				}
//				else if (c == '{') {
//					nextFile << 'X' << ' ' << c << " | ";
//					cout << "界限符:\t" << "<X, " << c << '>' << endl;
//					outputFile << "界限符:\t" << "<X, " << c << '>' << endl;
//				}
//				else if (c == '}') {
//					nextFile << 'Y' << ' ' << c << " | ";
//					cout << "界限符:\t" << "<Y, " << c << '>' << endl;
//					outputFile << "界限符:\t" << "<Y, " << c << '>' << endl;
//				}
//				else if (c == ';') {
//					nextFile << 'Z' << ' ' << c << " | ";
//					cout << "界限符:\t" << "<Z, " << c << '>' << endl;
//					outputFile << "界限符:\t" << "<Z, " << c << '>' << endl;
//				}
//			}
//		}
//	}
//	nextFile << '7' << ' ' << '#' << ' ';
//	cout << "词法分析通过！" << endl;
//	cout << "========================================" << endl;
//	fclose(inputFile);
//	outputFile.close();
//	nextFile.close();
//}
//
//void pop(int n) {
//	for (int i = 0; i < n; i++) {
//		state_stack.pop();
//	}
//	state = state_stack.top();
//}
//
//void wrong(int state, int col)
//{
//	cout << "语法错误！" << endl;
//	cout << "当前状态为：" << state << " 错误访问LR(1)表的第" << col << "列，此时读入字符为：" << currSymbol << endl;
//	exit(0);
//}
//
//// 移位
//void shift(int s) {
//	state = s;
//	state_stack.push(s);
//}
//
//void r1() {
//	printf("用(1)S->for(A;B;A){C}归约\n");
//	currSymbol = "S";
//	pop(11);
//	hasBeenReduced = 2;
//}
//
//void r2() {
//	cout << "用(2)C->S归约\n";
//	currSymbol = "C";
//	pop(1);
//	hasBeenReduced = 2;
//
//	fourElements.push_back(increaseList[increaseList.size() - 2]);
//	fourElements.push_back(increaseList[increaseList.size() - 1]);
//	increaseList.erase(increaseList.end() - 1);
//	increaseList.erase(increaseList.end() - 1);
//
//	string op = "JUMP";
//	string arg2 = "_";
//	string arg1 = "_";
//	string result = "(" + to_string(judge_stack.top()) + ")";
//	judge_stack.pop();
//	arg_stack.push(head + to_string(currElement));
//	FourElement newfourElement1(op, arg1, arg2, result);
//	fourElements.push_back(newfourElement1);
//}
//
//void r3() {
//	cout << "用(3)C->D归约\n";
//	currSymbol = "C";
//	pop(1);
//	hasBeenReduced = 2;
//
//	fourElements.push_back(increaseList[increaseList.size() - 2]);
//	fourElements.push_back(increaseList[increaseList.size() - 1]);
//	increaseList.erase(increaseList.end() - 1);
//	increaseList.erase(increaseList.end() - 1);
//
//	string op = "JUMP";
//	string arg2 = "_";
//	string arg1 = "_";
//	string result = "(" + to_string(judge_stack.top()) + ")";
//	judge_stack.pop();
//	arg_stack.push(head + to_string(currElement));
//	FourElement newfourElement1(op, arg1, arg2, result);
//	fourElements.push_back(newfourElement1);
//}
//
//void r4() {
//	if (hasBeenReducedByB) {
//		string op = op_stack.top(); op_stack.pop();
//		string arg2 = "_";
//		string arg1 = arg_stack.top(); arg_stack.pop();
//		string result = arg_stack.top(); arg_stack.pop();
//		FourElement newfourElement(op, arg1, arg2, result);
//		increaseList.push_back(newfourElement);
//
//		hasBeenReducedByB = false;
//	}
//	else {
//		string op = op_stack.top(); op_stack.pop();
//		string arg2 = "_";
//		string arg1 = arg_stack.top(); arg_stack.pop();
//		string result = arg_stack.top(); arg_stack.pop();
//		FourElement newfourElement(op, arg1, arg2, result);
//		fourElements.push_back(newfourElement);
//	}
//
//	cout << "用(4)A->i=F归约\n";
//	currSymbol = "A";
//	pop(3);
//	hasBeenReduced = 2;
//}
//
//void r5() {
//	string op = op_stack.top(); op_stack.pop();
//	string arg2 = arg_stack.top(); arg_stack.pop();
//	string arg1 = arg_stack.top(); arg_stack.pop();
//	string result = head + to_string(currElement);
//	arg_stack.push(head + to_string(currElement));
//	FourElement newfourElement1(op, arg1, arg2, result);
//	fourElements.push_back(newfourElement1);
//	judge_stack.push(fourElements.size() - 1);
//	currElement++;
//
//	if (isFirst) {
//		op = "JZ";
//		arg2 = "_";
//		arg1 = arg_stack.top(); arg_stack.pop();
//		result = "Exit";
//		FourElement newfourElement2(op, arg1, arg2, result);
//		fourElements.push_back(newfourElement2);
//		isFirst = false;
//	}
//	else {
//		op = "JZ";
//		arg2 = "_";
//		arg1 = arg_stack.top(); arg_stack.pop();
//		result = increaseList[increaseList.size()-2].result;
//		FourElement newfourElement2(op, arg1, arg2, result);
//		fourElements.push_back(newfourElement2);
//	}
//
//	//op = "JNZ";
//	//arg2 = "_";
//	//result = head + to_string(currElement+1);
//	//FourElement newfourElement3(op, arg1, arg2, result);
//	//fourElements.push_back(newfourElement3);
//
//	printf("用(5)B->FrF\n");
//	currSymbol = "B";
//	pop(3);
//	hasBeenReduced = 2;
//	hasBeenReducedByB = true;
//}
//
//void r6() {
//	if (hasBeenReducedByB) {
//		string op = op_stack.top(); op_stack.pop();
//		string arg2 = arg_stack.top(); arg_stack.pop();
//		string arg1 = arg_stack.top(); arg_stack.pop();
//		string result = head + to_string(currElement);
//		arg_stack.push(head + to_string(currElement));
//		FourElement newfourElement(op, arg1, arg2, result);
//		increaseList.push_back(newfourElement);
//		currElement++;
//	}
//	else {
//		string op = op_stack.top(); op_stack.pop();
//		string arg2 = arg_stack.top(); arg_stack.pop();
//		string arg1 = arg_stack.top(); arg_stack.pop();
//		string result = head + to_string(currElement);
//		arg_stack.push(head + to_string(currElement));
//		FourElement newfourElement(op, arg1, arg2, result);
//		fourElements.push_back(newfourElement);
//		currElement++;
//	}
//
//	printf("用(6)F->EmF归约\n");
//	currSymbol = "F";
//	pop(3);
//	hasBeenReduced = 2;
//}
//
//void r7() {
//	cout << "用(7)F->E归约\n";
//	currSymbol = "F";
//	pop(1);
//	hasBeenReduced = 2;
//}
//
//void r8() {
//	cout << "用(8)E->n归约\n";
//	currSymbol = "E";
//	pop(1);
//	hasBeenReduced = 2;
//}
//
//void r9() {
//	printf("用(9)E->i归约\n");
//	currSymbol = "E";
//	pop(1);
//	hasBeenReduced = 2;
//}
//
//void r10() {
//	cout << "用(10)D->A;归约\n";
//	currSymbol = "D";
//	pop(2);
//	hasBeenReduced = 2;
//}
//
//void r11() {
//	cout << "用(11)D->A;D归约\n";
//	currSymbol = "D";
//	pop(3);
//	hasBeenReduced = 2;
//}
//
//void success() {
//	cout << "语法分析成功！" << endl;
//}
//
//void translate() {
//	cout << "语法分析" << endl;
//	cout << "========================================" << endl;
//	cout << "文法:" << endl;
//	cout << "(1) S->for(A;B;A){C}" << endl;
//	cout << "(2) C->D" << endl;
//	cout << "(3) C->S" << endl;
//	cout << "(4) A->i=F" << endl;
//	cout << "(5) B->FrF" << endl;
//	cout << "(6) F->EmF" << endl;
//	cout << "(7) F->E" << endl;
//	cout << "(8) E->n" << endl;
//	cout << "(9) E->i" << endl;
//	cout << "(10) D->A;D" << endl;
//	cout << "(11) D->A;" << endl;
//	cout << "========================================" << endl;
//	cout << "符号说明:" << endl;
//	cout << "A == 赋值表达式" << endl;
//	cout << "B == 逻辑表达式" << endl;
//	cout << "i == 标识符" << endl;
//	cout << "n == 运算符符" << endl;
//	cout << "r == 比较符" << endl;
//	cout << "m == 运算符" << endl;
//	cout << "========================================" << endl;
//
//	fstream input;
//	input.open("refinedWords.txt");
//	cout << "开始语法分析\n";
//
//	// 状态0入栈
//	state_stack.push(0);
//	state = 0;
//
//	while (isReadOK)
//	{
//		needRead = true;
//		//如果是无符号数或者是标识符的话 存操作数栈
//		if (currSymbol.compare("3") == 0 || currSymbol.compare("4") == 0)
//		{
//			input >> currSymbol;
//			arg_stack.push(currSymbol);
//		}
//		//运算符或比较符的话 存符号栈
//		else if (currSymbol.compare("1") == 0 || currSymbol.compare("6") == 0 || currSymbol.compare("2") == 0)
//		{
//			input >> currSymbol;
//			op_stack.push(currSymbol);
//		}
//		//如果刚归约了的话 不应该再取新的
//		if (hasBeenReduced == 0)
//		{
//			while (needRead) {
//				if (tempS.compare("|") == 0) {
//					needRead = false;
//				}
//				else {
//					input >> tempS;
//				}
//			}
//			input >> tempS;
//			currSymbol = tempS;
//		}
//		else if (hasBeenReduced == 2)
//		{
//			hasBeenReduced = hasBeenReduced - 1;
//		}
//		//将归约前的符号给currSymbol 因为currSymbol还没用过
//		else if (hasBeenReduced == 1)
//		{
//			hasBeenReduced = hasBeenReduced - 1;
//			currSymbol = tempS;
//		}
//
//		// switch实现的分析表
//		int col = 0;
//		switch (currSymbol.at(0)) {
//		case '7': col = 0; break;
//		case '8': col = 1; break;
//		case '9': col = 2; break;
//		case 'Z': col = 3; break;
//		case '2': col = 4; break;
//		case '0': col = 5; break;
//		case '3': col = 6; break;
//		case '1': col = 7; break;
//		case '4': col = 8; break;
//		case '6': col = 9; break;
//		case 'X': col = 10; break;
//		case 'Y': col = 11; break;
//		case 'A': col = 12; break;
//		case 'B': col = 13; break;
//		case 'C': col = 14; break;
//		case 'D': col = 15; break;
//		case 'E': col = 16; break;
//		case 'F': col = 17; break;
//		case 'S': col = 18; break;
//		}
//
//		char* choice = lr1[state][col];
//		if (choice[0] == 'a') {
//			success();
//			break;
//		}
//		if (choice[0] == 'S') {
//			char* s = choice + 1;
//			shift(atoi(s));
//		}
//		else if (choice[0] == 'R') {
//			char* s = choice + 1;
//			switch (atoi(s)) {
//			case 1: r1(); break;
//			case 2: r2(); break;
//			case 3: r3(); break;
//			case 4: r4(); break;
//			case 5: r5(); break;
//			case 6: r6(); break;
//			case 7: r7(); break;
//			case 8: r8(); break;
//			case 9: r9(); break;
//			case 10: r10(); break;
//			case 11: r11(); break;
//			}
//		}
//		else if (choice[0] == '0') {
//			wrong(state, col);
//			break;
//		}
//		else {
//			shift(atoi(choice));
//		}
//
//	}
//
//	// 加入最后的exit
//	string op = "_";
//	string arg1 = "_";
//	string arg2 = "_";
//	string result = "Exit";
//	FourElement exit(op, arg1, arg2, result);
//	fourElements.push_back(exit);
//
//	// 地址转换
//	for (int i = 0; i < fourElements.size(); i++) {
//		if (fourElements[i].op.compare("JZ") == 0) {
//			for (int j = fourElements.size() - 1; j >= i; j--) {
//				if (fourElements[j].result.compare(fourElements[i].result) == 0) {
//					fourElements[i].result = "(" + to_string(j) + ")";
//					break;
//				}
//			}
//		}
//	}
//
//	fstream resultFile("result.txt");
//
//	// 输出结果四元式
//	cout << "========================================" << endl;
//	cout << "输出四元式：" << endl;
//	cout << "========================================" << endl;
//
//	for (int i = 0; i < fourElements.size(); i++)
//	{
//		cout << i << "\t" << "(" << fourElements[i].op << "\t" << fourElements[i].arg1
//			<< "\t" << fourElements[i].arg2 << "\t" << fourElements[i].result << ")" << endl;
//		resultFile << i << "\t" << "(" << fourElements[i].op << "\t" << fourElements[i].arg1
//			<< "\t" << fourElements[i].arg2 << "\t" << fourElements[i].result << ")" << endl;
//	}
//
//	input.close();
//	resultFile.close();
//}