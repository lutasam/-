//#include<iostream>
//#include<stack>
//#include<string>
//using namespace std;
//
//struct fourElement{
//	string op;
//	string arg1;
//	string arg2;
//	string result;
//} fourelement[100];
//int currFourelement = 0;
//
//string action[34][11] = {
//"0","0","0","0","0","S2","0","0","0","0","0",
//"acc","0","0","0","0","0","0","0","0","0","0",
//"0","S3","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","S6","0","0","0","0",
//"0","0","0","S7","0","0","0","0","0","0","0",
//"0","0","0","0","S8","0","0","0","0","0","0",
//"0","0","0","0","R4","0","0","0","0","0","0",
//"0","0","0","0","0","0","S11","S12","0","0","0",
//"0","0","0","0","0","0","S14","S15","0","0","0",
//"0","0","0","S16","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","0","0","S17","0","0",
//"0","0","0","0","0","0","0","0","R5","0","0",
//"0","0","0","0","0","0","0","0","R6","0","0",
//"0","0","0","R2","0","0","0","0","0","0","0",
//"0","0","0","R5","0","0","0","0","0","0","0",
//"0","0","0","R6","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","S6","0","0","0","0",
//"0","0","0","0","0","0","S14","S15","0","0","0",
//"0","0","S21","0","0","0","0","0","0","0","0",
//"0","0","0","0","S22","0","0","0","0","0","0",
//"0","0","0","R3","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","0","0","0","S23","0",
//"0","0","0","0","0","0","S25","S26","0","0","0",
//"0","0","0","0","0","0","S6","0","0","0","0",
//"0","0","R2","0","0","0","0","0","0","0","0",
//"0","0","R5","0","0","0","0","0","0","0","0",
//"0","0","R6","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","0","0","0","0","S29",
//"0","0","0","0","S30","0","0","0","0","0","0",
//"R1","0","0","0","0","0","0","0","0","0","0",
//"0","0","0","0","0","0","S32","S33","0","0","0",
//"0","0","0","0","0","0","0","0","0","0","R2",
//"0","0","0","0","0","0","0","0","0","0","R5",
//"0","0","0","0","0","0","0","0","0","0","R6"
//};
//
//int gotoarr[34][5] = { 
//0,0,0,0,1,
//0,0,0,0,0,
//0,0,0,0,0,
//4,0,5,0,0,
//0,0,0,0,0,
//0,0,0,0,0,
//0,0,0,0,0,
//0,9,0,10,0,
//0,0,0,13,0,
//0,0,0,0,0,
//0,0,0,0,0,
//0,0,0,0,0,
//0,0,0,0,0,
//0,0,0,0,0,
//0,0,0,0,0,
//0,0,0,0,0,
//18,0,19,0,0,
//0,0,0,20,0,
//0,0,0,0,0,
//0,0,0,0,0,
//0,0,0,0,0,
//0,0,0,0,0,
//0,0,0,24,0,
//27,0,28,0,0,
//0,0,0,0,0,
//0,0,0,0,0,
//0,0,0,0,0,
//0,0,0,0,0,
//0,0,0,0,0,
//0,0,0,0,0,
//0,0,0,31,0,
//0,0,0,0,0,
//0,0,0,0,0,
//0,0,0,0,0 };
//char vt[11] = { '#','(',')',';','=','f', 'i', 'n', 'r', '{', '}'};     //终结符               
//char vn[5] = { 'A','B','C','E','S'};                //文法的非终结符
//
//string Production[6] = { "S->f(A;B;A){A}","A->C=E","B->ErE","C->i","E->i", "E->n"};   //产生式
//int _count_ = 0;              //符号栈中元素的个数？？？？？？？
//int line = 1;              //输出行号
//bool flag = false;
//int StatusNumber = 1;
//string stacktd = "#";     //已经移进符号栈的内容
//int Status[50] = { 0 };          //??  输出状态栈内容用
//stack <char> Stack;     //符号栈
//stack <int> status;    //状态栈
//void Judge(int& i, int j, char arr[], char ch, string s)      //?????????
//{
//	flag = false;
//	for (int l = 0; l < j; l++)
//	{
//		if (ch == arr[l])
//		{
//			flag = true;
//			i = l;
//			break;
//		}
//	}
//	if (flag == false)
//	{
//		cout << "\tError" << endl;
//		_count_ = s.size();
//	}
//}
//
//void Outputstatus()
//{
//	for (int i = 0; i < StatusNumber; i++)
//	{
//		cout << Status[i];
//		if (i != StatusNumber - 1)
//			cout << ',';
//	}
//
//	cout << ';';
//	if (StatusNumber < 4)
//		cout << '\t';
//}
////输出剩余串
//void Outputstring(string s) {
//	for (int i = _count_; i < s.size(); i++)
//		cout << s.at(i);
//}
//void Output(string s) {
//	cout << line << "\t";
//	Outputstatus();
//	cout << "\t" << stacktd << "\t";
//	Outputstring(s);
//	cout << "\t\t";
//	line++;
//}
///*移进*/
//void Shift(int i, string s) {
//	Output(s);
//	cout << "ACTION[" << status.top() << "," << s.at(_count_) << "]=S" << i << ",状态" << i << "入栈" << endl;
//	status.push(i);
//	Status[StatusNumber] = i;
//	Stack.push(s.at(_count_));
//	stacktd = stacktd + s.at(_count_);
//	_count_++;
//	StatusNumber++;
//}
//
//void Goto(stack <int> st1, stack <char> st2, string s)
//{
//	int j = -1;
//	int ch1 = st1.top();
//	char ch2 = st2.top();
//	Judge(j, 5, vn, ch2, s);
//	if (gotoarr[ch1][j] == 0) {
//		cout << "\tError" << endl;
//		_count_ = s.size();
//	}
//	else {
//		status.push(gotoarr[ch1][j]);
//		Status[StatusNumber] = gotoarr[ch1][j];
//		StatusNumber++;
//	}
//}
///*规约*/
//void Reduction(int i, string s)
//{
//	Output(s);
//	cout << "r" << i << ":" << Production[i - 1] << "归约，GoTo(";
//	int N = Production[i - 1].length() - 3;
//	if (Production[i - 1].compare(""))
//	for (int j = 0; j < N; j++)
//	{
//		status.pop();
//		Stack.pop();
//		StatusNumber--;
//		stacktd.erase(stacktd.length() - 1);
//	}
//	cout << status.top() << "," << Production[i - 1].at(0) << ")=";
//	Stack.push(Production[i - 1].at(0));
//	stacktd = stacktd + Stack.top();
//	Goto(status, Stack, s);
//	cout << status.top() << "入栈" << endl;
//	Status[StatusNumber] = status.top();
//
//}
//
//void Analyse(string s)
//{
//	Stack.push('#');
//	status.push(0);
//	s = s + "#";
//	int t = -1;
//
//	while (_count_ < s.size())
//	{
//		int i = status.top();
//		char ch = s.at(_count_);
//		Judge(t, 11, vt, ch, s);
//		if (flag == true) {
//			if (action[i][t] != "acc" && action[i][t] != "0")
//			{
//				if (action[i][t].at(0) == 'S') {
//					action[i][t].erase(0, 1);
//					Shift(atoi(action[i][t].c_str()), s);
//					action[i][t].insert(0, "S");
//				}
//				else if (action[i][t].at(0) == 'R') {
//					action[i][t].erase(0, 1);
//					Reduction(atoi(action[i][t].c_str()), s);
//					action[i][t].insert(0, "R");
//				}
//			}
//			else if (action[i][t] == "0") {
//				cout << "\tError" << endl;
//				break;
//			}
//			else if (action[i][t] == "acc") {
//				Output(s);
//				cout << "acc" << "\t分析成功" << endl;
//				break;
//			}
//		}
//		else if (flag == false)
//			break;
//	}
//}
//
//int main(void)
//{
//	string s;
//	cout << "************************LR(1)分析*************************" << endl;
//	printf("    F -> 赋值表达式\n");
//	printf("    E -> 算术表达式\n");
//	printf("    B -> 比较表达式\n");
//	printf("    T -> 变量\n");
//	printf("    k -> 类型说明程序中只用到3个类型int double float\n");
//	printf("    i -> 标识符\n");
//	printf("    m -> 算术运算符\n");
//	printf("    r -> 比较符号包括> < >= <=\n");
//	printf("    n -> 无符号数\n");
//	cout << "本分析文法产生式为" << endl;
//	for (int j = 0; j < 6; j++)
//		cout << Production[j] << endl;
//	cout << "************************LR(1)分析*************************" << endl;
//	char T;
//	do {
//		cout << "输入字符串" << endl;
//		cin >> s;
//		cout << "************************现进行如下分析*************************" << endl;
//		cout << "步骤" << "\t" << "状态栈" << "\t\t" << "符号栈" << "\t" << "剩余输入串" << "\t" << "动作说明" << endl;
//		Analyse(s);
//		_count_ = 0;
//		line = 1;
//		stacktd = "#";
//		StatusNumber = 1;
//		while (!Stack.empty()) {
//			Stack.pop();
//		}
//		while (!status.empty()) {
//			status.pop();
//		}
//		cout << "是否继续分析,Y或y继续" << endl;
//		cin >> T;
//	} while (T == 'y' || T == 'Y');
//	return 0;
//
//}
