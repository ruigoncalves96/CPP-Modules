# include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain class constructed" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	this->_copyBrain(copy);
	std::cout << "Brain class copied" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain class destructor" << std::endl;
}

Brain& Brain::operator=(const Brain &copy)
{
	if (this != &copy)
	{
		this->_copyBrain(copy);
		std::cout << "Brain class copied using operator assignment" << std::endl;
	}
	return (*this);
}

//	--- Public ---	//

void Brain::setIdea(int idx, const std::string &idea)
{
	if (idx >= 0 && idx < 100)
		this->_ideas[idx] = idea;
	std::cout << "Idea added" << std::endl;
}

const std::string Brain::getIdea(int idx) const
{
	if (idx >= 0 && idx < 100)
		return (_ideas[idx]);
	else
		return (std::string());
	std::cout << "Idea Accessed" << std::endl;
}

//	--- Private ---  //
void Brain::_copyBrain(const Brain &src)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
}

