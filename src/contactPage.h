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
    explicit ContactPage(QString dbUsername, QString dbPassword, QWidget* parent = 0);
    virtual ~ContactPage();

    QVBoxLayout* getLayout() const;
    void         closeDatabase();

    void         viewContact(int contactId);
    void         deleteContact(int contactId);

  private:
    QSqlDatabase m_db;

    QString      m_configDir;
    QString      m_dbName;

    QVBoxLayout* m_layout;
    bool         m_passwordIsShown;

    QLineEdit*   m_id;

    QLineEdit*   m_website;
    QLineEdit*   m_email;
    QLineEdit*   m_password;
    QLineEdit*   m_firstName;
    QLineEdit*   m_lastName;
    QLineEdit*   m_phoneNumber;
    QLineEdit*   m_address1;
    QLineEdit*   m_address2;

    QString      m_idTextValue;
    QString      m_websiteTextValue;
    QString      m_emailTextValue;
    QString      m_passwordTextValue;
    QString      m_firstNameTextValue;
    QString      m_lastNameTextValue;
    QString      m_phoneNumberTextValue;
    QString      m_address1TextValue;
    QString      m_address2TextValue;

    QPushButton* m_saveButton;

    void         m_setupInputFields();
    void         m_setupSaveButton();

  public slots:
    // Is that a naming convention? - s_
    void s_sendFieldsToDB(int contactId = 0);
    void s_togglePasswordVisibility(QAction* togglePasswordVisibilty);
};
#endif // CONTACTPAGE_H
