#pragma once

#include <QWidget>

class QSvgWidget;
class QHBoxLayout;

class Logo : public QWidget {
  public:
    explicit Logo(QWidget* parent = 0);
    ~Logo();

    QHBoxLayout* getLayout();

  private:
    QSvgWidget*  m_logo;
    QString      m_logoPath;
    QHBoxLayout* m_headerLayout;
};
