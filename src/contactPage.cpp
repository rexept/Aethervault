#include "contactPage.h"
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

ContactPage::ContactPage(QWidget *parent) : QWidget(parent) {
  m_layout = new QVBoxLayout(this);

  m_website = new QLineEdit(this);
  m_email = new QLineEdit(this);
  m_password = new QLineEdit(this);
  m_name = new QLineEdit(this);

  setup_widgets();
}

QVBoxLayout *ContactPage::get_layout() { return m_layout; }

void ContactPage::setup_widgets() {
  m_layout->addWidget(m_website);
  m_layout->addWidget(m_email);
  m_layout->addWidget(m_password);
  m_layout->addWidget(m_name);

  const QString website_placeholder = "Website";
  const QString email_placeholder = "Email";
  const QString password_placeholder = "Password";
  const QString name_placeholder = "Name";

  m_website->setPlaceholderText(website_placeholder);
  m_email->setPlaceholderText(email_placeholder);
  m_password->setPlaceholderText(password_placeholder);
  m_name->setPlaceholderText(name_placeholder);
}
