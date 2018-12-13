#ifndef SETMACTOOL_H
#define SETMACTOOL_H

#include <QDialog>
#include "tbsbase.h"
#include "tbshardware.h"
namespace Ui {
class SetMACTool;
}

class SetMACTool : public QDialog {
  Q_OBJECT

 public:
  explicit SetMACTool(QWidget *parent = 0);
  ~SetMACTool();
  QString readNetMacSFile();
  int writeNetMacFile(QString mac);
  int initUI(void);

 private:
  Ui::SetMACTool *ui;
#ifdef Q_OS_WIN  // windows
  SOCKET uiudpfd;
#else
  int uiudpfd;
#endif
  int devno;
  int iserror;
  int netnum;
  int com_IP_soltEN_flg;
  TBSMesgDlg *msgbox;
  QThread m_Thread;
  TBShardware *tbshd;
  RD_WT_PARM tbsrwparm;
  NET_NODE nettag[16];
 private slots:
  void threadFinished();
  void soltsDisplayMsgUI(TBS_Msg_Type *msg);
  void on_btn_Macapply_clicked();
  void slot_com_LocalIP_currentIndexChanged(int idx);
};

#endif  // SETMACTOOL_H
