#include <QApplication>
#include <QTextCodec>

/**
 * @brief Lanceur de l'application.
 */
int main(int argc, char *argv[])
{
    /*
     * These line are used to fix character encoding problems of compatibility with older
     * version of Qt (< v4). If you own a Qt version 5 or more please let these line commented.
    */
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QApplication app(argc, argv);

    // Create Observer, subject, etc.

    return app.exec();
}

