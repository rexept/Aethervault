#include "contactPage.h"
#include <QAction>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>

ContactPage::ContactPage(QString dbUsername, QString dbPassword, QWidget* parent) : QWidget(parent) {
    // Init
    m_passwordIsShown = false;
    // Database - SQL
    m_configDir = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);

    qDebug() << "Config directory: " + m_configDir;

    QDir dbDir;
    dbDir.mkdir(m_configDir + "/aethervault");
    m_dbName = m_configDir + "/aethervault/aether.db";

    qDebug() << "Database path: " + m_dbName;

    // Init layout
    m_layout = new QVBoxLayout(this);

    // Init input boxes
    m_id          = new QLineEdit(this);
    m_website     = new QLineEdit(this);
    m_email       = new QLineEdit(this);
    m_password    = new QLineEdit(this);
    m_firstName   = new QLineEdit(this);
    m_lastName    = new QLineEdit(this);
    m_phoneNumber = new QLineEdit(this);
    m_address1    = new QLineEdit(this);
    m_address2    = new QLineEdit(this);

    // Make m_id non-editable
    m_id->setReadOnly(true);

    // Hide password
    m_password->setEchoMode(QLineEdit::Password);

    QAction* togglePasswordVisibility{m_password->addAction(QIcon("../assets/eye-slash-solid.png"), QLineEdit::TrailingPosition)};

    connect(togglePasswordVisibility, &QAction::triggered, this, [this, togglePasswordVisibility]() { s_togglePasswordVisibility(togglePasswordVisibility); });

    // Database - SQL
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(m_dbName);
    m_db.setUserName(dbUsername);
    m_db.setPassword(dbPassword);

    if (!m_db.open()) {
        qDebug() << "Error: Unable to open the database" << m_db.lastError().text();
        QMessageBox::warning(this, "Error!", "Error: Unable to open the database");
    } else {
        qDebug() << "Database Opened";
    }

    // Create contact table (if it doesn't exist)
    QSqlQuery query(m_db);
    if (!query.exec("CREATE TABLE IF NOT EXISTS contacts ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "website TEXT, "
                    "email TEXT, "
                    "password TEXT, "
                    "first_name TEXT, "
                    "last_name TEXT, "
                    "phone_number TEXT, "
                    "address_one TEXT, "
                    "address_two TEXT)")) {
        qDebug() << "Error: Unable to make contacts table" << query.lastError().text();
        QMessageBox::warning(this, "Error!", "Error: Unable to make contacts table");
    } else {
        qDebug() << "Initiated contacts table";
    }
    m_setupInputFields();
    m_setupSaveButton();
}

void ContactPage::closeDatabase() {
    // Do I also have to remove??
    // Risky although ok because it gets closed before QCoreApplication is deleted
    // See docs
    m_db.close();
    qDebug() << "Closed database";
}

ContactPage::~ContactPage() {
    qDebug() << "ContactPage destructed";
}

// useless?
QVBoxLayout* ContactPage::getLayout() const {
    return this->m_layout;
}

/// Adds widgets to layout and sets their respective placeholders
void ContactPage::m_setupInputFields() {
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

    const QString idPlaceholder          = "Id - If you can see this something is broken...";
    const QString websitePlaceholder     = "Website";
    const QString emailPlaceholder       = "Email";
    const QString passwordPlaceholder    = "Password";
    const QString firstNamePlaceholder   = "First Name";
    const QString lastNamePlaceholder    = "Last Name";
    const QString phoneNumberPlaceholder = "Phone Number";
    const QString address1Placeholder    = "Address 1";
    const QString address2Placeholder    = "Address 2";

    // Set defaults
    m_idTextValue          = "";
    m_websiteTextValue     = "";
    m_emailTextValue       = "";
    m_passwordTextValue    = "";
    m_firstNameTextValue   = "";
    m_lastNameTextValue    = "";
    m_phoneNumberTextValue = "";
    m_address1TextValue    = "";
    m_address2TextValue    = "";

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

void ContactPage::m_setupSaveButton() {
    m_saveButton = new QPushButton("Save", this);

    m_layout->addWidget(m_saveButton);
    m_layout->setAlignment(m_saveButton, Qt::AlignRight);

    // Connect button to QLineEdits
    connect(m_saveButton, &QPushButton::clicked, this, &ContactPage::s_sendFieldsToDB);
}

void ContactPage::viewContact(int contactId) {
    QSqlQuery query(m_db);
    query.prepare("SELECT website, email, password, first_name, last_name, "
                  "phone_number, address_one, address_two "
                  "FROM contacts WHERE id = ?");

    query.addBindValue(contactId);

    // Execute the query
    if (query.exec() && query.next()) {
        m_websiteTextValue     = query.value(0).toString();
        m_emailTextValue       = query.value(1).toString();
        m_passwordTextValue    = query.value(2).toString();
        m_firstNameTextValue   = query.value(3).toString();
        m_lastNameTextValue    = query.value(4).toString();
        m_phoneNumberTextValue = query.value(5).toString();
        m_address1TextValue    = query.value(6).toString();
        m_address2TextValue    = query.value(7).toString();

        m_idTextValue = QString::number(contactId);

        qDebug() << "Viewing Contact ID: " << m_idTextValue;
        m_id->setText(m_idTextValue);
        m_website->setText(m_websiteTextValue);
        m_email->setText(m_emailTextValue);
        m_password->setText(m_passwordTextValue);
        m_firstName->setText(m_firstNameTextValue);
        m_lastName->setText(m_lastNameTextValue);
        m_phoneNumber->setText(m_phoneNumberTextValue);
        m_address1->setText(m_address1TextValue);
        m_address2->setText(m_address2TextValue);
    } else {
        qDebug() << "No contact found with ID " << contactId << " or query failed: " << query.lastError().text();
    }
    // re-connect button to QLineEdits
    connect(m_saveButton, &QPushButton::clicked, this, [contactId, this]() { ContactPage::s_sendFieldsToDB(contactId); });
}

void ContactPage::deleteContact(int contactId) {
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM contacts WHERE id = ?");

    query.addBindValue(contactId);

    if (query.exec()) {
        qDebug() << "Contact with ID " << contactId << " has been deleted.";
    } else {
        qDebug() << "Failed to delete contact with ID " << contactId << ": " << query.lastError().text();
    }
}

// SLOTS

void ContactPage::s_sendFieldsToDB(int contactId) {
    // When the button is clicked, retrieve the text from the QLineEdits
    QString   m_websiteField     = m_website->text();
    QString   m_emailField       = m_email->text();
    QString   m_passwordField    = m_password->text();
    QString   m_firstNameField   = m_firstName->text();
    QString   m_lastNameField    = m_lastName->text();
    QString   m_phoneNumberField = m_phoneNumber->text();
    QString   m_address1Field    = m_address1->text();
    QString   m_address2Field    = m_address2->text();

    QSqlQuery query(m_db);
    if (contactId == 0) {
        query.prepare("INSERT INTO contacts (website, email, password, first_name, "
                      "last_name, phone_number, address_one, address_two) VALUES"
                      "(?, ?, ?, ?, ?, ?, ?, ?)");
        query.addBindValue(m_websiteField);
        query.addBindValue(m_emailField);
        query.addBindValue(m_passwordField);
        query.addBindValue(m_firstNameField);
        query.addBindValue(m_lastNameField);
        query.addBindValue(m_phoneNumberField);
        query.addBindValue(m_address1Field);
        query.addBindValue(m_address2Field);
    } else {
        // clang-format off
	query.prepare("UPDATE contacts SET website = ?, email = ?, password = ?, first_name = ?, "
				  "last_name = ?, phone_number = ?, address_one = ?, address_two = ? "
				  "WHERE id = ?");
        // clang-format on
        query.addBindValue(m_websiteField);
        query.addBindValue(m_emailField);
        query.addBindValue(m_passwordField);
        query.addBindValue(m_firstNameField);
        query.addBindValue(m_lastNameField);
        query.addBindValue(m_phoneNumberField);
        query.addBindValue(m_address1Field);
        query.addBindValue(m_address2Field);
        query.addBindValue(contactId);
    }

    if (!query.exec()) {
        qDebug() << "Error: Failed to insert contact to database" << query.lastError().text();
        QMessageBox::warning(this, "Error!", "Error: Failed to insert contact to database");
    } else {
        qDebug() << "Sent contact fields to db";
    }
}

void ContactPage::s_togglePasswordVisibility(QAction* togglePasswordVisibility) {
    if (!m_passwordIsShown) {
        m_password->setEchoMode(QLineEdit::Normal);
        togglePasswordVisibility->setIcon(QIcon("../assets/eye-solid.png"));

        m_passwordIsShown = true;
    } else {
        m_password->setEchoMode(QLineEdit::Password);
        togglePasswordVisibility->setIcon(QIcon("../assets/eye-slash-solid.png"));

        m_passwordIsShown = false;
    }
}
