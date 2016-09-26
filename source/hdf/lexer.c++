/*
 * Copyright (C) 2014-2015  absurdworlds
 * Copyright (C) 2015       Hedede <hededrk@gmail.com>
 *
 * License LGPLv3 or later:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#include <cassert>
#include <cstdio>

#include <aw/fileformat/hdf/lexer.h>

#include <aw/io/input_stream.h>
#include <aw/utility/string/compose.h>
#include <aw/algorithm/in.h>

namespace aw {
namespace hdf {
inline bool isDigit (char c) {
	return (c >= '0' && c <= '9');
}

inline bool isNameBeginChar (char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

inline bool isNameChar (char c) {
	return isNameBeginChar(c) || isDigit(c) || c == '-' || c == '_';
}

inline bool isWhitespace (char c) {
	return (in(c, ' ', '\t', '\r', '\n'));
}

bool junk(char c)
{
	return isWhitespace(c) || c == '/';
}

template<typename Func>
void Lexer::skip(Func condition)
{
	char c;
	stream.peek(c);

	while(condition(c) && c != 0)
		stream.next(c);
}

void Lexer::skipLine()
{
	skip( [] (char c) { return c != '\n'; });
}

void Lexer::skipWhitespace()
{
	skip(isWhitespace);
}

void Lexer::fastForward()
{
	char c;
	stream.peek(c);

	if (isWhitespace(c)) {
		skipWhitespace();
	} else if (c == '/') {
		stream.next(c);

		if (c == '/') {
			skipLine();
		} else {
			stream.get(c);
			error("unexpected token: /");
		}
	}
}

std::string Lexer::readNumber()
{
	char c;
	stream.peek(c);

	std::string val;

	while ((c >= '0' && c <= '9') || in(c, '.', 'e', 'E', '+', '-')) {
		val += c;
		stream.next(c);
	}

	return val;
}

std::string Lexer::readString() {
	char c;
	stream.peek(c);

	std::string val;

	while (c != '"') {
		// When '\' is encountered in a string, skip the '\' and read
		// next character as it is.
		if (c == '\\')
			stream.next(c);

		val += c;
		stream.next(c);
	}

	// consume "
	stream.get(c);
	return val;
}

std::string Lexer::readName()
{
	char c;
	stream.peek(c);

	std::string name;

	while (isNameChar(c)) {
		name += c;

		stream.next(c);
	}

	return name;
}

std::string Lexer::readIllegalToken()
{
	char c;
	stream.peek(c);

	std::string name;

	while(!isWhitespace(c) && !in(c, '[', ']', '=', ':', ',')) {
		name += c;

		stream.next(c);
	}

	return name;
}

token Lexer::readToken()
{
	char c;
	stream.peek(c);

	while (junk(c)) {
		fastForward();
		stream.peek(c);
	}

	auto getChar = [&] () {
		stream.get(c);
		return std::string(1, c);
	};

	switch (c) {
	case 0:
		return token{token::eof};
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		return token{token::number, readNumber(), pos};
	case '"':
		stream.next(c); // consume '"'
		return token{token::string, readString(), pos};
	case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G':
	case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N':
	case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U':
	case 'V': case 'W': case 'X': case 'Y': case 'Z':
	case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
	case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
	case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u':
	case 'v': case 'w': case 'x': case 'y': case 'z':
		return token{token::name, readName(), pos};
	case '=':
		return token{token::equals, getChar(), pos};
	case ':':
		return token{token::colon, getChar(), pos};
	case ',':
		return token{token::comma, getChar(), pos};
	case '!':
		return token{token::bang, getChar(), pos};
	case '[':
		stream.next(c); // consume '['
		return token{token::node_begin, readName(), pos};
	case ']':
		return token{token::node_end, getChar(), pos};
	case '{':
		return token{token::vec_begin, getChar(), pos};
	case '}':
		return token{token::vec_end, getChar(), pos};
	default:
		return token{token::invalid, readIllegalToken(), pos};
	}
}

token Lexer::peekToken()
{
	return tok;
}

token Lexer::getToken()
{
	token tmp = tok;
	tok = readToken();
	return tmp;
}

void Lexer::error(std::string msg)
{
	printf("[HDF:%u]: %s\n", stream.position(), msg.c_str());
}
} // namespace hdf
} // namespace aw
