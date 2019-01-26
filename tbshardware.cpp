#include "tbshardware.h"

TBShardware::TBShardware() {
  m_bRun = true;
  runmode = 0;
  readmode = 0;
  writemode = 0;
  tbsmsg = new TBS_Msg_Type();
  tbsmsg->type = 0;
  tbsmsg->iserror = -1;
  tbsmsg->btnL = 0;
  tbsmsg->btnR = 0;
  tbsmsg->btnRtext = QString("OK");
  tbsmsg->tilie = QString("");
  tbsmsg->displaytext = QString("");
  manual_ip = QString("NULL");
}

TBShardware::~TBShardware() {
  if (tbsmsg) {
    delete tbsmsg;
  }
}
void TBShardware::start() {
  int ret = -1;
#ifdef Q_OS_WIN  // windows
  SOCKET sudpfd = 0;
#else
  int sudpfd = 0;
#endif
  // while (1) {
  QMutexLocker locker(&m_Mutex);
  tbsmsg->type = 1;
  tbsmsg->isreadall = 0;
  tbsmsg->iserror = 0;
  tbsmsg->isread = 3;
  tbsmsg->btnL = 0;
  tbsmsg->btnR = 0;
  tbsmsg->btnRtext = QString("");
  tbsmsg->tilie = QString("information");
  tbsmsg->displaytext = QString("Device running now,please wait..");
  tbsmsg->devip = QString("");
  tbsmsg->devport = 0;
  tbsmsg->switchStatus = 0x0f;
  emit sigDisplayMsgUI(tbsmsg);

  switch (runmode) {
    case TBS_READ_FUNC:
      ret = readBuffer(readmode);
      break;
    case TBS_WRITE_FUNC:
      ret = writeBuffer(writemode);
      break;
    case TBS_UDPMULTICAST_FUNC:
      if (QString("NULL") == manual_ip) {
        ret = udpMulticastClinet(0);
      } else {
        ret = udpMulticastClinet(1);
      }
      if (-1 == ret) {
        break;
      }

      sudpfd = udpOpen(first_ip.ip, first_ip.port);

      if (sudpfd < 3) {
        ret = -1;
        break;
      }

      setudpfd(sudpfd);
      ret = readBuffer(READ_NET_MODULATOR_PARM_FUNC);

      if (-1 == ret) {
        break;
      }

      break;

    case TBS_UDOMULTICAST_MAC_FUNC:
      ret = udpMulticastClinet(0);

      if (-1 == ret) {
        break;
      }

      sudpfd = udpOpen(first_ip.ip, first_ip.port);

      if (sudpfd < 3) {
        ret = -1;
        break;
      }

      setudpfd(sudpfd);
      ret = readBuffer(READ_NET_MAC_FUNC);

      if (-1 == ret) {
        break;
      }

      break;

    case TBS_RESET_FUNC:
      //ret = subcard_restart();
      if (0 == ret) {
        ret = 5;
      }
      break;
    case TBS_RESTSRT_MCU_FUNC:
      ret = mcu_poweroff();
      if (0 == ret) {
        ret = 5;
      }
      break;
    case TBS_NULL_FUNC:
      ret = -1;
      break;

    default:
      ret = -1;
      break;
  }

  runmode = 0;
  readmode = 0;
  writemode = 0;
  sudpfd = udpClose(sudpfd);
  setudpfd(sudpfd);
  QMSLEEP(500);

  if (0 == ret) {  // read success
    tbsmsg->type = 1;
    tbsmsg->isreadall = 0;
    tbsmsg->iserror = 0;
    tbsmsg->isread = 1;
    tbsmsg->btnL = 0;
    tbsmsg->btnR = 1;
    tbsmsg->btnRtext = QString("OK");
    tbsmsg->tilie = QString("information");
    tbsmsg->displaytext = QString("Success");
    tbsmsg->devip = QString("");
    tbsmsg->devport = 0;
    tbsmsg->switchStatus = 0x0f;
    emit sigDisplayMsgUI(tbsmsg);
  } else if (-1 == ret) {  // rw failure
    tbsmsg->type = 1;
    tbsmsg->isreadall = 0;
    tbsmsg->iserror = 1;
    tbsmsg->isread = 2;
    tbsmsg->btnL = 0;
    tbsmsg->btnR = 1;
    tbsmsg->btnRtext = QString("OK");
    tbsmsg->tilie = QString("error");
    tbsmsg->displaytext = QString("Failure");
    tbsmsg->devip = QString("");
    tbsmsg->devport = 0;
    tbsmsg->switchStatus = 0x0f;
    emit sigDisplayMsgUI(tbsmsg);
  } else if (1 == ret) {
    tbsmsg->type = 1;
    tbsmsg->isreadall = 0;
    tbsmsg->iserror = 0;
    tbsmsg->isread = 2;
    tbsmsg->btnL = 0;
    tbsmsg->btnR = 0;
    tbsmsg->btnRtext = QString("");
    tbsmsg->tilie = QString("information");
    tbsmsg->displaytext = QString("Configuring now,please wait..");
    tbsmsg->devip = QString("");
    tbsmsg->devport = 0;
    tbsmsg->switchStatus = 0x0f;
    emit sigDisplayMsgUI(tbsmsg);
  } else if (2 == ret) {
    tbsmsg->type = 1;
    tbsmsg->isreadall = 0;
    tbsmsg->iserror = 0;
    tbsmsg->isread = 0;
    tbsmsg->btnL = 0;
    tbsmsg->btnR = 1;
    tbsmsg->btnRtext = QString("OK");
    tbsmsg->tilie = QString("information");
    tbsmsg->displaytext = QString("Success");
    tbsmsg->devip = QString("");
    tbsmsg->devport = 0;
    tbsmsg->switchStatus = 0x0f;
    emit sigDisplayMsgUI(tbsmsg);
  } else if (4 == ret) {
    tbsmsg->type = 1;
    tbsmsg->isreadall = 1;
    tbsmsg->iserror = 0;
    tbsmsg->isread = 1;
    tbsmsg->btnL = 0;
    tbsmsg->btnR = 1;
    tbsmsg->btnRtext = QString("OK");
    tbsmsg->tilie = QString("information");
    tbsmsg->displaytext = QString("Success");
    tbsmsg->devip = QString("");
    tbsmsg->devport = 0;
    tbsmsg->switchStatus = 0x0f;
    emit sigDisplayMsgUI(tbsmsg);
  } else if (5 == ret) {  // rest
    tbsmsg->type = 1;
    tbsmsg->isreadall = 0;
    tbsmsg->iserror = 0;
    tbsmsg->isread = 3;
    tbsmsg->btnL = 0;
    tbsmsg->btnR = 1;
    tbsmsg->btnRtext = QString("OK");
    tbsmsg->tilie = QString("information");
    tbsmsg->displaytext = QString("Success");
    tbsmsg->devip = QString("");
    tbsmsg->devport = 0;
    tbsmsg->switchStatus = 0x0f;
    emit sigDisplayMsgUI(tbsmsg);
  } else if (6 == ret) {  // read mac
    tbsmsg->type = 3;
    tbsmsg->isreadall = 0;
    tbsmsg->iserror = 0;
    tbsmsg->isread = 1;
    tbsmsg->btnL = 0;
    tbsmsg->btnR = 1;
    tbsmsg->btnRtext = QString("OK");
    tbsmsg->tilie = QString("information");
    tbsmsg->displaytext = QString("Success");
    tbsmsg->devip = QString("");
    tbsmsg->devport = 0;
    tbsmsg->switchStatus = 0x0f;
    emit sigDisplayMsgUI(tbsmsg);
  } else if (7 == ret) {
    tbsmsg->type = 3;
    tbsmsg->isreadall = 0;
    tbsmsg->iserror = 0;
    tbsmsg->isread = 0;
    tbsmsg->btnL = 0;
    tbsmsg->btnR = 1;
    tbsmsg->btnRtext = QString("OK");
    tbsmsg->tilie = QString("information");
    tbsmsg->displaytext = QString("Success");
    tbsmsg->devip = QString("");
    tbsmsg->devport = 0;
    tbsmsg->switchStatus = 0x0f;
    emit sigDisplayMsgUI(tbsmsg);
  }

  //  if (false == m_bRun) {
  //      break;
  //  }
  // qDebug() << QString("%1->%2->%3->%4")
  //  .arg(__FILE__)
  //  .arg(__LINE__)
  //  .arg(__FUNCTION__)
  //  .arg((int)QThread::currentThreadId());
}

void TBShardware::stop() {
  QMutexLocker locker(&m_Mutex);
  m_bRun = false;
}

int TBShardware::readBuffer(int rmode) {
  int ret = 0;

  switch (rmode) {
    case READ_NET_PARM_FUNC:
      ret = readIPParm();
      break;
    case READ_MODULATOR_PARM_FUNC:
      ret = readModulatorParm();
      break;
    case READ_NET_MODULATOR_PARM_FUNC:
      ret = readIPParm();

      if (ret < 0) {
        return -1;
      }

      ret = readModulatorParm();

      if (0 == ret) {
        ret = 4;
      }

      break;

    case READ_NET_MAC_FUNC:
      return readNetMac();
      break;

    case READ_NULL_FUNC:
      return -1;
      break;

    default:
      return -1;
      break;
  }

  return ret;
}

int TBShardware::writeBuffer(int wmode) {
  int ret = 0;

  switch (wmode) {
    case WRITE_NET_PARM_FUNC:
      return writeIPParm();
      break;

    case WRITE_MODULATOR_PARM_FUNC:
      ret = writeModulatorParm();

      if (-1 == ret) {
        u8 writeMcudata[2] = {0, 0};
        writeREG(REG64_BY_UDP_FUNC, 0x4034, 1, writeMcudata);
      }

      break;

    case WRITE_NET_MAC_FUNC:
      return writeNetMac();
      break;

    case WRITE_NULL_FUNC:
      return -1;
      break;

    default:
      return -1;
      break;
  }

  return ret;
}

int TBShardware::readSwitchStatus(void) {
  u8 tmp[8] = {0};
  int ret = readREG(REG64_BY_UDP_FUNC, 0x4014, 8, tmp);
  // for (int i = 0; i < 8; i++) {
  //  qDebug("tmp[%d]:%02x  ret= %d", i, tmp[i],ret);
  //}
  rwparm.switchStatus = (tmp[0] & 0x0f);

  if (-1 == ret) {
    return -2;
  } else if (0 == ret) {
    return 2;
  }

  return 0;
}

int TBShardware::readIPParm(void) {
  u8 tmp[27] = {0};
  int ret = controlExternalMemory(READ, 0x0000, tmp, 27);
  // for (int i = 0; i < 27; i++) {
  //  qDebug() << tmp[i];
  //}
  rwparm.ip = QString("%1.%2.%3.%4")
                  .arg(tmp[0x00])
                  .arg(tmp[0x01])
                  .arg(tmp[0x02])
                  .arg(tmp[0x03]);
  TBSSWAP(tmp[0x04], tmp[0x05]);
  rwparm.port = *(u16 *)(&tmp[0x04]);
  rwparm.Netmask = QString("%1.%2.%3.%4")
                       .arg(tmp[0x10])
                       .arg(tmp[0x11])
                       .arg(tmp[0x12])
                       .arg(tmp[0x13]);
  rwparm.gateway = QString("%1.%2.%3.%4")
                       .arg(tmp[0x16])
                       .arg(tmp[0x17])
                       .arg(tmp[0x18])
                       .arg(tmp[0x19]);
  rwparm.dhcp = tmp[0x1a];
  return ret;
}

int TBShardware::readModulatorParm(void) {
  int i = 0;
  int ret = 0;
  int rfxbaseaddr = 0x0020;
  int rfxofficeaddr = 0x0080;
  int devno = rwparm.devno;
  int rfxphyaddr = rfxbaseaddr + rfxofficeaddr * devno;
  int mcusfaddr = 0x1c + devno;
  u8 mcusfdata = 0;
  u8 rfxdata[0x78] = {0};

  memset(rfxdata, 0, 0x78);
  qDebug() << "select devno:" << rwparm.devno;
  ret = controlExternalMemory(READ, rfxphyaddr, rfxdata, 0x78);
  if (-1 == ret) {
    return ret;
  }
  for (int j = 0; j < CHNO; j++) {
    QString qfreq = QString("%1%2%3%4%5%6%7")
                        .arg((char)(rfxdata[0x00 + 0x20 * j]))
                        .arg((char)(rfxdata[0x01 + 0x20 * j]))
                        .arg((char)(rfxdata[0x02 + 0x20 * j]))
                        .arg((char)(rfxdata[0x03 + 0x20 * j]))
                        .arg((char)(rfxdata[0x04 + 0x20 * j]))
                        .arg((char)(rfxdata[0x05 + 0x20 * j]))
                        .arg((char)(rfxdata[0x06 + 0x20 * j]));
    rwparm.fre[j] = qfreq;
    qDebug() << "read fre:" << rwparm.fre[j]<<"["<<j<<"]";
    TBSSWAP(rfxdata[0x07 + 0x20 * j], rfxdata[0x08 + 0x20 * j]);
    rwparm.sym = *(u16 *)(&rfxdata[0x07]);
    qDebug() << "read sym:" << rwparm.sym << "[" << j << "]";
    rwparm.qam = rfxdata[0x09];
    qDebug() << "read qam:" << rwparm.qam << "[" << j << "]";
    rwparm.chesw[j] = rfxdata[0x0a + 0x20*j];
    qDebug() << "read chesw:" << rwparm.chesw[j] << "[" << j << "]";
    //QString qlevl = QString("%1%2%3%4")
    //                    .arg((char)(rfxdata[0x15]))
    //                    .arg((char)(rfxdata[0x16]))
    //                    .arg((char)(rfxdata[0x17]))
    //                    .arg((char)(rfxdata[0x18]));
    //if ('.' == (char)(rfxdata[0x18])) {
    //  qlevl.append(QString((char)(rfxdata[0x19])));
    //}
    QString qlevl = QString("%1").arg(rfxdata[0x0b+0x20*j]);
    rwparm.lev[j] = qlevl;
    qDebug() << "read level:" << rwparm.lev[j] << "[" << j << "]";
		rwparm.prate = QString("%1").arg(ntohl(*(u32 *)&rfxdata[0x0c]));
		qDebug() << "read playreate:" << rwparm.prate << "[" << j << "]";

    rwparm.mucastip[j] = QString("%1.%2.%3.%4")
                             .arg(rfxdata[0x11 + 0x20 * j])
                             .arg(rfxdata[0x12 + 0x20 * j])
                             .arg(rfxdata[0x13 + 0x20 * j])
                             .arg(rfxdata[0x14 + 0x20 * j]);
    qDebug() << "read mucastip:" << rwparm.mucastip[j] << "[" << j << "]";
    rwparm.protocol[j] = rfxdata[0x15 + 0x20 * j];
    qDebug() << "read protocol:" << rwparm.protocol[j] << "[" << j << "]";
    TBSSWAP(rfxdata[0x16 + 0x20 * j], rfxdata[0x17 + 0x20 * j]);
    rwparm.tsport[j] = *(u16 *)(&rfxdata[0x16 + 0x20 * j]);
    qDebug() << "read tsport:" << rwparm.tsport << "[" << j << "]";
  }
	ret = controlExternalMemory(READ, mcusfaddr, &mcusfdata, 1);
  rwparm.softrst = mcusfdata;
  qDebug() << "read  softrst:" << rwparm.softrst;
  return ret;
}

int TBShardware::readNetMac(void) {
  u8 tmp[8] = {0};
  u8 mac[8] = {0};
  int ret = controlExternalMemory(READ, 0x0008, tmp, 6);
  rwparm.netmac.sprintf("%02x:%02x:%02x:%02x:%02x:%02x", tmp[0], tmp[1], tmp[2],
                        tmp[3], tmp[4], tmp[5]);
  mac[0] = tmp[5];
  mac[1] = tmp[4];
  mac[2] = tmp[3];
  *(int *)&mac[0] = *(int *)&mac[0] + 1;
  tmp[5] = mac[0];
  tmp[4] = mac[1];
  tmp[3] = mac[2];
  rwparm.setnetmac.sprintf("%02x:%02x:%02x:%02x:%02x:%02x", tmp[0], tmp[1],
                           tmp[2], tmp[3], tmp[4], tmp[5]);
  qDebug() << rwparm.netmac;
  qDebug() << rwparm.setnetmac;

  if (0 == ret) {
    ret = 6;
  }

  return ret;
}

int TBShardware::writeIPParm(void) {
  u8 tmp[30] = {0};
  tmp[0x00] = rwparm.ip.section('.', 0, 0).trimmed().toInt();
  tmp[0x01] = rwparm.ip.section('.', 1, 1).trimmed().toInt();
  tmp[0x02] = rwparm.ip.section('.', 2, 2).trimmed().toInt();
  tmp[0x03] = rwparm.ip.section('.', 3, 3).trimmed().toInt();
  tmp[0x04] = ((rwparm.port >> 8) & 0xff);
  tmp[0x05] = ((rwparm.port) & 0xff);
  int ret = controlExternalMemory(WRITE, 0x0000, tmp, 6);

  if (-1 == ret) {
    return ret;
  }

  tmp[0x10] = rwparm.Netmask.section('.', 0, 0).trimmed().toInt();
  tmp[0x11] = rwparm.Netmask.section('.', 1, 1).trimmed().toInt();
  tmp[0x12] = rwparm.Netmask.section('.', 2, 2).trimmed().toInt();
  tmp[0x13] = rwparm.Netmask.section('.', 3, 3).trimmed().toInt();
  tmp[0x14] = 0;
  tmp[0x15] = 0;
  tmp[0x16] = rwparm.gateway.section('.', 0, 0).trimmed().toInt();
  tmp[0x17] = rwparm.gateway.section('.', 1, 1).trimmed().toInt();
  tmp[0x18] = rwparm.gateway.section('.', 2, 2).trimmed().toInt();
  tmp[0x19] = rwparm.gateway.section('.', 3, 3).trimmed().toInt();
  tmp[0x1a] = rwparm.dhcp;
  ret = controlExternalMemory(WRITE, 0x0010, &tmp[0x10], 11);

  if (-1 == ret) {
    return ret;
  }
  ret = mcu_poweroff();
  if (0 == ret) {
    ret = 2;
  }
  return ret;
}

int TBShardware::writeModulatorParm(void) {
  int i = 0;
  int ret = 0;
  int rfxbaseaddr = 0x0020;
  int rfxofficeaddr = 0x0080;
  int devno = rwparm.devno;
  int rfxphyaddr = rfxbaseaddr + rfxofficeaddr * devno;
  u8 rfxdata[0x78] = {0};
  int mcusfaddr = 0x1c + devno;
  u8 mcusfdata = 0;

  memset(rfxdata, 0, 0x78);
  qDebug() << "select devno:" << rwparm.devno;
  for (int j =0; j <CHNO;j++){
  // freq
  QString qfreq = QString::number(rwparm.fre[j].toFloat(), 'f', 3);
  qDebug() << "write freq:" << qfreq << "[" << j << "]";
  for (i = 0; i < qfreq.length(); i++) {
    rfxdata[0x00 + i +0x20*j] = (u8)(qfreq.at(i).toLatin1());
  }
  // qam&&sym
  rfxdata[0x07 + 0x20 * j] = ((rwparm.sym >> 8) & 0x0ff);
  rfxdata[0x08 + 0x20 * j] = (rwparm.sym & 0x0ff);
  qDebug() << "write sym:" << rwparm.sym << "[" << j << "]";
  rfxdata[0x09 + 0x20 * j] = rwparm.qam & 0xff;
  qDebug() << "write qam:" << rwparm.qam << "[" << j << "]";
  rfxdata[0x0a + 0x20 * j] = rwparm.chesw[j] & 0xff;
  qDebug() << "write chesw:" << rwparm.chesw[j] << "[" << j << "]";

  // level
 //QString qlevel = QString::number(rwparm.lev.toFloat(), 'f', 1);
 // qDebug() << "write level:" << qlevel << "[" << j << "]";
  //for (i = 0; i < qlevel.length(); i++) {
  //  rfxdata[0x15 + i] = (u8)(qlevel.at(i).toLatin1());
  //}
  rfxdata[0x0b + 0x20 * j] = rwparm.lev[j].toInt();
  qDebug() << "write level:" << rwparm.lev[j].toInt() << "[" << j << "]";
  //multicast ip
  for (i = 0; i < 4; i++) {
    rfxdata[0x11 + i + 0x20 * j] =
        (u8)(rwparm.mucastip[j].section('.', i, i).trimmed().toInt());
  }
  qDebug() << "write mucastip:" << rwparm.mucastip[j] << "[" << j << "]";
  rfxdata[0x15 + 0x20 * j] = (u8)(rwparm.protocol[j]& 0x0ff);
  qDebug() << "write protocol:" << rfxdata[0x15 + 0x20 * j] << "[" << j << "]";
  rfxdata[0x16 + 0x20 * j] = (u8)((rwparm.tsport[j] >> 8) & 0x0ff);
  rfxdata[0x17 + 0x20 * j] = (u8)(rwparm.tsport[j] & 0x0ff);
  qDebug() << "write tsport:" << rwparm.tsport[j] << "[" << j << "]";
	}
  ret = controlExternalMemory(WRITE, rfxphyaddr, rfxdata, 0x78);
  if (-1 == ret) {
    return ret;
  }
	qDebug() << "write  softrst:" << rwparm.softrst;
  mcusfdata = (u8)(rwparm.softrst);
  ret = controlExternalMemory(WRITE, mcusfaddr, &mcusfdata, 1);
  if (-1 == ret) {
    return ret;
  }
  u8 dev = (u8)(rwparm.devno);
  ret = subcard_restart(dev);
   if (-1 == ret) {
       return ret;
  }

#if 1
  ret = readModulatorParm();
  if (-1 == ret) {
    return ret;
  }
#endif
  if (0 == ret) {
    ret = 2;
  }
  return ret;
}
int TBShardware::writeNetMac(void) {
  u8 tmp[10] = {0};
  qDebug() << rwparm.netmac;
  char charry[32] = {'\0'};
  strcpy(charry, rwparm.netmac.toLatin1().data());
  sscanf(charry, "%02x:%02x:%02x:%02x:%02x:%02x", &tmp[0], &tmp[1], &tmp[2],
         &tmp[3], &tmp[4], &tmp[5]);
  int ret = controlExternalMemory(WRITE, 0x0008, tmp, 6);

  if (-1 == ret) {
    return ret;
  }

  ret = readBuffer(READ_NET_MAC_FUNC);

  if (6 == ret) {
    ret = 7;
  }

  return ret;
}

int TBShardware::udpMulticastClinet(int manualip) {
  int i = 0;
  int j = 0;
  int k = 0;
  int ret = 0;

  int timevalue = 2000;
  getHostIpAddress();
#ifdef Q_OS_WIN  // windows
  SOCKET Mfd;
  SOCKET mudpfd;
  WSADATA wsaData;
  WSAStartup(MAKEWORD(1, 1), &wsaData);
  int timeout = timevalue;
#else  // linux
  int Mfd;
  int mudpfd;
  struct timeval timeout = {1, 0};
#endif
  struct sockaddr_in addr;
  char recvtmp[128] = {'\0'};
  char sendbuf[64] = {'\0'};
  char recvbuf[64] = {'\0'};
  u8 tmp[2] = {0};

  if (1 == manualip) {
    tbsmsg->devip = manual_ip.section(':', 0, 0).trimmed();
    tbsmsg->devport = manual_ip.section(':', 1, 1).trimmed().toInt();
    mudpfd = udpOpen(tbsmsg->devip, tbsmsg->devport);
    if (mudpfd < 3) {
      return -1;
    }
    setudpfd(mudpfd);
    ret = readREG(REG64_BY_UDP_FUNC, 0x4014, 1, &tbsmsg->switchStatus);
    mudpfd = udpClose(mudpfd);
    setudpfd(mudpfd);
    if (ret < 0) {
      return -1;
    }
    first_ip.ip = tbsmsg->devip;
    first_ip.port = tbsmsg->devport;
    first_ip.switchStatus = tbsmsg->switchStatus;
    tbsmsg->type = 2;
    emit sigDisplayMsgUI(tbsmsg);
    return 0;
  }
  if ((Mfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    qDebug() << "fail to socket";
    return -1;
  }

  first_ip.ip = QString("192.168.0.0");
  first_ip.port = 0;
  first_ip.switchStatus = 0x0f;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr("239.255.0.9");
  addr.sin_port = htons(21571);  // 0x5443
  len = sizeof(addr);
  setsockopt(Mfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
  setsockopt(Mfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
  sendbuf[0] = 0xc0;  // read
  sendbuf[1] = 0xff;
  sendbuf[2] = 0xff;
  sendbuf[3] = 0xff;
  sendbuf[4] = 0x54;
  sendbuf[5] = 0x42;
  sendbuf[6] = 0x53;
  sendbuf[7] = 0x50;
  sendbuf[8] = 0x52;
  sendbuf[9] = 0x4f;
  sendbuf[10] = 0x44;
  sendbuf[11] = 0x54;

  // c0ffffff54425350524f4454
  if (sendto(Mfd, sendbuf, strlen(sendbuf), 0, (struct sockaddr *)&addr, len) <
      0) {
    qDebug() << " fail to sendto";
    return -1;
  }

  QMSLEEP(100);

  while (i < 16) {
    int n = recvfrom(Mfd, recvbuf, 64, 0, (struct sockaddr *)&addr, &len);

    if (n < 0) {
      qDebug() << QString("%1->%2->%3:scan ip dev over")
                      .arg(__FILE__)
                      .arg(__LINE__)
                      .arg(__FUNCTION__);

      if (i > 0) {
        ret = 0;
      }

      else {
        ret = -1;
      }

      break;
    }

    else {
      /**
              sprintf(recvtmp, "TBS%02x%02x:%d.%d.%d.%d:%d"
              "/%02x:%02x:%02x:%02x:%02x:%02x",
              (u8)0x80, (u8)0x30, (u8)recvbuf[6], \
              (u8)recvbuf[7], (u8)recvbuf[8],
              (u8)recvbuf[9], *(u16*)&tmp[0],
              (u8)recvbuf[12], (u8)recvbuf[13],
              (u8)recvbuf[14], (u8)recvbuf[15],
              (u8)recvbuf[16], (u8)recvbuf[17]);

              if ((((u8)(0x80) != (u8)recvbuf[4]) &&
              ((u8)(0x63) != (u8)recvbuf[4])) ||
              (((u8)(0x30) != (u8)recvbuf[5]) &&
              ((u8)(0x16) != (u8)recvbuf[5])) ||
                      (((u8)(0x00) != (u8)(recvbuf[12])) ||
              ((u8)(0x22) != (u8)(recvbuf[13])) ||
                              ((u8)(0xab) != (u8)(recvbuf[14])))) {
              continue;
      **/
      qDebug("%02x %02x %d.%d.%d.%d %d", (u8)recvbuf[4], (u8)recvbuf[5],
             (u8)recvbuf[6], (u8)recvbuf[7], (u8)recvbuf[8], (u8)recvbuf[9], gatewaynum);

      if (((u8)(0x82) != (u8)recvbuf[4]) ||((u8)(0x28) != (u8)recvbuf[5])) {
        continue;
      }

      for (k = 0; k < gatewaynum; k++) {
        if (true == hostip[k].contains(QString("%1.%2.%3")
                                           .arg((u8)recvbuf[6])
                                           .arg((u8)recvbuf[7])
                                           .arg((u8)recvbuf[8]),
                                       Qt::CaseSensitive)) {
          break;
        }
      }

      if (k == gatewaynum) {
        continue;
      }

      tmp[0] = (u8)recvbuf[11];
      tmp[1] = (u8)recvbuf[10];
      tbsmsg->devip = QString("%1.%2.%3.%4")
                          .arg((u8)recvbuf[6])
                          .arg((u8)recvbuf[7])
                          .arg((u8)recvbuf[8])
                          .arg((u8)recvbuf[9]);
      tbsmsg->devport = *(u16 *)(tmp);
      qDebug() << "success ip and port:"<<tbsmsg->devip << tbsmsg->devport;
      mudpfd = udpOpen(tbsmsg->devip, tbsmsg->devport);

      if (mudpfd < 3) {
        continue;
      }

      setudpfd(mudpfd);
      ret = readREG(REG64_BY_UDP_FUNC, 0x4014, 1, &tbsmsg->switchStatus);
      mudpfd = udpClose(mudpfd);
      setudpfd(mudpfd);

      if (ret < 0) {
        continue;
      }

      if (i == 0) {
        first_ip.ip = tbsmsg->devip;
        first_ip.port = tbsmsg->devport;
        first_ip.switchStatus = tbsmsg->switchStatus;
      }

      tbsmsg->type = 2;
      emit sigDisplayMsgUI(tbsmsg);
      QMSLEEP(100);
      i++;
    }
  }

  memset(recvbuf, 0, sizeof(recvbuf));
#ifdef Q_OS_WIN  // windows
  closesocket(Mfd);
  WSACleanup();
#else  // linux
  ::close(Mfd);
#endif
  return ret;
}

int TBShardware::getHostIpAddress(void) {
  QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
  // 获取第一个本主机的IPv4地址
  int nListSize = ipAddressesList.size();
  gatewaynum = 0;

  for (int i = 0; i < nListSize; ++i) {
    if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
        ipAddressesList.at(i).toIPv4Address() &&
        (ipAddressesList.at(i) != QHostAddress::Null)) {
      hostip[gatewaynum] = ipAddressesList.at(i).toString();
      qDebug() << i << "local PC ip:" << hostip[gatewaynum];
      gatewaynum++;
    }
  }

  // 如果没有找到，则以本地IP地址为IP
  if (0 == gatewaynum) {
    hostip[0] = QHostAddress(QHostAddress::LocalHost).toString();
    qDebug() << "local PC ip:" << hostip[0];
    gatewaynum = 1;
  }

  return 0;
}

int TBShardware::getRunMode() { return runmode; }

void TBShardware::setRunMode(int mode) { runmode = mode; }

int TBShardware::getReadMode() { return readmode; }

void TBShardware::setReadMode(int mode) { readmode = mode; }

int TBShardware::getWriteMode() { return writemode; }

void TBShardware::setWriteMode(int mode) { writemode = mode; }

void TBShardware::setManual_ip(QString ip) { manual_ip = ip; }

int TBShardware::subcard_restart( u8 devno) {
  u8 tmp[4] = {0xff, 0xff, 0xff, 0xff};
  int ret = 0;
  tmp[0] = devno;
  ret = controlExternalMemory(WRITE, 0xff08, tmp, 1);
  int timecout = 15000;
  qDebug("subcard_restart time:%d ms", timecout);
  QMSLEEP(timecout);
  return ret;
}

int TBShardware::mcu_poweroff() {
  u8 tmp[4] = {0xff, 0xff, 0xff, 0xff};
  int ret = 0;
  //u8 mcudata[4] = {0};
  //int mcuaddr = 0xe0;
  //int tunernum = 0;
  //ret = controlExternalMemory(READ, mcuaddr, mcudata, 4);
  //if (-1 == ret) {
  //  return ret;
  //}
  //for (int i = 0; i < 4; i++) {
  //  if (1 == mcudata[i]) {
  //    ++tunernum;
  //  }
  //}
 // tunernum = tunernum > rwparm.tunernum ? rwparm.tunernum : tunernum;
  ret = writeREG(REG64_BY_UDP_FUNC, 0x4014, 1, tmp);
  QMSLEEP(100);
  tmp[0] = 0;
  ret = writeREG(REG64_BY_UDP_FUNC, 0x4014, 1, tmp);
  int timecout = 15000;
  qDebug("mcu poweroff time:%d ms", timecout);
  QMSLEEP(timecout);
  return ret;
}

#ifdef Q_OS_WIN  // windows
SOCKET TBShardware::gethdudpfdMode() { return getudpfd(); }

void TBShardware::sethdudpfdMode(SOCKET f_hdudpfd) { setudpfd(f_hdudpfd); }
SOCKET TBShardware::openNetSocket(QString ip, int port) {
  return udpOpen(ip, port);
}
SOCKET TBShardware::closeNetSocket(SOCKET socketfd) {
  return udpClose(socketfd);
}
#else
int TBShardware::gethdudpfdMode() { return getudpfd(); }
void TBShardware::sethdudpfdMode(int f_hdudpfd) { setudpfd(f_hdudpfd); }
int TBShardware::openNetSocket(QString ip, int port) {
  return udpOpen(ip, port);
}
int TBShardware::closeNetSocket(int socketfd) { return udpClose(socketfd); }
#endif

RD_WT_PARM TBShardware::getHardWareParm(void) { return rwparm; }

void TBShardware::setHardWareParm(RD_WT_PARM rw) { rwparm = rw; }