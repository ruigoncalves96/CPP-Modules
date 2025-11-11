#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &copy);
		virtual ~Brain();

		Brain& operator=(const Brain &copy);

		void setIdea(int idx, const std::string &idea);
		const std::string getIdea(int idx) const;

	private:
		std::string _ideas[100];

		void _copyBrain(const Brain &src);
};

#endif
