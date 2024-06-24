#include <iostream>
#include <string>
using namespace std;

char* Date()
{
	char date[50] = {}; // строка для результата

	time_t unixTime = time(nullptr);// время в милисекундах

	ctime_s(date, sizeof(date) / sizeof(date[0]), &unixTime); // преобразование в строку
	return date;
}

class Printer
{
	string* statist;
	string* mas;
	int MaxSize;
	int length;
public:
	Printer(int m)
	{
		MaxSize = m;
		statist = new string[MaxSize];
		mas = new string[MaxSize];
		length = 0;
	}

	bool IsFull()
	{
		return length == MaxSize;
	}

	bool IsEmpty()
	{
		return length == 0;
	}

	int GetCount()
	{
		return length;
	}

	void Add(string s, string m)
	{
		if (!IsFull())
		{
			statist[length] = s;
			mas[length] = m;
			length++;
		}
	}

	void Pop()
	{
		if (!IsEmpty())
		{
			for (int i = 1; i < length;i++)
			{
				statist[i - 1] = statist[i];
				mas[i - 1] = mas[i];
			}
			length--;
		}
	}

	void Show() {
		cout << "\n-------------------------------------\n";
		for (int i = 0; i < length; i++) {
			cout << statist[i] << " "<< mas[i]<<endl;
		}
		cout << "\n-------------------------------------\n";
	}

	~Printer()
	{
		delete[] mas;
		delete[] statist;
	}
};

int main()
{
	string a1 = "first ";
	a1 += Date();
	string a2 = "second ";
	a2 += Date();

	Printer a(10);
	a.Add(a1, "FIRST");
	a.Add(a2, "SECOND");
	a.Show();
	a.Pop();
	a.Show();
}