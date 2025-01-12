#pragma once

#include <QWidget>

class QVBoxLayout;
class QHBoxLayout;
class QLineEdit;
class QLabel;
class QPushButton;
class QDialog;
class Logo;

class Login : public QWidget {
  public:
    explicit Login(QWidget* parent = 0);
    ~Login();

    int     exec() const;
    QString getUsername() const;
    QString getPassword() const;

  private:
    QVBoxLayout* m_authLayout;

    QDialog*     m_loginDialog;
    QLabel*      m_loginText;

    QLabel*      m_errorLabel;

    Logo*        m_logo;

    QPushButton* m_loginButton;

    QLineEdit*   m_usernameField;
    QLineEdit*   m_passwordField;

    QString      m_usernameInput;
    QString      m_passwordInput;
};
