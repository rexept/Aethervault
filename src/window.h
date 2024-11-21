#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QLineEdit;
class QLabel;
class ContactPage;
class QVBoxLayout;
class QHBoxLayout;
class QSvgWidget;
class QString;

class Window : public QWidget {
public:
  explicit Window(QWidget *parent = 0);

private:
  ContactPage *contactPage;
  QSvgWidget *logo;
  QVBoxLayout *masterLayout;
  QHBoxLayout *header;
  QString logoPath;
};

#endif // WINDOW_H
