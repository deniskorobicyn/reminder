#include <iostream>
#include "reminder.h"

using namespace reminder_app;

Reminder::Reminder(QString filename) : m_file(filename) {
}

void Reminder::add(Record person) {
  m_file.open(QIODevice::Append);

  QTextStream out(&m_file);
  out << person << "\n";

  m_file.close();
}

void Reminder::remove(QString person) {
  m_file.open(QIODevice::ReadWrite);
  QString s;
  QTextStream stream(&m_file);
  while (!stream.atEnd()) {
    QString line = stream.readLine();
    if (!line.contains(person))
      s.append(line + "\n");
  }
  m_file.resize(0);
  stream << s;
  m_file.close();
}

void Reminder::show() {
    m_file.open(QIODevice::ReadOnly);
    QTextStream stream(&m_file);
    while (!stream.atEnd()) {
        std::cout << stream.readLine().toUtf8().constData() << std::endl;
    }
    m_file.close();
}

Reminder::~Reminder() {
  if (m_file.isOpen())
    m_file.close();
}
