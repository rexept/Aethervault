#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class ContactPage;
class Header;
class QVBoxLayout;
class QHBoxLayout;
class QSvgWidget;
class QString;

class Window : public QWidget {
public:
  explicit Window(QWidget *parent = 0);

private:
  ContactPage *contactPage;
  Header *header;
  QSvgWidget *logo;
  QVBoxLayout *masterLayout;
  QString logoPath;
};

#endif // WINDOW_H
