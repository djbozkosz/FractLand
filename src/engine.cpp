//------------------------------------------------------------------------------
#include "engine.h"

//------------------------------------------------------------------------------
CEngine::CEngine(QWidget *parent) : QGLWidget(parent), terr(NULL), terrI(132)//, inited(false) , CEngineBase()
{
  //context = &c;
  scene = CScene(&c);
  models = CModels(&c);
  renderer = CRenderer(&c);
  shaders = CShaders(&c);
  camera = CCamera(&c);
  maps = CMaps(&c);
  c.setContext(this, &scene, &models, &renderer, &shaders, &camera, &maps, &openGL);

  setAttribute(Qt::WA_AcceptTouchEvents);
}
//------------------------------------------------------------------------------
CEngine::~CEngine()
{
}
//------------------------------------------------------------------------------
void CEngine::initializeGL()
{
#ifdef Q_OS_SYMBIAN
  QString path = "F:/FractLand/";
#else
  QString path = "";
#endif

  //srand(QDateTime::currentMSecsSinceEpoch());

  setMouseTracking(true);
  setFocusPolicy(Qt::StrongFocus);

  openGL = COpenGL(&c/*, context()*/);
  c.setContext(this, &scene, &models, &renderer, &shaders, &camera, &maps, &openGL);

  setAutoBufferSwap(false);

  c.getMaps()->loadDefaultMaps();
  c.getModels()->createRect();

  //aaa = reinterpret_cast<AAA>(wglGetProcAddress("glClear"));
  //if(aaadvdvdfe) qDebug("ok");
  //else qDebug("ne");

  c.getOpenGL()->enable(NOpenGL::DEPTH_TEST);

  c.getOpenGL()->enable(NOpenGL::CULL_FACE);
  c.getOpenGL()->frontFace(NOpenGL::CW);

  c.getOpenGL()->enable(NOpenGL::BLEND);
  c.getOpenGL()->blendFunc(NOpenGL::SRC_ALPHA, NOpenGL::ONE_MINUS_SRC_ALPHA);
  c.getOpenGL()->disable(NOpenGL::BLEND);

  c.getOpenGL()->clearColor(0.5, 0.6, 0.7, 1.0);

  //genTerrain2();
  //c.getScene()->addSceneObjectWater(SSceneObject(NScene::OBJECT_TYPE_WATER, "water", QVector3D(0.0, 0.0, 0.0), QQuaternion(), QVector3D(10000.0, 1.0, 10000.0)), SWater());
  CShader *vs;
  CShader *fs;

  vs = c.getShaders()->addShader(SShader(NShader::TYPE_VERTEX, NShader::STR_SHADER_VERTER_BASIC));
  fs = c.getShaders()->addShader(SShader(NShader::TYPE_FRAGMENT, NShader::STR_SHADER_FRAGMENT_BASIC));
  c.getShaders()->addShaderProgram(SShaderProgram(NShader::PROGRAM_BASIC, vs, fs));

  fs = c.getShaders()->addShader(SShader(NShader::TYPE_FRAGMENT, NShader::STR_SHADER_FRAGMENT_BASIC_ALPHA));
  c.getShaders()->addShaderProgram(SShaderProgram(NShader::PROGRAM_BASIC_ALPHA, vs, fs));

  vs = c.getShaders()->addShader(SShader(NShader::TYPE_VERTEX, NShader::STR_SHADER_VERTER_TERRAIN));
  fs = c.getShaders()->addShader(SShader(NShader::TYPE_FRAGMENT, NShader::STR_SHADER_FRAGMENT_TERRAIN));
  c.getShaders()->addShaderProgram(SShaderProgram(NShader::PROGRAM_TERRAIN, vs, fs));

  vs = c.getShaders()->addShader(SShader(NShader::TYPE_VERTEX, NShader::STR_SHADER_VERTER_WATER));
  fs = c.getShaders()->addShader(SShader(NShader::TYPE_FRAGMENT, NShader::STR_SHADER_FRAGMENT_WATER));
  c.getShaders()->addShaderProgram(SShaderProgram(NShader::PROGRAM_WATER, vs, fs));

  vs = c.getShaders()->addShader(SShader(NShader::TYPE_VERTEX, NShader::STR_SHADER_VERTER_UNDER_WATER));
  fs = c.getShaders()->addShader(SShader(NShader::TYPE_FRAGMENT, NShader::STR_SHADER_FRAGMENT_UNDER_WATER));
  c.getShaders()->addShaderProgram(SShaderProgram(NShader::PROGRAM_UNDER_WATER, vs, fs));

  reflectionFramebuffer = CFramebuffer(&c, SFramebuffer(true, true, 128, 128));

  hudMove.material = SMaterial(shaders.getShaderProgram(NShader::PROGRAM_BASIC_ALPHA), c.getMaps()->addMap(SMap(":/maps/data/maps/hubMove00.png", QVector4D(1.0, 1.0, 1.0, 1.0))), c.getMaps()->addMap(SMap(":/maps/data/maps/hubMove00a.png", QVector4D(1.0, 1.0, 1.0, 1.0))), NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, QVector<int32>(), false, true);
  //hudMove.material = SMaterial(shaders.getShaderProgram(NShader::PROGRAM_BASIC), reflectionFramebuffer.getFrameBuffer()->fboColorTexture, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, QVector<int32>(), false, true);

  sky = CSceneObject(&c, SSceneObject(NScene::OBJECT_TYPE_SKY, "sky"), SSky(c.getMaps()->addMap(SMap(path+"data/maps/sky00.png", QVector4D(0.5, 0.5, 0.5, 1.0)))));

  connect(&paintTimer, SIGNAL(timeout()), this, SLOT(delayedPaint()));
  paintTimer.setInterval(17);
  paintTimer.start();

  c.getCamera()->setSpeed(200);
  c.getCamera()->setRange(NCamera::CLIP_NEAR, 2000.0f);
}
//------------------------------------------------------------------------------
void CEngine::paintGL()
{
  const SScene *s = c.getScene()->getScene();
  QVector3D pos;
  QVector3D rot;
  c.getOpenGL()->clearColor(s->skyColor.x() * s->skyColor.w(), s->skyColor.y() * s->skyColor.w(), s->skyColor.z() * s->skyColor.w(), 1.0);
  c.getOpenGL()->clear(NOpenGL::COLOR_BUFFER_BIT | NOpenGL::DEPTH_BUFFER_BIT);

  reflectionFramebuffer.bind();
  c.getCamera()->setRenderMode(NCamera::RENDER_MODE_REFLECTION);
  //c.getOpenGL()->disable(NOpenGL::CULL_FACE);
  c.getOpenGL()->clearColor(s->skyColor.x() * s->skyColor.w(), s->skyColor.y() * s->skyColor.w(), s->skyColor.z() * s->skyColor.w(), 1.0);
  c.getOpenGL()->clear(NOpenGL::COLOR_BUFFER_BIT | NOpenGL::DEPTH_BUFFER_BIT);
  pos = c.getCamera()->getCamera()->position.toVector3D();
  rot = c.getCamera()->getCamera()->rotation.toVector3D();
  c.getCamera()->setPosition(QVector3D());
  c.getCamera()->setRotation(rot * QVector3D(-1.0, 1.0, 1.0));
  sky.render();
  c.getCamera()->setPosition(pos * QVector3D(1.0, -1.0, 1.0));
  c.getScene()->render();
  c.getRenderer()->runBatch();
  c.getRenderer()->clearGroups();
  c.getCamera()->setPosition(pos);
  c.getCamera()->setRotation(rot);
  //c.getOpenGL()->enable(NOpenGL::CULL_FACE);
  c.getCamera()->setRenderMode();
  reflectionFramebuffer.unbind();

  pos = c.getCamera()->getCamera()->position.toVector3D();
  c.getCamera()->setPosition(QVector3D());
  sky.render();
  c.getCamera()->setPosition(pos);
  c.getScene()->render();
  c.getRenderer()->runBatch();
  c.getRenderer()->clearGroups();

  if(c.getCamera()->getCamera()->touchMode)
  {
    c.getModels()->renderRectHud(&hudMove);
    c.getRenderer()->runBatch();
    c.getRenderer()->clearGroups();
  }

  c.getCamera()->setActive(c.getCamera()->setMove());

  swapBuffers();
}
//------------------------------------------------------------------------------
void CEngine::delayedPaint()
{
  c.getCamera()->updateTicks();
  if(c.getCamera()->getCamera()->active)
  {
    update();
  }
}
//------------------------------------------------------------------------------
void CEngine::resizeGL(int32 width, int32 height)
{
  c.getOpenGL()->viewport(0, 0, width, height);
  c.getCamera()->setSize(width, height);

  const float scale = 1.0f / c.getCamera()->getCamera()->height * 120.f;
  hudMove.position.setX(c.getCamera()->getCamera()->width / c.getCamera()->getCamera()->height * 0.575f - scale * 0.67f);
  hudMove.position.setY(-0.58f + scale * 0.67f);
  hudMove.position.setZ(-1.0f);
  hudMove.scale = QVector3D(scale, scale, 1.0);
  hudMove.mesh.mw = SMatrix::composeTransformation(hudMove.position, hudMove.rotation, hudMove.scale);
}
//------------------------------------------------------------------------------
bool CEngine::event(QEvent *event)
{
  if((event->type() == QEvent::TouchBegin) || (event->type() == QEvent::TouchEnd) || (event->type() == QEvent::TouchUpdate))
  {
    QTouchEvent *e = static_cast<QTouchEvent *>(event);
    const QList<QTouchEvent::TouchPoint> touchPoints = e->touchPoints();

    for(auto p = touchPoints.constBegin(); p != touchPoints.constEnd(); p++)
    {
      //QTouchEvent::TouchPoint *p;

      // 828, 489, 900, 558 -> -72, -69
      QVector2D v(p->pos().x() - width() + 72.0, p->pos().y() - height() + 69.8);
      const float len = v.length();
      //qDebug(QString("touch: %1").arg(p->id()).toStdString().c_str());

      if((p->state() == Qt::TouchPointPressed) && (len <= 52.0f) && (c.getCamera()->getCamera()->touchMoveId == NCamera::TOUCH_MOVE_ID_NONE))
      {
        //qDebug("in");
        c.getCamera()->setTouchMoveId(p->id());
      }
      else if((p->state() == Qt::TouchPointReleased) && (p->id() == c.getCamera()->getCamera()->touchMoveId))
      {
        //qDebug("stop");
        c.getCamera()->setTouchMoveId(NCamera::TOUCH_MOVE_ID_NONE);
        bool keys[NCamera::KEYS_COUNT];
        memset(keys, false, sizeof(bool) * NCamera::KEYS_COUNT);
        c.getCamera()->setKeys(keys);
      }

      if(p->id() != c.getCamera()->getCamera()->touchMoveId)
      {
        //qDebug("rot");
        if((p->state() == Qt::TouchPointPressed) || (p->state() == Qt::TouchPointReleased))
          c.getCamera()->setRotate(p->pos().x(), p->pos().y(), false);
        else if(p->state() == Qt::TouchPointMoved)
        {
          c.getCamera()->setRotate(p->pos().x(), p->pos().y(), true);
          update();
        }
      }
      else if(p->state() == Qt::TouchPointMoved)
      {
        //qDebug("move");
        v.normalize();
        const float dir = atan2f(v.y(), v.x()) * NMath::RAD_2_DEG;
        bool keys[NCamera::KEYS_COUNT];
        memset(keys, false, sizeof(bool) * NCamera::KEYS_COUNT);

        if(len >= 30.0f)
        {
          if((dir >= -22.5f) && (dir < 22.5f))
          {
            keys[NCamera::KEY_R] = true;
          }
          else if((dir >= 22.5f) && (dir < 67.5f))
          {
            keys[NCamera::KEY_R] = true;
            keys[NCamera::KEY_B] = true;
          }
          else if((dir >= 67.5f) && (dir < 112.5f))
          {
            keys[NCamera::KEY_B] = true;
          }
          else if((dir >= 112.5f) && (dir < 157.5f))
          {
            keys[NCamera::KEY_L] = true;
            keys[NCamera::KEY_B] = true;
          }
          else if((dir >= 157.5f) || (dir < -157.5f))
          {
            keys[NCamera::KEY_L] = true;
          }
          else if((dir >= -157.5f) && (dir < -112.5f))
          {
            keys[NCamera::KEY_L] = true;
            keys[NCamera::KEY_F] = true;
          }
          else if((dir >= -112.5f) && (dir < -67.5f))
          {
            keys[NCamera::KEY_F] = true;
          }
          else if((dir >= -67.5f) && (dir < -22.5f))
          {
            keys[NCamera::KEY_R] = true;
            keys[NCamera::KEY_F] = true;
          }
        }

        c.getCamera()->setKeys(keys);
        update();
      }
    }

    return true;
  }
  else if((event->type() == QEvent::MouseButtonPress) || (event->type() == QEvent::MouseButtonRelease) || (event->type() == QEvent::MouseMove))
  {
    QMouseEvent *e = static_cast<QMouseEvent *>(event);

    if((event->type() == QEvent::MouseButtonPress) || (event->type() == QEvent::MouseButtonRelease))
    {
      if(e->buttons() & Qt::RightButton)
      {
        //qDebug(QString("%1 %2, %3 %4").arg(e->pos().x()).arg(e->pos().y()).arg(width()).arg(height()).toStdString().c_str());
        c.getCamera()->setRotate(e->pos().x(), e->pos().y(), false);
      }
    }
    else if(event->type() == QEvent::MouseMove)
    {
      if(e->buttons() & Qt::RightButton)
      {
        c.getCamera()->setRotate(e->pos().x(), e->pos().y(), true);
        update();
      }
    }

    return true;
  }
  else if((event->type() == QEvent::KeyPress) || (event->type() == QEvent::KeyRelease))
  {
#ifndef Q_OS_SYMBIAN
    QKeyEvent *e = static_cast<QKeyEvent *>(event);
    bool state = (event->type() == QEvent::KeyPress) ? true : false;

    uint32 key = e->nativeVirtualKey();
    bool keys[NCamera::KEYS_COUNT];

    memcpy(keys, c.getCamera()->getCamera()->keys, sizeof(bool) * NCamera::KEYS_COUNT);

    if((key == 'W') || (key == VK_UP)) keys[NCamera::KEY_F] = state;
    else if((key == 'S') || (key == VK_DOWN)) keys[NCamera::KEY_B] = state;
    else if((key == 'A') || (key == VK_LEFT)) keys[NCamera::KEY_L] = state;
    else if((key == 'D') || (key == VK_RIGHT)) keys[NCamera::KEY_R] = state;
    else if(key == 'Q') keys[NCamera::KEY_D] = state;
    else if(key == 'E') keys[NCamera::KEY_U] = state;

    c.getCamera()->setKeys(keys);
    update();
#endif

    return true;
  }

  return QGLWidget::event(event);
}
//------------------------------------------------------------------------------
void CEngine::genTerrain()
{
  c.getScene()->removeSceneObject(terr);
  genTerrain2();
  update();
}
//------------------------------------------------------------------------------
void CEngine::genTerrain2()
{
  qDebug(QString("%1").arg(terrI).toStdString().c_str());

  QVector<SMaterialLayer> ml;
  ml.push_back(SMaterialLayer(QVector4D(0.2, 0.15, 0.1, 1.0), NULL, c.getMaps()->addMap(SMap(":/maps/data/maps/box00n.png", QVector4D(0.5, 0.5, 1.0, 1.0))), false, -0.5f, 0.5f, false, 0.0f, 1.0f));
  ml.push_back(SMaterialLayer(QVector4D(0.25, 0.4, 0.1, 1.0), NULL, c.getMaps()->addMap(SMap(":/maps/data/maps/grass00n.png", QVector4D(0.5, 0.5, 1.0, 1.0))), true, 0.015f, 0.5f, false, 0.0f, 1.0f));
  ml.push_back(SMaterialLayer(QVector4D(0.3, 0.3, 0.35, 1.0), NULL, c.getMaps()->addMap(SMap(":/maps/data/maps/rocks00n.png", QVector4D(0.5, 0.5, 1.0, 1.0))), true, -0.5f, 0.5f, true, 0.2f, 1.0f));

  terr = c.getScene()->addSceneObjectTerrain(SSceneObject(NScene::OBJECT_TYPE_TERRAIN, "terrain", QVector3D(0.0, -10.0, 0.0), QQuaternion(), QVector3D(1000.0, 1000.0, 1000.0)), STerrain(terrI, 8, 8, 4, 4, true, 0.5f, 0.42f, -0.05f, 0.1f, ml));
  terrI++;

  //emit terrainAdded(c.getScene()->getSceneObjectsCount() - 1);
}
//------------------------------------------------------------------------------
