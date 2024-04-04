#ifndef UPDATECHECKER_H
#define UPDATECHECKER_H

#include <QObject>

class UpdateChecker : public QObject {
  Q_OBJECT
 public:
  UpdateChecker(QWidget* parent);
  void checkForUpdates();

 private:
  QWidget* mParent;
};

#endif  // UPDATECHECKER_H
