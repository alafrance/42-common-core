#include "iter.hpp"
#include <iostream>

// int main() {
// 	std::string array[3] = {"first parameter", "second parameter","third parameter" };
// 	::iter(array, 4, ft_putstr);
// 	int		array_nb[3] = {4, 8, 1};
// 	::iter(array_nb, 3, ft_print_nb);
// 	::iter2(array, 3, ft_print);
// }

class Awesome
{
public:
Awesome( void ) : _n( 42 ) { return; }
int get( void ) const { return this->_n; }
private:
int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }
int main() {
int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
Awesome tab2[5];

iter( tab, 5, print );
iter( tab2, 5, print );

return 0;
}