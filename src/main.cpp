#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton button ("Sample button in learning Qt");
    button.setToolTip("This program works. Use it to learn more.");
    button.show();
    return app.exec();
}