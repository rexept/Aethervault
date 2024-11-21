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
  m_firstName = new QLineEdit(this);
  m_lastName = new QLineEdit(this);

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
  m_layout->addWidget(m_firstName);
  m_layout->addWidget(m_lastName);

  const QString websitePlaceholder = "Website";
  const QString emailPlaceholder = "Email";
  const QString passwordPlaceholder = "Password";
  const QString firstNamePlaceholder = "First Name";
  const QString lasttNamePlaceholder = "Last Name";

  m_website->setPlaceholderText(websitePlaceholder);
  m_email->setPlaceholderText(emailPlaceholder);
  m_password->setPlaceholderText(passwordPlaceholder);
  m_firstName->setPlaceholderText(firstNamePlaceholder);
  m_lastName->setPlaceholderText(lasttNamePlaceholder);
}
