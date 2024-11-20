#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QLineEdit;
class QLabel;
class Window : public QWidget {
public:
  explicit Window(QWidget *parent = 0);

private:
  QLineEdit *m_lineEdit;
  QLabel *m_label;
};

#endif // WINDOW_H
