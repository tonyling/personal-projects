#include <iostream>
#include <vector>
#include <cstdlib>
//#include <time>
#include "quicksort.cpp"

template <typename T>
void gen_rand_vector(std::vector<T> &array)
{
	unsigned int size=array.size();
	for (unsigned i = 0; i < size; i++)
	{
		array[i]=i;
	}

	for (unsigned i = 0; i < size; i++)
	{
		int index = rand()%size;
		T temp = array[i];
		array[i]=array[index];
		array[index]= temp;
	}
}

template <typename T>
void print_vector(std::vector<T> &vec)
{
	for (unsigned i = 0; i < vec.size(); i++)
	{
		std::cout << "  "<< vec[i] << std::endl;
	}
}
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	std::vector<int> array;
	array.resize(10);
	std::cout << "Randomized array:" << std::endl;
	gen_rand_vector(array);
	print_vector(array);

	std::cout << "Sorted array:" << std::endl;	
	quicksort(array, 0, array.size()-1);
	print_vector(array);
		
	return 0;
}