//New_eCard���f��k

//�ޥΨ�L�ʺA�s���w,�ݭn�b��@���{��������k���u���ϥΡA�äޥ�Hid_Usb_Send DLL
//devfile : �s���w���|
extern "C" _declspec(dllexport) DWORD Dev_LoadComportLibrarys(char * devfile);
//�ޥΨ�L�ʺA�s���w,�ݭn�b��@���{��������k���u���ϥΡA�äޥ�Hid_Usb_Send DLL
//hinstLib : Hid_Usb_Send DLL��procdure �y�`
extern "C" _declspec(dllexport) DWORD WINAPI Dev_LoadComLibHins(HINSTANCE hinstLib)

//���˥ثe�s�����˸m�ƶq
//GetDevCnt:�^�Ǹ˸m�ƶq
extern "C" _declspec(dllexport) int Dev_FindDevCnt(int*GetDevCnt);

//�˸m�T�w
//times:�T�w����
extern "C" _declspec(dllexport) int Dev_Bell(int times);

//���}������f
//port:��f�������˸m���_�l�Ȭ�1�A�̸˸m�ƶq���W1,2,3...�H������
//baudrate�T�w��0�Y�i
extern "C" _declspec(dllexport) DWORD Dev_OpenComport(DWORD port, unsigned long baudrate);

//�����Ҧ���f�s��
extern "C" _declspec(dllexport) void Dev_CloseComport();

//���o�d���w�d��
extern "C" _declspec(dllexport) DWORD Dev_ReadCardSerialNo(unsigned char *sn);

//���o�u�d���u���B�m�W�B�y����
//EmpNo:�^�Ǥu��
//EmpName:�^�ǩm�W
//EmpCardID:�^�Ǭy����
 DWORD Ter_ReadEmpInfo(char *EmpNo, char *EmpName, int *EmpCardID);
 
 //�ϥΦ۩w�qkeyŪ��
 //BlockNum:���s��,[0]~[63]
 //Passwd:Key Value,����[6]
 //KeyType: 0x60->KeyA  0x61->KeyB
 //PBlock_Data:�����e,����[16]
 //Card_SN:�w�d��,����[4],�w�]�ϥ�[0,0,0,0]�Y�i
extern "C" _declspec(dllexport) DWORD Ter_ReadDataPW(BYTE BlockNum, unsigned char * Passwd, BYTE KeyType, unsigned char * PBlock_Data, unsigned char * Card_SN)
 
//�u�dŪ��
//BlockNum:���s��,[0]~[63]
//PBlock_Data:�����e,����[16]
//Card_SN:�w�d��,����[4],�w�]�ϥ�[0,0,0,0]�Y�i
//IsSector:false 
extern "C" _declspec(dllexport) DWORD Dev_ReadDataEx(BYTE BlockNum, unsigned char * PBlock_Data,unsigned char * Card_SN, BOOL IsSector)

 //�ϥΦ۩w�qkey�g��
 //BlockNum:���s��,[0]~[63],[0]~[2]���i�g
 //Passwd:Key Value,����[6]
 //KeyType: 0x60->KeyA  0x61->KeyB
 //PBlock_Data:�����e�A����[16]
 //Card_SN:�w�d���A����[4],�w�]�ϥ�[0,0,0,0]�Y�i
extern "C" _declspec(dllexport) DWORD Ter_WriteDataPW(BYTE BlockNum, unsigned char * Passwd, BYTE KeyType , unsigned char * PBlock_Data, unsigned char * Card_SN)

//�u�d�g��
//BlockNum:���s��,[0]~[63]
//PBlock_Data:�����e,����[16]
//Card_SN:�w�d��,����[4],�w�]�ϥ�[0,0,0,0]�Y�i
//IsSector:false 
extern "C" _declspec(dllexport) DWORD Dev_WriteDataEx(BYTE BlockNum, unsigned char * PBlock_Data,unsigned char * Card_SN, BOOL IsSector)

//�u�dŪ����
//BlockNum:���Ͻs��,[0]~[15]
//Card_SN:�w�d���A����[4],�w�]�ϥ�[0,0,0,0]�Y�i
//IsSector:true
extern "C" _declspec(dllexport) DWORD Dev_ReadSectorDataEx(BYTE BlockNum, unsigned char * PBlock_Data,unsigned char * Card_SN, BOOL IsSector)

//�u�d�g����
//BlockNum:���Ͻs��,[0]~[15]
//Card_SN:�w�d���A����[4],�w�]�ϥ�[0,0,0,0]�Y�i
//IsSector:true
extern "C" _declspec(dllexport) DWORD Dev_WriteSectorDataEx(BYTE BlockNum, unsigned char * PBlock_Data,unsigned char * Card_SN, BOOL IsSector)
									  
									  
									  