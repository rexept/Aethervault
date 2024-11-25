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

  const QString dbName = configDir + "/aethervault/aether.db";

  qDebug() << "Database path: " + dbName;

  db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(dbName);
  if (!db.open()) {
    qDebug() << "Error: Unable to open the database";
    QMessageBox::warning(nullptr, "Error!",
                         "Error: Unable to open the database");
  }

  // Create contact table (if it doesn't exist)
  if (!query.exec("CREATE TABLE IF NOT EXISTS contacts ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "website TEXT, "
                  "email TEXT, "
                  "password_hash TEXT, "
                  "first_name TEXT, "
                  "last_name TEXT, "
                  "phone_number TEXT, "
                  "address_one TEXT, "
                  "address_two TEXT)")) {
    qDebug() << "Error: Unable to make contacts table"
             << query.lastError().text();
    QMessageBox::warning(nullptr, "Error!",
                         "Error: Unable to make contacts table");
  } else {
    qDebug() << "Initiated contacts table";
  }

  // Init layout
  m_layout = new QVBoxLayout(this);

  // Init input boxes
  m_id = new QLineEdit(this);
  m_website = new QLineEdit(this);
  m_email = new QLineEdit(this);
  m_password = new QLineEdit(this);
  m_firstName = new QLineEdit(this);
  m_lastName = new QLineEdit(this);
  m_phoneNumber = new QLineEdit(this);
  m_address1 = new QLineEdit(this);
  m_address2 = new QLineEdit(this);

  // Make m_id non-editable
  m_id->setReadOnly(true);

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
  m_layout->addWidget(m_id);
  m_layout->addWidget(m_website);
  m_layout->addWidget(m_email);
  m_layout->addWidget(m_password);
  m_layout->addWidget(m_firstName);
  m_layout->addWidget(m_lastName);
  m_layout->addWidget(m_phoneNumber);
  m_layout->addWidget(m_address1);
  m_layout->addWidget(m_address2);

  const QString idPlaceholder =
      "Id - If you can see this something is broken...";
  const QString websitePlaceholder = "Website";
  const QString emailPlaceholder = "Email";
  const QString passwordPlaceholder = "Password";
  const QString firstNamePlaceholder = "First Name";
  const QString lastNamePlaceholder = "Last Name";
  const QString phoneNumberPlaceholder = "Phone Number";
  const QString address1Placeholder = "Address 1";
  const QString address2Placeholder = "Address 2";

  m_id->setPlaceholderText(idPlaceholder);
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

  // Connect button to QLineEdits
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
