#pragma once

#include <iosfwd>
#include <format>

struct Vertex
{
    double m_col = 0; // x
    double m_row = 0; // y

    Vertex() = default;
    Vertex(double col, double row) : m_col(col), m_row(row) {}

    bool isHigherThan(const Vertex& other) const;
    bool isToTheRightOf(const Vertex& other) const;
    bool isValid() const;
};

std::istream& operator>>(std::istream& istr, Vertex& v);
std::ostream& operator<<(std::ostream& ostr, const Vertex& v);

template <>
struct std::formatter<Vertex>
{
    constexpr auto parse(format_parse_context& ctx)
    {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const Vertex& v, FormatContext& ctx) const
    {
        return format_to(ctx.out(), "{}", std::tie(v.m_col, v.m_row));
    }
};
