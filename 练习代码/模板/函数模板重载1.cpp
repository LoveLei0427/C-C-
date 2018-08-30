#include<iostream>
#include<array>
static int i;
template <typename T>

void showarray(std::array<T, 10>myarray, int n)
{	
	std::cout << "TTTTTTTTTTTTT" << std::endl;
	for (i = 0; i < n; i++)
	{
		std::cout << myarray[i] << std::endl;
	}
	std::cout << std::endl;
}

template<typename T>
void showarray(std::array<T*,10>myarray,int n)
{
	std::cout << "T***************" << std::endl;
	for (i = 0; i < n; i++)
	{
		std::cout << *myarray[i] << std::endl;
	}
	std::cout << std::endl;
}

int main(void)
{
	std::array<int, 10>intarray = { 1, 2, 3, 4, 5,6,7,8,9,10 };
	showarray(intarray, 10);
	std::array<int*, 10>pointarray;
	std::array<int**, 10>addressarray;
	for (i = 0; i < 10; i++)
	{
		pointarray[i] = &intarray[i];
	}
	showarray(intarray, 10);
	showarray(pointarray, 10);
	/*
	for (i = 0; i < 10; i++)
	{
		adressintarray[i] = &pointarray[i];
	}
	showarray(addressarray, 10);//´òÓ¡µØÖ·
	*/
	showarray(addressarray, 10);
	
	std::cin.get();
}