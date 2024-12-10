#include "login.h"
#include "logo.h"
#include <QDebug>
#include <QDialog>
#include <QFont>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

// This is used when we know aether.db was created
Login::Login(QWidget *parent) : QWidget(parent) {
  // Create a dialog for the login popup
  m_loginDialog = new QDialog(this);
  m_loginDialog->setWindowTitle("Login");
  m_loginDialog->setFixedSize(400, 300);

  // Init layouts and widgets
  m_authLayout = new QVBoxLayout(m_loginDialog);
  m_logo = new Logo(m_loginDialog);

  m_usernameField = new QLineEdit(m_loginDialog);
  m_passwordField = new QLineEdit(m_loginDialog);

  m_loginButton = new QPushButton("Login", m_loginDialog);

  // Config
  m_usernameField->setPlaceholderText("Username");
  m_passwordField->setPlaceholderText("Password");
  m_passwordField->setEchoMode(QLineEdit::Password);

  // Add widgets to the layout
  m_authLayout->addLayout(m_logo->getLayout());
  m_authLayout->addWidget(m_usernameField);
  m_authLayout->addWidget(m_passwordField);
  m_authLayout->addWidget(m_loginButton);

  // Connect Button
  connect(m_loginButton, &QPushButton::clicked, this, [this]() {
    this->m_usernameInput = m_usernameField->text();
    this->m_passwordInput = m_passwordField->text();
    m_loginDialog->accept();
  });
}

Login::~Login() {
  delete m_loginDialog;
  qDebug() << "Login destructed";
}

int Login::exec() const { return m_loginDialog->exec(); }

QString Login::getUsername() const { return this->m_usernameInput; }
QString Login::getPassword() const { return this->m_passwordInput; }
