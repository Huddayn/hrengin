/*
 * Copyright (C) 2014-2016  absurdworlds
 * Copyright (C) 2015-2016  Hedede <haddayn@gmail.com>
 *
 * License LGPLv3 or later:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef aw_string_split_h
#define aw_string_split_h
#include <string>
#include <vector>
#include <algorithm>
namespace aw {
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
inline std::string join(std::vector<std::string>& source, 
		std::string const& delim)
{
	std::string result;
	for (auto const& str : source) {
		result.append(delim + str);
	}

	return result;
}

/*!
 * \brief
 *      Split string into tokens. Ignores empty tokens.
 *      For example, `split("/ab/cde//fgh/", "/")` will produce 
 *      three tokens: {"ab", "cde", "fgh"}
 * \param source
 *      Source string to split
 * \param delim
 *      String containing possible delimiters.
 * \return
 *      Vector with found tokens.
 */
inline std::vector<std::string>
split(std::string const& source, std::string const& delim)
{
	std::vector<std::string> holder;
	size_t num_tokens = 0;

	size_t pos = source.find_first_not_of(delim);
	size_t delim_pos = source.find_first_of(delim, pos);

	while (pos != std::string::npos) {
		holder.push_back(source.substr(pos, delim_pos - pos));
		++num_tokens;

		pos = source.find_first_not_of(delim, delim_pos);
		delim_pos = source.find_first_of(delim, pos);
	}

	return holder;
}

/*!
 * \brief
 *      Split string into tokens, including empty tokens
 *      For example, explode("/") produces {"", ""}.
 * \param source
 *      Source string to split
 * \param delim
 *      Delimiting sequence
 * \return
 *      Vector of found tokens.
 */
inline std::vector<std::string>
explode(std::string const& source, std::string const& delim)
{
	std::vector<std::string> holder;
	size_t pos1 = 0;
	size_t pos2;

	do {
		pos2 = source.find(delim, pos1);
		holder.push_back(source.substr(pos1, pos2 - pos1));

		if (pos2 == std::string::npos)
			break;

		pos1 = pos2 + delim.size();
	} while (true);

	return holder;
}
} // namespace string
} // namespace aw
#endif//aw_string_split_h