/*
 * Copyright (C) 2014  absurdworlds
 *
 * License LGPLv3-only:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef _hrengin_stringutils_
#define _hrengin_stringutils_

#include <hrengin/common/compiler_setup.h>

#include <cstring>

#include <string>
#include <vector>

#include <hrengin/core/core.h>

namespace hrengin {
//! Generic strlen
template<typename char_type>
size_t strlen_g (char_type const* str)
{
	char_type const* s = str;
	while(*s) {
		s++;
	}
	return s - str;
}

//! Get file extension from string
inline std::string getFileExtension (std::string& dest, std::string const& path)
{
	size_t extpos = path.find_last_of(".");

	if(extpos == std::string::npos) {
		dest = "";
	}

	dest = path.substr(extpos+1);

	std::transform(dest.begin(), dest.end(), dest.begin(), ::tolower);

	return dest;
}

/*!
 * \brief 
 * 	Split string into tokens
 * \param source
 * 	Source string to split
 * \param delim
 * 	Delimiting sequence
 * \param holder
 * 	Vector to hold results
 * \return
 * 	Number of found tokens
 */
inline size_t splitString (std::string const& source, std::string const& delim,
		std::vector<std::string>& holder)
{
	size_t num_tokens = 0;

	size_t pos = source.find_first_not_of(delim);
	size_t delim_pos = source.find_first_of(delim, pos);

	while(pos != std::string::npos) {
		holder.push_back(source.substr(pos, delim_pos - pos));
		++num_tokens;

		pos = source.find_first_not_of(delim, delim_pos);
		delim_pos = source.find_first_of(delim, pos);
	}

	return num_tokens;
}

namespace string {
/*!
 * \brief
 * 	join strings together
 * \param source
 * 	vector of strings to be joined
 * \param delim 
 * 	delimiting sequence which will be inserted between 
 * 	joined strings
 * \return
 * 	resulting string concatenated together
 */
inline std::string join (std::vector<std::string>& source, 
		std::string const& delim)
{
	std::string result;
	for(auto const& str : source) {
		result.append(delim + str);
	}

	return result;
}
} // namespace string
} // namespace hrengin
#endif //_hrengin_stringutils_
