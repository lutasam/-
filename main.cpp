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
//char vt[11] = { '#','(',')',';','=','f', 'i', 'n', 'r', '{', '}'};     //�ս��               
//char vn[5] = { 'A','B','C','E','S'};                //�ķ��ķ��ս��
//
//string Production[6] = { "S->f(A;B;A){A}","A->C=E","B->ErE","C->i","E->i", "E->n"};   //����ʽ
//int _count_ = 0;              //����ջ��Ԫ�صĸ�����������������
//int line = 1;              //����к�
//bool flag = false;
//int StatusNumber = 1;
//string stacktd = "#";     //�Ѿ��ƽ�����ջ������
//int Status[50] = { 0 };          //??  ���״̬ջ������
//stack <char> Stack;     //����ջ
//stack <int> status;    //״̬ջ
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
////���ʣ�മ
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
///*�ƽ�*/
//void Shift(int i, string s) {
//	Output(s);
//	cout << "ACTION[" << status.top() << "," << s.at(_count_) << "]=S" << i << ",״̬" << i << "��ջ" << endl;
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
///*��Լ*/
//void Reduction(int i, string s)
//{
//	Output(s);
//	cout << "r" << i << ":" << Production[i - 1] << "��Լ��GoTo(";
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
//	cout << status.top() << "��ջ" << endl;
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
//				cout << "acc" << "\t�����ɹ�" << endl;
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
//	cout << "************************LR(1)����*************************" << endl;
//	printf("    F -> ��ֵ���ʽ\n");
//	printf("    E -> �������ʽ\n");
//	printf("    B -> �Ƚϱ��ʽ\n");
//	printf("    T -> ����\n");
//	printf("    k -> ����˵��������ֻ�õ�3������int double float\n");
//	printf("    i -> ��ʶ��\n");
//	printf("    m -> ���������\n");
//	printf("    r -> �ȽϷ��Ű���> < >= <=\n");
//	printf("    n -> �޷�����\n");
//	cout << "�������ķ�����ʽΪ" << endl;
//	for (int j = 0; j < 6; j++)
//		cout << Production[j] << endl;
//	cout << "************************LR(1)����*************************" << endl;
//	char T;
//	do {
//		cout << "�����ַ���" << endl;
//		cin >> s;
//		cout << "************************�ֽ������·���*************************" << endl;
//		cout << "����" << "\t" << "״̬ջ" << "\t\t" << "����ջ" << "\t" << "ʣ�����봮" << "\t" << "����˵��" << endl;
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
//		cout << "�Ƿ��������,Y��y����" << endl;
//		cin >> T;
//	} while (T == 'y' || T == 'Y');
//	return 0;
//
//}
