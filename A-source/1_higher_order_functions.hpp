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

// higher order functions:

/***********************************************************************************************************************/

namespace nlfs_1
{
	using namespace nlfs_0;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// baseline functions:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// (compile-time) generic:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

	template<auto f> constexpr bool V_out_type_is_void		= V_equal_TxT<f_out_type<f>, void>;
	template<auto f, auto = _na_> using S_out_type_is_void		= S_equal_TxT<f_out_type<f>, void>;
	template<auto f, auto  > using S_left_out_type_is_void		= S_out_type_is_void<f>;
	template<auto  , auto g> using S_right_out_type_is_void		= S_out_type_is_void<g>;

	//

	template<auto f> constexpr bool V_out_type_not_void		= ! V_equal_TxT<f_out_type<f>, void>;
	template<auto f, auto = _na_> using S_out_type_not_void		= S_boolean<V_out_type_not_void<f>>;
	template<auto f, auto  > using S_left_out_type_not_void		= S_out_type_not_void<f>;
	template<auto  , auto g> using S_right_out_type_not_void	= S_out_type_not_void<g>;

/***********************************************************************************************************************/

	template<auto f, auto = _na_> using S_in_type_is_void		= S_boolean<V_is_nullary_function<f>>;
	template<auto f, auto  > using S_left_in_type_is_void		= S_in_type_is_void<f>;
	template<auto  , auto g> using S_right_in_type_is_void		= S_in_type_is_void<g>;

/***********************************************************************************************************************/

	template<auto f> constexpr bool V_is_nfu	= V_out_type_is_void<f>   &&  V_is_unary_function<f>;
	template<auto f> constexpr bool V_is_ufu	= V_out_type_not_void<f>  &&  V_is_unary_function<f>;
	template<auto f> constexpr bool V_is_ufs	= V_out_type_not_void<f>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// (run-time) primitives:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

	template<typename T1, typename T2> constexpr bool equal(T1 a1, T2 a2)			{ return (a1 == a2); }
	template<typename T1, typename T2> constexpr bool not_equal(T1 a1, T2 a2)		{ return (a1 != a2); }
	template<typename T1, typename T2> constexpr bool less_than(T1 a1, T2 a2)		{ return (a1 < a2); }
	template<typename T1, typename T2> constexpr bool less_than_or_equal(T1 a1, T2 a2)	{ return (a1 <= a2); }
	template<typename T1, typename T2> constexpr bool greater_than(T1 a1, T2 a2)		{ return (a1 > a2); }
	template<typename T1, typename T2> constexpr bool greater_than_or_equal(T1 a1, T2 a2)	{ return (a1 >= a2); }

	template<typename T, T Val> constexpr bool is_value(T a)				{ return (a == Val); }
	template<typename T, T Val> constexpr bool not_value(T a)				{ return (a != Val); }
	template<typename T, T Val> constexpr bool is_less_than(T a)				{ return (a < Val); }
	template<typename T, T Val> constexpr bool is_less_than_or_equal(T a)			{ return (a <= Val); }
	template<typename T, T Val> constexpr bool is_greater_than(T a)				{ return (a > Val); }
	template<typename T, T Val> constexpr bool is_greater_than_or_equal(T a)		{ return (a >= Val); }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// constants:

/***********************************************************************************************************************/

	template<typename T, T Val> constexpr T constant()					{ return Val; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// arithmetic operators:

/***********************************************************************************************************************/

	template<typename T0, typename T1, typename T2> constexpr T0 add(T1 a1, T2 a2)		{ return a1 + a2; }
	template<typename T0, typename T1, typename T2> constexpr T0 subtract(T1 a1, T2 a2)	{ return a1 - a2; }
	template<typename T0, typename T1, typename T2> constexpr T0 multiply(T1 a1, T2 a2)	{ return a1 * a2; }
	template<typename T0, typename T1, typename T2> constexpr T0 divide(T1 a1, T2 a2)	{ return a1 / a2; }
	template<typename T0, typename T1, typename T2> constexpr T0 modulo(T1 a1, T2 a2)	{ return a1 % a2; }

	template<typename T, T Val> constexpr T add_by(T a)					{ return a + Val; }
	template<typename T, T Val> constexpr T subtract_by(T a)				{ return a - Val; }
	template<typename T, T Val> constexpr T multiply_by(T a)				{ return a * Val; }
	template<typename T, T Val> constexpr T divide_by(T a)					{ return a / Val; }
	template<typename T, T Val> constexpr T modulo_by(T a)					{ return a % Val; }

	template<typename T, T Val> constexpr void add_assign_by(T a)				{ a += Val; }
	template<typename T, T Val> constexpr void subtract_assign_by(T a)			{ a -= Val; }
	template<typename T, T Val> constexpr void multiply_assign_by(T a)			{ a *= Val; }
	template<typename T, T Val> constexpr void divide_assign_by(T a)			{ a /= Val; }
	template<typename T, T Val> constexpr void modulo_assign_by(T a)			{ a %= Val; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// comparative operators:

/***********************************************************************************************************************/

	template<typename T0, typename T1, typename T2> constexpr T0 max(T1 a1, T2 a2)	{ return a1 > a2 ? a1 : a2; }
	template<typename T0, typename T1, typename T2> constexpr T0 min(T1 a1, T2 a2)	{ return a1 < a2 ? a1 : a2; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// mutators:

/***********************************************************************************************************************/

	template<typename T1, typename T2> constexpr void assign(T1 a1, T2 a2)			{ a1 = a2; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// unary:

/***********************************************************************************************************************/

// keywords:

	constexpr void _id_()							{ }	// (identity)

	//

	template<auto = _na_, auto = _na_> using return_id_keyword		= S_value_V<_id_>;

/***********************************************************************************************************************/

	template<auto f> constexpr bool V_is_id_keyword				= V_equal_VxV<f, _id_>;
	template<auto f, auto = _na_> using S_is_id_keyword			= S_equal_VxV<f, _id_>;

	template<auto f, auto  > using S_left_is_id_keyword			= S_is_id_keyword<f>;
	template<auto  , auto g> using S_right_is_id_keyword			= S_is_id_keyword<g>;
	template<auto f, auto g> using S_both_are_id_keyword			= S_boolean_and
	<
		V_is_id_keyword<f>, V_is_id_keyword<g>
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// kernel:

/***********************************************************************************************************************/

	template<typename Type>
	constexpr Type id(Type arg)						{ return arg; }

	template<auto f>
	constexpr auto V_id_cast_V						= id<f_in_type<f>>;

	//

	template<auto Type, auto = _na_> using return_id			= S_value_V<id<T_type_U<Type>>>;

/***********************************************************************************************************************/

	template<auto f, auto = _na_> using S_equals_id				= S_equal_VxV<f, V_id_cast_V<f>>;

		// Assumes f is a function
		// Assumes the out_type of f is not void
		// Assumes the in_type of f is unary

	template<auto f, auto = _na_>
	using S_is_id_func = T_colist_Bs
	<
		f, _na_,			f, _na_,

		S_not_a_function,		return_false,
		S_out_type_is_void,		return_false,
		S_not_unary_function,		return_false,
		otherwise,			S_equals_id
	>;

	template<auto f, auto = _na_> constexpr bool V_is_id_func		= V_value_S<S_is_id_func<f>>;

	template<auto f, auto  > using S_left_is_id_func			= S_is_id_func<f>;
	template<auto  , auto g> using S_right_is_id_func			= S_is_id_func<g>;
	template<auto f, auto g> using S_both_are_id_func			= S_boolean_and
	<
		V_is_id_func<f>, V_is_id_func<g>
	>;

/***********************************************************************************************************************/

	template<auto f, auto = _na_> using S_is_id_keyword_or_func		= S_boolean_or
	<
		V_is_id_keyword<f>, V_is_id_func<f>
	>;

	template<auto f, auto = _na_> constexpr bool V_is_id_keyword_or_func	= V_value_S<S_is_id_keyword_or_func<f>>;

	template<auto f, auto  > using S_left_is_id_keyword_or_func		= S_is_id_keyword_or_func<f>;
	template<auto  , auto g> using S_right_is_id_keyword_or_func		= S_is_id_keyword_or_func<g>;
	template<auto f, auto g> using S_both_are_id_keyword_or_func		= S_boolean_and
	<
		V_is_id_keyword_or_func<f>, V_is_id_keyword_or_func<g>
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// binary:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

	// _car_ , _cdr_

	// Not applicable : In the general case, type inference will
	//                  fail for whichever argument isn't used.

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// kernel:

/***********************************************************************************************************************/

	template<typename Type1, typename Type2>
	constexpr Type1 car(Type1 arg1, Type2 arg2)				{ return arg1; }

	template<auto f>
	constexpr auto V_car_cast_V						= car<f_in_type<f, 0>, f_in_type<f, 1>>;

	//

	template<typename Type1, typename Type2>
	constexpr Type2 cdr(Type1 arg1, Type2 arg2)				{ return arg2; }

	template<auto f>
	constexpr auto V_cdr_cast_V						= cdr<f_in_type<f, 0>, f_in_type<f, 1>>;

	//

	template<auto Type, auto = _na_> using return_car			= S_value_V<car<T_type_U<Type>>>;
	template<auto Type, auto = _na_> using return_cdr			= S_value_V<cdr<T_type_U<Type>>>;

/***********************************************************************************************************************/

	template<auto f, auto = _na_> using S_equals_car			= S_equal_VxV<f, V_car_cast_V<f>>;

		// Assumes f is a function
		// Assumes the out_type of f is not void
		// Assumes the in_type of f is binary

	template<auto f, auto = _na_>
	using S_is_car_func = T_colist_Bs
	<
		f, _na_,			f, _na_,

		S_not_a_function,		return_false,
		S_out_type_is_void,		return_false,
		S_not_binary_function,		return_false,
		otherwise,			S_equals_car
	>;

	template<auto f> constexpr bool V_is_car_func				= V_value_S<S_is_car_func<f>>;

	template<auto f, auto  > using S_left_is_car_func			= S_is_car_func<f>;
	template<auto  , auto g> using S_right_is_car_func			= S_is_car_func<g>;
	template<auto f, auto g> using S_both_are_car_func			= S_boolean_and
	<
		V_is_car_func<f>, V_is_car_func<g>
	>;

/***********************************************************************************************************************/

	template<auto f, auto = _na_> using S_equals_cdr			= S_equal_VxV<f, V_cdr_cast_V<f>>;

		// Assumes f is a function
		// Assumes the out_type of f is not void
		// Assumes the in_type of f is binary

	template<auto f, auto = _na_>
	using S_is_cdr_func = T_colist_Bs
	<
		f, _na_,			f, _na_,

		S_not_a_function,		return_false,
		S_out_type_is_void,		return_false,
		S_not_binary_function,		return_false,
		otherwise,			S_equals_cdr
	>;

	template<auto f> constexpr bool V_is_cdr_func				= V_value_S<S_is_cdr_func<f>>;

	template<auto f, auto  > using S_left_is_cdr_func			= S_is_cdr_func<f>;
	template<auto  , auto g> using S_right_is_cdr_func			= S_is_cdr_func<g>;
	template<auto f, auto g> using S_both_are_cdr_func			= S_boolean_and
	<
		V_is_cdr_func<f>, V_is_cdr_func<g>
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// composition:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// (binary) optimizations:

	// n,car:

		template<auto f, typename Type1, typename Type2>
		constexpr void n_compose_car(Type1 arg1, Type2 arg2) { f(arg1); }

		template<bool, auto g, auto f, typename, typename InType1, typename InType2>
		using func_n_compose_car_cont = S_value_V<n_compose_car<f, InType1, InType2>>;

		template<auto f, auto g>
		using return_n_compose_car = typename pattern_match_function<g>::template induct
		<
			func_n_compose_car_cont, f
		>;

	// n,cdr:

		template<auto f, typename Type1, typename Type2>
		constexpr void n_compose_cdr(Type1 arg1, Type2 arg2) { f(arg2); }

		template<bool, auto g, auto f, typename, typename InType1, typename InType2>
		using func_n_compose_cdr_cont = S_value_V<n_compose_cdr<f, InType1, InType2>>;

		template<auto f, auto g>
		using return_n_compose_cdr = typename pattern_match_function<g>::template induct
		<
			func_n_compose_cdr_cont, f
		>;

	// u,car:

		template<auto f, typename Type1, typename Type2>
		constexpr f_out_type<f> u_compose_car(Type1 arg1, Type2 arg2) { return f(arg1); }

		template<bool, auto g, auto f, typename, typename InType1, typename InType2>
		using func_u_compose_car_cont = S_value_V<u_compose_car<f, InType1, InType2>>;

		template<auto f, auto g>
		using return_u_compose_car = typename pattern_match_function<g>::template induct
		<
			func_u_compose_car_cont, f
		>;

	// u,cdr:

		template<auto f, typename Type1, typename Type2>
		constexpr f_out_type<f> u_compose_cdr(Type1 arg1, Type2 arg2) { return f(arg2); }

		template<bool, auto g, auto f, typename, typename InType1, typename InType2>
		using func_u_compose_cdr_cont = S_value_V<u_compose_cdr<f, InType1, InType2>>;

		template<auto f, auto g>
		using return_u_compose_cdr = typename pattern_match_function<g>::template induct
		<
			func_u_compose_cdr_cont, f
		>;

/***********************************************************************************************************************/

// assertions:

	struct left_not_a_func_assertion
	{
		template<bool Value>
		static constexpr int result()
			{ static_assert(Value, "S_compose: Left auto arg is not a function."); return 0; }
	};

	struct right_not_a_func_assertion
	{
		template<bool Value>
		static constexpr int result()
			{ static_assert(Value, "S_compose: Right auto arg is not a function."); return 0; }
	};

	struct not_valid_composition_assertion
	{
		template<bool Value>
		static constexpr int result()
			{ static_assert(Value, "S_compose: Functions do not form a valid composition."); return 0; }
	};

	template<typename Type>
	using assert_S_compose = T_hold
	<
		! V_equal_TxT<Type, left_not_a_func_assertion>		&&
		! V_equal_TxT<Type, right_not_a_func_assertion>		&&
		! V_equal_TxT<Type, not_valid_composition_assertion>	,

		void,
		force_static_assert, Type
	>;

	template<auto, auto> using return_left_not_a_func_assertion		= left_not_a_func_assertion;
	template<auto, auto> using return_right_not_a_func_assertion		= right_not_a_func_assertion;
	template<auto, auto> using return_not_valid_composition_assertion	= not_valid_composition_assertion;

/***********************************************************************************************************************/

// try:

	template<auto f, auto g>
	using try_n_compose_s_but_return_left_function = return_function
	<
		f, V_value_S<return_n_compose_s<f, g>>
	>;

	template<auto f, auto g>
	using try_u_compose_s_but_return_left_function = return_function
	<
		f, V_value_S<return_u_compose_s<f, g>>
	>;

	template<auto f, auto g>
	using try_u_compose_s_but_return_right_function = return_function
	<
		g, V_value_S<return_u_compose_s<f, g>>
	>;

/***********************************************************************************************************************/

	// potential:

	//	n func u   o  u func s  -->  n func s
	//	u func u   o  u func s  -->  u func s

	template<auto f, auto g>
	using S_not_valid_composition = S_boolean_not
	<
		(V_is_nfu<f> && V_is_ufs<g>) || (V_is_ufu<f> && V_is_ufs<g>)
	>;

/***********************************************************************************************************************/

	// optimization:

	//	   _id_    ,  _id_      -->  _id_
	//	   _id_    ,  func2     -->  func2
	//	   func1   ,  _id_      -->  func1
                              
	//	   id<T1>  ,  id<T2>    -->  id<T2>		(Warning: Can this have unintended side effects?)
	//	   id<T1>  ,  func2     -->  func2
	//	   func1   ,  id<T2>    -->  func1
                              
	//	   func1   ,  func2     -->  func1 o func2

	template<auto f, auto g>
	using return_u_compose_opt = T_colist_Bs
	<
		f, g,					f, g,

		S_left_is_id_keyword,			return_right_function,
		S_right_is_id_keyword,			return_left_function,

		S_left_is_id_func,			try_u_compose_s_but_return_right_function,
		S_right_is_id_func,			try_u_compose_s_but_return_left_function,

		S_is_car_func,				return_u_compose_car,
		S_is_cdr_func,				return_u_compose_cdr,

		otherwise,				return_u_compose_s
	>;

	template<auto f, auto g>
	using return_n_compose_opt = T_colist_Bs
	<
		f, g,					f, g,

		S_right_is_id_keyword,			return_left_function,

		S_right_is_id_func,			try_n_compose_s_but_return_left_function,

		S_is_car_func,				return_n_compose_car,
		S_is_cdr_func,				return_n_compose_cdr,

		otherwise,				return_n_compose_s
	>;

/***********************************************************************************************************************/

	template<auto f, auto g>
	using S_compose_opt = T_colist_Bs
	<
		f, g,					f, g,

		S_left_not_a_function,			return_left_not_a_func_assertion,
		S_right_not_a_function,			return_right_not_a_func_assertion,
		S_not_valid_composition,		return_not_valid_composition_assertion,

		S_left_out_type_not_void,		return_u_compose_opt,
		otherwise,				return_n_compose_opt
	>;

	template<auto f, auto g>
	constexpr auto V_compose_opt = V_value_S<S_compose_opt<f, g>>;

/***********************************************************************************************************************/

// do compose:

	template<auto f, auto g>
	using S_do_compose_opt = S_compose_opt<g, f>;

	template<auto f, auto g>
	constexpr auto V_do_compose_opt = V_value_S<S_compose_opt<g, f>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// subcomposition:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	template<typename...> struct arg_list	{ };

	template<typename, typename> struct pattern_match_subcompose;

	template
	<
		template<typename...> class ListName1, typename... FTypes1,
		template<typename...> class ListName2, typename... FTypes2
	>
	struct pattern_match_subcompose<ListName1<FTypes1...>, ListName2<FTypes2...>>
	{
		template<auto f, auto g, typename... GTypes>
		static constexpr f_out_type<f> result(FTypes1... f_args1, GTypes... g_args, FTypes2... f_args2)
		{
			return f(f_args1..., g(g_args...), f_args2...);
		}
	};

	template<auto f, auto g>
	constexpr auto V_subcompose_opt = pattern_match_subcompose
	<
		arg_list1, arg_list2, arg_list3

	>::template result<f, g>;
*/

/***********************************************************************************************************************/

	//	_car_   , func1 , func2  -->  func1
	//	_cdr_   , func1 , func2  -->  func2

	//	car<T1> , func1 , func2  -->  func1
	//	cdr<T1> , func1 , func2  -->  func2

	//	func0   , func1 , func2  -->  func0 ( func1 , func2 )

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

