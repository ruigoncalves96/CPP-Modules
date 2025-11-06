#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "yellowpages.hpp"
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook() :	_next_index_to_fill(0),
						_nbr_of_contacts(0) {};
		~PhoneBook(){};

		bool add_contact();	
		void print_yellowbook();
		bool choose_contact();

	private:
		Contact	_contacts[8];
		int		_next_index_to_fill;
		int		_nbr_of_contacts;
};

# endif
