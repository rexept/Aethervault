#include "header.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QSvgWidget>

Header::Header(QWidget *parent) : QWidget(parent) {
  m_logo = new QSvgWidget(this);

  m_logoPath = "../assets/Aethervault-logot.svg";
  m_logo->load(m_logoPath);
  m_logo->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  // Values taken from svg file - rounded
  m_logo->setFixedWidth(272);
  m_logo->setFixedHeight(45);

  // Header - for logo - or other stuff
  m_headerLayout = new QHBoxLayout(this);
  m_headerLayout->addWidget(m_logo, 0, Qt::AlignLeft);
}

Header::~Header() { qDebug() << "Header destructed"; }

QHBoxLayout *Header::getLayout() { return this->m_headerLayout; }
