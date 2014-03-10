#include <iostream>
#include <string>
#include "linked_list.cpp"

int main(int argc, char const *argv[])
{
	std::cout << "Testing int:\n";
	linked_list<int> ll(10);
	std::cout << "  Inserted 10"          << std::endl;
	std::cout << "    linked_list size: " << ll.size()  << std::endl;
	std::cout << "    front of ll: "      << ll.front() << std::endl;
	ll.insert(22);
	std::cout << "  Inserted 22"          << std::endl;
	std::cout << "    linked_list size: " << ll.size()  << std::endl;
	std::cout << "    front of ll: "      << ll.front() << std::endl;
	std::cout << "    back of ll: "       << ll.back()  << std::endl;
	std::cout << "    exists 22: "        << ll.exists(22) << std::endl;
	ll.pop();
	std::cout << "  pop()"                << std::endl;	
	std::cout << "    linked_list size: " << ll.size()  << std::endl;
	std::cout << "    front of ll: "      << ll.front() << std::endl;
	std::cout << "    back of ll: "       << ll.back()  << std::endl;
	std::cout << "    exists 10: "        << ll.exists(10) << std::endl;
	std::cout << "    exists 22: "        << ll.exists(22) << std::endl;
	
	std::cout << "  Inserting 1000 int"   << std::endl;
	for (unsigned i = 0; i < 1000; i++)
		ll.insert(i);
	std::cout << "    linked_list size: " << ll.size()  << std::endl;
	std::cout << "    front of ll: "      << ll.front() << std::endl;
	std::cout << "    back of ll: "       << ll.back()  << std::endl;
	
	std::cout << "Testing char:\n";
	linked_list<char> ll_c('h');
	std::cout << "  Inserted 'g'"         << std::endl;
	std::cout << "    linked_list size: " << ll_c.size() << std::endl;
	std::cout << "    front of ll_c: "    << static_cast<char>(ll_c.front()) << std::endl;
	std::cout << "  Testing insert, insert_after, pop_after"     << std::endl;

	ll_c.insert('l');
	ll_c.insert('l');
	ll_c.insert_after('e',0);
	ll_c.insert_after('c',1);
	ll_c.insert_after('o',ll_c.size()-1);
	ll_c.pop_after(1);

	std::cout << "    ";
	while (!ll_c.empty())
		std::cout << ll_c.pop();
	std::cout << std::endl;
	return 0;
}