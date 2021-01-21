/************************************************************************************************************************
**
** Copyright 2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
**
** This file is part of near_linear_function_space.
**
** near_linear_function_space is free software: you can redistribute it and/or modify it under the terms
** of the GNU General Public License as published by the Free Software Foundation, either version 3
** of the License, or (at your option) any later version.
**
** near_linear_function_space is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
** without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with near_linear_function_space.
** If not, see <http://www.gnu.org/licenses/>.
**
************************************************************************************************************************/

#include<cstdio>
#include"a-source.hpp"
//#include"b-modules.hpp"
//#include"C-tests/prerequisites.hpp"

/***********************************************************************************************************************/

//	using namespace extended_numbers;
//	using namespace ocli_testing;

/***********************************************************************************************************************/

	using namespace list_operators;

/***********************************************************************************************************************/

	void print(int x)						{ printf("%d\n", x); }
	constexpr char c73()						{ return 73; }
	constexpr int plus_two(int x)					{ return x+2; }
	constexpr int local_add(int x, int y)				{ return x+y; }
	template<typename Type> constexpr Type square(Type x)		{ return x*x; }

	constexpr auto func0						= V_compose_opt<square<int>, plus_two>;
	constexpr auto func1						= V_compose_opt<square<int>, local_add>;
	constexpr auto func2						= V_compose_opt<plus_two, c73>;
	constexpr auto func3						= V_compose_opt<print, c73>;

//	constexpr int multiply2(int x, int y)				{ return x*y; }
//	constexpr int add3(int x, int y, int z)				{ return x+y+z; }

//	constexpr auto curried_func					= pattern_match_compose
//									<arg_list1, arg_list2, arg_list3>::template
//									result<add3, multiply2>;

/***********************************************************************************************************************/

	int main(int argc, char *argv[])
	{
		printf("%d\n", func0(5));			// prints: 49
		printf("%d\n", func1(5, 7));			// prints: 144
		printf("%d\n", func2());			// prints: 75
		func3();					// prints: 73

		return 0;
	}

/***********************************************************************************************************************/

/*
	auto comp1		= V_compose_opt		< square   , plus_two >;
	auto comp2		= V_compose_opt		< print    , square   >;

//	using S_comp3		= S_compose_opt		< 5        , plus_two >;	// static assertion failure.
	using S_comp3		= S_compose_opt		< plus_two , plus_two >;	// static assertion success.
	using assert1		= assert_S_compose	< S_comp3             >;

	auto comp3		= V_value_S		< S_comp3             >;
*/

/***********************************************************************************************************************/

//		print(comp1(5));	// prints: 49
//		comp2(7);		// prints: 49
//		print(comp3(11));	// prints: 15

//		printf("%d\n", curried_func(1, 2, 3, 4));	// prints: 11

//		print_number(39275);

