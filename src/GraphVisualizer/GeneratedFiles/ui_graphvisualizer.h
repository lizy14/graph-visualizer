/********************************************************************************
** Form generated from reading UI file 'graphvisualizer.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHVISUALIZER_H
#define UI_GRAPHVISUALIZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphVisualizerClass
{
public:
    QAction *actionTopicGraph;
    QAction *actionPaperConferenceAuthorGraph;
    QAction *actionAbout;
    QAction *actionDocumentContent;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *btnUp;
    QPushButton *btnLeft;
    QPushButton *btnZoomIn;
    QPushButton *btnRight;
    QPushButton *btnDown;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnReset;
    QPushButton *btnZoomOut;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QComboBox *comboBoxTheme;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QSlider *radiusSlider;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QSlider *widthSlider;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QSlider *fontSizeSlider;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSlider *degreeSlider;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuAbout;
    QMenu *menuTools;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GraphVisualizerClass)
    {
        if (GraphVisualizerClass->objectName().isEmpty())
            GraphVisualizerClass->setObjectName(QStringLiteral("GraphVisualizerClass"));
        GraphVisualizerClass->resize(766, 600);
        GraphVisualizerClass->setMouseTracking(true);
        actionTopicGraph = new QAction(GraphVisualizerClass);
        actionTopicGraph->setObjectName(QStringLiteral("actionTopicGraph"));
        actionPaperConferenceAuthorGraph = new QAction(GraphVisualizerClass);
        actionPaperConferenceAuthorGraph->setObjectName(QStringLiteral("actionPaperConferenceAuthorGraph"));
        actionAbout = new QAction(GraphVisualizerClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionDocumentContent = new QAction(GraphVisualizerClass);
        actionDocumentContent->setObjectName(QStringLiteral("actionDocumentContent"));
        centralWidget = new QWidget(GraphVisualizerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMouseTracking(true);
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(16777215, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btnUp = new QPushButton(centralWidget);
        btnUp->setObjectName(QStringLiteral("btnUp"));
        btnUp->setEnabled(true);
        btnUp->setMinimumSize(QSize(40, 40));
        btnUp->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(btnUp, 0, 1, 1, 1);

        btnLeft = new QPushButton(centralWidget);
        btnLeft->setObjectName(QStringLiteral("btnLeft"));
        btnLeft->setMinimumSize(QSize(40, 40));
        btnLeft->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(btnLeft, 1, 0, 1, 1);

        btnZoomIn = new QPushButton(centralWidget);
        btnZoomIn->setObjectName(QStringLiteral("btnZoomIn"));
        btnZoomIn->setMinimumSize(QSize(40, 40));
        btnZoomIn->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(btnZoomIn, 0, 4, 1, 1);

        btnRight = new QPushButton(centralWidget);
        btnRight->setObjectName(QStringLiteral("btnRight"));
        btnRight->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(btnRight, 1, 2, 1, 1);

        btnDown = new QPushButton(centralWidget);
        btnDown->setObjectName(QStringLiteral("btnDown"));
        btnDown->setMinimumSize(QSize(40, 40));
        btnDown->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(btnDown, 2, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));

        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        btnReset = new QPushButton(centralWidget);
        btnReset->setObjectName(QStringLiteral("btnReset"));
        btnReset->setMinimumSize(QSize(40, 40));
        btnReset->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(btnReset, 2, 3, 1, 1);

        btnZoomOut = new QPushButton(centralWidget);
        btnZoomOut->setObjectName(QStringLiteral("btnZoomOut"));
        btnZoomOut->setMaximumSize(QSize(40, 40));

        gridLayout->addWidget(btnZoomOut, 2, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_6);

        comboBoxTheme = new QComboBox(centralWidget);
        comboBoxTheme->setObjectName(QStringLiteral("comboBoxTheme"));

        horizontalLayout_2->addWidget(comboBoxTheme);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        radiusSlider = new QSlider(centralWidget);
        radiusSlider->setObjectName(QStringLiteral("radiusSlider"));
        radiusSlider->setMinimum(20);
        radiusSlider->setValue(60);
        radiusSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(radiusSlider);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_7->addWidget(label_4);

        widthSlider = new QSlider(centralWidget);
        widthSlider->setObjectName(QStringLiteral("widthSlider"));
        widthSlider->setValue(20);
        widthSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(widthSlider);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_8->addWidget(label_5);

        fontSizeSlider = new QSlider(centralWidget);
        fontSizeSlider->setObjectName(QStringLiteral("fontSizeSlider"));
        fontSizeSlider->setMinimum(6);
        fontSizeSlider->setMaximum(20);
        fontSizeSlider->setValue(12);
        fontSizeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(fontSizeSlider);


        verticalLayout->addLayout(horizontalLayout_8);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_3->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_2);

        degreeSlider = new QSlider(centralWidget);
        degreeSlider->setObjectName(QStringLiteral("degreeSlider"));
        degreeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(degreeSlider);


        verticalLayout->addLayout(horizontalLayout);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        verticalLayout->setStretch(8, 1);

        horizontalLayout_4->addLayout(verticalLayout);

        GraphVisualizerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GraphVisualizerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 766, 25));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        GraphVisualizerClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(GraphVisualizerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setAutoFillBackground(true);
        GraphVisualizerClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menu->addAction(actionTopicGraph);
        menu->addAction(actionPaperConferenceAuthorGraph);
        menuAbout->addAction(actionAbout);
        menuTools->addAction(actionDocumentContent);

        retranslateUi(GraphVisualizerClass);

        QMetaObject::connectSlotsByName(GraphVisualizerClass);
    } // setupUi

    void retranslateUi(QMainWindow *GraphVisualizerClass)
    {
        GraphVisualizerClass->setWindowTitle(QApplication::translate("GraphVisualizerClass", "GraphVisualizer", 0));
        actionTopicGraph->setText(QApplication::translate("GraphVisualizerClass", "TopicGraph", 0));
#ifndef QT_NO_STATUSTIP
        actionTopicGraph->setStatusTip(QApplication::translate("GraphVisualizerClass", "Load a TopicGraph from file.", 0));
#endif // QT_NO_STATUSTIP
        actionPaperConferenceAuthorGraph->setText(QApplication::translate("GraphVisualizerClass", "PaperConferenceAuthorGraph", 0));
#ifndef QT_NO_STATUSTIP
        actionPaperConferenceAuthorGraph->setStatusTip(QApplication::translate("GraphVisualizerClass", "Load a PaperConferenceAuthorGraph from file.", 0));
#endif // QT_NO_STATUSTIP
        actionAbout->setText(QApplication::translate("GraphVisualizerClass", "About...", 0));
#ifndef QT_NO_STATUSTIP
        actionAbout->setStatusTip(QApplication::translate("GraphVisualizerClass", "About this application.", 0));
#endif // QT_NO_STATUSTIP
        actionDocumentContent->setText(QApplication::translate("GraphVisualizerClass", "DocumentContent", 0));
#ifndef QT_NO_STATUSTIP
        btnUp->setStatusTip(QApplication::translate("GraphVisualizerClass", "Move view upwards.", 0));
#endif // QT_NO_STATUSTIP
        btnUp->setText(QApplication::translate("GraphVisualizerClass", "\342\206\221", 0));
#ifndef QT_NO_STATUSTIP
        btnLeft->setStatusTip(QApplication::translate("GraphVisualizerClass", "Move view leftwards.", 0));
#endif // QT_NO_STATUSTIP
        btnLeft->setText(QApplication::translate("GraphVisualizerClass", "\342\206\220", 0));
#ifndef QT_NO_TOOLTIP
        btnZoomIn->setToolTip(QApplication::translate("GraphVisualizerClass", "Zoom in", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnZoomIn->setStatusTip(QApplication::translate("GraphVisualizerClass", "Zoom in.", 0));
#endif // QT_NO_STATUSTIP
        btnZoomIn->setText(QApplication::translate("GraphVisualizerClass", "+", 0));
#ifndef QT_NO_STATUSTIP
        btnRight->setStatusTip(QApplication::translate("GraphVisualizerClass", "Move view rightwards.", 0));
#endif // QT_NO_STATUSTIP
        btnRight->setText(QApplication::translate("GraphVisualizerClass", "\342\206\222", 0));
#ifndef QT_NO_STATUSTIP
        btnDown->setStatusTip(QApplication::translate("GraphVisualizerClass", "Move view downwards.", 0));
#endif // QT_NO_STATUSTIP
        btnDown->setText(QApplication::translate("GraphVisualizerClass", "\342\206\223", 0));
#ifndef QT_NO_STATUSTIP
        btnReset->setStatusTip(QApplication::translate("GraphVisualizerClass", "Reset view.", 0));
#endif // QT_NO_STATUSTIP
        btnReset->setText(QApplication::translate("GraphVisualizerClass", "R", 0));
#ifndef QT_NO_TOOLTIP
        btnZoomOut->setToolTip(QApplication::translate("GraphVisualizerClass", "Zoom out", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        btnZoomOut->setStatusTip(QApplication::translate("GraphVisualizerClass", "Zoom out.", 0));
#endif // QT_NO_STATUSTIP
        btnZoomOut->setText(QApplication::translate("GraphVisualizerClass", "-", 0));
        label_6->setText(QApplication::translate("GraphVisualizerClass", "Color Theme", 0));
#ifndef QT_NO_STATUSTIP
        comboBoxTheme->setStatusTip(QApplication::translate("GraphVisualizerClass", "Choose theme for coloring.", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        label_3->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        label_3->setText(QApplication::translate("GraphVisualizerClass", "Node Radius", 0));
#ifndef QT_NO_STATUSTIP
        radiusSlider->setStatusTip(QApplication::translate("GraphVisualizerClass", "Decide radius of nodes in the graph.", 0));
#endif // QT_NO_STATUSTIP
        label_4->setText(QApplication::translate("GraphVisualizerClass", "Edge Width ", 0));
#ifndef QT_NO_STATUSTIP
        widthSlider->setStatusTip(QApplication::translate("GraphVisualizerClass", "Decide width of edges in the graph.", 0));
#endif // QT_NO_STATUSTIP
        label_5->setText(QApplication::translate("GraphVisualizerClass", "Font Size  ", 0));
#ifndef QT_NO_STATUSTIP
        fontSizeSlider->setStatusTip(QApplication::translate("GraphVisualizerClass", "Adjust font size.", 0));
#endif // QT_NO_STATUSTIP
        label->setText(QApplication::translate("GraphVisualizerClass", "Layout", 0));
#ifndef QT_NO_STATUSTIP
        comboBox->setStatusTip(QApplication::translate("GraphVisualizerClass", "Choose layout strategy.", 0));
#endif // QT_NO_STATUSTIP
        label_2->setText(QApplication::translate("GraphVisualizerClass", "Filter", 0));
#ifndef QT_NO_STATUSTIP
        degreeSlider->setStatusTip(QApplication::translate("GraphVisualizerClass", "Adjust degree filter. ", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        textEdit->setStatusTip(QApplication::translate("GraphVisualizerClass", "Node details.", 0));
#endif // QT_NO_STATUSTIP
        menu->setTitle(QApplication::translate("GraphVisualizerClass", "Load", 0));
        menuAbout->setTitle(QApplication::translate("GraphVisualizerClass", "About", 0));
        menuTools->setTitle(QApplication::translate("GraphVisualizerClass", "Tools", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphVisualizerClass: public Ui_GraphVisualizerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHVISUALIZER_H
