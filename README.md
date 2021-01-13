# near-linear-function-space

A C++17 library for template / compile time *higher order functions*, oriented around generic functional programming.
The library is self-contained, in the sense that it does not use the standard namespace (*std::*).

Also included within are modules for the one cycle list inductor paradigm. A one cycle list inductor is an operator
that can specialize to any one cycle list operator. The core inventory includes: *repeat*, *map*, *fold*, *find first*,
*find all*, *zip* (bimap), *fasten* (bifold), *glide* (zip with a carry).

This inductor implementation is translated from the theory given [here](https://github.com/Daniel-Nikpayuk/Mathematics/blob/main/Essays/List%20Induction/Version-One/induction.pdf).
