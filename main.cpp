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
																
	// Standard version:

//		template<typename Type> Type square(Type x) { return x*x; }

/***********************************************************************************************************************/

	template<auto f, typename Struct, typename Type>
	constexpr Struct set(Type value)
	{
		Struct arg;
		f(arg) = value;

		return arg;
	}

/***********************************************************************************************************************/

	template<typename CarType, typename CdrType>
	struct pair_signature
	{
		CarType car;
		CdrType cdr;

		pair_signature() { }
	};

	//

	template<typename Pair>
	constexpr auto & pair_car(Pair & arg)		{ return arg.car; }

	template<typename Pair>
	constexpr auto & pair_cdr(Pair & arg)		{ return arg.cdr; }

	//

	template<typename Pair, auto Car, auto Cdr>
	struct pair_specification
	{
		using sign_type				= Pair;

		static constexpr auto sign_return	= Car;
		static constexpr auto sign_facade	= set<Cdr, Pair, T_reference_type_T<f_out_type<Cdr>>>;

		static constexpr auto car		= Car;
		static constexpr auto cdr		= Cdr;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// Function as Text version:

		template<typename Spec>
		struct car__cdr
		{
			using return_type			= typename Spec::sign_type &;
			using arg_type				= typename Spec::sign_type &;

			static constexpr auto lval		= Spec::car;
			static constexpr auto rval		= Spec::cdr;

			static constexpr auto return_cons	= id<return_type>;
		};

		template<typename Spec>
		struct car__car_x_cdr
		{
			using return_type			= typename Spec::sign_type &;
			using arg_type				= typename Spec::sign_type &;

			static constexpr auto lval		= Spec::car;
			static constexpr auto car_rval		= Spec::car;
			static constexpr auto cdr_rval		= Spec::cdr;

			static constexpr auto return_cons	= id<return_type>;
		};

		template<typename Spec>
		constexpr auto sign_square = V_do_compose_opt
		<
			sign_assign	< car__cdr       <Spec> >,
			sign_multiply	< car__car_x_cdr <Spec> >
		>;

		template<typename Type>
		Type square(Type x)
		{
			using pair		= pair_signature	< Type, Type                           >;
			using spec		= pair_specification	< pair, pair_car<pair>, pair_cdr<pair> >;

			sign_type<spec> s	= sign_facade<spec>(x);

			return sign_return<spec>(sign_square<spec>(s));
		}

/***********************************************************************************************************************/

	int main(int argc, char *argv[])
	{
		printf("%d\n", square(5));	// prints: 25

		return 0;
	}

/***********************************************************************************************************************/

//		print(comp1(5));	// prints: 49
//		comp2(7);		// prints: 49
//		print(comp3(11));	// prints: 15

//		print_number(39275);

