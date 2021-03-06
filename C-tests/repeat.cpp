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

#include"list_operators.h"

/***********************************************************************************************************************/

// repeat:

namespace ocli_testing
{
	using namespace list_operators;

/***********************************************************************************************************************/

	void simple_repeat_test()
	{
		using spec = repeat_spec
		<
			s_type
		>;

		array<s_type> arr;

		repeat<spec>(arr.begin(), arr.end(), s_type(7));

		print_sarray(arr.begin(), arr.end());
	}

/***********************************************************************************************************************/

}

