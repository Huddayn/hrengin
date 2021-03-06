/*
 * Copyright (C) 2014      absurdworlds
 * Copyright (C) 2014-2016 hedede <haddayn@gmail.com>
 *
 * License LGPLv3 or later:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef aw_math_float_h
#define aw_math_float_h
#include <aw/math/math.h>
#include <aw/types/support/reinterpret.h>
#include <aw/types/traits/basic_traits.h>
namespace aw {
template <typename Flt>
struct float_traits;

template <>
struct float_traits<f32> {
	static constexpr size_t max_ulps = 4;
	static constexpr f32 max_rel = std::numeric_limits<f32>::epsilon();
	static constexpr f32 epsilon = 0.0001f;
	typedef i32 int_type;
	typedef u32 uint_type;
};

template <>
struct float_traits<f64> {
	static constexpr size_t max_ulps = 8;
	static constexpr f64 max_rel = std::numeric_limits<f64>::epsilon();
	static constexpr f64 epsilon = 0.0000001;
	typedef i64 int_type;
	typedef u64 uint_type;
};

namespace _impl {
/*
 * See
 * https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
 */
template <typename F>
inline bool almostEqualUlps(F a, F b, size_t maxUlpsDiff)
{
	using uint_type = typename float_traits<F>::uint_type;

	// Different signs means they do not match.
	if ((a < 0) != (b < 0))
		return a == b;

	// Find the difference in ULPs.
	uint_type ulps_a = reinterpret<uint_type>(a);
	uint_type ulps_b = reinterpret<uint_type>(b);

	if (ulps_a > ulps_b)
		std::swap(ulps_a, ulps_b);

	return (ulps_a - ulps_b) <= maxUlpsDiff;
}

template <typename F>
inline bool almostEqualRelative(F a, F b, F maxRelDiff)
{
	const F diff = fabs(a - b);

	a = fabs(a);
	b = fabs(b);

	return diff <= std::max(a, b) * maxRelDiff;
}

template <typename F>
inline bool almostEqualEpsilon(F a, F b, F maxDiff)
{
	// Check if the numbers are really close -- needed
	// when comparing numbers near zero.
	return fabs(a - b) <= maxDiff;
}

template <typename F>
bool less_epsilon(F a, F b, F maxDiff)
{
	if (a < (b - maxDiff))
		return true;
	return false;
}

template <typename F>
bool greater_epsilon(F a, F b, F maxDiff)
{
	if (a < (b + maxDiff))
		return true;
	return false;
}
} // namespace _impl

template <typename F>
bool compare_ulps(F a, F b)
{
	static_assert(is_float<F>, "Type must be a floating point type!");

	using I = typename float_traits<F>::uint_type;

	constexpr I max_ulps = float_traits<F>::max_ulps;
	constexpr F epsilon  = float_traits<F>::epsilon;

	return _impl::almostEqualUlps(a,b,max_ulps) ||
	       _impl::almostEqualEpsilon(a,b,epsilon);
}

template <typename F>
bool compare_float(F a, F b)
{
	static_assert(is_float<F>, "Type must be a floating point type!");

	constexpr F max_rel = float_traits<F>::max_rel;
	constexpr F epsilon = float_traits<F>::epsilon;

	return _impl::almostEqualRelative(a,b,max_rel) ||
	       _impl::almostEqualEpsilon(a,b,epsilon);
}
} //namespace aw
#endif//aw_math_float_h
