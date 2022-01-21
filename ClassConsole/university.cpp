#include "university.h"

University::University()
{
//    Person::name = "";
    //    __super::name = "";
}

University::University(const QString &name, const QString &college, const QString &_class)
{
    this->setFullName(name, college, _class);
}

void University::setFullName(const QString &name, const QString &college, const QString &_class)
{
    this->m_name = name;
    this->m_college = college;
    this->m_class = _class;
}

const QString& University::getName() const
{
    return this->m_name;
}

const QString& University::getCollege() const
{
    return this->m_college;
}

const QString& University::getClass() const
{
    return this->m_class;
}

void University::setName(const QString &name)
{
    this->m_name = name;
}

void University::setCollege(const QString &college)
{
    this->m_college = college;
}

void University::setClass(const QString &_class)
{
    this->m_class = _class;
}
