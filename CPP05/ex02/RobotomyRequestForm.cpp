# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45, "Unkown")
{
	// std::cout << "Default RobotomyRequestForm constructor called. 'Sir' created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request", 72, 45, target)
{
	// std::cout << "Default RobotomyRequestForm constructor called. '" << this->_name << "' created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj)
{
	// std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "Default RobotomyRequestForm destructor called. '" << this->_name << "' destroyed." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	// std::cout << "RobotomyRequestForm copy assignment called." << std::endl;
	(void)obj;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->getSign() == true)
	{
		if (executor.getGrade() <= this->getExecGrade())
		{
			std::cout << "<BRRRRRR#RRR ZRRR#RR#RRR BR BR BRRRR#>\n";
			if (chance50())
				std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
			else
				std::cout << "The robotomy failed!" << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		throw FormNotSigned();
}

bool RobotomyRequestForm::chance50() const
{
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }
    return std::rand() % 2 == 0;
}