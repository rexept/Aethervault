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
  ~Window();

private:
  ContactPage *m_contactPage;
  Header *m_header;
  QVBoxLayout *m_masterLayout;
  QString m_logoPath;
};

#endif // WINDOW_H
