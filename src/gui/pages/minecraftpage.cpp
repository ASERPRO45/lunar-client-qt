//
// Created by nils on 12/2/21.
//

#include "minecraftpage.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>

MinecraftPage::MinecraftPage(Config &config, QWidget *parent) : ConfigurationPage(config, parent) {
    customMinecraftDir = new QCheckBox(QStringLiteral("Custom .minecraft directory"));

    minecraftPathChooser = new FileChooser(FileChooser::FileType::FOLDER);
    minecraftPathChooser->setDisabled(true);

    connect(customMinecraftDir, &QCheckBox::toggled, minecraftPathChooser, &QLineEdit::setEnabled);

    //Custom jre groups
    QVBoxLayout* customMCPathContainer = new QVBoxLayout();
    customMCPathContainer->setSpacing(6);
    customMCPathContainer->addWidget(customMinecraftDir, 0, Qt::AlignHCenter);
    customMCPathContainer->addWidget(minecraftPathChooser);

    windowWidth = new QSpinBox();
    windowHeight = new QSpinBox();

    windowWidth->setMinimum(0);
    windowWidth->setMaximum(99999);

    windowHeight->setMinimum(0);
    windowHeight->setMaximum(99999);

    QHBoxLayout* windowResContainer = new QHBoxLayout();
    windowResContainer->setSpacing(30);
    windowResContainer->addWidget(new QLabel(QStringLiteral("Window width")));
    windowResContainer->addWidget(windowWidth, 1);
    windowResContainer->addWidget(new QLabel(QStringLiteral("Window height")));
    windowResContainer->addWidget(windowHeight, 1);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->setSpacing(40);
    mainLayout->addLayout(customMCPathContainer);
    mainLayout->addLayout(windowResContainer);
    mainLayout->addStretch(1);

    setLayout(mainLayout);
}

QString MinecraftPage::title() {
    return QStringLiteral("Minecraft");
}

QIcon MinecraftPage::icon() {
    return QIcon(":/res/icons/minecraft.svg");
}

void MinecraftPage::apply() {
    config.windowWidth = windowWidth->value();
    config.windowHeight = windowHeight->value();
}

void MinecraftPage::load() {
    windowWidth->setValue(config.windowWidth);
    windowHeight->setValue(config.windowHeight);
}







