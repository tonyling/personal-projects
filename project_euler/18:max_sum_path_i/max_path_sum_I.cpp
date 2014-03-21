#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cerrno>
#include <cstdlib>

static void 
die(const char *msg)
{
	std::perror(msg);
	std::exit(1);
}

static void 
die2(const char *msg)
{
	std::cerr << msg << std::endl;
	std::exit(1);
}

// Returns a vector of vector of ints resembling a triangle structure
std::vector< std::vector<int> > 
gen_triangle_vec(const char* file_name)
{
	std::vector< std::vector<int> > triangle;
	std::stringstream ss;
	std::vector<int> temp_v;
	int temp_int;

	std::string line;
	std::ifstream file(file_name);
	if (file.is_open())
	{
		// Read from triangle.txt file and store data into 2D array
		while(std::getline(file, line))
		{
			// Clear and reset ss and helper vector
			ss.str("");
			ss.clear();
			temp_v.clear();
			
			// Uses stringstream to convert string to int and push onto vector
			ss << line;
			while (ss >> temp_int) 
			{
				temp_v.push_back(temp_int);
			}
			triangle.push_back(temp_v);
		}
	}
	else
		die("File cannot be opened");
	return triangle;

}

// Uses a dynamic programming, bottom up approach to avoid recursion
// When given 2 bottom adjacent values, we want the greatest value
// Calculates values from bottom of the triangle to the top, so the peak
// of the triangle contains the maximum sum possible
int
find_max_sum(std::vector< std::vector<int> > triangle)
{
	if (triangle.empty())
		die2("Triangle vector is empty");

	unsigned int depth = triangle.size();
	for (int i = depth-2; i >=0; i--)
	{
		for (int j = 0; j < triangle[i].size(); j++)
		{
			//Check bottom left adjacent value
			int cur_max = triangle[i+1][j];
		
			//Check bottom right adjacent value
			if (triangle[i+1][j+1] > cur_max)
				cur_max    = triangle[i+1][j+1];

			triangle[i][j] += cur_max;
		}
	}
	return triangle[0][0];
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
		die2("Usage: ./a.out [textfile]");
	std::vector< std::vector<int> > triangle = gen_triangle_vec(argv[1]);
	std::cout << find_max_sum(triangle) << std::endl;	

	return 0;
}