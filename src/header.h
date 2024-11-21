#ifndef HEADER_H
#define HEADER_H

#include <QWidget>

class QSvgWidget;
class QHBoxLayout;

class Header : public QWidget {
public:
  explicit Header(QWidget *parent = 0);

  QHBoxLayout *getLayout();

private:
  QSvgWidget *m_logo;
  QString m_logoPath;
  QHBoxLayout *m_header;
};

#endif // HEADER_H
