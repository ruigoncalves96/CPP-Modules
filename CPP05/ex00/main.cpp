# include "Bureaucrat.hpp"

int main(void)
{
	// Constructors test
	{
		std::cout << "|| Constructors test || \n";
		Bureaucrat a;
		std::cout << a << "\n";
		Bureaucrat b("Rui", 50);
		std::cout << b << "\n";
		Bureaucrat c(b);
		std::cout << "Copy constructor -> " << b << "\n";
		try
		{
			Bureaucrat out_of_range("Rui", 0);
			std::cout << b << "\n\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			Bureaucrat out_of_range("Rui", 151);
			std::cout << b << "\n\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\n\n";
	}
	// Operator ++ test
	{
		std::cout << "|| Operator ++ test || \n";
		Bureaucrat student("Rui", 2);
		try
		{
			std::cout << student << "\n";
			std::cout << student.getName() << "'s grade + 1" << "\n";
			student++;
			std::cout << student.getName() << "'s new grade = " << student.getGrade() << "\n";
			std::cout << student.getName() << "'s grade + 1" << "\n";
			student++;
			std::cout << student.getName() << "'s new grade = " << student.getGrade() << "\n";
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "\n\n";
	}
	// Operator -- test
	{
		std::cout << "|| Operator -- test || \n";
		Bureaucrat student("Rui", 149);
		try
		{
			std::cout << student << "\n";
			std::cout << student.getName() << "'s grade - 1" << "\n";
			student--;
			std::cout << student.getName() << "'s new grade = " << student.getGrade() << "\n";
			std::cout << student.getName() << "'s grade - 1" << "\n";
			student--;
			std::cout << student.getName() << "'s new grade = " << student.getGrade() << "\n";
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	return (0);
}
