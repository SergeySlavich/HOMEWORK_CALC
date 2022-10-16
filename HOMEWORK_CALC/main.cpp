#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define HOMEWORK_CALC_IF_ELSE	// Калькулятор на основе "if...else" - 117 строк
//#define HOMEWORK_CALC_SWITCH	// Калькулятор на основе "switch" - 120 строк
#define HOMEWORK_CALC_FUNCTION	// Калькулятор на основе функций - 139 строк

void printResult(double var1, char operation, double var2, double result) //Вывод выражения с результатом
{
	cout << var1 << ' ' << operation << ' ' << var2 << " = " << result << endl;
	cout << "Для продолжения вычислений над результатом просто продолжите вводить выражение:\n";
}

double addition(double var1, double var2) // Сложение
{
	double result = var1 + var2;
	printResult(var1, '+', var2, result);
	return result;
}

double substraction(double var1, double var2) // Вычитание
{
	double result = var1 - var2;
	printResult(var1, '-', var2, result);
	return result;
}

double multiplication(double var1, double var2) // Умножение
{
	double result = var1 * var2;
	printResult(var1, '*', var2, result);
	return result;
}

double divided(double var1, double var2) // Деление с проверкой деления на 0
{
	if (var2 == 0)
	{
		cout << "На 0 делить нельзя.\n";
		return 'n' + 'n';
	}
	else
	{
		double result = var1 / var2;
		printResult(var1, '/', var2, result);
		return result;
	}
}

int rounder(double var) // Округление до ближайшего целого по правилам математики
{
	int varr = (int)var;
	if ((var - varr) < 0.5)
	{
		varr = (int)var;
	}
	else
	{
		varr = (int)var + 1;
	}
	return varr;
}

int remaind(double var1, double var2) // Деление по модулю (остаток от деления) с округлением по запросу дробных чисел по правилам математики (до ближайшего целого)
{
	int var1r = (int) var1, var2r = (int) var2, remaind;
	if (var1r < var1 || var2r < var2)
	{
		char input;
		bool esc = false;
		cout << "Эта операция допустима только для целых чисел. Округлить введенные числа до целых? y - да, n - нет, отменить вычисления.\nВаш ответ: ";
		while (!esc)
		{
			cin >> input;
			switch (input)
			{
			case 'n':
			case 'N': cout << "Операция отменена."; !esc; break;
			case 'y':
			case 'Y': var1r = rounder(var1); var2r = rounder(var2); break;
			default: cout << "Вы ввели неверный символ. Попробуйте ещё раз: ";
			}
			!esc; break;
		}
	}
	remaind = var1r % var2r;
	printResult(var1r, '%', var2r, remaind);
	return remaind;
}

double exponential(double var, double exp) // Возведение в степень с проверкой показателя степени, в том числе с отрицательным показателем степени
{
	if ((int)exp < exp)
	{
		cout << "В этой версии калькулятора показатель степени может быть только целым числом.";
		!exit;
	}
	else
	{
		double result = 1;
		if (exp > 0)
		{
			for (int i = 0; i < exp; i++)
			{
				result *= var;
			}
		}
		if (exp < 0)
		{
			for (int i = 0; i > exp; i--)
			{
				result *= var;
			}
			result = 1 / result;
		}
		printResult(var, '^', exp, result);
		return result;
	}
}

double factorial(double var) //Факториал
{
	long double factorial = 1;
	int varr = (int)var;
	if (varr < var)
	{
		char input;
		bool esc = false;
		cout << "Эта операция допустима только для целых чисел. Округлить введенные числа до целых? y - да, n - нет, отменить вычисления.\nВаш ответ: ";
		while (!esc)
		{
			cin >> input;
			switch (input)
			{
			case 'n':
			case 'N': cout << "Операция отменена."; !esc; break;
			case 'y':
			case 'Y': varr = rounder(var); break;
			default: cout << "Вы ввели неверный символ. Попробуйте ещё раз: ";
			}
			!esc; break;
		}
	}
	if (varr > 20)
	{
		cout << "Факториал корректно может быть посчитан только для целых чисел до 20 включительно.";
		!exit;
	}
	else if (varr < 0)
	{
		cout << "Факториал отрицательных чисел не существует.";
		!exit;
	}
	else
	{
		for (int i = 1; i <= varr; i++)
		{
			factorial *= i;
		}
		cout << var << "! = " << factorial << endl;
		cout << "Для продолжения вычислений над результатом просто продолжите вводить выражение:\n";
		return factorial;
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");

#if defined HOMEWORK_CALC_IF_ELSE
	double var1, var2, result = 1;
	char operation;
	bool exit = false;
	cout << "Программа для вычислений.\nДопустимые операции:\n\t+ сложение\n\t- вычитание\n\t* умножение\n\t/ деление\n\t% вычисление остатка от деления (только для целых чисел)\n";
	cout << "\t^ возведение в степень (только для целых показетелей степени)\n\t! вычисление факториала (до 20, включительно только для натуральных чисел)\n";
	cout << "Для выхода из программы нажмите \"n\" после вывода результата.\nВведите первое выражение для вычисления:\n";
	cin >> var1;

	while (exit == false)
	{
		cin >> operation;
		if (operation == 'n' || operation == 'N')	// Exit Выход
		{
			exit = true;
			cout << "Работа с программой закончена.\n";
		}
		// Unary operators Унарные операторы
		else if (operation == '!')					// Factorial Факториал
		{
			if (var1 > 20)
			{
				cout << "ПРЕДУПРЕЖДЕНИЕ! Факториал корректно может быть посчитан только для целого числа до 20, включительно.\n";
				exit = true;
			}
			else if (var1 < 0)
			{
				cout << "ПРЕДУПРЕЖДЕНИЕ! Факториал отрицательных чисел не существует.\n";
				exit = true;
			}
			else
			{
				long long factorial = 1;
				for (int i = 1; i <= (int)var1; i++)
				{
					factorial *= i;
				}
				cout << var1 << "! = " << factorial << endl;
			}
		}
		// Binary operators
		else
		{
			cout << var1; cin >> var2;
			if (operation == '+')					// Addition Сложение
			{
				result = var1 + var2;
			}
			else if (operation == '-')				// Subtraction Вычитание
			{
				result = var1 - var2;
			}
			else if (operation == '*')				// Multiplication Умножение
			{
				result = var1 * var2;
			}
			else if (operation == '/')				// Dividing Деление
			{
				if (var2 == 0)
				{
					cout << "ПРЕДУПРЕЖДЕНИЕ! На ноль делить нельзя!";
					exit = true;
				}
				else
				{
					result = var1 / var2;
				}
			}
			else if (operation == '%')				// Remainder of dividing Остаток от деления
			{
				if ((int)var1 < var1 || (int)var2 < var2)
				{
					cout << "ПРЕДУПРЕЖДЕНИЕ! Эта операция возможна только для целых чисел.";
					exit = true;
				}
				else
				{
					result = (int)var1 % (int)var2;
				}
			}
			else if (operation == '^')				// Exponetiation Возведение в степень
			{
				result = 1;
				if ((int)var2 < var2)
				{
					cout << "ПРЕДУПРЕЖДЕНИЕ! Показатель степени должен быть целым числом."ж
					exit = true;
				}
				else if (var2 < 0)
				{
					var2 = -var2;
					for (int i = 1; i <= var2; i++)
					{
						result *= var1;
					}
					result = 1 / result;
				}
				else
				{
					for (int i = 1; i <= var2; i++)
					{
						result *= var1;
					}
				}
			}
			if (exit == true)						// Print result Вывод результата
			{
				cout << "\n Выполнение программы прервано из-за некорректного ввода данных пользователем.";
			}
			else
			{
				cout << " " << operation << " " << var2 << " = " << result << endl;
				var1 = result;
			}
		}
	}
#endif
		
#if defined HOMEWORK_CALC_SWITCH
	double var1, var2, result = 1;
	char operation;
	bool exit = false;
	cout << "Программа для вычислений.\nДопустимые операции:\n\t+ сложение\n\t- вычитание\n\t* умножение\n\t/ деление\n\t% вычисление остатка от деления (только для целых чисел)\n";
	cout << "\t^ возведение в степень (только для целых показателей степени)\n\t! вычисление факториала (до 20, включительно только для натуральных чисел)\n";
	cout << "Для выхода из программы нажмите \"n\" после вывода результата.\nВведите первое выражение для вычисления:\n";
	cin >> var1;

	while (exit == false)
	{
		cin >> operation;
		switch (operation)
		{
		// Unary operators Унарные операторы
		case 'n':									// Exit Выход
		case 'N': exit = true; cout << "Работа с программой завершена."; break;
		case '!':									// Factorial Факториал
		{
			if (var1 > 20)
			{
				cout << "ПРЕДУПРЕЖДЕНИЕ! Факториал корректно может быть посчитан только для целого числа до 20, включительно.\n";
				exit = true;
			}
			else if (var1 < 0)
			{
				cout << "ПРЕДУПРЕЖДЕНИЕ! Факториал отрицательного числа не существует.\n";
				exit = true;
			}
			else
			{
				long long factorial = 1;
				for (int i = 1; i <= (int)var1; i++)
				{
					factorial *= i;
				}
				cout << var1 << "! = " << factorial << endl;
				var1 = factorial;
			}
			break;
		}
		default:
		{
			// Binary operators Бинарные операторы
			cout << var1; cin >> var2;
			switch (operation)
			{
			case '+': result = var1 + var2; break;	// Addition Сложение
			case '-': result = var1 - var2; break;	// Substraction Вычитание
			case '*': result = var1 * var2; break;	// Multiplication Умножение
			case '/':								// Divided Деление
			{
				if (var2 != 0)
				{
					result = var1 / var2;
				}
				else
				{
					cout << "ПРЕДУПРЕЖДЕНИЕ! На ноль делить нельзя!";
					exit = true;
				}
				break;
			}
			case '%':								// Remainder of dividing Остаток от деления
			{
				if (!((int)var1 < var1 || (int)var2 < var2))
				{
					cout << "ПРЕДУПРЕЖДЕНИЕ! Эта операция возможна только для целых чисел.";
					exit = true;
				}
				else
				{
					result = (int)var1 / (int)var2;
				}
				break;
			}
			case '^':								// Exponential Возведение в степень
			{
				result = 1;
				if ((int)var2 < var1)
				{
					cout << "ПРЕДУПРЕЖДЕНИЕ! Показатель степени должен быть целым числом.";
					exit = true;
				}
				else if (var2 < 0)
				{
					var2 = -var2;
					for (int i = 1; i <= var2; i++)
					{
						result *= var1;
					}
					result = 1 / result;
				}
				else
				{
					for (int i = 1; i <= var2; i++)
					{
						result *= var1;
					}
				}
				break;
			}
			default:
			{
				cout << "ПРЕДУПРЕЖДЕНИЕ! Введена некорректная операция.\n";
			}
			}
		if (exit == true)							// Print result Вывод результата
		{
			cout << "\n Выполнение программы прервано из-за некорректного ввода данных пользователем.";
		}
		else
		{
			cout << " " << operation << " " << var2 << " = " << result << endl;
			var1 = result;
		}
		}
		}
	}
#endif

#if defined HOMEWORK_CALC_FUNCTION
	double var1, var2 = 0, result;
	char operation = 0;
	bool exit = false;
	cout << "Программа для вычислений.\nДопустимые операции:\n\t+ сложение\n\t- вычитание\n\t* умножение\n\t/ деление\n\t% вычисление остатка от деления (только для целых чисел)\n";
	cout << "\t^ возведение в степень (только для целых показателей степени)\n\t! вычисление факториала (до 20, включительно только для натуральных чисел)\n";
	cout << "Для выхода из программы нажмите \"n\" после вывода результата.\nВведите первое выражение для вычисления:\n";
	cin >> var1;

	while (!exit)
	{
		cin >> operation;
		if (operation != '!' && operation != 'n' && operation != 'N') cin >> var2;
		switch (operation)
		{
			// Unary operators Унарные операторы
		case 'n':												// Exit Выход
		case 'N': exit = true; cout << "Работа с программой завершена.\n"; break;
		//case 's': sinus(var1); break;							// Sinus Синус
		//case 'c': cosinus(var1); break:						// Cosinus Косинус
		case '!': result = factorial(var1); break;						// Factorial Факториал
			// Binary operators Бинарные операторы
		case '+': result = addition(var1, var2); break;		// Addition Сложение
		case '-': result = substraction(var1, var2); break;	// Substraction Вычитание
		case '*': result = multiplication(var1, var2); break;	// Multiplication Умножение
		case '/': result = divided(var1, var2); break;		// Divided Деление
		case '%': result = remaind(var1, var2); break;		// Remainder of the didided Остаток от деления
		case '^': result = exponential(var1, var2); break;				// Exponential Возведение в степень
		default: cin >> var1; break;
		}
		var1 = result;
	}
#endif	
}

