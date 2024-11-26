#ifndef CONTACTPAGE_H
#define CONTACTPAGE_H

#include <QWidget>
#include <QtSql>

class QLineEdit;
class QLabel;
class QVBoxLayout;
class QPushButton;

class ContactPage : public QWidget {
public:
  explicit ContactPage(QWidget *parent = 0);
  ~ContactPage();

  QVBoxLayout *getLayout();
  void closeDatabase();

private:
  QSqlDatabase db;
  QSqlQuery query;

  QString configDir;
  QString dbName;

  QVBoxLayout *m_layout;

  QLineEdit *m_id;
  QLabel *m_idLabel;

  QLineEdit *m_website;
  QLineEdit *m_email;
  QLineEdit *m_password;
  QLineEdit *m_firstName;
  QLineEdit *m_lastName;
  QLineEdit *m_phoneNumber;
  QLineEdit *m_address1;
  QLineEdit *m_address2;

  QString m_websiteField;
  QString m_emailField;
  QString m_passwordField;
  QString m_firstNameField;
  QString m_lastNameField;
  QString m_phoneNumberField;
  QString m_address1Field;
  QString m_address2Field;

  QPushButton *m_saveButton;

  void setupInputFields();
  void setupSaveButton();
};
#endif // CONTACTPAGE_H
