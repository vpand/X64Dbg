#ifndef VALIDATEEXPRESSIONTHREAD_H
#define VALIDATEEXPRESSIONTHREAD_H

#include <QMutex>
#include <QThread>
#include <functional>

#include "Imports.h"

typedef std::function<void(QString expression)> EXPRESSIONCHANGEDCB;

class ValidateExpressionThread : public QThread {
  Q_OBJECT
 public:
  ValidateExpressionThread(QObject* parent = 0);
  void start();
  void stop();
  void emitExpressionChanged(bool validExpression, bool validPointer,
                             dsint value);
  void emitInstructionChanged(dsint sizeDifference, QString error);

 signals:
  void expressionChanged(bool validExpression, bool validPointer, dsint value);
  void instructionChanged(dsint sizeDifference, QString error);

 public slots:
  void textChanged(QString text);
  void additionalStateChanged();
  void setOnExpressionChangedCallback(EXPRESSIONCHANGEDCB callback);

 private:
  QMutex mExpressionMutex;
  QString mExpressionText;
  bool mExpressionChanged;
  volatile bool mStopThread;
  EXPRESSIONCHANGEDCB mOnExpressionChangedCallback;

  void run();
};

#endif  // VALIDATEEXPRESSIONTHREAD_H
