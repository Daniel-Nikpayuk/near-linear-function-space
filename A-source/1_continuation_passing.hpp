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

// continuation passing paradigm:

/*
	ch - continuation halting
	cp - continuation passing

	opt - optimizes against id keyword or cast,
	    - returns _id_ when id<Type> cannot be inferred.
*/

// run time (compatible) stem lattice:

/*
	pf - policy_f		p1f  - policy1_f	p2f  - policy2_f
	bf - break_f		b1f  - break1_f		b2f  - break2_f
	nf - next_f		n1f  - next1_f		n2f  - next2_f
				n11f - next11_f		n2f - next2_f
				n12f - next12_f
	cf - cont_f
*/

/***********************************************************************************************************************/

namespace ocli_1
{
	using namespace ocli_0;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// baseline functions:

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// generic:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// predicates:

/***********************************************************************************************************************/

	template<auto f, auto = _na_> using S_is_a_function			= S_boolean<V_is_function_V<f>>;
	template<auto f, auto = _na_> using S_not_a_function			= S_boolean<!V_is_function_V<f>>;

	template<auto f, auto  > using S_left_is_a_function			= S_is_a_function<f>;
	template<auto  , auto g> using S_right_is_a_function			= S_is_a_function<g>;

	template<auto f, auto  > using S_left_not_a_function			= S_not_a_function<f>;
	template<auto  , auto g> using S_right_not_a_function			= S_not_a_function<g>;

	//

	template<auto f, auto = _na_> using S_out_type_equals_void		= S_equal_TxT<f_out_type<f>, void>;

	template<auto f, auto  > using S_left_out_type_equals_void		= S_out_type_equals_void<f>;
	template<auto  , auto g> using S_right_out_type_equals_void		= S_out_type_equals_void<g>;

	//

	template<auto f, auto = _na_> using S_in_type_equals_void		= S_boolean<V_is_nullary_V<f>>;
	template<auto f, auto = _na_> using S_is_nullary			= S_boolean<V_is_nullary_V<f>>;
	template<auto f, auto = _na_> using S_not_nullary			= S_boolean<!V_is_nullary_V<f>>;

	template<auto f, auto  > using S_left_in_type_equals_void		= S_in_type_equals_void<f>;
	template<auto  , auto g> using S_right_in_type_equals_void		= S_in_type_equals_void<g>;

	template<auto f, auto  > using S_left_is_nullary			= S_is_nullary<f>;
	template<auto  , auto g> using S_right_is_nullary			= S_is_nullary<g>;

	template<auto f, auto  > using S_left_not_nullary			= S_not_nullary<f>;
	template<auto  , auto g> using S_right_not_nullary			= S_not_nullary<g>;

	//

	template<auto f, auto = _na_> using S_is_unary				= S_boolean<V_is_unary_V<f>>;
	template<auto f, auto = _na_> using S_not_unary				= S_boolean<!V_is_unary_V<f>>;

	template<auto f, auto  > using S_left_is_unary				= S_is_unary<f>;
	template<auto  , auto g> using S_right_is_unary				= S_is_unary<g>;

	template<auto f, auto  > using S_left_not_unary				= S_not_unary<f>;
	template<auto  , auto g> using S_right_not_unary			= S_not_unary<g>;

	//

	template<auto f, auto = _na_> using S_is_binary				= S_boolean<V_is_binary_V<f>>;
	template<auto f, auto = _na_> using S_not_binary			= S_boolean<!V_is_binary_V<f>>;

	template<auto f, auto  > using S_left_is_binary				= S_is_binary<f>;
	template<auto  , auto g> using S_right_is_binary			= S_is_binary<g>;

	template<auto f, auto  > using S_left_not_binary			= S_not_binary<f>;
	template<auto  , auto g> using S_right_not_binary			= S_not_binary<g>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// return:

/***********************************************************************************************************************/

	template<auto f, auto = _na_> using return_function			= S_value_V<f>;

	template<auto f, auto> using return_left_function			= S_value_V<f>;
	template<auto, auto g> using return_right_function			= S_value_V<g>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// unary:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

/***********************************************************************************************************************/

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
		S_out_type_equals_void,		return_false,
		S_not_unary,			return_false,
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

// kernel composition:

/***********************************************************************************************************************/

	template<auto f, auto g>
	constexpr void v_compose_v()						{ f(g()); }

	template<auto f, auto g>
	constexpr void v_compose_t(f_in_type<g> arg)				{ f(g(arg)); }

	template<auto f, auto g>
	constexpr f_out_type<f> t_compose_v()					{ return f(g()); }

	template<auto f, auto g>
	constexpr f_out_type<f> t_compose_t(f_in_type<g> arg)			{ return f(g(arg)); }

/***********************************************************************************************************************/

	template<auto f, auto g> using return_v_compose_v			= S_value_V<v_compose_v<f, g>>;
	template<auto f, auto g> using return_v_compose_t			= S_value_V<v_compose_t<f, g>>;
	template<auto f, auto g> using return_t_compose_v			= S_value_V<t_compose_v<f, g>>;
	template<auto f, auto g> using return_t_compose_t			= S_value_V<t_compose_t<f, g>>;

/***********************************************************************************************************************/

	struct left_not_a_func_assertion
	{
		template<bool Value>
		static constexpr int result()
			{ static_assert(Value, "S_compose: left auto arg is not a function."); return 0; }
	};

	struct right_not_a_func_assertion
	{
		template<bool Value>
		static constexpr int result()
			{ static_assert(Value, "S_compose: right auto arg is not a function."); return 0; }
	};

	struct right_not_unary_assertion
	{
		template<bool Value>
		static constexpr int result()
			{ static_assert(Value, "S_compose: right auto arg is not a unary function."); return 0; }
	};

	template<typename Type>
	using assert_S_compose = T_hold
	<
		! V_equal_TxT<Type, left_not_a_func_assertion>	&&
		! V_equal_TxT<Type, right_not_a_func_assertion>	&&
		! V_equal_TxT<Type, right_not_unary_assertion>	,

		void, force_static_assert, Type
	>;

	template<auto, auto> using return_left_not_a_func_assertion		= left_not_a_func_assertion;
	template<auto, auto> using return_right_not_a_func_assertion		= right_not_a_func_assertion;
	template<auto, auto> using return_right_not_unary_assertion		= right_not_unary_assertion;

/***********************************************************************************************************************/

	template<auto f, auto g>
	using return_v_compose = T_colist_Bs
	<
		g, _na_,				f, g,

		S_in_type_equals_void,			return_v_compose_v,
		otherwise,				return_v_compose_t
	>;

	template<auto f, auto g>
	using return_compose_v = T_colist_Bs
	<
		g, _na_,				f, g,

		otherwise,				return_t_compose_v
	>;

	template<auto f, auto g>
	using S_compose = T_colist_Bs
	<
		f, g,					f, g,

		S_left_not_a_function,			return_left_not_a_func_assertion,
		S_right_not_a_function,			return_right_not_a_func_assertion,
		S_right_not_unary,			return_right_not_unary_assertion,

		S_left_out_type_equals_void,		return_v_compose,
		S_right_in_type_equals_void,		return_compose_v,
		otherwise,				return_t_compose_t
	>;

	template<auto f, auto g>
	constexpr auto V_compose = V_value_S<S_compose<f, g>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// optimized composition:

/***********************************************************************************************************************/

	//	_id_   , _id_    -->  _id_
	//	_id_   , func2   -->  func2
	//	func1  , _id_    -->  func1

	//	id<T1> , id<T2>  -->  id<T2>		(Warning: Can this have unintended side effects?)
	//	id<T1> , func2   -->  func2
	//	func1  , id<T2>  -->  func1

	//	func1  , func2   -->  func1 o func2

	template<auto f, auto g> using try_compose_but_return_left_function 	= return_function<f, t_compose_t<f, g>>;
	template<auto f, auto g> using try_compose_but_return_right_function 	= return_function<g, t_compose_t<f, g>>;

	template<auto f, auto g>
	using S_compose_opt = T_colist_Bs
	<
		f, g,				f, g,

		S_left_is_id_keyword,		return_right_function,
		S_right_is_id_keyword,		return_left_function,

		S_left_is_id_func,		try_compose_but_return_right_function,
		S_right_is_id_func,		try_compose_but_return_left_function,

		otherwise,			return_t_compose_t
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

// binary:

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

	constexpr void _car_()				{ }	// (left projection)
	constexpr void _cdr_()				{ }	// (right projection)

/***********************************************************************************************************************/

	template<typename Type1, typename Type2>
	constexpr Type1 car(Type1 arg1, Type2 arg2)				{ return arg1; }

	template<typename Type1, typename Type2>
	constexpr Type2 cdr(Type1 arg1, Type2 arg2)				{ return arg2; }

	template<auto f>
	constexpr auto V_car_cast_V						= car<f_car_in_type<f>, f_cdr_in_type<f>>;

	template<auto f>
	constexpr auto V_cdr_cast_V						= cdr<f_car_in_type<f>, f_cdr_in_type<f>>;

/***********************************************************************************************************************/

	template<auto f, auto g1, auto g2> constexpr f_out_type<f>
	V_curry_compose_VxVxV(f_car_in_type<g1> arg1, f_cdr_in_type<g2> arg2)	{ return f(g1(arg1), g2(arg2)); }

	template<auto f, auto g> constexpr f_out_type<f>
	V_curry_compose_left_VxV(f_car_in_type<g> arg1, f_cdr_in_type<f> arg2)	{ return f(g(arg1), arg2); }

	template<auto f, auto g> constexpr f_out_type<f>
	V_curry_compose_right_VxV(f_car_in_type<f> arg1, f_cdr_in_type<g> arg2)	{ return f(arg1, g(arg2)); }

/***********************************************************************************************************************/

	template<auto = _na_, auto = _na_> using return_car_keyword		= S_value_V<_car_>;
	template<auto Type, auto = _na_> using return_car			= S_value_V<car<T_type_U<Type>>>;

	template<auto = _na_, auto = _na_> using return_cdr_keyword		= S_value_V<_cdr_>;
	template<auto Type, auto = _na_> using return_cdr			= S_value_V<cdr<T_type_U<Type>>>;

/***********************************************************************************************************************/

// is _car_, car:

	template<auto f, auto = _na_> using S_is_car_keyword		= S_equal_VxV<f, _car_>;

	template<auto f, auto  > using S_left_is_car_keyword		= S_is_car_keyword<f>;
	template<auto  , auto g> using S_right_is_car_keyword		= S_is_car_keyword<g>;
	template<auto f, auto g> using S_both_are_car_keyword		= S_boolean
									<
										V_value_S<S_is_car_keyword<f>> &&
									  	V_value_S<S_is_car_keyword<g>>
									>;

	//

	template<auto f, auto = _na_> using S_equals_car		= S_equal_VxV<f, V_car_cast_V<f>>;

		// Assumes f is a function
		// Assumes the out_type of f is not void
		// Assumes the in_type of f is binary

	template<auto f, auto = _na_>
	using S_is_car_func = T_colist_Bs
	<
		f, _na_,			f, _na_,

		S_not_a_function,		return_false,
		S_out_type_equals_void,		return_false,
		S_not_binary,			return_false,
		otherwise,			S_equals_car
	>;

	template<auto f, auto  > using S_left_is_car_func		= S_is_car_func<f>;
	template<auto  , auto g> using S_right_is_car_func		= S_is_car_func<g>;
	template<auto f, auto g> using S_both_are_car_func		= S_boolean
									<
										V_value_S<S_is_car_func<f>> &&
										V_value_S<S_is_car_func<g>>
									>;

	//

	template<auto f, auto = _na_> using S_is_car_keyword_or_func	= S_boolean
									<
										V_value_S<S_is_car_keyword<f>> ||
										V_value_S<S_is_car_func<f>>
									>;

	template<auto f, auto  > using S_left_is_car_keyword_or_func	= S_is_car_keyword_or_func<f>;
	template<auto  , auto g> using S_right_is_car_keyword_or_func	= S_is_car_keyword_or_func<g>;
	template<auto f, auto g> using S_both_are_car_keyword_or_func	= S_boolean
									<
										V_value_S<S_is_car_keyword_or_func<f>> &&
										V_value_S<S_is_car_keyword_or_func<g>>
									>;

/***********************************************************************************************************************/

// is _cdr_, cdr:

	template<auto f, auto = _na_> using S_is_cdr_keyword		= S_equal_VxV<f, _cdr_>;

	template<auto f, auto  > using S_left_is_cdr_keyword		= S_is_cdr_keyword<f>;
	template<auto  , auto g> using S_right_is_cdr_keyword		= S_is_cdr_keyword<g>;
	template<auto f, auto g> using S_both_are_cdr_keyword		= S_boolean
									<
										V_value_S<S_is_cdr_keyword<f>> &&
									  	V_value_S<S_is_cdr_keyword<g>>
									>;

	//

	template<auto f, auto = _na_> using S_equals_cdr		= S_equal_VxV<f, V_cdr_cast_V<f>>;

		// Assumes f is a function
		// Assumes the out_type of f is not void
		// Assumes the in_type of f is binary

	template<auto f, auto = _na_>
	using S_is_cdr_func = T_colist_Bs
	<
		f, _na_,			f, _na_,

		S_not_a_function,		return_false,
		S_out_type_equals_void,		return_false,
		S_not_binary,			return_false,
		otherwise,			S_equals_cdr
	>;

	template<auto f, auto  > using S_left_is_cdr_func		= S_is_cdr_func<f>;
	template<auto  , auto g> using S_right_is_cdr_func		= S_is_cdr_func<g>;
	template<auto f, auto g> using S_both_are_cdr_func		= S_boolean
									<
										V_value_S<S_is_cdr_func<f>> &&
										V_value_S<S_is_cdr_func<g>>
									>;

	//

	template<auto f, auto = _na_> using S_is_cdr_keyword_or_func	= S_boolean
									<
										V_value_S<S_is_cdr_keyword<f>> ||
										V_value_S<S_is_cdr_func<f>>
									>;

	template<auto f, auto  > using S_left_is_cdr_keyword_or_func	= S_is_cdr_keyword_or_func<f>;
	template<auto  , auto g> using S_right_is_cdr_keyword_or_func	= S_is_cdr_keyword_or_func<g>;
	template<auto f, auto g> using S_both_are_cdr_keyword_or_func	= S_boolean
									<
										V_value_S<S_is_cdr_keyword_or_func<f>> &&
										V_value_S<S_is_cdr_keyword_or_func<g>>
									>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// (keyword inert) composition:

/***********************************************************************************************************************/

// curry compose (_car_, _cdr_):

	//	_car_   , func1 , func2  -->  func1
	//	_cdr_   , func1 , func2  -->  func2

	//	car<T1> , func1 , func2  -->  func1
	//	cdr<T1> , func1 , func2  -->  func2

	//	func0   , func1 , func2  -->  func0 ( func1 , func2 )

	template<auto f>
	struct dispatch_curry_composition_opt
	{
		template<auto g1, auto g2> using return_binary_function		= S_value_V<f>;
		template<auto g1, auto g2> using return_curry_compose_left	= S_value_V<V_curry_compose_left_VxV<f, g1>>;
		template<auto g1, auto g2> using return_curry_compose_right	= S_value_V<V_curry_compose_right_VxV<f, g2>>;
		template<auto g1, auto g2> using return_curry_compose		= S_value_V<V_curry_compose_VxVxV<f, g1, g2>>;

		template<auto g1, auto g2>
		using result = T_colist_Bs
		<
			g1, g2,					g1, g2,

			S_both_are_id_keyword_or_func,		return_binary_function,
			S_left_is_id_keyword_or_func,		return_curry_compose_right,
			S_right_is_id_keyword_or_func,		return_curry_compose_left,
			otherwise,				return_curry_compose
		>;
	};

	template<auto f>
	struct try_curry_but_dispatch_left_function
	{
		template<auto g1, auto g2>
		using result = return_function<g1, V_curry_compose_VxVxV<f, g1, g2>>;
	};

	template<auto f>
	struct try_curry_but_dispatch_right_function
	{
		template<auto g1, auto g2>
		using result = return_function<g2, V_curry_compose_VxVxV<f, g1, g2>>;
	};

	template<auto f, auto g1, auto g2>
	using S_curry_compose_opt = T_colist_Bs
	<
		f, _na_,			g1, g2,

		S_is_car_keyword,		return_left_function,
		S_is_cdr_keyword,		return_right_function,

		S_is_car_func,			try_curry_but_dispatch_left_function<f>::template result,
		S_is_cdr_func,			try_curry_but_dispatch_right_function<f>::template result,

		otherwise,			dispatch_curry_composition_opt<f>::template result
	>;

	template<auto f, auto g1, auto g2>
	constexpr auto V_curry_compose_opt = V_value_S<S_curry_compose_opt<f, g1, g2>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// continuation passing constructors:

/***********************************************************************************************************************/

// lift:

		// returns a proper identity function rather than the _id_ keyword.

	template<auto f>
	struct cp_lift
	{
		template<auto composed_f, auto Type>
		using let_result = T_colist_Bs
		<
			composed_f, _na_,		Type, composed_f,

			S_is_id_keyword,		return_id,
			otherwise,			return_right_function
		>;

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_value_S
		<
			let_result
			<
				V_compose_opt<cont_f, f>,
				U_type_T<Type>
			>
		>;
	};

	//

	template<bool predicate, auto function1, auto function2 = _id_>
	using cp_if_then_else = cp_lift<V_if_then_else<predicate, function1, function2>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// stem:

/***********************************************************************************************************************/

	template<auto policy_f, auto break_f, auto next_f>
	struct cp_stem
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return break_f(arg);
			else			return next_f(arg);
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return break_f(arg);
			else			return cont_f(next_f(arg));
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

	template<auto policy_f, auto break_f>
	struct cp_stem<policy_f, break_f, _id_>
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return break_f(arg);
			else			return arg;
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return break_f(arg);
			else			return cont_f(arg);
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

	template<auto policy_f, auto next_f>
	struct cp_stem<policy_f, _id_, next_f>
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return arg;
			else			return next_f(arg);
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return arg;
			else			return cont_f(next_f(arg));
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

//*** Assumes policy_f has no side effects:

	template<auto policy_f>
	struct cp_stem<policy_f, _id_, _id_>
	{
	// halting:

		template<auto, auto U>
		using return_halting = S_value_V<id<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return arg;
			else			return cont_f(arg);
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// costem:

/***********************************************************************************************************************/

	template<auto policy_f, auto next_f, auto break_f>
	struct cp_costem
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return next_f(arg);
			else			return break_f(arg);
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return cont_f(next_f(arg));
			else			return break_f(arg);
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

	template<auto policy_f, auto next_f>
	struct cp_costem<policy_f, next_f, _id_>
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return next_f(arg);
			else			return arg;
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return cont_f(next_f(arg));
			else			return arg;
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

	template<auto policy_f, auto break_f>
	struct cp_costem<policy_f, _id_, break_f>
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return arg;
			else			return break_f(arg);
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return cont_f(arg);
			else			return break_f(arg);
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

//*** Assumes policy_f has no side effects:

	template<auto policy_f>
	struct cp_costem<policy_f, _id_, _id_>
	{
	// halting:

		template<auto, auto U>
		using return_halting = S_value_V<id<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return cont_f(arg);
			else			return arg;
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// distem:

/***********************************************************************************************************************/

	template<auto policy_f, auto next1_f, auto next2_f>
	struct cp_distem
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return next1_f(arg);
			else			return next2_f(arg);
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return cont_f(next1_f(arg));
			else			return cont_f(next2_f(arg));
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

	template<auto policy_f, auto next1_f>
	struct cp_distem<policy_f, next1_f, _id_>
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return next1_f(arg);
			else			return arg;
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return cont_f(next1_f(arg));
			else			return cont_f(arg);
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

	template<auto policy_f, auto next2_f>
	struct cp_distem<policy_f, _id_, next2_f>
	{
	// halting:

		template<typename Type>
		static constexpr Type halting(Type arg)
		{
			if (policy_f(arg))	return arg;
			else			return next2_f(arg);
		}

		template<auto, auto U>
		using return_halting = S_value_V<halting<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			if (policy_f(arg))	return cont_f(arg);
			else			return cont_f(next2_f(arg));
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

//*** Assumes policy_f has no side effects:

	template<auto policy_f>
	struct cp_distem<policy_f, _id_, _id_>
	{
	// halting:

		template<auto, auto U>
		using return_halting = S_value_V<id<T_type_U<U>>>;

	// passing:

		template<auto cont_f, typename Type>
		static constexpr Type passing(Type arg)
		{
			return cont_f(arg);
		}

		template<auto cont_f, auto U>
		using return_passing = S_value_V<passing<cont_f, T_type_U<U>>>;

	// result:

		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = V_colist_Bs
		<
			cont_f, _na_,			cont_f, U_type_T<Type>,

			S_is_id_keyword_or_func,	return_halting,
			otherwise,			return_passing
		>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

