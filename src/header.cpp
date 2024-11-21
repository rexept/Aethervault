#include "header.h"
#include <QHBoxLayout>
#include <QSvgWidget>

Header::Header(QWidget *parent) : QWidget(parent) {
  logo = new QSvgWidget(this);

  logoPath = "../assets/Aethervault-logot.svg";
  logo->load(logoPath);
  logo->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  logo->setFixedWidth(272);
  logo->setFixedHeight(45);

  // Header - for logo - or other stuff
  header = new QHBoxLayout();
  header->addWidget(logo, 2, Qt::AlignLeft);
}

QHBoxLayout *Header::getLayout() { return this->header; }
