/*
 * Copyright (C) 2014-2015  absurdworlds
 * Copyright (C) 2015       Hedede <hededrk@gmail.com>
 *
 * License LGPLv3-only:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#include <stdio.h>

#include <hrengin/core/Logger.h>

#include <hrengin/io/WriteFile.h>

namespace hrengin {
namespace io {

WriteFile::WriteFile (std::string const& path, bool append)
	: File(path)
{
	this->open(append);
}

WriteFile::~WriteFile ()
{
	if(isOpen()) {
		fclose(file_);
	}
}

void WriteFile::open (bool append)
{
	if (path_.size() == 0) {
		return;
	}

	if(append) {
		file_ = fopen(path_.c_str(), "ab");
	} else {
		file_ = fopen(path_.c_str(), "wb");
	}

	if (file_) {
		fseek(file_, 0, SEEK_END);
		size_ = tell();
		fseek(file_, 0, SEEK_SET);
	} else {
	}
}

i32 WriteFile::write (void const* buffer, u32 size)
{
	if (!isOpen()) {
		return -1;
	}

	return i32(fwrite(buffer, 1, size, file_));
}

i32 WriteFile::seek (i32 offset, bool relative)
{
	if (!isOpen()) {
		return -1;
	}

	return fseek(file_, offset, relative ? SEEK_CUR : SEEK_SET);
}

u32 WriteFile::tell () const
{
	return ftell(file_);
}

u32 WriteFile::getSize () const
{
	return size_;
}

std::string const& WriteFile::getPath () const
{
	return path_;
}

} // namespace io
} // namespace hrengin