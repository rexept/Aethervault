#include "window.h"
#include "contactPage.h"
#include "header.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QVBoxLayout>
#include <QtSvg/QSvgWidget>

Window::Window(QWidget *parent) : QWidget(parent) {
  m_contactPage = new ContactPage(this);
  m_header = new Header(this);
  m_masterLayout = new QVBoxLayout(this);

  m_masterLayout->addLayout(m_header->getLayout());

  m_masterLayout->addWidget(m_contactPage);

  setLayout(m_masterLayout);
}
