//------------------------------------------------------------------------------
#include "mainWindow.h"

//------------------------------------------------------------------------------
CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::CMainWindow), dialogFirstTime(true)
{
  ui->setupUi(this);

  styleDefault = styleSheet().split("\n");
#if defined(Q_OS_SYMBIAN) || defined(QT_SIMULATOR)
  QCoreApplication::setAttribute(Qt::AA_S60DisablePartialScreenInputMode, false);
  //setWindowFlags(windowFlags() | Qt::WindowSoftkeysVisibleHint);
  ui->wgView->getContext()->getCamera()->setTouchMode(true);
#endif

  //touchMode = true;
  float scale;

  if(ui->wgView->getContext()->getCamera()->getCamera()->touchMode)
    scale = 1.0f;
  else
    scale = 0.55f;

  updateStyle(scale, false);

  QList<QCheckBox *> cb = ui->wgCentral->findChildren<QCheckBox *>();
  QList<QRadioButton *> rb = ui->wgCentral->findChildren<QRadioButton *>();

  for(auto i = cb.begin(); i != cb.end(); i++)
    (*i)->setFocusPolicy(Qt::NoFocus);

  for(auto i = rb.begin(); i != rb.end(); i++)
    (*i)->setFocusPolicy(Qt::NoFocus);

  if(ui->wgView->getContext()->getCamera()->getCamera()->touchMode)
  {
    mnRight.setParent(this);
    QList<QMenu *> m = ui->mbMain->findChildren<QMenu *>();
    int ii = 0;
    for(auto i = m.begin(); (i != m.end()) && (ii < (m.size() - 1)); i++, ii++)
    {
      QList<QAction *> act = (*i)->actions();
      for(auto a = act.begin(); a != act.end(); a++)
        (*a)->setShortcuts(QList<QKeySequence>());
      mnRight.addMenu(*i);
    }
  }

  /*tbRightShow = new QTabBar(this);
  tbRightShow->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
  tbRightShow->setDocumentMode(true);
  tbRightShow->setExpanding(false);
  tbRightShow->setUsesScrollButtons(false);
  tbRightShow->addTab("<");
  tbRightShow->addTab("");
  tbRightShow->setCurrentIndex(1);
  ui->vlRightShow->addWidget(tbRightShow);
  int tbHeight = 54.545f * scale; //ui->tbRight->findChild<QTabBar *>()->height();
  ui->frRightShow->setMaximumWidth(tbHeight);
  ui->frRightShow->setMaximumHeight(tbHeight);
  tbRightShow->setStyleSheet(QString("QTabBar::tab { min-width: 0px; width: %1px; padding-left: 0px; padding-right: 0px; } QTabBar::tab:pressed { border: none; } ").arg(tbHeight));*/
  //ui->frRightShow->setMaximumWidth(ui->pbRightShow->height());

  if(ui->wgView->getContext()->getCamera()->getCamera()->touchMode)
  {
    ui->sbMain->hide();
    ui->tbRight->hide();
    ui->tbRight->setMaximumWidth(QWIDGETSIZE_MAX);
  }
  else
  {
    ui->frRightShow->hide();
    //ui->tbRight->setMaximumWidth(QWIDGETSIZE_MAX);
  }

  QLabel *lbStatus = new QLabel("Created by: Tomáš Růžička, (c) 2005 - 2015.                         Version: 1.00.2015.627                         www.djbozkosz.wz.cz");
  ui->sbMain->addWidget(lbStatus);
  lbStatus->setStyleSheet("margin: 0px 5px 0px 5px;");

  colorDialog.setOptions(QColorDialog::DontUseNativeDialog);

  //ui->tbRight->setTabEnabled(1, false);

  //connect(ui->pushButton_6, SIGNAL(clicked()), ui->wgView, SLOT(genTerrain()));

  connect(ui->pbRightMenu, SIGNAL(clicked()), this, SLOT(showRightMenu()));
  connect(ui->pbRightShow, SIGNAL(clicked()), this, SLOT(showRightPanel()));

  connect(ui->acAddTerrain, SIGNAL(triggered()), this, SLOT(addTerrain()));
  connect(ui->acDeleteTerrain, SIGNAL(triggered()), this, SLOT(delTerrain()));
  connect(ui->lwTerrainList, SIGNAL(currentRowChanged(int)), this, SLOT(updateTerrainParameters(int)));
  connect(ui->lwTerrainLayersList, SIGNAL(currentRowChanged(int)), this, SLOT(updateTerrainLayers(int)));
  connect(ui->cbTerrainSeed, SIGNAL(toggled(bool)), ui->sbTerrainSeed, SLOT(setEnabled(bool)));
  connect(ui->pbTerrainLayersAdd, SIGNAL(clicked()), this, SLOT(addTerrainLayer()));
  connect(ui->pbTerrainLayersDel, SIGNAL(clicked()), this, SLOT(delTerrainLayer()));
  connect(ui->pbTerrainLayersUp, SIGNAL(clicked()), this, SLOT(moveUpTerrainLayer()));
  connect(ui->pbTerrainLayersDown, SIGNAL(clicked()), this, SLOT(moveDownTerrainLayer()));
  connect(ui->pbTerrainLayersColor, SIGNAL(clicked()), this, SLOT(pickColor()));
  connect(ui->dsTerrainLayersColorPower, SIGNAL(valueChanged(double)), this, SLOT(terrainLayerApply()));
  connect(ui->tbTerrainLayersNormal, SIGNAL(clicked()), this, SLOT(selectPathImageDialog()));
  connect(ui->cbTerrainLayersHeight, SIGNAL(toggled(bool)), this, SLOT(terrainLayerApply()));
  connect(ui->cbTerrainLayersSlope, SIGNAL(toggled(bool)), this, SLOT(terrainLayerApply()));
  connect(ui->hsTerrainLayersHeightMin, SIGNAL(valueChanged(int)), this, SLOT(terrainLayerApply()));
  connect(ui->hsTerrainLayersHeightMax, SIGNAL(valueChanged(int)), this, SLOT(terrainLayerApply()));
  connect(ui->hsTerrainLayersSlopeMin, SIGNAL(valueChanged(int)), this, SLOT(terrainLayerApply()));
  connect(ui->hsTerrainLayersSlopeMax, SIGNAL(valueChanged(int)), this, SLOT(terrainLayerApply()));
  connect(ui->clTerrainApply, SIGNAL(clicked()), this, SLOT(terrainApply()));

  connect(ui->acAddWater, SIGNAL(triggered()), this, SLOT(addWater()));
  connect(ui->acDeleteWater, SIGNAL(triggered()), this, SLOT(delWater()));
  connect(ui->lwWaterList, SIGNAL(currentRowChanged(int)), this, SLOT(updateWaterParameters(int)));
  connect(ui->tbWaterNormal, SIGNAL(clicked()), this, SLOT(selectPathImageDialog()));
  connect(ui->pbWaterGroundColor, SIGNAL(clicked()), this, SLOT(pickColor()));
  connect(ui->tbWaterGroundNormal, SIGNAL(clicked()), this, SLOT(selectPathImageDialog()));
  connect(ui->clWaterApply, SIGNAL(clicked()), this, SLOT(waterApply()));

  connect(ui->dsEnvironmentLightingSunDir, SIGNAL(valueChanged(double)), this, SLOT(environmentApply()));
  connect(ui->dsEnvironmentLightingSunHeight, SIGNAL(valueChanged(double)), this, SLOT(environmentApply()));
  connect(ui->pbEnvironmentLightingSunColor, SIGNAL(clicked()), this, SLOT(pickColor()));
  connect(ui->dsEnvironmentLightingSunColorPower, SIGNAL(valueChanged(double)), this, SLOT(environmentApply()));
  connect(ui->pbEnvironmentLightingSunSpec, SIGNAL(clicked()), this, SLOT(pickColor()));
  connect(ui->dsEnvironmentLightingSunSpecPower, SIGNAL(valueChanged(double)), this, SLOT(environmentApply()));
  connect(ui->dsEnvironmentLightingSunSpecPow, SIGNAL(valueChanged(double)), this, SLOT(environmentApply()));
  connect(ui->pbEnvironmentLightingSkyColor, SIGNAL(clicked()), this, SLOT(pickColor()));
  connect(ui->dsEnvironmentLightingSkyColorPower, SIGNAL(valueChanged(double)), this, SLOT(environmentApply()));
  connect(ui->pbEnvironmentLightingAmbColor, SIGNAL(clicked()), this, SLOT(pickColor()));
  connect(ui->dsEnvironmentLightingAmbColorPower, SIGNAL(valueChanged(double)), this, SLOT(environmentApply()));

  connect(ui->dsEnvironmentFogDist, SIGNAL(valueChanged(double)), this, SLOT(environmentApply()));
  connect(ui->dsEnvironmentFogHeight, SIGNAL(valueChanged(double)), this, SLOT(environmentApply()));
  connect(ui->dsEnvironmentFogStart, SIGNAL(valueChanged(double)), this, SLOT(environmentApply()));
  connect(ui->pbEnvironmentFogColor, SIGNAL(clicked()), this, SLOT(pickColor()));
  connect(ui->dsEnvironmentFogColorPower, SIGNAL(valueChanged(double)), this, SLOT(environmentApply()));
  connect(ui->dsEnvironmentFogWaterDist, SIGNAL(valueChanged(double)), this, SLOT(environmentApply()));
  connect(ui->dsEnvironmentFogWaterHeight, SIGNAL(valueChanged(double)), this, SLOT(environmentApply()));
  connect(ui->dsEnvironmentFogWaterStart, SIGNAL(valueChanged(double)), this, SLOT(environmentApply()));
  connect(ui->pbEnvironmentFogWaterColor, SIGNAL(clicked()), this, SLOT(pickColor()));
  connect(ui->dsEnvironmentFogWaterColorPower, SIGNAL(valueChanged(double)), this, SLOT(environmentApply()));

  connect(ui->acNew, SIGNAL(triggered()), this, SLOT(newScene()));
  connect(ui->acOpen, SIGNAL(triggered()), this, SLOT(openScene()));
  connect(ui->acSave, SIGNAL(triggered()), this, SLOT(saveScene()));
  connect(ui->acSaveAs, SIGNAL(triggered()), this, SLOT(saveAsScene()));
  connect(ui->acExit, SIGNAL(triggered()), qApp, SLOT(quit()));
  connect(ui->acViewHelp, SIGNAL(triggered()), this, SLOT(showHelp()));
  connect(ui->acAbout, SIGNAL(triggered()), this, SLOT(showInfo()));

  QTimer::singleShot(0, this, SLOT(initGui()));
}
//------------------------------------------------------------------------------
CMainWindow::~CMainWindow()
{
  delete ui;
}
//------------------------------------------------------------------------------
void CMainWindow::initGui()
{
  //qDebug("initGui");
  updateTerrain(-1);
  updateWater(-1);
  updateEnvironment();
}
//------------------------------------------------------------------------------
void CMainWindow::updateTerrain(int index)
{
  //qDebug("updateTerrain");
  ui->lwTerrainList->blockSignals(true);
  ui->lwTerrainList->clear();
  uint32 count = ui->wgView->getContext()->getScene()->getSceneObjectsCount();
  for(uint32 i = 0; i < count; i++)
  {
    const SSceneObject *so = ui->wgView->getContext()->getScene()->getSceneObject(i)->getSceneObject();
    if(so->type == NScene::OBJECT_TYPE_TERRAIN)
      ui->lwTerrainList->addItem(so->name);
  }
  ui->lwTerrainList->setCurrentRow(index);
  ui->lwTerrainList->blockSignals(false);

  updateTerrainParameters(index);
}
//------------------------------------------------------------------------------
void CMainWindow::updateTerrainParameters(int index)
{
  //qDebug(QString("updateTerrainParameters %1").arg(index).toStdString().c_str());
  if(index == -2)
  { // set defaults
    ui->gbTerrainParameters->show();
    ui->leTerrainName->setText(QString("Terrain %1").arg(ui->lwTerrainList->count()));
    ui->dsTerrainPosX->setValue(0.0);
    ui->dsTerrainPosY->setValue(0.0);
    ui->dsTerrainPosZ->setValue(0.0);
    ui->dsTerrainRotX->setValue(0.0);
    ui->dsTerrainRotY->setValue(0.0);
    ui->dsTerrainRotZ->setValue(0.0);
    ui->dsTerrainScaleX->setValue(1000.0);
    ui->dsTerrainScaleY->setValue(1000.0);
    ui->dsTerrainScaleZ->setValue(1000.0);
    ui->cbTerrainSeed->setChecked(true);
    ui->sbTerrainSeed->setValue(132);
    ui->cbTerrainGrid->setCurrentIndex(8);
    ui->cbTerrainLand->setChecked(true);
    ui->dsTerrainHeightMul->setValue(0.3);
    ui->dsTerrainDepthMul->setValue(0.4);
    ui->dsTerrainHeightMod1->setValue(-0.1);
    ui->dsTerrainHeightMod2->setValue(0.2);
    terrainLayers.clear();
    updateTerrainLayers(-1);
  }
  else if(index == -1)
  { // hide
    ui->gbTerrainParameters->hide();
  }
  else
  { // set by selectecd
    ui->gbTerrainParameters->show();
    const SSceneObject *so = ui->wgView->getContext()->getScene()->getSceneObject(index, NScene::OBJECT_TYPE_TERRAIN)->getSceneObject();
    const STerrain *terr = dynamic_cast<CTerrain *>(so->model)->getTerrain();
    ui->leTerrainName->setText(so->name);
    ui->dsTerrainPosX->setValue(so->position.x());
    ui->dsTerrainPosY->setValue(so->position.y());
    ui->dsTerrainPosZ->setValue(so->position.z());
    QVector3D rot = SQuaternion::quat2angle(so->rotation);
    ui->dsTerrainRotX->setValue(rot.x());
    ui->dsTerrainRotY->setValue(rot.y());
    ui->dsTerrainRotZ->setValue(rot.z());
    ui->dsTerrainScaleX->setValue(so->scale.x());
    ui->dsTerrainScaleY->setValue(so->scale.y());
    ui->dsTerrainScaleZ->setValue(so->scale.z());
    ui->cbTerrainSeed->setChecked(true);
    ui->sbTerrainSeed->setValue(terr->seed);
    ui->cbTerrainGrid->setCurrentIndex(terr->stepX);
    ui->cbTerrainLand->setChecked(terr->landBorder);
    ui->dsTerrainHeightMul->setValue(terr->heightMultiplier);
    ui->dsTerrainDepthMul->setValue(terr->depthMultiplier);
    ui->dsTerrainHeightMod1->setValue(terr->heightModifier0);
    ui->dsTerrainHeightMod2->setValue(terr->heightModifier1);
    terrainLayers = terr->layers;
    updateTerrainLayers(-1);
  }
}
//------------------------------------------------------------------------------
void CMainWindow::updateTerrainLayers(int index)
{
  //qDebug(QString("updateTerrainLayers %1").arg(index).toStdString().c_str());
  ui->pbTerrainLayersUp->setEnabled(false);
  ui->pbTerrainLayersDown->setEnabled(false);
  ui->lwTerrainLayersList->blockSignals(true);
  ui->lwTerrainLayersList->clear();
  for(int32 i = 0; i < terrainLayers.size(); i++)
    ui->lwTerrainLayersList->addItem((terrainLayers[i].detailTexture) ? QFileInfo(terrainLayers[i].detailTexture->getMap()->file).fileName() : NMainWindow::STR_NO_TEXTURE);
  ui->lwTerrainLayersList->setCurrentRow(index);
  ui->lwTerrainLayersList->blockSignals(false);

  if(index == -1)
  {
    ui->frTerrainLayersParameters->hide();
    ui->pbTerrainLayersDel->setEnabled(false);
  }
  else
  {
    ui->frTerrainLayersParameters->show();
    int32 i = ui->lwTerrainLayersList->currentRow();
    ui->pbTerrainLayersDel->setEnabled(true);
    if(i > 0)
      ui->pbTerrainLayersUp->setEnabled(true);
    if(i < (ui->lwTerrainLayersList->count() - 1))
      ui->pbTerrainLayersDown->setEnabled(true);

    terrainBlockSignals(true);
    getColor(terrainLayers[i].color, ui->pbTerrainLayersColor, ui->dsTerrainLayersColorPower);
    ui->leTerrainLayersNormal->setText((terrainLayers[i].detailTexture) ? terrainLayers[i].detailTexture->getMap()->file : NMainWindow::STR_NO_TEXTURE);
    ui->cbTerrainLayersHeight->setChecked(terrainLayers[i].useHeightLimit);
    ui->frTerrainLayersHeight->setEnabled(terrainLayers[i].useHeightLimit);
    ui->hsTerrainLayersHeightMin->setValue(terrainLayers[i].minHeight * 100);
    ui->hsTerrainLayersHeightMax->setValue(terrainLayers[i].maxHeight * 100);
    ui->cbTerrainLayersSlope->setChecked(terrainLayers[i].useSlopeLimit);
    ui->frTerrainLayersSlope->setEnabled(terrainLayers[i].useSlopeLimit);
    ui->hsTerrainLayersSlopeMin->setValue(terrainLayers[i].minSlope * 100);
    ui->hsTerrainLayersSlopeMax->setValue(terrainLayers[i].maxSlope * 100);

    ui->hsTerrainLayersHeightMin->setToolTip(QString("%1").arg(terrainLayers[i].minHeight));
    ui->hsTerrainLayersHeightMax->setToolTip(QString("%1").arg(terrainLayers[i].maxHeight));
    ui->hsTerrainLayersSlopeMin->setToolTip(QString("%1").arg(terrainLayers[i].minSlope));
    ui->hsTerrainLayersSlopeMax->setToolTip(QString("%1").arg(terrainLayers[i].maxSlope));
    terrainBlockSignals(false);
  }
}
//------------------------------------------------------------------------------
void CMainWindow::terrainLayerApply()
{
  int32 i = ui->lwTerrainLayersList->currentRow();
  if(i == -1)
    return;

  //qDebug(QString("terrainLayerApply %1").arg(i).toStdString().c_str());
  terrainLayers[i].color = getColor2(ui->pbTerrainLayersColor, ui->dsTerrainLayersColorPower);
  terrainLayers[i].detailTexture = ((ui->leTerrainLayersNormal->text().length()) && (ui->leTerrainLayersNormal->text() != NMainWindow::STR_NO_TEXTURE)) ? ui->wgView->getContext()->getMaps()->addMap(SMap(ui->leTerrainLayersNormal->text(), QVector4D(0.5, 0.5, 1.0, 1.0))) : ui->wgView->getContext()->getMaps()->getMap(NMap::DEFAULT_NORMAL);
  ui->frTerrainLayersHeight->setEnabled(ui->cbTerrainLayersHeight->isChecked());
  terrainLayers[i].useHeightLimit = ui->cbTerrainLayersHeight->isChecked();
  terrainLayers[i].minHeight = static_cast<float>(ui->hsTerrainLayersHeightMin->value()) / 100.0f;
  terrainLayers[i].maxHeight = static_cast<float>(ui->hsTerrainLayersHeightMax->value()) / 100.0f;
  ui->frTerrainLayersSlope->setEnabled(ui->cbTerrainLayersSlope->isChecked());
  terrainLayers[i].useSlopeLimit = ui->cbTerrainLayersSlope->isChecked();
  terrainLayers[i].minSlope = static_cast<float>(ui->hsTerrainLayersSlopeMin->value()) / 100.0f;
  terrainLayers[i].maxSlope = static_cast<float>(ui->hsTerrainLayersSlopeMax->value()) / 100.0f;

  ui->hsTerrainLayersHeightMin->setToolTip(QString("%1").arg(terrainLayers[i].minHeight));
  ui->hsTerrainLayersHeightMax->setToolTip(QString("%1").arg(terrainLayers[i].maxHeight));
  ui->hsTerrainLayersSlopeMin->setToolTip(QString("%1").arg(terrainLayers[i].minSlope));
  ui->hsTerrainLayersSlopeMax->setToolTip(QString("%1").arg(terrainLayers[i].maxSlope));
}
//------------------------------------------------------------------------------
void CMainWindow::addTerrain()
{
  ui->gbTerrainList->hide();
  updateTerrainParameters(-2);

  if((ui->wgView->getContext()->getCamera()->getCamera()->touchMode) && (ui->tbRight->isVisible()))
    showRightPanel();

  // skip
  addTerrainInsert();
}
//------------------------------------------------------------------------------
void CMainWindow::delTerrain()
{
  int32 i = ui->lwTerrainList->currentRow();
  if(i == -1)
    return;

  CScene *s = ui->wgView->getContext()->getScene();
  s->removeSceneObject(s->getSceneObject(i, NScene::OBJECT_TYPE_TERRAIN));
  updateTerrain(-1);

  if((ui->wgView->getContext()->getCamera()->getCamera()->touchMode) && (ui->tbRight->isVisible()))
    showRightPanel();

  ui->wgView->update();
}
//------------------------------------------------------------------------------
SSceneObject CMainWindow::getSceneObjectTerrain()
{
  return SSceneObject(
    NScene::OBJECT_TYPE_TERRAIN,
    ui->leTerrainName->text(),
    QVector3D(ui->dsTerrainPosX->value(), ui->dsTerrainPosY->value(), ui->dsTerrainPosZ->value()),
    QQuaternion::fromAxisAndAngle(QVector3D(1.0, 0.0, 0.0), ui->dsTerrainRotX->value()) * QQuaternion::fromAxisAndAngle(QVector3D(0.0, 1.0, 0.0), ui->dsTerrainRotY->value()) * QQuaternion::fromAxisAndAngle(QVector3D(0.0, 0.0, 1.0), ui->dsTerrainRotZ->value()),
    QVector3D(ui->dsTerrainScaleX->value(), ui->dsTerrainScaleY->value(), ui->dsTerrainScaleZ->value()));
}
//------------------------------------------------------------------------------
STerrain CMainWindow::getTerrain()
{
  return STerrain(
    ui->cbTerrainSeed->isChecked() ? ui->sbTerrainSeed->value() : (QDateTime::currentMSecsSinceEpoch() % 1000000),
    ui->cbTerrainGrid->currentIndex(),
    ui->cbTerrainGrid->currentIndex(),
    NMainWindow::GRID_DIV_SIZES[ui->cbTerrainGrid->currentIndex()],
    NMainWindow::GRID_DIV_SIZES[ui->cbTerrainGrid->currentIndex()],
    ui->cbTerrainLand->isChecked(),
    ui->dsTerrainHeightMul->value(),
    ui->dsTerrainDepthMul->value(),
    ui->dsTerrainHeightMod1->value(),
    ui->dsTerrainHeightMod2->value(),
    terrainLayers);
}
//------------------------------------------------------------------------------
void CMainWindow::addTerrainInsert()
{
  //qDebug("addTerrainInsert");
  ui->wgView->getContext()->getScene()->addSceneObjectTerrain(getSceneObjectTerrain(), getTerrain());

  ui->gbTerrainList->show();
  uint32 count = ui->wgView->getContext()->getScene()->getSceneObjectsCount();
  uint32 c = 0;
  for(uint32 i = 0; i < count; i++)
  {
    if(ui->wgView->getContext()->getScene()->getSceneObject(i)->getSceneObject()->type == NScene::OBJECT_TYPE_TERRAIN)
      c++;
  }
  updateTerrain(c - 1);
  ui->wgView->update();
}
//------------------------------------------------------------------------------
void CMainWindow::addTerrainCancel()
{
  ui->gbTerrainList->show();
  updateTerrain(-1);
}
//------------------------------------------------------------------------------
void CMainWindow::terrainApply()
{
  int32 i = ui->lwTerrainList->currentRow();
  //qDebug(QString("%1").arg(i).toStdString().c_str());
  if(i == -1)
    return;

  if((ui->wgView->getContext()->getCamera()->getCamera()->touchMode) && (ui->tbRight->isVisible()))
    showRightPanel();

  ui->wgView->getContext()->getScene()->updateSceneObjectTerrain(i, getSceneObjectTerrain(), getTerrain());
  updateTerrain(i);
  ui->wgView->update();
}
//------------------------------------------------------------------------------
void CMainWindow::addTerrainLayer()
{
  terrainLayers.push_back(SMaterialLayer());
  updateTerrainLayers(terrainLayers.size() - 1);
}
//------------------------------------------------------------------------------
void CMainWindow::delTerrainLayer()
{
  terrainLayers.remove(ui->lwTerrainLayersList->currentRow());
  updateTerrainLayers(-1);
}
//------------------------------------------------------------------------------
void CMainWindow::moveUpTerrainLayer()
{
  int32 i = ui->lwTerrainLayersList->currentRow();
  SMaterialLayer second = terrainLayers[i - 1];
  terrainLayers[i - 1] = terrainLayers[i];
  terrainLayers[i] = second;
  updateTerrainLayers(i - 1);
}
//------------------------------------------------------------------------------
void CMainWindow::moveDownTerrainLayer()
{
  int32 i = ui->lwTerrainLayersList->currentRow();
  SMaterialLayer second = terrainLayers[i + 1];
  terrainLayers[i + 1] = terrainLayers[i];
  terrainLayers[i] = second;
  updateTerrainLayers(i + 1);
}
//------------------------------------------------------------------------------
void CMainWindow::terrainBlockSignals(bool signal)
{
  ui->pbTerrainLayersColor->blockSignals(signal);
  ui->dsTerrainLayersColorPower->blockSignals(signal);
  ui->tbTerrainLayersNormal->blockSignals(signal);
  ui->cbTerrainLayersHeight->blockSignals(signal);
  ui->cbTerrainLayersSlope->blockSignals(signal);
  ui->hsTerrainLayersHeightMin->blockSignals(signal);
  ui->hsTerrainLayersHeightMax->blockSignals(signal);
  ui->hsTerrainLayersSlopeMin->blockSignals(signal);
  ui->hsTerrainLayersSlopeMax->blockSignals(signal);
}
//------------------------------------------------------------------------------
void CMainWindow::updateWater(int index)
{
  ui->lwWaterList->blockSignals(true);
  ui->lwWaterList->clear();
  uint32 count = ui->wgView->getContext()->getScene()->getSceneObjectsCount();
  for(uint32 i = 0; i < count; i++)
  {
    const SSceneObject *so = ui->wgView->getContext()->getScene()->getSceneObject(i)->getSceneObject();
    if(so->type == NScene::OBJECT_TYPE_WATER)
      ui->lwWaterList->addItem(so->name);
  }
  ui->lwWaterList->setCurrentRow(index);
  ui->lwWaterList->blockSignals(false);

  updateWaterParameters(index);
}
//------------------------------------------------------------------------------
void CMainWindow::updateWaterParameters(int index)
{
  //qDebug(QString("updateWaterParameters %1").arg(index).toStdString().c_str());
  if(index == -2)
  { // set defaults
    ui->gbWaterParameters->show();
    ui->leWaterName->setText(QString("Water %1").arg(ui->lwWaterList->count()));
    ui->dsWaterPosX->setValue(0.0);
    ui->dsWaterPosY->setValue(0.0);
    ui->dsWaterPosZ->setValue(0.0);
    ui->dsWaterRotX->setValue(0.0);
    ui->dsWaterRotY->setValue(0.0);
    ui->dsWaterRotZ->setValue(0.0);
    ui->dsWaterScaleX->setValue(10000.0);
    ui->dsWaterScaleY->setValue(10000.0);
    ui->dsWaterScaleZ->setValue(10000.0);
    ui->leWaterNormal->setText(NMainWindow::STR_NO_TEXTURE);
    ui->dsWaterDepth->setValue(-0.001);
    getColor(QVector4D(1.0, 1.0, 1.0, 1.0), ui->pbWaterGroundColor, ui->dsWaterGroundColor);
    ui->leWaterGroundNormal->setText(NMainWindow::STR_NO_TEXTURE);
  }
  else if(index == -1)
  { // hide
    ui->gbWaterParameters->hide();
  }
  else
  { // set by selectecd
    ui->gbWaterParameters->show();
    const SSceneObject *so = ui->wgView->getContext()->getScene()->getSceneObject(index, NScene::OBJECT_TYPE_WATER)->getSceneObject();
    const SWater *wat = dynamic_cast<CWater *>(so->model)->getWater();
    ui->leWaterName->setText(so->name);
    ui->dsWaterPosX->setValue(so->position.x());
    ui->dsWaterPosY->setValue(so->position.y());
    ui->dsWaterPosZ->setValue(so->position.z());
    QVector3D rot = SQuaternion::quat2angle(so->rotation);
    ui->dsWaterRotX->setValue(rot.x());
    ui->dsWaterRotY->setValue(rot.y());
    ui->dsWaterRotZ->setValue(rot.z());
    ui->dsWaterScaleX->setValue(so->scale.x());
    ui->dsWaterScaleY->setValue(so->scale.y());
    ui->dsWaterScaleZ->setValue(so->scale.z());
    ui->leWaterNormal->setText((wat->detailTexture) ? wat->detailTexture->getMap()->file : NMainWindow::STR_NO_TEXTURE);
    ui->dsWaterDepth->setValue(wat->depth);
    getColor(wat->color, ui->pbWaterGroundColor, ui->dsWaterGroundColor);
    ui->leWaterGroundNormal->setText((wat->detailGroundTexture) ? wat->detailGroundTexture->getMap()->file : NMainWindow::STR_NO_TEXTURE);
  }
}
//------------------------------------------------------------------------------
void CMainWindow::addWater()
{
  ui->gbWaterList->hide();
  updateWaterParameters(-2);

  if((ui->wgView->getContext()->getCamera()->getCamera()->touchMode) && (ui->tbRight->isVisible()))
    showRightPanel();

  // skip
  addWaterInsert();
}
//------------------------------------------------------------------------------
void CMainWindow::delWater()
{
  int32 i = ui->lwWaterList->currentRow();
  if(i == -1)
    return;

  CScene *s = ui->wgView->getContext()->getScene();
  s->removeSceneObject(s->getSceneObject(i, NScene::OBJECT_TYPE_WATER));
  updateWater(-1);

  if((ui->wgView->getContext()->getCamera()->getCamera()->touchMode) && (ui->tbRight->isVisible()))
    showRightPanel();

  ui->wgView->update();
}
//------------------------------------------------------------------------------
SSceneObject CMainWindow::getSceneObjectWater()
{
  return SSceneObject(
    NScene::OBJECT_TYPE_WATER,
    ui->leWaterName->text(),
    QVector3D(ui->dsWaterPosX->value(), ui->dsWaterPosY->value(), ui->dsWaterPosZ->value()),
    QQuaternion::fromAxisAndAngle(QVector3D(1.0, 0.0, 0.0), ui->dsWaterRotX->value()) * QQuaternion::fromAxisAndAngle(QVector3D(0.0, 1.0, 0.0), ui->dsWaterRotY->value()) * QQuaternion::fromAxisAndAngle(QVector3D(0.0, 0.0, 1.0), ui->dsWaterRotZ->value()),
    QVector3D(ui->dsWaterScaleX->value(), ui->dsWaterScaleY->value(), ui->dsWaterScaleZ->value()));
}
//------------------------------------------------------------------------------
SWater CMainWindow::getWater()
{
#ifdef Q_OS_SYMBIAN
  QString path = "F:/FractLand/";
#else
  QString path = "";
#endif

  return SWater(
    ((ui->leWaterNormal->text().length()) && (ui->leWaterNormal->text() != NMainWindow::STR_NO_TEXTURE)) ? ui->wgView->getContext()->getMaps()->addMap(SMap(ui->leWaterNormal->text(), QVector4D(0.5, 0.5, 1.0, 1.0))) : ui->wgView->getContext()->getMaps()->getMap(NMap::DEFAULT_NORMAL),
    ui->wgView->getContext()->getMaps()->addMap(SMap(path+"data/maps/water00a.png", QVector4D(0.5, 0.5, 0.5, 1.0))),
    ui->wgView->getReflectionFramebuffer()->getFrameBuffer()->fboColorTexture,
    ui->dsWaterDepth->value(),
    getColor2(ui->pbWaterGroundColor, ui->dsWaterGroundColor),
    ((ui->leWaterGroundNormal->text().length()) && (ui->leWaterGroundNormal->text() != NMainWindow::STR_NO_TEXTURE)) ? ui->wgView->getContext()->getMaps()->addMap(SMap(ui->leWaterGroundNormal->text(), QVector4D(0.5, 0.5, 1.0, 1.0))) : ui->wgView->getContext()->getMaps()->getMap(NMap::DEFAULT_NORMAL));
}
//------------------------------------------------------------------------------
void CMainWindow::addWaterInsert()
{
  ui->wgView->getContext()->getScene()->addSceneObjectWater(getSceneObjectWater(), getWater());
  ui->gbWaterList->show();
  uint32 count = ui->wgView->getContext()->getScene()->getSceneObjectsCount();
  uint32 c = 0;
  for(uint32 i = 0; i < count; i++)
  {
    if(ui->wgView->getContext()->getScene()->getSceneObject(i)->getSceneObject()->type == NScene::OBJECT_TYPE_WATER)
      c++;
  }
  updateWater(c - 1);
  ui->wgView->update();
}
//------------------------------------------------------------------------------
void CMainWindow::addWaterCancel()
{
  ui->gbWaterList->show();
  updateWater(-1);
}
//------------------------------------------------------------------------------
void CMainWindow::waterApply()
{
  int32 i = ui->lwWaterList->currentRow();
  //qDebug(QString("%1").arg(i).toStdString().c_str());
  if(i == -1)
    return;

  if((ui->wgView->getContext()->getCamera()->getCamera()->touchMode) && (ui->tbRight->isVisible()))
    showRightPanel();

  ui->wgView->getContext()->getScene()->updateSceneObjectWater(i, getSceneObjectWater(), getWater());
  updateWater(i);
  ui->wgView->update();
}
//------------------------------------------------------------------------------
void CMainWindow::waterBlockSignals(bool signal)
{
  Q_UNUSED(signal);
  //ui->pbWaterLayersColor->blockSignals(signal); blocking...
}
//------------------------------------------------------------------------------
void CMainWindow::updateEnvironment()
{
  //qDebug("updateEnvironment");
  const SScene *s = ui->wgView->getContext()->getScene()->getScene();

  environmentBlockSignals(true);
  ui->dsEnvironmentLightingSunDir->setValue(s->sunDir);
  ui->dsEnvironmentLightingSunHeight->setValue(s->sunHeight);
  getColor(s->sunColor, ui->pbEnvironmentLightingSunColor, ui->dsEnvironmentLightingSunColorPower);
  getColor(s->sunSpec, ui->pbEnvironmentLightingSunSpec, ui->dsEnvironmentLightingSunSpecPower);
  ui->dsEnvironmentLightingSunSpecPow->setValue(s->sunPow);
  getColor(s->skyColor, ui->pbEnvironmentLightingSkyColor, ui->dsEnvironmentLightingSkyColorPower);
  getColor(s->ambColor, ui->pbEnvironmentLightingAmbColor, ui->dsEnvironmentLightingAmbColorPower);

  ui->dsEnvironmentFogDist->setValue(s->fogDist);
  ui->dsEnvironmentFogHeight->setValue(s->fogHeight);
  ui->dsEnvironmentFogStart->setValue(s->fogStart);
  getColor(s->fogColor, ui->pbEnvironmentFogColor, ui->dsEnvironmentFogColorPower);
  ui->dsEnvironmentFogWaterDist->setValue(s->fogWaterDist);
  ui->dsEnvironmentFogWaterHeight->setValue(s->fogWaterHeight);
  ui->dsEnvironmentFogWaterStart->setValue(s->fogWaterStart);
  getColor(s->fogWaterColor, ui->pbEnvironmentFogWaterColor, ui->dsEnvironmentFogWaterColorPower);
  environmentBlockSignals(false);
}
//------------------------------------------------------------------------------
void CMainWindow::environmentApply()
{
  //qDebug("environmentApply");
  SScene s = *ui->wgView->getContext()->getScene()->getScene();

  s.sunDir = ui->dsEnvironmentLightingSunDir->value();
  s.sunHeight = ui->dsEnvironmentLightingSunHeight->value();
  s.sunColor = getColor2(ui->pbEnvironmentLightingSunColor, ui->dsEnvironmentLightingSunColorPower);
  s.sunSpec = getColor2(ui->pbEnvironmentLightingSunSpec, ui->dsEnvironmentLightingSunSpecPower);
  s.sunPow = ui->dsEnvironmentLightingSunSpecPow->value();
  s.skyColor = getColor2(ui->pbEnvironmentLightingSkyColor, ui->dsEnvironmentLightingSkyColorPower);
  s.ambColor = getColor2(ui->pbEnvironmentLightingAmbColor, ui->dsEnvironmentLightingAmbColorPower);

  s.fogDist = ui->dsEnvironmentFogDist->value();
  s.fogHeight = ui->dsEnvironmentFogHeight->value();
  s.fogStart = ui->dsEnvironmentFogStart->value();
  s.fogColor = getColor2(ui->pbEnvironmentFogColor, ui->dsEnvironmentFogColorPower);
  s.fogWaterDist = ui->dsEnvironmentFogWaterDist->value();
  s.fogWaterHeight = ui->dsEnvironmentFogWaterHeight->value();
  s.fogWaterStart = ui->dsEnvironmentFogWaterStart->value();
  s.fogWaterColor = getColor2(ui->pbEnvironmentFogWaterColor, ui->dsEnvironmentFogWaterColorPower);

  ui->wgView->getContext()->getScene()->updateScene(s);
  ui->wgView->getContext()->getCamera()->setRange(NCamera::CLIP_NEAR, s.fogDist);
  ui->wgView->update();
}
//------------------------------------------------------------------------------
void CMainWindow::environmentBlockSignals(bool signal)
{
  ui->dsEnvironmentLightingSunDir->blockSignals(signal);
  ui->dsEnvironmentLightingSunHeight->blockSignals(signal);
  ui->pbEnvironmentLightingSunColor->blockSignals(signal);
  ui->dsEnvironmentLightingSunColorPower->blockSignals(signal);
  ui->pbEnvironmentLightingSunSpec->blockSignals(signal);
  ui->dsEnvironmentLightingSunSpecPower->blockSignals(signal);
  ui->dsEnvironmentLightingSunSpecPow->blockSignals(signal);
  ui->pbEnvironmentLightingSkyColor->blockSignals(signal);
  ui->dsEnvironmentLightingSkyColorPower->blockSignals(signal);
  ui->pbEnvironmentLightingAmbColor->blockSignals(signal);
  ui->dsEnvironmentLightingAmbColorPower->blockSignals(signal);

  ui->dsEnvironmentFogDist->blockSignals(signal);
  ui->dsEnvironmentFogHeight->blockSignals(signal);
  ui->dsEnvironmentFogStart->blockSignals(signal);
  ui->pbEnvironmentFogColor->blockSignals(signal);
  ui->dsEnvironmentFogColorPower->blockSignals(signal);
  ui->dsEnvironmentFogWaterDist->blockSignals(signal);
  ui->dsEnvironmentFogWaterHeight->blockSignals(signal);
  ui->dsEnvironmentFogWaterStart->blockSignals(signal);
  ui->pbEnvironmentFogWaterColor->blockSignals(signal);
  ui->dsEnvironmentFogWaterColorPower->blockSignals(signal);
}
//------------------------------------------------------------------------------
void CMainWindow::getColor(const QVector4D &color, QPushButton *pb, QDoubleSpinBox *ds)
{
  QString c = QColor(color.x() * 255, color.y() * 255, color.z() * 255).name();
  pb->setText(c);
  pb->setStyleSheet("QPushButton { background-color: "+c+"; color: #808080; border-image: none; border: 1px solid #808080; border-radius: 8px; }");
  ds->setValue(color.w());
}
//------------------------------------------------------------------------------
QVector4D CMainWindow::getColor2(QPushButton *pb, QDoubleSpinBox *ds)
{
  QColor color(pb->text());
  return QVector4D(static_cast<float>(color.red()) / 255.0f, static_cast<float>(color.green()) / 255.0f, static_cast<float>(color.blue()) / 255.0f, ds->value());
}
//------------------------------------------------------------------------------
void CMainWindow::pickColor()
{
  QPushButton *pb = dynamic_cast<QPushButton *>(sender());
  colorDialog.setCurrentColor(pb ? QColor(pb->text()) : QColor());
  if(!colorDialog.exec())
    return;
  QColor color = colorDialog.selectedColor();

  if(pb)
  {
    pb->setText(color.name());
    pb->setStyleSheet("QPushButton { background-color: "+pb->text()+"; color: #808080; border-image: none; border: 1px solid #808080; border-radius: 8px; }");

    if(pb == ui->pbTerrainLayersColor)
      terrainLayerApply();
    else
      environmentApply();
  }
}
//------------------------------------------------------------------------------
void CMainWindow::selectPathImageDialog()
{
  QString file = QFileDialog::getOpenFileName(this, "Open File", dialogFirstTime ? /*QString::fromLocal8Bit(getenv("userprofile"))*/ QDir::currentPath() : dialogPath, "Image: (*.png *.bmp *.jpg *.gif)", 0, QFileDialog::ReadOnly);
  if(!file.length())
    return;

  dialogFirstTime = false;
  dialogPath = QFileInfo(file).path();

  if(sender() == ui->tbTerrainLayersNormal)
  {
    ui->leTerrainLayersNormal->setText((file.length()) ? file : NMainWindow::STR_NO_TEXTURE);
    ui->lwTerrainLayersList->currentItem()->setText(QFileInfo(file).fileName());
    terrainLayerApply();
  }
  else if(sender() == ui->tbWaterNormal)
    ui->leWaterNormal->setText((file.length()) ? file : NMainWindow::STR_NO_TEXTURE);
  else if(sender() == ui->tbWaterGroundNormal)
    ui->leWaterGroundNormal->setText((file.length()) ? file : NMainWindow::STR_NO_TEXTURE);
}
//------------------------------------------------------------------------------
void CMainWindow::newScene()
{
  ui->wgView->getContext()->getScene()->clearScene();
  initGui();

  if((ui->wgView->getContext()->getCamera()->getCamera()->touchMode) && (ui->tbRight->isVisible()))
    showRightPanel();

  ui->wgView->update();
}
//------------------------------------------------------------------------------
void CMainWindow::openScene()
{
  QString file = QFileDialog::getOpenFileName(this, "Open File", dialogFirstTime ? /*QString::fromLocal8Bit(getenv("userprofile"))*/ QDir::currentPath() : dialogPath, "Text file: (*.txt)", 0, QFileDialog::ReadOnly);
  if(!file.length())
    return;

  dialogFirstTime = false;
  dialogPath = QFileInfo(file).path();
  fileOpened = file;

  if((ui->wgView->getContext()->getCamera()->getCamera()->touchMode) && (ui->tbRight->isVisible()))
    showRightPanel();

  loadSceneFile();
  ui->wgView->update();
}
//------------------------------------------------------------------------------
void CMainWindow::saveScene()
{
  if(!fileOpened.length())
    saveAsScene();
  else
    saveSceneFile();
}
//------------------------------------------------------------------------------
void CMainWindow::saveAsScene()
{
  QString file = QFileDialog::getSaveFileName(this, "Save File", dialogFirstTime ? /*QString::fromLocal8Bit(getenv("userprofile"))*/ QDir::currentPath() : dialogPath, "Text file: (*.txt)");
  if(!file.length())
    return;

  dialogFirstTime = false;
  dialogPath = QFileInfo(file).path();
  fileOpened = file;

  if((ui->wgView->getContext()->getCamera()->getCamera()->touchMode) && (ui->tbRight->isVisible()))
    showRightPanel();

  saveSceneFile();
  ui->wgView->update();
}
//------------------------------------------------------------------------------
void CMainWindow::loadSceneFile()
{
#ifdef Q_OS_SYMBIAN
  QString path = "F:/FractLand/";
#else
  QString path = "";
#endif

  QFile f(fileOpened);
  if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    qDebug("Unable to open scene!");
    return;
  }
  QString text = f.readAll();
  f.close();

  //qDebug(text.toStdString().c_str());

  ui->wgView->getContext()->getScene()->clearScene();
  QStringList t = text.split("\n", QString::SkipEmptyParts);
  for(int32 s = 0; s < t.size(); s++)
  {
    if(t[s] == "___terr")
    {
      //qDebug("new terr");
      SSceneObject so;
      STerrain terr;
      so.type = NScene::OBJECT_TYPE_TERRAIN;
      s++;
      so.name = t[s++];
      so.position = QVector3D(t[s].toFloat(), t[s + 1].toFloat(), t[s + 2].toFloat()); s += 3;
      so.rotation = QQuaternion::fromAxisAndAngle(QVector3D(1.0, 0.0, 0.0), t[s].toFloat()) * QQuaternion::fromAxisAndAngle(QVector3D(0.0, 1.0, 0.0), t[s + 1].toFloat()) * QQuaternion::fromAxisAndAngle(QVector3D(0.0, 0.0, 1.0), t[s + 2].toFloat()); s += 3;
      so.scale = QVector3D(t[s].toFloat(), t[s + 1].toFloat(), t[s + 2].toFloat()); s += 3;
      terr.seed = t[s++].toUInt();
      terr.stepX = t[s++].toUInt();
      terr.stepZ = terr.stepX;
      terr.divStepX = NMainWindow::GRID_DIV_SIZES[terr.stepX];
      terr.divStepZ = NMainWindow::GRID_DIV_SIZES[terr.stepX];
      terr.landBorder = t[s++].toUInt();
      terr.heightMultiplier = t[s++].toFloat();
      terr.depthMultiplier = t[s++].toFloat();
      terr.heightModifier0 = t[s++].toFloat();
      terr.heightModifier1 = t[s++].toFloat();

      if(t[s] == "___terr_layer")
      {
        for(; s < t.size(); s++)
        {
          //qDebug(QString("Token: \""+t[s - 1]+"\" \""+t[s]+"\" \""+t[s + 1]+"\"!").toStdString().c_str());
          if(t[s] == "___terr_layer")
          {
            //qDebug("new terr layer");
            SMaterialLayer ml;
            s++;
            ml.color = QVector4D(t[s].toFloat(), t[s + 1].toFloat(), t[s + 2].toFloat(), t[s + 3].toFloat()); s += 4;
            ml.detailTexture = (t[s] != "NULL") ? ui->wgView->getContext()->getMaps()->addMap(SMap(t[s], QVector4D(0.5, 0.5, 1.0, 1.0))) : NULL; s++;
            ml.useHeightLimit = t[s++].toUInt();
            ml.minHeight = t[s++].toFloat();
            ml.maxHeight = t[s++].toFloat();
            ml.useSlopeLimit = t[s++].toUInt();
            ml.minSlope = t[s++].toFloat();
            ml.maxSlope = t[s].toFloat();
            terr.layers.push_back(ml);
          }
          else
            break;
        }
      }
      s--;

      ui->wgView->getContext()->getScene()->addSceneObjectTerrain(so, terr);
    }
    else if(t[s] == "___water")
    {
      SSceneObject so;
      SWater wat;
      so.type = NScene::OBJECT_TYPE_WATER;
      s++;
      so.name = t[s++];
      so.position = QVector3D(t[s].toFloat(), t[s + 1].toFloat(), t[s + 2].toFloat()); s += 3;
      so.rotation = QQuaternion::fromAxisAndAngle(QVector3D(1.0, 0.0, 0.0), t[s].toFloat()) * QQuaternion::fromAxisAndAngle(QVector3D(0.0, 1.0, 0.0), t[s + 1].toFloat()) * QQuaternion::fromAxisAndAngle(QVector3D(0.0, 0.0, 1.0), t[s + 2].toFloat()); s += 3;
      so.scale = QVector3D(t[s].toFloat(), t[s + 1].toFloat(), t[s + 2].toFloat()); s += 3;
      wat.detailTexture = (t[s] != "NULL") ? ui->wgView->getContext()->getMaps()->addMap(SMap(t[s], QVector4D(0.5, 0.5, 1.0, 1.0))) : NULL; s++;
      wat.windTexture = ui->wgView->getContext()->getMaps()->addMap(SMap(path+"data/maps/water00a.png", QVector4D(0.5, 0.5, 0.5, 1.0)));
      wat.environmentTexture = ui->wgView->getReflectionFramebuffer()->getFrameBuffer()->fboColorTexture;
      wat.depth = t[s++].toFloat();
      wat.color = QVector4D(t[s].toFloat(), t[s + 1].toFloat(), t[s + 2].toFloat(), t[s + 3].toFloat()); s += 4;
      wat.detailGroundTexture = (t[s] != "NULL") ? ui->wgView->getContext()->getMaps()->addMap(SMap(t[s], QVector4D(0.5, 0.5, 1.0, 1.0))) : NULL;

      ui->wgView->getContext()->getScene()->addSceneObjectWater(so, wat);
    }
    else if(t[s] == "___env")
    {
      //qDebug("new env");
      SScene sc;
      s++;
      sc.sunDir = t[s++].toFloat();
      sc.sunHeight = t[s++].toFloat();
      sc.sunColor = QVector4D(t[s].toFloat(), t[s + 1].toFloat(), t[s + 2].toFloat(), t[s + 3].toFloat()); s += 4;
      sc.sunSpec = QVector4D(t[s].toFloat(), t[s + 1].toFloat(), t[s + 2].toFloat(), t[s + 3].toFloat()); s += 4;
      sc.sunPow = t[s++].toFloat();
      sc.skyColor = QVector4D(t[s].toFloat(), t[s + 1].toFloat(), t[s + 2].toFloat(), t[s + 3].toFloat()); s += 4;
      sc.ambColor = QVector4D(t[s].toFloat(), t[s + 1].toFloat(), t[s + 2].toFloat(), t[s + 3].toFloat()); s += 4;

      sc.fogDist = t[s++].toFloat();
      sc.fogHeight = t[s++].toFloat();
      sc.fogStart = t[s++].toFloat();
      sc.fogColor = QVector4D(t[s].toFloat(), t[s + 1].toFloat(), t[s + 2].toFloat(), t[s + 3].toFloat()); s += 4;
      sc.fogWaterDist = t[s++].toFloat();
      sc.fogWaterHeight = t[s++].toFloat();
      sc.fogWaterStart = t[s++].toFloat();
      sc.fogWaterColor = QVector4D(t[s].toFloat(), t[s + 1].toFloat(), t[s + 2].toFloat(), t[s + 3].toFloat()); s += 3;

      ui->wgView->getContext()->getScene()->updateScene(sc);
      break;
    }
    else
    {
      qDebug(QString("Undefined token: \""+t[s]+"\"!").toStdString().c_str());
      break;
    }
  }

  initGui();
  qDebug("Loaded.");
}
//------------------------------------------------------------------------------
void CMainWindow::saveSceneFile()
{
  QString text;
  uint32 count = ui->wgView->getContext()->getScene()->getSceneObjectsCount();
  for(uint32 i = 0; i < count; i++)
  {
    const SSceneObject *so = ui->wgView->getContext()->getScene()->getSceneObject(i)->getSceneObject();
    const STerrain *terr = dynamic_cast<CTerrain *>(so->model)->getTerrain();
    const SWater *wat = dynamic_cast<CWater *>(so->model)->getWater();
    if(so->type == NScene::OBJECT_TYPE_TERRAIN)
    {
      text += "___terr\n";
      text += so->name+"\n";
      text += QString("%1\n").arg(so->position.x());
      text += QString("%1\n").arg(so->position.y());
      text += QString("%1\n").arg(so->position.z());
      QVector3D rot = SQuaternion::quat2angle(so->rotation);
      text += QString("%1\n").arg(rot.x());
      text += QString("%1\n").arg(rot.y());
      text += QString("%1\n").arg(rot.z());
      text += QString("%1\n").arg(so->scale.x());
      text += QString("%1\n").arg(so->scale.y());
      text += QString("%1\n").arg(so->scale.z());
      text += QString("%1\n").arg(terr->seed);
      text += QString("%1\n").arg(terr->stepX);
      text += QString((terr->landBorder) ? "1" : "0")+"\n";
      text += QString("%1\n").arg(terr->heightMultiplier);
      text += QString("%1\n").arg(terr->depthMultiplier);
      text += QString("%1\n").arg(terr->heightModifier0);
      text += QString("%1\n").arg(terr->heightModifier1);

      for(auto s = terr->layers.constBegin(); s != terr->layers.constEnd(); s++)
      {
        text += "___terr_layer\n";
        text += QString("%1\n").arg(s->color.x());
        text += QString("%1\n").arg(s->color.y());
        text += QString("%1\n").arg(s->color.z());
        text += QString("%1\n").arg(s->color.w());
        text += QString((s->detailTexture) ? s->detailTexture->getMap()->file : "NULL")+"\n";
        text += QString((s->useHeightLimit) ? "1" : "0")+"\n";
        text += QString("%1\n").arg(s->minHeight);
        text += QString("%1\n").arg(s->maxHeight);
        text += QString((s->useSlopeLimit) ? "1" : "0")+"\n";
        text += QString("%1\n").arg(s->minSlope);
        text += QString("%1\n").arg(s->maxSlope);
      }
    }
    else if(so->type == NScene::OBJECT_TYPE_WATER)
    {
      text += "___water\n";
      text += so->name+"\n";
      text += QString("%1\n").arg(so->position.x());
      text += QString("%1\n").arg(so->position.y());
      text += QString("%1\n").arg(so->position.z());
      QVector3D rot = SQuaternion::quat2angle(so->rotation);
      text += QString("%1\n").arg(rot.x());
      text += QString("%1\n").arg(rot.y());
      text += QString("%1\n").arg(rot.z());
      text += QString("%1\n").arg(so->scale.x());
      text += QString("%1\n").arg(so->scale.y());
      text += QString("%1\n").arg(so->scale.z());
      text += QString((wat->detailTexture) ? wat->detailTexture->getMap()->file : "NULL")+"\n";
      text += QString("%1\n").arg(wat->depth);
      text += QString("%1\n").arg(wat->color.x());
      text += QString("%1\n").arg(wat->color.y());
      text += QString("%1\n").arg(wat->color.z());
      text += QString("%1\n").arg(wat->color.w());
      text += QString((wat->detailGroundTexture) ? wat->detailGroundTexture->getMap()->file : "NULL")+"\n";
    }
  }
  const SScene *s = ui->wgView->getContext()->getScene()->getScene();
  text += "___env\n";
  text += QString("%1\n").arg(s->sunDir);
  text += QString("%1\n").arg(s->sunHeight);
  text += QString("%1\n").arg(s->sunColor.x());
  text += QString("%1\n").arg(s->sunColor.y());
  text += QString("%1\n").arg(s->sunColor.z());
  text += QString("%1\n").arg(s->sunColor.w());
  text += QString("%1\n").arg(s->sunSpec.x());
  text += QString("%1\n").arg(s->sunSpec.y());
  text += QString("%1\n").arg(s->sunSpec.z());
  text += QString("%1\n").arg(s->sunSpec.w());
  text += QString("%1\n").arg(s->sunPow);
  text += QString("%1\n").arg(s->skyColor.x());
  text += QString("%1\n").arg(s->skyColor.y());
  text += QString("%1\n").arg(s->skyColor.z());
  text += QString("%1\n").arg(s->skyColor.w());
  text += QString("%1\n").arg(s->ambColor.x());
  text += QString("%1\n").arg(s->ambColor.y());
  text += QString("%1\n").arg(s->ambColor.z());
  text += QString("%1\n").arg(s->ambColor.w());

  text += QString("%1\n").arg(s->fogDist);
  text += QString("%1\n").arg(s->fogHeight);
  text += QString("%1\n").arg(s->fogStart);
  text += QString("%1\n").arg(s->fogColor.x());
  text += QString("%1\n").arg(s->fogColor.y());
  text += QString("%1\n").arg(s->fogColor.z());
  text += QString("%1\n").arg(s->fogColor.w());
  text += QString("%1\n").arg(s->fogWaterDist);
  text += QString("%1\n").arg(s->fogWaterHeight);
  text += QString("%1\n").arg(s->fogWaterStart);
  text += QString("%1\n").arg(s->fogWaterColor.x());
  text += QString("%1\n").arg(s->fogWaterColor.y());
  text += QString("%1\n").arg(s->fogWaterColor.z());
  text += QString("%1\n").arg(s->fogWaterColor.w());

  //qDebug(text.toStdString().c_str());

  QFile f(fileOpened);
  if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
  {
    qDebug("Unable to save scene!");
    return;
  }
  QTextStream out(&f);
  out << text;
  f.close();
  qDebug("Saved.");
}
//------------------------------------------------------------------------------
void CMainWindow::showHelp()
{
  QDesktopServices::openUrl(QUrl(QDir::currentPath()+"/manual.pdf"));
}
//------------------------------------------------------------------------------
void CMainWindow::showInfo()
{
  if((ui->wgView->getContext()->getCamera()->getCamera()->touchMode) && (!ui->tbRight->isVisible()))
    showRightPanel();

  QMessageBox msg;
  msg.setWindowTitle("About");
  msg.setText("Author: Tomáš Růžička\nE-mail: xruzic42@stud.fit.vutbr.cz\nVIN Project 2015, FIT VUT\n\nwww.djbozkosz.wz.cz");
  msg.exec();
}
//------------------------------------------------------------------------------
void CMainWindow::showRightMenu()
{
  if((ui->wgView->getContext()->getCamera()->getCamera()->touchMode) && (!ui->tbRight->isVisible()))
    showRightPanel();

  mnRight.popup(QPoint(width(), height()));
}
//------------------------------------------------------------------------------
void CMainWindow::showRightPanel()
{
  if(ui->tbRight->isVisible())
  {
    ui->wgView->hide();
    ui->tbRight->hide();
    ui->pbRightShow->setText("<");
    ui->wgView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    ui->wgView->setMaximumWidth(QWIDGETSIZE_MAX);
    ui->wgView->show();
  }
  else
  {
    ui->wgView->hide();
    ui->tbRight->show();
    ui->wgView->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    ui->wgView->setMaximumWidth(1);
    ui->wgView->show();
  }

  /*tbRightShow->blockSignals(true);
  tbRightShow->setCurrentIndex(1);
  tbRightShow->blockSignals(false);*/
}
//------------------------------------------------------------------------------
void CMainWindow::updateStyle(const float scale, bool inverse)
{
  QStringList style = styleDefault;

  for(auto s = style.begin(); s != style.end(); s++)
  {
    if(inverse)
    {
      if(s->indexOf("no_invert") == -1)
      {
        if(s->indexOf("color: #000000;") != -1)
          s->replace("color: #000000;", "color: #ffffff;");
        else
          s->replace("color: #ffffff;", "color: #000000;");
        s->replace("rgba(255, 255, 255, 128);", "rgba(0, 0, 0, 128);");
        if(s->indexOf("_inverse.png") == -1)
          s->replace(".png", "_inverse.png");
        else
          s->replace("_inverse.png", ".png");
      }
    }

    if(s->indexOf(QRegExp("[ +-]\\d+px")) != -1)
    {
      int i = s->lastIndexOf("px", s->length() - 1) - 1;
      for(int j = i + 1; (i = s->lastIndexOf(QRegExp("px|.\\:"), i)) != -1; j = i, i--)
      {
        const float v = s->mid(i + 2, j - i - 2).toFloat();
        if(fabsf(v) > 1.0f)
          s->replace(i + 3, j - i - 3, QString("%1").arg(static_cast<int>(v * scale)));
      }
    }
  }

  setStyleSheet(style.join("\n"));
}
//------------------------------------------------------------------------------
