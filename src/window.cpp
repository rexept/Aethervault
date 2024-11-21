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
  contactPage = new ContactPage(this);
  header = new Header(this);
  masterLayout = new QVBoxLayout(this);

  masterLayout->addLayout(header->getLayout());

  masterLayout->addWidget(contactPage);

  setLayout(masterLayout);
}
