#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact {
	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		int 		_phoneNumber;
		std::string _darkestSecret;
		std::string	input(std::string, bool);
		bool		_isDigit(std::string);
	public:
		Contact();
		// Accessor
		std::string getFirstname() const;
		std::string getLastname() const;
		std::string getNickname() const;
		int 		getPhoneNumber() const;
		std::string getDarkestSecret() const;
		void 		setFirstname(std::string);
		void 		setLastname(std::string);
		void 		setNickname(std::string);
		void 		setPhoneNumber(int);
		void 		setDarkestSecret(std::string);

		// Fcts
		void		initContact();
		void		displayContact();
};
#endif