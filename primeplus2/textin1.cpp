#include<iostream>
#include"stock.h"

const int st = 4;
void foo(int* ptr)
{

	*ptr+=1;
}
int main()
{
	Stock stock[st] = {
	Stock("NN",12,20.0),
	Stock("BB",22,22.0),
	Stock("MM",23,23.25),
	Stock("FF",60,26.5)
	};
	std::cout << "-------------___________________------------";
	int ss;
	for (ss = 0; ss < st; ss++)
	{
		stock[ss].show();
	}
	const Stock* top = &stock[0];
	for (ss = 1; ss < st; ss++)
	{
		std::cout << top << std::endl;
		std::cout << &top << "======="<<std::endl;

		top = &top->topval(stock[ss]);
		std::cout << top << std::endl;
		std::cout << &top << std::endl;
	}
	std::cout << "------------=====-----------";
	top->show();
	int a=5;
	int* pValue = &a;
	std::cout << pValue << std::endl;
	std::cout << &pValue << std::endl;
	std::cout << &*pValue << std::endl;
	std::cout << *&pValue << std::endl;
	std::cout << *pValue << std::endl;
	foo(pValue);
	return 0;
}