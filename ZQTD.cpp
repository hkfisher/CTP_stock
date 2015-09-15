// ZQTD.cpp: implementation of the CZQTD class.
//
//////////////////////////////////////////////////////////////////////
#include "util.h"
#include "ZQTD.h"
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CZQTD::CZQTD()
{

}

CZQTD::~CZQTD()
{

}

void CZQTD::Init()
{

	// ����һ��CThostFtdcTraderApiʵ��
	m_pTdApi = CZQThostFtdcTraderApi::CreateFtdcTraderApi("");

	// ע��һ�¼������ʵ��
	m_pTdApi->RegisterSpi(this);
	
	// ����˽����
	//        TERT_RESTART:�ӱ������տ�ʼ�ش�
	//        TERT_RESUME:���ϴ��յ�������
	//        TERT_QUICK:ֻ���͵�¼��˽����������
	m_pTdApi->SubscribePrivateTopic(ZQTHOST_TERT_RESUME);
	
	// ���Ĺ�����
	//        TERT_RESTART:�ӱ������տ�ʼ�ش�
	//        TERT_RESUME:���ϴ��յ�������
	//        TERT_QUICK:ֻ���͵�¼�󹫹���������
	m_pTdApi->SubscribePublicTopic(ZQTHOST_TERT_RESUME);

	// ���ý����й�ϵͳ����ĵ�ַ������ע������ַ����
	/*printf("�����뽻�׷�������ַ..(���磺tcp://180.166.11.40:41205,������ԣ������޷����ӣ�����)\n");
	char buffer[40];
    cin>>buffer;
	char *add_td=buffer;*/
	m_pTdApi->RegisterFront("tcp://180.166.11.40:41205");

	// ʹ�ͻ��˿�ʼ���̨����������
	m_pTdApi->Init();
}

void CZQTD::OnFrontConnected()
{
	CZQThostFtdcReqUserLoginField reqUserLogin;
	memset(&reqUserLogin,0,sizeof(reqUserLogin));

	strcpy(reqUserLogin.BrokerID,"2011");//�˴�2011��Ҫ��

	strcpy(reqUserLogin.UserID,"20000003");

	strcpy(reqUserLogin.Password,"112233");
	int login=m_pTdApi->ReqUserLogin(&reqUserLogin, 1);
	printf("��¼�������,����ֵ%d\n",login); 
}
void CZQTD::OnRspUserLogin(CZQThostFtdcRspUserLoginField *pRspUserLogin, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	printf("��¼������Ӧ��pRspInfo->ErrorID:%d,pRspInfo->ErrorMsg:%s\n",pRspInfo->ErrorID,pRspInfo->ErrorMsg);	
	//�������ܴ���
	//CZQThostFtdcInputOrderField pInputOrder;
	//memset(&pInputOrder,0,sizeof(pInputOrder));
	//CZQThostFtdcInputOrderField * pIptOrdFld=&pInputOrder;
	////���͹�˾����
	//strcpy_s(pIptOrdFld->BrokerID,"2011");
	////Ͷ���ߴ���
	//strcpy_s(pIptOrdFld->InvestorID,"20000002");
	////��Լ����
	//strcpy_s(pIptOrdFld->InstrumentID,"601857");
	////����������  
	//strcpy_s(pIptOrdFld->ExchangeID,"SSE");//SSE�Ͻ��� SZE���
	////�����۸�����  
	//pIptOrdFld->OrderPriceType=THOST_FTDC_OPT_LimitPrice;
	////��������
	//pIptOrdFld->Direction=THOST_FTDC_D_Buy;
	////����
	//pIptOrdFld->VolumeTotalOriginal=20000;
	////��Ч������
	//pIptOrdFld->TimeCondition = THOST_FTDC_TC_GFD;
	////�ɽ�������
	//pIptOrdFld->VolumeCondition=THOST_FTDC_VC_AV;
	////��������
	//pIptOrdFld->ContingentCondition = THOST_FTDC_CC_Immediately;
	////ǿƽԭ��
	//pIptOrdFld->ForceCloseReason = THOST_FTDC_FCC_NotForceClose;
	////�۸�
	//strcpy_s(pIptOrdFld->LimitPrice,"9.89");
	//pIptOrdFld->CombOffsetFlag[0]=THOST_FTDC_OF_Open;
	//pIptOrdFld->CombHedgeFlag[0]=THOST_FTDC_HF_Speculation;
	//strcpy_s(pIptOrdFld->UserID,"20000002");
	//pIptOrdFld->IsAutoSuspend = 0;
	//pIptOrdFld->UserForceClose = 0;
	//int resCode=m_pTdApi->ReqOrderInsert(pIptOrdFld, ++nRequestID);
	//printf("ReqOrderInsert:<-����ֵ->%d\n",resCode);	
	
	//��ֲ�
	//CZQThostFtdcQryInvestorPositionField pField;
	//memset(&pField,0,sizeof(pField));
	//CZQThostFtdcQryInvestorPositionField *pFld=&pField;
	//strcpy_s(pFld->BrokerID,"2011");
	//strcpy_s(pFld->InvestorID,"20000002");
	////strcpy_s(pFld->InstrumentID,"600002");//��д���������þ���ĳ��֤ȯ�ĳֲ���Ϣ�������ʾ�����гֲ�
	//int lo=m_pTdApi->ReqQryInvestorPosition(pFld,nRequestID);
	}

void CZQTD::OnRspQryInvestorPosition(CZQThostFtdcInvestorPositionField *pInvestorPosition, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	//printf("BrokerID���͹�˾:%s  InstrumentID֤ȯ����:%s  InvestorIDͶ����:%s  Position���ճֲ�:%d  Position���ճֲ�:%d  OpenVolume������:%d   Commission������:%f\n",pInvestorPosition->BrokerID,pInvestorPosition->InstrumentID,pInvestorPosition->InvestorID,pInvestorPosition->Position,pInvestorPosition->YdPosition,pInvestorPosition->OpenVolume,pInvestorPosition->Commission);
	return;
}
void CZQTD::OnRspQryInstrument(CZQThostFtdcInstrumentField *pInstrument, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if(pInstrument!=NULL)
		printf("Instrument:%s;Name:%s!\n",pInstrument->InstrumentID,pInstrument->InstrumentName);
}
void CZQTD::OnRspOrderInsert(CZQThostFtdcInputOrderField *pInputOrder2, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
 {
	printf("ReqOrderAction---pRspInfo->ErrorID:%d,pRspInfo->ErrorMsg:%s\n",pRspInfo->ErrorID,pRspInfo->ErrorMsg);
	return;
}
void CZQTD::OnRspQryOrder(CZQThostFtdcOrderField *pOrder, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
 {
	 if(pOrder!=NULL){
     CZQThostFtdcInputOrderActionField pInputOrder;
	 memset(&pInputOrder,0,sizeof(pInputOrder));
	 CZQThostFtdcInputOrderActionField *pIptOrdFld=&pInputOrder;
	 /*������ʽһ��ͬһ��session*/
	 //pIptOrdFld->FrontID=pOrder->FrontID;
	 //pIptOrdFld->SessionID=pOrder->SessionID;
	 //strcpy_s(pIptOrdFld->OrderRef,pOrder->OrderRef);
	 //pIptOrdFld->ActionFlag=THOST_FTDC_AF_Delete;

	 /*������ʽ��������ͬһ��session*/
	 strcpy(pIptOrdFld->OrderLocalID,pOrder->OrderLocalID);
     strcpy(pIptOrdFld->TraderID,pOrder->TraderID);
	 strcpy(pIptOrdFld->BrokerID,pOrder->BrokerID);
	 strcpy(pIptOrdFld->ExchangeID,pOrder->ExchangeID);
	 pIptOrdFld->ActionFlag=THOST_FTDC_AF_Delete;

	// if(pOrder->OrderStatus=='1'){
	 printf("--��ÿɳ�������-!!%s!!%d!!%d\n",pOrder->OrderLocalID,pOrder->OrderStatus,pOrder->LimitPrice);
	 int resCode2=m_pTdApi->ReqOrderAction(pIptOrdFld, ++nRequestID);
	 printf("ReqOrderAction�����ύ:%d,++nRequestID%d\n",resCode2,nRequestID);	
	//}
	 }
	return;
}
void CZQTD::OnRspQryTradingCode(CZQThostFtdcTradingCodeField *pTradingCode, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	printf("InvestorID:%d   ClientID:%d\n",pTradingCode->InvestorID,pTradingCode->ClientID);
	return;
}
void CZQTD::OnRspQryInstrumentCommissionRate(CZQThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	return;
}
void CZQTD::OnRspError(CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	printf("--OnRspError--:%s\n",pRspInfo->ErrorMsg);
	return;
}
void CZQTD::OnErrRtnOrderInsert(CZQThostFtdcInputOrderField *pInputOrder, CZQThostFtdcRspInfoField *pRspInfo)
{
	printf("--OnErrRtnOrderInsert--:%s\n",pRspInfo->ErrorMsg);
	return;
}
void CZQTD::OnErrRtnOrderAction(CZQThostFtdcOrderActionField *pOrderAction, CZQThostFtdcRspInfoField *pRspInfo)
{
	printf("--OnErrRtnOrderAction--:%s--\n",pRspInfo->ErrorMsg);
	return;
}
//Rtn/////////////////////////////////////////////////////////////////////

void CZQTD::OnRtnOrder(CZQThostFtdcOrderField *pOrder)
{
	printf("--pOrder-----%d!!%d!!%s!!%s!!%s\n",pOrder->FrontID,pOrder->SessionID,pOrder->OrderLocalID,pOrder->TraderID,pOrder->StatusMsg);	
	return;
}

void CZQTD::OnRspOrderAction(CZQThostFtdcInputOrderActionField *pInputOrderAction, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	printf("=������Ӧ==�۸�%s��������:%s!!���ر������:%s--ErrorMsg��%s\n",pInputOrderAction->LimitPrice,pInputOrderAction->OrderRef,pInputOrderAction->OrderLocalID,pRspInfo->ErrorMsg);
	return;
}

void CZQTD::OnRtnTrade(CZQThostFtdcTradeField *pTrade)
{
	printf("Instrument:%s;Price:%s;dbPrice:%n!\n",pTrade->InstrumentID,pTrade->Price,getPrice(pTrade->Price));
	return;
}
void CZQTD::OnRtnInstrumentStatus(CZQThostFtdcInstrumentStatusField *pInstrumentStatus)
{
	return;
}

double CZQTD::getPrice(TZQThostFtdcStockPriceType price)
{
	return sizeof(price) / sizeof(price[0]);
}
