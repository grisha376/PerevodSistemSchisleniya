// +++++++++++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale>

using namespace std;

void DexToDec()
{
	cout << "Введите шестнадцатиричное число (можно с точкой): ";
	string number;
	cin >> number;
	bool point = false;
	for (int i = 0; i < number.length(); i++)
		if (number[i] < '0' || number[i] > '9')
			if (number[i] < 'A' || number[i] > ('F'))
			{
				if (number[i] == '.' && !point &&
					i != 0 && i != number.length() - 1)
				{
					point = true;
					continue;
				}
				cout << "Направильное число!" << endl;
				DexToDec();
			}
	string left, right;
	for (int i = 0; i < number.length(); i++)
	{
		if (number[i] == '.')
		{
			for (++i; i < number.length(); i++)
				right += number[i];
			break;
		}
		left = number[i] + left;
	}
	double sum = 0;
	for (int i = 0; i < left.length(); i++)
		if (left[i] >= '0' && left[i] <= '9') sum += (left[i] - '0') * pow(16, i);
		else sum += (left[i] - 'A' + 10) * pow(16, i);
	if (point)
		for (int i = 0; i < right.length(); i++)
			if (right[i] >= '0' && right[i] <= '9') sum += (right[i] - '0') * pow(16, -(i + 1));
			else sum += (right[i] - 'A' + 10) * pow(16, -(i + 1));
	cout << "Десятичное число: " << sum << endl;
}

void DecToDex()
{
	cout << "Введите десятичное чило: ";
	string number;
	cin >> number;
	int decimal = 0;
	for (int i = 0; i < number.length(); i++)
		if (number[i] < '0' || number[i] > '9')
		{
			cout << "Направильное число!" << endl;
			DecToDex();
		}
		else
		{
			decimal *= 10;
			decimal += number[i] - '0';
		}
	number = "";
	for (int i = 0; (i < 10) && (decimal != 0); i++)
	{
		char symbol;
		if (decimal % 16 < 10) symbol = decimal % 16 + '0';
		else symbol = decimal % 16 - 10 + 'A';
		number = symbol + number;
		decimal /= 16;
	}
	cout << "Шестнадцатиричное число: " << number << endl;
}

int main()
{
	setlocale(0, "ru");
	cout.precision(100);
	DexToDec();
	cout << endl;
	DecToDex();
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
