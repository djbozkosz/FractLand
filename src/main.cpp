//------------------------------------------------------------------------------
#include "mainWindow.h"

//------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

#ifdef Q_OS_SYMBIAN
  QDir::setCurrent("E:\\FractLand\\");
#endif

  CMainWindow w;
#if defined(Q_OS_SYMBIAN) || defined(QT_SIMULATOR)
  w.setAttribute(Qt::WA_LockLandscapeOrientation);
  w.showFullScreen();
#ifdef QT_SIMULATOR
  w.openScene();
#endif
#else
  w.show();
#endif

  return a.exec();
}
//------------------------------------------------------------------------------
