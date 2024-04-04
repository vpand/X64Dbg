#ifndef SHORTCUTEDIT_H
#define SHORTCUTEDIT_H

#include <QKeyEvent>
#include <QKeySequence>
#include <QLineEdit>

class ShortcutEdit : public QLineEdit {
  Q_OBJECT
  Q_PROPERTY(bool error MEMBER mError READ error)
  int keyInt;
  bool mError;

 public:
  explicit ShortcutEdit(QWidget* parent = 0);
  const QKeySequence getKeysequence() const;
  bool error() const;

 public slots:
  void setErrorState(bool error);

 signals:
  void askForSave();

 protected:
  void keyPressEvent(QKeyEvent* event);
};

#endif  // SHORTCUTEDIT_H
