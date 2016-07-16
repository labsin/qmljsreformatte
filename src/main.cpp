#include <QCoreApplication>
#include <QCommandLineParser>
#include <QString>
#include <QStringList>
#include <QTimer>
#include <QList>
#include <QFile>
#include <QTextStream>

#include "qmljs/qmljsdocument.h"
#include "qmljs/qmljsreformatter.h"
#include "qmljs/parser/qmljsengine_p.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("qmljsreformatter");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("QML Reformatter");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("source", QCoreApplication::translate("main", "Source file to copy."));
    parser.addPositionalArgument("destination", QCoreApplication::translate("main", "Destination file to save."));

    // Process the actual command line arguments given by the user
    parser.process(app);

    const QStringList args = parser.positionalArguments();
    if(args.length() < 2) {
        qInfo() << "no source or destination file given";
        return 1;
    }
    QString source = args.at(0);
    QString dest = args.at(1);
    QTimer::singleShot(0, Q_NULLPTR, [&]{
                QString contents;
                QFile inFile(source);

                if (inFile.open(QIODevice::ReadOnly)) {
                    QTextStream ins(&inFile);
                    contents = ins.readAll();
                    inFile.close();
                }
                else {
                    qDebug() << "couldn't open input file";
                    app.exit(2);
                }
                QmlJS::Document::MutablePtr doc = QmlJS::Document::create(source, QmlJS::Dialect(QmlJS::Dialect::Qml));
                doc->setEditorRevision(0);
                doc->setSource(contents);
                bool success = doc->parse();
                if(!success) {
                    qDebug() << "doc parse error";
                    for(auto msg : doc->diagnosticMessages()) {
                        qDebug() << msg.loc.startLine + ":" + msg.loc.startColumn << ":" << msg.message;
                    }
                    app.exit(3);
                }
                QString output = QmlJS::reformat(doc);
                QFile outFile(dest);
                if (outFile.open(QIODevice::WriteOnly)) {
                    QTextStream outs(&outFile);
                    outs << output;
                    outFile.close();
                }
                else {
                    qDebug() << "couldn't open output file";
                    app.exit(4);
                }
                app.exit(0);
            });

	return app.exec();
}
