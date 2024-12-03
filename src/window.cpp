#include "window.h"
#include "contactPage.h"
#include "logo.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QVBoxLayout>
#include <QtSvg/QSvgWidget>

Window::Window(QString dbUsername, QString dbPassword, QWidget *parent)
    : QWidget(parent) {
  // Init layouts and widgets
  m_contactPage = new ContactPage(dbUsername, dbPassword, this);
  m_logo = new Logo(this);
  m_masterLayout = new QVBoxLayout(this);

  // Add layouts and widgets to master layout
  m_masterLayout->addLayout(m_logo->getLayout());
  m_masterLayout->addWidget(m_contactPage);

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
