#include "window.h"
#include "contactPage.h"
#include "header.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QVBoxLayout>
#include <QtSvg/QSvgWidget>

Window::Window(QWidget *parent) : QWidget(parent) {
  // Init layouts and widgets
  m_contactPage = new ContactPage(this);
  m_header = new Header(this);
  m_masterLayout = new QVBoxLayout(this);

  // Add layouts and widgets to master layout
  m_masterLayout->addLayout(m_header->getLayout());
  m_masterLayout->addWidget(m_contactPage);

  setLayout(m_masterLayout);
}

Window::~Window() {
  m_contactPage->closeDatabase();
  delete m_contactPage;
  delete m_header;
  delete m_masterLayout;
  qDebug() << "Window destructed";
}
