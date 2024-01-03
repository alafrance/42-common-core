 #ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include "Contact.hpp"

class Phonebook {
	private:
		int			nbContact;
		Contact		_Contact[8];
		bool		_isDigit(std::string);
	public:
		Phonebook(void);
		Contact*			getContact(void);
		void				print_format_string(std::string);
		void 				ft_add(void);
		void 				ft_search(void);
};
#endif