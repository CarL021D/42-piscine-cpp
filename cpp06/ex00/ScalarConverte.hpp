#pragma once
#include <iostream>

class  ScalarConverte {
	public:
			ScalarConverte();
			~ScalarConverte();
			ScalarConverte(const ScalarConverte& src);
			ScalarConverte& operator=(const ScalarConverte& rhs);

			static void		convert(std::string str);
};