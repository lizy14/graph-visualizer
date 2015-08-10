/********************************************************************************
** Form generated from reading UI file 'documentviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCUMENTVIEWER_H
#define UI_DOCUMENTVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_documentViewer
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *boxID;
    QTextEdit *boxDocument;

    void setupUi(QMainWindow *documentViewer)
    {
        if (documentViewer->objectName().isEmpty())
            documentViewer->setObjectName(QStringLiteral("documentViewer"));
        documentViewer->resize(619, 532);
        centralWidget = new QWidget(documentViewer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        boxID = new QLineEdit(centralWidget);
        boxID->setObjectName(QStringLiteral("boxID"));

        horizontalLayout->addWidget(boxID);


        verticalLayout->addLayout(horizontalLayout);

        boxDocument = new QTextEdit(centralWidget);
        boxDocument->setObjectName(QStringLiteral("boxDocument"));

        verticalLayout->addWidget(boxDocument);

        documentViewer->setCentralWidget(centralWidget);

        retranslateUi(documentViewer);

        QMetaObject::connectSlotsByName(documentViewer);
    } // setupUi

    void retranslateUi(QMainWindow *documentViewer)
    {
        documentViewer->setWindowTitle(QApplication::translate("documentViewer", "DocumentContent Viewer", 0));
        label->setText(QApplication::translate("documentViewer", "Find a document using it's ID: ", 0));
    } // retranslateUi

};

namespace Ui {
    class documentViewer: public Ui_documentViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCUMENTVIEWER_H
