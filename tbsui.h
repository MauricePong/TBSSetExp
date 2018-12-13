#ifndef TBSUI_H
#define TBSUI_H
#include "appinit.h"
#include "tbsbase.h"
#include "tbshardware.h"
#if WINDOWSSPACE

#endif
namespace Ui {
class tbsui;
}

class tbsui : public QDialog {
  Q_OBJECT

 public:
  explicit tbsui(QWidget *parent = 0);
  ~tbsui();
  void initForm();
  void init_sql(void);
  void updateMac_sql(QString qstrMac);
  void refresh(void);

 protected:
  bool eventFilter(QObject *watched, QEvent *event);

 private:
  Ui::tbsui *ui;
  int width;
  int height;
  int width_s;
  int height_s;
  int iserror;
  int devno;
  int netnum;
  int com_IP_soltEN_flg;
  TBSMesgDlg *msgbox;
  QSqlDatabase database;
  QSqlQuery *sql_query;
  QThread m_Thread;
  TBShardware *tbshd;
  RD_WT_PARM tbsrwparm;
  NET_NODE nettag[16];
  int uilock;
#ifdef Q_OS_WIN  // windows
  SOCKET uiudpfd;
#else
  int uiudpfd;
#endif
 private slots:
  void threadFinished();
  void soltsDisplayMsgUI(TBS_Msg_Type *msg);
  void tunersCheckboxClick();

  void on_sli_H_valueChanged(int value);
  void on_btnMenu_Min_clicked();
  void on_btnMenu_Max_clicked();
  void on_btnMenu_Close_clicked();

  // ui set
  void on_too_Refresh_clicked();
  void on_too_Apply_clicked();
  void on_too_Reset_clicked();
  void on_too_Reboot_clicked();
  void slot_com_IP_currentIndexChanged(int idx);
  void on_che_Mip_stateChanged(int arg1);
};

#endif  //
