#include "window.h"
#include <QApplication>

int main(int argc, char **argv) {
  const QString NAME = "Aethervault";
  const QString VERSION = "0.0.1";

  QApplication app(argc, argv);
  app.setApplicationName(NAME);
  app.setApplicationVersion(VERSION);

  Window window;
  window.show();

  return app.exec();
}
