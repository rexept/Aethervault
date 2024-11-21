#include "window.h"
#include "contactPage.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QVBoxLayout>
#include <QtSvg/QSvgWidget>

Window::Window(QWidget *parent) : QWidget(parent) {
  contactPage = new ContactPage(this);
  masterLayout = new QVBoxLayout(this);
  logo = new QSvgWidget(this);

  logoPath = "../assets/Aethervault-logot.svg";
  logo->load(logoPath);
  logo->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  logo->setFixedWidth(272);
  logo->setFixedHeight(45);

  // Top layout - header - for logo
  QHBoxLayout *topLayout = new QHBoxLayout();
  topLayout->addWidget(logo, 2, Qt::AlignLeft);

  masterLayout->addLayout(topLayout);

  masterLayout->addWidget(contactPage);

  setLayout(masterLayout);
}
