#include<iostream>
#include<string>
#include<Windows.h>
#include<vector>
using namespace std;


class Questions
{
	string text;
	vector<string> answers;
	int correct_id;
public:
	Questions(string text, vector<string> answers, int correct_id) : text(text), answers(answers), correct_id(correct_id) {}
	friend class Quiz;
};

class Quiz
{
	vector<Questions> questions;
	string name;
	int score;
public:
	Quiz(string name) : name(name), score(0) {}
	Quiz(vector<Questions> questions, string name) : questions(questions), name(name), score(0) {}

	void addQuestion(Questions& question)
	{
		questions.push_back(question);
	}

	void displayQuestion(int index)
	{
		Sleep(2500);
		cout << "������ �" << index + 1 << "/" << questions.size() << endl;
		cout << questions[index].text << endl;
		for (int i = 0; i < questions[index].answers.size(); i++)
		{
			Sleep(500);
			cout << i + 1 << ") " << questions[index].answers[i] << endl;
		}
	}

	int getAnswer()
	{
		int userAnswer;
		cout << "������� ���� ����� (�� 1 �� 4): ";
		cin >> userAnswer;
		while (userAnswer < 1 or userAnswer > 4)
		{
			cout << "������! ����������, ������� ���� ����� (1, 2, 3 ��� 4) ��� ���: ";
			cin >> userAnswer;
		}
		return userAnswer;
	}

	bool checkAnswer(int index, int userAnswer)
	{
		return userAnswer == questions[index].correct_id;
	}

	void runQuiz()
	{
		for (int i = 0; i < questions.size(); i++)
		{
			displayQuestion(i);
			int userAnswer = getAnswer();
			if (checkAnswer(i, userAnswer))
			{
				cout << "\n���������!" << endl << endl;
				score++;
			}
			else
				cout << "\n�����������!" << endl << endl;
		}
		cout << "��������� ��������! " << name << ", ��� ����: " << score << "/" << questions.size() << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string name;
	cout << "������� ��� ���: ";
	cin >> name;

	Quiz quiz(name);

	Questions q1("Devil May Cry ���������� ������ ���� ����� ������������ ������ ��������� �����. ����� ?", { "Bayonetta", "Resident Evil", "��� ������ ���� ��������������� ����", "Metal Gear Solid" }, 2);
	Questions q2("��� ��� ����� ������� � ����� ���������� ��������. ��� �� ���?", { "����� - �������� ���������� ����� � �����", "����� - �������� �����, ������� ������ �� ������ ���", "������� ����� �������� - ����������� ���� �������������", "����� � ���� �����, ������� ������� � ����� ���" }, 3);
	Questions q3("������������ ����� �� ������ �������������� ��� �������� �����, �� � ������� ��������� ������� � ������ �� ��� ������������. ������?", { "������� � ���� � �����", "������������� ��������", "������ ������", "����" }, 2);
	Questions q4("� �������� ����� ���������� ����� �������� ����. ��� ��� ���� �������� ��������. � ����?", { "��� ������� � ���������� \"�����\", ������ ��� ����� ��������", "���� -  ��������� ������� ����� �� ���������", "Nero - ��������� ��� ������ ������ �� CD � DVD", "����� - ������� ���������" }, 4);
	Questions q5("���� � ���������� Ebony � Ivory ��������� �������. � ����� ���� �� ���� �����?", { "������� ������ � �������� �����, ���� ��� ����������� ��������", "��� ����������� �������� ������ �����", "� ����� ������������� ������������ ������� � ������ ������� ��� �������, ������� ��", "��� ������� �������, ��� �������" }, 2);
	Questions q6("������ ����� Devil May Cry ���������� �� ���� ���, ���������� ����� �� PlayStation 2. ���?", { "��� �� �����������", "� ��������� � ����� ��� ������ ����� ����������� �����", "�������� ��������", "����� ����� �� ���� ������ � ������������ �� ������ ����������" }, 4);
	Questions q7("���� ��� �� �������� �� ������ � �����. ��� ������������ �������� ������ ������, ���:", { "��� ��������� �������, ������� ����� � �����", "��� ����� ��������� � 20-�������� ������ ����� � ��������� ������", "� ��� ����� ������� ���� �� �������� ���������� ����������", "��� �������� � ����� �������� �������, ��� ����������� ��������� ������������ ���"
		}, 4);
	Questions q8("� ����� ���� ����� ������ ����� Devil May Cry �� PlayStation 2?", { "1997", "1999", "2001", "2007" }, 2);
	Questions q9("��� ����� ���� ����� � ��������?", { "������", "����", "������", "������" }, 4);
	Questions q10("�� ��� ������� ����� � ���� � ������� ������?", { "������", "�����", "���������������", "�������" }, 1);

	quiz.addQuestion(q1);
	quiz.addQuestion(q2);
	quiz.addQuestion(q3);
	quiz.addQuestion(q4);
	quiz.addQuestion(q5);
	quiz.addQuestion(q6);
	quiz.addQuestion(q7);
	quiz.addQuestion(q8);
	quiz.addQuestion(q9);
	quiz.addQuestion(q10);

	quiz.runQuiz();
}
