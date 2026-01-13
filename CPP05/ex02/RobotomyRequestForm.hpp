#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm&);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm&);

		void execute(const Bureaucrat &executor) const;
	
	private:
		bool chance50() const;
};

#endif