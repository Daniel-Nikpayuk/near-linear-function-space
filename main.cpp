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

	using namespace list_operators;

/***********************************************************************************************************************/

	// in type:

/*
		struct recursive_in_type
		{
			template<bool, auto Value, auto pos, auto, auto InType, auto... InTypes>
			using in_type_cont = T_hold
			<
				!bool(pos),

				T_type_U, InType,
				S_in_type, 
			>;

			template<auto Value, auto pos = 0>
			using result = T_if_then_else
			<
				!bool(pos), in_type_true, in_type_false

			>::template hold
			<
				pattern_match_function<Value>::template induct, in_type_cont, Value, pos
			>
		};

		template<auto Value, auto pos = 0>
		using S_in_type = T_hold
		<
			V_is_nullary<Value>,

			void,

			recursive_in_type::template result, Value, pos
		>;
*/

/***********************************************************************************************************************/

//	template<typename... Types> using type_list			= S_value_V<types_map<Types...>>; // wrong!

/***********************************************************************************************************************/

		constexpr void _id_()			{ }
		constexpr void char_ptr(char*)		{ }
		constexpr char c73()			{ return 73; }
		constexpr int int_sq(int x)		{ return x*x; }

/***********************************************************************************************************************/

	int main(int argc, char *argv[])
	{
		printf("%s\n", V_equal_TxT<T_type_U<U_type_T<void>>, char&> ? "true" : "false");
		printf("%s\n", V_equal_TxT<T_type_U<U_type_T<void>>, void> ? "true" : "false");
		printf("%s\n", V_equal_TxT<T_type_U<U_type_T<char>>, void> ? "true" : "false");
		printf("%s\n", V_equal_TxT<T_type_U<U_type_T<void>>, char> ? "true" : "false");
		printf("%s\n", V_equal_TxT<T_type_U<U_type_T<hold_true>>, hold_true> ? "true" : "false");

	//	printf("%s\n", V_is_function<5> ? "true" : "false");
	//	printf("%s\n", V_is_function<c73> ? "true" : "false");

	//	printf("%s\n", V_is_nullary<c73> ? "true" : "false");
	//	printf("%s\n", V_is_nullary<int_sq> ? "true" : "false");

	//	printf("%s\n", V_is_unary<c73> ? "true" : "false");
	//	printf("%s\n", V_is_unary<int_sq> ? "true" : "false");

	//	printf("%s\n", V_equal_TxT<f_out_type<_id_>, void> ? "true" : "false");
	//	printf("%s\n", V_equal_TxT<f_out_type<c73>, void> ? "true" : "false");
	//	printf("%s\n", V_equal_TxT<f_out_type<int_sq>, int> ? "true" : "false");

		return 0;
	}

