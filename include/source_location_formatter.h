#ifndef SOURCE_LOCATION_FORMATTER_H
#define SOURCE_LOCATION_FORMATTER_H

#include <format>
#include <source_location>
#include <string>

template <>
struct std::formatter<std::source_location> : std::formatter<std::string> {
    auto format(const std::source_location& loc,
                std::format_context& ctx) const {
        return std::format_to(ctx.out(), "{}, {}, {}, {}", loc.file_name(),
                              loc.line(), loc.column(), loc.function_name());
    }
};

#endif // SOURCE_LOCATION_FORMATTER_H

