//------------------------------------------------------------------------------
#ifndef ENGINE_H
#define ENGINE_H

#include <QGLWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTouchEvent>
#include <QTimer>
#include <QDateTime>

#include "scene.h"

//------------------------------------------------------------------------------
class CEngine : public QGLWidget//, protected QGLFunctions, public CEngineBase
{
  private:
    Q_OBJECT

    CContext c;
    CScene scene;
    CModels models;
    CRenderer renderer;
    CShaders shaders;
    CCamera camera;
    CMaps maps;
    COpenGL openGL;

    QTimer paintTimer;

    CSceneObject *terr;
    uint32 terrI;

    SSceneHud hudMove;
    CSceneObject sky;
    CFramebuffer reflectionFramebuffer;

    void genTerrain2();

  private slots:
    void delayedPaint();

  protected:
    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int32 width, int32 height);

    virtual bool event(QEvent *event);

  public:
    CEngine(QWidget *parent = NULL);
    ~CEngine();

    inline CContext *getContext() { return &c; }

    inline const CFramebuffer *getReflectionFramebuffer() const { return &reflectionFramebuffer; }

  public slots:
    void genTerrain();
};
//------------------------------------------------------------------------------
#endif // ENGINE_H
