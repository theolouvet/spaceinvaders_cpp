
#include <QApplication>

#include "../header/window.hpp"


int main(int argc,char *argv[])
{
  QApplication app(argc,argv);
  window win;

  win.show();
  return app.exec();
}
