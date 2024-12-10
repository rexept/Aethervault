#ifndef CONTACTPAGE_H
#define CONTACTPAGE_H

#include <QWidget>
#include <QtSql>

class QLineEdit;
class QLabel;
class QVBoxLayout;
class QPushButton;

class ContactPage : public QWidget {
  // ADD THE OBJECT BACK! - vtable error tho
  /* Q_OBJECT */

public:
  explicit ContactPage(QString dbUsername, QString dbPassword,
                       QWidget *parent = 0);
  virtual ~ContactPage();

  QVBoxLayout *getLayout() const;
  void closeDatabase();

  void openViewContactPage();

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

public slots:
  // Is that a naming convention? - s_
  void s_sendFieldsToDB();
  void s_togglePasswordVisibility(QAction *togglePasswordVisibilty);
};
#endif // CONTACTPAGE_H
