#include "window.h"
#include "contactPage.h"
#include "header.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QVBoxLayout>
#include <QtSvg/QSvgWidget>

using CONTACTPAGE_H::SaveButton;

Window::Window(QWidget *parent) : QWidget(parent) {
  // Init layouts and widgets
  m_contactPage = new ContactPage(this);
  m_saveButton = new SaveButton(this);
  m_header = new Header(this);
  m_masterLayout = new QVBoxLayout(this);

  // Add layouts and widgets to master layout
  m_masterLayout->addLayout(m_header->getLayout());
  m_masterLayout->addWidget(m_contactPage);
  m_masterLayout->addWidget(m_saveButton);

  setLayout(m_masterLayout);
}
