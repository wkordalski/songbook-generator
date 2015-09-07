#include <QApplication>
#include <QPushButton>
#include "model.hpp"
#include "window.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Cantionale::Model model(nullptr);
    Cantionale::Window wnd(model);
    wnd.show();
    return app.exec();
}