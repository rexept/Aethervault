#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class ContactPage;
class SaveButton;
class Header;
class QVBoxLayout;
class QHBoxLayout;
class QSvgWidget;
class QString;

class Window : public QWidget {
public:
  explicit Window(QWidget *parent = 0);

private:
  ContactPage *m_contactPage;
  SaveButton *m_saveButton;
  Header *m_header;
  QSvgWidget *m_logo;
  QVBoxLayout *m_masterLayout;
  QString m_logoPath;
};

#endif // WINDOW_H
