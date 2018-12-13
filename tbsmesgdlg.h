#ifndef TBSMESGDLG_H
#define TBSMESGDLG_H

#include <QDebug>
#include <QDialog>
#include <QTimer>
namespace Ui {
class TBSMesgDlg;
}

class TBSMesgDlg : public QDialog {
  Q_OBJECT

 public:
  explicit TBSMesgDlg(QWidget *parent = 0);
  ~TBSMesgDlg();
  void displayText(QString qstmsg);
  void hideBtn(int left, int right, QString qstright);
  void setWinTitle(QString qsttitle);
  void timerstart(int time);
  void timerstop();
  void set_pbar_arg(int val, int maxval);
  // void set
 private slots:
  void on_btn_Left_clicked();
  void on_btn_Right_clicked();
  void timeoutfunc();

 private:
  Ui::TBSMesgDlg *ui;
  QTimer *timer;
  int pbarmax;
  int pbarvalue;
  int pbarstep;
};

#endif  // TBSMESGDLG_H
