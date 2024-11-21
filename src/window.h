#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QLineEdit;
class QLabel;
class ContactPage;

class Window : public QWidget {
public:
  explicit Window(QWidget *parent = 0);

private:
  ContactPage *contactpage;
};

#endif // WINDOW_H
