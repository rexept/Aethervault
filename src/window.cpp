#include "window.h"
#include "contactPage.h"
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

Window::Window(QWidget *parent) : QWidget(parent) {
  contactpage = new ContactPage(this);

  QVBoxLayout *layout = contactpage->get_layout();

  setLayout(layout);
}
