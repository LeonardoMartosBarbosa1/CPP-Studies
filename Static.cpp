/*Static Class Data Members

	(1) A data member or member function may be declared with the STATIC keyword in its member-declaration
	    in such case they are  static data member or static member functions: https://eel.is/c++draft/class#mem.general-5

	(2) A non-volatile non-inline const static data member of enumeration or integral type can specify an 
	brace-or-equal-initializer in the class definition. if still odr-used, it shall be defined in a namespace 
	scope and shall not contain an initializer: https://eel.is/c++draft/class#static.data-4

	(3)A non-inline static data member declaration in a class definition is a non-defining declaration:
	https://eel.is/c++draft/basic#def-2.3

	(4)static data member declared outside class definition is a non-defining declaration if it was defined in
	the class definition with the CONSTEXPR specifier https://eel.is/c++draft/basic#def-2.4
													  https://eel.is/c++draft/depr.static.constexpr

	(5) A function or static data member declared with the constexpr or consteval specifier on its first declaration is implicitly 
	    an inline function or variable: https://eel.is/c++draft/dcl.constexpr#1.sentence-3
	
	(6) About (2) and (3) more info: https://stackoverflow.com/questions/41982545/c-static-const-members-definition
	                                 https://stackoverflow.com/questions/61856487/confusion-about-declaration-and-definition-of-static-const-data-memebers
									 https://stackoverflow.com/questions/3025997/defining-static-const-integer-members-in-class-definition
									 https://www.stroustrup.com/bs_faq2.html#in-class

*/


/* 
(2) and (3)
*/

#include <iostream>

class AE {
	// ...
public:
	static const int c6 = 7;
	static const int c7 = 31;
	static const int c8 = 32;
};
const int AE::c7;       // definition
const int AE::c8 = 4;   // definition with initializer -> error by (2)

int main()
{
	const int* p1 = &AE::c6;    // error: c6 not an lvalue
	const int* p2 = &AE::c7;    // ok
	// ...
	std::cout << *p1 << "(" << p1 << ") - " << *p2 << "(" << p2 << ")" << std::endl;
	return 0;
}

/*
	(4) Note that By (5) the static member below is inline, so it doesnt fall in (2) and neither non defining declaration
	case, so its a definition
*/

struct A {
	static constexpr int n = 5;   // definition (declaration in C++ 2014)
								  
};

constexpr int A::n;  // redundant declaration (definition in C++ 2014)

