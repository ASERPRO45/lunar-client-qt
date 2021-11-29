//
// Created by nils on 11/4/21.
//

#ifndef LUNAR_CLIENT_QT_MAINWINDOW_H
#define LUNAR_CLIENT_QT_MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QComboBox>
#include <QStandardPaths>

#include "launch/offlinelauncher.h"
#include "launch/launcher.h"
#include "pages/configurationpage.h"
#include "pages/generalpage.h"
#include "pages/agentspage.h"

class MainWindow : public QMainWindow {
Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    void load();
    void save();

    void launch(Launcher& launcher, bool cosmetics = true);

    void closeEvent(QCloseEvent* closeEvent) override;
private slots:
    void resetLaunchButtons();
    void launchOffline();
    void launchNoCosmetics();
    void errorCallback(const QString& message);
private:
    QListWidget* pageList;
    QStackedWidget* pageStack;
    QPushButton* launchNoCosmeticsButton;
    QPushButton* launchOfflineButton;
    QComboBox* versionSelect;

    GeneralPage* generalPage;
    AgentsPage* agentsPage;

    OfflineLauncher offlineLauncher;

    static const QString configLocation;
};


#endif //LUNAR_CLIENT_QT_MAINWINDOW_H
