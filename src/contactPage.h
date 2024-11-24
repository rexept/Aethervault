#ifndef CONTACTPAGE_H
#define CONTACTPAGE_H

#include <QWidget>

class QLineEdit;
class QLabel;
class QVBoxLayout;

class ContactPage : public QWidget {
public:
  explicit ContactPage(QWidget *parent = 0);

  QVBoxLayout *getLayout();

private:
  QVBoxLayout *m_layout;
  QLineEdit *m_website;
  QLineEdit *m_email;
  QLineEdit *m_password;
  QLineEdit *m_firstName;
  QLineEdit *m_lastName;
  QLineEdit *m_phoneNumber;
  QLineEdit *m_address1;
  QLineEdit *m_address2;

  void setupInputFields();
};

/// This creates a save button for the contact page fields
class SaveButton : public QWidget {
public:
  explicit SaveButton(QWidget *parent = 0);
};
#endif // CONTACTPAGE_H
