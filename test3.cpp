//#include <iostream>
//#include <cstdio>
//#include <vector>
//#include <string>
//#include <string.h>
//#include <map>
//#include <set>
//#include <stack>
//#include <queue>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
///********************************************************
// *                                                      *
// *                ��һ���֣��ʷ�����                       *
// *                                                      *
// *******************************************************/
// // �ؼ��ֱ��ó�ʼֵ
//string Cppkeyword[100] = { "#", "��ʶ��(������)", "����", "ʵ��", "�ַ�����", "+", "-", "*", "/", "<",
//						  "<=", "==", "!=", ">=", ">", "&", "&&", "||", "=", "(",
//						  ")", "[", "]", "{", "}", ":", ";", ",", "@", "!",
//						  "void", "int", "float", "char", "if", "else", "while", "do", "for", "true",
//						  "false", "using", "namespace", "std", "main", "return", "null" };
//class word
//{
//public:
//	int syn{};
//	string token;
//};
////�洢�ʷ��������
//word lexicalTable[1000];
//int lexicalTableLen = 0;
////��λ��Ԫʽ����Դ�������һ��
//vector<int> whichLine;
//
//// ����ؼ��ʺͱ����ĺ���
//word letterAnalysis(const string& subCode)
//{
//	word item;
//	int isKeyword = 0;
//	for (int i = 30; i <= 46; i++)
//	{
//		if (subCode.substr(0, Cppkeyword[i].length()) == Cppkeyword[i])
//		{
//			item.syn = i;
//			isKeyword = 1;
//		}
//	}
//	/* ��������forѭ���Ļ��͵�����һһ�о٣�����ؼ�����Ŀ�϶࣬��Ҫд�ܶ�ͼ�����
//	if (subCode.substr(0, 4) == "void")
//	{
//		item.syn = 28;
//	}
//	else if (subCode.substr(0, 3) == "int")
//	{
//		item.syn = 29;
//	}
//	else if (subCode.substr(0, 5) == "float")
//*/
//	if (isKeyword == 0)
//	{
//		// ������������ؼ��ʣ�һ����Ϊ������
//		for (int i = 0; i <= subCode.length(); ++i)
//		{ //�ҵ���һ���������֡���ĸ���»��ߵ�λ��
//			if (!(subCode[i] >= 'a' && subCode[i] <= 'z' || subCode[i] >= 'A' && subCode[i] <= 'Z' || subCode[i] >= '0' && subCode[i] <= '9' || subCode[i] == '_'))
//			{
//				item.syn = 1; //1��λ�洢������
//				Cppkeyword[item.syn] = subCode.substr(0, i);
//				break;
//			}
//		}
//	}
//	item.token = Cppkeyword[item.syn];
//	return item;
//}
//
//// �������ֵĺ���
//word numberAnalysis(string subCode)
//{
//	word item;
//	for (int i = 0; i <= subCode.length(); ++i)
//	{
//		// ��ȡ����һ�������ֺ�С�����ַ�
//		if (!(subCode[i] >= '0' && subCode[i] <= '9' || subCode[i] == '.'))
//		{
//			string curNum = subCode.substr(0, i);
//			if (curNum.find('.') == string::npos) //û����'.'����ֵΪ�ܴ����������������ֵ�ǵ�һ�γ��ֵ��±�
//				item.syn = 2;                     //2��λ������
//			else
//				item.syn = 3; //3��λ��ʵ��
//
//			Cppkeyword[item.syn] = curNum;
//			break;
//		}
//	}
//	item.token = Cppkeyword[item.syn];
//	return item;
//}
//
//// �����ַ������ĺ���
//word strAnalysis(string subCode)
//{ //"hello"<<endl;
//	word item;
//	int nextindex = subCode.find_first_of('"', 1); //�ҵ��ڶ���"���ֵ�λ���±�
//	item.syn = 4;                                  //�ַ�������Ϊ4
//	Cppkeyword[item.syn] = subCode.substr(0, nextindex + 1);
//
//	item.token = Cppkeyword[item.syn];
//	return item;
//}
//
//// �����ַ��ĺ���
//word charAnalysis(string subCode)
//{
//	word item;
//	switch (subCode[0])
//	{
//	case '#':
//		item.syn = 0;
//		break;
//	case '+':
//		item.syn = 5;
//		break;
//	case '-':
//		item.syn = 6;
//		break;
//	case '*':
//		item.syn = 7;
//		break;
//	case '/':
//		item.syn = 8;
//		break;
//	case '<':
//		if (subCode[1] == '=')
//		{
//			item.syn = 10;
//		}
//		else
//		{
//			item.syn = 9;
//		}
//		break;
//	case '=':
//		if (subCode[1] == '=')
//		{
//			item.syn = 11;
//		}
//		else
//		{
//			item.syn = 18;
//		}
//		break;
//	case '!':
//		if (subCode[1] == '=')
//		{
//			item.syn = 12;
//		}
//		else
//			item.syn = 29;
//		break;
//
//	case '>':
//		if (subCode[1] == '=')
//		{
//			item.syn = 13;
//		}
//		else
//		{
//			item.syn = 14;
//		}
//		break;
//	case '&':
//		if (subCode[1] == '&')
//		{
//			item.syn = 16;
//		}
//		else
//		{
//			item.syn = 15;
//		}
//		break;
//	case '|':
//		if (subCode[1] == '|')
//		{
//			item.syn = 17;
//		}
//		break;
//
//	case '(':
//		item.syn = 19;
//		break;
//	case ')':
//		item.syn = 20;
//		break;
//	case '[':
//		item.syn = 21;
//		break;
//	case ']':
//		item.syn = 22;
//		break;
//	case '{':
//		item.syn = 23;
//		break;
//	case '}':
//		item.syn = 24;
//		break;
//	case ':':
//		item.syn = 25;
//		break;
//	case ';':
//		item.syn = 26;
//		break;
//	case ',':
//		item.syn = 27;
//		break;
//	case '@':
//		item.syn = 28;
//		break;
//	}
//	item.token = Cppkeyword[item.syn];
//	return item;
//}
//
//// �ʷ�����
//void scanner(const string& code)
//{ //if a=1;
//
//	for (int i = 0; i < code.length(); ++i)
//	{
//		word item;
//		if (code[i] >= 'a' && code[i] <= 'z' || code[i] >= 'A' && code[i] <= 'Z')
//		{ // ������,��������� if a=1;���е��ʷ����󷵻ء�if��,i��������λ������ڸú��������������
//			item = letterAnalysis(code.substr(i, code.length() - i + 1));
//		}
//		else if (code[i] >= '0' && code[i] <= '9')
//		{ // ��������
//			item = numberAnalysis(code.substr(i, code.length() - i + 1));
//		}
//		else if (code[i] == ' ')
//		{ // ����ǿո�ֱ������
//			continue;
//		}
//		else
//		{ // �����������
//			item = charAnalysis(code.substr(i, code.length() - i + 1));
//		}
//		i += int(item.token.length()) - 1;
//		lexicalTable[lexicalTableLen++] = item; //�ʷ�������Ľ������lexicalTable��
//		cout << "(" << item.syn << "," << item.token << ")" << endl;
//	}
//}
///****************************************************************
// *                                                              *
// *        �ڶ����֡��﷨����ǰ��һЩ׼������,��Ҫ����:                 *
// *      (1) ɨ���ķ�����ȡ�ķ��г��ֵ����е�Vn��Vt                    *
// *      (2) ���ķ��еĲ���ʽ���Ϊ�󲿡��Ҳ�,�����Ҳ�����vector���б���  *
// *      (3) ��������Vn��Vt��first����follow��                      *
// *                                                              *
// ****************************************************************/
//vector<string> grammar;          //�洢�ķ�
//map<string, int> VN2int, VT2int; //VN��VTӳ��Ϊ�±�����
//int symbolNum = 0;
//map<string, bool> nullable; //���ս������ս���Ƿ�ɿ�
//set<string> first[50];      //�洢��Vn��Vt��first����û��VtҲ����first��������������
//set<string> follow[50];     //�洢��Vn��Vt��follow����Vt��follow���ǿգ�240~263��ȡ��ע�Ϳɲ鿴Vt��first��follow��
//
//string getVn(string grammar)
//{ //��ȡ�ķ��еķ��ս��
//
//	if (grammar.substr(0, 2) == "<<")
//	{ //��������"<<exp>>"��ʽ�ķ��ս��
//		int bracketsDelimiter = grammar.find(">>");
//		string Vn = grammar.substr(0, bracketsDelimiter + 2);
//		return Vn;
//	}
//	if (grammar[1] == '\'')
//	{ //��'�ķ��ս��,�� E',T'
//		return grammar.substr(0, 2);
//	}
//	else
//	{ //����'���������ս������E��T
//		return grammar.substr(0, 1);
//	}
//}
//
//string getVt(string grammar)
//{ //��ȡ�ķ��е��ս��
//	for (int k = 0; k <= 29; k++)
//	{ //����Ӧ��ע�⣺ʹ���ƥ�䡣����������>=������ƥ��>���Ⲣ����Ҫ��
//		if (grammar.substr(0, 2) == Cppkeyword[k])
//			return grammar.substr(0, 2);
//	}
//	for (int k = 0; k <= 29; k++)
//	{ //ʹ���ƥ��
//		if (grammar.substr(0, 1) == Cppkeyword[k])
//			return grammar.substr(0, 1);
//	}
//	for (int k = 30; k <= 46; k++)
//	{ //ʹ���ƥ��
//		string Vt = grammar.substr(0, Cppkeyword[k].length());
//		if (Vt == Cppkeyword[k])
//		{
//			return Vt;
//		}
//	}
//	//������е����˵������ս�����ǹؼ��ʱ���ģ���ΪСд��ĸҲ�����ս��
//	if (grammar[0] >= 'a' && grammar[0] <= 'z')
//	{
//		return grammar.substr(0, 1);
//	}
//}
//
//void readVnAndVt()
//{
//	//ɨ��һ������ʽ��ʶ�����еķ��ս�����ս��
//	for (int i = 0; i < grammar.size(); i++)
//	{
//		for (int j = 0; j < grammar[i].length(); j++)
//		{
//			if (grammar[i][j] == ' ')
//			{
//				continue;
//			}
//			else if (grammar[i].substr(j, 2) == "<<")
//			{ //��������"<<exp>>"��ʽ�ķ��ս��
//				int bracketsDelimiter = grammar[i].substr(j, grammar[i].length() - j).find(">>");
//				string Vn = grammar[i].substr(j, bracketsDelimiter + 2);
//				if (VN2int[Vn] == 0)
//					VN2int[Vn] = ++symbolNum;
//				j = j + Vn.length() - 1;
//			}
//			else if (grammar[i][j] >= 'A' && grammar[i][j] <= 'Z')
//			{ //���ս��һ���д
//				string Vn = getVn(grammar[i].substr(j, 2));
//				if (VN2int[Vn] == 0)
//					VN2int[Vn] = ++symbolNum;
//				j = j + Vn.length() - 1;
//			}
//			else if (grammar[i].substr(j, 2) == "->")
//			{
//				j = j + 2 - 1;
//			}
//			else
//			{ //ɨ�����ʽ�Ҳ��Ŀ��ܵ��ս��(�ؼ��ʱ�)
//				string Vt = getVt(grammar[i].substr(j, grammar[i].length() - j));
//				if (VT2int[Vt] == 0)
//					//���ս����һ�γ���,�����ս��ӳ��Ϊ�±�����
//					VT2int[Vt] = ++symbolNum;
//				j = j + Vt.length() - 1;
//			}
//		}
//	}
//
//	cout << "���ս��VN:" << endl;
//	for (auto it = VN2int.begin(); it != VN2int.end(); it++)
//	{
//		cout << "�����±�:" << it->second << "\t���ƣ�" << it->first << endl;
//	}
//	cout << "�ս��VT:" << endl;
//	for (auto it = VT2int.begin(); it != VT2int.end(); it++)
//	{
//		cout << "�����±�:" << it->second << "\t���ƣ�" << it->first << endl;
//	}
//}
//
//vector<string> splitGrammarIntoYi(string rightGrama)
//{ //������ʽ���Ҳ�(��->�Ҳ����)��X->Y1Y2...Yk
//	vector<string> Y;
//
//	for (int j = 0; j < rightGrama.length(); j++)
//	{
//		if (rightGrama[j] == ' ')
//		{
//			continue;
//		}
//		if (rightGrama[j] >= 'A' && rightGrama[j] <= 'Z' || rightGrama.substr(j, 2) == "<<")
//		{ //���ս��
//			string Vn = getVn(rightGrama.substr(j, rightGrama.length() - j));
//			Y.push_back(Vn);
//			j = j + Vn.length() - 1;
//		}
//		else
//		{ //�ս��
//			string Vt = getVt(rightGrama.substr(j, rightGrama.length() - j));
//			Y.push_back(Vt);
//			j = j + Vt.length() - 1;
//		}
//	}
//	return Y;
//}
//
//void split(string grama, string& X, vector<string>& Y)
//{
//	int delimiterIndex = grama.find("->");
//	X = grama.substr(0, delimiterIndex);
//	//trim()���ܣ�C++������ֻ���Լ�ʵ�֣�������β�Ŀո����
//	X.erase(0, X.find_first_not_of(" "));
//	X.erase(X.find_last_not_of(" ") + 1);
//	string rightGrama = grama.substr(delimiterIndex + 2, grama.length() - delimiterIndex - 2);
//	Y = splitGrammarIntoYi(rightGrama);
//}
//
//bool allNullable(vector<string> Y, int left, int right)
//{ //�ж� Y[left]...Y[right]�Ƿ�ȫ�ɿ�
//	if (left >= Y.size() || left > right || right < 0)
//		return true;
//	for (int i = left; i <= right; i++)
//	{
//		if (nullable[Y[i]] == false)
//			return false;
//	}
//	return true;
//}
//
//void getFirstFollowSet()
//{
//	/*����FIRST��FOLLOW��nullable���㷨*/
//	for (auto it = VT2int.begin(); it != VT2int.end(); it++)
//	{ //��ÿһ���ս��Z��first[Z]={Z}
//		string Vt = it->first;
//		int Vt_index = it->second;
//		first[Vt_index].insert(Vt);
//	}
//	for (int grammarIndex = 0; grammarIndex < grammar.size(); grammarIndex++)
//	{
//		//����ÿ������ʽ��X->Y1Y2...Yk
//		string X;
//		vector<string> Y;
//		int delimiterIndex = grammar[grammarIndex].find("->");
//		X = grammar[grammarIndex].substr(0, delimiterIndex);
//		X.erase(0, X.find_first_not_of(" "));
//		X.erase(X.find_last_not_of(" ") + 1);                                                                                      //��"->"Ϊ�磬�ָ�����ʽ
//		string rightGrama = grammar[grammarIndex].substr(delimiterIndex + 2, grammar[grammarIndex].length() - delimiterIndex - 2); //��ȡ�󲿲���ʽ
//		Y = splitGrammarIntoYi(rightGrama);
//
//		int k = Y.size();
//		nullable["null"] = true;
//		//�������Yi���ǿɿյģ���nullable[X]=true
//		if (allNullable(Y, 0, k - 1))
//		{
//			nullable[X] = true;
//		}
//
//		for (int i = 0; i < k; i++)
//		{
//			//���Y0...Y(i-1)���ǿɿյ�(����֮��Yi����),��first[X] = first[X]��first[Yi] (1)
//			if (nullable[Y[i]] == false && allNullable(Y, 0, i - 1))
//			{
//				if (i <= k - 1)
//				{
//					set<string> setX = first[VN2int[X]];
//					//�ж�Yi���ս�����Ƿ��ս��
//					set<string> setY = VT2int.count(Y[i]) != 0 ? first[VT2int[Y[i]]] : first[VN2int[Y[i]]];
//					set_union(setX.begin(), setX.end(), setY.begin(), setY.end(), inserter(setX, setX.begin())); //(1)
//					first[VN2int[X]] = setX;
//				}
//			}
//			//���Y(i+1)...Yk���ǿɿյ�(����֮��Y0..Y(i-1)������)����follow[Yi] = follow[Yi]��follow[X] (2)
//			if (allNullable(Y, i + 1, k - 1))
//			{
//				set<string> setX = follow[VN2int[X]];
//				//�ж�Yi���ս�����Ƿ��ս��
//				set<string> setY = VT2int.count(Y[i]) ? follow[VT2int[Y[i]]] : follow[VN2int[Y[i]]];
//				set_union(setX.begin(), setX.end(), setY.begin(), setY.end(), inserter(setY, setY.begin()));
//				VT2int.count(Y[i]) ? follow[VT2int[Y[i]]] : follow[VN2int[Y[i]]] = setY;
//			}
//
//			for (int j = i + 1; j < k; j++)
//			{
//				//���Y(i+1)...Y(j-1)���ǿɿյ�(����֮��Yj����),��follow[Yi] = follow[Yi]��first[Yj] (3)
//				if (nullable[Y[j]] == false && allNullable(Y, i + 1, j - 1))
//				{
//					if (j <= k - 1)
//					{
//						set<string> setYi = VT2int.count(Y[i]) ? follow[VT2int[Y[i]]] : follow[VN2int[Y[i]]];
//						set<string> setYj = VT2int.count(Y[j]) ? first[VT2int[Y[j]]] : first[VN2int[Y[j]]];
//						set_union(setYi.begin(), setYi.end(), setYj.begin(), setYj.end(), inserter(setYi, setYi.begin()));
//						VT2int.count(Y[i]) ? follow[VT2int[Y[i]]] : follow[VN2int[Y[i]]] = setYi;
//					}
//				}
//			}
//		}
//	}
//}
//
//void converge()
//{ //��������first��follow����ֱ������
//	set<string> oldFirst[50];
//	set<string> oldFollow[50];
//	int isConverge = 1;
//	string _vn = getVn(grammar[0]);
//	//����һ�������ֶ��޸ĵĵط����ܶ�̲ĵ���ֹ����һ��������ͳһһ�£�����#��Ϊ��ֹ��
//	follow[VN2int[_vn]].insert("#");
//	int times = 1; //���������ֲ�����
//	do
//	{ //���ս����first��follow���ٱ仯������
//		isConverge = 1;
//		getFirstFollowSet();
//		//VN��״̬
//		for (auto it = VN2int.begin(); it != VN2int.end(); it++)
//		{
//			int vnindex = it->second;
//			if (oldFirst[vnindex].size() != first[vnindex].size() || oldFollow[vnindex].size() != follow[vnindex].size())
//				isConverge = 0;
//			//�����״̬���Ա�֮�����״̬�Ƚ��Ƿ�仯�ж��������
//			oldFirst[vnindex] = first[vnindex];
//			oldFollow[vnindex] = follow[vnindex];
//		}
//	} while (isConverge != 1);
//	//������ս��
//	cout << endl;
//	for (auto it = VN2int.begin(); it != VN2int.end(); it++)
//	{
//		int vnindex = it->second;
//		if (oldFirst[vnindex].size() != first[vnindex].size() || oldFollow[vnindex].size() != follow[vnindex].size())
//		{
//			isConverge = 0;
//		}
//		//���״̬
//		cout << it->first << "��first����\t";
//		for (auto first_it = first[vnindex].begin(); first_it != first[vnindex].end(); first_it++)
//		{
//			cout << *first_it << " ";
//		}
//		cout << endl;
//		cout << it->first << "��follow����\t";
//		for (auto follow_it = follow[vnindex].begin(); follow_it != follow[vnindex].end(); follow_it++)
//		{
//			cout << *follow_it << " ";
//		}
//		cout << endl;
//	}
//}
//
///****************************************************************
// *                                                              *
// *                  �������֣������ķ���LR1������                   *
// *          �ؼ�������(1) closure():�������LR1�հ�               *
// *                  (2) GOTO():���I����Vn��Vtת���J          *
// *                                                              *
// ****************************************************************/
//struct term
//{                 //LR1��ڲ�����
//	int termType; //�ƽ���Ŀ����Լ��Ŀ����Լ��Ŀ
//	string leftPart;
//	vector<string> rightPart;
//	int dotPos{ -1 };             //��ǰ׺���Ҳ���λ��,��ʼ��Ϊ-1
//	vector<string> subsequence; //LR1�ķ����õ��ĺ�̷�,����ʼ��һ���ַ���
//	bool operator==(const term& b) const
//	{
//		if (leftPart == b.leftPart && rightPart == b.rightPart && dotPos == b.dotPos)
//		{
//			if (subsequence == b.subsequence)
//				return true;
//		}
//		return false;
//	}
//};
//const int maxN = 4000;        //Ԥ�������maxN��״̬�������ټӣ�����ò�Ҫ����10000����Ȼ���ܻᷢ��δ֪����
//vector<term> statusSet[maxN]; //�
//int globalStatusNum = 1;      //����
//int actionTable[maxN][50];    //action���б�ʾ״̬���б�ʾ�ս��������Ԥ�����50���ս����Ӧ�ù�����
//int gotoTable[maxN][50];      //goto���б�ʾ״̬���б�ʾ���ս��
//
//void initGrammar()
//{
//
//	grammar.push_back("S'->S");
//	grammar.push_back("S->f(A;B;A){C}");
//	grammar.push_back("C->S");
//	grammar.push_back("C->D");
//	grammar.push_back("A->i=F");
//	grammar.push_back("B->FrF");
//	grammar.push_back("F->EmF");
//	grammar.push_back("F->E");
//	grammar.push_back("E->n");
//	grammar.push_back("E->i");
//	grammar.push_back("D->A;");
//	grammar.push_back("D->A;D");
//}
//
////�ú�������:�I����Vn��Vt���ܻ������µ��J����Ҳ�п���ָ����������ú��������ж��Ƿ�ָ�������
//int mergeSet()
//{
//	int flag = -1; //�ٶ������Խ��кϲ�
//	for (int i = 0; i < globalStatusNum - 1; i++)
//	{
//		if (statusSet[globalStatusNum - 1].size() != statusSet[i].size())
//			continue;
//		flag = i; //���Ժ�״̬��i�ϲ�
//		for (int j = 0; j < statusSet[globalStatusNum - 1].size(); j++)
//		{
//			if (!(statusSet[i][j] == statusSet[globalStatusNum - 1][j]))
//			{
//				flag = -1;
//			}
//		}
//		if (flag != -1) //��һ���������Ժϲ��ļ��Ͼͽ�������Ȼ�ȵ������������Ŀ����ȵ�״̬����ͬ�����
//			return flag;
//	}
//	return -1;
//}
//
//void initI0()
//{
//	term firstTerm;
//	string X;
//	vector<string> Y;
//	split(grammar[0], X, Y);
//	if (firstTerm.dotPos == -1) //���û�л�ǰ׺"��"
//		firstTerm.dotPos = 0;   //����ӻ�ǰ׺
//	firstTerm.leftPart = X;
//	firstTerm.rightPart = Y;
//	firstTerm.subsequence.push_back("#");
//	statusSet[0].push_back(firstTerm);
//}
//
////�����LR0��SLR��LR1��closure����������д�Ķ�����������д
//void closure(int statusNum)
//{ //����LR1�ķ�����հ�
//	queue<term> termQueue;
//	for (int i = 0; i < statusSet[statusNum].size(); i++)
//		termQueue.push(statusSet[statusNum][i]);
//	while (!termQueue.empty())
//	{ //���I��ÿ����[A->a��B beta,alpha]
//		term curTerm = termQueue.front();
//		if (curTerm.dotPos == curTerm.rightPart.size()) //����ǹ�Լ���������������
//		{
//			termQueue.pop();
//			continue;
//		}
//		string B = curTerm.rightPart[curTerm.dotPos];
//		for (int j = 0; j < grammar.size(); j++)
//		{ //�������ķ�G'�е�ÿ������ʽB->gamma
//			if (B != getVn(grammar[j].substr(0, grammar[j].length())))
//				continue;
//			//��[B->��gamma,b]���뼯��I�У�����b��FIRST[beta alpha]�е��ս��
//			term newTerm;
//			newTerm.dotPos = 0;
//			split(grammar[j], newTerm.leftPart, newTerm.rightPart);
//			//warning:����û����B->null�����������˵�Ѿ�������(null�����ս��)
//			if (VT2int.count(newTerm.rightPart[0]) != 0) //B->��bA���ƽ���Ŀ
//				newTerm.termType = 2;
//			else if (VN2int.count(newTerm.rightPart[0]) != 0) //B->b��A,��Լ��Ŀ
//				newTerm.termType = 3;
//			//��b
//			string beta;
//			vector<string> b;
//			if (curTerm.dotPos == curTerm.rightPart.size() - 1)
//			{ //���beta�����ڣ�b��alpha
//				b = curTerm.subsequence;
//			}
//			else if (VT2int.count(curTerm.rightPart[curTerm.dotPos + 1]) != 0)
//			{ //���beta���ڣ�bΪfirst(beta)��������betaΪ�ս��ʱ��b����beta
//				b.push_back(curTerm.rightPart[curTerm.dotPos + 1]);
//			}
//			else
//			{ //����first(beta)�е��ս��b
//				beta = curTerm.rightPart[curTerm.dotPos + 1];
//				for (auto it = first[VN2int[beta]].begin(); it != first[VN2int[beta]].end(); it++)
//				{
//					b.push_back(*it);
//				}
//			}
//			newTerm.subsequence = b;
//			//ֻ�бհ����ɵ�����B->gamma,���ڼ���I�вż��룻�ڼ���I�е�ֻҪ��Ӧ�����Ӻ�̷�
//			int newTermFlag = -1; //�ȼ��費�ڼ���I��
//			for (int k = 0; k < statusSet[statusNum].size(); k++)
//			{
//				if (newTerm.leftPart == statusSet[statusNum][k].leftPart && newTerm.rightPart == statusSet[statusNum][k].rightPart && newTerm.dotPos == statusSet[statusNum][k].dotPos)
//					newTermFlag = k;
//			}
//			if (newTermFlag == -1)
//			{ //���ڼ���I�оͼ���
//				termQueue.push(newTerm);
//				statusSet[statusNum].push_back(newTerm);
//			}
//			else
//			{ //�������B->gamma�ڼ���I�У����������̷�(������º�̷��Ļ�)
//				map<string, int> subsequenceMap;
//				for (int m = 0; m < statusSet[statusNum][newTermFlag].subsequence.size(); m++)
//				{
//					subsequenceMap[statusSet[statusNum][newTermFlag].subsequence[m]]++;
//				}
//				for (int m = 0; m < newTerm.subsequence.size(); m++)
//				{
//					if (subsequenceMap[newTerm.subsequence[m]] == 0)
//						statusSet[statusNum][newTermFlag].subsequence.push_back(newTerm.subsequence[m]);
//				}
//			}
//		}
//		termQueue.pop();
//	}
//}
//
////GOTO��������䶯��������LR0,SLR,LR1���������ǴӼ���I����һ�����ž����հ�����õ�����J��goto�����ڲ�������closure()��
//int GOTO(int statusNum, string symbol)
//{ //��״̬��statusNum����һ������symbol(vn��vt)������ת�ƺ������
//	int size = statusSet[statusNum].size();
//	for (int i = 0; i < size; i++)
//	{
//		vector<string> right = statusSet[statusNum][i].rightPart;
//		int dotPos = statusSet[statusNum][i].dotPos;
//		//symbol��vn����vt����
//		if (dotPos < right.size() && symbol == right[dotPos])
//		{
//			term tmpTerm = statusSet[statusNum][i];
//			tmpTerm.dotPos = tmpTerm.dotPos + 1; //��ǰ׺����һλ
//			dotPos = tmpTerm.dotPos;
//			//�������һλ֮���ֳ�Ϊ�˹�Լ��Ŀ,���������Ŀ��
//			if (tmpTerm.dotPos == tmpTerm.rightPart.size())
//			{
//				tmpTerm.termType = 4;
//				statusSet[globalStatusNum].push_back(tmpTerm);
//			}
//			else if (VT2int.count(tmpTerm.rightPart[dotPos]) != 0)
//			{ //��ǰ׺��������ҽ�����һ���ս��(�ƽ���Ŀ)����������Ŀ
//				tmpTerm.termType = 2;
//				statusSet[globalStatusNum].push_back(tmpTerm);
//			}
//			else if (VN2int.count(tmpTerm.rightPart[dotPos]) != 0)
//			{ //��ǰ׺��������ҽ�����һ�����ս��(��Լ��Ŀ)������һ��״̬���еĸ÷��ս������ʽ����
//				//�ȼ��� S->B��B
//				tmpTerm.termType = 3;
//				statusSet[globalStatusNum].push_back(tmpTerm);
//				//�ٽ��бհ�����
//				closure(globalStatusNum);
//			}
//		}
//	}
//	globalStatusNum++;
//	int flag = mergeSet();
//	if (flag != -1) //�ɺϲ�
//	{
//		statusSet[globalStatusNum - 1].clear(); //��գ��Է���һ
//		globalStatusNum--;
//		return flag;
//	}
//	else
//		return globalStatusNum - 1;
//}
//
//void printStatus()
//{
//	//���״̬��
//	for (int i = 0; i < globalStatusNum; i++)
//	{
//		if (statusSet[i].size() == 0)
//			continue;
//		cout << "��������������������������������������������������" << endl;
//		cout << "��      I" << i << "\t\t��" << endl;
//		cout << "��������������������������������������������������" << endl;
//		for (auto it = statusSet[i].begin(); it != statusSet[i].end(); it++)
//		{
//			cout << " \t";
//			cout << it->leftPart << "->";
//			for (int j = 0; j < it->rightPart.size(); j++)
//			{
//				if (j == it->dotPos)
//					cout << "��";
//				cout << it->rightPart[j];
//			}
//			if (it->rightPart.size() == it->dotPos)
//				cout << "��";
//			for (int j = 0; j < it->subsequence.size(); j++)
//			{
//				if (j == 0)
//					cout << "," << it->subsequence[j];
//				else
//					cout << "_" << it->subsequence[j];
//			}
//			cout << "     \t" << endl;
//		}
//
//		cout << "��������������������������������������������������" << endl;
//	}
//}
//
//void printTable()
//{
//	//�����������ͷ
//	// cout << " \t";
//	for (auto it = VT2int.begin(); it != VT2int.end(); it++)
//		cout << it->first << ",";
//	for (auto it = VN2int.begin(); it != VN2int.end(); it++)
//	{ //goto�����������ķ�����
//		if (it->first == getVn(grammar[0].substr(0, grammar[0].length())))
//			continue;
//		cout << it->first << ",";
//	}
//	cout << endl;
//	//���������
//	for (int i = 0; i < globalStatusNum; i++)
//	{
//		if (statusSet[i].size() == 0)
//			continue;
//		// cout << i << "\t";
//		for (auto it = VT2int.begin(); it != VT2int.end(); it++)
//		{ //action���ƽ�(��20000)����Լ(��30000)��������Ϊ10000
//			if (actionTable[i][it->second] >= 20000 && actionTable[i][it->second] < 30000)
//				cout << "" << "S" << actionTable[i][it->second] - 20000 << ",";
//			else if (actionTable[i][it->second] >= 30000 && actionTable[i][it->second] < 40000)
//				cout << "" << "R" << actionTable[i][it->second] - 30000 << ",";
//			else if (actionTable[i][it->second] == 10000)
//				cout << "" << "acc" << ",";
//			else
//				cout << "" << actionTable[i][it->second] << ",";
//		}
//		for (auto it = VN2int.begin(); it != VN2int.end(); it++)
//		{ //goto�����������ķ����󲿣�goto�����־�������
//			if (it->first == getVn(grammar[0].substr(0, grammar[0].length())))
//				continue;
//			cout << "" << gotoTable[i][it->second] << ",";
//		}
//		cout << endl;
//	}
//}
//
////���LR0��SLR��LR1������ֻ�Թ�Լ����иĶ�(�����ࣺ�ƽ���(����)��������(?)��GOTO��(����))
////ɾ��ʮ���У�����1�о�ok��
//void constructStatusSet(int choice = 0)
//{ //ͬ��������ͷ�����
//	initI0();
//	closure(0);
//	queue<string> symbolToRead;
//	map<string, int> symbolMap;
//	int curStatus = 0; //�����е�ǰ���״̬
//
//	for (int i = 0; i < statusSet[0].size(); i++)
//	{
//		string symbolStr = statusSet[0][i].rightPart[statusSet[0][i].dotPos];
//		if (symbolMap[symbolStr] == 0)
//		{
//			symbolToRead.push(symbolStr);
//			symbolMap[symbolStr]++;
//		}
//	}
//	symbolToRead.push("sep"); //����ָ���
//
//	while (!symbolToRead.empty())
//	{
//		if (symbolToRead.front() == "sep")
//		{ //һ������ƽ����goto��������֮�󣬿�ʼ�����Լ��
//			for (int ii = 0; ii < statusSet[curStatus].size(); ii++)
//			{
//				/****action���Լ���****/
//				if (statusSet[curStatus][ii].dotPos == statusSet[curStatus][ii].rightPart.size())
//				{ //�жϸù�Լ�������ĸ�����ʽ��Լ��
//					term tmpTerm = statusSet[curStatus][ii];
//					string reduceTerm = tmpTerm.leftPart + "->";
//					for (int ii = 0; ii < tmpTerm.rightPart.size(); ii++)
//						reduceTerm = reduceTerm + tmpTerm.rightPart[ii];
//					int genNum = -1;
//					for (int ii = 0; ii < grammar.size(); ii++)
//						if (reduceTerm == grammar[ii])
//							genNum = ii;
//					//����״̬
//					if (genNum == 0)
//						actionTable[curStatus][VT2int["#"]] = 10000;
//					else
//					{
//						//LR(1)�����У�ֻ�й�Լ��ĺ�̷��Ž��й�Լ
//						for (int _i = 0; _i < tmpTerm.subsequence.size(); _i++)
//						{
//							if (actionTable[curStatus][VT2int[tmpTerm.subsequence[_i]]] != 0)
//								cout << "(״̬" << curStatus << "���ڹ�Լ-��Լ��ͻ)" << endl;
//							actionTable[curStatus][VT2int[tmpTerm.subsequence[_i]]] = 30000 + genNum; //ͬ��Ϊ�����ų�ͻ����Լ��ȫ���30000
//						}
//					}
//				}
//				continue;
//			}
//			/****action���Լ��������*****/
//			curStatus++;
//			symbolToRead.pop();
//			continue;
//		}
//		int nextStatus = GOTO(curStatus, symbolToRead.front());
//		cout << "I" << curStatus << "--" << symbolToRead.front() << "-->"
//			<< "I" << nextStatus;
//		//action�����������
//		if (VT2int.count(symbolToRead.front()) != 0)
//		{
//			if (actionTable[curStatus][VT2int[symbolToRead.front()]] != 0)
//				cout << "(״̬" << curStatus << "�ƽ�" << symbolToRead.front() << "���ڳ�ͻ)";
//			actionTable[curStatus][VT2int[symbolToRead.front()]] = 20000 + nextStatus;
//		}
//		else //goto�����
//			gotoTable[curStatus][VN2int[symbolToRead.front()]] = nextStatus;
//		cout << endl;
//		//��״̬���Ļ�ǰ׺����ķ���(����vn��vt)�����,��������״̬�������е�״̬���ľͲ�����
//		if (nextStatus == globalStatusNum - 1)
//		{
//			symbolMap.clear();
//			for (int ii = 0; ii < statusSet[nextStatus].size(); ii++)
//			{
//				//��Լ�������
//				if (statusSet[nextStatus][ii].dotPos == statusSet[nextStatus][ii].rightPart.size())
//					continue;
//				string symbolStr = statusSet[nextStatus][ii].rightPart[statusSet[nextStatus][ii].dotPos];
//				if (symbolMap[symbolStr] == 0)
//				{
//					symbolToRead.push(symbolStr);
//					symbolMap[symbolStr]++;
//				}
//			}
//			symbolToRead.push("sep"); //����ָ���
//		}
//		symbolToRead.pop();
//	}
//	printStatus(); //���״̬�
//	printTable();  //���������
//}
//
//int main()
//{
//	initGrammar();        //��ʼ���ķ�
//	readVnAndVt();        //��ȡ�ķ������е�VN��VT
//	converge();           //����first��follow��
//	constructStatusSet(); //����LR(1)������
//
//	return 0;
//}
//
//
