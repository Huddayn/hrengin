/*
 * Copyright (C) 2016  Hedede <haddayn@gmail.com>
 *
 * License LGPLv3 or later:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef aw_internal_winapi_helpers_h
#define aw_internal_winapi_helpers_h
#include <system_error>

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
namespace aw {
namespace io {
namespace win32 {
inline void set_error( std::error_code& ec )
{
	ec.assign( GetLastError(), std::system_category() );
}

inline void set_error_if(bool cond, std::error_code& ec)
{
	if (cond) {
		set_error( ec );
	} else {
		ec.clear();
	}
}

inline bool close_handle( uintptr_t handle, std::error_code& ec )
{
	bool closed = ::CloseHandle( HANDLE(handle) );
	set_error_if( !closed, ec );
	return closed;
}

inline uintmax_t get_file_size(file_descriptor fd, std::error_code& ec)
{
	LARGE_INTEGER sz;
	bool ret = ::GetFileSizeEx( HANDLE(fd), &sz);

	set_error_if(!ret, ec);

	return ret ? sz.QuadPart : uintmax_t(-1);
}

} // namespace win32
} // namespace io
} // namespace aw
#endif//aw_internal_winapi_helpers_h