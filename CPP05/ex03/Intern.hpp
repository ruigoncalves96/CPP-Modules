#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern&);
		~Intern();

		Intern& operator=(const Intern&);

		AForm* makeForm(const std::string &form, const std::string &target);

	private:
		static const std::string _formsName[3];

		int getFormIndex(const std::string &form);
};

#endif