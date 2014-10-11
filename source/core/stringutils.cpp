/**
   Copyright (C) 2014  absurdworlds

   License LGPLv3-only:
   GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
   This is free software: you are free to change and redistribute it.
   There is NO WARRANTY, to the extent permitted by law.
 */

#include <algorithm>

#include <hrengin/common/types.h>
#include <hrengin/common/stringutils.h>

namespace hrengin {

std::string getFileExtension(std::string& dest, std::string const& path)
{
	size_t extpos = path.find_last_of(".");

	if(extpos == std::string::npos) {
		dest = "";
	}

	dest = path.substr(extpos+1);

	std::transform(dest.begin(), dest.end(), dest.begin(), ::tolower);

	return dest;
}

} // namespace hrengin