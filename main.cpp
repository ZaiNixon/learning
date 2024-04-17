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
		cout << "Вопрос №" << index + 1 << "/" << questions.size() << endl;
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
		cout << "Введите свой ответ (от 1 до 4): ";
		cin >> userAnswer;
		while (userAnswer < 1 or userAnswer > 4)
		{
			cout << "Ошибка! Пожалуйста, введите свой ответ (1, 2, 3 или 4) ещё раз: ";
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
				cout << "\nПравильно!" << endl << endl;
				score++;
			}
			else
				cout << "\nНеправильно!" << endl << endl;
		}
		cout << "Викторина пройдена! " << name << ", Ваш счёт: " << score << "/" << questions.size() << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string name;
	cout << "Введите своё имя: ";
	cin >> name;

	Quiz quiz(name);

	Questions q1("Devil May Cry изначально должна была стать продолжением другой культовой серии. Какой ?", { "Bayonetta", "Resident Evil", "Это всегда была самостоятельная игра", "Metal Gear Solid" }, 2);
	Questions q2("Своё имя Данте получил в честь знаменитой личности. Кто же это?", { "Кобра - персонаж одноимённых манги и аниме", "Данте - персонаж поэмы, который «гулял» по кругам ада", "Дуранте дельи Алигьери - итальянский поэт средневековья", "Данте и есть Данте, никакой истории у имени нет" }, 3);
	Questions q3("Разработчики серии не только позаимствовали имя великого поэта, но и сделали множество отсылок к одному из его произведений. Какому?", { "«Вопрос о воде и земле»", "«Божественная комедия»", "«Новая жизнь»", "«Пир»" }, 2);
	Questions q4("В четвёртой части появляется новый персонаж Неро. Его имя тоже является отсылкой. К чему?", { "Это перевод с греческого \"новый\", потому что новый персонаж", "Неро -  Избранный главный герой из «Матрицы»", "Nero - программа для записи файлов на CD и DVD", "Нерон - римский император" }, 4);
	Questions q5("Даже у пистолетов Ebony и Ivory непростая история. В честь чего им дали имена?", { "Черного дерева и слоновой кости, ведь так переводятся названия", "Это устоявшееся название клавиш рояля", "В честь американского ежемесячного журнала и бренда средств для гигиены, конечно же", "Нет никакой истории, это выдумка" }, 2);
	Questions q6("Вторая часть Devil May Cry отличилась от всех игр, выходивших тогда на PlayStation 2. Чем?", { "Она не запускалась", "В комплекте с игрой шёл полный сезон одноимённого аниме", "Большими скидками", "Вышла сразу на двух дисках с прохождением за разных персонажей" }, 4);
	Questions q7("Мало кто из геймеров не слышал о Данте. Его популярность достигла такого уровня, что:", { "Ему посвятили картину, которая висит в Лувре", "Его образ воплотили в 20-метровую статую рядом с Токийской башней", "В его честь назвали один из островов Малайского архипелага", "Его включили в Книгу рекордов Гиннеса, как величайшего персонажа компьютерных игр"
		}, 4);
	Questions q8("В каком году вышла первая часть Devil May Cry на PlayStation 2?", { "1997", "1999", "2001", "2007" }, 2);
	Questions q9("Как зовут отца Данте и Вергилия?", { "Мундус", "Неро", "Аркхам", "Спарда" }, 4);
	Questions q10("На чём сбегают Данте и Триш с острова Маллет?", { "Самолёт", "Лодка", "Телепортируются", "Корабль" }, 1);

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
