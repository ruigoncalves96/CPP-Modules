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
			std::cout << out_of_range << "\n";
		}
		catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
		try
		{
			Bureaucrat out_of_range("Rui", 151);
			std::cout << out_of_range << "\n";
		}
		catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
		std::cout << "\n\n";
	}
	// Operator ++ test
	{
		std::cout << "|| Operator ++ test || \n";
		Bureaucrat bureau("Rui", 3);
		try
		{
			std::cout << bureau << "\n";
			std::cout << "-------\n";
			std::cout << bureau.getName() << "'s grade + 1:" << "\n";
			std::cout << "   * [bureau++] = " << bureau++ << "\n";
			std::cout << bureau.getName() << "'s new grade = " << bureau.getGrade() << "\n";
			std::cout << "-------\n";
			std::cout << bureau.getName() << "'s grade + 1:" << "\n";
			std::cout << "   * [++bureau] = " << ++bureau << "\n";
			std::cout << bureau.getName() << "'s new grade = " << bureau.getGrade() << "\n";
			std::cout << "-------\n";
			std::cout << bureau.getName() << "'s grade + 1 -> [Must throw an error]" << "\n";
			bureau++;
		}
		catch (std::exception& e) { std::cout << e.what() << std::endl; }
		std::cout << "\n\n";
	}
	// Operator -- test
	{
		std::cout << "|| Operator -- test || \n";
		Bureaucrat bureau("Rui", 148);
		try
		{
			std::cout << bureau << "\n";
			std::cout << "-------\n";
			std::cout << bureau.getName() << "'s grade - 1:" << "\n";
			std::cout << "   * [bureau--] = " << bureau-- << "\n";
			std::cout << bureau.getName() << "'s new grade = " << bureau.getGrade() << "\n";
			std::cout << "-------\n";
			std::cout << bureau.getName() << "'s grade - 1:" << "\n";
			std::cout << "   * [--bureau] = " << --bureau << "\n";
			std::cout << bureau.getName() << "'s new grade = " << bureau.getGrade() << "\n";
			std::cout << "-------\n";
			std::cout << bureau.getName() << "'s grade - 1 -> [Must throw an error]" << "\n";
			bureau--;
		}
		catch (std::exception& e) { std::cout << e.what() << std::endl; }
	}
	
	return (0);
}
