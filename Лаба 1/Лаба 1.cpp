/*Создать класс String (строка). Разработать в классе методы для работы со строками: trim (удаляет начальные и конечные пробелы из строки,
c помощью дополнительного оператора можно задать где именно удалить пробелы: both (в начале и в конце), trailing (только в конце), leading (только в
начале), indexOf(find, start, end) (возвращает позицию первого вхождения подстроки find в текущую строку, параметр start позволяет установить
позицию в текущей строке, с которой начинается поиск подстроки find. Если подстрока не найдена, то возвращается -1. Использовать конструктор с
параметрами, конструктор без параметров, конструктор копирования. Написать программу, которая будет запрашивать у пользователя и выводить
на экран сведения о сотрудниках. В класс добавить необходимый набор полей и методов (минимум два поля и два метода) на свое усмотрение.
Предусмотреть метод для записи полученных данных в файл.*/

#include <iostream>
using namespace std;

class MyString
{
public:

	MyString()
	{
		str = nullptr;
		length = 0;
	}
	MyString(const char* str)
	{

		length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
	}
	~MyString()
	{
		delete[] this->str;
	}

	MyString(const MyString &other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}

	MyString& operator = (const MyString &other)
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';

		return *this;


	}

	MyString operator+(const MyString& other)
	{
		MyString newStr;

		int thisLenght = strlen(this->str);
		int otherLenght = strlen(other.str);
		newStr.length = thisLenght + otherLenght;
		newStr.str = new char[newStr.length + 1];
		
		int i = 0;
		for (; i < thisLenght; i++)
		{
			newStr.str[i] = this->str[i];
		}

		for (int j = 0; j < otherLenght; j++)
		{
			newStr.str[j+i] = other.str[j];
		}
		newStr.str[newStr.length] = '\0';
		return newStr;
	}
	void Print()
	{
		cout << str;
	}

	int Length()
	{
		return length;
	}

	MyString removeFirstPlaseSpace()
	{
		MyString newStr;
		length = strlen(this->str);
		newStr.str = new char[newStr.length + 1];
		int j = 0;
		for (int i = 0; i < length; i++)
		{
			if (this->str[0] == ' ')
			{
				length--;
				i--;
			}
			else
			{
				newStr.str[j] = this->str[i];
				j++;
			}
		}
		newStr.str[length] = '\0';

		return newStr;
	}
	
	bool operator ==(const MyString &other)
	{
		if (this->length != other.length )
		{
			return false; 
		}

		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}


	bool operator !=(const MyString& other)
	{
		return !(this->operator==(other));

	}

	char& operator [](int index)
	{
		return this->str[index];
	}

	MyString(MyString &&other)
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}
private:
	char* str;

	int length;
};




int main()
{
	MyString str("1  Hello");
	MyString str2("    World");

	MyString result; 
	result = str + str2;
	
	//result.removeFirstPlaseSpace();
	result.Print();
	return 0;
}
