/*
 * Copyright (C) 2015  absurdworlds
 * Copyright (C) 2015  Hedede <hededrk@gmail.com>
 *
 * License LGPLv3-only:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef _hrengin_NonCopyable_
#define _hrengin_NonCopyable_
namespace hrengin {
/*!
 * Utility class, supposed to be used as base, to explicitly define classes,
 * which are derived from this class non-copyable.
 */
class NonCopyable {
protected:
	NonCopyable() = default;
	~NonCopyable() = default;
private:
	NonCopyable(NonCopyable const&) = delete;
	NonCopyable& operator = (NonCopyable const&) = delete;
};
} // namespace hrengin
#endif//_hrengin_NonCopyable_
