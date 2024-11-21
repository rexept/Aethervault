#include <QWidget>

class QLineEdit;
class QLabel;
class QVBoxLayout;

class ContactPage : public QWidget {
public:
  explicit ContactPage(QWidget *parent = 0);

  QVBoxLayout *get_layout();

private:
  QVBoxLayout *m_layout;
  QLineEdit *m_website;
  QLineEdit *m_email;
  QLineEdit *m_password;
  QLineEdit *m_name;

  void setup_widgets();
};