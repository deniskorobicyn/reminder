#ifndef RECORD_H
#define RECORD_H
#include <QString>
#include <QDate>
#include <QTextStream>

namespace reminder_app {
class Record {
  QString m_name;
  QDate m_birthday;

  friend QTextStream& operator<<(QTextStream& out, const Record& record);

 public:
  Record(const QString&, const QString&);

  QString name() const;
  QString birthday() const;

  QString line();
};

QTextStream& operator<<(QTextStream& out, const Record& record);
}

#endif  // RECORD_H
