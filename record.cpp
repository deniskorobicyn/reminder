#include "record.h"
using namespace reminder_app;

Record::Record(QString line) {
  QStringList all = line.split(' ');
  m_birthday = QDate::fromString(all.last(), "yyyy-MM-dd");

  all.pop_back();

  m_name = all.join(' ');
}

Record::Record(QString name, QString birthday) : m_name(name) {
  m_birthday = QDate::fromString(birthday, "yyyy-MM-dd");
}

QString Record::name() const {
  return m_name;
}

QDate Record::birthday() const {
  return m_birthday;
}

QString Record::line() const {
  return m_name + ' ' + m_birthday.toString("yyyy-MM-dd");
}

bool Record::valid() const {
  return !m_name.isEmpty() && m_birthday.isValid();
}

QTextStream& reminder_app::operator<<(QTextStream& out, const Record& record) {
  out << record.name() << " " << record.birthday().toString("yyyy-MM-dd")
      << "\n";

  return out;
}
