#include "window.h"
#include "contactPage.h"
#include "logo.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QStackedWidget>
#include <QString>
#include <QVBoxLayout>
#include <QtSvg/QSvgWidget>

Window::Window(QString dbUsername, QString dbPassword, QWidget *parent)
    : QWidget(parent) {
  // Init layouts and widgets
  m_contactPage = new ContactPage(dbUsername, dbPassword);
  m_logo = new Logo();
  m_stackedWidget = new QStackedWidget(this);
  m_masterLayout = new QVBoxLayout();

  // Add layouts and widgets to master layout
  m_stackedWidget->addWidget(m_contactPage);

  m_masterLayout->addLayout(m_logo->getLayout());
  m_masterLayout->addWidget(m_stackedWidget);

  setLayout(m_masterLayout);
}

Window::~Window() {
  m_contactPage->closeDatabase();
  // Redundant? Does QT know to delete because of window.show()
  delete m_contactPage;
  delete m_logo;
  delete m_masterLayout;
  qDebug() << "Window destructed";
}
