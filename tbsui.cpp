#pragma execution_character_set("utf-8")
#include "tbsui.h"
#include "iconhelper.h"
#include "ui_tbsui.h"
#define ITMEL(n) ITMEL##n

tbsui::tbsui(QWidget *parent) : QDialog(parent), ui(new Ui::tbsui) {
  ui->setupUi(this);
  this->initForm();
  // init_sql();
}

tbsui::~tbsui() {
  if (tbshd) {
    // tbshd->stop();
    connect(&m_Thread, SIGNAL(finished()), tbshd, SLOT(deleteLater()));
    connect(&m_Thread, SIGNAL(finished()), this, SLOT(threadFinished()));
    m_Thread.quit();
    m_Thread.wait();
  }

  if (msgbox) {
    delete msgbox;
    msgbox = NULL;
  }

  // database.close();
  // delete sql_query;
  delete ui;
}

void tbsui::init_sql(void) {
  // 1.create sql
  if (QSqlDatabase::contains("qt_sql_default_connection")) {
    database = QSqlDatabase::database("qt_sql_default_connection");
  }

  else {
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("TBSMAC.db");
  }

  // 2.open sql
  if (!database.open()) {
    qDebug() << "Error: Failed to connect database." << database.lastError();
  }

  // 3.create from
  sql_query = new QSqlQuery();
  QString create_sql = "create table macValue (id int,MAC varchar(20))";
  sql_query->prepare(create_sql);

  if (!sql_query->exec()) {
    qDebug() << "Error: Fail to create table." << sql_query->lastError();
  }

  else {
    qDebug() << "Table created!";
  }

  // 4.select_sql
  QString select_sql = "select * from macValue";

  if (!sql_query->exec(select_sql)) {
    qDebug() << sql_query->lastError();
  }

  else {
    if (!(sql_query->next())) {
      // 5.insert_sql
      QString insert_sql = "insert into macValue values (?, ?)";
      sql_query->prepare(insert_sql);
      sql_query->addBindValue(1);
      sql_query->addBindValue("00:22:ab:00:00:00");

      if (!sql_query->exec()) {
        qDebug() << sql_query->lastError();
      }

      else {
        qDebug() << "inserted one!";
      }

      //  sql_query->addBindValue(2);
      //  sql_query->addBindValue("00:22:ab:00:00:00");
      //  if (!sql_query->exec())
      //  {
      //      qDebug() << sql_query->lastError();
      //  }
      //  else
      //  {
      //      qDebug() << "inserted two!";
      //  }
    }
  }

  qDebug() << "init sql over";
}

void tbsui::updateMac_sql(QString qstrMac) {
  QString update_sql = "update macValue set MAC = :MAC where id = :id";
  sql_query->prepare(update_sql);
  sql_query->bindValue(":MAC", qstrMac.toStdString().data());
  sql_query->bindValue(":id", 1);

  if (!sql_query->exec()) {
    qDebug() << sql_query->lastError();
  }

  else {
    qDebug() << "one updated!";
  }

  //  sql_query->bindValue(":MAC", nqstrMac.toStdString().data());
  //  sql_query->bindValue(":id", 2);
  //  if (!sql_query->exec())
  //      qDebug() << sql_query->lastError();
  //  }
  //  else
  //  {
  //      qDebug() << "two updated!";
  //  }
}

void tbsui::refresh(void) {
  netnum = 0;
  ui->com_IP->clear();
  disconnect(ui->com_IP, SIGNAL(currentIndexChanged(int)), this,
             SLOT(slot_com_IP_currentIndexChanged(int)));
  com_IP_soltEN_flg = 0;
  tbshd->setRunMode(TBS_UDPMULTICAST_FUNC);
  tbsrwparm.devno = devno;
  tbshd->setHardWareParm(tbsrwparm);
  m_Thread.quit();
  m_Thread.wait();
  m_Thread.start();
}

bool tbsui::eventFilter(QObject *watched, QEvent *event) {
  if (event->type() == QEvent::MouseButtonDblClick) {
    if (watched == ui->widgetTitle) {
      on_btnMenu_Max_clicked();
      return true;
    }
  }

  return QWidget::eventFilter(watched, event);
}

void tbsui::initForm() {
  this->setProperty("form", true);
  this->setProperty("canMove", true);
  this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint |
                       Qt::WindowMinMaxButtonsHint);
  this->setAttribute(Qt::WA_InputMethodEnabled, false);
  // QPixmap icon(":/image/logo.png");
  QPixmap icon(":/qss/psblack/uilogo/logo.png");
  ui->labIco->setPixmap(icon);
  ui->labIco->resize(icon.width(), icon.height());
  // IconHelper::Instance()->setIcon(ui->labIco, QChar(0xf099), 30);
  IconHelper::Instance()->setIcon(ui->btnMenu_Min, QChar(0xf068));
  IconHelper::Instance()->setIcon(ui->btnMenu_Max, QChar(0xf067));
  IconHelper::Instance()->setIcon(ui->btnMenu_Close, QChar(0xf00d));
  // IconHelper::Instance()->setIcon(ui->lab_enico, QChar(0xf069), 30);
  // ui->widgetMenu->setVisible(false);
  ui->widgetTitle->installEventFilter(this);
  ui->widgetTitle->setProperty("form", "title");
  ui->widgetTop->setProperty("nav", "top");
  // ui->labTitle->setText("TBS CAPTURE");
  ui->labTitle->setFont(QFont("Microsoft Yahei", 20));
  this->setWindowTitle(ui->labTitle->text());
  // ui->stackedWidget->setStyleSheet("QLabel{font:10pt;}");
  //单独设置指示器大小
  int addWidth = 20;
  int addHeight = 10;
  int rbtnWidth = 15;
  int ckWidth = 13;
  int scrWidth = 12;
  int borderWidth = 3;
  QStringList qss;
  qss.append(QString("QComboBox::drop-down,QDateEdit::drop-down,QTimeEdit::"
                     "drop-down,QDateTimeEdit::drop-down{width:%1px;}")
                 .arg(addWidth));
  qss.append(QString("QComboBox::down-arrow,QDateEdit[calendarPopup=\"true\"]::"
                     "down-arrow,QTimeEdit[calendarPopup=\"true\"]::down-arrow,"
                     "QDateTimeEdit[calendarPopup=\"true\"]::down-arrow{width:%"
                     "1px;height:%1px;right:2px;}")
                 .arg(addHeight));
  qss.append(QString("QRadioButton::indicator{width:%1px;height:%1px;}")
                 .arg(rbtnWidth));
  qss.append(
      QString("QCheckBox::indicator,QGroupBox::indicator,QTreeWidget::"
              "indicator,QListWidget::indicator{width:%1px;height:%1px;}")
          .arg(ckWidth));
  qss.append(QString("QScrollBar:horizontal{min-height:%1px;border-radius:%2px;"
                     "}QScrollBar::handle:horizontal{border-radius:%2px;}"
                     "QScrollBar:vertical{min-width:%1px;border-radius:%2px;}"
                     "QScrollBar::handle:vertical{border-radius:%2px;}")
                 .arg(scrWidth)
                 .arg(scrWidth / 2));
  qss.append(QString("QWidget#widget_top>QToolButton:pressed,QWidget#widget_"
                     "top>QToolButton:hover,"
                     "QWidget#widget_top>QToolButton:checked,QWidget#widget_"
                     "top>QLabel:hover{"
                     "border-width:0px 0px %1px 0px;}")
                 .arg(borderWidth));
  qss.append(QString("QWidget#widgetleft>QPushButton:checked,QWidget#"
                     "widgetleft>QToolButton:checked,"
                     "QWidget#widgetleft>QPushButton:pressed,QWidget#"
                     "widgetleft>QToolButton:pressed{"
                     "border-width:0px 0px 0px %1px;}")
                 .arg(borderWidth));
  this->setStyleSheet(qss.join(""));
  //  connect(ui->tree_Dev, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this,
  //  SLOT(showSelectedImage(QTreeWidgetItem*, int)));
  QList<QCheckBox *> ches = ui->gbox_Tuners->findChildren<QCheckBox *>();

  foreach (QCheckBox *che, ches) {
    che->setCheckable(true);
    connect(che, SIGNAL(clicked()), this, SLOT(tunersCheckboxClick()));
  }
  ui->com_IP->clear();
  ui->com_IP->setEditable(false);
  ui->tw_Set->setCurrentIndex(0);
  width_s = this->size().width();
  height_s = this->size().height();
  width = width_s;
  height = height_s;
  uiudpfd = 0;
  iserror = -1;
  devno = 0;
  netnum = 0;
  com_IP_soltEN_flg = 0;
  uilock = 0;
  tbsrwparm.switchStatus = 0x0f;
  msgbox = NULL;
  msgbox = new TBSMesgDlg();
  tbshd = NULL;
  tbshd = new TBShardware();
  tbshd->moveToThread(&m_Thread);
  connect(&m_Thread, SIGNAL(started()), tbshd, SLOT(start()));
  connect(tbshd, SIGNAL(sigDisplayMsgUI(TBS_Msg_Type *)), this,
          SLOT(soltsDisplayMsgUI(TBS_Msg_Type *)));
  //tbsrwparm.devno = devno;
  //tbshd->setHardWareParm(tbsrwparm);
  //tbshd->setRunMode(TBS_UDPMULTICAST_FUNC);
 // m_Thread.start();

  // connect(&m_Thread, SIGNAL(finished()), tbshd, SLOT(deleteLater()));
  // connect(&m_Thread, SIGNAL(finished()), this, SLOT(threadFinished()));
  // qDebug() << QString("%1->%2->%3->%4")
  //  .arg(__FILE__)
  //  .arg(__LINE__)
  //  .arg(__FUNCTION__)
  //  .arg((int)QThread::currentThreadId());
}

void tbsui::on_btnMenu_Min_clicked() { showMinimized(); }

void tbsui::on_btnMenu_Max_clicked() {
  static bool max = false;
  static QRect location = this->geometry();

  if (max) {
    this->setGeometry(location);
    width = width_s;
    height = height_s;
  }

  else {
    location = this->geometry();
    this->setGeometry(qApp->desktop()->availableGeometry());
    width = this->size().width();
    height = this->size().height();
  }

  this->setProperty("canMove", max);
  max = !max;
}

void tbsui::on_btnMenu_Close_clicked() {
  if (tbshd) {
    connect(&m_Thread, SIGNAL(finished()), tbshd, SLOT(deleteLater()));
    connect(&m_Thread, SIGNAL(finished()), this, SLOT(threadFinished()));
    // tbshd->stop();
    m_Thread.quit();
    m_Thread.wait();
    tbshd = NULL;
  }

  if (msgbox) {
    delete msgbox;
    msgbox = NULL;
  }

  close();
}

/**
        void tbsui::on_btn_Reset_chlicked()
        {
        qDebug() << "2222222222222222222";
        int  ipindex = ui->com_IP->currentIndex();
        if (-1 == ipindex) {
                return;
        }
        uiudpfd = tbshd->udpOpen(nettag[ipindex].ip, nettag[ipindex].port);
        if (uiudpfd < 3) {
                return;
        }
        else {
                tbshd->setudpfd(uiudpfd);
                tbshd->setRunMode(TBS_RESET_FUNC);
                tbsrwparm.devno = devno;
                tbshd->setHardWareParm(tbsrwparm);

                m_Thread.quit();
                m_Thread.wait();
                m_Thread.start();
        }
        return;
        }
*/

void tbsui::on_too_Refresh_clicked() {
  if (1 == uilock) {
    return;
  }
  uilock = 1;
  qDebug() << "Refresh";
  int mip = ui->che_Mip->isChecked();
  if (0 == mip) {
    tbshd->setManual_ip(QString("NULL"));
  } else {
    QString mip = ui->com_IP->lineEdit()->text();
    qDebug() << mip;
    tbshd->setManual_ip(mip);
  }
  refresh();
}

void tbsui::on_too_Apply_clicked() {
  if (1 == uilock) {
    return;
  }
  uilock = 1;
  qDebug() << "Apply";
#if 1
  int index = ui->tw_Set->currentIndex();
  int ipindex = ui->com_IP->currentIndex();

  if (-1 == ipindex) {
    return;
  }

  uiudpfd = tbshd->udpOpen(nettag[ipindex].ip, nettag[ipindex].port);

  // uiudpfd = tbshd->udpOpen(QString("192.168.8.232"), 5444);
  if (uiudpfd < 3) {
    return;
  }

  else {
    tbshd->setudpfd(uiudpfd);
    tbsrwparm.tunernum = ui->che_t0->isEnabled();
    tbsrwparm.tunernum += ui->che_t1->isEnabled();
    tbsrwparm.tunernum += ui->che_t2->isEnabled();
    tbsrwparm.tunernum += ui->che_t3->isEnabled();
    if (0 == index) {
      tbshd->setRunMode(TBS_WRITE_FUNC);
      tbshd->setWriteMode(WRITE_NET_PARM_FUNC);
      tbsrwparm.dhcp = ui->che_dhcp->isChecked();
      tbsrwparm.ip = ui->lin_LIP->text();
      tbsrwparm.port = ui->lin_Lport->text().toInt();
      tbsrwparm.Netmask = ui->Lin_Netmask->text();
      tbsrwparm.gateway = ui->lin_Gateway->text();
      tbshd->setHardWareParm(tbsrwparm);
      m_Thread.quit();
      m_Thread.wait();
      m_Thread.start();
    }

    else if (1 == index) {
      if (0 == ((nettag[ipindex].switchStatus >> devno) & 0x01)) {
        // check ui
        int sym = ui->lin_Sym->text().toInt();  // 2000~7200
        int tsport = ui->lin_TSPort->text().toInt();
        float fre = ui->lin_Fre->text().toFloat();  // 100.000~1000.000
        float lev = ui->lin_Lev->text().toFloat();  // 0.0~-35.0

        if ((fre < 100.000) || (fre > 1000.000)) {
          ui->lin_Fre->setStyleSheet("QLineEdit{border:1px solid red }");
          return;
        } else {
          ui->lin_Fre->setStyleSheet(
              "QLineEdit{border:1px solid gray border-radius:1px}");
        }
        if ((lev > 0.0) || (lev < -35.0)) {
          ui->lin_Lev->setStyleSheet("QLineEdit{border:1px solid red }");
          return;
        } else {
          ui->lin_Lev->setStyleSheet(
              "QLineEdit{border:1px solid gray border-radius:1px}");
        }
        if ((sym < 2000) || (sym > 7200)) {
          ui->lin_Sym->setStyleSheet("QLineEdit{border:1px solid red }");
          return;
        } else {
          ui->lin_Sym->setStyleSheet(
              "QLineEdit{border:1px solid gray border-radius:1px}");
        }

        if ((tsport < 0) || (tsport > 65536)) {
          ui->lin_TSPort->setStyleSheet("QLineEdit{border:1px solid red }");
          return;
        }

        else {
          ui->lin_TSPort->setStyleSheet(
              "QLineEdit{border:1px solid gray border-radius:1px}");
        }

        tbshd->setRunMode(TBS_WRITE_FUNC);
        tbshd->setWriteMode(WRITE_MODULATOR_PARM_FUNC);
        tbsrwparm.devno = devno;
        tbsrwparm.protocol = (u8)(ui->com_Protocol->currentIndex());
        tbsrwparm.qam = ui->com_Modulation->currentIndex();
        tbsrwparm.sym = ui->lin_Sym->text().toInt();
        tbsrwparm.fre = ui->lin_Fre->text();
        tbsrwparm.lev = ui->lin_Lev->text();
        tbsrwparm.tsport = ui->lin_TSPort->text().toInt();
        tbsrwparm.mucastip = ui->lin_CastIP->text();
        tbsrwparm.isRst = ui->che_Rst->isChecked();
        tbsrwparm.ismcurst = ui->che_mcurst->isChecked();
        tbshd->setHardWareParm(tbsrwparm);
        m_Thread.quit();
        m_Thread.wait();
        m_Thread.start();
      }
    }
  }

#endif
}

void tbsui::on_too_Reset_clicked() {
  if (1 == uilock) {
    return;
  }
  uilock = 1;
  qDebug() << "dvbc sub-card Restart";
  int ipindex = ui->com_IP->currentIndex();
  if (-1 == ipindex) {
    return;
  }

  uiudpfd = tbshd->udpOpen(nettag[ipindex].ip, nettag[ipindex].port);
  if (uiudpfd < 3) {
    return;
  } else {
    tbshd->setudpfd(uiudpfd);
    tbsrwparm.devno = devno;
    tbsrwparm.tunernum = ui->che_t0->isEnabled();
    tbsrwparm.tunernum += ui->che_t1->isEnabled();
    tbsrwparm.tunernum += ui->che_t2->isEnabled();
    tbsrwparm.tunernum += ui->che_t3->isEnabled();
    tbshd->setRunMode(TBS_RESET_FUNC);
    tbshd->setHardWareParm(tbsrwparm);
    m_Thread.quit();
    m_Thread.wait();
    m_Thread.start();
  }
}

void tbsui::on_too_Reboot_clicked() {
  if (1 == uilock) {
    return;
  }
  uilock = 1;
  qDebug() << "All Restart";
  int ipindex = ui->com_IP->currentIndex();
  if (-1 == ipindex) {
    return;
  }

  uiudpfd = tbshd->udpOpen(nettag[ipindex].ip, nettag[ipindex].port);
  if (uiudpfd < 3) {
    return;
  } else {
    tbshd->setudpfd(uiudpfd);
    tbsrwparm.devno = devno;
    tbsrwparm.tunernum = ui->che_t0->isEnabled();
    tbsrwparm.tunernum += ui->che_t1->isEnabled();
    tbsrwparm.tunernum += ui->che_t2->isEnabled();
    tbsrwparm.tunernum += ui->che_t3->isEnabled();
    tbshd->setRunMode(TBS_RESTSRT_MCU_FUNC);
    tbshd->setHardWareParm(tbsrwparm);
    m_Thread.quit();
    m_Thread.wait();
    m_Thread.start();
  }
}

void tbsui::slot_com_IP_currentIndexChanged(int idx) {
#if 1
  if (1 == uilock) {
    return;
  }
  uilock = 1;
  if (idx < 0) {
    return;
  }

  qDebug() << "idx" << idx << nettag[idx].ip << nettag[idx].port;
  uiudpfd = tbshd->udpOpen(nettag[idx].ip, nettag[idx].port);

  if (uiudpfd < 3) {
    return;
  } else {
    tbshd->setudpfd(uiudpfd);
    tbsrwparm.devno = devno;
    tbshd->setHardWareParm(tbsrwparm);
    tbshd->setRunMode(TBS_READ_FUNC);
    tbshd->setReadMode(READ_NET_MODULATOR_PARM_FUNC);
    m_Thread.quit();
    m_Thread.wait();
    m_Thread.start();
  }

#endif
}

void tbsui::threadFinished() {
  qDebug()
      << QString("%1->%2->%3").arg(__FILE__).arg(__LINE__).arg(__FUNCTION__);
}

void tbsui::soltsDisplayMsgUI(TBS_Msg_Type *msg) {
  if (NULL == msgbox) {
    return;
  }

  if (0 == msg->type) {
    return;
  }

  if (1 == msg->type) {
    if ((1 == msg->isread) && (0 == msg->iserror)) {
      uiudpfd = tbshd->udpClose(uiudpfd);
      tbshd->setudpfd(uiudpfd);

      if (0 == com_IP_soltEN_flg) {
        connect(ui->com_IP, SIGNAL(currentIndexChanged(int)), this,
                SLOT(slot_com_IP_currentIndexChanged(int)));
        com_IP_soltEN_flg = 1;
      }

      tbsrwparm = tbshd->getHardWareParm();

      if (1 == msg->isreadall) {
        ui->che_dhcp->setChecked(tbsrwparm.dhcp);
        ui->lin_LIP->setText(tbsrwparm.ip);
        ui->lin_Lport->setText(QString("%1").arg(tbsrwparm.port));
        ui->Lin_Netmask->setText(tbsrwparm.Netmask);
        ui->lin_Gateway->setText(tbsrwparm.gateway);
        ui->lin_Pla->setText(tbsrwparm.pla);
        ui->lin_TSPort->setText(QString("%1").arg(tbsrwparm.tsport));
        ui->lin_CastIP->setText(tbsrwparm.mucastip);
        ui->lin_Fre->setText(tbsrwparm.fre);
        ui->lin_Lev->setText(tbsrwparm.lev);
        ui->lin_Sym->setText(QString("%1").arg(tbsrwparm.sym));
        ui->com_Modulation->setCurrentIndex(tbsrwparm.qam);
        ui->com_Protocol->setCurrentIndex(tbsrwparm.protocol);
        ui->che_Rst->setChecked(tbsrwparm.isRst);
        ui->che_mcurst->setChecked(tbsrwparm.ismcurst);
      } else {
        int index = ui->tw_Set->currentIndex();

        if (0 == index) {
          ui->che_dhcp->setChecked(tbsrwparm.dhcp);
          ui->lin_LIP->setText(tbsrwparm.ip);
          ui->lin_Lport->setText(QString("%1").arg(tbsrwparm.port));
          ui->Lin_Netmask->setText(tbsrwparm.Netmask);
          ui->lin_Gateway->setText(tbsrwparm.gateway);
        } else if (1 == index) {
          ui->lin_Pla->setText(tbsrwparm.pla);
          ui->lin_TSPort->setText(QString("%1").arg(tbsrwparm.tsport));
          ui->lin_CastIP->setText(tbsrwparm.mucastip);
          ui->lin_Fre->setText(tbsrwparm.fre);
          ui->lin_Sym->setText(QString("%1").arg(tbsrwparm.sym));
          ui->lin_Lev->setText(tbsrwparm.lev);
          ui->com_Modulation->setCurrentIndex(tbsrwparm.qam);
          ui->com_Protocol->setCurrentIndex(tbsrwparm.protocol);
          ui->che_Rst->setChecked(tbsrwparm.isRst);
          ui->che_mcurst->setChecked(tbsrwparm.ismcurst);
        }
      }
    } else if ((0 == msg->isread) && (0 == msg->iserror)) {  // return write
      uiudpfd = tbshd->udpClose(uiudpfd);
      tbshd->setudpfd(uiudpfd);
      int comindex = ui->com_IP->currentIndex();
      int twindex = ui->tw_Set->currentIndex();

      if (0 == twindex) {
        int dhcpEN = ui->che_dhcp->isChecked();

        if (0 == dhcpEN) {
          nettag[comindex].ip = ui->lin_LIP->text();
          nettag[comindex].port = ui->lin_Lport->text().toInt();
          ui->com_IP->setItemText(comindex, nettag[comindex].ip);
        } else {
          ui->com_IP->setItemText(comindex, QString(""));
        }
      } else if (1 == twindex) {
        tbsrwparm = tbshd->getHardWareParm();
        // add something
        ui->lin_Pla->setText(tbsrwparm.pla);
        ui->lin_TSPort->setText(QString("%1").arg(tbsrwparm.tsport));
        ui->lin_CastIP->setText(tbsrwparm.mucastip);
        ui->lin_Fre->setText(tbsrwparm.fre);
        ui->lin_Lev->setText(tbsrwparm.lev);
        ui->lin_Sym->setText(QString("%1").arg(tbsrwparm.sym));
        ui->com_Modulation->setCurrentIndex(tbsrwparm.qam);
        ui->com_Protocol->setCurrentIndex(tbsrwparm.protocol);
        ui->che_Rst->setChecked(tbsrwparm.isRst);
        ui->che_mcurst->setChecked(tbsrwparm.ismcurst);
      }
    } else if ((2 == msg->isread) && (1 == msg->iserror)) {
      if (0 == com_IP_soltEN_flg) {
        connect(ui->com_IP, SIGNAL(currentIndexChanged(int)), this,
                SLOT(slot_com_IP_currentIndexChanged(int)));
        com_IP_soltEN_flg = 1;
      }
    }

    msgbox->setWinTitle(msg->tilie);
    msgbox->displayText(msg->displaytext);
    msgbox->hideBtn(msg->btnL, msg->btnR, msg->btnRtext);

    if ((0 == msg->btnL) && (0 == msg->btnR)) {
      uilock = 1;
			msgbox->setModal(false);
      msgbox->set_pbar_arg(20000,100000);
      msgbox->timerstart(100);
      msgbox->show();
    } else {
      msgbox->timerstop();
      msgbox->setModal(true);
      msgbox->exec();
      uilock = 0;
    }
  } else if (2 == msg->type) {
    qDebug() << QString("%1->%2->%3:msg->switchStatus=%4")
                    .arg(__FILE__)
                    .arg(__LINE__)
                    .arg(__FUNCTION__)
                    .arg(msg->switchStatus);

    if (0 == netnum) {
      ui->che_t0->setDisabled((msg->switchStatus >> 0) & 0x01);
      ui->che_t1->setDisabled((msg->switchStatus >> 1) & 0x01);
      ui->che_t2->setDisabled((msg->switchStatus >> 2) & 0x01);
      ui->che_t3->setDisabled((msg->switchStatus >> 3) & 0x01);
    }

    qDebug() << "netnum:" << netnum << msg->devip << msg->devport;
    nettag[netnum].ip = msg->devip;
    nettag[netnum].port = msg->devport;
    nettag[netnum].switchStatus = msg->switchStatus;
    ui->com_IP->addItem(
        QString("%1:%2").arg(nettag[netnum].ip).arg(nettag[netnum].port),
        netnum);
    ui->com_IP->setCurrentIndex(0);
    ;
    netnum++;
  }
}

void tbsui::tunersCheckboxClick() {
  QCheckBox *c = (QCheckBox *)sender();
  QList<QCheckBox *> ches = ui->gbox_Tuners->findChildren<QCheckBox *>();

  foreach (QCheckBox *ch, ches) {
    if (ch == c) {
      ch->setChecked(true);
    } else {
      ch->setChecked(false);
    }
  }

  QString name = c->text();

  if (name == "Tuner 0") {
    devno = 0;
  } else if (name == "Tuner 1") {
    devno = 1;
  } else if (name == "Tuner 2") {
    devno = 2;
  } else if (name == "Tuner 3") {
    devno = 3;
  }

#if 1
  int ipindex = ui->com_IP->currentIndex();

  if (-1 == ipindex) {
    return;
  }

  uiudpfd = tbshd->udpOpen(nettag[ipindex].ip, nettag[ipindex].port);

  if (uiudpfd < 3) {
    return;
  } else {
    tbshd->setudpfd(uiudpfd);

    if (0 == ((nettag[ipindex].switchStatus >> devno) & 0x01)) {
      tbshd->setRunMode(TBS_READ_FUNC);
      tbshd->setReadMode(READ_MODULATOR_PARM_FUNC);
      tbsrwparm.devno = devno;
      tbshd->setHardWareParm(tbsrwparm);
      m_Thread.quit();
      m_Thread.wait();
      m_Thread.start();
    }
  }

#endif
}

void tbsui::on_sli_H_valueChanged(int value) {
  qDebug() << value;
  this->setStyleSheet(QString("font:%1pt;").arg(value));
  ui->labTitle->setFont(QFont("Microsoft Yahei", 20 - 10 + value));
  // qDebug()<<width<<"*"<<height;
  this->resize(width, height);
  QString qst = QString("QCheckBox::indicator{ width: %1px; height: %1px; }")
                    .arg(4 + value);  //改变大小
}

void tbsui::on_che_Mip_stateChanged(int arg1) {
  if (arg1 == 0) {
    ui->com_IP->setEditable(false);
  } else {
    ui->com_IP->setEditable(true);
  };
}
