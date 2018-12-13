#ifndef TBSBASE_H
#define TBSBASE_H
#define NOMINMAX
#define RWNO 128
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QDebug>
#include <QDialog>
#include <QFile>
#include <QHostAddress>
#include <QMessageBox>
#include <QMutex>
#include <QNetworkInterface>
#include <QObject>
#include <QProcess>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QThread>
#include <QTreeWidgetItem>
#include "tbsmesgdlg.h"
#ifdef Q_OS_WIN  // windows
#include <atlbase.h>
#include <bdatypes.h>
#include <comdef.h>
#include <conio.h>
#include <initguid.h>
#include <ks.h>
#include <ksmedia.h>
#include <tuner.h>
#include <windows.h>
#include <winsock.h>
#include <bdaiface.h>
#include <bdamedia.h>
#define QMSLEEP(n) Sleep(n)

#else  // linux
#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <inttypes.h>
#include <linux/dvb/frontend.h>
#include <linux/fs.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define QMSLEEP(n) usleep(1000 * n)

#endif
#define TBSSWAP(a, b) \
  do {                \
    a ^= b;           \
    b ^= a;           \
    a ^= b;           \
  } while (0)
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifndef WRITE
#define WRITE 0
#endif
#ifndef READ
#define READ 1
#endif
// run
#define TBS_NULL_FUNC 0
#define TBS_READ_FUNC 1
#define TBS_WRITE_FUNC 2
#define TBS_UDPMULTICAST_FUNC 3
#define TBS_RESET_FUNC 4
#define TBS_UDOMULTICAST_MAC_FUNC 5
#define TBS_RESTSRT_MCU_FUNC 6
// read
#define READ_NULL_FUNC 0
#define READ_NET_PARM_FUNC 1
#define READ_MODULATOR_PARM_FUNC 2
#define READ_NET_MODULATOR_PARM_FUNC 3
#define READ_NET_MAC_FUNC 4

// write
#define WRITE_NULL_FUNC 0
#define WRITE_NET_PARM_FUNC 1
#define WRITE_MODULATOR_PARM_FUNC 2
#define WRITE_NET_MAC_FUNC 4

#define REG64_BY_UDP_FUNC 1

#define REG32_TO_OR_FromExtMemOnce 1

#define REG32MonopolizeCPU 1

class RD_WT_PARM {
 public:
  u8 switchStatus;
  int dhcp;
  int port;
  QString ip;
  QString Netmask;
  QString gateway;
  QString netmac;
  QString setnetmac;
  u8 protocol;
  int tsport;
  int devno;
  int qam;
  int sym;
  QString pla;
  QString fre;
  QString lev;
  QString mucastip;
  int isRst;
  int ismcurst;
  int tunernum;
};

class TBS_Msg_Type {
 public:
  int type;
  int iserror;
  int isread;
  int isreadall;
  int btnL;
  int btnR;
  u8 switchStatus;
  QString btnRtext;
  QString tilie;
  QString displaytext;
  QString devip;
  int devport;
};

class NET_NODE {
 public:
  QString ip;
  int port;
  int switchStatus;
};

class TBSbase {
 public:
  explicit TBSbase();
  ~TBSbase();
#ifdef Q_OS_WIN  // windows
  SOCKET udpOpen(QString ipaddr, int ipport);
  SOCKET udpClose(SOCKET ufd);
  SOCKET udpOpen_no(QString ipaddr, int ipport);
  SOCKET getudpfd(void);
  void setudpfd(SOCKET ufd);

#else
  int udpOpen(QString ipaddr, int ipport);
  int udpClose(int ufd);
  int udpOpen_no(QString ipaddr, int ipport);
  int getudpfd(void);
  void setudpfd(int ufd);
#endif

  int readREG64ByUDP(int subAddr, unsigned char num, unsigned char *rdbuffer);

  int writeREG64ByUDP(int subAddr, unsigned char num, unsigned char *wtbuffer);

  int readREG(int mode, int subAddr, unsigned char num,
              unsigned char *rdbuffer);

  int writeREG(int mode, int subAddr, unsigned char num,
               unsigned char *rdbuffer);

  int readREG32FromExternalMemoryOnce(int m_addr, unsigned char *rdbuff,
                                      unsigned char num);

  int writeREG32ToExternalMemoryOnce(int m_addr, unsigned char *wtbuff,
                                     unsigned char num);

  int readFromExternalMemoryOnce(int mode, int m_addr, unsigned char *rdbuff,
                                 unsigned char num);

  int writeToExternalMemoryOnce(int mode, int m_addr, unsigned char *wtbuff,
                                unsigned char num);
  int readFromExternalMemory(int ram_addr, unsigned char *rdbff, int rd_size);
  int writeToExternalMemory(int ram_addr, unsigned char *wtbff, int wt_size);
  int controlExternalMemory(int mode, int addr, unsigned char *buff, int size);
  int readREG32MonopolizeCPUStatus(int m_addr, unsigned char *rdbuff,
                                   unsigned char num);
  int writeREG32MonopolizeCPUStatus(int m_addr, unsigned char *wtbuff,
                                    unsigned char num);
  int readMonopolizeCPUStatus(int mode, int m_addr, unsigned char *rdbuff,
                              unsigned char num);
  int writeMonopolizeCPUStatus(int mode, int m_addr, unsigned char *wtbuff,
                               unsigned char num);
  int writeRdCmdFinish(int m_addr, unsigned char *wtbuff, unsigned char num);

  int checkHostStatus(int cs);
  int waitForHostWorkDone();

 private:
  struct sockaddr_in udpsockaddr;

#ifdef Q_OS_WIN  // windows
  // net
  SOCKET udpfd;
  WSADATA wsaData;
  int len;
#else
  int udpfd;
  socklen_t len;
#endif
};

#endif  // TBSBASE_H