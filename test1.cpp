//#define _CRT_SECURE_NO_WARNINGS
//#define reserveWordLen 33
//
//#include <iostream>
//#include <fstream>
//#include <cstring>
//#include <cstdio>
//using namespace std;
//
//// ������
//bool isReverseWord(char str[])
//{
//	const char* reserveWord[] = {
//		"int", "long", "short", "float", "unsigned", "signed", "double", "char", "const", "main",
//		"void", "volatile", "enum", "struct", "union", "if", "else", "goto", "switch",
//		"case", "do", "while", "for", "continue", "break", "return", "default", "typedef", "auto",
//		"register", "extern", "static", "sizeof", "restrict"
//	};
//
//	for (int i = 0; i < reserveWordLen; i++)
//	{
//		if (strcmp(reserveWord[i], str) == 0)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//// ����
//bool isNumber(char c)
//{
//	if (c >= '0' && c <= '9')
//	{
//		return true;
//	}
//	return false;
//}
//
//// ��ĸ
//bool isLetter(char c)
//{
//	if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
//	{
//		return true;
//	}
//	return false;
//}
//
//// �����
//bool isOperator(char c)
//{
//	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '%' || c == '^' || c == '&' || c == '|' || c == '!')
//	{
//		return true;
//	}
//	return false;
//}
//
//// ���
//bool isBounder(char c)
//{
//	if (c == ',' || c == ';' || c == '(' || c == ')' || c == '{' || c == '}' || c == '<' || c == '>' || c == '#' || c == '\'' || c == '\"')
//	{
//		return true;
//	}
//	return false;
//}
//
//int main()
//{
//	FILE* inputFile = fopen("input.txt", "r");
//	fstream outputFile;
//	outputFile.open("output.txt", ofstream::out | ofstream::ate);
//	char c;
//
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
//					cout << "����" << endl;
//					outputFile << "����" << endl;
//					return 0;
//				}
//				str[i] = '\0';
//				if (isReverseWord(str))
//				{
//					cout << "������:\t" << "<1, " << str << '>' << endl;
//					outputFile << "������:\t" << "<1, " << str << '>' << endl;
//				}
//				else
//				{
//					cout << "��ʶ��:\t" << "<2, " << str << '>' << endl;
//					outputFile << "��ʶ��:\t" << "<2, " << str << '>' << endl;
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
//					cout << "����" << endl;
//					outputFile << "����" << endl;
//					return 0;
//				}
//				else {
//					str[i] = '\0';
//					cout << "������:\t" << "<3, " << str << '>' << endl;
//					outputFile << "������:\t" << "<3, " << str << '>' << endl;
//				}
//			}
//			if (isOperator(c))
//			{
//				if (c == '=' || c == '>' || c == '<') {
//					char ano_c = fgetc(inputFile);
//					if (ano_c == '=') {
//						cout << "�����:\t" << "<4, " << c << ano_c << '>' << endl;
//						outputFile << "�����:\t" << "<4, " << c << ano_c << '>' << endl;
//					}
//					else {
//						cout << "�����:\t" << "<4, " << c << '>' << endl;
//						outputFile << "�����:\t" << "<4, " << c << '>' << endl;
//					}
//				}
//				else if (c == '&' || c == '|') {
//					char ano_c = fgetc(inputFile);
//					if (c == ano_c) {
//						cout << "�����:\t" << "<4, " << c << ano_c << '>' << endl;
//						outputFile << "�����:\t" << "<4, " << c << ano_c << '>' << endl;
//					}
//					else {
//						cout << "�����:\t" << "<4, " << c << '>' << endl;
//						outputFile << "�����:\t" << "<4, " << c << '>' << endl;
//					}
//				}
//				else {
//					cout << "�����:\t" << "<4, " << c << '>' << endl;
//					outputFile << "�����:\t" << "<4, " << c << '>' << endl;
//				}
//			}
//			if (isBounder(c))
//			{
//				cout << "���޷�:\t" << "<5, " << c << '>' << endl;
//				outputFile << "���޷�:\t" << "<5, " << c << '>' << endl;
//			}
//		}
//	}
//
//	fclose(inputFile);
//	outputFile.close();
//	return 0;
//}