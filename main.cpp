#include <QApplication>
#include <QCommandLineParser>

#include "reminder.h"

using namespace reminder_app;

int main(int argc, char* argv[]) {
  QCoreApplication app(argc, argv);
  QCoreApplication::setApplicationName("reminder");
  QCoreApplication::setApplicationVersion("1.0");

  Reminder reminder("reminder.dat");

  QCommandLineParser parser;
  parser.setApplicationDescription(
      "Reminder is simple application for storing and showing birthays");
  parser.addHelpOption();
  parser.addVersionOption();
  parser.addPositionalArgument("name",
                               QCoreApplication::translate("main", "Name"));
  parser.addPositionalArgument(
      "birthday", QCoreApplication::translate("main", "Birthday date"));

  QCommandLineOption addition(
      "a",
      QCoreApplication::translate("main",
                                  "Add record to database, \n example: "
                                  "reminder -a \"john smith\" \"yyyy-mm-dd\""));
  parser.addOption(addition);

  QCommandLineOption remove(
      "r",
      QCoreApplication::translate(
          "main",
          "Add record to database,\n example: reminder -r \"john smith\""));
  parser.addOption(remove);

  parser.process(app);

  if (parser.isSet(addition)) {
    const QStringList args = parser.positionalArguments();
    Record r(args.at(0), args.at(1));

    reminder.add(r);

  } else {
    if (parser.isSet(remove)) {
      const QStringList args = parser.positionalArguments();

      reminder.remove(args.at(0));

    } else {
      reminder.show();
    }
  }

  return 0;
}
