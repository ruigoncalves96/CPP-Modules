# include "MutantStack.hpp"
# include <iostream>
# include <list>

int main(void)
{
	std::cout << "|| MutantStack tests ||\n\n";
	{
		MutantStack<int> mstack;
	
		std::cout << "* Using Base std::stack members in MutantStack *\n";
		mstack.push(5);
		mstack.push(17);
		std::cout << "Poping value -> " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Stacks size = " << mstack.size() << std::endl;
		std::cout << "* --- --- --- *\n\n";
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
	
		std::cout << "* Iterators creation and print Stack *\n";
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "* --- --- --- *\n\n";

		std::cout << "* Stack copy constructor MutantStack *\n";
		std::stack<int> s(mstack);
		std::cout << "Done Successfully\n";
		std::cout << "* --- --- --- *\n\n";

		std::cout << "* MutantStack copy constructor *\n";
		MutantStack<int> copy_stack(mstack);
		it = copy_stack.begin();
		ite = copy_stack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "* --- --- --- *\n\n";

		std::cout << "* MutantStack copy assignment *\n";
		MutantStack<int> copy_a_stack;
		copy_a_stack = mstack;
		it = copy_a_stack.begin();
		ite = copy_a_stack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "* --- --- --- *\n\n";
	}
	std::cout << "|| List Container comparision ||" << std::endl;
	{
		std::list<int> mstack;
	
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
	
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return (0);
}