#include "record.h"
using namespace reminder_app;

Record::Record(const QString& name, const QString& birthday) : m_name(name) {
  m_birthday = QDate::fromString(birthday, "yyyy-MM-dd");
}

QString Record::name() const {
  return m_name;
}

QString Record::birthday() const {
  return m_birthday.toString("yyyy-MM-dd");
}

QTextStream& reminder_app::operator<<(QTextStream& out, const Record& record) {
  out << record.name() << " " << record.birthday() << "\n";

  return out;
}
