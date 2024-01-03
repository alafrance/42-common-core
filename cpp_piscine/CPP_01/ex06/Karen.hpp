#ifndef KAREN
#define KAREN
#include <iostream>

class Karen {
public:
	Karen();
	~Karen();
	void complain( std::string level );
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	typedef void (Karen::*ptrMemFunc) (void);
	void	display_level(std::string header, ptrMemFunc func);
};

#endif