#include "custom_allocator.hpp"
#include <string>
#include <vector>
#include <map>

namespace katahiromz {

typedef std::basic_string<char, std::char_traits<char>,
                          custom_allocator<char> >      custom_string;
typedef std::basic_string<wchar_t, std::char_traits<wchar_t>,
                          custom_allocator<wchar_t> >   custom_wstring;

template <typename T>
using custom_vector = std::vector<T, custom_allocator<T> >;

template <typename KEY, typename VALUE, typename COMPARE = std::less<KEY> >
using custom_map = std::map<KEY, VALUE, COMPARE,
                            custom_allocator<std::pair<const KEY, VALUE> > >;

} // namespace katahiromz
