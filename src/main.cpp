#include "login.h"
#include "window.h"
#include <QApplication>
#include <QDebug>
#include <QDialog>

int main(int argc, char **argv) {
  const QString NAME = "Aethervault";
  const QString VERSION = "0.0.1";

  QApplication app(argc, argv);
  app.setApplicationName(NAME);
  app.setApplicationVersion(VERSION);

  Login login;
  // Make sure login button is clicked
  if (login.exec()) {
    Window *window = new Window(login.getUsername(), login.getPassword());
    window->show();
  } else {
    qDebug() << "Login failed or cancelled.";
    app.quit();
    return 1;
  }

  return app.exec();
}
