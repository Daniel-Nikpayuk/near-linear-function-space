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

// one cycle list inductor:

/***********************************************************************************************************************/

namespace ocli_2
{
	using namespace ocli_1;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// endopose:

		// Restricted to functions with the same input and output types.
		// This is limiting in general, but works in this context.

	// continuation passing monadic composition:

	//	f(x, c1(y))  endopose  g(y, c2(z))    :=    f(x, \y -> g(y, c2(z)))

	template<typename StemType1, typename StemType2>
	struct cp_endopose
	{
		template<auto cont_f, typename Type>
		static constexpr Type (*result)(Type) = StemType1::template result
		<
			StemType2::template result<cont_f, Type>,
			Type
		>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// chain endopose:

/***********************************************************************************************************************/

// empty:

	template<typename... Types> constexpr bool V_empty_Ts = ! bool(sizeof...(Types));

/***********************************************************************************************************************/
/***********************************************************************************************************************/

// cp_stem:

/***********************************************************************************************************************/

// true:

	struct cp_chain_endopose_true
	{
		// hold:

			template
			<
			// true:

				typename Default,

			// false:

				template
				<
					typename, typename,
					typename, typename...

				> class Suboperator, typename Operator, typename Current,

				typename... CP_Stems
			>
			using T_hold_Ts = Default;
	};

/***********************************************************************************************************************/

// false:

	struct cp_chain_endopose_false
	{
		// hold:

			template
			<
			// true:

				typename Default,

			// false:

				template
				<
					typename, typename,
					typename, typename...

				> class Suboperator, typename Operator, typename Current,

				typename CP_Stem, typename... CP_Stems
			>
			using T_hold_Ts = Suboperator<Operator, Current, CP_Stem, CP_Stems...>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	struct cp_chain_endopose
	{
		template
		<
			typename ChainEndopose, typename Chain,
			typename CP_Stem, typename... CP_Stems
		>
		using loop = typename ChainEndopose::template result
		<
			cp_endopose<Chain, CP_Stem>, CP_Stems...
		>;

		template
		<
			typename Chain, typename... CP_Stems
		>
		using result = typename T_if_then_else
		<
			V_empty_Ts<CP_Stems...>,

				cp_chain_endopose_true, cp_chain_endopose_false

		>::template T_hold_Ts
		<
			Chain,
			loop, cp_chain_endopose, Chain, CP_Stems...
		>;
	};

/***********************************************************************************************************************/

// inductor:

	template
	<
		typename Type, auto cont_f, typename... CP_Stems
	>
	constexpr Type (*cp_inductor)(Type) = cp_chain_endopose::template result
	<
		cp_lift<_id_>, CP_Stems...

	>::template result<cont_f, Type>;

/***********************************************************************************************************************/

// recursive inductor:

	template
	<
		typename Type, typename... CP_Stems
	>
	constexpr Type cp_recursive_inductor(Type arg)
	{
		return cp_chain_endopose::template result
		<
			cp_lift<_id_>, CP_Stems...

		>::template result<cp_recursive_inductor<Type, CP_Stems...>, Type>(arg);
	}

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// cycle inductor:

/***********************************************************************************************************************/

	template
	<
		typename Signature, typename... CP_Stems
	>
	constexpr Signature & precycle(Signature & arg)
	{
		return cp_chain_endopose::template result
		<
			cp_lift<_id_>, CP_Stems...

		>::template result<_id_, Signature &>(arg);
	}

/***********************************************************************************************************************/

	template
	<
		typename Signature, typename... CP_Stems
	>
	constexpr Signature & cycle(Signature & arg)
	{
		return cp_chain_endopose::template result
		<
			cp_lift<_id_>, CP_Stems...

		>::template result<cycle<Signature, CP_Stems...>, Signature &>(arg);
	}

/***********************************************************************************************************************/

	template
	<
		typename Signature, typename... CP_Stems
	>
	constexpr Signature & postcycle(Signature & arg)
	{
		return cp_chain_endopose::template result
		<
			cp_lift<_id_>, CP_Stems...

		>::template result<_id_, Signature &>(arg);
	}

/***********************************************************************************************************************/

	template<auto f, auto g, auto h>
	constexpr auto cycle_inductor = V_do_compose_opt
	<
		V_do_compose_opt<f, g>, h
	>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// baseline functions:

/***********************************************************************************************************************/

// predicates:

	template<typename Type> constexpr bool equal(Type arg1, Type arg2)			{ return (arg1 == arg2); }
	template<typename Type> constexpr bool not_equal(Type arg1, Type arg2)			{ return (arg1 != arg2); }
	template<typename Type> constexpr bool less_than(Type arg1, Type arg2)			{ return (arg1 < arg2); }
	template<typename Type> constexpr bool less_than_or_equal(Type arg1, Type arg2)		{ return (arg1 <= arg2); }
	template<typename Type> constexpr bool greater_than(Type arg1, Type arg2)		{ return (arg1 > arg2); }
	template<typename Type> constexpr bool greater_than_or_equal(Type arg1, Type arg2)	{ return (arg1 >= arg2); }

	template<typename Type, Type Value> constexpr bool is_value(Type arg)			{ return (arg == Value); }
	template<typename Type, Type Value> constexpr bool not_value(Type arg)			{ return (arg != Value); }
	template<typename Type, Type Value> constexpr bool is_less_than(Type arg)		{ return (arg < Value); }
	template<typename Type, Type Value> constexpr bool is_less_than_or_equal(Type arg)	{ return (arg <= Value); }
	template<typename Type, Type Value> constexpr bool is_greater_than(Type arg)		{ return (arg > Value); }
	template<typename Type, Type Value> constexpr bool is_greater_than_or_equal(Type arg)	{ return (arg >= Value); }

/***********************************************************************************************************************/

// constants:

	template<typename Type, Type Value> constexpr Type constant()				{ return Value; }

/***********************************************************************************************************************/

// arithmetic operators:

	template<typename Type> constexpr Type add(Type arg1, Type arg2)			{ return arg1 + arg2; }
	template<typename Type> constexpr Type subtract(Type arg1, Type arg2)			{ return arg1 - arg2; }
	template<typename Type> constexpr Type multiply(Type arg1, Type arg2)			{ return arg1 * arg2; }
	template<typename Type> constexpr Type divide(Type arg1, Type arg2)			{ return arg1 / arg2; }
	template<typename Type> constexpr Type modulo(Type arg1, Type arg2)			{ return arg1 % arg2; }

	template<typename Type, auto Value> constexpr Type add_by(Type arg)			{ return arg + Value; }
	template<typename Type, Type Value> constexpr Type subtract_by(Type arg)		{ return arg - Value; }
	template<typename Type, Type Value> constexpr Type multiply_by(Type arg)		{ return arg * Value; }
	template<typename Type, Type Value> constexpr Type divide_by(Type arg)			{ return arg / Value; }
	template<typename Type, Type Value> constexpr Type modulo_by(Type arg)			{ return arg % Value; }

	template<typename Type, Type Value> constexpr void add_assign_by(Type & arg)		{ arg += Value; }
	template<typename Type, Type Value> constexpr void subtract_assign_by(Type & arg)	{ arg -= Value; }
	template<typename Type, Type Value> constexpr void multiply_assign_by(Type & arg)	{ arg *= Value; }
	template<typename Type, Type Value> constexpr void divide_assign_by(Type & arg)		{ arg /= Value; }
	template<typename Type, Type Value> constexpr void modulo_assign_by(Type & arg)		{ arg %= Value; }

/***********************************************************************************************************************/

	template<typename Type> constexpr Type max(Type arg1, Type arg2)	{ return arg1 > arg2 ? arg1 : arg2; }
	template<typename Type> constexpr Type min(Type arg1, Type arg2)	{ return arg1 < arg2 ? arg1 : arg2; }

/***********************************************************************************************************************/

// mutators:

	template<typename Type1, typename Type2>
		constexpr void assign(Type1 & arg1, Type2 arg2)			{ arg1 = arg2; }

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

