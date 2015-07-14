#ifndef REMINDER_H
#define REMINDER_H

#include <QFile>
#include <QString>
#include "record.h"

namespace reminder_app {
class Reminder {
  QFile m_file;

 public:

  Reminder(QString);
  void add(Record);
  void remove(QString);
  void show();
  ~Reminder();

 private:
  Reminder(Reminder&);
  Reminder& operator=(Reminder&);
};
}

#endif  // REMINDER_H
