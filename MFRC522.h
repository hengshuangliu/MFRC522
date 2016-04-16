#ifndef MFRC522_H
#define MFRC522_H
/******************************************************************************
 * 包含文件
 ******************************************************************************/
#include <bcm2835.h>
#include <stdio.h>

#define MAX_LEN 18
/////////////////////////////////////////////////////////////////////
//MF522命令字
/////////////////////////////////////////////////////////////////////
#define PCD_IDLE              0x00               //取消当前命令
#define PCD_AUTHENT           0x0E               //验证密钥
#define PCD_RECEIVE           0x08               //接收数据
#define PCD_TRANSMIT          0x04               //发送数据
#define PCD_TRANSCEIVE        0x0C               //发送并接收数据
#define PCD_RESETPHASE        0x0F               //复位
#define PCD_CALCCRC           0x03               //CRC计算
/////////////////////////////////////////////////////////////////////
//Mifare_One卡片命令字
/////////////////////////////////////////////////////////////////////
#define PICC_REQIDL           0x26               //寻天线区内未进入休眠状态
#define PICC_REQALL           0x52               //寻天线区内全部卡
#define PICC_ANTICOLL         0x93            
#define PICC_ANTICOLL1        0x93               //防冲撞
#define PICC_ANTICOLL2        0x95               //防冲撞
#define PICC_AUTHENT1A        0x60               //验证A密钥
#define PICC_AUTHENT1B        0x61               //验证B密钥
#define PICC_READ             0x30               //读块
#define PICC_WRITE            0xA0               //写块
#define PICC_DECREMENT        0xC0               //扣款
#define PICC_INCREMENT        0xC1               //充值
#define PICC_RESTORE          0xC2               //调块数据到缓冲区
#define PICC_TRANSFER         0xB0               //保存缓冲区中数据
#define PICC_HALT             0x50               //休眠
/////////////////////////////////////////////////////////////////////
//MF522 FIFO长度定义
/////////////////////////////////////////////////////////////////////
#define DEF_FIFO_LENGTH       64                 //FIFO size=64byte
/////////////////////////////////////////////////////////////////////
//MF522寄存器定义
/////////////////////////////////////////////////////////////////////
// PAGE 0
#define     RFU00                 0x00   
#define     CommandReg            0x01   
#define     CommIEnReg            0x02   
#define     DivlEnReg             0x03   
#define     CommIrqReg            0x04   
#define     DivIrqReg             0x05
#define     ErrorReg              0x06   
#define     Status1Reg            0x07   
#define     Status2Reg            0x08   
#define     FIFODataReg           0x09
#define     FIFOLevelReg          0x0A
#define     WaterLevelReg         0x0B
#define     ControlReg            0x0C
#define     BitFramingReg         0x0D
#define     CollReg               0x0E
#define     RFU0F                 0x0F
// PAGE 1    
#define     RFU10                 0x10
#define     ModeReg               0x11
#define     TxModeReg             0x12
#define     RxModeReg             0x13
#define     TxControlReg          0x14
#define     TxAutoReg             0x15
#define     TxSelReg              0x16
#define     RxSelReg              0x17
#define     RxThresholdReg        0x18
#define     DemodReg              0x19
#define     RFU1A                 0x1A
#define     RFU1B                 0x1B
#define     MifareReg             0x1C
#define     RFU1D                 0x1D
#define     RFU1E                 0x1E
#define     SerialSpeedReg        0x1F
// PAGE 2   
#define     RFU20                 0x20 
#define     CRCResultRegM         0x21
#define     CRCResultRegL         0x22
#define     RFU23                 0x23
#define     ModWidthReg           0x24
#define     RFU25                 0x25
#define     RFCfgReg              0x26
#define     GsNReg                0x27
#define     CWGsCfgReg            0x28
#define     ModGsCfgReg           0x29
#define     TModeReg              0x2A
#define     TPrescalerReg         0x2B
#define     TReloadRegH           0x2C
#define     TReloadRegL           0x2D
#define     TCounterValueRegH     0x2E
#define     TCounterValueRegL     0x2F
// PAGE 3     
#define     RFU30                 0x30
#define     TestSel1Reg           0x31
#define     TestSel2Reg           0x32
#define     TestPinEnReg          0x33
#define     TestPinValueReg       0x34
#define     TestBusReg            0x35
#define     AutoTestReg           0x36
#define     VersionReg            0x37
#define     AnalogTestReg         0x38
#define     TestDAC1Reg           0x39 
#define     TestDAC2Reg           0x3A  
#define     TestADCReg            0x3B  
#define     RFU3C                 0x3C  
#define     RFU3D                 0x3D  
#define     RFU3E                 0x3E  
#define     RFU3F    0x3F
/////////////////////////////////////////////////////////////////////
//和MF522通讯时返回的错误代码
/////////////////////////////////////////////////////////////////////
#define MI_OK                          0
#define MI_NOTAGERR                    (-1)
#define MI_ERR                         (-2)
 
 /******************************************************************************
 * 函 数 名：init
 * 功能描述：初始化RC522
 * 输入参数：无
 * 返 回 值：无
 ******************************************************************************/
 void MFRC522_init();
 
 /******************************************************************************
 * 函 数 名：writeMFRC522
 * 功能描述：向MFRC522的某一寄存器写一个字节数据
 * 输入参数：addr--寄存器地址；val--要写入的值
 * 返 回 值：无
 ******************************************************************************/
void writeMFRC522(unsigned char Address, unsigned char value);

/******************************************************************************
 * 函 数 名：readMFRC522
 * 功能描述：从MFRC522的某一寄存器读一个字节数据
 * 输入参数：addr--寄存器地址
 * 返 回 值：返回读取到的一个字节数据
 ******************************************************************************/
unsigned char readMFRC522(unsigned char Address);

/******************************************************************************
 * 函 数 名：setBitMask
 * 功能描述：置RC522寄存器位
 * 输入参数：reg--寄存器地址;mask--置位值
 * 返 回 值：无
 ******************************************************************************/
void RFID_setBitMask(unsigned char reg, unsigned char mask);

/******************************************************************************
 * 函 数 名：clearBitMask
 * 功能描述：清RC522寄存器位
 * 输入参数：reg--寄存器地址;mask--清位值
 * 返 回 值：无
 ******************************************************************************/
void RFID_clearBitMask(unsigned char reg, unsigned char mask);

/******************************************************************************
 * 函 数 名：antennaOn
 * 功能描述：开启天线,每次启动或关闭天险发射之间应至少有1ms的间隔
 * 输入参数：无
 * 返 回 值：无
 ******************************************************************************/
void RFID_antennaOn(void);

/******************************************************************************
 * 函 数 名：antennaOff
 * 功能描述：关闭天线,每次启动或关闭天险发射之间应至少有1ms的间隔
 * 输入参数：无
 * 返 回 值：无
 ******************************************************************************/
void RFID_antennaOff(void);

/******************************************************************************
 * 函 数 名：calculateCRC
 * 功能描述：用MF522计算CRC
 * 输入参数：pIndata--要读数CRC的数据，len--数据长度，pOutData--计算的CRC结果
 * 返 回 值：无
 ******************************************************************************/
void RFID_calculateCRC(unsigned char *pIndata, unsigned char len, unsigned char *pOutData);

/******************************************************************************
 * 函 数 名：MFRC522ToCard
 * 功能描述：RC522和ISO14443卡通讯
 * 输入参数：command--MF522命令字，
 *           sendData--通过RC522发送到卡片的数据,
 *                     sendLen--发送的数据长度
 *                     backData--接收到的卡片返回数据，
 *                     backLen--返回数据的位长度
 * 返 回 值：成功返回MI_OK
 ******************************************************************************/
unsigned char RFID_MFRC522ToCard(unsigned char command, unsigned char *sendData, unsigned char sendLen, unsigned char *backData, unsigned int *backLen);

 /******************************************************************************
 * 函 数 名：findCard
 * 功能描述：寻卡，读取卡类型号
 * 输入参数：reqMode--寻卡方式，
 *           TagType--返回卡片类型
 *                    0x4400 = Mifare_UltraLight
 *                    0x0400 = Mifare_One(S50)
 *                    0x0200 = Mifare_One(S70)
 *                    0x0800 = Mifare_Pro(X)
 *                    0x4403 = Mifare_DESFire
 * 返 回 值：成功返回MI_OK
 ******************************************************************************/
unsigned char RFID_findCard(unsigned char reqMode, unsigned char *TagType);

/******************************************************************************
 * 函 数 名：anticoll
 * 功能描述：防冲突检测，读取选中卡片的卡序列号
 * 输入参数：serNum--返回4字节卡序列号,第5字节为校验字节
 * 返 回 值：成功返回MI_OK
 ******************************************************************************/
unsigned char RFID_anticoll(unsigned char *serNum);

/******************************************************************************
 * 函 数 名：auth
 * 功能描述：验证卡片密码
 * 输入参数：authMode--密码验证模式
 *                     0x60 = 验证A密钥
 *                     0x61 = 验证B密钥
 *           BlockAddr--块地址
 *           Sectorkey--扇区密码
 *           serNum--卡片序列号，4字节
 * 返 回 值：成功返回MI_OK
 ******************************************************************************/
unsigned char RFID_auth(unsigned char authMode, unsigned char BlockAddr, unsigned char *Sectorkey, unsigned char *serNum);

/******************************************************************************
 * 函 数 名：read
 * 功能描述：读块数据
 * 输入参数：blockAddr--块地址;recvData--读出的块数据
 * 返 回 值：成功返回MI_OK
 ******************************************************************************/
unsigned char RFID_read(unsigned char blockAddr, unsigned char *recvData);

/******************************************************************************
 * 函 数 名：write
 * 功能描述：写块数据
 * 输入参数：blockAddr--块地址;writeData--向块写16字节数据
 * 返 回 值：成功返回MI_OK
 ******************************************************************************/
unsigned char RFID_write(unsigned char blockAddr, unsigned char *writeData);

/******************************************************************************
 * 函 数 名：selectTag
 * 功能描述：选卡，读取卡存储器容量
 * 输入参数：serNum--传入卡序列号
 * 返 回 值：成功返回卡容量
 ******************************************************************************/
unsigned char RFID_selectTag(unsigned char *serNum);

/******************************************************************************
 * 函 数 名：Halt
 * 功能描述：命令卡片进入休眠状态
 * 输入参数：无
 * 返 回 值：无
 ******************************************************************************/
void RFID_halt();
 
#endif
