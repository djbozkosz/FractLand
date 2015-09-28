/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created: Tue 7. Jul 02:32:39 2015
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <src/engine.h>

QT_BEGIN_NAMESPACE

class Ui_CMainWindow
{
public:
    QAction *acNew;
    QAction *acOpen;
    QAction *acSave;
    QAction *acSaveAs;
    QAction *acExit;
    QAction *acAddTerrain;
    QAction *acAddWater;
    QAction *acDeleteTerrain;
    QAction *acViewHelp;
    QAction *acAbout;
    QAction *acDeleteWater;
    QWidget *wgCentral;
    QHBoxLayout *hlCentral;
    CEngine *wgView;
    QTabWidget *tbRight;
    QWidget *twTerrain;
    QVBoxLayout *vlTerrain;
    QScrollArea *saTerrain;
    QWidget *swTerrain;
    QFormLayout *flTerrain;
    QGroupBox *gbTerrainList;
    QFormLayout *flTerrainList;
    QListWidget *lwTerrainList;
    QGroupBox *gbTerrainParameters;
    QFormLayout *flTerrainParameters;
    QLabel *lbTerrainName;
    QLineEdit *leTerrainName;
    QLabel *lbTerrainPosition;
    QFrame *frTerrainPosition;
    QHBoxLayout *hlTerrainPosition;
    QDoubleSpinBox *dsTerrainPosX;
    QDoubleSpinBox *dsTerrainPosY;
    QDoubleSpinBox *dsTerrainPosZ;
    QLabel *lbTerrainRotation;
    QFrame *frTerrainRotation;
    QHBoxLayout *hlTerrainRotation;
    QDoubleSpinBox *dsTerrainRotX;
    QDoubleSpinBox *dsTerrainRotY;
    QDoubleSpinBox *dsTerrainRotZ;
    QLabel *lbTerrainScale;
    QFrame *frTerrainScale;
    QHBoxLayout *hlTerrainScale;
    QDoubleSpinBox *dsTerrainScaleX;
    QDoubleSpinBox *dsTerrainScaleY;
    QDoubleSpinBox *dsTerrainScaleZ;
    QFrame *frTerrainSep00;
    QCheckBox *cbTerrainSeed;
    QSpinBox *sbTerrainSeed;
    QLabel *lbTerrainGrid;
    QComboBox *cbTerrainGrid;
    QCheckBox *cbTerrainLand;
    QLabel *lbTerrainHeightMul;
    QDoubleSpinBox *dsTerrainHeightMul;
    QLabel *lbTerrainDepthMul;
    QDoubleSpinBox *dsTerrainDepthMul;
    QLabel *lbTerrainHeightMod1;
    QDoubleSpinBox *dsTerrainHeightMod1;
    QLabel *lbTerrainHeightMod2;
    QDoubleSpinBox *dsTerrainHeightMod2;
    QFrame *frTerrainSep01;
    QFrame *frTerrainInsert;
    QHBoxLayout *hlTerrainInsert;
    QSpacerItem *hsTerrainInsert;
    QCommandLinkButton *clTerrainApply;
    QGroupBox *gbTerrainLayers;
    QFormLayout *formLayout;
    QFrame *frTerrainLayers;
    QHBoxLayout *hlTerrainLayers;
    QSpacerItem *hsTerrainLayers;
    QPushButton *pbTerrainLayersAdd;
    QPushButton *pbTerrainLayersDel;
    QPushButton *pbTerrainLayersUp;
    QPushButton *pbTerrainLayersDown;
    QListWidget *lwTerrainLayersList;
    QFrame *frTerrainLayersParameters;
    QFormLayout *flTerrainLayersParameters;
    QLabel *lbTerrainLayersColor;
    QFrame *frTerrainLayersColor;
    QHBoxLayout *hlTerrainLayersColor;
    QPushButton *pbTerrainLayersColor;
    QDoubleSpinBox *dsTerrainLayersColorPower;
    QLabel *lbTerrainLayersNormal;
    QFrame *frTerrainLayersNormal;
    QHBoxLayout *hlTerrainLayersNormal;
    QLineEdit *leTerrainLayersNormal;
    QToolButton *tbTerrainLayersNormal;
    QCheckBox *cbTerrainLayersHeight;
    QFrame *frTerrainLayersHeight;
    QHBoxLayout *hlTerrainLayersHeight;
    QSlider *hsTerrainLayersHeightMin;
    QSlider *hsTerrainLayersHeightMax;
    QCheckBox *cbTerrainLayersSlope;
    QFrame *frTerrainLayersSlope;
    QHBoxLayout *hlTerrainLayersSlope;
    QSlider *hsTerrainLayersSlopeMin;
    QSlider *hsTerrainLayersSlopeMax;
    QWidget *twWater;
    QVBoxLayout *vlWater;
    QScrollArea *saWater;
    QWidget *swWater;
    QFormLayout *formLayout_2;
    QGroupBox *gbWaterList;
    QFormLayout *flWaterList;
    QListWidget *lwWaterList;
    QGroupBox *gbWaterParameters;
    QFormLayout *flWaterParameters;
    QLabel *lbWaterName;
    QLineEdit *leWaterName;
    QLabel *lbWaterPosition;
    QFrame *frWaterPosition;
    QHBoxLayout *hlWaterPosition;
    QDoubleSpinBox *dsWaterPosX;
    QDoubleSpinBox *dsWaterPosY;
    QDoubleSpinBox *dsWaterPosZ;
    QLabel *lbWaterRotation;
    QFrame *frWaterRotation;
    QHBoxLayout *hlWaterRotation;
    QDoubleSpinBox *dsWaterRotX;
    QDoubleSpinBox *dsWaterRotY;
    QDoubleSpinBox *dsWaterRotZ;
    QLabel *lbWaterScale;
    QFrame *frWaterScale;
    QHBoxLayout *hlWaterScale;
    QDoubleSpinBox *dsWaterScaleX;
    QDoubleSpinBox *dsWaterScaleY;
    QDoubleSpinBox *dsWaterScaleZ;
    QFrame *frWaterSep00;
    QLabel *lbWaterNormal;
    QFrame *frWaterNormal;
    QHBoxLayout *hlWaterNormal;
    QLineEdit *leWaterNormal;
    QToolButton *tbWaterNormal;
    QLabel *lbWaterGroundNormal;
    QFrame *frWaterGroundNormal;
    QHBoxLayout *hlWaterGroundNormal;
    QLineEdit *leWaterGroundNormal;
    QToolButton *tbWaterGroundNormal;
    QFrame *frWaterSep01;
    QFrame *frWaterInsert;
    QHBoxLayout *hlWaterInsert;
    QSpacerItem *hsWaterInsert;
    QCommandLinkButton *clWaterApply;
    QLabel *lbWaterGroundColor;
    QFrame *frWaterGroundColor;
    QHBoxLayout *hlWaterGroundColor;
    QPushButton *pbWaterGroundColor;
    QDoubleSpinBox *dsWaterGroundColor;
    QLabel *lbWaterDepth;
    QDoubleSpinBox *dsWaterDepth;
    QWidget *twEnvironment;
    QVBoxLayout *vlEnvironment;
    QScrollArea *saEnvironment;
    QWidget *swEnvironment;
    QFormLayout *formLayout_3;
    QGroupBox *gbEnvironmentLighting;
    QFormLayout *flEnvironmentLighting;
    QLabel *lbEnvironmentLightingSunDir;
    QDoubleSpinBox *dsEnvironmentLightingSunDir;
    QLabel *lbEnvironmentLightingSunHeight;
    QDoubleSpinBox *dsEnvironmentLightingSunHeight;
    QLabel *lbEnvironmentLightingSunColor;
    QFrame *frEnvironmentLightingSunColor;
    QHBoxLayout *hlEnvironmentLightingSunColor;
    QPushButton *pbEnvironmentLightingSunColor;
    QDoubleSpinBox *dsEnvironmentLightingSunColorPower;
    QLabel *lbEnvironmentLightingSunSpec;
    QFrame *frEnvironmentLightingSunSpec;
    QHBoxLayout *hlEnvironmentLightingSunSpec;
    QPushButton *pbEnvironmentLightingSunSpec;
    QDoubleSpinBox *dsEnvironmentLightingSunSpecPower;
    QLabel *lbEnvironmentLightingSunSpecPow;
    QDoubleSpinBox *dsEnvironmentLightingSunSpecPow;
    QLabel *lbEnvironmentLightingSkyColor;
    QFrame *frEnvironmentLightingSkyColor;
    QHBoxLayout *hlEnvironmentLightingSkyColor;
    QPushButton *pbEnvironmentLightingSkyColor;
    QDoubleSpinBox *dsEnvironmentLightingSkyColorPower;
    QLabel *lbEnvironmentLightingAmbColor;
    QFrame *frEnvironmentLightingAmbColor;
    QHBoxLayout *hlEnvironmentLightingAmbColor;
    QPushButton *pbEnvironmentLightingAmbColor;
    QDoubleSpinBox *dsEnvironmentLightingAmbColorPower;
    QGroupBox *gbEnvironmentFog;
    QFormLayout *flEnvironmentFog;
    QLabel *lbEnvironmentFogDist;
    QDoubleSpinBox *dsEnvironmentFogDist;
    QLabel *lbEnvironmentFogHeight;
    QDoubleSpinBox *dsEnvironmentFogHeight;
    QLabel *lbEnvironmentFogWaterDist;
    QDoubleSpinBox *dsEnvironmentFogWaterDist;
    QLabel *lbEnvironmentFogWaterHeight;
    QDoubleSpinBox *dsEnvironmentFogWaterHeight;
    QLabel *lbEnvironmentFogColor;
    QLabel *lbEnvironmentFogWaterColor;
    QFrame *frEnvironmentFogColor;
    QHBoxLayout *hlEnvironmentFogColor;
    QPushButton *pbEnvironmentFogColor;
    QDoubleSpinBox *dsEnvironmentFogColorPower;
    QFrame *frEnvironmentFogWaterColor;
    QHBoxLayout *hlEnvironmentFogWaterColor;
    QPushButton *pbEnvironmentFogWaterColor;
    QDoubleSpinBox *dsEnvironmentFogWaterColorPower;
    QLabel *lbEnvironmentFogStart;
    QDoubleSpinBox *dsEnvironmentFogStart;
    QLabel *lbEnvironmentFogWaterStart;
    QDoubleSpinBox *dsEnvironmentFogWaterStart;
    QFrame *frRightShow;
    QVBoxLayout *vlRightShow;
    QSpacerItem *verticalSpacer;
    QPushButton *pbRightMenu;
    QPushButton *pbRightShow;
    QMenuBar *mbMain;
    QMenu *mnFile;
    QMenu *mnObjects;
    QMenu *mnHelp;
    QStatusBar *sbMain;

    void setupUi(QMainWindow *CMainWindow)
    {
        if (CMainWindow->objectName().isEmpty())
            CMainWindow->setObjectName(QString::fromUtf8("CMainWindow"));
        CMainWindow->resize(1200, 600);
        CMainWindow->setStyleSheet(QString::fromUtf8("/*QGroupBox {\n"
"  color: #004080;\n"
"  font-size: 12px;\n"
"}\n"
"QGroupBox::title {\n"
"  subcontrol-origin: margin;\n"
"  padding: 0px 3px 0px 3px;\n"
"}*/\n"
"\n"
"/* version: 2015.06.21 */\n"
"\n"
"QWidget {\n"
"  color: #ffffff;\n"
"  font-size: 22px;\n"
"}\n"
"\n"
"QMainWindow {\n"
"  background-color: #000000;\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_background.png) 0 0 0 0;\n"
"}\n"
"\n"
"QScrollArea, QScrollArea > QWidget > QWidget{\n"
"  background: transparent;\n"
"}\n"
"\n"
"QGroupBox {\n"
"  border-top: 1px solid rgba(255, 255, 255, 128);\n"
"  margin: 15px 0px 0px 0px;\n"
"  padding: 5px 0px 0px 0px;\n"
"}\n"
"QGroupBox::title {\n"
"  subcontrol-position: top center;\n"
"  subcontrol-origin: margin;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"  width: 10000px;\n"
"  height: 48px;\n"
"}\n"
"QTabWidget::pane {\n"
"  border: none;\n"
"}\n"
"\n"
"QMenu, QComboBox QAbstractItemView {\n"
"  background: transparent;\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_popup.png) 7 6 7 6;"
                        "\n"
"  border-width: 7px 6px 7px 6px;\n"
"  padding: 0px -6px 0px -6px;\n"
"}\n"
"QMenu::item, QMenuBar::item, QComboBox QAbstractItemView::item {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_list_popup_normal.png) 0 0 1 0;\n"
"  border-width: 0px 0px 1px 0px;\n"
"  padding: 0px 30px -1px 40px;\n"
"  height: 40px;\n"
"}\n"
"QMenu::item:disabled, QMenuBar::item:disabled, QComboBox QAbstractItemView::item:disabled {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_list_popup_transparent.png) 0 0 1 0;\n"
"  color: rgba(255, 255, 255, 128);\n"
"}\n"
"QMenu::item:selected, QMenuBar::item:selected, QComboBox QAbstractItemView::item:selected {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_list_pressed.png) 0 0 1 0;\n"
"  color: #ffffff;\n"
"}\n"
"QMenu::indicator{\n"
"  left: 4px;\n"
"  width: 32px;\n"
"  height: 32px;\n"
"}\n"
"QMenu::separator{\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_popup_divider.png) 4 12 4 12;\n"
"  border-width: 4px 12px 4px 12px;\n"
"  padding: -4px -12p"
                        "x -4px -12px;\n"
"  height: 10px;\n"
"}\n"
"QMenuBar {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_tab_bar.png) 2 0 2 0;\n"
"  border-width: 2px 0px 2px 0px;\n"
"  height: 40px;\n"
"}\n"
"QMenuBar::item {\n"
"  padding: 0px 20px -1px 20px;\n"
"}\n"
"\n"
"QStatusBar {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_tab_bar.png) 2 0 2 0;\n"
"  border-width: 2px 0px 2px 0px;\n"
"  padding: -2px 0px -2px 0px;\n"
"  height: 40px;\n"
"}\n"
"\n"
"QToolTip {\n"
"  background: transparent;\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_tooltip.png) 20 20 20 20;\n"
"  border-width: 20px 20px 20px 20px;\n"
"  padding: -20px -10px -20px -10px;\n"
"  min-height: 42px;\n"
"  min-width: 22px;\n"
"  color: #ffffff;\n"
"  font-size: 20px;\n"
"}\n"
"\n"
"QTabBar {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_tab_bar.png) 2 0 2 0;\n"
"  border-width: 2px 0px 2px 0px;\n"
"  padding: -2px 0px -2px 0px;\n"
"  font-size: 20px;\n"
"}\n"
"QTabBar::tab {\n"
"  border-image: url(:/images/gui/images/gu"
                        "i/qtg_fr_tab_active.png) 2 1 2 1;\n"
"  border-width: 2px 1px 2px 1px;\n"
"  padding: -2px 19px -2px 19px;\n"
"  height: 48px;\n"
"  min-width: 90px;\n"
"}\n"
"QTabBar::tab:!selected {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_tab_passive_normal.png) 2 1 2 1;\n"
"  color: rgba(255, 255, 255, 128);\n"
"}\n"
"QTabBar::tab:pressed {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_tab_passive_pressed.png) 2 1 2 1;\n"
"}\n"
"QTabBar::tab:disabled {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_background_inverse.png) 0 0 0 0;\n"
"}\n"
"\n"
"QListWidget, QTreeWidget, QTableWidget, QListView, QTreeView, QTableView {\n"
"  background: transparent;\n"
"  border: none;\n"
"}\n"
"QListWidget::item, QTreeWidget::item, QTableWidget::item, QListView::item, QTreeView::item, QTableView::item {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_list_normal.png) 0 0 1 0;\n"
"  border-width: 0px 0px 1px 0px;\n"
"  padding: 0px 20px -1px 20px;\n"
"  height: 50px;\n"
"}\n"
"QListWidget::item:disabl"
                        "ed, QTreeWidget::item:disabled, QTableWidget::item:disabled, QListView::item:disabled, QTreeView::item:disabled, QTableView::item:disabled {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_list_disabled.png) 0 0 1 0;\n"
"  color: rgba(255, 255, 255, 128);\n"
"}\n"
"QListWidget::item:selected, QTreeWidget::item:selected, QTableWidget::item:selected, QListView::item:selected, QTreeView::item:selected, QTableView::item:selected {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_list_pressed.png) 0 0 1 0;\n"
"  color: #ffffff;\n"
"}\n"
"\n"
"QPushButton, QComboBox::!editable {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_pushbutton_normal.png) 20 20 20 20;\n"
"  border-width: 20px 20px 20px 20px;\n"
"  padding: -20px -10px -20px -10px;\n"
"  min-height: 42px;\n"
"  min-width: 22px;\n"
"}\n"
"QPushButton:pressed, QComboBox::!editable:pressed {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_pushbutton_pressed.png) 20 20 20 20;\n"
"}\n"
"QPushButton:disabled, QComboBox::!editable:disabl"
                        "ed {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_pushbutton_disabled.png) 20 20 20 20;\n"
"}\n"
"\n"
"QCommandLinkButton, QToolButton {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_toolbutton_text_normal.png) 24 24 24 24;\n"
"  border-width: 24px 24px 24px 24px;\n"
"  padding: -24px -12px -24px -12px;\n"
"  min-height: 50px;\n"
"  min-width: 25px;\n"
"}\n"
"QCommandLinkButton:pressed, QToolButton:pressed {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_toolbutton_text_pressed.png) 24 24 24 24;\n"
"}\n"
"QCommandLinkButton:disabled, QToolButton:disabled {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_toolbutton_text_disabled.png) 24 24 24 24;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"  background: transparent;\n"
"  subcontrol-position: top right;\n"
"  subcontrol-origin: margin;\n"
"  width: 42px;\n"
"  min-height: 42px;\n"
"}\n"
"QComboBox::down-arrow{\n"
"  image: url(:/images/gui/images/gui/qtg_graf_choice_list_indicator.png);\n"
"  width: 30px;\n"
"  height: 30px;\n"
""
                        "}\n"
"QComboBox::down-arrow:editable{\n"
"  image: url(:/images/gui/images/gui/qtg_graf_choice_list_indicator_inverse.png); /* no_invert */\n"
"}\n"
"QComboBox::down-arrow:disabled{\n"
"  image: url(:/images/gui/images/gui/qtg_graf_choice_list_indicator_disabled.png);\n"
"}\n"
"QComboBox::down-arrow:editable:disabled{\n"
"  image: url(:/images/gui/images/gui/qtg_graf_choice_list_indicator_disabled_inverse.png); /* no_invert */\n"
"}\n"
"\n"
"QCheckBox {\n"
"  min-width: 42px;\n"
"  min-height: 42px;\n"
"}\n"
"QCheckBox::indicator {\n"
"  width: 42px;\n"
"  height: 42px;\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_checkbox_normal_unselected.png);\n"
"}\n"
"QCheckBox::indicator:unchecked:pressed {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_checkbox_pressed.png);\n"
"}\n"
"QCheckBox::indicator:unchecked:disabled {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_checkbox_disabled_unselected.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"  image: url(:/i"
                        "mages/gui/images/gui/qtg_graf_checkbox_normal_selected.png);\n"
"}\n"
"QCheckBox::indicator:checked:pressed {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_checkbox_pressed.png);\n"
"}\n"
"QCheckBox::indicator:checked:disabled {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_checkbox_disabled_selected.png);\n"
"}\n"
"QCheckBox::indicator:indeterminate {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_radiobutton_normal_selected.png);\n"
"}\n"
"QCheckBox::indicator:indeterminate:pressed {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_radiobutton_pressed.png);\n"
"}\n"
"QCheckBox::indicator:indeterminate:disabled {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_radiobutton_disabled_selected.png);\n"
"}\n"
"\n"
"QCheckBox[autoRepeatDelay=\"1000\"] {\n"
"  min-width: 66px;\n"
"  min-height: 44px;\n"
"}\n"
"QCheckBox[autoRepeatDelay=\"1000\"]::indicator {\n"
"  width: 66px;\n"
"  height: 44px;\n"
"}\n"
"QCheckBox[autoRepeatDelay=\"1000\"]::indicator:unchecked {\n"
"  image: url(:/images/gui/images/g"
                        "ui/qtg_graf_switchbutton_off.png);\n"
"}\n"
"QCheckBox[autoRepeatDelay=\"1000\"]::indicator:unchecked:pressed {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_switchbutton_off_pressed.png);\n"
"}\n"
"QCheckBox[autoRepeatDelay=\"1000\"]::indicator:unchecked:disabled {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_switchbutton_disabled_off.png);\n"
"}\n"
"QCheckBox[autoRepeatDelay=\"1000\"]::indicator:checked {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_switchbutton_on.png);\n"
"}\n"
"QCheckBox[autoRepeatDelay=\"1000\"]::indicator:checked:pressed {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_switchbutton_on_pressed.png);\n"
"}\n"
"QCheckBox[autoRepeatDelay=\"1000\"]::indicator:checked:disabled {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_switchbutton_disabled_on.png);\n"
"}\n"
"QCheckBox[autoRepeatDelay=\"1000\"]::indicator:indeterminate {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_switchbutton_fill.png);\n"
"}\n"
"QCheckBox[autoRepeatDelay=\"1000\"]::indicator:indeterminate:pre"
                        "ssed {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_switchbutton_on_pressed.png);\n"
"}\n"
"QCheckBox[autoRepeatDelay=\"1000\"]::indicator:indeterminate:disabled {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_switchbutton_disabled_off.png);\n"
"}\n"
"\n"
"QRadioButton {\n"
"  min-width: 42px;\n"
"  min-height: 42px;\n"
"}\n"
"QRadioButton::indicator {\n"
"  width: 42px;\n"
"  height: 42px;\n"
"}\n"
"QRadioButton::indicator:unchecked {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_radiobutton_normal_unselected.png);\n"
"}\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_radiobutton_pressed.png);\n"
"}\n"
"QRadioButton::indicator:unchecked:disabled {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_radiobutton_disabled_unselected.png);\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_radiobutton_normal_selected.png);\n"
"}\n"
"QRadioButton::indicator:checked:pressed {\n"
"  image: url(:/images/gui/images/"
                        "gui/qtg_graf_radiobutton_pressed.png);\n"
"}\n"
"QRadioButton::indicator:checked:disabled {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_radiobutton_disabled_selected.png);\n"
"}\n"
"\n"
"QLineEdit, QTextEdit, QPlainTextEdit, QSpinBox, QDoubleSpinBox, QDateEdit, QDateTimeEdit, QComboBox::editable {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_textfield_editable.png) 20 20 20 20;\n"
"  border-width: 20px 20px 20px 20px;\n"
"  color: #000000; /* no_invert */\n"
"  padding: -20px -10px -20px -10px;\n"
"  min-height: 42px;\n"
"  min-width: 21px;\n"
"}\n"
"QTextEdit, QPlainTextEdit {\n"
"  padding: -10px -10px -10px -10px;\n"
"}\n"
"QLineEdit:focus, QTextEdit:focus, QPlainTextEdit:focus, QSpinBox:focus, QDoubleSpinBox:focus, QDateEdit:focus, QDateTimeEdit:focus, QComboBox::editable:focus {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_textfield_highlighted.png) 20 20 20 20;\n"
"}\n"
"QLineEdit:disabled, QLineEdit:read-only, QTextEdit:disabled, QTextEdit:read-only, QPlainTextEdit:disabled, QP"
                        "lainTextEdit:read-only, QSpinBox:disabled, QSpinBox:read-only, QDoubleSpinBox:disabled, QDoubleSpinBox:read-only, QDateEdit:disabled, QDateEdit:read-only, QDateTimeEdit:disabled, QDateTimeEdit:read-only, QComboBox::editable:disabled, QComboBox::editable:read-only {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_textfield_uneditable.png) 20 20 20 20;\n"
"  color: rgba(0, 0, 0, 128);\n"
"}\n"
"\n"
"QSpinBox::down-button, QSpinBox::up-button, QDoubleSpinBox::down-button, QDoubleSpinBox::up-button, QDateEdit::down-button, QDateEdit::up-button, QDateTimeEdit::down-button, QDateTimeEdit::up-button {\n"
"  background: transparent;\n"
"  subcontrol-position: top right;\n"
"  subcontrol-origin: margin;\n"
"  width: 42px;\n"
"  min-height: 42px;\n"
"}\n"
"QSpinBox::up-button, QDoubleSpinBox::up-button, QDateEdit::up-button, QDateTimeEdit::up-button {\n"
"  right: 36px;\n"
"  padding-left: 20px;\n"
"  padding-right: -6px;\n"
"}\n"
"QSpinBox::down-button, QDoubleSpinBox::down-button, QDateEdit::down-button, QDateT"
                        "imeEdit::down-button {\n"
"  padding-left: -6px;\n"
"}\n"
"QSpinBox::up-arrow, QSpinBox::down-arrow, QDoubleSpinBox::up-arrow, QDoubleSpinBox::down-arrow, QDateEdit::up-arrow, QDateTimeEdit::up-arrow, QDateTimeEdit::down-arrow {\n"
"  width: 30px;\n"
"  height: 30px;\n"
"}\n"
"QSpinBox::up-arrow, QDoubleSpinBox::up-arrow, QDateEdit::up-arrow, QDateTimeEdit::up-arrow {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_slider_increment_normal_inverse.png); /* no_invert */\n"
"}\n"
"QSpinBox::up-arrow:pressed, QDoubleSpinBox::up-arrow:pressed, QDateEdit::up-arrow:pressed, QDateTimeEdit::up-arrow:pressed {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_slider_increment_pressed.png);\n"
"}\n"
"QSpinBox::up-arrow:disabled, QSpinBox::up-arrow:off, QDoubleSpinBox::up-arrow:disabled, QDoubleSpinBox::up-arrow:off, QDateEdit::up-arrow:disabled, QDateEdit::up-arrow:off, QDateTimeEdit::up-arrow:disabled, QDateTimeEdit::up-arrow:off {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_slider_increment_normal.png); /* no_i"
                        "nvert */\n"
"}\n"
"QSpinBox::down-arrow, QDoubleSpinBox::down-arrow, QDateEdit::down-arrow, QDateTimeEdit::down-arrow {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_slider_decrement_normal_inverse.png); /* no_invert */\n"
"}\n"
"QSpinBox::down-arrow:pressed, QDoubleSpinBox::down-arrow:pressed, QDateEdit::down-arrow:pressed, QDateTimeEdit::down-arrow:pressed {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_slider_decrement_pressed.png);\n"
"}\n"
"QSpinBox::down-arrow:disabled, QSpinBox::down-arrow:off, QDoubleSpinBox::down-arrow:disabled, QDoubleSpinBox::down-arrow:off, QDateEdit::down-arrow:disabled, QDateEdit::down-arrow:off, QDateTimeEdit::down-arrow:disabled, QDateTimeEdit::down-arrow:off {\n"
"  image: url(:/images/gui/images/gui/qtg_graf_slider_decrement_normal.png); /* no_invert */\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_scrollbar_v_track_normal.png) 6 4 6 4;\n"
"  border-width: 6px 8px 6px 8px;\n"
"  padding: -6px -8px -6px -8px;\n"
"  width: 2"
                        "0px;\n"
"}\n"
"QScrollBar:horizontal {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_scrollbar_h_track_normal.png) 4 6 4 6;\n"
"  border-width: 8px 6px 8px 6px;\n"
"  padding: -8px -6px -8px -6px;\n"
"  height: 20px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_scrollbar_v_handle_normal.png) 6 4 6 4;\n"
"  border-width: 6px 8px 6px 8px;\n"
"  padding: -6px -8px -6px -8px;\n"
"  min-height: 30px;\n"
"}\n"
"QScrollBar::handle:horizontal {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_scrollbar_h_handle_normal.png) 4 6 4 6;\n"
"  border-width: 8px 6px 8px 6px;\n"
"  padding: -8px -6px -8px -6px;\n"
"  min-width: 30px;\n"
"}\n"
"QScrollBar::handle:vertical:pressed {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_scrollbar_v_handle_pressed.png) 6 4 6 4;\n"
"}\n"
"QScrollBar::handle:horizontal:pressed {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_scrollbar_h_handle_pressed.png) 4 6 4 6;\n"
"}\n"
"QScrollBar::handle:disabled{\n"
" "
                        " border-image: none;\n"
"}\n"
"QScrollBar::add-page:horizontal,\n"
"QScrollBar::sub-page:horizontal,\n"
"QScrollBar::add-page:vertical,\n"
"QScrollBar::sub-page:vertical{\n"
"  background: transparent;\n"
"}\n"
"QScrollBar::add-line:horizontal,\n"
"QScrollBar::sub-line:horizontal,\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical{\n"
"  background: transparent;\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_slider_h_track_normal.png) 9 4 9 4;\n"
"  border-width: 9px 4px 9px 4px;\n"
"  padding: -9px -4px -9px -4px;\n"
"  height: 20px;\n"
"}\n"
"QSlider::groove:vertical {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_slider_v_track_normal.png) 4 9 4 9;\n"
"  border-width: 4px 9px 4px 9px;\n"
"  padding: -4px -9px -4px -9px;\n"
"  width: 20px;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"  border-image: url(:/images/gui/images/gui/qtg_graf_slider_h_handle_normal.png) 14 14 14 14;\n"
"  border-width: 14px 14px 14px 14px;\n"
"  padding: -"
                        "14px -14px -14px -14px;\n"
"  margin: -5px 0px -5px 0px;\n"
"  width: 30px;\n"
"}\n"
"QSlider::handle:horizontal:pressed {\n"
"  border-image: url(:/images/gui/images/gui/qtg_graf_slider_h_handle_pressed.png) 14 14 14 14;\n"
"}\n"
"QSlider::handle:vertical {\n"
"  border-image: url(:/images/gui/images/gui/qtg_graf_slider_v_handle_normal.png) 14 14 14 14;\n"
"  border-width: 14px 14px 14px 14px;\n"
"  padding: -14px -14px -14px -14px;\n"
"  margin: 0px -5px 0px -5px;\n"
"  height: 30px;\n"
"}\n"
"QSlider::handle:vertical:pressed {\n"
"  border-image: url(:/images/gui/images/gui/qtg_graf_slider_v_handle_pressed.png) 14 14 14 14;\n"
"}\n"
"QSlider::sub-page:horizontal:enabled {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_slider_h_fill_normal.png) 9 4 9 4;\n"
"  border-width: 9px 4px 9px 4px;\n"
"  padding: -9px -4px -9px -4px;\n"
"}\n"
"QSlider::add-page:vertical:enabled {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_slider_v_fill_normal.png) 4 9 4 9;\n"
"  border-width: 4px 9px 4px 9px;\n"
""
                        "  padding: -4px -9px -4px -9px;\n"
"}\n"
"\n"
"QProgressBar {\n"
"  text-align: center;\n"
"  font-size: 18px;\n"
"}\n"
"QProgressBar:horizontal {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_progressbar_track.png) 9 4 9 4;\n"
"  border-width: 9px 4px 9px 4px;\n"
"  padding: -9px -4px -9px -4px;\n"
"  min-height: 20px;\n"
"}\n"
"QProgressBar:vertical {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_progressbar_v_track.png) 4 9 4 9;\n"
"  border-width: 4px 9px 4px 9px;\n"
"  padding: -4px -9px -4px -9px;\n"
"  min-width: 20px;\n"
"}\n"
"QProgressBar::chunk:horizontal {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_progressbar_fill.png) 9 4 9 4;\n"
"  border-width: 9px 4px 9px 4px;\n"
"  padding: -9px -4px -9px -4px;\n"
"}\n"
"QProgressBar::chunk:vertical {\n"
"  border-image: url(:/images/gui/images/gui/qtg_fr_progressbar_v_fill.png) 4 9 4 9;\n"
"  border-width: 4px 9px 4px 9px;\n"
"  padding: -4px -9px -4px -9px;\n"
"}"));
        acNew = new QAction(CMainWindow);
        acNew->setObjectName(QString::fromUtf8("acNew"));
        acOpen = new QAction(CMainWindow);
        acOpen->setObjectName(QString::fromUtf8("acOpen"));
        acSave = new QAction(CMainWindow);
        acSave->setObjectName(QString::fromUtf8("acSave"));
        acSaveAs = new QAction(CMainWindow);
        acSaveAs->setObjectName(QString::fromUtf8("acSaveAs"));
        acExit = new QAction(CMainWindow);
        acExit->setObjectName(QString::fromUtf8("acExit"));
        acAddTerrain = new QAction(CMainWindow);
        acAddTerrain->setObjectName(QString::fromUtf8("acAddTerrain"));
        acAddWater = new QAction(CMainWindow);
        acAddWater->setObjectName(QString::fromUtf8("acAddWater"));
        acDeleteTerrain = new QAction(CMainWindow);
        acDeleteTerrain->setObjectName(QString::fromUtf8("acDeleteTerrain"));
        acViewHelp = new QAction(CMainWindow);
        acViewHelp->setObjectName(QString::fromUtf8("acViewHelp"));
        acAbout = new QAction(CMainWindow);
        acAbout->setObjectName(QString::fromUtf8("acAbout"));
        acDeleteWater = new QAction(CMainWindow);
        acDeleteWater->setObjectName(QString::fromUtf8("acDeleteWater"));
        wgCentral = new QWidget(CMainWindow);
        wgCentral->setObjectName(QString::fromUtf8("wgCentral"));
        hlCentral = new QHBoxLayout(wgCentral);
        hlCentral->setSpacing(0);
        hlCentral->setContentsMargins(11, 11, 11, 11);
        hlCentral->setObjectName(QString::fromUtf8("hlCentral"));
        hlCentral->setContentsMargins(0, 0, 0, 0);
        wgView = new CEngine(wgCentral);
        wgView->setObjectName(QString::fromUtf8("wgView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wgView->sizePolicy().hasHeightForWidth());
        wgView->setSizePolicy(sizePolicy);

        hlCentral->addWidget(wgView);

        tbRight = new QTabWidget(wgCentral);
        tbRight->setObjectName(QString::fromUtf8("tbRight"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tbRight->sizePolicy().hasHeightForWidth());
        tbRight->setSizePolicy(sizePolicy1);
        tbRight->setMaximumSize(QSize(300, 16777215));
        twTerrain = new QWidget();
        twTerrain->setObjectName(QString::fromUtf8("twTerrain"));
        vlTerrain = new QVBoxLayout(twTerrain);
        vlTerrain->setSpacing(0);
        vlTerrain->setContentsMargins(11, 11, 11, 11);
        vlTerrain->setObjectName(QString::fromUtf8("vlTerrain"));
        vlTerrain->setContentsMargins(0, 0, 0, 0);
        saTerrain = new QScrollArea(twTerrain);
        saTerrain->setObjectName(QString::fromUtf8("saTerrain"));
        saTerrain->setFrameShape(QFrame::NoFrame);
        saTerrain->setFrameShadow(QFrame::Plain);
        saTerrain->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        saTerrain->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        saTerrain->setWidgetResizable(true);
        swTerrain = new QWidget();
        swTerrain->setObjectName(QString::fromUtf8("swTerrain"));
        swTerrain->setGeometry(QRect(0, -1127, 280, 1604));
        flTerrain = new QFormLayout(swTerrain);
        flTerrain->setSpacing(6);
        flTerrain->setContentsMargins(11, 11, 11, 11);
        flTerrain->setObjectName(QString::fromUtf8("flTerrain"));
        flTerrain->setHorizontalSpacing(5);
        flTerrain->setVerticalSpacing(5);
        flTerrain->setContentsMargins(5, 5, 5, 5);
        gbTerrainList = new QGroupBox(swTerrain);
        gbTerrainList->setObjectName(QString::fromUtf8("gbTerrainList"));
        flTerrainList = new QFormLayout(gbTerrainList);
        flTerrainList->setSpacing(6);
        flTerrainList->setContentsMargins(11, 11, 11, 11);
        flTerrainList->setObjectName(QString::fromUtf8("flTerrainList"));
        flTerrainList->setHorizontalSpacing(5);
        flTerrainList->setVerticalSpacing(5);
        flTerrainList->setContentsMargins(5, 5, 5, 5);
        lwTerrainList = new QListWidget(gbTerrainList);
        lwTerrainList->setObjectName(QString::fromUtf8("lwTerrainList"));
        lwTerrainList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        lwTerrainList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        flTerrainList->setWidget(0, QFormLayout::SpanningRole, lwTerrainList);


        flTerrain->setWidget(0, QFormLayout::SpanningRole, gbTerrainList);

        gbTerrainParameters = new QGroupBox(swTerrain);
        gbTerrainParameters->setObjectName(QString::fromUtf8("gbTerrainParameters"));
        flTerrainParameters = new QFormLayout(gbTerrainParameters);
        flTerrainParameters->setSpacing(6);
        flTerrainParameters->setContentsMargins(11, 11, 11, 11);
        flTerrainParameters->setObjectName(QString::fromUtf8("flTerrainParameters"));
        flTerrainParameters->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        flTerrainParameters->setHorizontalSpacing(5);
        flTerrainParameters->setVerticalSpacing(5);
        flTerrainParameters->setContentsMargins(5, 5, 5, 5);
        lbTerrainName = new QLabel(gbTerrainParameters);
        lbTerrainName->setObjectName(QString::fromUtf8("lbTerrainName"));

        flTerrainParameters->setWidget(0, QFormLayout::LabelRole, lbTerrainName);

        leTerrainName = new QLineEdit(gbTerrainParameters);
        leTerrainName->setObjectName(QString::fromUtf8("leTerrainName"));

        flTerrainParameters->setWidget(1, QFormLayout::SpanningRole, leTerrainName);

        lbTerrainPosition = new QLabel(gbTerrainParameters);
        lbTerrainPosition->setObjectName(QString::fromUtf8("lbTerrainPosition"));

        flTerrainParameters->setWidget(2, QFormLayout::LabelRole, lbTerrainPosition);

        frTerrainPosition = new QFrame(gbTerrainParameters);
        frTerrainPosition->setObjectName(QString::fromUtf8("frTerrainPosition"));
        hlTerrainPosition = new QHBoxLayout(frTerrainPosition);
        hlTerrainPosition->setSpacing(5);
        hlTerrainPosition->setContentsMargins(11, 11, 11, 11);
        hlTerrainPosition->setObjectName(QString::fromUtf8("hlTerrainPosition"));
        hlTerrainPosition->setContentsMargins(0, 0, 0, 0);
        dsTerrainPosX = new QDoubleSpinBox(frTerrainPosition);
        dsTerrainPosX->setObjectName(QString::fromUtf8("dsTerrainPosX"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dsTerrainPosX->sizePolicy().hasHeightForWidth());
        dsTerrainPosX->setSizePolicy(sizePolicy2);
        dsTerrainPosX->setMinimum(-1e+06);
        dsTerrainPosX->setMaximum(1e+06);

        hlTerrainPosition->addWidget(dsTerrainPosX);

        dsTerrainPosY = new QDoubleSpinBox(frTerrainPosition);
        dsTerrainPosY->setObjectName(QString::fromUtf8("dsTerrainPosY"));
        sizePolicy2.setHeightForWidth(dsTerrainPosY->sizePolicy().hasHeightForWidth());
        dsTerrainPosY->setSizePolicy(sizePolicy2);
        dsTerrainPosY->setMinimum(-1e+06);
        dsTerrainPosY->setMaximum(1e+06);

        hlTerrainPosition->addWidget(dsTerrainPosY);

        dsTerrainPosZ = new QDoubleSpinBox(frTerrainPosition);
        dsTerrainPosZ->setObjectName(QString::fromUtf8("dsTerrainPosZ"));
        sizePolicy2.setHeightForWidth(dsTerrainPosZ->sizePolicy().hasHeightForWidth());
        dsTerrainPosZ->setSizePolicy(sizePolicy2);
        dsTerrainPosZ->setMinimum(-1e+06);
        dsTerrainPosZ->setMaximum(1e+06);

        hlTerrainPosition->addWidget(dsTerrainPosZ);


        flTerrainParameters->setWidget(3, QFormLayout::SpanningRole, frTerrainPosition);

        lbTerrainRotation = new QLabel(gbTerrainParameters);
        lbTerrainRotation->setObjectName(QString::fromUtf8("lbTerrainRotation"));

        flTerrainParameters->setWidget(4, QFormLayout::LabelRole, lbTerrainRotation);

        frTerrainRotation = new QFrame(gbTerrainParameters);
        frTerrainRotation->setObjectName(QString::fromUtf8("frTerrainRotation"));
        hlTerrainRotation = new QHBoxLayout(frTerrainRotation);
        hlTerrainRotation->setSpacing(5);
        hlTerrainRotation->setContentsMargins(11, 11, 11, 11);
        hlTerrainRotation->setObjectName(QString::fromUtf8("hlTerrainRotation"));
        hlTerrainRotation->setContentsMargins(0, 0, 0, 0);
        dsTerrainRotX = new QDoubleSpinBox(frTerrainRotation);
        dsTerrainRotX->setObjectName(QString::fromUtf8("dsTerrainRotX"));
        sizePolicy2.setHeightForWidth(dsTerrainRotX->sizePolicy().hasHeightForWidth());
        dsTerrainRotX->setSizePolicy(sizePolicy2);
        dsTerrainRotX->setMinimum(-1e+06);
        dsTerrainRotX->setMaximum(1e+06);

        hlTerrainRotation->addWidget(dsTerrainRotX);

        dsTerrainRotY = new QDoubleSpinBox(frTerrainRotation);
        dsTerrainRotY->setObjectName(QString::fromUtf8("dsTerrainRotY"));
        sizePolicy2.setHeightForWidth(dsTerrainRotY->sizePolicy().hasHeightForWidth());
        dsTerrainRotY->setSizePolicy(sizePolicy2);
        dsTerrainRotY->setMinimum(-1e+06);
        dsTerrainRotY->setMaximum(1e+06);

        hlTerrainRotation->addWidget(dsTerrainRotY);

        dsTerrainRotZ = new QDoubleSpinBox(frTerrainRotation);
        dsTerrainRotZ->setObjectName(QString::fromUtf8("dsTerrainRotZ"));
        sizePolicy2.setHeightForWidth(dsTerrainRotZ->sizePolicy().hasHeightForWidth());
        dsTerrainRotZ->setSizePolicy(sizePolicy2);
        dsTerrainRotZ->setMinimum(-1e+06);
        dsTerrainRotZ->setMaximum(1e+06);

        hlTerrainRotation->addWidget(dsTerrainRotZ);


        flTerrainParameters->setWidget(5, QFormLayout::SpanningRole, frTerrainRotation);

        lbTerrainScale = new QLabel(gbTerrainParameters);
        lbTerrainScale->setObjectName(QString::fromUtf8("lbTerrainScale"));

        flTerrainParameters->setWidget(6, QFormLayout::LabelRole, lbTerrainScale);

        frTerrainScale = new QFrame(gbTerrainParameters);
        frTerrainScale->setObjectName(QString::fromUtf8("frTerrainScale"));
        hlTerrainScale = new QHBoxLayout(frTerrainScale);
        hlTerrainScale->setSpacing(5);
        hlTerrainScale->setContentsMargins(11, 11, 11, 11);
        hlTerrainScale->setObjectName(QString::fromUtf8("hlTerrainScale"));
        hlTerrainScale->setContentsMargins(0, 0, 0, 0);
        dsTerrainScaleX = new QDoubleSpinBox(frTerrainScale);
        dsTerrainScaleX->setObjectName(QString::fromUtf8("dsTerrainScaleX"));
        sizePolicy2.setHeightForWidth(dsTerrainScaleX->sizePolicy().hasHeightForWidth());
        dsTerrainScaleX->setSizePolicy(sizePolicy2);
        dsTerrainScaleX->setMinimum(-1e+06);
        dsTerrainScaleX->setMaximum(1e+06);
        dsTerrainScaleX->setValue(1);

        hlTerrainScale->addWidget(dsTerrainScaleX);

        dsTerrainScaleY = new QDoubleSpinBox(frTerrainScale);
        dsTerrainScaleY->setObjectName(QString::fromUtf8("dsTerrainScaleY"));
        sizePolicy2.setHeightForWidth(dsTerrainScaleY->sizePolicy().hasHeightForWidth());
        dsTerrainScaleY->setSizePolicy(sizePolicy2);
        dsTerrainScaleY->setMinimum(-1e+06);
        dsTerrainScaleY->setMaximum(1e+06);
        dsTerrainScaleY->setValue(1);

        hlTerrainScale->addWidget(dsTerrainScaleY);

        dsTerrainScaleZ = new QDoubleSpinBox(frTerrainScale);
        dsTerrainScaleZ->setObjectName(QString::fromUtf8("dsTerrainScaleZ"));
        sizePolicy2.setHeightForWidth(dsTerrainScaleZ->sizePolicy().hasHeightForWidth());
        dsTerrainScaleZ->setSizePolicy(sizePolicy2);
        dsTerrainScaleZ->setMinimum(-1e+06);
        dsTerrainScaleZ->setMaximum(1e+06);
        dsTerrainScaleZ->setValue(1);

        hlTerrainScale->addWidget(dsTerrainScaleZ);


        flTerrainParameters->setWidget(7, QFormLayout::SpanningRole, frTerrainScale);

        frTerrainSep00 = new QFrame(gbTerrainParameters);
        frTerrainSep00->setObjectName(QString::fromUtf8("frTerrainSep00"));
        frTerrainSep00->setMinimumSize(QSize(0, 10));

        flTerrainParameters->setWidget(8, QFormLayout::SpanningRole, frTerrainSep00);

        cbTerrainSeed = new QCheckBox(gbTerrainParameters);
        cbTerrainSeed->setObjectName(QString::fromUtf8("cbTerrainSeed"));
        cbTerrainSeed->setChecked(true);
        cbTerrainSeed->setAutoRepeatDelay(1000);

        flTerrainParameters->setWidget(9, QFormLayout::LabelRole, cbTerrainSeed);

        sbTerrainSeed = new QSpinBox(gbTerrainParameters);
        sbTerrainSeed->setObjectName(QString::fromUtf8("sbTerrainSeed"));
        sbTerrainSeed->setMaximum(1000000);
        sbTerrainSeed->setValue(132);

        flTerrainParameters->setWidget(9, QFormLayout::FieldRole, sbTerrainSeed);

        lbTerrainGrid = new QLabel(gbTerrainParameters);
        lbTerrainGrid->setObjectName(QString::fromUtf8("lbTerrainGrid"));

        flTerrainParameters->setWidget(10, QFormLayout::LabelRole, lbTerrainGrid);

        cbTerrainGrid = new QComboBox(gbTerrainParameters);
        cbTerrainGrid->setObjectName(QString::fromUtf8("cbTerrainGrid"));

        flTerrainParameters->setWidget(11, QFormLayout::SpanningRole, cbTerrainGrid);

        cbTerrainLand = new QCheckBox(gbTerrainParameters);
        cbTerrainLand->setObjectName(QString::fromUtf8("cbTerrainLand"));
        cbTerrainLand->setAutoRepeatDelay(1000);

        flTerrainParameters->setWidget(12, QFormLayout::SpanningRole, cbTerrainLand);

        lbTerrainHeightMul = new QLabel(gbTerrainParameters);
        lbTerrainHeightMul->setObjectName(QString::fromUtf8("lbTerrainHeightMul"));

        flTerrainParameters->setWidget(13, QFormLayout::LabelRole, lbTerrainHeightMul);

        dsTerrainHeightMul = new QDoubleSpinBox(gbTerrainParameters);
        dsTerrainHeightMul->setObjectName(QString::fromUtf8("dsTerrainHeightMul"));
        dsTerrainHeightMul->setMinimum(-1);
        dsTerrainHeightMul->setMaximum(1);
        dsTerrainHeightMul->setSingleStep(0.1);
        dsTerrainHeightMul->setValue(0.3);

        flTerrainParameters->setWidget(13, QFormLayout::FieldRole, dsTerrainHeightMul);

        lbTerrainDepthMul = new QLabel(gbTerrainParameters);
        lbTerrainDepthMul->setObjectName(QString::fromUtf8("lbTerrainDepthMul"));

        flTerrainParameters->setWidget(14, QFormLayout::LabelRole, lbTerrainDepthMul);

        dsTerrainDepthMul = new QDoubleSpinBox(gbTerrainParameters);
        dsTerrainDepthMul->setObjectName(QString::fromUtf8("dsTerrainDepthMul"));
        dsTerrainDepthMul->setMaximum(1);
        dsTerrainDepthMul->setSingleStep(0.1);
        dsTerrainDepthMul->setValue(0.4);

        flTerrainParameters->setWidget(14, QFormLayout::FieldRole, dsTerrainDepthMul);

        lbTerrainHeightMod1 = new QLabel(gbTerrainParameters);
        lbTerrainHeightMod1->setObjectName(QString::fromUtf8("lbTerrainHeightMod1"));

        flTerrainParameters->setWidget(15, QFormLayout::LabelRole, lbTerrainHeightMod1);

        dsTerrainHeightMod1 = new QDoubleSpinBox(gbTerrainParameters);
        dsTerrainHeightMod1->setObjectName(QString::fromUtf8("dsTerrainHeightMod1"));
        dsTerrainHeightMod1->setMinimum(-1);
        dsTerrainHeightMod1->setMaximum(1);
        dsTerrainHeightMod1->setSingleStep(0.1);
        dsTerrainHeightMod1->setValue(-0.1);

        flTerrainParameters->setWidget(15, QFormLayout::FieldRole, dsTerrainHeightMod1);

        lbTerrainHeightMod2 = new QLabel(gbTerrainParameters);
        lbTerrainHeightMod2->setObjectName(QString::fromUtf8("lbTerrainHeightMod2"));

        flTerrainParameters->setWidget(16, QFormLayout::LabelRole, lbTerrainHeightMod2);

        dsTerrainHeightMod2 = new QDoubleSpinBox(gbTerrainParameters);
        dsTerrainHeightMod2->setObjectName(QString::fromUtf8("dsTerrainHeightMod2"));
        dsTerrainHeightMod2->setMinimum(-1);
        dsTerrainHeightMod2->setMaximum(1);
        dsTerrainHeightMod2->setSingleStep(0.1);
        dsTerrainHeightMod2->setValue(0.2);

        flTerrainParameters->setWidget(16, QFormLayout::FieldRole, dsTerrainHeightMod2);

        frTerrainSep01 = new QFrame(gbTerrainParameters);
        frTerrainSep01->setObjectName(QString::fromUtf8("frTerrainSep01"));
        frTerrainSep01->setMinimumSize(QSize(0, 10));

        flTerrainParameters->setWidget(18, QFormLayout::SpanningRole, frTerrainSep01);

        frTerrainInsert = new QFrame(gbTerrainParameters);
        frTerrainInsert->setObjectName(QString::fromUtf8("frTerrainInsert"));
        hlTerrainInsert = new QHBoxLayout(frTerrainInsert);
        hlTerrainInsert->setSpacing(5);
        hlTerrainInsert->setContentsMargins(11, 11, 11, 11);
        hlTerrainInsert->setObjectName(QString::fromUtf8("hlTerrainInsert"));
        hlTerrainInsert->setContentsMargins(0, 0, 0, 0);
        hsTerrainInsert = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlTerrainInsert->addItem(hsTerrainInsert);

        clTerrainApply = new QCommandLinkButton(frTerrainInsert);
        clTerrainApply->setObjectName(QString::fromUtf8("clTerrainApply"));
        clTerrainApply->setMaximumSize(QSize(100, 16777215));

        hlTerrainInsert->addWidget(clTerrainApply);


        flTerrainParameters->setWidget(19, QFormLayout::SpanningRole, frTerrainInsert);

        gbTerrainLayers = new QGroupBox(gbTerrainParameters);
        gbTerrainLayers->setObjectName(QString::fromUtf8("gbTerrainLayers"));
        formLayout = new QFormLayout(gbTerrainLayers);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setHorizontalSpacing(5);
        formLayout->setVerticalSpacing(5);
        formLayout->setContentsMargins(2, 10, 2, 5);
        frTerrainLayers = new QFrame(gbTerrainLayers);
        frTerrainLayers->setObjectName(QString::fromUtf8("frTerrainLayers"));
        hlTerrainLayers = new QHBoxLayout(frTerrainLayers);
        hlTerrainLayers->setSpacing(5);
        hlTerrainLayers->setContentsMargins(11, 11, 11, 11);
        hlTerrainLayers->setObjectName(QString::fromUtf8("hlTerrainLayers"));
        hlTerrainLayers->setContentsMargins(0, 0, 0, 0);
        hsTerrainLayers = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlTerrainLayers->addItem(hsTerrainLayers);

        pbTerrainLayersAdd = new QPushButton(frTerrainLayers);
        pbTerrainLayersAdd->setObjectName(QString::fromUtf8("pbTerrainLayersAdd"));

        hlTerrainLayers->addWidget(pbTerrainLayersAdd);

        pbTerrainLayersDel = new QPushButton(frTerrainLayers);
        pbTerrainLayersDel->setObjectName(QString::fromUtf8("pbTerrainLayersDel"));

        hlTerrainLayers->addWidget(pbTerrainLayersDel);

        pbTerrainLayersUp = new QPushButton(frTerrainLayers);
        pbTerrainLayersUp->setObjectName(QString::fromUtf8("pbTerrainLayersUp"));

        hlTerrainLayers->addWidget(pbTerrainLayersUp);

        pbTerrainLayersDown = new QPushButton(frTerrainLayers);
        pbTerrainLayersDown->setObjectName(QString::fromUtf8("pbTerrainLayersDown"));

        hlTerrainLayers->addWidget(pbTerrainLayersDown);


        formLayout->setWidget(0, QFormLayout::SpanningRole, frTerrainLayers);

        lwTerrainLayersList = new QListWidget(gbTerrainLayers);
        lwTerrainLayersList->setObjectName(QString::fromUtf8("lwTerrainLayersList"));
        lwTerrainLayersList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        lwTerrainLayersList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        formLayout->setWidget(1, QFormLayout::SpanningRole, lwTerrainLayersList);

        frTerrainLayersParameters = new QFrame(gbTerrainLayers);
        frTerrainLayersParameters->setObjectName(QString::fromUtf8("frTerrainLayersParameters"));
        frTerrainLayersParameters->setFrameShape(QFrame::StyledPanel);
        frTerrainLayersParameters->setFrameShadow(QFrame::Raised);
        flTerrainLayersParameters = new QFormLayout(frTerrainLayersParameters);
        flTerrainLayersParameters->setSpacing(6);
        flTerrainLayersParameters->setContentsMargins(11, 11, 11, 11);
        flTerrainLayersParameters->setObjectName(QString::fromUtf8("flTerrainLayersParameters"));
        flTerrainLayersParameters->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        flTerrainLayersParameters->setHorizontalSpacing(5);
        flTerrainLayersParameters->setVerticalSpacing(5);
        flTerrainLayersParameters->setContentsMargins(0, 0, 0, 0);
        lbTerrainLayersColor = new QLabel(frTerrainLayersParameters);
        lbTerrainLayersColor->setObjectName(QString::fromUtf8("lbTerrainLayersColor"));

        flTerrainLayersParameters->setWidget(0, QFormLayout::LabelRole, lbTerrainLayersColor);

        frTerrainLayersColor = new QFrame(frTerrainLayersParameters);
        frTerrainLayersColor->setObjectName(QString::fromUtf8("frTerrainLayersColor"));
        hlTerrainLayersColor = new QHBoxLayout(frTerrainLayersColor);
        hlTerrainLayersColor->setSpacing(5);
        hlTerrainLayersColor->setContentsMargins(11, 11, 11, 11);
        hlTerrainLayersColor->setObjectName(QString::fromUtf8("hlTerrainLayersColor"));
        hlTerrainLayersColor->setContentsMargins(0, 0, 0, 0);
        pbTerrainLayersColor = new QPushButton(frTerrainLayersColor);
        pbTerrainLayersColor->setObjectName(QString::fromUtf8("pbTerrainLayersColor"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pbTerrainLayersColor->sizePolicy().hasHeightForWidth());
        pbTerrainLayersColor->setSizePolicy(sizePolicy3);

        hlTerrainLayersColor->addWidget(pbTerrainLayersColor);

        dsTerrainLayersColorPower = new QDoubleSpinBox(frTerrainLayersColor);
        dsTerrainLayersColorPower->setObjectName(QString::fromUtf8("dsTerrainLayersColorPower"));
        dsTerrainLayersColorPower->setMinimum(-1000);
        dsTerrainLayersColorPower->setMaximum(1000);
        dsTerrainLayersColorPower->setSingleStep(0.1);
        dsTerrainLayersColorPower->setValue(1);

        hlTerrainLayersColor->addWidget(dsTerrainLayersColorPower);


        flTerrainLayersParameters->setWidget(0, QFormLayout::FieldRole, frTerrainLayersColor);

        lbTerrainLayersNormal = new QLabel(frTerrainLayersParameters);
        lbTerrainLayersNormal->setObjectName(QString::fromUtf8("lbTerrainLayersNormal"));

        flTerrainLayersParameters->setWidget(1, QFormLayout::SpanningRole, lbTerrainLayersNormal);

        frTerrainLayersNormal = new QFrame(frTerrainLayersParameters);
        frTerrainLayersNormal->setObjectName(QString::fromUtf8("frTerrainLayersNormal"));
        hlTerrainLayersNormal = new QHBoxLayout(frTerrainLayersNormal);
        hlTerrainLayersNormal->setSpacing(6);
        hlTerrainLayersNormal->setContentsMargins(11, 11, 11, 11);
        hlTerrainLayersNormal->setObjectName(QString::fromUtf8("hlTerrainLayersNormal"));
        hlTerrainLayersNormal->setContentsMargins(0, 0, 0, 0);
        leTerrainLayersNormal = new QLineEdit(frTerrainLayersNormal);
        leTerrainLayersNormal->setObjectName(QString::fromUtf8("leTerrainLayersNormal"));
        leTerrainLayersNormal->setReadOnly(true);

        hlTerrainLayersNormal->addWidget(leTerrainLayersNormal);

        tbTerrainLayersNormal = new QToolButton(frTerrainLayersNormal);
        tbTerrainLayersNormal->setObjectName(QString::fromUtf8("tbTerrainLayersNormal"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tbTerrainLayersNormal->sizePolicy().hasHeightForWidth());
        tbTerrainLayersNormal->setSizePolicy(sizePolicy4);

        hlTerrainLayersNormal->addWidget(tbTerrainLayersNormal);


        flTerrainLayersParameters->setWidget(2, QFormLayout::SpanningRole, frTerrainLayersNormal);

        cbTerrainLayersHeight = new QCheckBox(frTerrainLayersParameters);
        cbTerrainLayersHeight->setObjectName(QString::fromUtf8("cbTerrainLayersHeight"));
        cbTerrainLayersHeight->setAutoRepeatDelay(1000);

        flTerrainLayersParameters->setWidget(3, QFormLayout::SpanningRole, cbTerrainLayersHeight);

        frTerrainLayersHeight = new QFrame(frTerrainLayersParameters);
        frTerrainLayersHeight->setObjectName(QString::fromUtf8("frTerrainLayersHeight"));
        hlTerrainLayersHeight = new QHBoxLayout(frTerrainLayersHeight);
        hlTerrainLayersHeight->setSpacing(6);
        hlTerrainLayersHeight->setContentsMargins(11, 11, 11, 11);
        hlTerrainLayersHeight->setObjectName(QString::fromUtf8("hlTerrainLayersHeight"));
        hlTerrainLayersHeight->setContentsMargins(0, 0, 0, 0);
        hsTerrainLayersHeightMin = new QSlider(frTerrainLayersHeight);
        hsTerrainLayersHeightMin->setObjectName(QString::fromUtf8("hsTerrainLayersHeightMin"));
        sizePolicy.setHeightForWidth(hsTerrainLayersHeightMin->sizePolicy().hasHeightForWidth());
        hsTerrainLayersHeightMin->setSizePolicy(sizePolicy);
        hsTerrainLayersHeightMin->setMinimumSize(QSize(0, 22));
        hsTerrainLayersHeightMin->setMinimum(-50);
        hsTerrainLayersHeightMin->setMaximum(50);
        hsTerrainLayersHeightMin->setOrientation(Qt::Horizontal);
        hsTerrainLayersHeightMin->setTickPosition(QSlider::TicksBelow);

        hlTerrainLayersHeight->addWidget(hsTerrainLayersHeightMin);

        hsTerrainLayersHeightMax = new QSlider(frTerrainLayersHeight);
        hsTerrainLayersHeightMax->setObjectName(QString::fromUtf8("hsTerrainLayersHeightMax"));
        sizePolicy.setHeightForWidth(hsTerrainLayersHeightMax->sizePolicy().hasHeightForWidth());
        hsTerrainLayersHeightMax->setSizePolicy(sizePolicy);
        hsTerrainLayersHeightMax->setMinimumSize(QSize(0, 22));
        hsTerrainLayersHeightMax->setMinimum(-50);
        hsTerrainLayersHeightMax->setMaximum(50);
        hsTerrainLayersHeightMax->setValue(50);
        hsTerrainLayersHeightMax->setOrientation(Qt::Horizontal);
        hsTerrainLayersHeightMax->setTickPosition(QSlider::TicksBelow);

        hlTerrainLayersHeight->addWidget(hsTerrainLayersHeightMax);


        flTerrainLayersParameters->setWidget(4, QFormLayout::SpanningRole, frTerrainLayersHeight);

        cbTerrainLayersSlope = new QCheckBox(frTerrainLayersParameters);
        cbTerrainLayersSlope->setObjectName(QString::fromUtf8("cbTerrainLayersSlope"));
        cbTerrainLayersSlope->setAutoRepeatDelay(1000);

        flTerrainLayersParameters->setWidget(5, QFormLayout::SpanningRole, cbTerrainLayersSlope);

        frTerrainLayersSlope = new QFrame(frTerrainLayersParameters);
        frTerrainLayersSlope->setObjectName(QString::fromUtf8("frTerrainLayersSlope"));
        hlTerrainLayersSlope = new QHBoxLayout(frTerrainLayersSlope);
        hlTerrainLayersSlope->setSpacing(6);
        hlTerrainLayersSlope->setContentsMargins(11, 11, 11, 11);
        hlTerrainLayersSlope->setObjectName(QString::fromUtf8("hlTerrainLayersSlope"));
        hlTerrainLayersSlope->setContentsMargins(0, 0, 0, 0);
        hsTerrainLayersSlopeMin = new QSlider(frTerrainLayersSlope);
        hsTerrainLayersSlopeMin->setObjectName(QString::fromUtf8("hsTerrainLayersSlopeMin"));
        sizePolicy.setHeightForWidth(hsTerrainLayersSlopeMin->sizePolicy().hasHeightForWidth());
        hsTerrainLayersSlopeMin->setSizePolicy(sizePolicy);
        hsTerrainLayersSlopeMin->setMinimumSize(QSize(0, 22));
        hsTerrainLayersSlopeMin->setMaximum(100);
        hsTerrainLayersSlopeMin->setOrientation(Qt::Horizontal);
        hsTerrainLayersSlopeMin->setTickPosition(QSlider::TicksBelow);

        hlTerrainLayersSlope->addWidget(hsTerrainLayersSlopeMin);

        hsTerrainLayersSlopeMax = new QSlider(frTerrainLayersSlope);
        hsTerrainLayersSlopeMax->setObjectName(QString::fromUtf8("hsTerrainLayersSlopeMax"));
        sizePolicy.setHeightForWidth(hsTerrainLayersSlopeMax->sizePolicy().hasHeightForWidth());
        hsTerrainLayersSlopeMax->setSizePolicy(sizePolicy);
        hsTerrainLayersSlopeMax->setMinimumSize(QSize(0, 22));
        hsTerrainLayersSlopeMax->setMaximum(100);
        hsTerrainLayersSlopeMax->setValue(100);
        hsTerrainLayersSlopeMax->setOrientation(Qt::Horizontal);
        hsTerrainLayersSlopeMax->setTickPosition(QSlider::TicksBelow);

        hlTerrainLayersSlope->addWidget(hsTerrainLayersSlopeMax);


        flTerrainLayersParameters->setWidget(6, QFormLayout::SpanningRole, frTerrainLayersSlope);


        formLayout->setWidget(2, QFormLayout::SpanningRole, frTerrainLayersParameters);


        flTerrainParameters->setWidget(17, QFormLayout::SpanningRole, gbTerrainLayers);


        flTerrain->setWidget(1, QFormLayout::SpanningRole, gbTerrainParameters);

        saTerrain->setWidget(swTerrain);

        vlTerrain->addWidget(saTerrain);

        tbRight->addTab(twTerrain, QString());
        twWater = new QWidget();
        twWater->setObjectName(QString::fromUtf8("twWater"));
        vlWater = new QVBoxLayout(twWater);
        vlWater->setSpacing(0);
        vlWater->setContentsMargins(11, 11, 11, 11);
        vlWater->setObjectName(QString::fromUtf8("vlWater"));
        vlWater->setContentsMargins(0, 0, 0, 0);
        saWater = new QScrollArea(twWater);
        saWater->setObjectName(QString::fromUtf8("saWater"));
        saWater->setFrameShape(QFrame::NoFrame);
        saWater->setFrameShadow(QFrame::Plain);
        saWater->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        saWater->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        saWater->setWidgetResizable(true);
        swWater = new QWidget();
        swWater->setObjectName(QString::fromUtf8("swWater"));
        swWater->setGeometry(QRect(0, -417, 280, 941));
        formLayout_2 = new QFormLayout(swWater);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setHorizontalSpacing(5);
        formLayout_2->setVerticalSpacing(5);
        formLayout_2->setContentsMargins(5, 5, 5, 5);
        gbWaterList = new QGroupBox(swWater);
        gbWaterList->setObjectName(QString::fromUtf8("gbWaterList"));
        flWaterList = new QFormLayout(gbWaterList);
        flWaterList->setSpacing(6);
        flWaterList->setContentsMargins(11, 11, 11, 11);
        flWaterList->setObjectName(QString::fromUtf8("flWaterList"));
        flWaterList->setHorizontalSpacing(5);
        flWaterList->setVerticalSpacing(5);
        flWaterList->setContentsMargins(5, 5, 5, 5);
        lwWaterList = new QListWidget(gbWaterList);
        lwWaterList->setObjectName(QString::fromUtf8("lwWaterList"));
        lwWaterList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        lwWaterList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        flWaterList->setWidget(0, QFormLayout::SpanningRole, lwWaterList);


        formLayout_2->setWidget(0, QFormLayout::SpanningRole, gbWaterList);

        gbWaterParameters = new QGroupBox(swWater);
        gbWaterParameters->setObjectName(QString::fromUtf8("gbWaterParameters"));
        flWaterParameters = new QFormLayout(gbWaterParameters);
        flWaterParameters->setSpacing(6);
        flWaterParameters->setContentsMargins(11, 11, 11, 11);
        flWaterParameters->setObjectName(QString::fromUtf8("flWaterParameters"));
        flWaterParameters->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        flWaterParameters->setHorizontalSpacing(5);
        flWaterParameters->setVerticalSpacing(5);
        flWaterParameters->setContentsMargins(5, 5, 5, 5);
        lbWaterName = new QLabel(gbWaterParameters);
        lbWaterName->setObjectName(QString::fromUtf8("lbWaterName"));

        flWaterParameters->setWidget(0, QFormLayout::LabelRole, lbWaterName);

        leWaterName = new QLineEdit(gbWaterParameters);
        leWaterName->setObjectName(QString::fromUtf8("leWaterName"));

        flWaterParameters->setWidget(1, QFormLayout::SpanningRole, leWaterName);

        lbWaterPosition = new QLabel(gbWaterParameters);
        lbWaterPosition->setObjectName(QString::fromUtf8("lbWaterPosition"));

        flWaterParameters->setWidget(2, QFormLayout::LabelRole, lbWaterPosition);

        frWaterPosition = new QFrame(gbWaterParameters);
        frWaterPosition->setObjectName(QString::fromUtf8("frWaterPosition"));
        hlWaterPosition = new QHBoxLayout(frWaterPosition);
        hlWaterPosition->setSpacing(5);
        hlWaterPosition->setContentsMargins(11, 11, 11, 11);
        hlWaterPosition->setObjectName(QString::fromUtf8("hlWaterPosition"));
        hlWaterPosition->setContentsMargins(0, 0, 0, 0);
        dsWaterPosX = new QDoubleSpinBox(frWaterPosition);
        dsWaterPosX->setObjectName(QString::fromUtf8("dsWaterPosX"));
        sizePolicy2.setHeightForWidth(dsWaterPosX->sizePolicy().hasHeightForWidth());
        dsWaterPosX->setSizePolicy(sizePolicy2);
        dsWaterPosX->setMinimum(-1e+06);
        dsWaterPosX->setMaximum(1e+06);

        hlWaterPosition->addWidget(dsWaterPosX);

        dsWaterPosY = new QDoubleSpinBox(frWaterPosition);
        dsWaterPosY->setObjectName(QString::fromUtf8("dsWaterPosY"));
        sizePolicy2.setHeightForWidth(dsWaterPosY->sizePolicy().hasHeightForWidth());
        dsWaterPosY->setSizePolicy(sizePolicy2);
        dsWaterPosY->setMinimum(-1e+06);
        dsWaterPosY->setMaximum(1e+06);

        hlWaterPosition->addWidget(dsWaterPosY);

        dsWaterPosZ = new QDoubleSpinBox(frWaterPosition);
        dsWaterPosZ->setObjectName(QString::fromUtf8("dsWaterPosZ"));
        sizePolicy2.setHeightForWidth(dsWaterPosZ->sizePolicy().hasHeightForWidth());
        dsWaterPosZ->setSizePolicy(sizePolicy2);
        dsWaterPosZ->setMinimum(-1e+06);
        dsWaterPosZ->setMaximum(1e+06);

        hlWaterPosition->addWidget(dsWaterPosZ);


        flWaterParameters->setWidget(3, QFormLayout::SpanningRole, frWaterPosition);

        lbWaterRotation = new QLabel(gbWaterParameters);
        lbWaterRotation->setObjectName(QString::fromUtf8("lbWaterRotation"));

        flWaterParameters->setWidget(4, QFormLayout::LabelRole, lbWaterRotation);

        frWaterRotation = new QFrame(gbWaterParameters);
        frWaterRotation->setObjectName(QString::fromUtf8("frWaterRotation"));
        hlWaterRotation = new QHBoxLayout(frWaterRotation);
        hlWaterRotation->setSpacing(5);
        hlWaterRotation->setContentsMargins(11, 11, 11, 11);
        hlWaterRotation->setObjectName(QString::fromUtf8("hlWaterRotation"));
        hlWaterRotation->setContentsMargins(0, 0, 0, 0);
        dsWaterRotX = new QDoubleSpinBox(frWaterRotation);
        dsWaterRotX->setObjectName(QString::fromUtf8("dsWaterRotX"));
        sizePolicy2.setHeightForWidth(dsWaterRotX->sizePolicy().hasHeightForWidth());
        dsWaterRotX->setSizePolicy(sizePolicy2);
        dsWaterRotX->setMinimum(-1e+06);
        dsWaterRotX->setMaximum(1e+06);

        hlWaterRotation->addWidget(dsWaterRotX);

        dsWaterRotY = new QDoubleSpinBox(frWaterRotation);
        dsWaterRotY->setObjectName(QString::fromUtf8("dsWaterRotY"));
        sizePolicy2.setHeightForWidth(dsWaterRotY->sizePolicy().hasHeightForWidth());
        dsWaterRotY->setSizePolicy(sizePolicy2);
        dsWaterRotY->setMinimum(-1e+06);
        dsWaterRotY->setMaximum(1e+06);

        hlWaterRotation->addWidget(dsWaterRotY);

        dsWaterRotZ = new QDoubleSpinBox(frWaterRotation);
        dsWaterRotZ->setObjectName(QString::fromUtf8("dsWaterRotZ"));
        sizePolicy2.setHeightForWidth(dsWaterRotZ->sizePolicy().hasHeightForWidth());
        dsWaterRotZ->setSizePolicy(sizePolicy2);
        dsWaterRotZ->setMinimum(-1e+06);
        dsWaterRotZ->setMaximum(1e+06);

        hlWaterRotation->addWidget(dsWaterRotZ);


        flWaterParameters->setWidget(5, QFormLayout::SpanningRole, frWaterRotation);

        lbWaterScale = new QLabel(gbWaterParameters);
        lbWaterScale->setObjectName(QString::fromUtf8("lbWaterScale"));

        flWaterParameters->setWidget(6, QFormLayout::LabelRole, lbWaterScale);

        frWaterScale = new QFrame(gbWaterParameters);
        frWaterScale->setObjectName(QString::fromUtf8("frWaterScale"));
        hlWaterScale = new QHBoxLayout(frWaterScale);
        hlWaterScale->setSpacing(5);
        hlWaterScale->setContentsMargins(11, 11, 11, 11);
        hlWaterScale->setObjectName(QString::fromUtf8("hlWaterScale"));
        hlWaterScale->setContentsMargins(0, 0, 0, 0);
        dsWaterScaleX = new QDoubleSpinBox(frWaterScale);
        dsWaterScaleX->setObjectName(QString::fromUtf8("dsWaterScaleX"));
        sizePolicy2.setHeightForWidth(dsWaterScaleX->sizePolicy().hasHeightForWidth());
        dsWaterScaleX->setSizePolicy(sizePolicy2);
        dsWaterScaleX->setMinimum(-1e+06);
        dsWaterScaleX->setMaximum(1e+06);
        dsWaterScaleX->setValue(1);

        hlWaterScale->addWidget(dsWaterScaleX);

        dsWaterScaleY = new QDoubleSpinBox(frWaterScale);
        dsWaterScaleY->setObjectName(QString::fromUtf8("dsWaterScaleY"));
        sizePolicy2.setHeightForWidth(dsWaterScaleY->sizePolicy().hasHeightForWidth());
        dsWaterScaleY->setSizePolicy(sizePolicy2);
        dsWaterScaleY->setMinimum(-1e+06);
        dsWaterScaleY->setMaximum(1e+06);
        dsWaterScaleY->setValue(1);

        hlWaterScale->addWidget(dsWaterScaleY);

        dsWaterScaleZ = new QDoubleSpinBox(frWaterScale);
        dsWaterScaleZ->setObjectName(QString::fromUtf8("dsWaterScaleZ"));
        sizePolicy2.setHeightForWidth(dsWaterScaleZ->sizePolicy().hasHeightForWidth());
        dsWaterScaleZ->setSizePolicy(sizePolicy2);
        dsWaterScaleZ->setMinimum(-1e+06);
        dsWaterScaleZ->setMaximum(1e+06);
        dsWaterScaleZ->setValue(1);

        hlWaterScale->addWidget(dsWaterScaleZ);


        flWaterParameters->setWidget(7, QFormLayout::SpanningRole, frWaterScale);

        frWaterSep00 = new QFrame(gbWaterParameters);
        frWaterSep00->setObjectName(QString::fromUtf8("frWaterSep00"));
        frWaterSep00->setMinimumSize(QSize(0, 10));

        flWaterParameters->setWidget(8, QFormLayout::SpanningRole, frWaterSep00);

        lbWaterNormal = new QLabel(gbWaterParameters);
        lbWaterNormal->setObjectName(QString::fromUtf8("lbWaterNormal"));

        flWaterParameters->setWidget(9, QFormLayout::SpanningRole, lbWaterNormal);

        frWaterNormal = new QFrame(gbWaterParameters);
        frWaterNormal->setObjectName(QString::fromUtf8("frWaterNormal"));
        hlWaterNormal = new QHBoxLayout(frWaterNormal);
        hlWaterNormal->setSpacing(6);
        hlWaterNormal->setContentsMargins(11, 11, 11, 11);
        hlWaterNormal->setObjectName(QString::fromUtf8("hlWaterNormal"));
        hlWaterNormal->setContentsMargins(0, 0, 0, 0);
        leWaterNormal = new QLineEdit(frWaterNormal);
        leWaterNormal->setObjectName(QString::fromUtf8("leWaterNormal"));
        leWaterNormal->setReadOnly(true);

        hlWaterNormal->addWidget(leWaterNormal);

        tbWaterNormal = new QToolButton(frWaterNormal);
        tbWaterNormal->setObjectName(QString::fromUtf8("tbWaterNormal"));
        sizePolicy4.setHeightForWidth(tbWaterNormal->sizePolicy().hasHeightForWidth());
        tbWaterNormal->setSizePolicy(sizePolicy4);

        hlWaterNormal->addWidget(tbWaterNormal);


        flWaterParameters->setWidget(10, QFormLayout::SpanningRole, frWaterNormal);

        lbWaterGroundNormal = new QLabel(gbWaterParameters);
        lbWaterGroundNormal->setObjectName(QString::fromUtf8("lbWaterGroundNormal"));

        flWaterParameters->setWidget(13, QFormLayout::SpanningRole, lbWaterGroundNormal);

        frWaterGroundNormal = new QFrame(gbWaterParameters);
        frWaterGroundNormal->setObjectName(QString::fromUtf8("frWaterGroundNormal"));
        hlWaterGroundNormal = new QHBoxLayout(frWaterGroundNormal);
        hlWaterGroundNormal->setSpacing(6);
        hlWaterGroundNormal->setContentsMargins(11, 11, 11, 11);
        hlWaterGroundNormal->setObjectName(QString::fromUtf8("hlWaterGroundNormal"));
        hlWaterGroundNormal->setContentsMargins(0, 0, 0, 0);
        leWaterGroundNormal = new QLineEdit(frWaterGroundNormal);
        leWaterGroundNormal->setObjectName(QString::fromUtf8("leWaterGroundNormal"));
        leWaterGroundNormal->setReadOnly(true);

        hlWaterGroundNormal->addWidget(leWaterGroundNormal);

        tbWaterGroundNormal = new QToolButton(frWaterGroundNormal);
        tbWaterGroundNormal->setObjectName(QString::fromUtf8("tbWaterGroundNormal"));
        sizePolicy4.setHeightForWidth(tbWaterGroundNormal->sizePolicy().hasHeightForWidth());
        tbWaterGroundNormal->setSizePolicy(sizePolicy4);

        hlWaterGroundNormal->addWidget(tbWaterGroundNormal);


        flWaterParameters->setWidget(14, QFormLayout::SpanningRole, frWaterGroundNormal);

        frWaterSep01 = new QFrame(gbWaterParameters);
        frWaterSep01->setObjectName(QString::fromUtf8("frWaterSep01"));
        frWaterSep01->setMinimumSize(QSize(0, 10));

        flWaterParameters->setWidget(15, QFormLayout::SpanningRole, frWaterSep01);

        frWaterInsert = new QFrame(gbWaterParameters);
        frWaterInsert->setObjectName(QString::fromUtf8("frWaterInsert"));
        hlWaterInsert = new QHBoxLayout(frWaterInsert);
        hlWaterInsert->setSpacing(5);
        hlWaterInsert->setContentsMargins(11, 11, 11, 11);
        hlWaterInsert->setObjectName(QString::fromUtf8("hlWaterInsert"));
        hlWaterInsert->setContentsMargins(0, 0, 0, 0);
        hsWaterInsert = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hlWaterInsert->addItem(hsWaterInsert);

        clWaterApply = new QCommandLinkButton(frWaterInsert);
        clWaterApply->setObjectName(QString::fromUtf8("clWaterApply"));
        clWaterApply->setMaximumSize(QSize(100, 16777215));

        hlWaterInsert->addWidget(clWaterApply);


        flWaterParameters->setWidget(16, QFormLayout::SpanningRole, frWaterInsert);

        lbWaterGroundColor = new QLabel(gbWaterParameters);
        lbWaterGroundColor->setObjectName(QString::fromUtf8("lbWaterGroundColor"));

        flWaterParameters->setWidget(12, QFormLayout::LabelRole, lbWaterGroundColor);

        frWaterGroundColor = new QFrame(gbWaterParameters);
        frWaterGroundColor->setObjectName(QString::fromUtf8("frWaterGroundColor"));
        hlWaterGroundColor = new QHBoxLayout(frWaterGroundColor);
        hlWaterGroundColor->setSpacing(5);
        hlWaterGroundColor->setContentsMargins(11, 11, 11, 11);
        hlWaterGroundColor->setObjectName(QString::fromUtf8("hlWaterGroundColor"));
        hlWaterGroundColor->setContentsMargins(0, 0, 0, 0);
        pbWaterGroundColor = new QPushButton(frWaterGroundColor);
        pbWaterGroundColor->setObjectName(QString::fromUtf8("pbWaterGroundColor"));
        sizePolicy3.setHeightForWidth(pbWaterGroundColor->sizePolicy().hasHeightForWidth());
        pbWaterGroundColor->setSizePolicy(sizePolicy3);

        hlWaterGroundColor->addWidget(pbWaterGroundColor);

        dsWaterGroundColor = new QDoubleSpinBox(frWaterGroundColor);
        dsWaterGroundColor->setObjectName(QString::fromUtf8("dsWaterGroundColor"));
        dsWaterGroundColor->setMinimum(-1000);
        dsWaterGroundColor->setMaximum(1000);
        dsWaterGroundColor->setSingleStep(0.1);
        dsWaterGroundColor->setValue(1);

        hlWaterGroundColor->addWidget(dsWaterGroundColor);


        flWaterParameters->setWidget(12, QFormLayout::FieldRole, frWaterGroundColor);

        lbWaterDepth = new QLabel(gbWaterParameters);
        lbWaterDepth->setObjectName(QString::fromUtf8("lbWaterDepth"));

        flWaterParameters->setWidget(11, QFormLayout::LabelRole, lbWaterDepth);

        dsWaterDepth = new QDoubleSpinBox(gbWaterParameters);
        dsWaterDepth->setObjectName(QString::fromUtf8("dsWaterDepth"));
        dsWaterDepth->setDecimals(3);
        dsWaterDepth->setMinimum(-1e+06);
        dsWaterDepth->setMaximum(1e+06);
        dsWaterDepth->setSingleStep(0.001);
        dsWaterDepth->setValue(-0.001);

        flWaterParameters->setWidget(11, QFormLayout::FieldRole, dsWaterDepth);


        formLayout_2->setWidget(1, QFormLayout::SpanningRole, gbWaterParameters);

        saWater->setWidget(swWater);

        vlWater->addWidget(saWater);

        tbRight->addTab(twWater, QString());
        twEnvironment = new QWidget();
        twEnvironment->setObjectName(QString::fromUtf8("twEnvironment"));
        vlEnvironment = new QVBoxLayout(twEnvironment);
        vlEnvironment->setSpacing(0);
        vlEnvironment->setContentsMargins(11, 11, 11, 11);
        vlEnvironment->setObjectName(QString::fromUtf8("vlEnvironment"));
        vlEnvironment->setContentsMargins(0, 0, 0, 0);
        saEnvironment = new QScrollArea(twEnvironment);
        saEnvironment->setObjectName(QString::fromUtf8("saEnvironment"));
        saEnvironment->setFrameShape(QFrame::NoFrame);
        saEnvironment->setFrameShadow(QFrame::Plain);
        saEnvironment->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        saEnvironment->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        saEnvironment->setWidgetResizable(true);
        swEnvironment = new QWidget();
        swEnvironment->setObjectName(QString::fromUtf8("swEnvironment"));
        swEnvironment->setGeometry(QRect(0, 0, 280, 784));
        formLayout_3 = new QFormLayout(swEnvironment);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_3->setHorizontalSpacing(5);
        formLayout_3->setVerticalSpacing(5);
        formLayout_3->setContentsMargins(5, 5, 5, 5);
        gbEnvironmentLighting = new QGroupBox(swEnvironment);
        gbEnvironmentLighting->setObjectName(QString::fromUtf8("gbEnvironmentLighting"));
        flEnvironmentLighting = new QFormLayout(gbEnvironmentLighting);
        flEnvironmentLighting->setSpacing(6);
        flEnvironmentLighting->setContentsMargins(11, 11, 11, 11);
        flEnvironmentLighting->setObjectName(QString::fromUtf8("flEnvironmentLighting"));
        flEnvironmentLighting->setHorizontalSpacing(5);
        flEnvironmentLighting->setVerticalSpacing(5);
        flEnvironmentLighting->setContentsMargins(5, 10, 5, 5);
        lbEnvironmentLightingSunDir = new QLabel(gbEnvironmentLighting);
        lbEnvironmentLightingSunDir->setObjectName(QString::fromUtf8("lbEnvironmentLightingSunDir"));

        flEnvironmentLighting->setWidget(0, QFormLayout::LabelRole, lbEnvironmentLightingSunDir);

        dsEnvironmentLightingSunDir = new QDoubleSpinBox(gbEnvironmentLighting);
        dsEnvironmentLightingSunDir->setObjectName(QString::fromUtf8("dsEnvironmentLightingSunDir"));
        dsEnvironmentLightingSunDir->setWrapping(true);
        dsEnvironmentLightingSunDir->setMinimum(-180);
        dsEnvironmentLightingSunDir->setMaximum(180);
        dsEnvironmentLightingSunDir->setSingleStep(10);
        dsEnvironmentLightingSunDir->setValue(10);

        flEnvironmentLighting->setWidget(0, QFormLayout::FieldRole, dsEnvironmentLightingSunDir);

        lbEnvironmentLightingSunHeight = new QLabel(gbEnvironmentLighting);
        lbEnvironmentLightingSunHeight->setObjectName(QString::fromUtf8("lbEnvironmentLightingSunHeight"));

        flEnvironmentLighting->setWidget(1, QFormLayout::LabelRole, lbEnvironmentLightingSunHeight);

        dsEnvironmentLightingSunHeight = new QDoubleSpinBox(gbEnvironmentLighting);
        dsEnvironmentLightingSunHeight->setObjectName(QString::fromUtf8("dsEnvironmentLightingSunHeight"));
        dsEnvironmentLightingSunHeight->setMaximum(90);
        dsEnvironmentLightingSunHeight->setSingleStep(10);
        dsEnvironmentLightingSunHeight->setValue(30);

        flEnvironmentLighting->setWidget(1, QFormLayout::FieldRole, dsEnvironmentLightingSunHeight);

        lbEnvironmentLightingSunColor = new QLabel(gbEnvironmentLighting);
        lbEnvironmentLightingSunColor->setObjectName(QString::fromUtf8("lbEnvironmentLightingSunColor"));

        flEnvironmentLighting->setWidget(2, QFormLayout::LabelRole, lbEnvironmentLightingSunColor);

        frEnvironmentLightingSunColor = new QFrame(gbEnvironmentLighting);
        frEnvironmentLightingSunColor->setObjectName(QString::fromUtf8("frEnvironmentLightingSunColor"));
        hlEnvironmentLightingSunColor = new QHBoxLayout(frEnvironmentLightingSunColor);
        hlEnvironmentLightingSunColor->setSpacing(5);
        hlEnvironmentLightingSunColor->setContentsMargins(11, 11, 11, 11);
        hlEnvironmentLightingSunColor->setObjectName(QString::fromUtf8("hlEnvironmentLightingSunColor"));
        hlEnvironmentLightingSunColor->setContentsMargins(0, 0, 0, 0);
        pbEnvironmentLightingSunColor = new QPushButton(frEnvironmentLightingSunColor);
        pbEnvironmentLightingSunColor->setObjectName(QString::fromUtf8("pbEnvironmentLightingSunColor"));
        sizePolicy3.setHeightForWidth(pbEnvironmentLightingSunColor->sizePolicy().hasHeightForWidth());
        pbEnvironmentLightingSunColor->setSizePolicy(sizePolicy3);

        hlEnvironmentLightingSunColor->addWidget(pbEnvironmentLightingSunColor);

        dsEnvironmentLightingSunColorPower = new QDoubleSpinBox(frEnvironmentLightingSunColor);
        dsEnvironmentLightingSunColorPower->setObjectName(QString::fromUtf8("dsEnvironmentLightingSunColorPower"));
        dsEnvironmentLightingSunColorPower->setMinimum(-1000);
        dsEnvironmentLightingSunColorPower->setMaximum(1000);
        dsEnvironmentLightingSunColorPower->setSingleStep(0.1);
        dsEnvironmentLightingSunColorPower->setValue(1);

        hlEnvironmentLightingSunColor->addWidget(dsEnvironmentLightingSunColorPower);


        flEnvironmentLighting->setWidget(2, QFormLayout::FieldRole, frEnvironmentLightingSunColor);

        lbEnvironmentLightingSunSpec = new QLabel(gbEnvironmentLighting);
        lbEnvironmentLightingSunSpec->setObjectName(QString::fromUtf8("lbEnvironmentLightingSunSpec"));

        flEnvironmentLighting->setWidget(3, QFormLayout::LabelRole, lbEnvironmentLightingSunSpec);

        frEnvironmentLightingSunSpec = new QFrame(gbEnvironmentLighting);
        frEnvironmentLightingSunSpec->setObjectName(QString::fromUtf8("frEnvironmentLightingSunSpec"));
        hlEnvironmentLightingSunSpec = new QHBoxLayout(frEnvironmentLightingSunSpec);
        hlEnvironmentLightingSunSpec->setSpacing(5);
        hlEnvironmentLightingSunSpec->setContentsMargins(11, 11, 11, 11);
        hlEnvironmentLightingSunSpec->setObjectName(QString::fromUtf8("hlEnvironmentLightingSunSpec"));
        hlEnvironmentLightingSunSpec->setContentsMargins(0, 0, 0, 0);
        pbEnvironmentLightingSunSpec = new QPushButton(frEnvironmentLightingSunSpec);
        pbEnvironmentLightingSunSpec->setObjectName(QString::fromUtf8("pbEnvironmentLightingSunSpec"));
        sizePolicy3.setHeightForWidth(pbEnvironmentLightingSunSpec->sizePolicy().hasHeightForWidth());
        pbEnvironmentLightingSunSpec->setSizePolicy(sizePolicy3);

        hlEnvironmentLightingSunSpec->addWidget(pbEnvironmentLightingSunSpec);

        dsEnvironmentLightingSunSpecPower = new QDoubleSpinBox(frEnvironmentLightingSunSpec);
        dsEnvironmentLightingSunSpecPower->setObjectName(QString::fromUtf8("dsEnvironmentLightingSunSpecPower"));
        dsEnvironmentLightingSunSpecPower->setMinimum(-1000);
        dsEnvironmentLightingSunSpecPower->setMaximum(1000);
        dsEnvironmentLightingSunSpecPower->setSingleStep(0.1);
        dsEnvironmentLightingSunSpecPower->setValue(1);

        hlEnvironmentLightingSunSpec->addWidget(dsEnvironmentLightingSunSpecPower);


        flEnvironmentLighting->setWidget(3, QFormLayout::FieldRole, frEnvironmentLightingSunSpec);

        lbEnvironmentLightingSunSpecPow = new QLabel(gbEnvironmentLighting);
        lbEnvironmentLightingSunSpecPow->setObjectName(QString::fromUtf8("lbEnvironmentLightingSunSpecPow"));

        flEnvironmentLighting->setWidget(4, QFormLayout::LabelRole, lbEnvironmentLightingSunSpecPow);

        dsEnvironmentLightingSunSpecPow = new QDoubleSpinBox(gbEnvironmentLighting);
        dsEnvironmentLightingSunSpecPow->setObjectName(QString::fromUtf8("dsEnvironmentLightingSunSpecPow"));
        dsEnvironmentLightingSunSpecPow->setMaximum(1e+06);
        dsEnvironmentLightingSunSpecPow->setValue(64);

        flEnvironmentLighting->setWidget(4, QFormLayout::FieldRole, dsEnvironmentLightingSunSpecPow);

        lbEnvironmentLightingSkyColor = new QLabel(gbEnvironmentLighting);
        lbEnvironmentLightingSkyColor->setObjectName(QString::fromUtf8("lbEnvironmentLightingSkyColor"));

        flEnvironmentLighting->setWidget(5, QFormLayout::LabelRole, lbEnvironmentLightingSkyColor);

        frEnvironmentLightingSkyColor = new QFrame(gbEnvironmentLighting);
        frEnvironmentLightingSkyColor->setObjectName(QString::fromUtf8("frEnvironmentLightingSkyColor"));
        hlEnvironmentLightingSkyColor = new QHBoxLayout(frEnvironmentLightingSkyColor);
        hlEnvironmentLightingSkyColor->setSpacing(5);
        hlEnvironmentLightingSkyColor->setContentsMargins(11, 11, 11, 11);
        hlEnvironmentLightingSkyColor->setObjectName(QString::fromUtf8("hlEnvironmentLightingSkyColor"));
        hlEnvironmentLightingSkyColor->setContentsMargins(0, 0, 0, 0);
        pbEnvironmentLightingSkyColor = new QPushButton(frEnvironmentLightingSkyColor);
        pbEnvironmentLightingSkyColor->setObjectName(QString::fromUtf8("pbEnvironmentLightingSkyColor"));
        sizePolicy3.setHeightForWidth(pbEnvironmentLightingSkyColor->sizePolicy().hasHeightForWidth());
        pbEnvironmentLightingSkyColor->setSizePolicy(sizePolicy3);

        hlEnvironmentLightingSkyColor->addWidget(pbEnvironmentLightingSkyColor);

        dsEnvironmentLightingSkyColorPower = new QDoubleSpinBox(frEnvironmentLightingSkyColor);
        dsEnvironmentLightingSkyColorPower->setObjectName(QString::fromUtf8("dsEnvironmentLightingSkyColorPower"));
        dsEnvironmentLightingSkyColorPower->setMinimum(-1000);
        dsEnvironmentLightingSkyColorPower->setMaximum(1000);
        dsEnvironmentLightingSkyColorPower->setSingleStep(0.1);
        dsEnvironmentLightingSkyColorPower->setValue(1);

        hlEnvironmentLightingSkyColor->addWidget(dsEnvironmentLightingSkyColorPower);


        flEnvironmentLighting->setWidget(5, QFormLayout::FieldRole, frEnvironmentLightingSkyColor);

        lbEnvironmentLightingAmbColor = new QLabel(gbEnvironmentLighting);
        lbEnvironmentLightingAmbColor->setObjectName(QString::fromUtf8("lbEnvironmentLightingAmbColor"));

        flEnvironmentLighting->setWidget(6, QFormLayout::LabelRole, lbEnvironmentLightingAmbColor);

        frEnvironmentLightingAmbColor = new QFrame(gbEnvironmentLighting);
        frEnvironmentLightingAmbColor->setObjectName(QString::fromUtf8("frEnvironmentLightingAmbColor"));
        hlEnvironmentLightingAmbColor = new QHBoxLayout(frEnvironmentLightingAmbColor);
        hlEnvironmentLightingAmbColor->setSpacing(5);
        hlEnvironmentLightingAmbColor->setContentsMargins(11, 11, 11, 11);
        hlEnvironmentLightingAmbColor->setObjectName(QString::fromUtf8("hlEnvironmentLightingAmbColor"));
        hlEnvironmentLightingAmbColor->setContentsMargins(0, 0, 0, 0);
        pbEnvironmentLightingAmbColor = new QPushButton(frEnvironmentLightingAmbColor);
        pbEnvironmentLightingAmbColor->setObjectName(QString::fromUtf8("pbEnvironmentLightingAmbColor"));
        sizePolicy3.setHeightForWidth(pbEnvironmentLightingAmbColor->sizePolicy().hasHeightForWidth());
        pbEnvironmentLightingAmbColor->setSizePolicy(sizePolicy3);

        hlEnvironmentLightingAmbColor->addWidget(pbEnvironmentLightingAmbColor);

        dsEnvironmentLightingAmbColorPower = new QDoubleSpinBox(frEnvironmentLightingAmbColor);
        dsEnvironmentLightingAmbColorPower->setObjectName(QString::fromUtf8("dsEnvironmentLightingAmbColorPower"));
        dsEnvironmentLightingAmbColorPower->setMinimum(-1000);
        dsEnvironmentLightingAmbColorPower->setMaximum(1000);
        dsEnvironmentLightingAmbColorPower->setSingleStep(0.1);
        dsEnvironmentLightingAmbColorPower->setValue(1);

        hlEnvironmentLightingAmbColor->addWidget(dsEnvironmentLightingAmbColorPower);


        flEnvironmentLighting->setWidget(6, QFormLayout::FieldRole, frEnvironmentLightingAmbColor);


        formLayout_3->setWidget(0, QFormLayout::SpanningRole, gbEnvironmentLighting);

        gbEnvironmentFog = new QGroupBox(swEnvironment);
        gbEnvironmentFog->setObjectName(QString::fromUtf8("gbEnvironmentFog"));
        flEnvironmentFog = new QFormLayout(gbEnvironmentFog);
        flEnvironmentFog->setSpacing(6);
        flEnvironmentFog->setContentsMargins(11, 11, 11, 11);
        flEnvironmentFog->setObjectName(QString::fromUtf8("flEnvironmentFog"));
        flEnvironmentFog->setHorizontalSpacing(5);
        flEnvironmentFog->setVerticalSpacing(5);
        flEnvironmentFog->setContentsMargins(5, 10, 5, 5);
        lbEnvironmentFogDist = new QLabel(gbEnvironmentFog);
        lbEnvironmentFogDist->setObjectName(QString::fromUtf8("lbEnvironmentFogDist"));

        flEnvironmentFog->setWidget(0, QFormLayout::LabelRole, lbEnvironmentFogDist);

        dsEnvironmentFogDist = new QDoubleSpinBox(gbEnvironmentFog);
        dsEnvironmentFogDist->setObjectName(QString::fromUtf8("dsEnvironmentFogDist"));
        dsEnvironmentFogDist->setMinimum(0);
        dsEnvironmentFogDist->setMaximum(1e+06);
        dsEnvironmentFogDist->setSingleStep(128);
        dsEnvironmentFogDist->setValue(1024);

        flEnvironmentFog->setWidget(0, QFormLayout::FieldRole, dsEnvironmentFogDist);

        lbEnvironmentFogHeight = new QLabel(gbEnvironmentFog);
        lbEnvironmentFogHeight->setObjectName(QString::fromUtf8("lbEnvironmentFogHeight"));

        flEnvironmentFog->setWidget(1, QFormLayout::LabelRole, lbEnvironmentFogHeight);

        dsEnvironmentFogHeight = new QDoubleSpinBox(gbEnvironmentFog);
        dsEnvironmentFogHeight->setObjectName(QString::fromUtf8("dsEnvironmentFogHeight"));
        dsEnvironmentFogHeight->setMaximum(1e+06);
        dsEnvironmentFogHeight->setSingleStep(100);
        dsEnvironmentFogHeight->setValue(200);

        flEnvironmentFog->setWidget(1, QFormLayout::FieldRole, dsEnvironmentFogHeight);

        lbEnvironmentFogWaterDist = new QLabel(gbEnvironmentFog);
        lbEnvironmentFogWaterDist->setObjectName(QString::fromUtf8("lbEnvironmentFogWaterDist"));

        flEnvironmentFog->setWidget(4, QFormLayout::LabelRole, lbEnvironmentFogWaterDist);

        dsEnvironmentFogWaterDist = new QDoubleSpinBox(gbEnvironmentFog);
        dsEnvironmentFogWaterDist->setObjectName(QString::fromUtf8("dsEnvironmentFogWaterDist"));
        dsEnvironmentFogWaterDist->setMinimum(0);
        dsEnvironmentFogWaterDist->setMaximum(1e+06);
        dsEnvironmentFogWaterDist->setSingleStep(128);
        dsEnvironmentFogWaterDist->setValue(128);

        flEnvironmentFog->setWidget(4, QFormLayout::FieldRole, dsEnvironmentFogWaterDist);

        lbEnvironmentFogWaterHeight = new QLabel(gbEnvironmentFog);
        lbEnvironmentFogWaterHeight->setObjectName(QString::fromUtf8("lbEnvironmentFogWaterHeight"));

        flEnvironmentFog->setWidget(5, QFormLayout::LabelRole, lbEnvironmentFogWaterHeight);

        dsEnvironmentFogWaterHeight = new QDoubleSpinBox(gbEnvironmentFog);
        dsEnvironmentFogWaterHeight->setObjectName(QString::fromUtf8("dsEnvironmentFogWaterHeight"));
        dsEnvironmentFogWaterHeight->setMaximum(1e+06);
        dsEnvironmentFogWaterHeight->setSingleStep(10);
        dsEnvironmentFogWaterHeight->setValue(10);

        flEnvironmentFog->setWidget(5, QFormLayout::FieldRole, dsEnvironmentFogWaterHeight);

        lbEnvironmentFogColor = new QLabel(gbEnvironmentFog);
        lbEnvironmentFogColor->setObjectName(QString::fromUtf8("lbEnvironmentFogColor"));

        flEnvironmentFog->setWidget(3, QFormLayout::LabelRole, lbEnvironmentFogColor);

        lbEnvironmentFogWaterColor = new QLabel(gbEnvironmentFog);
        lbEnvironmentFogWaterColor->setObjectName(QString::fromUtf8("lbEnvironmentFogWaterColor"));

        flEnvironmentFog->setWidget(7, QFormLayout::LabelRole, lbEnvironmentFogWaterColor);

        frEnvironmentFogColor = new QFrame(gbEnvironmentFog);
        frEnvironmentFogColor->setObjectName(QString::fromUtf8("frEnvironmentFogColor"));
        hlEnvironmentFogColor = new QHBoxLayout(frEnvironmentFogColor);
        hlEnvironmentFogColor->setSpacing(5);
        hlEnvironmentFogColor->setContentsMargins(11, 11, 11, 11);
        hlEnvironmentFogColor->setObjectName(QString::fromUtf8("hlEnvironmentFogColor"));
        hlEnvironmentFogColor->setContentsMargins(0, 0, 0, 0);
        pbEnvironmentFogColor = new QPushButton(frEnvironmentFogColor);
        pbEnvironmentFogColor->setObjectName(QString::fromUtf8("pbEnvironmentFogColor"));
        sizePolicy3.setHeightForWidth(pbEnvironmentFogColor->sizePolicy().hasHeightForWidth());
        pbEnvironmentFogColor->setSizePolicy(sizePolicy3);

        hlEnvironmentFogColor->addWidget(pbEnvironmentFogColor);

        dsEnvironmentFogColorPower = new QDoubleSpinBox(frEnvironmentFogColor);
        dsEnvironmentFogColorPower->setObjectName(QString::fromUtf8("dsEnvironmentFogColorPower"));
        dsEnvironmentFogColorPower->setMinimum(-1000);
        dsEnvironmentFogColorPower->setMaximum(1000);
        dsEnvironmentFogColorPower->setSingleStep(0.1);
        dsEnvironmentFogColorPower->setValue(1);

        hlEnvironmentFogColor->addWidget(dsEnvironmentFogColorPower);


        flEnvironmentFog->setWidget(3, QFormLayout::FieldRole, frEnvironmentFogColor);

        frEnvironmentFogWaterColor = new QFrame(gbEnvironmentFog);
        frEnvironmentFogWaterColor->setObjectName(QString::fromUtf8("frEnvironmentFogWaterColor"));
        hlEnvironmentFogWaterColor = new QHBoxLayout(frEnvironmentFogWaterColor);
        hlEnvironmentFogWaterColor->setSpacing(5);
        hlEnvironmentFogWaterColor->setContentsMargins(11, 11, 11, 11);
        hlEnvironmentFogWaterColor->setObjectName(QString::fromUtf8("hlEnvironmentFogWaterColor"));
        hlEnvironmentFogWaterColor->setContentsMargins(0, 0, 0, 0);
        pbEnvironmentFogWaterColor = new QPushButton(frEnvironmentFogWaterColor);
        pbEnvironmentFogWaterColor->setObjectName(QString::fromUtf8("pbEnvironmentFogWaterColor"));
        sizePolicy3.setHeightForWidth(pbEnvironmentFogWaterColor->sizePolicy().hasHeightForWidth());
        pbEnvironmentFogWaterColor->setSizePolicy(sizePolicy3);

        hlEnvironmentFogWaterColor->addWidget(pbEnvironmentFogWaterColor);

        dsEnvironmentFogWaterColorPower = new QDoubleSpinBox(frEnvironmentFogWaterColor);
        dsEnvironmentFogWaterColorPower->setObjectName(QString::fromUtf8("dsEnvironmentFogWaterColorPower"));
        dsEnvironmentFogWaterColorPower->setMinimum(-1000);
        dsEnvironmentFogWaterColorPower->setMaximum(1000);
        dsEnvironmentFogWaterColorPower->setSingleStep(0.1);
        dsEnvironmentFogWaterColorPower->setValue(1);

        hlEnvironmentFogWaterColor->addWidget(dsEnvironmentFogWaterColorPower);


        flEnvironmentFog->setWidget(7, QFormLayout::FieldRole, frEnvironmentFogWaterColor);

        lbEnvironmentFogStart = new QLabel(gbEnvironmentFog);
        lbEnvironmentFogStart->setObjectName(QString::fromUtf8("lbEnvironmentFogStart"));

        flEnvironmentFog->setWidget(2, QFormLayout::LabelRole, lbEnvironmentFogStart);

        dsEnvironmentFogStart = new QDoubleSpinBox(gbEnvironmentFog);
        dsEnvironmentFogStart->setObjectName(QString::fromUtf8("dsEnvironmentFogStart"));
        dsEnvironmentFogStart->setMinimum(-1e+06);
        dsEnvironmentFogStart->setMaximum(1e+06);
        dsEnvironmentFogStart->setSingleStep(10);

        flEnvironmentFog->setWidget(2, QFormLayout::FieldRole, dsEnvironmentFogStart);

        lbEnvironmentFogWaterStart = new QLabel(gbEnvironmentFog);
        lbEnvironmentFogWaterStart->setObjectName(QString::fromUtf8("lbEnvironmentFogWaterStart"));

        flEnvironmentFog->setWidget(6, QFormLayout::LabelRole, lbEnvironmentFogWaterStart);

        dsEnvironmentFogWaterStart = new QDoubleSpinBox(gbEnvironmentFog);
        dsEnvironmentFogWaterStart->setObjectName(QString::fromUtf8("dsEnvironmentFogWaterStart"));
        dsEnvironmentFogWaterStart->setMinimum(-1e+06);
        dsEnvironmentFogWaterStart->setMaximum(1e+06);
        dsEnvironmentFogWaterStart->setSingleStep(10);

        flEnvironmentFog->setWidget(6, QFormLayout::FieldRole, dsEnvironmentFogWaterStart);


        formLayout_3->setWidget(1, QFormLayout::SpanningRole, gbEnvironmentFog);

        saEnvironment->setWidget(swEnvironment);

        vlEnvironment->addWidget(saEnvironment);

        tbRight->addTab(twEnvironment, QString());

        hlCentral->addWidget(tbRight);

        frRightShow = new QFrame(wgCentral);
        frRightShow->setObjectName(QString::fromUtf8("frRightShow"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(frRightShow->sizePolicy().hasHeightForWidth());
        frRightShow->setSizePolicy(sizePolicy5);
        vlRightShow = new QVBoxLayout(frRightShow);
        vlRightShow->setSpacing(5);
        vlRightShow->setContentsMargins(11, 11, 11, 11);
        vlRightShow->setObjectName(QString::fromUtf8("vlRightShow"));
        vlRightShow->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vlRightShow->addItem(verticalSpacer);

        pbRightMenu = new QPushButton(frRightShow);
        pbRightMenu->setObjectName(QString::fromUtf8("pbRightMenu"));

        vlRightShow->addWidget(pbRightMenu);

        pbRightShow = new QPushButton(frRightShow);
        pbRightShow->setObjectName(QString::fromUtf8("pbRightShow"));

        vlRightShow->addWidget(pbRightShow);


        hlCentral->addWidget(frRightShow);

        CMainWindow->setCentralWidget(wgCentral);
        mbMain = new QMenuBar(CMainWindow);
        mbMain->setObjectName(QString::fromUtf8("mbMain"));
        mbMain->setGeometry(QRect(0, 0, 1200, 40));
        mnFile = new QMenu(mbMain);
        mnFile->setObjectName(QString::fromUtf8("mnFile"));
        mnObjects = new QMenu(mbMain);
        mnObjects->setObjectName(QString::fromUtf8("mnObjects"));
        mnHelp = new QMenu(mbMain);
        mnHelp->setObjectName(QString::fromUtf8("mnHelp"));
        CMainWindow->setMenuBar(mbMain);
        sbMain = new QStatusBar(CMainWindow);
        sbMain->setObjectName(QString::fromUtf8("sbMain"));
        CMainWindow->setStatusBar(sbMain);

        mbMain->addAction(mnFile->menuAction());
        mbMain->addAction(mnObjects->menuAction());
        mbMain->addAction(mnHelp->menuAction());
        mnFile->addAction(acNew);
        mnFile->addSeparator();
        mnFile->addAction(acOpen);
        mnFile->addAction(acSave);
        mnFile->addAction(acSaveAs);
        mnFile->addSeparator();
        mnFile->addAction(acExit);
        mnObjects->addAction(acAddTerrain);
        mnObjects->addAction(acAddWater);
        mnObjects->addSeparator();
        mnObjects->addAction(acDeleteTerrain);
        mnObjects->addAction(acDeleteWater);
        mnHelp->addAction(acViewHelp);
        mnHelp->addSeparator();
        mnHelp->addAction(acAbout);

        retranslateUi(CMainWindow);

        tbRight->setCurrentIndex(0);
        cbTerrainGrid->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(CMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CMainWindow)
    {
        CMainWindow->setWindowTitle(QApplication::translate("CMainWindow", "FractLand", 0, QApplication::UnicodeUTF8));
        acNew->setText(QApplication::translate("CMainWindow", "&New", 0, QApplication::UnicodeUTF8));
        acNew->setShortcut(QApplication::translate("CMainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        acOpen->setText(QApplication::translate("CMainWindow", "&Open...", 0, QApplication::UnicodeUTF8));
        acOpen->setShortcut(QApplication::translate("CMainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        acSave->setText(QApplication::translate("CMainWindow", "&Save", 0, QApplication::UnicodeUTF8));
        acSave->setShortcut(QApplication::translate("CMainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        acSaveAs->setText(QApplication::translate("CMainWindow", "Save &As...", 0, QApplication::UnicodeUTF8));
        acSaveAs->setShortcut(QApplication::translate("CMainWindow", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
        acExit->setText(QApplication::translate("CMainWindow", "&Exit", 0, QApplication::UnicodeUTF8));
        acExit->setShortcut(QApplication::translate("CMainWindow", "Alt+F4", 0, QApplication::UnicodeUTF8));
        acAddTerrain->setText(QApplication::translate("CMainWindow", "Add &Terrain", 0, QApplication::UnicodeUTF8));
        acAddTerrain->setShortcut(QApplication::translate("CMainWindow", "Ctrl+1", 0, QApplication::UnicodeUTF8));
        acAddWater->setText(QApplication::translate("CMainWindow", "Add &Water", 0, QApplication::UnicodeUTF8));
        acAddWater->setShortcut(QApplication::translate("CMainWindow", "Ctrl+2", 0, QApplication::UnicodeUTF8));
        acDeleteTerrain->setText(QApplication::translate("CMainWindow", "&Delete Terrain", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        acDeleteTerrain->setToolTip(QApplication::translate("CMainWindow", "Delete Terrain", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        acDeleteTerrain->setShortcut(QApplication::translate("CMainWindow", "Del", 0, QApplication::UnicodeUTF8));
        acViewHelp->setText(QApplication::translate("CMainWindow", "View &Help (Czech)", 0, QApplication::UnicodeUTF8));
        acViewHelp->setShortcut(QApplication::translate("CMainWindow", "F1", 0, QApplication::UnicodeUTF8));
        acAbout->setText(QApplication::translate("CMainWindow", "&About", 0, QApplication::UnicodeUTF8));
        acAbout->setShortcut(QApplication::translate("CMainWindow", "Ctrl+F1", 0, QApplication::UnicodeUTF8));
        acDeleteWater->setText(QApplication::translate("CMainWindow", "D&elete Water", 0, QApplication::UnicodeUTF8));
        acDeleteWater->setShortcut(QApplication::translate("CMainWindow", "Ctrl+Del", 0, QApplication::UnicodeUTF8));
        gbTerrainList->setTitle(QApplication::translate("CMainWindow", "Objects List", 0, QApplication::UnicodeUTF8));
        gbTerrainParameters->setTitle(QApplication::translate("CMainWindow", "Object Parameters", 0, QApplication::UnicodeUTF8));
        lbTerrainName->setText(QApplication::translate("CMainWindow", "Name:", 0, QApplication::UnicodeUTF8));
        lbTerrainPosition->setText(QApplication::translate("CMainWindow", "Position:", 0, QApplication::UnicodeUTF8));
        lbTerrainRotation->setText(QApplication::translate("CMainWindow", "Rotation:", 0, QApplication::UnicodeUTF8));
        lbTerrainScale->setText(QApplication::translate("CMainWindow", "Scale:", 0, QApplication::UnicodeUTF8));
        cbTerrainSeed->setText(QApplication::translate("CMainWindow", "Use Seed:", 0, QApplication::UnicodeUTF8));
        lbTerrainGrid->setText(QApplication::translate("CMainWindow", "Grid Size:", 0, QApplication::UnicodeUTF8));
        cbTerrainGrid->clear();
        cbTerrainGrid->insertItems(0, QStringList()
         << QApplication::translate("CMainWindow", "1 x 1 (1 x 1)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CMainWindow", "2 x 2 (1 x 1)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CMainWindow", "4 x 4 (1 x 1)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CMainWindow", "8 x 8 (1 x 1)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CMainWindow", "16 x 16 (1 x 1)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CMainWindow", "32 x 32 (2 x 2)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CMainWindow", "64 x 64 (4 x 4)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CMainWindow", "128 x 128 (8 x 8)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CMainWindow", "256 x 256 (16 x 16)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CMainWindow", "512 x 512 (32 x 32)", 0, QApplication::UnicodeUTF8)
        );
        cbTerrainLand->setText(QApplication::translate("CMainWindow", "Land Borders", 0, QApplication::UnicodeUTF8));
        lbTerrainHeightMul->setText(QApplication::translate("CMainWindow", "Height Multiplier:", 0, QApplication::UnicodeUTF8));
        lbTerrainDepthMul->setText(QApplication::translate("CMainWindow", "Depth Multiplier:", 0, QApplication::UnicodeUTF8));
        lbTerrainHeightMod1->setText(QApplication::translate("CMainWindow", "Height Modifier 1:", 0, QApplication::UnicodeUTF8));
        lbTerrainHeightMod2->setText(QApplication::translate("CMainWindow", "Height Modifier 2:", 0, QApplication::UnicodeUTF8));
        clTerrainApply->setText(QApplication::translate("CMainWindow", "Apply", 0, QApplication::UnicodeUTF8));
        gbTerrainLayers->setTitle(QApplication::translate("CMainWindow", "Texture Layers", 0, QApplication::UnicodeUTF8));
        pbTerrainLayersAdd->setText(QApplication::translate("CMainWindow", "Add", 0, QApplication::UnicodeUTF8));
        pbTerrainLayersDel->setText(QApplication::translate("CMainWindow", "Del", 0, QApplication::UnicodeUTF8));
        pbTerrainLayersUp->setText(QApplication::translate("CMainWindow", "Up", 0, QApplication::UnicodeUTF8));
        pbTerrainLayersDown->setText(QApplication::translate("CMainWindow", "Down", 0, QApplication::UnicodeUTF8));
        lbTerrainLayersColor->setText(QApplication::translate("CMainWindow", "Color:", 0, QApplication::UnicodeUTF8));
        pbTerrainLayersColor->setText(QApplication::translate("CMainWindow", "#ffffff", 0, QApplication::UnicodeUTF8));
        lbTerrainLayersNormal->setText(QApplication::translate("CMainWindow", "Detail Normal:", 0, QApplication::UnicodeUTF8));
        tbTerrainLayersNormal->setText(QApplication::translate("CMainWindow", "...", 0, QApplication::UnicodeUTF8));
        cbTerrainLayersHeight->setText(QApplication::translate("CMainWindow", "Use Height Limit:", 0, QApplication::UnicodeUTF8));
        cbTerrainLayersSlope->setText(QApplication::translate("CMainWindow", "Use Slope Limit:", 0, QApplication::UnicodeUTF8));
        tbRight->setTabText(tbRight->indexOf(twTerrain), QApplication::translate("CMainWindow", "Terrain", 0, QApplication::UnicodeUTF8));
        gbWaterList->setTitle(QApplication::translate("CMainWindow", "Objects List", 0, QApplication::UnicodeUTF8));
        gbWaterParameters->setTitle(QApplication::translate("CMainWindow", "Object Parameters", 0, QApplication::UnicodeUTF8));
        lbWaterName->setText(QApplication::translate("CMainWindow", "Name:", 0, QApplication::UnicodeUTF8));
        lbWaterPosition->setText(QApplication::translate("CMainWindow", "Position:", 0, QApplication::UnicodeUTF8));
        lbWaterRotation->setText(QApplication::translate("CMainWindow", "Rotation:", 0, QApplication::UnicodeUTF8));
        lbWaterScale->setText(QApplication::translate("CMainWindow", "Scale:", 0, QApplication::UnicodeUTF8));
        lbWaterNormal->setText(QApplication::translate("CMainWindow", "Normal:", 0, QApplication::UnicodeUTF8));
        tbWaterNormal->setText(QApplication::translate("CMainWindow", "...", 0, QApplication::UnicodeUTF8));
        lbWaterGroundNormal->setText(QApplication::translate("CMainWindow", "Ground Normal:", 0, QApplication::UnicodeUTF8));
        tbWaterGroundNormal->setText(QApplication::translate("CMainWindow", "...", 0, QApplication::UnicodeUTF8));
        clWaterApply->setText(QApplication::translate("CMainWindow", "Apply", 0, QApplication::UnicodeUTF8));
        lbWaterGroundColor->setText(QApplication::translate("CMainWindow", "Color:", 0, QApplication::UnicodeUTF8));
        pbWaterGroundColor->setText(QApplication::translate("CMainWindow", "#ffffff", 0, QApplication::UnicodeUTF8));
        lbWaterDepth->setText(QApplication::translate("CMainWindow", "Depth:", 0, QApplication::UnicodeUTF8));
        tbRight->setTabText(tbRight->indexOf(twWater), QApplication::translate("CMainWindow", "Water", 0, QApplication::UnicodeUTF8));
        gbEnvironmentLighting->setTitle(QApplication::translate("CMainWindow", "Lighting", 0, QApplication::UnicodeUTF8));
        lbEnvironmentLightingSunDir->setText(QApplication::translate("CMainWindow", "Sun Direction:", 0, QApplication::UnicodeUTF8));
        lbEnvironmentLightingSunHeight->setText(QApplication::translate("CMainWindow", "Sun Height:", 0, QApplication::UnicodeUTF8));
        lbEnvironmentLightingSunColor->setText(QApplication::translate("CMainWindow", "Sun Color:", 0, QApplication::UnicodeUTF8));
        pbEnvironmentLightingSunColor->setText(QApplication::translate("CMainWindow", "#ffffff", 0, QApplication::UnicodeUTF8));
        lbEnvironmentLightingSunSpec->setText(QApplication::translate("CMainWindow", "Sun Spec.:", 0, QApplication::UnicodeUTF8));
        pbEnvironmentLightingSunSpec->setText(QApplication::translate("CMainWindow", "#ffffff", 0, QApplication::UnicodeUTF8));
        lbEnvironmentLightingSunSpecPow->setText(QApplication::translate("CMainWindow", "Sun Spec. Pow.:", 0, QApplication::UnicodeUTF8));
        lbEnvironmentLightingSkyColor->setText(QApplication::translate("CMainWindow", "Sky Color:", 0, QApplication::UnicodeUTF8));
        pbEnvironmentLightingSkyColor->setText(QApplication::translate("CMainWindow", "#ffffff", 0, QApplication::UnicodeUTF8));
        lbEnvironmentLightingAmbColor->setText(QApplication::translate("CMainWindow", "Ambient Color:", 0, QApplication::UnicodeUTF8));
        pbEnvironmentLightingAmbColor->setText(QApplication::translate("CMainWindow", "#ffffff", 0, QApplication::UnicodeUTF8));
        gbEnvironmentFog->setTitle(QApplication::translate("CMainWindow", "Fog", 0, QApplication::UnicodeUTF8));
        lbEnvironmentFogDist->setText(QApplication::translate("CMainWindow", "Distance:", 0, QApplication::UnicodeUTF8));
        lbEnvironmentFogHeight->setText(QApplication::translate("CMainWindow", "Height:", 0, QApplication::UnicodeUTF8));
        lbEnvironmentFogWaterDist->setText(QApplication::translate("CMainWindow", "Water Distance:", 0, QApplication::UnicodeUTF8));
        lbEnvironmentFogWaterHeight->setText(QApplication::translate("CMainWindow", "Water Height:", 0, QApplication::UnicodeUTF8));
        lbEnvironmentFogColor->setText(QApplication::translate("CMainWindow", "Color:", 0, QApplication::UnicodeUTF8));
        lbEnvironmentFogWaterColor->setText(QApplication::translate("CMainWindow", "Water Color:", 0, QApplication::UnicodeUTF8));
        pbEnvironmentFogColor->setText(QApplication::translate("CMainWindow", "#ffffff", 0, QApplication::UnicodeUTF8));
        pbEnvironmentFogWaterColor->setText(QApplication::translate("CMainWindow", "#ffffff", 0, QApplication::UnicodeUTF8));
        lbEnvironmentFogStart->setText(QApplication::translate("CMainWindow", "Start:", 0, QApplication::UnicodeUTF8));
        lbEnvironmentFogWaterStart->setText(QApplication::translate("CMainWindow", "Water Start:", 0, QApplication::UnicodeUTF8));
        tbRight->setTabText(tbRight->indexOf(twEnvironment), QApplication::translate("CMainWindow", "Environment", 0, QApplication::UnicodeUTF8));
        pbRightMenu->setText(QApplication::translate("CMainWindow", "^", 0, QApplication::UnicodeUTF8));
        pbRightShow->setText(QApplication::translate("CMainWindow", "<", 0, QApplication::UnicodeUTF8));
        mnFile->setTitle(QApplication::translate("CMainWindow", "&File", 0, QApplication::UnicodeUTF8));
        mnObjects->setTitle(QApplication::translate("CMainWindow", "&Objects", 0, QApplication::UnicodeUTF8));
        mnHelp->setTitle(QApplication::translate("CMainWindow", "&Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CMainWindow: public Ui_CMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
