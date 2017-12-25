//New_eCard接口方法

//引用其他動態連結庫,需要在實作的程式中此方法需優先使用，並引用Hid_Usb_Send DLL
//devfile : 連結庫路徑
extern "C" _declspec(dllexport) DWORD Dev_LoadComportLibrarys(char * devfile);
//引用其他動態連結庫,需要在實作的程式中此方法需優先使用，並引用Hid_Usb_Send DLL
//hinstLib : Hid_Usb_Send DLL的procdure 句柄
extern "C" _declspec(dllexport) DWORD WINAPI Dev_LoadComLibHins(HINSTANCE hinstLib)

//掃瞄目前連接的裝置數量
//GetDevCnt:回傳裝置數量
extern "C" _declspec(dllexport) int Dev_FindDevCnt(int*GetDevCnt);

//裝置響滴
//times:響滴次數
extern "C" _declspec(dllexport) int Dev_Bell(int times);

//打開虛擬串口
//port:串口對應的裝置號起始值為1，依裝置數量遞增1,2,3...以此類推
//baudrate固定填0即可
extern "C" _declspec(dllexport) DWORD Dev_OpenComport(DWORD port, unsigned long baudrate);

//關閉所有串口連接
extern "C" _declspec(dllexport) void Dev_CloseComport();

//取得卡片硬卡號
extern "C" _declspec(dllexport) DWORD Dev_ReadCardSerialNo(unsigned char *sn);

//取得工卡的工號、姓名、流水號
//EmpNo:回傳工號
//EmpName:回傳姓名
//EmpCardID:回傳流水號
 DWORD Ter_ReadEmpInfo(char *EmpNo, char *EmpName, int *EmpCardID);
 
 //使用自定義key讀塊
 //BlockNum:塊編號,[0]~[63]
 //Passwd:Key Value,長度[6]
 //KeyType: 0x60->KeyA  0x61->KeyB
 //PBlock_Data:塊內容,長度[16]
 //Card_SN:硬卡號,長度[4],預設使用[0,0,0,0]即可
extern "C" _declspec(dllexport) DWORD Ter_ReadDataPW(BYTE BlockNum, unsigned char * Passwd, BYTE KeyType, unsigned char * PBlock_Data, unsigned char * Card_SN)
 
//工卡讀塊
//BlockNum:塊編號,[0]~[63]
//PBlock_Data:塊內容,長度[16]
//Card_SN:硬卡號,長度[4],預設使用[0,0,0,0]即可
//IsSector:false 
extern "C" _declspec(dllexport) DWORD Dev_ReadDataEx(BYTE BlockNum, unsigned char * PBlock_Data,unsigned char * Card_SN, BOOL IsSector)

 //使用自定義key寫塊
 //BlockNum:塊編號,[0]~[63],[0]~[2]不可寫
 //Passwd:Key Value,長度[6]
 //KeyType: 0x60->KeyA  0x61->KeyB
 //PBlock_Data:塊內容，長度[16]
 //Card_SN:硬卡號，長度[4],預設使用[0,0,0,0]即可
extern "C" _declspec(dllexport) DWORD Ter_WriteDataPW(BYTE BlockNum, unsigned char * Passwd, BYTE KeyType , unsigned char * PBlock_Data, unsigned char * Card_SN)

//工卡寫塊
//BlockNum:塊編號,[0]~[63]
//PBlock_Data:塊內容,長度[16]
//Card_SN:硬卡號,長度[4],預設使用[0,0,0,0]即可
//IsSector:false 
extern "C" _declspec(dllexport) DWORD Dev_WriteDataEx(BYTE BlockNum, unsigned char * PBlock_Data,unsigned char * Card_SN, BOOL IsSector)

//工卡讀扇區
//BlockNum:扇區編號,[0]~[15]
//Card_SN:硬卡號，長度[4],預設使用[0,0,0,0]即可
//IsSector:true
extern "C" _declspec(dllexport) DWORD Dev_ReadSectorDataEx(BYTE BlockNum, unsigned char * PBlock_Data,unsigned char * Card_SN, BOOL IsSector)

//工卡寫扇區
//BlockNum:扇區編號,[0]~[15]
//Card_SN:硬卡號，長度[4],預設使用[0,0,0,0]即可
//IsSector:true
extern "C" _declspec(dllexport) DWORD Dev_WriteSectorDataEx(BYTE BlockNum, unsigned char * PBlock_Data,unsigned char * Card_SN, BOOL IsSector)
									  
									  
									  