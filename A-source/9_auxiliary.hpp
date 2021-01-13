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

// auxiliary code:

/*
	This code was originally used in the source, but has since become obsolete.
	It is being retained for now, on the off chance it becomes useful in a later extension.
	It is not currently included when the compiler reads the existing source.
*/

/***********************************************************************************************************************/

namespace nlfs_auxiliary
{
	using namespace nlfs_8;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specification (filter engine):

/***********************************************************************************************************************/

	template<typename...> struct pair_specification;

	template
	<
		typename CarType , typename CarAttrSpec ,
		typename CdrType , typename CdrAttrSpec
	>
	struct pair_specification
	<
		car_object	< CarType , CarAttrSpec >,
		cdr_object	< CdrType , CdrAttrSpec >
	>
	{
		using car_object_spec		= car_object	< CarType , CarAttrSpec >;
		using cdr_object_spec		= cdr_object	< CdrType , CdrAttrSpec >;
	};

/***********************************************************************************************************************/

	template<typename PairSpec> using pr_car_object			= typename PairSpec::car_object_spec;
	template<typename PairSpec> using pr_cdr_object			= typename PairSpec::cdr_object_spec;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template<typename PairSpec>
	using pr_signature = pair_signature
	<
		pr_car_object<PairSpec>,
		pr_cdr_object<PairSpec>
	>;

	//

	template<typename PairSpec> using T_pr_signature_T		= pr_signature<PairSpec>;
	template<auto PairSpec> using T_pr_signature_U			= pr_signature<T_type_U<PairSpec>>;

	template<typename PairSpec> constexpr auto U_pr_signature_T	= U_type_T<pr_signature<PairSpec>>;
	template<auto PairSpec> constexpr auto U_pr_signature_U		= U_type_T<pr_signature<T_type_U<PairSpec>>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// dispatch signature:

/***********************************************************************************************************************/

	template
	<
		typename InType1,
		typename InType2,
		typename AuxType,
		typename MsgType
	>
	struct dispatch_one_cycle_signature
	{
		// aliases:

		static constexpr auto InTypeMap1			= U_type_T<InType1>;
		static constexpr auto InTypeMap2			= U_type_T<InType2>;
		static constexpr auto AuxTypeMap			= U_type_T<AuxType>;
		static constexpr auto MsgTypeMap			= U_type_T<MsgType>;

		// predicates:

		template<auto TypeMap> static constexpr bool drop	= V_equal_UxU<TypeMap, U_void>;
		template<auto TypeMap> static constexpr bool keep	= ! V_equal_UxU<TypeMap, U_void>;

		//

		template<auto InMap1, auto InMap2> using S_is_unary	= S_boolean
									<
										(keep<InMap1> && drop<InMap2>)	||
										(drop<InMap1> && keep<InMap2>)
									>;
		template<auto InMap1, auto InMap2> using S_is_binary	= S_boolean<(keep<InMap1> && keep<InMap2>)>;

		//

		template<auto AuxMap, auto MsgMap> using S_is_aux_msg	= S_boolean<(keep<AuxMap> && keep<MsgMap>)>;
		template<auto AuxMap, auto MsgMap> using S_is_msg_only	= S_boolean<(drop<AuxMap> && keep<MsgMap>)>;
		template<auto AuxMap, auto MsgMap> using S_is_aux_only	= S_boolean<(keep<AuxMap> && drop<MsgMap>)>;

		// unary partial specializations:

		template<auto OutMap, auto EndMap>
		using return_out_in_end_ocm				= one_cycle_signature
									<
										out_object<T_type_U<OutMap>>,
										in_object<InType1>,
										end_object<T_type_U<EndMap>>
									>;

		template<auto OutMap, auto EndMap>
		using return_out_in_end_msg_ocm				= one_cycle_signature
									<
										out_object<T_type_U<OutMap>>,
										in_object<InType1>,
										end_object<T_type_U<EndMap>>,
										msg_object<MsgType>
									>;

		template<auto OutMap, auto EndMap>
		using return_out_in_end_aux_ocm				= one_cycle_signature
									<
										out_object<T_type_U<OutMap>>,
										in_object<InType1>,
										end_object<T_type_U<EndMap>>,
										aux_object<AuxType>
									>;

		template<auto OutMap, auto EndMap>
		using return_out_in_end_aux_msg_ocm			= one_cycle_signature
									<
										out_object<T_type_U<OutMap>>,
										in_object<InType1>,
										end_object<T_type_U<EndMap>>,
										aux_object<AuxType>,
										msg_object<MsgType>
									>;

		// binary partial specializations:

		template<auto OutMap, auto EndMap>
		using return_out_in1_in2_end_ocm			= one_cycle_signature
									<
										out_object<T_type_U<OutMap>>,
										car_in_object<InType1>,
										cdr_in_object<InType2>,
										end_object<T_type_U<EndMap>>
									>;

		template<auto OutMap, auto EndMap>
		using return_out_in1_in2_end_msg_ocm			= one_cycle_signature
									<
										out_object<T_type_U<OutMap>>,
										car_in_object<InType1>,
										cdr_in_object<InType2>,
										end_object<T_type_U<EndMap>>,
										msg_object<MsgType>
									>;

		template<auto OutMap, auto EndMap>
		using return_out_in1_in2_end_aux_ocm			= one_cycle_signature
									<
										out_object<T_type_U<OutMap>>,
										car_in_object<InType1>,
										cdr_in_object<InType2>,
										end_object<T_type_U<EndMap>>,
										aux_object<AuxType>
									>;

		template<auto OutMap, auto EndMap>
		using return_out_in1_in2_end_aux_msg_ocm		= one_cycle_signature
									<
										out_object<T_type_U<OutMap>>,
										car_in_object<InType1>,
										cdr_in_object<InType2>,
										end_object<T_type_U<EndMap>>,
										aux_object<AuxType>,
										msg_object<MsgType>
									>;

		// rest partial specializations:

		template<auto OutMap, auto EndMap>
		using return_out_end_ocm				= one_cycle_signature
									<
										out_object<T_type_U<OutMap>>,
										end_object<T_type_U<EndMap>>
									>;

		template<auto OutMap, auto EndMap>
		using return_out_end_msg_ocm				= one_cycle_signature
									<
										out_object<T_type_U<OutMap>>,
										end_object<T_type_U<EndMap>>,
										msg_object<MsgType>
									>;

		template<auto OutMap, auto EndMap>
		using return_out_end_aux_ocm				= one_cycle_signature
									<
										out_object<T_type_U<OutMap>>,
										end_object<T_type_U<EndMap>>,
										aux_object<AuxType>
									>;

		template<auto OutMap, auto EndMap>
		using return_out_end_aux_msg_ocm			= one_cycle_signature
									<
										out_object<T_type_U<OutMap>>,
										end_object<T_type_U<EndMap>>,
										aux_object<AuxType>,
										msg_object<MsgType>
									>;

		// dispatches:

		template<auto OutMap, auto EndMap>
		using return_unary = T_colist_Bs
		<
			AuxTypeMap, MsgTypeMap,		OutMap, EndMap,

			S_is_aux_msg,			return_out_in_end_aux_msg_ocm,
			S_is_msg_only,			return_out_in_end_msg_ocm,
			S_is_aux_only,			return_out_in_end_aux_ocm,
			otherwise,			return_out_in_end_ocm
		>;

		template<auto OutMap, auto EndMap>
		using return_binary = T_colist_Bs
		<
			AuxTypeMap, MsgTypeMap,		OutMap, EndMap,

			S_is_aux_msg,			return_out_in1_in2_end_aux_msg_ocm,
			S_is_msg_only,			return_out_in1_in2_end_msg_ocm,
			S_is_aux_only,			return_out_in1_in2_end_aux_ocm,
			otherwise,			return_out_in1_in2_end_ocm
		>;

		template<auto OutMap, auto EndMap>
		using return_rest = T_colist_Bs
		<
			AuxTypeMap, MsgTypeMap,		OutMap, EndMap,

			S_is_aux_msg,			return_out_end_aux_msg_ocm,
			S_is_msg_only,			return_out_end_msg_ocm,
			S_is_aux_only,			return_out_end_aux_ocm,
			otherwise,			return_out_end_ocm
		>;

		// result:

		template<auto OutMap, auto EndMap>
		using result = T_colist_Bs
		<
			InTypeMap1, InTypeMap2,		OutMap, EndMap,

			S_is_unary,			return_unary,
			S_is_binary,			return_binary,
			otherwise,			return_rest
		>;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

// specification (filter engine):

/***********************************************************************************************************************/

	template<typename...> struct one_cycle_specification;

// unary:

	template
	<
		typename OutType , typename OutAttrSpec ,
		typename InType  , typename InAttrSpec  ,
		typename EndType , typename EndAttrSpec ,
		typename AuxType , typename AuxAttrSpec ,
		typename MsgType , typename MsgAttrSpec
	>
	struct one_cycle_specification
	<
		out_object	< OutType , OutAttrSpec >,
		in_object	< InType  , InAttrSpec  >,
		end_object	< EndType , EndAttrSpec >,
		aux_object	< AuxType , AuxAttrSpec >,
		msg_object	< MsgType , MsgAttrSpec >
	>
	{
		using out_object_spec		= out_object	< OutType , OutAttrSpec >;
		using in_object_spec		= in_object	< InType  , InAttrSpec  >;
		using end_object_spec		= end_object	< EndType , EndAttrSpec >;
		using aux_object_spec		= aux_object	< AuxType , AuxAttrSpec >;
		using msg_object_spec		= msg_object	< MsgType , MsgAttrSpec >;

		using car_in_object_spec	= car_in_object	< InType		>;
		using cdr_in_object_spec	= cdr_in_object	< void			>;
	};

/***********************************************************************************************************************/

// binary:

	template
	<
		typename OutType , typename OutAttrSpec ,
		typename In1Type , typename In1AttrSpec ,
		typename In2Type , typename In2AttrSpec ,
		typename EndType , typename EndAttrSpec ,
		typename AuxType , typename AuxAttrSpec ,
		typename MsgType , typename MsgAttrSpec
	>
	struct one_cycle_specification
	<
		out_object	< OutType , OutAttrSpec >,
		car_in_object	< In1Type , In1AttrSpec >,
		cdr_in_object	< In2Type , In2AttrSpec >,
		end_object	< EndType , EndAttrSpec >,
		aux_object	< AuxType , AuxAttrSpec >,
		msg_object	< MsgType , MsgAttrSpec >
	>
	{
		using out_object_spec		= out_object		< OutType , OutAttrSpec >;
		using car_in_object_spec	= car_in_object		< In1Type , In1AttrSpec >;
		using cdr_in_object_spec	= cdr_in_object		< In2Type , In2AttrSpec >;
		using end_object_spec		= end_object		< EndType , EndAttrSpec >;
		using aux_object_spec		= aux_object		< AuxType , AuxAttrSpec >;
		using msg_object_spec		= msg_object		< MsgType , MsgAttrSpec >;
	};

/***********************************************************************************************************************/

	template<typename OCSpec> using oc_out_object			= typename OCSpec::out_object_spec;
	template<typename OCSpec> using oc_in_object			= typename OCSpec::in_object_spec;
	template<typename OCSpec> using oc_car_in_object		= typename OCSpec::car_in_object_spec;
	template<typename OCSpec> using oc_cdr_in_object		= typename OCSpec::cdr_in_object_spec;
	template<typename OCSpec> using oc_end_object			= typename OCSpec::end_object_spec;
	template<typename OCSpec> using oc_aux_object			= typename OCSpec::aux_object_spec;
	template<typename OCSpec> using oc_msg_object			= typename OCSpec::msg_object_spec;

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template<typename OCSpec>
	using oc_signature = typename dispatch_one_cycle_signature
	<
		obj_type<oc_car_in_object<OCSpec>>,
		obj_type<oc_cdr_in_object<OCSpec>>,
		obj_type<oc_aux_object<OCSpec>>,
		obj_type<oc_msg_object<OCSpec>>

	>::template result
	<
		U_type_T<obj_type<oc_out_object<OCSpec>>>,
		U_type_T<obj_type<oc_end_object<OCSpec>>>
	>;

	//

	template<typename OCSpec> using T_oc_signature_T		= oc_signature<OCSpec>;
	template<auto OCSpec> using T_oc_signature_U			= oc_signature<T_type_U<OCSpec>>;

	template<typename OCSpec> constexpr auto U_oc_signature_T	= U_type_T<oc_signature<OCSpec>>;
	template<auto OCSpec> constexpr auto U_oc_signature_U		= U_type_T<oc_signature<T_type_U<OCSpec>>>;

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

}

