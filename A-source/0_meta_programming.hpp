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
	S - value_pair					(typename)
	T - type					(typename)
	U - type_map					(constexpr auto)
	V - value					(constexpr auto)

	G - template<typename> class
	F - template<auto> class

	E - template<typename, typename> class
	D - template<typename, auto> class
	C - template<auto, typename> class
	B - template<auto, auto> class
*/

/***********************************************************************************************************************/

namespace ocli_0
{

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// keywords:

	constexpr void _na_()				{ }	// (not applicable)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// typename category:

/***********************************************************************************************************************/

	template<auto Value1, auto Value2>
	struct value_pair
	{
		static constexpr bool match		= false;

		// (gcc-8) internal compiler error:

	//	static constexpr auto car_value		= Value1;
	//	static constexpr auto cdr_value		= Value2;
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
		// then else:

			// value:

			template<auto Antecedent, auto Consequent>
			static constexpr auto V_then_else_VxV = Antecedent;

			// type:

			template<typename Antecedent, typename Consequent>
			using T_then_else_TxT = Antecedent;

		// hold:

			template<typename Antecedent, template<typename> class Function, typename Consequent>
			using T_hold_TxGxT = Antecedent;
	};

/***********************************************************************************************************************/

// false:

	template<auto NA>
	struct pattern_match_bool<false, NA>
	{
		// then else:

			// value:

			template<auto Antecedent, auto Consequent>
			static constexpr auto V_then_else_VxV = Consequent;

			// type:

			template<typename Antecedent, typename Consequent>
			using T_then_else_TxT = Consequent;

		// hold:

			template<typename Antecedent, template<typename> class Function, typename Consequent>
			using T_hold_TxGxT = Function<Consequent>;
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

	template<bool Predicate, typename Antecedent, template<typename> class Function, typename Consequent>
	using T_hold = typename pattern_match_bool<Predicate>::template
		T_hold_TxGxT<Antecedent, Function, Consequent>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// auto category:

/***********************************************************************************************************************/

// typename to auto (functor):

	template<typename Type>
	constexpr void type_map(Type)			{ }	// unsafe to use directly,
								// use the following instead:

	template<typename Type>
	constexpr auto U_type_T		 		= type_map
							<
								T_hold
								<
									V_is_reference_T<Type>,

									Type,
									T_pointer_T, Type
								>
							>;

	constexpr auto U_void				= U_type_T<void>;

	// T_decltype(_type)_T:

	template<typename Type>
	using T_decltype_T				= decltype(U_type_T<Type>);

	// U_(type_)decltype_V:

	template<auto Value>
	constexpr auto U_decltype_V	 		= U_type_T<decltype(Value)>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// error type:

/***********************************************************************************************************************/

	enum struct V_ErrMsg
	{
	// colist:

		no_available_match,
		no_value_specified,
		no_default_specified,
		no_available_info,

	// function:

		type_inference_failure,

	// filler:

		dimension
	};

	//

	template<V_ErrMsg e> constexpr bool V_is_no_available_match_V		= (e == V_ErrMsg::no_available_match);
	template<V_ErrMsg e> constexpr bool V_is_no_value_specified_V		= (e == V_ErrMsg::no_value_specified);
	template<V_ErrMsg e> constexpr bool V_is_no_default_specified_V		= (e == V_ErrMsg::no_default_specified);
	template<V_ErrMsg e> constexpr bool V_is_no_available_info_V		= (e == V_ErrMsg::no_available_info);

	template<V_ErrMsg e> constexpr bool V_is_type_inference_failure_V	= (e == V_ErrMsg::type_inference_failure);

/***********************************************************************************************************************/

	struct S_ErrMsg
	{
	// colist:

		using no_available_match		= S_value_V<V_ErrMsg::no_available_match>;
		using no_value_specified		= S_value_V<V_ErrMsg::no_value_specified>;
		using no_default_specified		= S_value_V<V_ErrMsg::no_default_specified>;
		using no_available_info			= S_value_V<V_ErrMsg::no_available_info>;

	// function:

		using type_inference_failure		= S_value_V<V_ErrMsg::type_inference_failure>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// colist type:

/***********************************************************************************************************************/

// empty:

	template<template<auto, auto> class... Aliases> constexpr bool V_empty_Bs = ! bool(sizeof...(Aliases));

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// stem:

/***********************************************************************************************************************/

// true:

	struct colist_true
	{
		// hold:

			template
			<
			// true:

				typename Default1,

			// false:

				template
				<
					typename,

					auto, auto,			auto, auto,			typename,

					template<auto, auto> class,	template<auto, auto> class,

					template<auto, auto> class...

				> class Suboperator, typename Operator,

				auto Value11, auto Value12,		auto Value21, auto Value22,	typename Default2,

				template<auto, auto> class... Aliases
			>
			using T_hold_Bs = Default1;

		// dihold:

			template
			<
			// true:

				template<auto, auto> class Alias, auto Value11, auto Value12,

			// false:

				template
				<
					auto, auto,			auto, auto,			typename,

					template<auto, auto> class...

				> class SubOperator,

				auto Value21, auto Value22,		auto Value31, auto Value32,	typename Default,

				template<auto, auto> class... Aliases
			>
			using T_dihold_Bs = Alias<Value11, Value12>;
	};

/***********************************************************************************************************************/

// false:

	struct colist_false
	{
		// hold:

			template
			<
			// true:

				typename Default1,

			// false:

				template
				<
					typename,

					auto, auto,			auto, auto,			typename,

					template<auto, auto> class,	template<auto, auto> class,

					template<auto, auto> class...

				> class Suboperator, typename Operator,

				auto Value11, auto Value12,		auto Value21, auto Value22,	typename Default2,

				template<auto, auto> class Alias1,	template<auto, auto> class Alias2,

				template<auto, auto> class... Aliases
			>
			using T_hold_Bs = Suboperator
			<
				Operator,

				Value11, Value12,	Value21, Value22,	Default2,

				Alias1,			Alias2,

				Aliases...
			>;

		// dihold:

			template
			<
			// true:

				template<auto, auto> class Alias, auto Value11, auto Value12,

			// false:

				template
				<
					auto, auto,			auto, auto,			typename,

					template<auto, auto> class...

				> class SubOperator,

				auto Value21, auto Value22,		auto Value31, auto Value32,	typename Default,

				template<auto, auto> class... Aliases
			>
			using T_dihold_Bs = SubOperator
			<
				Value21, Value22,	Value31, Value32,	Default,

				Aliases...
			>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// colist:

	struct T__colist__Bs
	{
		template
		<
			typename Colist,

			auto Value11, auto Value12,		auto Value21, auto Value22,	typename Default,

			template<auto, auto> class Policy,	template<auto, auto> class Break,

			template<auto, auto> class... Aliases
		>
		using loop = typename T_if_then_else
		<
			V_value_S<Policy<Value11, Value12>>,

				colist_true, colist_false

		>::template T_dihold_Bs
		<
		// true:

			Break, Value21, Value22,

		// false:

			Colist::template result,

			Value11, Value12,	Value21, Value22,	Default,

			Aliases...
		>;

		template
		<
			auto Value11, auto Value12,		auto Value21, auto Value22,	typename Default,

			template<auto, auto> class... Aliases
		>
		using result = typename T_if_then_else
		<
			V_empty_Bs<Aliases...>,

				colist_true, colist_false

		>::template T_hold_Bs
		<
		// true:

			Default,

		// false:

			loop, T__colist__Bs,

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
	using T_colist_Bs = typename T__colist__Bs::template result
	<
		Value11, Value12, Value21, Value22,
		S_ErrMsg::no_available_match,
		Aliases...
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
		typename T__colist__Bs::template result
		<
			Value11, Value12, Value21, Value22,
			S_ErrMsg::no_available_match,
			Aliases...
		>
	>;

/***********************************************************************************************************************/

	template<auto, auto> using otherwise		= S_true;
	template<auto, auto> using return_false		= S_false;
	template<auto, auto> using return_true		= S_true;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// function type:

/***********************************************************************************************************************/

	enum struct V_Arity
	{
		nullary,
		unary,
		binary,
		n_ary,

		dimension // filler
	};

/***********************************************************************************************************************/

	template<auto, auto = _na_>
	struct pattern_match_function
	{
		static constexpr bool match		= false;
	};

	template<typename OutType, OutType(*f)(), auto NA>
	struct pattern_match_function<f, NA>
	{
		static constexpr bool match		= true;
		static constexpr auto U_decltype	= U_decltype_V<f>;
		static constexpr V_Arity arity		= V_Arity::nullary;

		using out_type				= OutType;
		using in_type				= void;
	};

	template<typename OutType, typename InType, OutType(*f)(InType), auto NA>
	struct pattern_match_function<f, NA>
	{
		static constexpr bool match		= true;
		static constexpr auto U_decltype	= U_decltype_V<f>;
		static constexpr V_Arity arity		= V_Arity::unary;

		using out_type				= OutType;
		using in_type				= InType;
	};

	template<typename OutType, typename InType1, typename InType2, OutType(*f)(InType1, InType2), auto NA>
	struct pattern_match_function<f, NA>
	{
		static constexpr bool match		= true;
		static constexpr auto U_decltype	= U_decltype_V<f>;
		static constexpr V_Arity arity		= V_Arity::binary;

		using out_type				= OutType;
		using car_in_type			= InType1;
		using cdr_in_type			= InType2;
	};

	template
	<
		typename OutType,
		typename InType1, typename InType2, typename InType3, typename... InTypes,
		OutType(*f)(InType1, InType2, InType3, InTypes...), auto NA
	>
	struct pattern_match_function<f, NA>
	{
		static constexpr bool match		= true;
		static constexpr auto U_decltype	= U_decltype_V<f>;
		static constexpr V_Arity arity		= V_Arity::n_ary;

		using out_type				= OutType;
	};

/***********************************************************************************************************************/

	template<auto f> constexpr bool V_is_function_V			= pattern_match_function<f>::match;
	template<auto f> constexpr auto U_function_type_V		= pattern_match_function<f>::U_decltype;

	template<auto f> constexpr V_Arity V_arity_V			= pattern_match_function<f>::arity;
	template<auto f> constexpr bool V_is_nullary_V			= (V_arity_V<f> == V_Arity::nullary);
	template<auto f> constexpr bool V_is_unary_V			= (V_arity_V<f> == V_Arity::unary);
	template<auto f> constexpr bool V_is_binary_V			= (V_arity_V<f> == V_Arity::binary);

	//

	template<auto f, auto = _na_> using T_function_out_type_V	= typename pattern_match_function<f>::out_type;
	template<auto f, auto = _na_> using T_function_in_type_V	= typename pattern_match_function<f>::in_type;
	template<auto f, auto = _na_> using T_function_car_in_type_V	= typename pattern_match_function<f>::car_in_type;
	template<auto f, auto = _na_> using T_function_cdr_in_type_V	= typename pattern_match_function<f>::cdr_in_type;

	// (convenience aliases):

	template<auto f, auto = _na_> using f_out_type			= typename pattern_match_function<f>::out_type;
	template<auto f, auto = _na_> using f_in_type			= typename pattern_match_function<f>::in_type;
	template<auto f, auto = _na_> using f_car_in_type		= typename pattern_match_function<f>::car_in_type;
	template<auto f, auto = _na_> using f_cdr_in_type		= typename pattern_match_function<f>::cdr_in_type;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// identity type:

/***********************************************************************************************************************/

	template<typename Type1, typename Type2>
	constexpr bool V_is_equal_UxU(void(*)(Type1), void(*)(Type2))	// unsafe to use directly,
		{ return false; }

	template<typename Type>
	constexpr bool V_is_equal_UxU(void(*)(Type), void(*)(Type))	// use the following instead:
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

	//

	template<auto Type, auto = _na_> using S_equals_void		= S_equal_UxU<Type, U_void>;
	template<auto Type1, auto Type2> using S_left_equals_void	= S_equal_UxU<Type1, U_void>;
	template<auto Type1, auto Type2> using S_right_equals_void	= S_equal_UxU<Type2, U_void>;

/***********************************************************************************************************************/

	template<auto Value1, auto Value2>
	constexpr bool V_equal_VxV			= value_pair<Value1, Value2>::match;

	template<auto Value1, auto Value2>
	using S_equal_VxV				= S_boolean<value_pair<Value1, Value2>::match>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// error type (continued):

/***********************************************************************************************************************/

	template<typename e>
	constexpr bool V_is_type_inference_failure_T	= V_equal_TxT<e, S_ErrMsg::type_inference_failure>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// auto category (continued):

/***********************************************************************************************************************/

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
								T_function_in_type_V<TypeMap>
							>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

