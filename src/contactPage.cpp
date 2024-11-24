#include "contactPage.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
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
  m_phoneNumber = new QLineEdit(this);
  m_address1 = new QLineEdit(this);
  m_address2 = new QLineEdit(this);

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
  m_layout->addWidget(m_phoneNumber);
  m_layout->addWidget(m_address1);
  m_layout->addWidget(m_address2);

  const QString websitePlaceholder = "Website";
  const QString emailPlaceholder = "Email";
  const QString passwordPlaceholder = "Password";
  const QString firstNamePlaceholder = "First Name";
  const QString lastNamePlaceholder = "Last Name";
  const QString phoneNumberPlaceholder = "Phone Number";
  const QString address1Placeholder = "Address 1";
  const QString address2Placeholder = "Address 2";

  m_website->setPlaceholderText(websitePlaceholder);
  m_email->setPlaceholderText(emailPlaceholder);
  m_password->setPlaceholderText(passwordPlaceholder);
  m_firstName->setPlaceholderText(firstNamePlaceholder);
  m_lastName->setPlaceholderText(lastNamePlaceholder);
  m_phoneNumber->setPlaceholderText(phoneNumberPlaceholder);
  m_address1->setPlaceholderText(address1Placeholder);
  m_address2->setPlaceholderText(address2Placeholder);
}

SaveButton::SaveButton(QWidget *parent) {
  QPushButton *button = new QPushButton("Save", this);
}
