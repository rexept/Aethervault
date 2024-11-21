#include "header.h"
#include <QHBoxLayout>
#include <QSvgWidget>

Header::Header(QWidget *parent) : QWidget(parent) {
  m_logo = new QSvgWidget(this);

  m_logoPath = "../assets/Aethervault-logot.svg";
  m_logo->load(m_logoPath);
  m_logo->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  m_logo->setFixedWidth(272);
  m_logo->setFixedHeight(45);

  // Header - for logo - or other stuff
  m_header = new QHBoxLayout();
  m_header->addWidget(m_logo, 2, Qt::AlignLeft);
}

QHBoxLayout *Header::getLayout() { return this->m_header; }
