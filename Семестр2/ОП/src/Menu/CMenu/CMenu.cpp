#include "CMenu.h"

CMenu::CMenu(string title, ItemList itemList) : m_title(std::move(title)), m_items(std::move(itemList)) {}

void CMenu::selectItem(int selected)
{
    if (selected <= m_items.size() && selected > 0)
    {
        m_selected = selected - 1;
    }
    else
    {
        m_selected = -1;
    }
}

int CMenu::runSelected() const
{
    if (m_selected == -1)
    {
        return -1;
    }
    return m_items[m_selected](m_selected);
}

int CMenu::operator()() const
{
    return runSelected();
}

int CMenu::getSelected() const
{
    return m_selected;
}

void CMenu::print(std::ostream &out) const
{
    out << m_title << std::endl;
    out << "============================\n";

    size_t index{1};
    for (const auto &item : m_items)
    {
        out << index++ << ". " << item << '\n';
    }
    out << std::endl;
}

std::ostream &operator<<(std::ostream &out, const CMenu &menu)
{
    menu.print(out);

    return out;
}

std::istream &operator>>(std::istream &in, CMenu &menu)
{
    int selected = getEnteredNum(
        "Введите номер нужного пункта -> ",
        getValidate(menu.m_items.size()),
        in);
    menu.selectItem(selected);

    return in;
}

ValidateNum getValidate(int count_items)
{
    return [count_items](int value) -> bool
    {
        return (value <= count_items && value > 0);
    };
}
