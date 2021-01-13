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

/*
	int factorial(int n)
	{
		using pair			= pair_signature
						<
							_car_object<int>,
							_cdr_object<int>
						>;

		constexpr auto is_zero		= sign_cast
						<
							is_value<int, 0>, cd_cdr, pair
						>;
		constexpr auto times		= sign_bicast
						<
							multiply<int>    , _id_            , cd_car  ,
								           _id_            , cd_cdr  , pair
						>;
		constexpr auto iterate		= sign_biapply
						<
							assign<int, int> , _id_            , d_car   ,
									   times           , cd_pair , pair
						>;
		constexpr auto decrement	= sign_biapply
						<
							assign<int, int> , _id_            , d_cdr   ,
								           add_by<int, -1> , cd_cdr  , pair
						>;
		constexpr auto pair_factorial	= cycle
						<
							pair,

							cp_stem		< is_zero, _id_ , iterate >,
							cp_lift		< decrement               >
						>;
		constexpr auto pair_car		= pair_f_car
						<
							_id_, d_car<int>, pair
						>;

		pair s(1, n);

		return  pair_car(pair_factorial(s));
	};
*/

/***********************************************************************************************************************/

	int square(int x)	{ return x*x; }
	int plus_two(int x)	{ return x+2; }
	void print(int x)	{ printf("%d\n", x); }

	auto comp1		= V_compose		< square   , plus_two >;
	auto comp2		= V_compose		< print    , square   >;

	using S_comp3		= S_compose		< 5        , plus_two >;	// static assertion failure.
	using S_comp3		= S_compose		< plus_two , plus_two >;	// static assertion success.
	using assert1		= assert_S_compose	< S_comp3             >;

	auto comp3		= V_value_S		< S_comp3             >;

/***********************************************************************************************************************/

	int main(int argc, char *argv[])
	{
		print(comp1(5));	// prints: 49
		comp2(7);		// prints: 49
		print(comp3(11));	// prints: 15

//		print_number(39275);

		return 0;
	}

