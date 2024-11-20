#include "window.h"
#include <QLineEdit>
#include <QLabel>

Window::Window(QWidget *parent) : QWidget(parent) {
  m_lineEdit = new QLineEdit(this);
}
