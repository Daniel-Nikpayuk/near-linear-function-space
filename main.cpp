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

	template<auto f, auto g, typename... Types>
	constexpr f_out_type<f> u_compose_u(Types... args)
		{ return f(g(args...)); }

	constexpr int square(int x)		{ return x*x; }
	constexpr int plus_two(int x)		{ return x+2; }
	constexpr int local_add(int x, int y)	{ return x+y; }

	constexpr auto func0			= u_compose_u<square, plus_two, int>;
	constexpr auto func1			= u_compose_u<square, local_add, int, int>;

	//



	template<typename, typename, typename> struct pattern_match_compose;

	template
	<
		template<typename...> class ListName1, typename... Types1,
		template<typename...> class ListName2, typename... Types2,
		template<typename...> class ListName3, typename... Types3
	>
	struct pattern_match_compose<ListName1<Types1...>, ListName2<Types2...>, ListName3<Types3...>>
	{
		template<auto f_3, auto g_2>
		static constexpr f_out_type<f_3> result(Types1... args1, Types2... args2, Types3... args3)
		{
			return f_3(args1..., g_2(args2...), args3...);
		}
	};

	template<typename...> struct arg_list	{ };

	using arg_list1				= arg_list<int>;
	using arg_list2				= arg_list<int, int>;
	using arg_list3				= arg_list<int>;

	constexpr int multiply2(int x, int y)	{ return x*y; }
	constexpr int add3(int x, int y, int z)	{ return x+y+z; }

	constexpr auto curried_func		= pattern_match_compose<arg_list1, arg_list2, arg_list3>::template
							result<add3, multiply2>;

/***********************************************************************************************************************/

	int main(int argc, char *argv[])
	{
		printf("%d\n", func0(5));			// prints: 49
		printf("%d\n", func1(5, 7));			// prints: 144

		printf("%d\n", curried_func(1, 2, 3, 4));	// prints: 11

		return 0;
	}

/***********************************************************************************************************************/

/*
	int square(int x)	{ return x*x; }
	int plus_two(int x)	{ return x+2; }
	void print(int x)	{ printf("%d\n", x); }

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

//		print_number(39275);

