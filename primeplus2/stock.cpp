#include "stock.h"
#include<iostream>

Stock::Stock()
{
	compang = "none";
	share = 0;
	share_val = 0.0;
	total_val = 0.0;
}
Stock::Stock(const std::string& co, long n, double pr)
{
	compang = co;
	if (n < 0)
	{
		std::cout << "搞笑吧，股份小于零！！" << compang;
	}
	else
	{
		share = n;
	}
	share_val = pr;
	set_tot();
}
Stock::~Stock() {}
void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "搞笑吧，num小于零！！";
	}
	else
	{
		share += num;
		share_val = price;
		set_tot();
	}
}
void Stock::sell(long num, double price)
{
	if (num < 0)
	{
		std::cout << "搞笑吧，num小于零！！";
	}
	else if (num > share)
	{
		share -= num;
		share_val = price;
		set_tot();
	}
}
void Stock::update(double price)
{
	share_val = price;
	set_tot();

}
void Stock::show()const
{
	using std::cout;
	using std::ios_base;
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);

	cout << "compang:" << compang << "  share:" << share <<"   share_val:"<<share_val<< "\n";
	cout.precision(2);
	cout << "  total_val:" << total_val;

	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);

}
const Stock& Stock::topval(const Stock& s)const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
	
}







