#include <iostream>

class CountClass
{
	int* count;
public:
	CountClass() 
	{
		count = new int{};
		std::cout << this << " Count construct\n";
	}
	CountClass(int count) 
	{
		this->count = new int{ count };
		std::cout << this << " Count parameter construct\n";
	}

	CountClass(const CountClass& obj)
	{
		count = new int{ *(obj.count) };
		std::cout << this << " Count copy construct\n";
	}

	int& Count() { return *count; }

	~CountClass()
	{
		std::cout << this << " Count destruct\n";
		delete count;
	}

	CountClass operator=(const CountClass& obj)
	{
		count = new int{ *(obj.count) };
		std::cout << this << " Count copy assign\n";
		return *this;
	}
};

class Account
{
	int rub;
	int kop;
public:
	Account() : rub{}, kop{}
	{
		std::cout << "amount default cunstruct\n";
	}
	
	Account(int rub, int kop) 
		: rub{ rub }, kop{ kop }
	{
		std::cout << "amount parameter cunstruct\n";
	}

	explicit Account(int amount)
		: rub{ amount / 100 }, kop{ amount % 100 }
	{
		std::cout << "amount parameter cunstruct\n";
	}

	explicit Account(double amount)
	{
		rub = amount;
		kop = (amount - rub) * 100;
	}

	explicit operator double()
	{
		return rub + (double)kop / 100;
	}

	int& Rub() { return rub; }
	int& Kop() { return kop; }
};


void CountFunc(CountClass cnt)
{

}

CountClass GetCount()
{
	CountClass c;
	return c;
}


void PrintAccount(Account acc)
{
	std::cout << "Amount = " << acc.Rub() << " rub., " 
		<< acc.Kop() << " kop."
		<< "\n";
}

void PrintDouble(double x)
{
	std::cout << x << "\n";
}

int main()
{
	/*CountClass cnt1(10);
	CountClass cnt2;

	cnt2 = cnt1;*/

	/*
	std::cout << cnt1.Count() << " " << cnt2.Count() << "\n";
	cnt2.Count() = 20;
	std::cout << cnt1.Count() << " " << cnt2.Count() << "\n";*/

	//CountFunc(cnt1);

	/*Account acc1{ 10 };
	PrintAccount(acc1);*/
	//PrintAccount((Account)12.5);
	Account acc(12, 56);
	
	PrintDouble((double)acc);
}
