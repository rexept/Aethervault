#include "contactPage.h"
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

ContactPage::ContactPage(QWidget *parent) : QWidget(parent) {
  // Init layout
  m_layout = new QVBoxLayout(this);

  // Init input boxes
  m_website = new QLineEdit(this);
  m_email = new QLineEdit(this);
  m_password = new QLineEdit(this);
  m_name = new QLineEdit(this);

  setupInputFields();
}

// useless?
QVBoxLayout *ContactPage::getLayout() { return this->m_layout; }

/// Adds widgets to layout and sets their respective placeholders
void ContactPage::setupInputFields() {
  // Add widgets to layout
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
