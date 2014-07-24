#ifndef _CONFIGURATION_CONTROL_H
#define _CONFIGURATION_CONTROL_H

#include "configuration_stack.h"
#include "configuration_queue.h"
#include "configuration_system.h"
#include <math.h>
#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include "CassType.h"
#include "CassSysVar.h"

extern stack paramStack;

//����Ȥ�������
typedef struct region_of_interest_desc_type_
{
	int x_start;
	int y_start;
	int x_end;
	int y_end;
} region_of_interest_desc_type;  //(0,0,0,0)��ʾѡ������ͼ��

//��ͷ����
typedef struct camera_param_desc_type_
{
		int chroma;
		int luminance;
		int contrast;
		int saturation;
		int rsd[4];
} camera_param_desc_type;

/*������ṹ*/
typedef struct point_feature_desc_type_
{
	int x;          //x����
	int y;          //y����
	int v;          //����ֵ  
	int w;           //Ȩ��
} point_feature_desc_type;

/*ÿ�������������Ϣ��С��λ�ã�10�����ֹ�300����������Ϣ*/
typedef struct small_point_space_desc_type_
{
	int leftbound;          //���Ͻǿ�������
	int topbound;
	int width;				//��	       
	int height;
	point_feature_desc_type  point[300];
} small_point_feature_desc_type;

//�������ݰ�
typedef struct image_data_packet_desc_type_
{
	int updated;  //�汾��Ϣversion    
	int isGray;
	camera_param_desc_type     camera_desc;//��ͷ����
	region_of_interest_desc_type  roi_desc;	//��ͼ������Ϣ
	small_point_feature_desc_type space[10] ;//����ģ����Ϣ
} image_data_packet_desc_type;
 

/*bmp��Ϣ�ṹ��*/
typedef struct          
{
  long fileSize;
	long width;
	long height;	
	long dwSize;
} BMPINFO;

//�����ṹ��

//ʶ����
typedef struct
{
	uint8 index;
	uint8 percent;
}MATCHStruct;

/*typedef struct
{
    uint8 index;
}FILEOUTStruct;*/


//�豸����
typedef struct
{
	uint8 index;
	char  *portName; //���ں�
    int baudRate; //������
	uint8 parity;  //��żУ��
	uint8 stopBits; //ֹͣλ
	uint8 dataBits;  //����λ
}CAMERAINStruct;

//��˹�˲�
typedef struct
{
	uint8 index;
	uint8 length;
}GAUSSIANSMOOTHINGStruct;

//��ֵ�˲�
typedef struct
{
	uint8 index;
	uint8 length;
}MEDIANFILTERStruct;

//��ֵ�˲�
typedef struct
{
	uint8 index;
	uint8 length;
}MEANFILTERStruct;

//����������
typedef struct
{
	uint8 index;
	uint8 threshold;
}SOBELStruct;

//����ά�ش���
typedef struct
{
	uint8 index;
	uint8 threshold;
}PREWITTStruct;

//������˹����
typedef struct
{
	uint8 index;

}LAPLACEStruct;


//��ֵ��
typedef struct
{
	uint8 index;
	uint8 threshold;
}BINARYStruct;

//���Ŷ�ֵ��
typedef struct
{
	uint8 index;
}OSTUBINARYStruct;

//��ת��ɫ
typedef struct
{
	uint8 index;
}ANTICOLORStruct;

//�Ҷ�����
typedef struct
{
	uint8 index;
	uint8 left_gray_in;
	uint8 left_gray_out;
	uint8 right_gray_in;
	uint8 right_gray_out;
}GRAYSCALESTRETCHStruct;

//ֱ��ͼ���⻯
typedef struct
{
	uint8 index;
}HIAGRAMStruct;


//ȥ��
typedef struct
{
	uint8 index;
	uint8 noise_size;
}DENOSINGStruct;

//ϸ��
typedef struct
{
	uint8 index;
}ZHANGTHINStruct;

//����
typedef struct
{
	uint8 index;
	uint8 length;
}DIALATEStruct;


//��ʴ
typedef struct
{
	uint8 index;
	uint8 length;
}ERODEStruct;

//������
typedef struct
{
	uint8 index;
	uint8 length;
}OPENOPERATIONStruct;

//�ղ���
typedef struct
{
	uint8 index;
	uint8 length;
}CLOSEOPERATIONStruct;

//�����Ե���
typedef struct
{
	uint8 index;
	uint8 low_threshold;
	uint8 high_threshold;
}CANNYStruct;

//����ֱ�߼��
typedef struct
{
	uint8 index;
}HOUGHLINESStruct;

//�Ϳ�
typedef struct
{
	uint8 index;
}HOLLOWEDStruct;

//����˹�ǵ�
typedef struct
{
	uint8 index;
	uint8 low_threshold;
	uint8 high_threshold;
}HARRISStruct;

//��������
typedef struct
{
	uint8 index;
}CENTEROFGRAVITYStruct;

// �����ṹ��
// "PID"

typedef struct
{
	fp32 Kp;	 // ����
	#if defined PID_Ki_NOT0
	fp32 Ki;	 // ����
	#endif
	fp32 Kd;	 // ΢��

	uint32 Ts;	 // ����
	fp32 ei;	 // ƫ��
	fp32 ei_1;
	fp32 ei_2;
	// ����״̬
	//uint8 ucIsEmergency;
	// ��ȫֵ
	//fp32 fSaveValue;
	// ����ֵ����
	fp32 fSVL;  // �ڸ���ֵ,�ɲ���Ա����
	#if defined PID_fSR_NOT0
	fp32 fSR;  // ����ֵ�ı仯��,��ֵ	
	fp32 fSV;	// ��¼�ϴεĸ���ֵ
	#endif
	// ����������
	fp32 fPH;  // ���ޱ���
	fp32 fPL;  // ���ޱ���
	uint8 cPHA;  // ����״̬
	uint8 cPLA;  // ����״̬
	fp32 fHY;  // ��������	   10
	#if defined PID_cSelect_3 || defined PID_cSelect_4 || defined PID_fPR_NOT0
	fp32 fPV; 	// ������
	#endif
	#if defined PID_fPR_NOT0
	fp32 fPR;  // �������ı仯��
	#endif
	// ƫ���	
	uint8 cDorR; // 0 ������; 1 ������
	fp32 fDL;  // ƫ���ֵ
	uint8 cDLA;  // ƫ���״̬
	fp32 fBSGP; // ƫ������
	//fp32 fBSGN; // ƫ������
    #if (defined PID_cICM_1 || defined PID_cICM_2 || defined PID_cICM_3)
	fp32 fICV;  // ���벹���� 
	uint8 cICM;  // ���벹����ʽ
	#endif
	// PID����
	uint8 cSelect; // �㷨ѡ��	10
	fp32 fMV; // ���ֵ
	#if defined PID_cSelect_1	 
	fp32 fE0; // ���ַ�������
	#endif
	fp32 fMH; // ����������
	fp32 fML; // ����������
	#if defined PID_cSelect_3 || defined PID_cSelect_4
	fp32 fPV_1; // �ϴεı�����
	fp32 fPV_2; // ���ϴεı�����
	#endif
	// �������
	#if defined PID_cOCM_1 || defined PID_cOCM_2 || defined PID_cOCM_3
	fp32 fOCV;  // ���������	
	uint8 cOCM;  // ���������ʽ
	#endif
	#if defined PID_fMR_NOT0
	fp32 fMR;  // �仯������
	#endif
	#if defined PID_cFHorNH_1
	uint8 cFHorNH;  // �������	10
	#endif
	#if defined PID_cFSorNS_1
	uint8 cFSorNS;  // ��ȫ���
	fp32 fMS;  // ��ȫ�����
	#endif
	// �Զ����ֶ��л�
	uint8 cCtrlMode; // �����Զ�	�����ֶ�
}PIDStruct;

// ���ͺ󲹳�
typedef struct
{
	uint32 ulT1;  // ʱ�䳣��1
	uint32 ulT2;  // ʱ�䳣��2
	uint32 ulLagT;  //�ͺ�ʱ��
	fp32 fK;  // ��������
	uint32 ulTs;  // ��������
	fp32 fPV;  // ���
	fp32 fMV_1; // ���ϴ�����
	LinkQueue *queueIn;  // �������
	fp32 fMV;	 // �ϴ�����
	
	 	
}SMITHStruct;

// �����Ŀ���
typedef struct
{
	fp32 fK;   // ���ض���ķŴ�ϵ��
	uint32 ulT1;  // һ�ױ��ض����ʱ�䳣��
	uint32 ulTao; // ���ض���Ĵ��ͺ�ʱ��
	uint32 ulTs;  // ��������
	fp32 fMH;  // �������
	fp32 fML;  // �������
	uint8 cCtrlMod;  // 0�Զ�/1�ֶ�
	LinkQueue *queueMV;  // �������
	fp32 fei;  // �ϴε�ƫ��
	fp32 fMV;  // ���
	fp32 fSV;  // �趨ֵ
}LEASTStruct;

// ���ֿ���
typedef struct
{
	fp32 fK;  // ���ض���ķŴ�ϵ��
	uint32 ulT1;  // ʱ�䳣��
	uint32 ulT2;  // ʱ�䳣��
	uint32 ulTs;  // ��������
	uint32 ulTTao;  // �ջ�ϵͳ��ʱ�䳣�� 
	uint32 ulTao;  // �ͺ�ʱ��
	fp32 fMH; // �������
	fp32 fML; // �������
	uint8 cCtrlMod; // 0�Զ�/1�ֶ�
	LinkQueue *queueMV;  // �������
	fp32 fMV; // �ϴε����,Ҳ������ֶ��޸ĵ�ֵ
	fp32 fMV_1; 
	fp32 fei;  // �ϴε�ƫ��
	fp32 fei_1; // ���ϴε�ƫ��
	fp32 fSV;  // �趨ֵ
}DARLINStruct;

// ǰ��������
typedef struct
{
	fp32 fK1;  // �Ŷ�����ķŴ�ϵ��
	fp32 fK2;  // ���ض���ķŴ�ϵ��
	uint32 ulT1;  // �Ŷ�ͨ����ʱ�䳣��
	uint32 ulT2;  // ���ض����ʱ�䳣��
	uint32 ulTs;  // ��������
	uint32 ulTTao1;  // �Ŷ�ͨ����ʱ�䳣��
	uint32 ulTTao2;  // ���ض����ʱ�䳣��
	fp32 fMH; // �������
	fp32 fML; // �������
	uint8 cCtrlMod; // 0�Զ�/1�ֶ�
	fp32 fMV; // �ϴε����
	LinkQueue *queuePV;  // �������   
}PREStruct;

// �����㷨
typedef struct
{
	uint8 iN;  // ��·,���255·
	uint8 hasMatrix; // �Ƿ���������,����ʱ����һ��
	fp32 *paramMatrix;  // �������Ĳ���
	fp32 *jieOuMatrix; // �������Ľ��
	fp32 *ei;   // �ϴ�ƫ������
	fp32 *ei_1; // ���ϴ�ƫ������
	fp32 *fUk;  // �ϴο��������
	// �����е�PID����,�����м�·,���������о��м���
	fp32 *fKp;
	fp32 *fKi;
	fp32 *fKd;
	fp32 *fSV;	
	uint8  *cCtrlMod;
	fp32 *fMH; // �������
	fp32 *fML; // �������
	fp32 *fMV; // ���
	uint32 ulTs; // һ������

}JIEOUStruct;

// ģ������
typedef struct
{
	fp32 *fuzzyControlList; // ģ�����Ʊ�,���߼���
	fp32 fEH; // ƫ�����ֵ
	fp32 fECH; // ƫ��仯�����ֵ
	fp32 fEi;  // ƫ��
	fp32 fUH;  // �����ֵ
	uint32 ulL;  // ƫ��ģ������
	uint32 ulM;  // ƫ��仯��ģ������
	uint32 ulN;  // ������ģ������
	uint8 cCtrlMod;       // �Զ�/�ֶ�
	uint32 ulTs; // ����
	fp32 fMV;  // ���
	fp32 fSV;  // �趨ֵ 
}FUZZYStruct;

// "��"
typedef struct
{
	uint8 type;  // 0: λ���� 1:�ֽ����� 0xFF 2:������ 0xFFFF 3:˫������ 0xFFFFFFFF
	fp32 fLastVal; // �ϴε�ֵ
}ANDStruct;

// "��"
typedef struct
{
	uint8 type;  // 0: λ���� 1:�ֽ����� 0xFF 2:������ 0xFFFF 3:˫������ 0xFFFFFFFF
	fp32 fLastVal; // �ϴε�ֵ
}ORStruct;

// "���"
typedef struct
{
	uint8 type;  // 0: λ���� 1:�ֽ����� 0xFF 2:������ 0xFFFF 3:˫������ 0xFFFFFFFF
	  fp32 fLastVal; // �ϴε�ֵ
}XORStruct;

// "��"
typedef struct
{
	uint8 type;  // 0: λ���� 1:�ֽ����� 0xFF 2:������ 0xFFFF 3:˫������ 0xFFFFFFFF
	fp32 fLastVal; // �ϴε�ֵ
}NOTStruct;

// "���"
typedef struct
{
	uint8 type;  // 0: λ���� 1:�ֽ����� 0xFF 2:������ 0xFFFF 3:˫������ 0xFFFFFFFF
	fp32 fLastVal; // �ϴε�ֵ
}NANDStruct;

// "���"
typedef struct
{
	uint8 type;  // 0: λ���� 1:�ֽ����� 0xFF 2:������ 0xFFFF 3:˫������ 0xFFFFFFFF
	fp32 fLastVal; // �ϴε�ֵ
}NORStruct;

// "�����벻һ��"
typedef struct
{
	uint8 type;  // 0: λ���� 1:�ֽ����� 0xFF 2:������ 0xFFFF 3:˫������ 0xFFFFFFFF
	//uint32 cycle;	
	uint8 lastValue;  // �ϴε�ֵ,����һ������
}DISP3Struct;

// "����"
typedef struct
{
	uint8 type;  // 0: λ���� 1:�ֽ����� 0xFF 2:������ 0xFFFF 3:˫������ 0xFFFFFFFF
	fp32 fLastVal; // �ϴε�ֵ
}SWITStruct;

// "��������"
typedef struct
{
	uint32 cycle;  // ��������
	uint32 lastTimeRec;
	uint8 lastInValue;  // �ϴε�����ֵ
	uint8 lastOutValue;  // �ϴε����ֵ
}PULSEStruct;

// "�������"
typedef struct
{
	uint32 cycle;  // ����
	uint32 lastTimeRec;
	uint8 lastInValue;  // �ϴε�����ֵ
	uint8 lastOutValue;  // �ϴε����ֵ
}MAXPLStruct;

// ��С����
typedef struct
{
	uint32 cycle;  // ����
	uint32 lastTimeRec;
	uint8 lastInValue;  // �ϴε�����ֵ
	uint8 lastOutValue;  // �ϴε����ֵ
}MINPLStruct;

// RS
typedef struct
{
	uint8 lastValue;  // �ϴε�ֵ
}RSStruct;

// DELAY
typedef struct
{
	uint32 cycle;
	uint32 lastTimeRec;
	uint8 lastOutValue;  
}DELAYStruct;

// ON��ʱ
typedef struct
{
	uint32 cycle;
	uint32 lastTimeRec;
	uint8 lastOutValue;
	uint8 lastInValue;
	uint8 onSign;   // OFF->ON��־  
}ONDLYStruct;

// OFF��ʱ
typedef struct
{
	uint32 cycle;
	uint32 lastTimeRec;
	uint8 lastOutValue;
	uint8 lastInValue;
	uint8 offSign;   // ON->OFF��־  
}OFFDLYStruct;

// �仯���
typedef struct
{
	uint8 lastIn1;
	uint8 lastIn2;
	uint8 lastIn3; 
	fp32 fLastVal; // �ϴε�ֵ 
}CHDCTStruct;
// ���Ź�
typedef struct
{
	uint32 cycle;
	uint32 lastTimeRec;	
	uint8 lastInValue;
	uint8 isTrigger;  // �Ƿ񴥷�
	fp32 fLastVal; // �ϴε�ֵ	  
}WTDOGStruct;

// ѡͨ��
typedef struct
{
	uint8 cIsMin1;  // �Ƿ���ѡ�ܵ���1����
	uint8 cIsMax1;  // �Ƿ���ѡ�ܸ���1����	
	fp32 fMin1;   // ѡͨ1����
	fp32 fMax1;   // ѡ��1����
	
	uint8 cIsMin2;  // �Ƿ���ѡ�ܵ���2����
	uint8 cIsMax2;  // �Ƿ���ѡ�ܸ���2����	
	fp32 fMin2;   // ѡͨ2����
	fp32 fMax2;   // ѡ��2����
	
	uint8 cIsMin3;  // �Ƿ���ѡ�ܵ���3����
	uint8 cIsMax3;  // �Ƿ���ѡ�ܸ���3����	
	fp32 fMin3;   // ѡͨ3����
	fp32 fMax3;   // ѡ��3����
	
	uint8 cIsMin4;  // �Ƿ���ѡ�ܵ���4����
	uint8 cIsMax4;  // �Ƿ���ѡ�ܸ���4����	
	fp32 fMin4;   // ѡͨ4����
	fp32 fMax4;   // ѡ��4����
	
	uint8 cIsMin5;  // �Ƿ���ѡ�ܵ���5����
	uint8 cIsMax5; // �Ƿ���ѡ�ܸ���5����	
	fp32 fMin5;   // ѡͨ5����
	fp32 fMax5;   // ѡ��5����
	
	uint8 cIsMin6;  // �Ƿ���ѡ�ܵ���6����
	uint8 cIsMax6;  // �Ƿ���ѡ�ܸ���6����	
	fp32 fMin6;   // ѡͨ6����
	fp32 fMax6;   // ѡ��6����
	
	uint8 cIsMin7;  // �Ƿ���ѡ�ܵ���7����
	uint8 cIsMax7;  // �Ƿ���ѡ�ܸ���7����	
	fp32 fMin7;   // ѡͨ7����
	fp32 fMax7;   // ѡ��7����
	
	uint8 cIsMin8;  // �Ƿ���ѡ�ܵ���8����
	uint8 cIsMax8;  // �Ƿ���ѡ�ܸ���8����	
	fp32 fMin8;   // ѡͨ8����
	fp32 fMax8;   // ѡ��8����

	fp32 fLastVal1; // �ϴε�ֵ
	fp32 fLastVal2; // �ϴε�ֵ
	fp32 fLastVal3; // �ϴε�ֵ
	fp32 fLastVal4; // �ϴε�ֵ
	fp32 fLastVal5; // �ϴε�ֵ
	fp32 fLastVal6; // �ϴε�ֵ
	fp32 fLastVal7; // �ϴε�ֵ
	fp32 fLastVal8; // �ϴε�ֵ
}SELECTStruct;
// ��������
typedef struct 
{
	fp32 fC1;   // ���̵�λת������
	fp32 fC2;   // �Ǳ�ϵ��
	uint8  ucTBase;  // ����ʱ�䵥λ
	
}PIStruct;

// �˲�
typedef struct 
{
	uint32  ulTs;  // ��������
	uint32  ulTF;	// �˲�ʱ�䳣��
	fp32 fLastPV;  // �ϴε����	
}FILTStruct;

// һ�״��ݺ���
typedef struct
{
	// �ĸ�����
	fp32 A;
	fp32 B;
	fp32 C;
	fp32 D;
	fp32 Xk; // �м���ʱ����
	fp32 Uk; // �ϴ�����	
	uint32 Ts;
}TRANSStruct;

// ��������
typedef struct 
{
	uint32 ulCount;   // ��������ǰ�ļ���ֵ
	uint32 ulSetValue;   // �������趨ֵ
	uint8 ucType;  // ����������: 0,����; 1,�½�; 2,�ߵ�ƽ; 3,�͵�ƽ
	uint8 ucIsComplete;  // �����Ƿ����
	uint8 ucIsAutoReset;  // �Ƿ��Զ���λ
	fp32 fLastInValue;  // �ϴε�����ֵ
}CNTStruct;

// ��ʱ����
typedef struct
{
	uint32 ulTimer;   // ��ǰ�ļ�ʱֵ
	uint32 ulSetTimer;  // Ԥ��ֵ
	uint8 ucIsFinish;  // �Ƿ����
	uint8 ucAutoReset;  // �Ƿ��Զ���λ
	uint32 ulLastTimeRec; // �ϴμ�¼��ʱ��
}TIMStruct;

// �ۼƵ�
typedef struct
{
	fp32 accValue;  // �ۼ�ֵ
	fp32 setValue;  // Ԥ��ֵ
	uint32 TBase;     // ʱ�����,����Ϊ��λ
	uint8 isTot;  // �Ƿ��ۼ�
	uint8 isComplete; // �ۼ��Ƿ����
	fp32 valveValue;  // ��ֵ,Ҳ����С�ź��г�
	uint8 isAuto;  // �Ƿ��Զ���λ
	uint32 lastTimeRec; // �ϴβɼ���ʱ��
}TOTStruct;

// ��ֵ��
typedef struct
{
	fp32 fMin;  // ����
	fp32 fMax;  // ����
}LIMITStruct;

// ������
typedef struct
{
	fp32 fMin;  // ����
	fp32 fMax;  // ����
}PERCENTStruct;

// ��ֵ������
typedef struct
{
	fp32 fInMin;  // �������
	fp32 fInMax;  // �������
	fp32 fOutMin;  // �������
	fp32 fOutMax;  // �������
	fp32 fRation;  // ��ֵ�趨
	fp32 fClimbCon;  // ���³���
	fp32 fBias;   // ƫ��
	uint8 ucCtrlMod;  // �Ƿ����Զ�
	fp32 fPV;  // ���ֶ�ʱ,����ֵ
	fp32 fMV;   // ���ֶ�ʱ,���ֵ
}RATIONStruct;

// б�¿��Ƶ�
typedef struct
{
	uint8 sectionNum;  // ��Ч����,��λ��Ҫ���
	uint8 outNum;  // �������
	uint32 controlTime;  // ����ʱ��,�����ʱ��1193Сʱ,��49��,��λ������
	//uint8 timeUnit;  // ʱ�䵥λ
	uint8 ctrlMod;
	#if defined RAMP_manStyle_1
	uint8 manStyle;  // �ֶ�ʱ��ʱ��ʽ,0��ʾֹͣ,1��ʾ������ʱ
	#endif
	uint8 terminateStyle;  // ��ֹ��ʽ,0��ʾһ��ʱ�����ɺ����¼�ʱ,��0��ʾ
								   // ʱ�����ɺ�ֹͣ����,���������ֵ;�Ƿ���ѭ������
								   // ����˵����һ����ٿ���
	fp32  initOutValue;   // ��ʼ�����ֵ
	fp32 endOutValue;   // ��ֵֹ
	uint32 time[24];  // û������ʼʱ��0,ʱ���,��λΪms
	fp32 outValue[24];   // û�����ֵ��ĩֵ,�����
	fp32 fMV;  // �ֶ����
	uint32 lastTimeRec;
}RAMPStruct;

// ���ؿ��Ƶ�51
typedef struct
{
	uint8 ucSelect; // ѡ��
	//fp32 fPV; // ���
}SW51Struct;

 // ��ѹ������
typedef struct
{
	uint8 ucType;  // �������� 0:Һ�� 1:���������� 
						   // 2:����������(����) 3:����������������
						   // 4:����
	fp32 fRG;  // ��Ʊ���
	fp32 fRP;  // ���ѹ��
	fp32 fRQ;  // ���������������
	fp32 fRT;  // ����¶�
	fp32 fP0;  // ��ѹת��ϵ��
	fp32 fT0;  // �¶�ת��ϵ��
	fp32 fRX;  // �������ѹ��ϵ��
}FLCPStruct;

// ��Ľṹ��
typedef struct
{
	fp32 x;
	fp32 y;
}PointStruct;
// ͨ�����Ի���
typedef struct
{
	fp32 fInMin; // �������ֵ
	fp32 fInMax;
	fp32 fOutMin; // �������ֵ
	fp32 fOutMax;

	PointStruct pt[12]; 	

	uint8 effNum; // ��Ч��ĸ���
}GLINStruct;

// ���Ա任��
typedef struct
{
	fp32 fCoeffient;// ϵ��
	fp32 fBias;  //ƫ��
}LICHStruct; 

// �ߵ�ѡ����
typedef struct
{
	uint8 ucSelect; // 0:max 1:min 2:average
	uint8 ucEffNum; // ��Ч����
}SWHLStruct; 

// ����ȡ����
typedef struct
{
	#if defined SWMID_ucEffNum_2 || defined SWMID_ucEffNum_3
	uint8 ucSelect;// 0:max 1:min 2:average
	#endif 
	uint8 ucEffNum;  // ��Ч����
}SWMIDStruct;

// ���ؿ�����13
typedef struct
{
	uint8 ucSelect;  // 0:ѡ��1, 1:ѡ��2, 2:ѡ��3	
}SW13Struct;

// ƫ����ֵ��
typedef struct
{
 	fp32 fMaxBias;  // ���ƫ��
	fp32 fLastOut;	 // �ϴ����
    uint32 ulCycle;   // ����
	uint32 ulLastTimeRec; // �ϴο��Ƶ�ʱ��
}BIASLMTStruct;

// �仯����
typedef struct
{
	uint32 ulCycle;
	fp32 fLastIn;  // �ϴε�����
}CHRATStruct;

// ��Ȩƽ���˲���
typedef struct
{
	fp32 *fCoefficient;  // ϵ��
	fp32 *fSavedIn;  // ���ǰ7�ε�����
}AVEFLTStruct;

// ������
typedef struct
{
	fp32 fM[8];  // �˸��м����

}CALCUStruct;

// ģ��������
typedef struct
{
	fp32 fPV; // ���ֵ
	fp32 fSV; // �趨ֵ
	//fp32 fLastVal; // �ϴ�ֵ
	fp32 fRawVal; // ԭʼֵ
	uint8 isChange; // �Ƿ��������ת��
	fp32 fPVMax; // ���̵�λ����
	fp32 fPVMin; // ���̵�λ����
	fp32 fRawMax; // ԭʼ���ݸ���
	fp32 fRawMin; // ԭʼ���ݵ���
	fp32 fWarnLL;  // �����͵���ֵ
	uint8 isWarnLL; // �Ƿ����͵��ޱ���
	fp32 fWarnL; // ��������ֵ
	uint8 isWarnL; // �Ƿ������ޱ���
	fp32 fWarnHH;  // �����߸���
	uint8 isWarnHH; // �Ƿ����߸��ޱ���
	fp32 fWarnH; // ��������
	uint8 isWarnH; // �Ƿ������ޱ���
	fp32 fRation; // �仯��
	uint8 isRationWarn; // �Ƿ������б仯�ʱ���
	fp32 fBias;  // ƫ��
	uint8 isBiasWarn; // �Ƿ���ƫ���
	uint32 ulCycle; // ����	
}AIStruct;

// ģ�������
typedef struct
{
	fp32 fPV; // ���ֵ
	fp32 fSV; // �趨ֵ
	//fp32 fLastVal; // �ϴ�ֵ
	fp32 fRawVal; // ԭʼֵ
	uint8 isChange; // �Ƿ��������ת��
	fp32 fPVMax; // ���̵�λ����
	fp32 fPVMin; // ���̵�λ����
	fp32 fRawMax; // ԭʼ���ݸ���
	fp32 fRawMin; // ԭʼ���ݵ���
	fp32 fWarnLL;  // �����͵���ֵ
	uint8 isWarnLL; // �Ƿ����͵��ޱ���
	fp32 fWarnL; // ��������ֵ
	uint8 isWarnL; // �Ƿ������ޱ���
	fp32 fWarnHH;  // �����߸���
	uint8 isWarnHH; // �Ƿ����߸��ޱ���
	fp32 fWarnH; // ��������
	uint8 isWarnH; // �Ƿ������ޱ���
	fp32 fRation; // �仯��
	uint8 isRationWarn; // �Ƿ������б仯�ʱ���
	fp32 fBias;  // ƫ��
	uint8 isBiasWarn; // �Ƿ���ƫ���
	uint32 ulCycle; // ����	

}AOStruct;
// ��������
typedef struct
{
   uint8 cPV; // ���
   uint8 isInvert; // ��������
   uint8 cNormalVal; // ����ֵ
   uint8 isWarn;  // ����ֵ
   uint8 cRawVal; // ԭʼֵ

}DIStruct;
// �������
typedef struct
{
  uint8 cPV;	 // ���ֵ
  uint8 isInvert;// ��/������

}DOStruct;
//�����������
typedef struct
{
  fp32 fLastMV; // �ϴε�����ֵ
  uint8 cPV;	 // ���ֵ
  uint32 lCycle;// ��������
  uint8 cReset; // �Ƿ�����
  uint8 cStyle; // ��ʽ
  uint32 preCycle; // ǰ��ʱ��
  uint32 aftCycle; // ���ʱ��
  uint32 timeRec; // ʱ���¼
}PVMStruct;
//AD����
typedef struct
{
  uint8 ucCN; // ADͨ����
  //uint32 ulCycle; // ��������  
}ADStruct;
//DA���
typedef struct
{
  uint8 ucCN; // DAͨ����
  //uint32 ulCycle; // ��������  
}DAStruct;
// ����ʹ�ܶ˵�ģ����Ĭ�ϲ���:�ϴ�ֵ
//ADD�ӷ�
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}ADDStruct;
//SUB����
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}SUBStruct;
//MUL�˷�
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}MULStruct;
//DIV����
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}DIVStruct;
//POWER�˷�
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}POWERStruct;
//MOD����
typedef struct
{
  fp32 fLastValPV; // �ϴε�ֵ��
  fp32 fLastValQuat; // �ϴε�ֵ����
}MODStruct;
//ABS����ֵ
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}ABSStruct;
//COS����
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}COSStruct;
//SIN����
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}SINStruct;
//TAN����
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}TANStruct;
//ASIN������
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}ASINStruct;

//ACOS������
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}ACOSStruct;
//ATAN������
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}ATANStruct;
//EXPָ��
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}EXPStruct;
//LG���ö���
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}LGStruct;
//LN��Ȼ����
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}LNStruct;
//SQRTƽ����
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}SQRTStruct;
//TRUNC ȡ��
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}TRUNCStruct;
//������ON��Ч����
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}QOR2Struct;
// ������ON��Ч����
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}QOR3Struct;
// ���ڱȽ�
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}EQUStruct;
// �����ڱȽ�
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}UEQUStruct;
// ���ڱȽ�
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}GTStruct;
// С�ڱȽ�
typedef struct
{
  fp32 fLastVal; // �ϴε�ֵ
}LTStruct; // 157��struct-3 (154 / 2 = 77)
// �Ƚ�
typedef struct
{
  fp32 fResult; // �ȽϽ��
  uint8 isGT;// ����
  uint8 isLT;// С��
  uint8 isEQ;// ����
}COMPAREStruct;
// ������ϵ�
typedef struct
{
  uint8 inputStatus;// ����״̬
  uint8 outputStatus;// ���״̬
}DCStruct;
// ����������
typedef struct
{
  uint8 isEn;  // ʹ��
}PROCESSStruct;
////////////////////////////////////////////////////////////
//  2013.11.21 ͼ����
//extern uint8 FILEOUTControl(FILEOUTStruct *FILEOUT);
//�˲�
extern uint8 GAUSSIANSMOOTHINGControl(GAUSSIANSMOOTHINGStruct *GAUSSIANSMOOTHING);
extern uint8 MEDIANFILTERControl(MEDIANFILTERStruct  *MEDIANFILTER);
extern uint8 MEANFILTERControl(MEANFILTERStruct  *MEANFILTER);
extern uint8 SOBELControl(SOBELStruct *SOBEL);
extern uint8 PREWITTControl(PREWITTStruct  *PREWITT);
extern uint8 LAPLACEControl(LAPLACEStruct *LAPLACE);
//ɫ��
extern uint8 BINARYControl(BINARYStruct *BINARY);
extern uint8 OSTUBINARYControl(OSTUBINARYStruct  *OSTUBINARY);
extern uint8 ANTICOLORControl(ANTICOLORStruct  *ANTICOLOR);
extern uint8 GRAYSCALESTRETCHControl(GRAYSCALESTRETCHStruct *GRAYSCALESTRETCH);
extern uint8 HIAGRAMControl(HIAGRAMStruct *HIAGRAM);
//��̬ѧ
extern uint8 DENOSINGControl(DENOSINGStruct  *DENOSING);
extern uint8 ZHANGTHINControl(ZHANGTHINStruct  *ZHANGTHIN);
extern uint8 DIALATEControl(DIALATEStruct *DIALATE);
extern uint8 ERODEControl(ERODEStruct *ERODE);
extern uint8 OPENOPERATIONControl(OPENOPERATIONStruct *OPENOPERATION);
extern uint8 CLOSEOPERATIONControl(CLOSEOPERATIONStruct  *CLOSEOPERATION);
//�������
extern uint8 CANNYControl (CANNYStruct  *CANNY);
extern uint8 HOUGHLINESControl(HOUGHLINESStruct  *HOUGHLINES);
extern uint8 HOLLOWEDControl(HOLLOWEDStruct  *HOLLOWED);
//��������
extern uint8 HARRISControl(HARRISStruct  *HARRIS);
//��ֵ����
extern uint8 CENTEROFGRAVITYControl(CENTEROFGRAVITYStruct  *CENTEROFGRAVITY);
//ƥ��
extern uint8 MATCHControl(MATCHStruct *MATCH);

//
extern uint8 CONControl(fp32 a);
extern uint8 POPControl(void);
extern uint8 LDControl(void *a);
extern uint8 STControl(void *a);
extern uint8 ADDControl(ADDStruct *ADD);
extern uint8 SUBControl(SUBStruct *SUB);
extern uint8 MULControl(MULStruct *MUL);
extern uint8 DIVControl(DIVStruct *DIV);
extern uint8 POWERControl(POWERStruct *POWER);
extern uint8 MODControl(MODStruct *MOD);
extern uint8 ABSControl(ABSStruct *ABS);
extern uint8 COSControl(COSStruct *COS);
extern uint8 SINControl(SINStruct *SIN);
extern uint8 TANControl(TANStruct *TAN);
extern uint8 ASINControl(ASINStruct *ASIN);
extern uint8 ACOSControl(ACOSStruct *ACOS);
extern uint8 ATANControl(ATANStruct *ATAN);
extern uint8 EXPControl(EXPStruct *EXP);
extern uint8 LGControl(LGStruct *LG);
extern uint8 LNControl(LNStruct *LN);
extern uint8 SQRTControl(SQRTStruct *SQRT);
extern uint8 TRUNCControl(TRUNCStruct *TRUNC);
extern uint8 ANDControl(ANDStruct *AND);
extern uint8 ORControl(ORStruct *OR);
extern uint8 XORControl(XORStruct *XOR);
extern uint8 NOTControl(NOTStruct *NOT);
extern uint8 NANDControl(NANDStruct *NAND);
extern uint8 NORControl(NORStruct *NOR);
extern uint8 QOR2Control(QOR2Struct *QOR2);
extern uint8 QOR3Control(QOR3Struct *QOR3);
extern uint8 DISP3Control(DISP3Struct *DISP3);
extern uint8 SWITControl(SWITStruct *SWIT);
extern uint8 PULSEControl(PULSEStruct *PULSE);
extern uint8 MAXPLControl(MAXPLStruct *MAXPL);
extern uint8 MINPLControl(MINPLStruct *MINPL);
extern uint8 EQUControl(EQUStruct *EQU);
extern uint8 UEQUControl(UEQUStruct *UEQU);
extern uint8 GTControl(GTStruct *GT);
extern uint8 LTControl(LTStruct *LT);
extern uint8 RSControl(RSStruct *RS);
extern uint8 DELAYControl(DELAYStruct *DELAY);
extern uint8 ONDLYControl(ONDLYStruct *ONDLY);
extern uint8 OFFDLYControl(OFFDLYStruct *OFFDLY);
extern uint8 WTDOGControl(WTDOGStruct *WTDOG);
extern uint8 SELECTControl(SELECTStruct *SELECT);
extern uint8 CHDCTControl(CHDCTStruct *CHDCT);
extern uint8 RETControl(void);
extern uint8 PIControl(PIStruct *PI);
extern uint8 SMITHControl(SMITHStruct *SMITH);
extern uint8 LEASTControl(LEASTStruct *LEAST);
extern uint8 DARLINControl(DARLINStruct *DARLIN);
extern uint8 PREControl(PREStruct *PRE);
extern uint8 JIEOUControl(JIEOUStruct *JIEOU);
extern uint8 FUZZYControl(FUZZYStruct *FUZZY);
extern uint8 FILTControl(FILTStruct *FILT);
extern uint8 TRANSControl(TRANSStruct *TRANS);
extern uint8 CNTControl(CNTStruct *CNT);
extern uint8 TIMControl(TIMStruct *TIM);
extern uint8 TOTControl(TOTStruct *TOT);
extern uint8 LIMITControl(LIMITStruct *LIMIT);
extern uint8 PERCENTControl(PERCENTStruct *PERCENT);
extern uint8 RATIONControl(RATIONStruct *RATION);
extern uint8 RAMPControl(RAMPStruct *RAMP);
extern uint8 SW51Control(SW51Struct *SW51);
extern uint8 FLCPControl(FLCPStruct *FLCP);
extern fp32 Linearize(PointStruct pt1,PointStruct pt2,fp32 x);
extern uint8 GLINControl(GLINStruct *GLIN);
extern uint8 LICHControl(LICHStruct *LICH);
extern uint8 SWHLControl(SWHLStruct *SWHL);
extern uint8 SWMIDControl(SWMIDStruct *SWMID);
extern uint8 SW13Control(SW13Struct *SW13);
extern uint8 BIASLMTControl(BIASLMTStruct *BIASLMT);
extern uint8 DCControl(DCStruct *DC);
extern uint8 CHRATControl(CHRATStruct *CHRAT);
extern uint8 COMPAREControl(COMPAREStruct *COMPARE);
extern uint8 AVEFLTControl(AVEFLTStruct *AVEFLT);
extern uint8 PIDControl(PIDStruct* PID);
extern uint8 DAControl(DAStruct * DA);
extern uint8 ADControl(ADStruct * AD);
extern uint8 AOControl(AOStruct *AO);
extern uint8 DIControl(DIStruct* DI);
extern uint8 DOControl(DOStruct* DO);
extern uint8 AIControl(AIStruct *AI);
extern uint8 PVMControl(PVMStruct *PVM);

#endif




