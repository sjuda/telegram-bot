#include "utils.hpp"

#include <fstream>

namespace Utils
{

std::string fromLocale(const std::string& localeStr)
{
    boost::locale::generator g;
    g.locale_cache_enabled(true);
    std::locale loc = g(boost::locale::util::get_system_locale());
    return boost::locale::conv::to_utf<char>(localeStr, loc);
}


}
