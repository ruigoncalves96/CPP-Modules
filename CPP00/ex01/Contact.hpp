#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "yellowpages.hpp"

class Contact
{
	public:
		Contact() : index(0) {};
		~Contact(){};
	
		int					index;

		bool 				get_contact_info();
		void				print_contact_info();
		const std::string&	get_first_name() const;
		const std::string&	get_last_name() const;
		const std::string&	get_nickname() const;

	private:
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_phone_number;
		std::string		_darkest_secret;
};

# endif
