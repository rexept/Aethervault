#include "contactPage.h"
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>

ContactPage::ContactPage(QWidget *parent) : QWidget(parent) {
  // Database - SQL
  const QString configDir =
      QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);

  qDebug() << "Config directory: " + configDir;

  const QString dbName = configDir + "/aethervault/db.sqlite";

  qDebug() << "Database path: " + dbName;

  db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(dbName);
  if (!db.open()) {
    qDebug() << "Error: Unable to open the database";
    QMessageBox::warning(nullptr, "Error!",
                         "Error: Unable to open the database");
  }

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

  // Init default values for field inputs - blank
  // Does this handle blanks correctly?
  m_websiteField = "";
  m_emailField = "";
  m_passwordField = "";
  m_firstNameField = "";
  m_lastNameField = "";
  m_phoneNumberField = "";
  m_address1Field = "";
  m_address2Field = "";

  setupInputFields();
  setupSaveButton();
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

void ContactPage::setupSaveButton() {
  m_saveButton = new QPushButton("Save", this);

  m_layout->addWidget(m_saveButton);
  m_layout->setAlignment(m_saveButton, Qt::AlignRight);

  // Connect to QLineEdits
  connect(m_saveButton, &QPushButton::clicked, this, [this]() {
    // When the button is clicked, retrieve the text from the QLineEdits
    m_websiteField = m_website->text();
    m_emailField = m_email->text();
    m_passwordField = m_password->text();
    m_firstNameField = m_firstName->text();
    m_lastNameField = m_lastName->text();
    m_phoneNumberField = m_phoneNumber->text();
    m_address1Field = m_address1->text();
    m_address2Field = m_address2->text();
  });
}
