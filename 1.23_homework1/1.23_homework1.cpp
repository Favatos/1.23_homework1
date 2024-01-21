#include <list>
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

int menu() {
	int choice;

	cout << "1. добавить дело\n"
		"2. дело выполнено\n"
		"3. отобразить список дел\n"
		"4. отобразить отчёт(список выполненных дел)\n"
		"0. выход\n";
	cin >> choice;

	return choice;
}

void print(list<string> t) {
	list<string>::iterator it;
	for (it = t.begin(); it != t.end(); it++) {
		cout << *it << ", ";
	}
	cout << endl;
}

void done(string key, list<string>* a, list<string>* b) {
	list<string>::iterator it = find(a->begin(), a->end(), key);
	b->push_back(*it);
	a->erase(it);
	cout << "Готово\n";
}

void input(string* task) {
	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	getline(cin, *task);
}

int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	list<string> tasks;
	list<string> archive;
	int check = 5;
	string task;

	while (check != 0) {
		check = menu();
		switch (check) {
		case 1:
			cout << "Введите название дела: ";
			input(&task);
			cout << 'u'<<'\n';
			tasks.push_back(task);
			break;
		case 2:
			print(tasks);
			cout << endl << "Выберите дело: "; 
			input(&task);
			done(task, &tasks, &archive);
			break;
		case 3:
			print(tasks);
			break;
		case 4:
			print(archive);
			break;
		default:
			if (check != 0) cout << "Ошибка\n";
			else cout << "До свидания!\n";
			break;
		}
	}

	return 0;
}