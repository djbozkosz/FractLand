//------------------------------------------------------------------------------
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include <QUrl>
#include <QFileInfo>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QRegExp>
#include <QMenu>
#include <QMenuBar>
#include <QTabBar>
#include <QLabel>
#include <QCheckBox>
#include <QRadioButton>
#include <QDesktopServices>

#include "ui_mainWindow.h"
#include "engine.h"

//------------------------------------------------------------------------------
namespace NMainWindow
{
  static const uint32 GRID_DIV_SIZES[11] = { 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6 };

  static const char STR_NO_TEXTURE[] = "< no texture >";
}

namespace Ui
{
  class CMainWindow;
}
//------------------------------------------------------------------------------
class CMainWindow : public QMainWindow
{
  private:
    Q_OBJECT

    Ui::CMainWindow *ui;
    QStringList styleDefault;

    //QTabBar *tbRightShow;
    QMenu mnRight;

    QVector<SMaterialLayer> terrainLayers;
    bool dialogFirstTime;
    QString dialogPath;
    QString fileOpened;

    QColorDialog colorDialog;

    SSceneObject getSceneObjectTerrain();
    STerrain getTerrain();
    SSceneObject getSceneObjectWater();
    SWater getWater();

    void getColor(const QVector4D &color, QPushButton *pb, QDoubleSpinBox *ds);
    QVector4D getColor2(QPushButton *pb, QDoubleSpinBox *ds);

  public:
    explicit CMainWindow(QWidget *parent = NULL);
    ~CMainWindow();

    void updateStyle(const float scale, bool inverse);

  public slots:
    void initGui();

    void updateTerrain(int index);
    void updateTerrainParameters(int index);
    void updateTerrainLayers(int index);
    void terrainLayerApply();
    void addTerrain();
    void delTerrain();
    void addTerrainInsert();
    void addTerrainCancel();
    void terrainApply();
    void addTerrainLayer();
    void delTerrainLayer();
    void moveUpTerrainLayer();
    void moveDownTerrainLayer();
    void terrainBlockSignals(bool signal);

    void updateWater(int index);
    void updateWaterParameters(int index);
    void addWater();
    void delWater();
    void addWaterInsert();
    void addWaterCancel();
    void waterApply();
    void waterBlockSignals(bool signal);

    void updateEnvironment();
    void environmentApply();
    void environmentBlockSignals(bool signal);

    void pickColor();
    void selectPathImageDialog();

    void newScene();
    void openScene();
    void saveScene();
    void saveAsScene();
    void loadSceneFile();
    void saveSceneFile();

    void showHelp();
    void showInfo();

    void showRightMenu();
    void showRightPanel();
};
//------------------------------------------------------------------------------
#endif // MAINWINDOW_H
