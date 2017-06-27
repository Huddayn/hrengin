#include <vector>
#include <aw/archive/archive_base.h>
#include <aw/utility/ranges/char_view.h>
namespace aw {
namespace arc {

struct testarc : input_archive<testarc>, output_archive<testarc> {
	using input_archive<testarc>::operator();
	using output_archive<testarc>::operator();

	template<typename T>
	static constexpr bool is_directly_serializable {
		is_arithmetic<T> || is_string<T>
	};

	template<typename T>
	void save(T const& value)
	{
		if constexpr(is_string<T>) {
			save(value.size());
			for (char c : value) {
				data.push_back(c);
			}
		} else {
			for (char c : char_view_iterator{value})
				data.push_back(c);
		}
	}

	template<typename T>
	void load(T& value)
	{
		if constexpr(is_string<T>) {
			value.clear();
			size_t size; load(size);
			while (size --> 0) {
				value.push_back(data[iter++]);
			}
		} else {
			for (char& c : char_edit_iterator{value})
				c = data[iter++];
		}
	}

	void start_save_virtual(string_view type, string_view name) { save(type); }
	void end_save_virtual(string_view type, string_view name) { }

	std::string start_load_virtual(string_view name)
	{
		std::string type;
		load(type);
		return type;
	}
	void end_load_virtual(string_view name) { }

	void start_save(object_kind kind, string_view name) { }
	void end_save(object_kind kind, string_view name) { }

	void start_load(object_kind kind, string_view name) { }
	void end_load(object_kind kind, string_view name) { }

	std::vector<char> data;
	size_t iter = 0;
};

aw_register_archive( testarc );


} // namespace arc
} // namespace aw