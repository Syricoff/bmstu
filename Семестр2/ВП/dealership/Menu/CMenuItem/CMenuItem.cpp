#include "CMenuItem.h"

namespace SNS
{
    CMenuItem::CMenuItem(std::string name, Func func)
        : m_name(name), m_func(func) {}

    CMenuItem::CMenuItem(const CMenuItem &itemMenu)
        : CMenuItem(itemMenu.m_name, itemMenu.m_func) {}

    CMenuItem &CMenuItem::operator=(const CMenuItem &other)
    {
        if (this == &other) return *this;

        m_name = other.m_name;
        m_func = other.m_func;

        return *this;
    }

    int CMenuItem::run(int selected) const
    {
        return m_func(selected);
    }

    int CMenuItem::operator()(size_t selected) const
    {
        return run(selected);
    }

    void CMenuItem::print(std::ostream &out) const
    {
        out << m_name;
    }
    std::ostream &operator<<(std::ostream &out, const CMenuItem &itemMenu)
    {
        itemMenu.print(out);
        return out;
    }

} // namespace SNS