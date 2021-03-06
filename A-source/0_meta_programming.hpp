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

// template metaprogramming:

/*
	S   - value_pair				(typename)
	T   - type					(typename)
	U   - type_map					(constexpr auto)
	V   - value					(constexpr auto)

	G   - template<typename> class
	F   - template<auto> class

	E   - template<typename, typename> class
	D   - template<typename, auto> class
	C   - template<auto, typename> class
	B   - template<auto, auto> class


	opt - optimizer

	n   - nullary
	u   - unary
	b   - binary
	s   - variadic
*/

/***********************************************************************************************************************/

namespace nlfs_0
{

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

	constexpr void _na_()				{ }	// (not applicable auto)
	struct _NA_					{ };	// (not applicable typename)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// typename category:

/***********************************************************************************************************************/

	template<auto Value1, auto Value2>
	struct value_pair
	{
		static constexpr bool match		= false;

		static constexpr auto car_value		= Value1;
		static constexpr auto cdr_value		= Value2;
	};

	template<auto Value>
	struct value_pair<Value, Value>
	{
		static constexpr bool match		= true;

		static constexpr auto value		= Value;
	};

	//

	template<auto Value>
	using S_value_V = value_pair<Value, Value>;

	template<typename ValuePair>
	constexpr auto V_value_S = ValuePair::value;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// debugging:

/***********************************************************************************************************************/

	template<typename Type> using force_static_assert	= S_value_V<Type::template result<false>()>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// boolean type:

/***********************************************************************************************************************/

	using S_false								= S_value_V<false>;
	using S_true								= S_value_V<true>;

	template<bool Predicate, auto = _na_> using S_boolean			= S_value_V<Predicate>;

	template<bool Value, auto = _na_> using S_boolean_not			= S_value_V<!Value>;
	template<bool Value1, bool Value2> using S_boolean_and			= S_value_V<Value1 && Value2>;
	template<bool Value1, bool Value2> using S_boolean_or			= S_value_V<Value1 || Value2>;

	template<bool Value, auto = _na_> constexpr bool V_boolean_not		= ! Value;
	template<bool Value1, bool Value2> constexpr bool V_boolean_and		= Value1 && Value2;
	template<bool Value1, bool Value2> constexpr bool V_boolean_or		= Value1 || Value2;

/***********************************************************************************************************************/

// true:

	template<bool True, auto = _na_>
	struct pattern_match_bool
	{
		// value:

			template<auto Antecedent, auto Consequent>
			static constexpr auto V_then_else_VxV = Antecedent;

		// type:

			template<typename Antecedent, typename Consequent>
			using T_then_else_TxT = Antecedent;
	};

/***********************************************************************************************************************/

// false:

	template<auto NA>
	struct pattern_match_bool<false, NA>
	{
		// value:

			template<auto Antecedent, auto Consequent>
			static constexpr auto V_then_else_VxV = Consequent;

		// type:

			template<typename Antecedent, typename Consequent>
			using T_then_else_TxT = Consequent;
	};

/***********************************************************************************************************************/

// if then else:

	// value:

		template<bool Predicate, auto Antecedent, auto Consequent>
		constexpr auto V_if_then_else = pattern_match_bool<Predicate>::template
			V_then_else_VxV<Antecedent, Consequent>;

	// type:

		template<bool Predicate, typename Antecedent, typename Consequent>
		using T_if_then_else = typename pattern_match_bool<Predicate>::template
			T_then_else_TxT<Antecedent, Consequent>;

/***********************************************************************************************************************/

// hold:

	struct hold_ante
	{
		// value:

		// type:

			template<typename Antecedent, template<typename> class Function, typename Consequent>
			using T_hold_TxGxT = Antecedent;
	};

	struct hold_conse
	{
		// value:

		// type:

			template<typename Antecedent, template<typename> class Function, typename Consequent>
			using T_hold_TxGxT = Function<Consequent>;
	};

	// value:

	// type:

		template<bool Predicate, typename Antecedent, template<typename> class Function, typename Consequent>
		using T_hold = typename T_if_then_else
		<
			Predicate,

				hold_ante, hold_conse

		>::template T_hold_TxGxT
		<
			Antecedent, Function, Consequent
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// colist type:

/***********************************************************************************************************************/

// empty:

	template<template<auto, auto> class... Aliases> constexpr bool V_empty_Bs = ! bool(sizeof...(Aliases));

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	struct template_list_colist
	{
		struct colist_halt
		{
			template
			<
				typename Colist,
			// halt:
				typename Default1,
			// cont:
				auto Value11, auto Value12,		auto Value21, auto Value22,	typename Default2,

				template<auto, auto> class... Aliases
			>
			using result = Default1;
		};

		struct colist_cont
		{
			struct dihold_halt
			{
				template
				<
					typename Colist,
				// halt:
					template<auto, auto> class Break, auto Value11, auto Value12,
				// cont:
					auto Value21, auto Value22,		auto Value31, auto Value32,	typename Default,

					template<auto, auto> class... Aliases
				>
				using result = Break<Value11, Value12>;
			};

			struct dihold_cont
			{
				template
				<
					typename Colist,
				// halt:
					template<auto, auto> class Break, auto Value11, auto Value12,
				// cont:
					auto Value21, auto Value22,		auto Value31, auto Value32,	typename Default,

					template<auto, auto> class... Aliases
				>
				using result = typename Colist::template result
				<
					Value21, Value22,	Value31, Value32,	Default,

					Aliases...
				>;
			};

			template
			<
				typename Colist,
			// halt:
				typename Default1,
			// cont:
				auto Value11, auto Value12,		auto Value21, auto Value22,	typename Default2,

				template<auto, auto> class Policy,	template<auto, auto> class Break,

				template<auto, auto> class... Aliases
			>
			using result = typename T_if_then_else
			<
				V_value_S<Policy<Value11, Value12>>,

					dihold_halt, dihold_cont

			>::template result
			<
				Colist,
			// halt:
				Break, Value21, Value22,
			// cont:
				Value11, Value12,	Value21, Value22,	Default2,

				Aliases...
			>;
		};

		template
		<
			auto Value11, auto Value12,		auto Value21, auto Value22,	typename Default,

			template<auto, auto> class... Aliases
		>
		using result = typename T_if_then_else
		<
			V_empty_Bs<Aliases...>,

				colist_halt, colist_cont

		>::template result
		<
			template_list_colist,
		// halt:
			Default,
		// cont:
			Value11, Value12,	Value21, Value22,	Default,

			Aliases...
		>;
	};

/***********************************************************************************************************************/

// type:

	template
	<
		auto Value11, auto Value12,
		auto Value21, auto Value22,
		template<auto, auto> class... Aliases
	>
	using T_colist_Bs = typename template_list_colist::template result
	<
		Value11, Value12, Value21, Value22, _NA_, Aliases...
	>;

/***********************************************************************************************************************/

// value:

	template
	<
		auto Value11, auto Value12,
		auto Value21, auto Value22,
		template<auto, auto> class... Aliases
	>
	constexpr auto V_colist_Bs = V_value_S
	<
		typename template_list_colist::template result
		<
			Value11, Value12, Value21, Value22, _NA_, Aliases...
		>
	>;

/***********************************************************************************************************************/

	template<auto, auto> using otherwise		= S_true;
	template<auto, auto> using return_false		= S_false;
	template<auto, auto> using return_true		= S_true;

	template<auto, auto> using return_void		= void;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// function type:

/***********************************************************************************************************************/

	template<auto, auto = _na_>
	struct pattern_match_function
	{
		template
		<
			template
			<
				bool, auto, auto, typename, typename...

			> class Continuation
		>
		using induct = Continuation<false, _na_, _na_, _NA_>;
	};

	template<typename OutType, typename... InTypes, OutType(*f)(InTypes...), auto NA>
	struct pattern_match_function<f, NA>
	{
		template
		<
			template
			<
				bool, auto, auto, typename, typename...

			> class Continuation, auto count, typename... Args
		>
		using induct = Continuation<true, f, count, Args..., OutType, InTypes...>;
	};

	//

	template<auto f, auto = _na_> using return_function			= S_value_V<f>;

	template<auto f, auto> using return_left_function			= S_value_V<f>;
	template<auto, auto g> using return_right_function			= S_value_V<g>;

/***********************************************************************************************************************/

// match:

	template<bool Match, auto, auto, typename, typename...>
	using func_is_match_cont = S_value_V<Match>;

	template<auto f, auto = _na_>
	using S_is_a_function = typename pattern_match_function<f>::template induct
	<
		func_is_match_cont, _na_
	>;

	template<auto f, auto  > using S_left_is_a_function			= S_is_a_function<f>;
	template<auto  , auto g> using S_right_is_a_function			= S_is_a_function<g>;

	template<auto f> constexpr bool V_is_a_function				= V_value_S<S_is_a_function<f>>;

/***********************************************************************************************************************/

// not match:

	template<bool Match, auto, auto, typename, typename...>
	using func_not_match_cont = S_value_V<!Match>;

	template<auto f, auto = _na_>
	using S_not_a_function = typename pattern_match_function<f>::template induct
	<
		func_not_match_cont, _na_
	>;

	template<auto f, auto  > using S_left_not_a_function			= S_not_a_function<f>;
	template<auto  , auto g> using S_right_not_a_function			= S_not_a_function<g>;

	template<auto f> constexpr bool V_not_a_function			= V_value_S<S_not_a_function<f>>;

/***********************************************************************************************************************/

// arity:

	template<bool, auto, auto, typename Type, typename, typename... InTypes>
	using func_arity_cont = S_value_V<Type(sizeof...(InTypes))>;

	template<auto f, typename SizeType = unsigned>
	using S_function_arity = typename pattern_match_function<f>::template induct
	<
		func_arity_cont, _na_, SizeType
	>;

	template<auto f, typename SizeType = unsigned>
	constexpr bool V_function_arity = V_value_S<S_function_arity<f, SizeType>>;

/***********************************************************************************************************************/

// is nullary:

	template<bool, auto, auto, typename, typename... InTypes>
	using func_is_nullary_cont = S_value_V<!bool(sizeof...(InTypes))>;

	template<auto f, auto = _na_>
	using S_is_nullary_function = typename pattern_match_function<f>::template induct
	<
		func_is_nullary_cont, _na_
	>;

	template<auto f, auto  > using S_left_is_nullary_function	= S_is_nullary_function<f>;
	template<auto  , auto g> using S_right_is_nullary_function	= S_is_nullary_function<g>;

	template<auto f> constexpr bool V_is_nullary_function		= V_value_S<S_is_nullary_function<f>>;

// not nullary:

	template<bool, auto, auto, typename, typename... InTypes>
	using func_not_nullary_cont = S_value_V<bool(sizeof...(InTypes))>;

	template<auto f, auto = _na_>
	using S_not_nullary_function = typename pattern_match_function<f>::template induct
	<
		func_not_nullary_cont, _na_
	>;

	template<auto f, auto  > using S_left_not_nullary_function	= S_not_nullary_function<f>;
	template<auto  , auto g> using S_right_not_nullary_function	= S_not_nullary_function<g>;

	template<auto f> constexpr bool V_not_nullary_function		= V_value_S<S_not_nullary_function<f>>;

/***********************************************************************************************************************/

// is unary:

	template<bool, auto, auto, typename, typename... InTypes>
	using func_is_unary_cont = S_value_V<sizeof...(InTypes) == 1>;

	template<auto f, auto = _na_>
	using S_is_unary_function = typename pattern_match_function<f>::template induct
	<
		func_is_unary_cont, _na_
	>;

	template<auto f, auto  > using S_left_is_unary_function		= S_is_unary_function<f>;
	template<auto  , auto g> using S_right_is_unary_function	= S_is_unary_function<g>;

	template<auto f> constexpr bool V_is_unary_function		= V_value_S<S_is_unary_function<f>>;

// not unary:

	template<bool, auto, auto, typename, typename... InTypes>
	using func_not_unary_cont = S_value_V<sizeof...(InTypes) != 1>;

	template<auto f, auto = _na_>
	using S_not_unary_function = typename pattern_match_function<f>::template induct
	<
		func_not_unary_cont, _na_
	>;

	template<auto f, auto  > using S_left_not_unary_function	= S_not_unary_function<f>;
	template<auto  , auto g> using S_right_not_unary_function	= S_not_unary_function<g>;

	template<auto f> constexpr bool V_not_unary_function		= V_value_S<S_not_unary_function<f>>;

/***********************************************************************************************************************/

// is binary:

	template<bool, auto, auto, typename, typename... InTypes>
	using func_is_binary_cont = S_value_V<sizeof...(InTypes) == 2>;

	template<auto f, auto = _na_>
	using S_is_binary_function = typename pattern_match_function<f>::template induct
	<
		func_is_binary_cont, _na_
	>;

	template<auto f, auto  > using S_left_is_binary_function	= S_is_binary_function<f>;
	template<auto  , auto g> using S_right_is_binary_function	= S_is_binary_function<g>;

	template<auto f> constexpr bool V_is_binary_function		= V_value_S<S_is_binary_function<f>>;

// not binary:

	template<bool, auto, auto, typename, typename... InTypes>
	using func_not_binary_cont = S_value_V<sizeof...(InTypes) != 2>;

	template<auto f, auto = _na_>
	using S_not_binary_function = typename pattern_match_function<f>::template induct
	<
		func_not_binary_cont, _na_
	>;

	template<auto f, auto  > using S_left_not_binary_function	= S_not_binary_function<f>;
	template<auto  , auto g> using S_right_not_binary_function	= S_not_binary_function<g>;

	template<auto f> constexpr bool V_not_binary_function		= V_value_S<S_not_binary_function<f>>;

/***********************************************************************************************************************/

// out type:

	template<bool, auto, auto, typename OutType, typename...>
	using func_out_type_cont = OutType;

	// (convenience alias):

	template<auto f, auto = _na_>
	using f_out_type = typename pattern_match_function<f>::template induct
	<
		func_out_type_cont, _na_
	>;

	template<auto f, auto = _na_> using T_function_out_type = f_out_type<f>;

/***********************************************************************************************************************/

// in type:

	struct typename_list_at
	{
		struct at_halt
		{
			template<typename, auto pos, typename Type, typename... Types>
			using result = Type;
		};

		struct at_cont
		{
			template<typename At, auto pos, typename Type, typename... Types>
			using result = typename At::template result
			<
				pos - 1, Types...
			>;
		};

		template<auto pos, typename... Types>
		using result = typename T_if_then_else
		<
			!bool(pos),

				at_halt, at_cont

		>::template result<typename_list_at, pos, Types...>;
	};

	template<bool, auto, auto pos, typename, typename... InTypes>
	using func_in_type_cont = typename typename_list_at::template result
	<
		pos, InTypes...
	>;

	template<auto f, auto pos>
	using return_in_type = typename pattern_match_function<f>::template induct
	<
		func_in_type_cont, pos
	>;

	// (convenience alias):

	template<auto f, auto pos = 0>
	using f_in_type = T_colist_Bs
	<
		f, _na_,			f, pos,

		S_is_nullary_function,		return_void,
		otherwise,			return_in_type
	>;

	template<auto f, auto = _na_> using T_function_in_type = f_in_type<f>;

/***********************************************************************************************************************/

// composition:

	// n,s:

		template<auto f, auto g, typename... Types>
		constexpr void n_compose_s(Types... args) { f(g(args...)); }

		template<bool, auto g, auto f, typename, typename... InTypes>
		using func_n_compose_s_cont = S_value_V<n_compose_s<f, g, InTypes...>>;

		template<auto f, auto g>
		using return_n_compose_s = typename pattern_match_function<g>::template induct
		<
			func_n_compose_s_cont, f
		>;

	// u,s:

		template<auto f, auto g, typename... Types>
		constexpr f_out_type<f> u_compose_s(Types... args) { return f(g(args...)); }

		template<bool, auto g, auto f, typename, typename... InTypes>
		using func_u_compose_s_cont = S_value_V<u_compose_s<f, g, InTypes...>>;

		template<auto f, auto g>
		using return_u_compose_s = typename pattern_match_function<g>::template induct
		<
			func_u_compose_s_cont, f
		>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// pointer type:

/***********************************************************************************************************************/

	template<typename>
	struct pattern_match_pointer
	{
		static constexpr bool match		= false;
	};

	template<typename Type>
	struct pattern_match_pointer<Type*>
	{
		static constexpr bool match		= true;

		using type				= Type;
	};

/***********************************************************************************************************************/

	template<typename Type>
	constexpr bool V_is_pointer_T			= pattern_match_pointer<Type>::match;

	//

	template<typename Type>
	using T_pointer_T				= Type*;

	template<typename Pointer>
	using T_pointer_type_T				= typename pattern_match_pointer<Pointer>::type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// reference type:

/***********************************************************************************************************************/

	template<typename>
	struct pattern_match_reference
	{
		static constexpr bool match		= false;
	};

	template<typename Type>
	struct pattern_match_reference<Type&>
	{
		static constexpr bool match		= true;

		using type				= Type;
	};

/***********************************************************************************************************************/

	template<typename Type>
	constexpr bool V_is_reference_T			= pattern_match_reference<Type>::match;

	//

	template<typename Type>
	using T_reference_T				= Type&;

	template<typename Reference>
	using T_reference_type_T			= typename pattern_match_reference<Reference>::type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// auto category:

/***********************************************************************************************************************/

// typename to auto (functor):

	template<typename Type>
	constexpr void type_map(Type)			{ }			// Unsafe to use directly,
										// as Type cannot equal void.
										// use the following instead:

	template<typename Type>
	constexpr auto U_type_T		 		= type_map		// This implementation was chosen
							<			// as it simplifies the special
								T_hold		// case when Type == void.
								<
									V_is_reference_T<Type>,

									Type,
									T_pointer_T, Type
								>
							>;

	template<typename Type>
	using let_T_type_U		 		= T_hold
							<
								V_is_reference_T<Type>,

								Type,
								T_pointer_type_T, Type
							>;

	template<auto TypeMap>
	using T_type_U			 		= let_T_type_U
							<
								T_function_in_type<TypeMap>
							>;

	template<typename Type>				// T_decltype(_type)_T:
	using T_decltype_T				= decltype(U_type_T<Type>);

	template<auto Value>				// U_(type_)decltype_V:
	constexpr auto U_decltype_V	 		= U_type_T<decltype(Value)>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// identity type:

/***********************************************************************************************************************/

	template<auto Value1, auto Value2>
	constexpr bool V_equal_VxV			= value_pair<Value1, Value2>::match;

	template<auto Value1, auto Value2>
	using S_equal_VxV				= S_boolean<value_pair<Value1, Value2>::match>;

/***********************************************************************************************************************/

	template<typename Type1, typename Type2>
	constexpr bool V_is_equal_UxU(void(*)(Type1), void(*)(Type2))	// Unsafe to use directly,
		{ return false; }

	template<typename Type>
	constexpr bool V_is_equal_UxU(void(*)(Type), void(*)(Type))	// Use the following instead:
		{ return true; }

	//

	template<typename Type1, typename Type2>
	constexpr bool V_equal_TxT			= V_is_equal_UxU(U_type_T<Type1>, U_type_T<Type2>);

	template<typename Type1, typename Type2>
	using S_equal_TxT				= S_boolean<V_is_equal_UxU(U_type_T<Type1>, U_type_T<Type2>)>;

/***********************************************************************************************************************/

	template<auto TypeMap1, auto TypeMap2>
	constexpr bool V_equal_UxU			= V_is_equal_UxU(TypeMap1, TypeMap2);

	template<auto TypeMap1, auto TypeMap2>
	using S_equal_UxU				= S_boolean<V_is_equal_UxU(TypeMap1, TypeMap2)>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// identifiers (convenience aliases):

/***********************************************************************************************************************/

	constexpr auto U_void							= U_type_T<void>;
	constexpr auto U_char_ptr						= U_type_T<char*>;

/***********************************************************************************************************************/

	template<auto Type, auto = _na_> using S_equals_void			= S_equal_UxU<Type, U_void>;

	template<auto Type1, auto Type2> using S_left_equals_void		= S_equal_UxU<Type1, U_void>;
	template<auto Type1, auto Type2> using S_right_equals_void		= S_equal_UxU<Type2, U_void>;

	//

	template<auto Type> constexpr bool V_equals_char_ptr			= V_equal_UxU<Type, U_char_ptr>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

