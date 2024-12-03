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
  explicit ContactPage(QString dbUsername, QString dbPassword,
                       QWidget *parent = 0);
  ~ContactPage();

  QVBoxLayout *getLayout() const;
  void closeDatabase();

private:
  QSqlDatabase db;

  QString configDir;
  QString dbName;

  QVBoxLayout *m_layout;
  bool passwordIsShown;

  QLineEdit *m_id;

  QLineEdit *m_website;
  QLineEdit *m_email;
  QLineEdit *m_password;
  QLineEdit *m_firstName;
  QLineEdit *m_lastName;
  QLineEdit *m_phoneNumber;
  QLineEdit *m_address1;
  QLineEdit *m_address2;

  void setupInputFields();
  void setupSaveButton();
};
#endif // CONTACTPAGE_H
