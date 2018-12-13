#include <QApplication>
#include <QFile>
#include <QStyleFactory>
#include <QTextCodec>
#include "setmactool.h"
#include "tbsui.h"
#if 1
#define QTBS_MAIN_UI tbsui
#elif 0
#define QTBS_MAIN_UI SetMACTool
#else
#define QTBS_MAIN_UI tbsui

#endif
int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  /* 设置全局风格 */
  QApplication::setStyle(QStyleFactory::create("windows"));
  a.setWindowIcon(
      QIcon::fromTheme(QLatin1String("TBSSET"), QIcon(":/image/tbs.ico")));
#if (QT_VERSION <= QT_VERSION_CHECK(5, 0, 0))
#if _MSC_VER
  QTextCodec *codec = QTextCodec::codecForName("gbk");
#else
  QTextCodec *codec = QTextCodec::codecForName("utf-8");
#endif
  QTextCodec::setCodecForLocale(codec);
  QTextCodec::setCodecForCStrings(codec);
  QTextCodec::setCodecForTr(codec);
#else
  QTextCodec *codec = QTextCodec::codecForName("utf-8");
  QTextCodec::setCodecForLocale(codec);
#endif

  //加载样式表
  QFile file(":/qss/psblack.css");
  if (file.open(QFile::ReadOnly)) {
    QString qss = QLatin1String(file.readAll());
    QString paletteColor = qss.mid(20, 7);
    qApp->setPalette(QPalette(QColor(paletteColor)));
    qApp->setStyleSheet(qss);
    file.close();
  }
  a.setFont(QFont("Microsoft Yahei", 9));
  AppInit::Instance()->start();

  // QFont font  = qApp->font();
  // font.setPointSize(9);
  // qApp->setFont(font);

  QTBS_MAIN_UI w;
  w.show();

  return a.exec();
}