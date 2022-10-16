#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define HOMEWORK_CALC_IF_ELSE	// ����������� �� ������ "if...else" - 117 �����
//#define HOMEWORK_CALC_SWITCH	// ����������� �� ������ "switch" - 120 �����
#define HOMEWORK_CALC_FUNCTION	// ����������� �� ������ ������� - 139 �����

void printResult(double var1, char operation, double var2, double result) //����� ��������� � �����������
{
	cout << var1 << ' ' << operation << ' ' << var2 << " = " << result << endl;
	cout << "��� ����������� ���������� ��� ����������� ������ ���������� ������� ���������:\n";
}

double addition(double var1, double var2) // ��������
{
	double result = var1 + var2;
	printResult(var1, '+', var2, result);
	return result;
}

double substraction(double var1, double var2) // ���������
{
	double result = var1 - var2;
	printResult(var1, '-', var2, result);
	return result;
}

double multiplication(double var1, double var2) // ���������
{
	double result = var1 * var2;
	printResult(var1, '*', var2, result);
	return result;
}

double divided(double var1, double var2) // ������� � ��������� ������� �� 0
{
	if (var2 == 0)
	{
		cout << "�� 0 ������ ������.\n";
		return 'n' + 'n';
	}
	else
	{
		double result = var1 / var2;
		printResult(var1, '/', var2, result);
		return result;
	}
}

int rounder(double var) // ���������� �� ���������� ������ �� �������� ����������
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

int remaind(double var1, double var2) // ������� �� ������ (������� �� �������) � ����������� �� ������� ������� ����� �� �������� ���������� (�� ���������� ������)
{
	int var1r = (int) var1, var2r = (int) var2, remaind;
	if (var1r < var1 || var2r < var2)
	{
		char input;
		bool esc = false;
		cout << "��� �������� ��������� ������ ��� ����� �����. ��������� ��������� ����� �� �����? y - ��, n - ���, �������� ����������.\n��� �����: ";
		while (!esc)
		{
			cin >> input;
			switch (input)
			{
			case 'n':
			case 'N': cout << "�������� ��������."; !esc; break;
			case 'y':
			case 'Y': var1r = rounder(var1); var2r = rounder(var2); break;
			default: cout << "�� ����� �������� ������. ���������� ��� ���: ";
			}
			!esc; break;
		}
	}
	remaind = var1r % var2r;
	printResult(var1r, '%', var2r, remaind);
	return remaind;
}

double exponential(double var, double exp) // ���������� � ������� � ��������� ���������� �������, � ��� ����� � ������������� ����������� �������
{
	if ((int)exp < exp)
	{
		cout << "� ���� ������ ������������ ���������� ������� ����� ���� ������ ����� ������.";
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

double factorial(double var) //���������
{
	long double factorial = 1;
	int varr = (int)var;
	if (varr < var)
	{
		char input;
		bool esc = false;
		cout << "��� �������� ��������� ������ ��� ����� �����. ��������� ��������� ����� �� �����? y - ��, n - ���, �������� ����������.\n��� �����: ";
		while (!esc)
		{
			cin >> input;
			switch (input)
			{
			case 'n':
			case 'N': cout << "�������� ��������."; !esc; break;
			case 'y':
			case 'Y': varr = rounder(var); break;
			default: cout << "�� ����� �������� ������. ���������� ��� ���: ";
			}
			!esc; break;
		}
	}
	if (varr > 20)
	{
		cout << "��������� ��������� ����� ���� �������� ������ ��� ����� ����� �� 20 ������������.";
		!exit;
	}
	else if (varr < 0)
	{
		cout << "��������� ������������� ����� �� ����������.";
		!exit;
	}
	else
	{
		for (int i = 1; i <= varr; i++)
		{
			factorial *= i;
		}
		cout << var << "! = " << factorial << endl;
		cout << "��� ����������� ���������� ��� ����������� ������ ���������� ������� ���������:\n";
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
	cout << "��������� ��� ����������.\n���������� ��������:\n\t+ ��������\n\t- ���������\n\t* ���������\n\t/ �������\n\t% ���������� ������� �� ������� (������ ��� ����� �����)\n";
	cout << "\t^ ���������� � ������� (������ ��� ����� ����������� �������)\n\t! ���������� ���������� (�� 20, ������������ ������ ��� ����������� �����)\n";
	cout << "��� ������ �� ��������� ������� \"n\" ����� ������ ����������.\n������� ������ ��������� ��� ����������:\n";
	cin >> var1;

	while (exit == false)
	{
		cin >> operation;
		if (operation == 'n' || operation == 'N')	// Exit �����
		{
			exit = true;
			cout << "������ � ���������� ���������.\n";
		}
		// Unary operators ������� ���������
		else if (operation == '!')					// Factorial ���������
		{
			if (var1 > 20)
			{
				cout << "��������������! ��������� ��������� ����� ���� �������� ������ ��� ������ ����� �� 20, ������������.\n";
				exit = true;
			}
			else if (var1 < 0)
			{
				cout << "��������������! ��������� ������������� ����� �� ����������.\n";
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
			if (operation == '+')					// Addition ��������
			{
				result = var1 + var2;
			}
			else if (operation == '-')				// Subtraction ���������
			{
				result = var1 - var2;
			}
			else if (operation == '*')				// Multiplication ���������
			{
				result = var1 * var2;
			}
			else if (operation == '/')				// Dividing �������
			{
				if (var2 == 0)
				{
					cout << "��������������! �� ���� ������ ������!";
					exit = true;
				}
				else
				{
					result = var1 / var2;
				}
			}
			else if (operation == '%')				// Remainder of dividing ������� �� �������
			{
				if ((int)var1 < var1 || (int)var2 < var2)
				{
					cout << "��������������! ��� �������� �������� ������ ��� ����� �����.";
					exit = true;
				}
				else
				{
					result = (int)var1 % (int)var2;
				}
			}
			else if (operation == '^')				// Exponetiation ���������� � �������
			{
				result = 1;
				if ((int)var2 < var2)
				{
					cout << "��������������! ���������� ������� ������ ���� ����� ������."�
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
			if (exit == true)						// Print result ����� ����������
			{
				cout << "\n ���������� ��������� �������� ��-�� ������������� ����� ������ �������������.";
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
	cout << "��������� ��� ����������.\n���������� ��������:\n\t+ ��������\n\t- ���������\n\t* ���������\n\t/ �������\n\t% ���������� ������� �� ������� (������ ��� ����� �����)\n";
	cout << "\t^ ���������� � ������� (������ ��� ����� ����������� �������)\n\t! ���������� ���������� (�� 20, ������������ ������ ��� ����������� �����)\n";
	cout << "��� ������ �� ��������� ������� \"n\" ����� ������ ����������.\n������� ������ ��������� ��� ����������:\n";
	cin >> var1;

	while (exit == false)
	{
		cin >> operation;
		switch (operation)
		{
		// Unary operators ������� ���������
		case 'n':									// Exit �����
		case 'N': exit = true; cout << "������ � ���������� ���������."; break;
		case '!':									// Factorial ���������
		{
			if (var1 > 20)
			{
				cout << "��������������! ��������� ��������� ����� ���� �������� ������ ��� ������ ����� �� 20, ������������.\n";
				exit = true;
			}
			else if (var1 < 0)
			{
				cout << "��������������! ��������� �������������� ����� �� ����������.\n";
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
			// Binary operators �������� ���������
			cout << var1; cin >> var2;
			switch (operation)
			{
			case '+': result = var1 + var2; break;	// Addition ��������
			case '-': result = var1 - var2; break;	// Substraction ���������
			case '*': result = var1 * var2; break;	// Multiplication ���������
			case '/':								// Divided �������
			{
				if (var2 != 0)
				{
					result = var1 / var2;
				}
				else
				{
					cout << "��������������! �� ���� ������ ������!";
					exit = true;
				}
				break;
			}
			case '%':								// Remainder of dividing ������� �� �������
			{
				if (!((int)var1 < var1 || (int)var2 < var2))
				{
					cout << "��������������! ��� �������� �������� ������ ��� ����� �����.";
					exit = true;
				}
				else
				{
					result = (int)var1 / (int)var2;
				}
				break;
			}
			case '^':								// Exponential ���������� � �������
			{
				result = 1;
				if ((int)var2 < var1)
				{
					cout << "��������������! ���������� ������� ������ ���� ����� ������.";
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
				cout << "��������������! ������� ������������ ��������.\n";
			}
			}
		if (exit == true)							// Print result ����� ����������
		{
			cout << "\n ���������� ��������� �������� ��-�� ������������� ����� ������ �������������.";
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
	cout << "��������� ��� ����������.\n���������� ��������:\n\t+ ��������\n\t- ���������\n\t* ���������\n\t/ �������\n\t% ���������� ������� �� ������� (������ ��� ����� �����)\n";
	cout << "\t^ ���������� � ������� (������ ��� ����� ����������� �������)\n\t! ���������� ���������� (�� 20, ������������ ������ ��� ����������� �����)\n";
	cout << "��� ������ �� ��������� ������� \"n\" ����� ������ ����������.\n������� ������ ��������� ��� ����������:\n";
	cin >> var1;

	while (!exit)
	{
		cin >> operation;
		if (operation != '!' && operation != 'n' && operation != 'N') cin >> var2;
		switch (operation)
		{
			// Unary operators ������� ���������
		case 'n':												// Exit �����
		case 'N': exit = true; cout << "������ � ���������� ���������.\n"; break;
		//case 's': sinus(var1); break;							// Sinus �����
		//case 'c': cosinus(var1); break:						// Cosinus �������
		case '!': result = factorial(var1); break;						// Factorial ���������
			// Binary operators �������� ���������
		case '+': result = addition(var1, var2); break;		// Addition ��������
		case '-': result = substraction(var1, var2); break;	// Substraction ���������
		case '*': result = multiplication(var1, var2); break;	// Multiplication ���������
		case '/': result = divided(var1, var2); break;		// Divided �������
		case '%': result = remaind(var1, var2); break;		// Remainder of the didided ������� �� �������
		case '^': result = exponential(var1, var2); break;				// Exponential ���������� � �������
		default: cin >> var1; break;
		}
		var1 = result;
	}
#endif	
}

