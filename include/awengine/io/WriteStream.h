/*
 * Copyright (C) 2015  absurdworlds
 * Copyright (C) 2015  hedede <haddayn@gmail.com>
 *
 * License LGPLv3 or later:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef _awrts_OStream_
#define _awrts_OStream_
#include <string>

#include <awengine/common/types.h>

namespace awrts {
namespace io {
/*!
 * This class provides unified interface for sequential data writing.
 */
class WriteStream {
public:
	/*! Write a character into the output stream. */
	virtual i32 put(char c) = 0;

	/*! Write a string into the output stream */
	virtual i32 put(std::string str) = 0;

	/*!
	 * Get current position in the stream.
	 */
	virtual size_t position() const = 0;
};

} // namespace io
} // namespace awrts
#endif//_awrts_OStream_
