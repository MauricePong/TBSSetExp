#include "tbsmesgdlg.h"
#include "ui_tbsmesgdlg.h"

TBSMesgDlg::TBSMesgDlg(QWidget *parent)
    : QDialog(parent), ui(new Ui::TBSMesgDlg) {
  ui->setupUi(this);
  setWindowFlags(windowFlags() & ~Qt::WindowMinMaxButtonsHint |
                 Qt::WindowMinimizeButtonHint);
  setFixedSize(350, 100);
  setWindowTitle(QString(""));
  ui->lab_Msg->setText(QString(""));
  ui->btn_Left->setText("Yes");
  ui->btn_Right->setText("NO");

  ui->btn_Left->show();
  ui->btn_Right->show();
  pbarmax = 0;
  pbarvalue = 0;
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(timeoutfunc()));
}

TBSMesgDlg::~TBSMesgDlg() {
  if (NULL != timer) {
    delete timer;
  }
  delete ui;
}

void TBSMesgDlg::displayText(QString qstmsg) {
  ui->lab_Msg->setText(QString(""));
  ui->lab_Msg->setText(qstmsg);
}

void TBSMesgDlg::hideBtn(int left, int right, QString qstright) {
  if ((0 == left) && (0 == right)) {
    ui->btn_Left->hide();
    ui->btn_Right->hide();
    return;
  } else {
    ui->btn_Right->show();
  }
  if (0 == left) {
    ui->btn_Left->hide();
    ui->btn_Right->setText(qstright);
  } else if (1 == left) {
    ui->btn_Left->show();
    ui->btn_Right->setText(qstright);
  }
}

void TBSMesgDlg::setWinTitle(QString qsttitle) {
  setWindowTitle(QString(""));
  setWindowTitle(qsttitle);
}
void TBSMesgDlg::timerstart(int time) {
	pbarstep = time;
	timer->start(time);
}
void TBSMesgDlg::timerstop() {
  timer->stop();
  ui->progressBar->setValue(pbarmax);
}
void TBSMesgDlg::set_pbar_arg(int val, int maxval) {
	pbarvalue = val;
  pbarmax = maxval;
}
void TBSMesgDlg::on_btn_Left_clicked() {
  // int ret = 0;
  // ret = ui->btn_Left->isHidden();
  return;
}
void TBSMesgDlg::on_btn_Right_clicked() { this->accept(); }

void TBSMesgDlg::timeoutfunc() {
	ui->progressBar->setRange(0,pbarmax);
  pbarvalue = pbarvalue + pbarstep;
  if (pbarvalue > pbarmax - 300) {
    pbarvalue = pbarmax - 300;
	}
	ui->progressBar->setValue(pbarvalue);
}
