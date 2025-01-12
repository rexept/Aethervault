#pragma once

#include <QWidget>

class ContactPage;
class Logo;
class QVBoxLayout;
class QHBoxLayout;
class QSvgWidget;
class QString;
class QStackedWidget;

class Window : public QWidget {
  public:
    explicit Window(QString dbUsername, QString dbPassword, QWidget* parent = 0);
    ~Window();

  private:
    ContactPage*    m_contactPage;
    Logo*           m_logo;
    QVBoxLayout*    m_masterLayout;
    QStackedWidget* m_stackedWidget;
    QString         m_logoPath;
};
