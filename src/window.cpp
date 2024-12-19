#include "window.h"
#include "contactPage.h"
#include "logo.h"

#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QStackedWidget>
#include <QString>
#include <QVBoxLayout>

Window::Window(QString dbUsername, QString dbPassword, QWidget* parent) : QWidget(parent) {
    // Init layouts and widgets
    m_masterLayout  = new QVBoxLayout();
    m_stackedWidget = new QStackedWidget(this);
    m_contactPage   = new ContactPage(dbUsername, dbPassword);
    m_logo          = new Logo();

    // Add layouts and widgets to master layout
    m_stackedWidget->addWidget(m_contactPage);

    m_masterLayout->addLayout(m_logo->getLayout());
    m_masterLayout->addWidget(m_stackedWidget);

    setLayout(m_masterLayout);
}

Window::~Window() {
    m_contactPage->closeDatabase();
    // Redundant? Does QT know to delete because of window.show()
    delete m_masterLayout;
    delete m_stackedWidget;
    qDebug() << "Window destructed";
}
