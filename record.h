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
  Record(QString);
  Record(QString, QString);

  QString name() const;
  QDate birthday() const;

  bool valid() const;

  QString line() const;
};

QTextStream& operator<<(QTextStream& out, const Record& record);
}

#endif  // RECORD_H
